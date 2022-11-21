#include "Circle.h"

CCircle::CCircle(Color outlineColor, Color fillColor, Point const& center, double radius)
	: CSolidShape(outlineColor, fillColor)
	, m_center(center)
	, m_radius(radius)
{
}

void CCircle::Draw(ICanvas& canvas) const
{
	canvas.SetOutlineColor(m_outlineColor);
	canvas.SetFillColor(m_fillColor);
	canvas.DrawCircle(m_center, m_radius);
}

Point CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}
