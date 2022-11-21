#include <fstream>

#include "DeleteItemCommand.h"
#include "DeleteItemCommand.h"
#include "InsertDocumentItemCommand.h"
#include "ReplaceParagraphTextCommand.h"
#include "ResizeImageCommand.h"
#include "SetTitleCommand.h"

#include "Document.h"
#include "Paragraph.h"
#include "Image.h"

const std::string IMAGES_DIR = "images";

namespace
{
	std::string ConvertToHtmlString(std::string const& str)
	{
		std::string result;

		for (auto ch : str)
		{
			switch (ch)
			{
			case '<':
				result += "&lt;";
				break;
			case '>':
				result += "&gt;";
				break;
			case '\"':
				result += "&quot;";
				break;
			case '\'':
				result += "&apos;";
				break;
			case '&':
				result += "&amp;";
				break;
			default:
				result += ch;
				break;
			}
		}

		return result;
	}
} // namespace

CDocument::CDocument()
	: m_commandSink(CHistoryAdapter(m_history))
{
}

std::shared_ptr<IParagraph> CDocument::InsertParagraph(const std::string& text, std::optional<size_t> index)
{
	auto paragraph = std::make_shared<CParagraph>(text, m_commandSink);
	auto documentItem = CDocumentItem(paragraph);
	m_history.AddAndExecuteCommand(std::make_unique<CInsertDocumentItemCommand>(documentItem, m_items, index));

	return paragraph;
}

std::shared_ptr<IImage> CDocument::InsertImage(const Path& path, int width, int height, std::optional<size_t> index)
{
	auto image = std::make_shared<CImage>(path, width, height, m_commandSink);
	auto documentItem = CDocumentItem(image);
	m_history.AddAndExecuteCommand(std::make_unique<CInsertDocumentItemCommand>(documentItem, m_items, index));

	return image;
}

size_t CDocument::GetItemsCount() const
{
	return m_items.size();
}

CConstDocumentItem CDocument::GetItem(size_t index) const
{
	return m_items.at(index);
}

CDocumentItem CDocument::GetItem(size_t index)
{
	return m_items.at(index);
}

void CDocument::DeleteItem(size_t index)
{
	m_history.AddAndExecuteCommand(std::make_unique<CDeleteItemCommand>(m_items, index));
}

void CDocument::ReplaceParagraphText(size_t index, const std::string& text)
{
	if (index >= GetItemsCount())
	{
		throw std::invalid_argument("Paragraph index is out of range");
	}

	auto paragraph = GetItem(index).GetParagraph();
	if (!paragraph)
	{
		throw std::invalid_argument("Is not a paragraph");
	}

	paragraph->SetText(text);
}

void CDocument::ResizeImage(size_t index, int width, int height)
{
	if (index >= GetItemsCount())
	{
		throw std::invalid_argument("Image index is out of range");
	}

	auto image = GetItem(index).GetImage();
	if (!image)
	{
		throw std::invalid_argument("Is not an image");
	}

	image->Resize(width, height);
}

std::string CDocument::GetTitle() const
{
	return m_title;
}

void CDocument::SetTitle(const std::string& title)
{
	m_history.AddAndExecuteCommand(std::make_unique<CSetTitleCommand>(m_title, title));
}

bool CDocument::CanUndo() const
{
	return m_history.CanUndo();
}

void CDocument::Undo()
{
	m_history.Undo();
}

bool CDocument::CanRedo() const
{
	return m_history.CanRedo();
}

void CDocument::Redo()
{
	m_history.Redo();
}

void CDocument::Save(Path const& path) const
{
	std::ofstream html(path);

	Path directory = path.parent_path() / IMAGES_DIR;
	if (!std::filesystem::is_directory(directory))
	{
		std::filesystem::create_directory(directory);
	}

	html << "<html>\n"
		 << "<head>\n"
		 << "<title>" << ConvertToHtmlString(m_title) << "</title>\n"
		 << "</head>\n"
		 << "<body>\n";

	for (auto item : m_items)
	{
		if (auto image = item.GetImage())
		{
			Path src = image->GetPath();
			int width = image->GetWidth();
			int height = image->GetHeight();

			html << "<img src=\"" + src.string() + "\" width=\"" + std::to_string(width) + "\" height=\"" + std::to_string(height) + "\" />" << std::endl;

			if (!std::filesystem::exists(directory / src.filename()))
			{
				std::filesystem::copy_file(src, directory / src.filename());
			}
		}
		else
		{
			auto paragraph = item.GetParagraph();
			std::string text = ConvertToHtmlString(paragraph->GetText());
			html << "<p>" + text + "</p>" << std::endl;
		}
	}

	html << "</body>\n"
		 << "</html>" << std::endl;
}