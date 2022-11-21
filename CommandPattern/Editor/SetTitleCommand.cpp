#include "SetTitleCommand.h"
#include <algorithm>

CSetTitleCommand::CSetTitleCommand(std::string& target, std::string const& newTitle)
	: m_target(target)
	, m_newTitle(newTitle)
{
}

void CSetTitleCommand::DoExecute()
{
	std::swap(m_target, m_newTitle);
}

void CSetTitleCommand::DoUnexecute()
{
	std::swap(m_target, m_newTitle);
}
