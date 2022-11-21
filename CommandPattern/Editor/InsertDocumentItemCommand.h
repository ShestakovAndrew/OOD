#pragma once
#include "AbstractCommand.h"
#include "DocumentItem.h"
#include <optional>

class CInsertDocumentItemCommand : public CAbstractCommand
{
public:
	CInsertDocumentItemCommand(CDocumentItem const& item, std::vector<CDocumentItem>& items, std::optional<size_t> index = std::nullopt);
	~CInsertDocumentItemCommand();

private:
	void DoExecute() override;
	void DoUnexecute() override;

	CDocumentItem m_item;
	std::vector<CDocumentItem>& m_items;
	std::optional<size_t> m_index;
};
