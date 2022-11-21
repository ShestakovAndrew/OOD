#include "HistoryAdapter.h"

CHistoryAdapter::CHistoryAdapter(CHistory& history)
	: m_history(history)
{
}

void CHistoryAdapter::SaveCommand(ICommandPtr&& command)
{
	m_history.AddAndExecuteCommand(std::move(command));
}
