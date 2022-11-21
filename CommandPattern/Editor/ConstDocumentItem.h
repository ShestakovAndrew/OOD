#pragma once
#include "IImage.h"
#include "IParagraph.h"
#include <memory>
#include <variant>

class CConstDocumentItem
{
public:
	using Item = std::variant<std::shared_ptr<IImage>, std::shared_ptr<IParagraph>>;

	CConstDocumentItem(Item const& item);

	// Возвращает указатель на константное изображение, либо nullptr,
	// если элемент не является изображением
	std::shared_ptr<const IImage> GetImage() const;

	// Возвращает указатель на константный параграф, либо nullptr, если элемент не является параграфом
	std::shared_ptr<const IParagraph> GetParagraph() const;

	virtual ~CConstDocumentItem() = default;

protected:
	Item m_item;
};