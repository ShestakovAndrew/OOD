#pragma once
#include "IParagraph.h"
#include "ICommandSink.h"

class CParagraph : public IParagraph
{
public:
	CParagraph(std::string const& text, ICommandSink& commandSink);

	std::string GetText() const override;
	void SetText(std::string const& text) override;

private:
	std::string m_text;
	ICommandSink& m_commandSink;
};
