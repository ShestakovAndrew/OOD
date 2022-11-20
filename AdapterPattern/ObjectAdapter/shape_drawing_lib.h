#pragma once
#include "graphics_lib.h"

namespace shape_drawing_lib
{
struct Point
{
	int x;
	int y;
};

class ICanvasDrawable
{
public:
	virtual void Draw(graphics_lib::ICanvas& canvas) const = 0;
	virtual ~ICanvasDrawable() = default;
};

class CTriangle : public ICanvasDrawable
{
public:
	CTriangle(const Point& vertex1, const Point& vertex2, const Point& vertex3)
		: m_vertex1(vertex1)
		, m_vertex2(vertex2)
		, m_vertex3(vertex3)
	{
	}

	void Draw(graphics_lib::ICanvas& canvas) const override
	{
		canvas.MoveTo(m_vertex1.x, m_vertex1.y);
		canvas.LineTo(m_vertex2.x, m_vertex2.y);
		canvas.LineTo(m_vertex3.x, m_vertex3.y);

		canvas.MoveTo(m_vertex2.x, m_vertex2.y);
		canvas.LineTo(m_vertex3.x, m_vertex3.y);
	}

private:
	Point m_vertex1;
	Point m_vertex2;
	Point m_vertex3;
};

class CRectangle : public ICanvasDrawable
{
public:
	CRectangle(const Point& leftTop, int width, int height)
		: m_leftTop(leftTop)
		, m_width(width)
		, m_height(height)
	{
	}

	void Draw(graphics_lib::ICanvas& canvas) const override
	{
		canvas.MoveTo(m_leftTop.x, m_leftTop.y);
		canvas.LineTo(m_leftTop.x + m_width, m_leftTop.y);
		canvas.LineTo(m_leftTop.x, m_leftTop.y - m_height);

		canvas.MoveTo(m_leftTop.x + m_width, m_leftTop.y - m_height);
		canvas.LineTo(m_leftTop.x, m_leftTop.y - m_height);
		canvas.LineTo(m_leftTop.x + m_width, m_leftTop.y);
	}

private:
	Point m_leftTop;
	int m_width;
	int m_height;
};

class CCanvasPainter
{
public:
	CCanvasPainter(graphics_lib::ICanvas& canvas)
		: m_canvas(canvas)
	{
	}
	void Draw(const ICanvasDrawable& drawable)
	{
		drawable.Draw(m_canvas);
	}

private:
	graphics_lib::ICanvas& m_canvas;
};

} // namespace shape_drawing_lib