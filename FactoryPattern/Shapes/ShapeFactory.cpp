#include "ShapeFactory.h"
#include <algorithm>
#include <cctype>
#include <map>
#include <sstream>

std::unique_ptr<CShape> CShapeFactory::CreateShape(std::string const& description) const
{
	Params params = ParseParams(description);
	if (params.empty())
	{
		throw std::invalid_argument("Invalid number of parameters");
	}
	std::string shapeName = params[0];

	auto it = SHAPES_CREATION.find(shapeName);
	if (it != SHAPES_CREATION.end())
	{
		return it->second(params);
	}
	throw std::runtime_error("Invalid name of shape");
}

CShapeFactory::Params CShapeFactory::ParseParams(std::string const& str)
{
	std::stringstream ss(str);
	CShapeFactory::Params params;
	std::string param;

	while (ss >> param)
	{
		std::transform(param.begin(), param.end(), param.begin(), [](char c) { return std::tolower(c); });
		params.push_back(param);
	}
	return params;
}

Color CShapeFactory::GetColor(std::string const& color)
{
	if (color == "red")
	{
		return Color::Red;
	}
	else if (color == "orange")
	{
		return Color::Orange;
	}
	else if (color == "yellow")
	{
		return Color::Yellow;
	}
	else if (color == "green")
	{
		return Color::Green;
	}
	else if (color == "lightblue")
	{
		return Color::LightBlue;
	}
	else if (color == "blue")
	{
		return Color::Blue;
	}
	else if (color == "violet")
	{
		return Color::Violet;
	}
	else if (color == "black")
	{
		return Color::Black;
	}
	else if (color == "white")
	{
		return Color::White;
	}
	else if (color == "pink")
	{
		return Color::Pink;
	}
	else if (color == "skin")
	{
		return Color::Skin;
	}

	throw std::invalid_argument("Unknown color");
}

double CShapeFactory::ToDouble(std::string const& number)
{
	try
	{
		return std::stod(number);
	}
	catch (std::invalid_argument const&)
	{
		throw std::invalid_argument("Failed to create double number");
	}
}

size_t CShapeFactory::ToUnsigned(std::string const& number)
{
	try
	{
		return static_cast<size_t>(std::stoull(number));
	}
	catch (std::invalid_argument const&)
	{
		throw std::invalid_argument("Failed to create unsigned number");
	}
}

std::unique_ptr<CShape> CShapeFactory::CreateLineSegment(Params const& params)
{
	if (params.size() != 6)
	{
		throw std::invalid_argument("Invalid number of parameters");
	}

	Color lineColor = GetColor(params[1]);
	Point startPoint = { ToDouble(params[2]), ToDouble(params[3]) };
	Point endPoint = { ToDouble(params[4]), ToDouble(params[5]) };

	return std::make_unique<CLineSegment>(lineColor, startPoint, endPoint);
}

std::unique_ptr<CShape> CShapeFactory::CreateRectangle(Params const& params)
{
	if (params.size() != 7)
	{
		throw std::invalid_argument("Invalid number of parameters");
	}

	Color outlineColor = GetColor(params[1]);
	Color fillColor = GetColor(params[2]);
	Point leftTop = { ToDouble(params[3]), ToDouble(params[4]) };
	double width = ToDouble(params[5]);
	double height = ToDouble(params[6]);

	return std::make_unique<CRectangle>(outlineColor, fillColor, leftTop, width, height);
}

std::unique_ptr<CShape> CShapeFactory::CreateTriangle(Params const& params)
{
	if (params.size() != 9)
	{
		throw std::invalid_argument("Invalid number of parameters");
	}

	Color outlineColor = GetColor(params[1]);
	Color fillColor = GetColor(params[2]);
	Point vertex1 = { ToDouble(params[3]), ToDouble(params[4]) };
	Point vertex2 = { ToDouble(params[5]), ToDouble(params[6]) };
	Point vertex3 = { ToDouble(params[7]), ToDouble(params[8]) };

	return std::make_unique<CTriangle>(outlineColor, fillColor, vertex1, vertex2, vertex3);
}

std::unique_ptr<CShape> CShapeFactory::CreateCircle(Params const& params)
{
	if (params.size() != 6)
	{
		throw std::invalid_argument("Invalid number of parameters");
	}

	Color outlineColor = GetColor(params[1]);
	Color fillColor = GetColor(params[2]);
	Point center = { ToDouble(params[3]), ToDouble(params[4]) };
	double radius = ToDouble(params[5]);

	return std::make_unique<CCircle>(outlineColor, fillColor, center, radius);
}

std::unique_ptr<CShape> CShapeFactory::CreateEllipse(Params const& params)
{
	if (params.size() != 7)
	{
		throw std::invalid_argument("Invalid number of parameters");
	}

	Color outlineColor = GetColor(params[1]);
	Color fillColor = GetColor(params[2]);
	Point center = { ToDouble(params[3]), ToDouble(params[4]) };
	double horizontalRadius = ToDouble(params[5]);
	double verticalRadius = ToDouble(params[6]);

	return std::make_unique<CEllipse>(outlineColor, fillColor, center, horizontalRadius, verticalRadius);
}

std::unique_ptr<CShape> CShapeFactory::CreateRegularPolygon(Params const& params)
{
	if (params.size() != 7)
	{
		throw std::invalid_argument("Invalid number of parameters");
	}

	Color outlineColor = GetColor(params[1]);
	Color fillColor = GetColor(params[2]);
	size_t vertexCount = ToUnsigned(params[3]);
	Point center = { ToDouble(params[4]), ToDouble(params[5]) };
	double radius = ToDouble(params[6]);

	return std::make_unique<CRegularPolygon>(outlineColor, fillColor, vertexCount, center, radius);
}