#pragma once
#include <utility>
#include <string>
class IShape
{
public:
	virtual ~IShape()= default;
	[[nodiscard]] virtual double GetArea() const = 0 ;
	[[nodiscard]] virtual double GetPerimeter() const = 0;
	[[nodiscard]] virtual std::string ToString() const = 0;
	[[nodiscard]] virtual uint32_t GetOutlineColor() const = 0;
};

