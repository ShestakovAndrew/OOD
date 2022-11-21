#include "Paragraph.h"
#include "ReplaceParagraphTextCommand.h"

CParagraph::CParagraph(std::string const& text, ICommandSink& commandSink)
	: m_text(text)
	, m_commandSink(commandSink)
{
}

std::string CParagraph::GetText() const
{
	return m_text;
}

void CParagraph::SetText(std::string const& text)
{
	m_commandSink.SaveCommand(std::make_unique<CReplaceParagraphTextCommand>(m_text, text));
}
