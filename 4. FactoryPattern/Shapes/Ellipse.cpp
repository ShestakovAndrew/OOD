#include "Ellipse.h"

CEllipse::CEllipse(Color outlineColor, Color fillColor, Point const& center, double horizontalRadius, double verticalRadius)
	: CSolidShape(outlineColor, fillColor)
	, m_center(center)
	, m_horizontalRadius(horizontalRadius)
	, m_verticalRadius(verticalRadius)
{
}

void CEllipse::Draw(ICanvas& canvas) const
{
	canvas.SetOutlineColor(m_outlineColor);
	canvas.SetFillColor(m_fillColor);
	canvas.DrawEllipse(m_center, m_horizontalRadius, m_verticalRadius);
}

Point CEllipse::GetCenter() const
{
	return m_center;
}

double CEllipse::GetHorizontalRadius() const
{
	return m_horizontalRadius;
}

double CEllipse::GetVerticalRadius() const
{
	return m_verticalRadius;
}
