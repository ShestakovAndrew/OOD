#include "DocumentItem.h"

CDocumentItem::CDocumentItem(Item const& item)
    : CConstDocumentItem(item)
{
}

std::shared_ptr<IImage> CDocumentItem::GetImage()
{
    return std::shared_ptr<IImage>();
}

std::shared_ptr<IParagraph> CDocumentItem::GetParagraph()
{
    return std::shared_ptr<IParagraph>();
}
