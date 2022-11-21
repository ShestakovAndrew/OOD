#pragma once
#include "PictureDraft.h"

class CPainter
{
public:
	void DrawPicture(CPictureDraft const& draft, ICanvas& canvas) const;
};
