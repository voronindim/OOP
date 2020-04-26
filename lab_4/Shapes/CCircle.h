#include "ISolidShape.h"

class CCircle : public ISolidShape
{
	double GetArea() override;
	double GetPerimeter() override;
	std::string ToString() override;
	uint32_t GetOutlineColor() override;

};

