#pragma once
#include "Shape.h"

class CSolidShape : public CShape
{
public:
	CSolidShape(Color outlineColor, Color fillColor);

	virtual void Draw(ICanvas& canvas) const = 0;
	Color GetFillColor() const;

	virtual ~CSolidShape() = default;

protected:
	Color m_fillColor;
};

