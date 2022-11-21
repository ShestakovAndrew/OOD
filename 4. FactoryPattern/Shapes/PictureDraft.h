#pragma once
#include "Shape.h"
#include <memory>
#include <vector>

class CPictureDraft
{
public:
	size_t GetShapeCount() const;
	CShape& GetShape(size_t index) const;

	void AddShape(std::unique_ptr<CShape>&& shape);

private:
	std::vector<std::unique_ptr<CShape>> m_shapes{};
};
