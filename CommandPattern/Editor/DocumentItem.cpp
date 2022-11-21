#include "DocumentItem.h"

CDocumentItem::CDocumentItem(CConstDocumentItem::Item const& item)
	: CConstDocumentItem(item)
{
}

std::shared_ptr<IImage> CDocumentItem::GetImage()
{
	if (std::holds_alternative<std::shared_ptr<IImage>>(m_item))
	{
		return std::get<std::shared_ptr<IImage>>(m_item);
	}
	return nullptr;
}

std::shared_ptr<IParagraph> CDocumentItem::GetParagraph()
{
	if (std::holds_alternative<std::shared_ptr<IParagraph>>(m_item))
	{
		return std::get<std::shared_ptr<IParagraph>>(m_item);
	}
	return nullptr;
}