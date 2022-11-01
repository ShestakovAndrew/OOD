#include "SolidShape.h"

CSolidShape::CSolidShape(Color outlineColor, Color fillColor)
    : CShape(outlineColor)
    , m_fillColor(fillColor)
{
}

Color CSolidShape::GetFillColor() const
{
    return m_fillColor;
}