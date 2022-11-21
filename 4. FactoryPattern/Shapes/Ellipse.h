#pragma once
#include "SolidShape.h"

class CEllipse : public CSolidShape
{
public:
	CEllipse(Color outlineColor, Color fillColor, Point const& center, double horizontalRadius, double verticalRadius);

	void Draw(ICanvas& canvas) const override;
	Point GetCenter() const;
	double GetHorizontalRadius() const;
	double GetVerticalRadius() const;

private:
	Point m_center;
	double m_horizontalRadius;
	double m_verticalRadius;
};
