#include "History.h"

bool CHistory::CanUndo() const
{
	return m_nextIndex != 0;
}

void CHistory::Undo()
{
	if (CanUndo())
	{
		m_commands[m_nextIndex - 1]->Unexecute();
		--m_nextIndex;
	}
}

bool CHistory::CanRedo() const
{
	return m_nextIndex != m_commands.size();
}

void CHistory::Redo()
{
	if (CanRedo())
	{
		m_commands[m_nextIndex]->Execute();
		++m_nextIndex;
	}
}

void CHistory::AddAndExecuteCommand(ICommandPtr&& command)
{
	command->Execute();
	for (size_t i = m_nextIndex; i < m_commands.size(); ++i)
	{
		m_commands.erase(m_commands.begin() + i);	
	}
	++m_nextIndex;
	m_commands.push_back(std::move(command));

	if (m_nextIndex - 1 == HISTORY_LENGTH)
	{
		m_commands.erase(m_commands.begin());
		--m_nextIndex;
	}
}
