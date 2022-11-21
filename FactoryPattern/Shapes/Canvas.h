#pragma once
#include "ICanvas.h"
#include "Color.h"

#include <SFML/Graphics.hpp>
#pragma comment(lib, "winmm.lib")

class CCanvas : public ICanvas
{
public:
	CCanvas(sf::RenderTarget& renderTarget);

	void SetFillColor(Color fillColor) override;
	void SetOutlineColor(Color outlineColor) override;

	void DrawLine(Point const& from, Point const& to) override;
	void DrawCircle(Point const& center, double radius) override;
	void DrawEllipse(Point const& center, double horizontalRadius, double verticalRadius) override;
	void DrawPoligon(std::vector<Point> const& points) override;

private:
	sf::CircleShape CreateCircleShape(Point const& center, double radius);
	sf::Vector2f GetCoordOnCanvas(Point const& point);
	sf::Color ToSFMLColor(Color color);
	void SetShapeColor(sf::ConvexShape& shape);

	int m_width;
	int m_height;
	sf::Color m_fillColor;
	sf::Color m_outlineColor;
	sf::RenderTarget& m_renderTarget;
};