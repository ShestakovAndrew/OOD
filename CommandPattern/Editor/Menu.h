#pragma once
#include "ICommand.h"
#include <functional>
#include <iostream>
#include <string>
#include <vector>

class CMenu
{
public:
	typedef std::function<void(std::istream& in)> Command;

	CMenu(std::istream& inStream, std::ostream& outStream);

	void AddItem(const std::string& shortcut, const std::string& description, Command const& command);
	void Run();
	void ShowInstructions() const;
	void Exit();

private:
	struct Item
	{
		Item(const std::string& shortcut, const std::string& description,
			CMenu::Command const& command)
			: shortcut(shortcut)
			, description(description)
			, command(command)
		{
		}
		std::string shortcut;
		std::string description;
		CMenu::Command command;
	};

	bool ExecuteCommand(const std::string& command);

	std::vector<Item> m_items;
	bool m_exit = false;
	std::istream& m_inStream;
	std::ostream& m_outStream;
};
