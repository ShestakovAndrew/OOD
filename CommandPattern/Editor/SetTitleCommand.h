#pragma once
#include "AbstractCommand.h"
#include <string>

class CSetTitleCommand : public CAbstractCommand
{
public:
	CSetTitleCommand(std::string& target, std::string const& newTitle);

private:
	void DoExecute() override;
	void DoUnexecute() override;

	std::string m_newTitle;
	std::string& m_target;
};
