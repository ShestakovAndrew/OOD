#pragma once
#include "Shape.h"

class CLineSegment : public CShape
{
public:
	CLineSegment(Color lineColor, Point const& startPoint, Point const& endPoint);

	void Draw(ICanvas& canvas) const override;
	Point GetStartPoint() const;
	Point GetEndPoint() const;

private:
	Point m_startPoint;
	Point m_endPoint;
};

