#include "CCanvas.h"

using namespace sf;

CCanvas::CCanvas(RenderWindow& window)
    : m_window(window)
{
}

Color ConvertColor(uint32_t color)
{
    return Color((color / (256 * 256) % 256), (color / (256) % 256), (color % 256));
}

void CCanvas::DrawLine(CPoint from, CPoint to, uint32_t lineColor)
{
    Vertex line[] =
            {
                    Vertex(Vector2f(from.x, (float)m_window.getSize().y - from.y)),
                    Vertex(Vector2f(to.x, (float)m_window.getSize().y - to.y))
            };
    line[0].color = ConvertColor(lineColor);
    line[1].color = ConvertColor(lineColor);
    m_window.draw(line, 2, Lines);
}

void CCanvas::FillPolygon(std::vector<CPoint> points, uint32_t fillColor)
{
    ConvexShape convexShape;
    convexShape.setPointCount(points.size());
    for (size_t i = 0; i < points.size(); i++)
    {
        convexShape.setPoint(i, Vector2f(points[i].x, (float)m_window.getSize().y - points[i].y));
    }
    convexShape.setFillColor(ConvertColor(fillColor));
    m_window.draw(convexShape);
}

void CCanvas::DrawCircle(CPoint center, double radius, uint32_t lineColor)
{
    CircleShape circle((float)radius);
    circle.setOutlineColor(ConvertColor(lineColor));
    circle.setOrigin((float)radius, (float)radius);
    circle.setOutlineThickness(0.5);
    circle.move((float)center.x, (float)m_window.getSize().y - (float)center.y);
    m_window.draw(circle);
}

void CCanvas::FillCircle(CPoint center, double radius, uint32_t fillColor)
{
    CircleShape circle((float)radius);
    circle.setFillColor(ConvertColor(fillColor));
    circle.setOrigin((float)radius, (float)radius);
    circle.move((float)center.x, (float)m_window.getSize().y - (float)center.y);
    m_window.draw(circle);
}



