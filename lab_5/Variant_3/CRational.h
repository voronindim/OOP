#pragma once
#include <iostream>
#include <utility>

class CRational
{
public:
	CRational(int numerator = 0, int denominator = 1);

	int GetNumerator() const;
	int GetDenominator() const;

	double ToDouble() const;

	CRational operator+() const;
	CRational operator-() const;

	CRational& operator+=(const CRational& rational);
	CRational& operator-=(const CRational& rational);
	CRational& operator*=(const CRational& rational);
	CRational& operator/=(const CRational& rational);

	std::pair<int, CRational> ToCompoundFraction() const;
private:

	void ReductionOfFraction();
	int m_numerator;
	int m_denominator;

};

CRational operator+(const CRational& rational, const CRational& rational1);
CRational operator-(const CRational& rational, const CRational& rational1);
CRational operator*(const CRational& rational, const CRational& rational1);
CRational operator/(const CRational& rational, const CRational& rational1);

bool operator==(const CRational& rational, const CRational& rational1);
bool operator!=(const CRational& rational, const CRational& rational1);
bool operator<(const CRational& rational, const CRational& rational1);
bool operator>(const CRational& rational, const CRational& rational1);
bool operator<=(const CRational& rational, const CRational& rational1);
bool operator>=(const CRational& rational, const CRational& rational1);

std::ostream& operator<<(std::ostream& ostream, const CRational& rational);
std::istream& operator>>(std::istream& istream, CRational& rational);