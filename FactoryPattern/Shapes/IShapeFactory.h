#pragma once
#include "Shape.h"
#include <string>
#include <memory>

class IShapeFactory
{
public:
	virtual std::unique_ptr<CShape> CreateShape(std::string const& description) const = 0;
	virtual ~IShapeFactory() = default;
};
