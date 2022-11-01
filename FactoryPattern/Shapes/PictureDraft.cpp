#include "PictureDraft.h"
#include <stdexcept>

size_t CPictureDraft::GetShapeCount() const
{
	return m_shapes.size();
}

CShape& CPictureDraft::GetShape(size_t index) const
{
	if (index >= m_shapes.size())
	{
		throw std::out_of_range("Index is out of range");
	}

	return *m_shapes.at(index).get();
}

void CPictureDraft::AddShape(std::unique_ptr<CShape>&& shape)
{
	m_shapes.push_back(std::move(shape));
}
