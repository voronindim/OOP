#include <utility>
#include <string>
class IShape
{
public:
	virtual double GetArea() = 0;
	virtual double GetPerimeter() = 0;
	virtual std::string ToString() = 0;
	virtual uint32_t GetOutlineColor() = 0;
};

