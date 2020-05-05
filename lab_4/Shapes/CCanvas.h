#pragma once
#include "ICanvas.h"
#include <SFML/Graphics.hpp>

class CCanvas : public ICanvas
{
public:
    explicit CCanvas (sf::RenderWindow &window);
    void DrawLine(CPoint from, CPoint to, uint32_t lineColor) override;
    void FillPolygon(std::vector<CPoint> points, uint32_t fillColor) override;
    void DrawCircle(CPoint center, double radius, uint32_t lineColor) override;
    void FillCircle(CPoint center, double radius, uint32_t fillColor) override;

private:
    sf::RenderWindow &m_window;
};
