#include "Menu.h"
#include <algorithm>
#include <iostream>
#include <sstream>

CMenu::CMenu(std::istream& inStream, std::ostream& outStream)
	: m_inStream(inStream)
	, m_outStream(outStream)
{
}

void CMenu::AddItem(const std::string& shortcut, const std::string& description, CMenu::Command const& command)
{
	m_items.emplace_back(shortcut, description, command);
}

void CMenu::Run()
{
	ShowInstructions();

	std::string command;
	while ((m_outStream << ">")
		&& std::getline(m_inStream, command)
		&& ExecuteCommand(command))
	{
	}
}

void CMenu::ShowInstructions() const
{
	m_outStream << "Commands list:\n";
	for (auto& item : m_items)
	{
		m_outStream << "  " << item.shortcut << ": " << item.description << "\n";
	}
}

void CMenu::Exit()
{
	m_exit = true;
}

bool CMenu::ExecuteCommand(const std::string& command)
{
	std::istringstream ss(command);
	std::string commandName;
	ss >> commandName;

	m_exit = false;
	auto it = std::find_if(m_items.begin(), m_items.end(), [&](const Item& item) {
		return item.shortcut == commandName;
	});
	if (it != m_items.end())
	{
		it->command(ss);
	}
	else
	{
		m_outStream << "Unknown command\n";
	}
	return !m_exit;
}
