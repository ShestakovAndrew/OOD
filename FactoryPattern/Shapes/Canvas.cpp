#include "Canvas.h"

CCanvas::CCanvas(sf::RenderTarget& renederTarget)
	: m_renderTarget(renederTarget)
{
	m_width = renederTarget.getSize().x;
	m_height = renederTarget.getSize().y;
}

void CCanvas::SetFillColor(Color fillColor)
{
	m_fillColor = ToSFMLColor(fillColor);
}

void CCanvas::SetOutlineColor(Color outlineColor)
{
	m_outlineColor = ToSFMLColor(outlineColor);
}

void CCanvas::DrawLine(Point const& from, Point const& to)
{
	sf::Vertex line[] = 
	{
		sf::Vertex(GetCoordOnCanvas(from)),
		sf::Vertex(GetCoordOnCanvas(to))
	};
	line[0].color = m_outlineColor;
	line[1].color = m_outlineColor;
	m_renderTarget.draw(line, 2, sf::Lines);
}

void CCanvas::DrawEllipse(Point const& center, double horizontalRadius, double verticalRadius)
{
	sf::CircleShape ellipse(static_cast<float>(horizontalRadius));

	ellipse.setOrigin(static_cast<float>(horizontalRadius), static_cast<float>(horizontalRadius));
	ellipse.move(GetCoordOnCanvas(center));
	ellipse.setScale(3.f, static_cast<float>(verticalRadius / horizontalRadius));

	ellipse.setOutlineColor(m_outlineColor);
	ellipse.setOutlineThickness(3.f);
	ellipse.setFillColor(m_fillColor);

	m_renderTarget.draw(ellipse);
}

void CCanvas::DrawCircle(Point const& center, double radius)
{
	sf::CircleShape circle = CreateCircleShape(center, radius);

	circle.setOutlineColor(m_outlineColor);
	circle.setOutlineThickness(3.f);
	circle.setFillColor(m_fillColor);

	m_renderTarget.draw(circle);
}

void CCanvas::DrawPoligon(std::vector<Point> const& points)
{
	sf::ConvexShape shape;
	shape.setPointCount(points.size());

	for (size_t pointCount = 0; pointCount < points.size(); pointCount++)
	{
		shape.setPoint(pointCount, GetCoordOnCanvas(points[pointCount]));
	}

	SetShapeColor(shape);
	m_renderTarget.draw(shape);
}

sf::CircleShape CCanvas::CreateCircleShape(Point const& center, double radius)
{
	sf::CircleShape circle(static_cast<float>(radius));
	circle.setOrigin(static_cast<float>(radius), static_cast<float>(radius));
	circle.move(GetCoordOnCanvas(center));
	return circle;
}

sf::Vector2f CCanvas::GetCoordOnCanvas(Point const& point)
{
	return sf::Vector2f(static_cast<float>(point.x), m_height - static_cast<float>(point.y));
}

sf::Color CCanvas::ToSFMLColor(Color color)
{
	switch (color)
	{
	case Color::Red: return sf::Color::Red;
	case Color::Orange: return sf::Color(255, 165, 0);
	case Color::Yellow: return sf::Color::Yellow;
	case Color::Green: return sf::Color::Green;
	case Color::LightBlue: return sf::Color(173, 216, 230);
	case Color::Blue: return sf::Color::Blue;
	case Color::Violet: return sf::Color(238, 130, 238);
	case Color::Black: return sf::Color::Black;
	case Color::White: return sf::Color::White;
	case Color::Pink: return sf::Color(255, 20, 147);
	case Color::Skin: return sf::Color(255, 219, 184);
	default: throw std::exception("Error translate color to SFML color!");
	}
}

void CCanvas::SetShapeColor(sf::ConvexShape& shape) {
	shape.setOutlineColor(m_outlineColor);
	shape.setOutlineThickness(3.f);
	shape.setFillColor(m_fillColor);
}