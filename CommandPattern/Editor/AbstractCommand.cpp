#include "AbstractCommand.h"

void CAbstractCommand::Execute()
{
	if (!m_executed)
	{
		DoExecute();
		m_executed = true;
	}
}

void CAbstractCommand::Unexecute()
{
	if (m_executed)
	{
		DoUnexecute();
		m_executed = false;
	}
}

bool CAbstractCommand::IsExecuted() const
{
	return m_executed;
}
