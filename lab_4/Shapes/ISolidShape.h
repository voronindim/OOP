#include "IShape.h"

class ISolidShape : public IShape
{
public:
	virtual uint32_t GetFillColor() = 0;
};

