#include "ISolidShape.h"
#include "CPoint.h"
#include <string>

class CTriangle : ISolidShape
{
public:
	CTriangle( CPoint vertex1, CPoint vertex2, CPoint vertex3, uint32_t outlineColor, uint32_t fillCOlor);
	[[nodiscard]] double GetArea() const;
	[[nodiscard]] double GetPerimeter() const;
	[[nodiscard]] std::string ToString() const;

	[[nodiscard]] uint32_t GetOutlineColor() const;
	[[nodiscard]] uint32_t GetFillColor() const;

	[[nodiscard]] CPoint GetVertex1() const;
	[[nodiscard]] CPoint GetVertex2() const;
	[[nodiscard]] CPoint GetVertex3() const;

private:
	CPoint m_vertex1{};
	CPoint m_vertex2{};
	CPoint m_vertex3{};

	uint32_t m_fillColor{};
	uint32_t m_outlineColor{};
//	[[nodiscard]] double GetLength(CPoint point1, CPoint point2) const;
};

