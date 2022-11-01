#include "LineSegment.h"

CLineSegment::CLineSegment(Color lineColor, Point const& startPoint, Point const& endPoint)
	: CShape(lineColor)
	, m_startPoint(startPoint)
	, m_endPoint(endPoint)
{
}

void CLineSegment::Draw(ICanvas& canvas) const
{
	canvas.SetOutlineColor(m_outlineColor);
	canvas.DrawLine(m_startPoint, m_endPoint);
}

Point CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

Point CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}
