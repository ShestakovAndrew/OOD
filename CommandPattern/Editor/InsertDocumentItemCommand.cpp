#include "InsertDocumentItemCommand.h"

CInsertDocumentItemCommand::CInsertDocumentItemCommand(CDocumentItem const& item, std::vector<CDocumentItem>& items, std::optional<size_t> index)
	: m_item(item)
	, m_items(items)
	, m_index(index)
{
	if (m_index >= m_items.size())
	{
		throw std::invalid_argument("Index cannot be greater than number of elements");
	}
}

CInsertDocumentItemCommand::~CInsertDocumentItemCommand()
{
	if (m_item.GetImage() && !IsExecuted())
	{
		m_item.GetImage()->Remove();
	}
}

void CInsertDocumentItemCommand::DoExecute()
{
	auto index = (m_index) ? (m_items.begin() + m_index.value()) : (m_items.end());
	m_items.emplace(index, m_item);
}

void CInsertDocumentItemCommand::DoUnexecute()
{
	auto index = (m_index) ? (m_items.begin() + m_index.value()) : (--m_items.end());
	m_items.erase(index);
}