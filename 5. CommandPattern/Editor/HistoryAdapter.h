#pragma once
#include "History.h"
#include "ICommandSink.h"
class CHistoryAdapter : public ICommandSink
{
public:
	CHistoryAdapter(CHistory& history);

	void SaveCommand(ICommandPtr&& command) override;

private:
	CHistory& m_history;
};
