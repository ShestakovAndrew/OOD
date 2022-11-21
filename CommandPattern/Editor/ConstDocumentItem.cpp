#include "ConstDocumentItem.h"

CConstDocumentItem::CConstDocumentItem(Item const& item)
{
}

std::shared_ptr<const IImage> CConstDocumentItem::GetImage() const
{
	return std::shared_ptr<const IImage>();
}

std::shared_ptr<const IParagraph> CConstDocumentItem::GetParagraph() const
{
	return std::shared_ptr<const IParagraph>();
}
