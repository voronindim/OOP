#include "CCircle.h"
#include <cmath>

CCircle::CCircle(CPoint center, double radius, uint32_t outlineColor, uint32_t fillColor)
{
	this->m_center = center;
	this->m_radius = radius;
	this->m_outlineColor = outlineColor;
	this->m_fillColor = fillColor;
}
double CCircle::GetArea() const
{
	return M_PI * pow((m_radius), 2);
}
double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}
double CCircle::GetRadius() const
{
	return m_radius;
}
std::string CCircle::ToString() const
{
	return "Координаты центра окружности: " + std::to_string(m_center.x) + " " + std::to_string(m_center.y) + "\n" +
	"Радиус: " + std::to_string(m_radius) + "\n" +
	"Плоащдь: " + std::to_string(GetArea()) + "\n" +
	"Периметр: " + std::to_string(GetPerimeter()) + "\n" +
	"Цвет контура: " + std::to_string(m_outlineColor) + "\n" +
	"Цвет заливки: " + std::to_string(m_fillColor) + "\n";
}
uint32_t CCircle::GetOutlineColor() const
{
	return m_outlineColor;
}
u_int32_t CCircle::GetFillColor() const
{
	return m_fillColor;
}
CPoint CCircle::GetCenter() const
{
	return m_center;
}

void CCircle::Draw(ICanvas &canvas)
{
    canvas.DrawCircle(m_center, m_radius, m_outlineColor);
    canvas.FillCircle(m_center, m_radius, m_fillColor);
}
