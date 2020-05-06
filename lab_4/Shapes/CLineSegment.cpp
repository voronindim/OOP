#include "CLineSegment.h"
#include <cmath>
#include <sstream>

CLineSegment::CLineSegment(CPoint startPoint, CPoint endPoint, uint32_t outlineColor)
{
	this->m_startPoint = startPoint;
	this->m_endPoint = endPoint;
	this->m_outlineColor = outlineColor;
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	CPoint startPoint = GetStartPoint();
	CPoint endPoint = GetEndPoint();
	return sqrt(pow((startPoint.x - endPoint.x), 2) + pow((startPoint.y - endPoint.y), 2));
}

std::string CLineSegment::ToString() const
{
	return "Начало линии: " + std::to_string(m_startPoint.x) + " " + std::to_string(m_startPoint.y) + "\n" +
	"Конец линии: " + std::to_string(m_endPoint.x) + " " + std::to_string(m_endPoint.y) + "\n" +
	"Цвет линии: " + ConvertColor(m_outlineColor) + "\n";
}

uint32_t CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

void CLineSegment::Draw(ICanvas &canvas)
{
    canvas.DrawLine(m_startPoint, m_endPoint, m_outlineColor);
}

std::string CLineSegment::ConvertColor(uint32_t color)
{
    std::stringstream ss;
    ss << std::hex << color;
    return ss.str();
}

