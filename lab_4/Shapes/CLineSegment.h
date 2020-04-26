#include "IShape.h"

class CLineSegment : public IShape
{
	double GetArea() override;
	double GetPerimeter() override;
	std::string ToString() override;
	uint32_t GetOutlineColor() override;
};
