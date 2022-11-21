#pragma once
#include "Color.h"
#include "ICanvas.h"

class CShape
{
public:
	CShape(Color outlineColor);

	virtual void Draw(ICanvas& canvas) const = 0;
	Color GetOutlineColor() const;

	virtual ~CShape() = default;

protected:
	Color m_outlineColor;
};
