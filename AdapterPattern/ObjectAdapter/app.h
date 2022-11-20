#pragma once
#include "modern_graphics_lib.h"
#include "shape_drawing_lib.h"

namespace app
{
class CModernGraphicsAdapter : public graphics_lib::ICanvas
	{
	public:
		CModernGraphicsAdapter(modern_graphics_lib::CModernGraphicsRenderer& renderer)
			: m_renderer(renderer)
		{
		}

		void MoveTo(int x, int y) override
		{
			m_start = { x, y };
		}

		void LineTo(int x, int y) override
		{
			modern_graphics_lib::CPoint end(x, y);
			m_renderer.DrawLine(m_start, end);
		}

	private:
		modern_graphics_lib::CModernGraphicsRenderer& m_renderer;
		modern_graphics_lib::CPoint m_start;
	};

void PaintPicture(shape_drawing_lib::CCanvasPainter& painter)
{
	using namespace shape_drawing_lib;

	CTriangle triangle({ 10, 15 }, { 100, 200 }, { 150, 250 });
	CRectangle rectangle({ 30, 40 }, 18, 24);

	painter.Draw(triangle);
	painter.Draw(rectangle);
}

void PaintPictureOnCanvas()
{
	graphics_lib::CCanvas simpleCanvas;
	shape_drawing_lib::CCanvasPainter painter(simpleCanvas);
	PaintPicture(painter);
}

void PaintPictureOnModernGraphicsRenderer()
{
	modern_graphics_lib::CModernGraphicsRenderer renderer(std::cout);
	renderer.BeginDraw();
	CModernGraphicsAdapter canvas(renderer);
	shape_drawing_lib::CCanvasPainter painter(canvas);
	PaintPicture(painter);
}
} // namespace app
