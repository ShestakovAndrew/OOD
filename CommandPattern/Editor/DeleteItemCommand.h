#pragma once
#include "AbstractCommand.h"
#include "DocumentItem.h"
#include <optional>
#include <vector>

class CDeleteItemCommand : public CAbstractCommand
{
public:
	CDeleteItemCommand(std::vector<CDocumentItem>& items, size_t index);
	~CDeleteItemCommand();

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	std::vector<CDocumentItem>& m_items;
	size_t m_index;
	std::shared_ptr<CDocumentItem> m_item;
};
