#include "CPoint.h"
#include "IShape.h"

class CLineSegment : public IShape
{
	CLineSegment(CPoint startPoint, CPoint endPoint, uint32_t outlineColor);

	[[nodiscard]] double GetArea() const;
	[[nodiscard]] double GetPerimeter() const;

	[[nodiscard]] std::string ToString() const;

	[[nodiscard]] uint32_t GetOutlineColor() const;
	[[nodiscard]] CPoint GetStartPoint() const;
	[[nodiscard]] CPoint GetEndPoint() const;

private:
	uint32_t m_outlineColor;
	CPoint m_startPoint;
	CPoint m_endPoint;
};
