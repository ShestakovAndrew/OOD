#pragma once
#include "History.h"
#include "IDocument.h"
#include "HistoryAdapter.h"

class CDocument : public IDocument
{
public:
	CDocument();

	std::shared_ptr<IParagraph> InsertParagraph(const std::string& text, std::optional<size_t> index = std::nullopt) override;
	std::shared_ptr<IImage> InsertImage(const Path& path, int width, int height, std::optional<size_t> index = std::nullopt) override;

	size_t GetItemsCount() const override;

	CConstDocumentItem GetItem(size_t index) const override;
	CDocumentItem GetItem(size_t index) override;
	void DeleteItem(size_t index) override;

	void ReplaceParagraphText(size_t index, const std::string& text) override;
	void ResizeImage(size_t index, int width, int height) override;

	std::string GetTitle() const override;
	void SetTitle(const std::string& title) override;

	bool CanUndo() const override;
	void Undo() override;

	bool CanRedo() const override;
	void Redo() override;

	void Save(const Path& path) const override;

private:
	std::string m_title;
	std::vector<CDocumentItem> m_items{};
	CHistory m_history;
	CHistoryAdapter m_commandSink;
};
