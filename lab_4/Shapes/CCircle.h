#include "ISolidShape.h"
#include "CPoint.h"

class CCircle : public ISolidShape
{
	CCircle(CPoint center, double radius, uint32_t outlineColor, uint32_t fillColor);
	[[nodiscard]] double GetArea() const;
	[[nodiscard]] double GetPerimeter() const;
	[[nodiscard]] double GetRadius() const;

	[[nodiscard]] std::string ToString() const;

	[[nodiscard]] uint32_t GetOutlineColor() const;
	[[nodiscard]] u_int32_t GetFillColor() const;

	[[nodiscard]] CPoint GetCenter() const;

private:
	CPoint m_center{};
	double m_radius;
	uint32_t m_fillColor;
	uint32_t m_outlineColor;
};

