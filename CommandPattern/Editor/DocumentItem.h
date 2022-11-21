#pragma once
#include "ConstDocumentItem.h"
#include "Item.h"

class CDocumentItem: public CConstDocumentItem
{
public:
	CDocumentItem(Item const& item);
	// Возвращает указатель на изображение, либо nullptr, если элемент не является изображением
	std::shared_ptr<IImage> GetImage();
	// Возвращает указатель на параграф, либо nullptr, если элемент не является параграфом
	std::shared_ptr<IParagraph> GetParagraph();
};