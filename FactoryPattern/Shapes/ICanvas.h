#pragma once
#include <vector>

#include "Color.h"
#include "Point.h"

class ICanvas
{
public:
	virtual void SetFillColor(Color fillColor) = 0;
	virtual void SetOutlineColor(Color outlineColor) = 0;

	virtual void DrawLine(Point const& from, Point const& to) = 0;
	virtual void DrawCircle(Point const& center, double radius) = 0;
	virtual void DrawEllipse(Point const& center, double horizontalRadius, double verticalRadius) = 0;
	virtual void DrawPoligon(std::vector<Point> const& points) = 0;

	virtual ~ICanvas() = default;
};
