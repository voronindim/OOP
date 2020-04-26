#include "CTriangle.h"
#include <cmath>
CTriangle::CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, uint32_t outlineColor, uint32_t fillColor)
{
	this->m_vertex1 = vertex1;
	this->m_vertex2 = vertex2;
	this->m_vertex3 = vertex3;
	this->m_outlineColor = outlineColor;
	this->m_fillColor = fillColor;
}

double CTriangle::GetArea() const
{
	return abs((m_vertex2.x - m_vertex1.x) * (m_vertex3.y - m_vertex1.y) -
	(m_vertex3.x - m_vertex1.x) * (m_vertex2.y - m_vertex1.y) / 2);
}

double GetLength( CPoint point1, CPoint point2 )
{
	return sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));
}

double CTriangle::GetPerimeter() const
{
	return GetLength(m_vertex1, m_vertex2) + GetLength(m_vertex1, m_vertex3) + GetLength(m_vertex2, m_vertex3);
}
std::string CTriangle::ToString() const
{
	return "Вершина треугольника №1: " + std::to_string(m_vertex1.x) + " " + std::to_string(m_vertex1.y) + "\n" +
		"Вершина треугольника №2: " + std::to_string(m_vertex2.x) + " " + std::to_string(m_vertex2.y) + "\n" +
		"Вершина треугольника №3: " + std::to_string(m_vertex3.x) + " " + std::to_string(m_vertex3.y) + "\n" +
		"Периметр: " + std::to_string(GetPerimeter()) + "\n" +
		"Площадь: " + std::to_string(GetArea()) + "\n" +
		"Цвет контура: " + std::to_string(m_outlineColor) + "\n" +
		"Цвет заливки: " + std::to_string(m_fillColor) + "\n";
}
uint32_t CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
}
uint32_t CTriangle::GetFillColor() const
{
	return m_fillColor;
}
CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}
CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}
CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}

