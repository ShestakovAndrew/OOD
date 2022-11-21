#pragma once
#include "SolidShape.h"
#include <vector>

class CRegularPolygon : public CSolidShape
{
public:
	CRegularPolygon(Color outlineColor, Color fillColor, size_t vertexCount, Point const& center, double radius);

	void Draw(ICanvas& canvas) const override;
	std::vector<Point> GetVertexes() const;
	size_t GetVertexCount() const;
	Point GetCenter() const;
	double GetRadius() const;

private:
	size_t m_vertexCount;
	Point m_center;
	double m_radius;
};
