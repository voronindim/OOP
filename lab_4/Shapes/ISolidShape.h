#pragma once
#include "IShape.h"

class ISolidShape : public IShape
{
public:
	[[nodiscard]] virtual uint32_t GetFillColor() const = 0;
};

