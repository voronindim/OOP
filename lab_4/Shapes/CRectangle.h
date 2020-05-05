#pragma once
#include "CPoint.h"
#include "ISolidShape.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle(CPoint topLeft, double wight, double height,  uint32_t fillColor, uint32_t outlineColor);

	[[nodiscard]] double GetArea() const override;
	[[nodiscard]] double GetPerimeter() const override;
	[[nodiscard]] std::string ToString() const override;

	[[nodiscard]] uint32_t GetOutlineColor() const override;
	[[nodiscard]] uint32_t GetFillColor() const override;
	void Draw(ICanvas& canvas) override;

	[[nodiscard]] CPoint GetTopLeftPoint() const;
	[[nodiscard]] CPoint GetBottomRightPoint() const;

	[[nodiscard]] double GetHeight() const;
	[[nodiscard]] double GetWight() const;

private:
	CPoint m_topLeft{};
	double m_height{};
	double m_width{};
	uint32_t m_fillColor{};
	uint32_t m_outlineColor{};
};

