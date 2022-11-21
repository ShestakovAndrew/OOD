#include "DeleteItemCommand.h"
#include "Paragraph.h"
#include <filesystem>

CDeleteItemCommand::CDeleteItemCommand(std::vector<CDocumentItem>& items, size_t index)
	: m_items(items)
	, m_index(index)
{
	if (m_index >= m_items.size())
	{
		throw std::invalid_argument("Index cannot be greater than number of elements");
	}
	auto item = m_items.at(index);
	m_item = std::make_shared<CDocumentItem>(item);
}

CDeleteItemCommand::~CDeleteItemCommand()
{
	if (IsExecuted() && m_item->GetImage())
	{
		m_item->GetImage()->Remove();
	}
}

void CDeleteItemCommand::DoExecute()
{
	m_items.erase(m_items.begin() + m_index);
}

void CDeleteItemCommand::DoUnexecute()
{
	m_items.emplace(m_items.begin() + m_index, *m_item);
}
