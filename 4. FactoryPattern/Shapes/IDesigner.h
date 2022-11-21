#pragma once
#include "PictureDraft.h"

class IDesigner
{
public:
	virtual CPictureDraft CreateDraft(std::istream& stream) const = 0;
	virtual ~IDesigner() = default;
};
