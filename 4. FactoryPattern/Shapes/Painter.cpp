#include "Painter.h"

void CPainter::DrawPicture(CPictureDraft const& draft, ICanvas& canvas) const
{
	for (size_t i = 0; i < draft.GetShapeCount(); i++)
	{
		CShape& shape = draft.GetShape(i);
		shape.Draw(canvas);
	}
}
