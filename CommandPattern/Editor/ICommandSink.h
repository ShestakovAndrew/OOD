#pragma once
#include "ICommand.h"

class ICommandSink
{
public:
	virtual ~ICommandSink() = default;
	virtual void SaveCommand(ICommandPtr&& command) = 0;
};