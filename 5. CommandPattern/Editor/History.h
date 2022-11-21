#pragma once
#include "ICommand.h"
#include <vector>

class CHistory
{
public:
	bool CanUndo() const;
	void Undo();

	bool CanRedo() const;
	void Redo();

	void AddAndExecuteCommand(ICommandPtr&& command);

private:
	const size_t HISTORY_LENGTH = 10;

	std::vector<ICommandPtr> m_commands{};
	size_t m_nextIndex = 0;
};
