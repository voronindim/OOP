#include "CRational.h"
#include <tuple>

CRational::CRational()
{
	this->m_numerator = 0;
	this->m_denominator = 1;
}

CRational::CRational(int value)
{
	this->m_numerator = value;
	this->m_denominator = 1;
}

CRational::CRational(int numerator, int denominator)
{
	if (denominator == 0)
	{
		throw std::runtime_error("Знаменатель не может быть равен 0");
	}
	this->m_numerator = numerator;
	this->m_denominator = denominator;
	ReductionOfFraction();
}

int FindGreatestCommandDivisor(int num1, int num2)
{
	while (num2 != 0)
	{
		num1 %= num2;
		std::swap(num1, num2);
	}
	return num1;
}

void CRational::ReductionOfFraction()
{
	int greatestCommandDivisor = FindGreatestCommandDivisor(m_numerator, m_denominator);
	m_numerator /= greatestCommandDivisor;
	m_denominator /= greatestCommandDivisor;
	if (m_denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = abs(m_denominator);
	}
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

double CRational::ToDouble() const
{
	return ((double)m_numerator / (double)m_denominator);
}

CRational CRational::operator+() const
{
	return {m_numerator, m_denominator};
}

CRational CRational::operator-() const
{
	return {-m_numerator, m_denominator};
}

CRational& CRational::operator+=(const CRational& rational)
{
	m_numerator = rational.GetDenominator() * m_numerator + rational.GetNumerator() * m_denominator;
	m_denominator *= rational.GetDenominator();
	ReductionOfFraction();
	return *this;
}

CRational& CRational::operator-=(const CRational& rational)
{
	m_numerator = rational.GetDenominator() * m_numerator - rational.GetNumerator() * m_denominator;
	m_denominator *= rational.GetDenominator();
	ReductionOfFraction();
	return *this;
}

CRational& CRational::operator*=(const CRational& rational)
{
	m_numerator *= rational.GetNumerator();
	m_denominator *= rational.GetDenominator();
	ReductionOfFraction();
	return *this;
}
CRational& CRational::operator/=(const CRational& rational)
{
	if (rational == 0)
	{
		throw std::runtime_error("Деление на 0");
	};
	m_numerator *= rational.GetDenominator();
	m_denominator *= rational.GetNumerator();
	ReductionOfFraction();
	return *this;
}
std::pair<int, CRational> CRational::ToCompoundFraction() const
{
	int integerPart = m_numerator / m_denominator;
	int numerator = m_numerator % m_denominator;
	return std::make_pair(integerPart, CRational{numerator, m_denominator});
}

bool operator==(const CRational& rational, const CRational& rational1)
{
	return (rational.GetNumerator() == rational1.GetNumerator() && rational.GetDenominator() == rational1.GetDenominator());
}

bool operator!=(const CRational& rational, const CRational& rational1)
{
	return !(rational == rational1);
}

bool operator<(const CRational& rational, const CRational& rational1)
{
	int num = rational.GetNumerator() * rational1.GetDenominator();
	int num1 = rational1.GetNumerator() * rational.GetDenominator();
	return num < num1;
}

bool operator>(const CRational& rational, const CRational& rational1)
{
	int num = rational.GetNumerator() * rational1.GetDenominator();
	int num1 = rational1.GetNumerator() * rational.GetDenominator();
	return num > num1;
}

bool operator<=(const CRational& rational, const CRational& rational1)
{
	int num = rational.GetNumerator() * rational1.GetDenominator();
	int num1 = rational1.GetNumerator() * rational.GetDenominator();
	return num <= num1;
}

bool operator>=(const CRational& rational, const CRational& rational1)
{
	int num = rational.GetNumerator() * rational1.GetDenominator();
	int num1 = rational1.GetNumerator() * rational.GetDenominator();
	return num >= num1;
}

CRational operator+(const CRational& rational, const CRational& rational1)
{
	int resultNumerator = rational.GetNumerator() * rational1.GetDenominator() + rational1.GetNumerator() * rational.GetDenominator();
	int resultDenominator = rational.GetDenominator() * rational1.GetDenominator();
	return {resultNumerator, resultDenominator};
}

CRational operator-(const CRational& rational, const CRational& rational1)
{
	int resultNumerator = rational.GetNumerator() * rational1.GetDenominator() - rational1.GetNumerator() * rational.GetDenominator();
	int resultDenominator = rational.GetDenominator() * rational1.GetDenominator();
	return {resultNumerator, resultDenominator};
}

CRational operator*(const CRational& rational, const CRational& rational1)
{
	int resultNumerator = rational.GetNumerator() * rational1.GetNumerator();
	int resultDenominator = rational.GetDenominator() * rational1.GetDenominator();
	return {resultNumerator, resultDenominator};
}

CRational operator/(const CRational& rational, const CRational& rational1)
{
	if (rational1 == 0)
	{
		throw std::runtime_error("Деление на 0");
	}
	int resultNumerator = rational.GetNumerator() * rational1.GetDenominator();
	int resultDenominator = rational.GetDenominator() * rational1.GetNumerator();
	return {resultNumerator, resultDenominator};
}

std::ostream& operator<<(std::ostream& ostream, const CRational& rational)
{
	ostream << rational.GetNumerator() << '/' << rational.GetDenominator();
	return ostream;
}

std::istream& operator>>(std::istream& istream, CRational& rational)
{
	int numerator, denominator;
	if ((istream >> numerator) && (istream.get() == '/') && (istream >> denominator))
	{
		rational = CRational(numerator, denominator);
	}
	else
	{
		istream.setstate(std::ios_base::failbit | istream.rdstate());
	}
	return istream;
}
