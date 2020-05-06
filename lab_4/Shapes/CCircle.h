#pragma once
#include "ISolidShape.h"

class CCircle : public ISolidShape
{
public:
	CCircle(CPoint center, double radius, uint32_t outlineColor, uint32_t fillColor);
	[[nodiscard]] double GetArea() const override;
	[[nodiscard]] double GetPerimeter() const override;
	[[nodiscard]] double GetRadius() const;

	[[nodiscard]] std::string ToString() const override;

	[[nodiscard]] uint32_t GetOutlineColor() const override;
	[[nodiscard]] uint32_t GetFillColor() const override;
    void Draw(ICanvas& canvas) override;

	[[nodiscard]] CPoint GetCenter() const;

private:
    [[nodiscard]] static std::string ConvertColor(uint32_t color);
	CPoint m_center{};
	double m_radius;
	uint32_t m_fillColor;
	uint32_t m_outlineColor;
};

