#pragma once
#include "SolidShape.h"

class CRectangle : public CSolidShape
{
public:
	CRectangle(Color outlineColor, Color fillColor, Point const& leftTop, double width, double height);

	void Draw(ICanvas& canvas) const override;
	Point GetLeftTop() const;
	Point GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

private:
	Point m_leftTop;
	double m_width;
	double m_height;
};
