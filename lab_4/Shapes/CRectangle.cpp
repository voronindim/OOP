#include "CRectangle.h"

CRectangle::CRectangle(CPoint topLeft, double wight, double height, uint32_t fillColor, uint32_t outlineColor)
{
	this->m_topLeft = topLeft;
	this->m_width = wight;
	this->m_height = height;
	this->m_fillColor = fillColor;
	this->m_outlineColor = outlineColor;
}

double CRectangle::GetArea() const
{
	return m_height * m_width;
}

double CRectangle::GetPerimeter() const
{
	return 2 * (m_height + m_width);
}

std::string CRectangle::ToString() const
{
	return "Верхняя левая вершина имеет координаты: " + std::to_string(m_topLeft.x) + " " +  std::to_string(m_topLeft.y) + "\n" +
	"Высота: " + std::to_string(m_height) + "\n" +
	"Ширина" + std::to_string(m_width) + "\n";
}

uint32_t CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

CPoint CRectangle::GetTopLeftPoint() const
{
	return m_topLeft;
}

CPoint CRectangle::GetBottomRightPoint() const
{
	CPoint rightBottomPoint{};
	rightBottomPoint.x = m_topLeft.x + m_width;
	rightBottomPoint.y = m_topLeft.y + m_height;
	return rightBottomPoint;
}

double CRectangle::GetHeight() const
{
	return m_height;
}

double CRectangle::GetWight() const
{
	return m_width;
}

uint32_t CRectangle::GetFillColor() const
{
	return m_fillColor;
}

