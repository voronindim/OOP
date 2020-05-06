#include "CMockedCanvas.h"

void CMockedCanvas::DrawLine(CPoint from, CPoint to, uint32_t lineColor)
{
    m_actionHistory.emplace_back("DrawLine");
}

void CMockedCanvas::FillPolygon(std::vector<CPoint> points, uint32_t fillColor)
{
    m_actionHistory.emplace_back("FillPolygon");
}

void CMockedCanvas::DrawCircle(CPoint center, double radius, uint32_t lineColor)
{
    m_actionHistory.emplace_back("DrawCircle");
}

void CMockedCanvas::FillCircle(CPoint center, double radius, uint32_t fillColor)
{
    m_actionHistory.emplace_back("FillCircle");
}

std::vector<std::string> CMockedCanvas::GetActionHistory() const
{
    return m_actionHistory;
}
