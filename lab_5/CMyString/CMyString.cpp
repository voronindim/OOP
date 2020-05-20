#include "CMyString.h"
#include <iostream>

CMyString::CMyString()
{
    this->m_pString = new char[1];
    this->m_length = 0;
    m_pString[0] = '\0';
}

CMyString::CMyString(const char *pString)
{
    this->m_length = strlen(pString);
    m_pString = new char[m_length + 1];
    memcpy(m_pString, pString, m_length + 1);
}

CMyString::CMyString(const char *pString, size_t length)
{
    this->m_length = length;
    this->m_pString = new char[length + 1];
    memcpy(m_pString, pString, length);
    m_pString[m_length] = '\0';
}

CMyString::CMyString(const CMyString &other)
{
    this->m_length = other.GetLength();
    this->m_pString = new char[other.GetLength() + 1];
    memcpy(m_pString, other.GetStringDate(), m_length + 1);
}

CMyString::CMyString(CMyString &&other) noexcept
{
    this->m_length = other.m_length;
    this->m_pString = other.m_pString;
    other.m_pString = nullptr;
    other.m_length = 0;
}

using namespace std;

CMyString::CMyString(const std::string &stlString)
{
    this->m_length = stlString.length();
    this->m_pString = new char[stlString.length() + 1];
    memcpy(m_pString, stlString.c_str(), m_length + 1);
}

CMyString::~CMyString()
{
    delete[] m_pString;
}

size_t CMyString::GetLength() const
{
    return m_length;
}

const char *CMyString::GetStringDate() const
{
    return m_pString;
}

CMyString CMyString::SubString(size_t start, size_t length) const
{
    if (start >= length)
    {
        throw runtime_error("Начальная позиция больше длины строки");
    }
    return {m_pString + start, min(length, m_length - start)};
}

void CMyString::Clear()
{
    m_length = 0;
    delete[] m_pString;
    m_pString = new char[1];
    m_pString[0] = '\0';
}

CMyString &CMyString::operator=(const CMyString &other)
{
    if (this != &other)
    {
        CMyString temp(other);
        std::swap(m_length, temp.m_length);
        std::swap(m_pString, temp.m_pString);
    }
    return *this;
}

CMyString &CMyString::operator=(CMyString &&other) noexcept
{
    if (&other != this)
    {
        delete[] m_pString;
        m_length = other.m_length;
        m_pString = other.m_pString;
        other.m_length = 0;
        other.m_pString = nullptr;
    }
    return *this;
}

CMyString &CMyString::operator+=(const CMyString &other)
{
    *this = *this + other;
    return *this;
}

const char &CMyString::operator[](size_t index) const
{
    if (index < m_length)
    {
        return m_pString[index];
    }
    throw runtime_error("Номер элеманта больше длины строки");
}

char &CMyString::operator[](size_t index)
{
    if (index < m_length)
    {
        return m_pString[index];
    }
    throw runtime_error("Номер элеманта больше длины строки");
}

CMyString operator+(const CMyString &str, const CMyString &str1)
{
    size_t newLength = str.GetLength() + str1.GetLength();
    char* newString = new char[newLength];
    memcpy(newString, str.GetStringDate(), str.GetLength());
    memcpy(newString + str.GetLength(), str1.GetStringDate(), str1.GetLength());
    return {newString, newLength};
}

bool operator==(CMyString &str, CMyString &str1)
{
    if (str.GetLength() == str1.GetLength())
    {
        for(size_t i = 0; i < str.GetLength(); i++)
        {
            if (str[i] != str1[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool operator!=(CMyString str, CMyString str1)
{
    return !(str == str1);
}

bool operator<(CMyString &str, CMyString &str1)
{
    for (size_t i = 0; i < min(str.GetLength(), str1.GetLength()); i++)
    {
        if (str[i] < str1[i])
        {
            return true;
        }
        if (str[i] > str1[i])
        {
            return false;
        }
    }
    return str.GetLength() < str1.GetLength();
}

bool operator>(CMyString &str, CMyString &str1)
{
    return str1 < str;
}

bool operator<=(CMyString &str, CMyString &str1)
{
    return !(str > str1);
}

bool operator>=(CMyString &str, CMyString &str1)
{
    return !(str < str1);
}

std::ostream &operator<<(std::ostream &ostream, const CMyString &str)
{
    for (size_t i = 0; i < str.GetLength(); i++)
    {
        ostream << str[i];
    }
    return ostream;
}

std::istream &operator>>(std::istream &istream, CMyString &str)
{
    std::string input;
    istream >> input;
    str = CMyString(input);
    return istream;
}