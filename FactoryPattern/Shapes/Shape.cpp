#include "Shape.h"

CShape::CShape(Color outlineColor)
	: m_outlineColor(outlineColor)
{
}

Color CShape::GetOutlineColor() const
{
	return m_outlineColor;
}