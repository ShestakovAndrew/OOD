#include "Rectangle.h"

CRectangle::CRectangle(Color outlineColor, Color fillColor, Point const& leftTop, double width, double height)
	: CSolidShape(outlineColor, fillColor)
	, m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
{
}

void CRectangle::Draw(ICanvas& canvas) const
{
	Point rightBottom = GetRightBottom();
	Point leftBottom{ m_leftTop.x, rightBottom.y };
	Point rightTop{ rightBottom.x, m_leftTop.y };

	canvas.SetOutlineColor(m_outlineColor);
	canvas.SetFillColor(m_fillColor);
	canvas.DrawPoligon({ m_leftTop, leftBottom, rightBottom, rightTop });
}

Point CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

Point CRectangle::GetRightBottom() const
{
	return { m_leftTop.x + m_width, m_leftTop.y - m_height };
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}
