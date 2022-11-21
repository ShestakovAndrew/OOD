#pragma once
#include "AbstractCommand.h"
#include "IParagraph.h"

class CReplaceParagraphTextCommand : public CAbstractCommand
{
public:
	CReplaceParagraphTextCommand(std::string& text, std::string const& newText);

private:
	void DoExecute() override;
	void DoUnexecute() override;

	std::string& m_text;
	std::string m_newText;
};
