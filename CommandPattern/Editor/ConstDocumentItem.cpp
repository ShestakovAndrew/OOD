#include "ConstDocumentItem.h"

CConstDocumentItem::CConstDocumentItem(Item const& item)
	: m_item(item)
{
}

std::shared_ptr<const IImage> CConstDocumentItem::GetImage() const
{
	if (std::holds_alternative<std::shared_ptr<IImage>>(m_item))
	{
		return std::get<std::shared_ptr<IImage>>(m_item);
	}
	return nullptr;
}

std::shared_ptr<const IParagraph> CConstDocumentItem::GetParagraph() const
{
	if (std::holds_alternative<std::shared_ptr<IParagraph>>(m_item))
	{
		return std::get<std::shared_ptr<IParagraph>>(m_item);
	}
	return nullptr;
}