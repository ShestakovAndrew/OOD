#pragma once
#include "Menu.h"
#include "IDocument.h"

class CEditor
{
public:
	CEditor(std::istream& inStream = std::cin, std::ostream& outStream = std::cout);
	void Start();

private:
	void InsertParagraph(std::istream& in);
	void InsertImage(std::istream& in);
	void SetTitle(std::istream& in);
	void List(std::istream&);
	void ReplaceText(std::istream& in);
	void ResizeImage(std::istream& in);
	void DeleteItem(std::istream& in);
	void Undo(std::istream&);
	void Redo(std::istream&);
	void Save(std::istream& in);

	CMenu m_menu;
	std::unique_ptr<IDocument> m_document;
	std::ostream& m_outStream;
};
