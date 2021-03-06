#pragma once
#include "IShape.h"


class CLineSegment : public IShape
{
public:
	CLineSegment(CPoint startPoint, CPoint endPoint, uint32_t outlineColor);
	[[nodiscard]] double GetArea() const override;
	[[nodiscard]] double GetPerimeter()  const override;

	[[nodiscard]] std::string ToString() const override;

	[[nodiscard]] uint32_t GetOutlineColor() const override;
	[[nodiscard]] CPoint GetStartPoint() const;
	[[nodiscard]] CPoint GetEndPoint() const;
	void Draw(ICanvas& canvas) override;
private:
    [[nodiscard]] static std::string ConvertColor(uint32_t color);
	uint32_t m_outlineColor;
	CPoint m_startPoint{};
	CPoint m_endPoint{};
};
