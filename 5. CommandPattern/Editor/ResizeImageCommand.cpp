#include "ResizeImageCommand.h"

CResizeImageCommand::CResizeImageCommand(int& width, int& height, int newWidth, int newHeight)
	: m_width(width)
	, m_height(height)
{
	if (newWidth < 1 || newHeight < 1 || newWidth > 10000 || newHeight > 10000)
	{
		throw std::invalid_argument("image size cannot be negative");
	}
	m_newWidth = newWidth;
	m_newHeight = newHeight;
}

void CResizeImageCommand::DoExecute()
{
	std::swap(m_height, m_newHeight);
	std::swap(m_width, m_newWidth);
}

void CResizeImageCommand::DoUnexecute()
{
	std::swap(m_height, m_newHeight);
	std::swap(m_width, m_newWidth);
}
