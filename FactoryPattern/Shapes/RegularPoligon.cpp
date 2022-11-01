#include "RegularPoligon.h"
#include <stdexcept>

const double PI = 3.1416;

CRegularPolygon::CRegularPolygon(Color outlineColor, Color fillColor, size_t vertexCount, Point const& center, double radius)
	: CSolidShape(outlineColor, fillColor)
	, m_center(center)
	, m_radius(radius)
{
	if (vertexCount < 3)
	{
		throw std::invalid_argument("Vertex count must be more than 2");
	}
	m_vertexCount = vertexCount;
}

void CRegularPolygon::Draw(ICanvas& canvas) const
{
	canvas.SetOutlineColor(m_outlineColor);
	canvas.SetFillColor(m_fillColor);
	canvas.DrawPoligon(GetVertexes());
}

std::vector<Point> CRegularPolygon::GetVertexes() const
{
	std::vector<Point> vertexes;
	double offsetAngle = 2 * PI / m_vertexCount;

	for (size_t i = 0; i < m_vertexCount; i++)
	{
		vertexes.push_back({
			m_center.x + m_radius * cos(offsetAngle * i),
			m_center.y + m_radius * sin(offsetAngle * i),
			});
	}

	return vertexes;
}

size_t CRegularPolygon::GetVertexCount() const
{
	return m_vertexCount;
}

Point CRegularPolygon::GetCenter() const
{
	return m_center;
}

double CRegularPolygon::GetRadius() const
{
	return m_radius;
}
