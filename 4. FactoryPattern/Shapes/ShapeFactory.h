#pragma once
#include <vector>
#include <functional>
#include <map>

#include "IShapeFactory.h"
#include "LineSegment.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Ellipse.h"
#include "RegularPoligon.h"

class CShapeFactory : public IShapeFactory
{

public:
	std::unique_ptr<CShape> CreateShape(std::string const& description) const override;

private:
	using Params = std::vector<std::string>;

	using Handler = std::function<std::unique_ptr<CShape>(Params const& params)>;
	using ActionMap = std::map<std::string, Handler>;

	const ActionMap SHAPES_CREATION = {
		{ "line", std::bind(&CreateLineSegment, std::placeholders::_1) },
		{ "rectangle", std::bind(&CreateRectangle, std::placeholders::_1) },
		{ "triangle", std::bind(&CreateTriangle, std::placeholders::_1) },
		{ "circle", std::bind(&CreateCircle, std::placeholders::_1) },
		{ "ellipse", std::bind(&CreateEllipse, std::placeholders::_1) },
		{ "regularpolygon", std::bind(&CreateRegularPolygon, std::placeholders::_1) } };

	static std::unique_ptr<CShape> CreateLineSegment(Params const& params);
	static std::unique_ptr<CShape> CreateRectangle(Params const& params);
	static std::unique_ptr<CShape> CreateTriangle(Params const& params);
	static std::unique_ptr<CShape> CreateCircle(Params const& params);
	static std::unique_ptr<CShape> CreateEllipse(Params const& params);
	static std::unique_ptr<CShape> CreateRegularPolygon(Params const& params);

	static Params ParseParams(std::string const& str);
	static Color GetColor(std::string const& color);
	static double ToDouble(std::string const& number);
	static size_t ToUnsigned(std::string const& number);
};
