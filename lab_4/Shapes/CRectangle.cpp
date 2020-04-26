#include "CRectangle.h"

CRectangle::CRectangle(CPoint topLeft, double wight, double height, uint32_t fillColor, uint32_t outlineColor)
{
	this->m_topLeft = topLeft;
	this->m_width = wight;
	this->m_height = height;
	this->m_fillColor = fillColor;
	this->m_outlineColor = outlineColor;
}

double CRectangle::GetArea()
{
	return m_height * m_width;
}

double CRectangle::GetPerimeter()
{
	return 2 * (m_height + m_width);
}

std::string CRectangle::ToString()
{
	return "Верхняя левая вершина имеет координаты: " + std::to_string(m_topLeft.x) + " " +  std::to_string(m_topLeft.y) + "\n" +
	"Высота: " + std::to_string(m_height) + "\n" +
	"Ширина" + std::to_string(m_width) + "\n";
}

uint32_t CRectangle::GetOutlineColor()
{
	return 0;
}

CPoint CRectangle::GetTopLeftPoint()
{
	return m_topLeft;
}

CPoint CRectangle::GetBottomRightPoint()
{
	CPoint rightBottomPoint{};
	rightBottomPoint.x = m_topLeft.x + m_width;
	rightBottomPoint.y = m_topLeft.y + m_height;
	return rightBottomPoint;
}

double CRectangle::GetHeight()
{
	return m_height;
}

double CRectangle::GetWight()
{
	return m_width;
}

uint32_t CRectangle::GetFillColor()
{
	return m_fillColor;
}

