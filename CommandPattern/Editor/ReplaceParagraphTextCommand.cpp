#include "ReplaceParagraphTextCommand.h"

CReplaceParagraphTextCommand::CReplaceParagraphTextCommand(std::string& text, std::string const& newText)
	: m_text(text)
	, m_newText(newText)
{
}

void CReplaceParagraphTextCommand::DoExecute()
{
	std::swap(m_text, m_newText);
}

void CReplaceParagraphTextCommand::DoUnexecute()
{
	std::swap(m_text, m_newText);
}
