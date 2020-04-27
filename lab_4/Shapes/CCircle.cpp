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
	return std::string();
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
