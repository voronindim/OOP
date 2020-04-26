#include "CPoint.h"
#include "ISolidShape.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle(CPoint topLeft, double wight, double height,  uint32_t fillColor, uint32_t outlineColor);

	double GetArea() override;
	double GetPerimeter() override;
	std::string ToString() override;

	uint32_t GetOutlineColor() override;
	uint32_t GetFillColor() override;

	CPoint GetTopLeftPoint();
	CPoint GetBottomRightPoint();

	double GetHeight();
	double GetWight();

private:
	CPoint m_topLeft{};
	double m_height{};
	double m_width{};
	uint32_t m_fillColor{};
	uint32_t m_outlineColor{};
};

