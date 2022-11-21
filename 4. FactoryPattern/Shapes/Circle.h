#pragma once
#include "SolidShape.h"

class CCircle : public CSolidShape
{
public:
	CCircle(Color outlineColor, Color fillColor, Point const& center, double radius);

	void Draw(ICanvas& canvas) const override;
	Point GetCenter() const;
	double GetRadius() const;

private:
	Point m_center;
	double m_radius;
};

