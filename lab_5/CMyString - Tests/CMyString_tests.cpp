#include "../catch.hpp"
#include "../CMyString/CMyString.h"
#include <sstream>

TEST_CASE("Тестирование конструкторов")
{
    CMyString myString;
    CHECK(myString.GetLength() == 0);
    CHECK(myString.GetStringDate() == std::string());

    CMyString myString1("hello");
    CHECK(myString1.GetLength() == 5);
    CHECK(myString1.GetStringDate() == std::string("hello"));

    CMyString myString2("hello world", 5);
    CHECK(myString2.GetLength() == 5);
    CHECK(myString2.GetStringDate() == std::string("hello"));

    CMyString myString3("hello\0world", 11);
    CHECK(myString3.GetLength() == 11);
    CHECK(myString3.GetStringDate() == std::string("hello\0world"));

    CMyString myString4(myString3);
    CHECK(myString4.GetLength() == 11);
    CHECK(myString4.GetStringDate() == std::string("hello\0world"));

    CMyString myString5(std::string("hello world"));
    CHECK(myString5.GetLength() == 11);
    CHECK(myString5.GetStringDate() == std::string("hello world"));
}

TEST_CASE("Проверка метода SubString")
{
    CMyString myString("hello\0world", 11);
    CMyString substr = myString.SubString(3);
    CHECK(substr.GetLength() == 8);
    CHECK(substr.GetStringDate() == std::string("lo\0world"));
//    CHECK_THROWS_AS(myString.SubString(12), std::runtime_error);
}

TEST_CASE("Проверка метода Clear")
{
    CMyString myString("hello");
    myString.Clear();
    CHECK(myString.GetLength() == 0);
    CHECK(myString.GetStringDate() == std::string());
}

TEST_CASE("Првоерка оператора =")
{
    CMyString myString = CMyString("hello");
    CHECK(myString.GetLength() == 5);
    CHECK(myString.GetStringDate() == std::string("hello"));

    myString = CMyString("hell");
    CHECK(myString.GetLength() == 4);
    CHECK(myString.GetStringDate() == std::string("hell"));
}

TEST_CASE("Проверка оператора +")
{
    CMyString resultString = "hello" + CMyString(" world");
    CHECK(resultString.GetLength() == 11);
    CHECK(resultString.GetStringDate() == std::string("hello world"));

    CMyString resultString1 = CMyString("hello") + CMyString(" world");
    CHECK(resultString1.GetLength() == 11);
    CHECK(resultString1.GetStringDate() == std::string("hello world"));

    CMyString resultString2 = CMyString("hello") + CMyString("\0") + CMyString("world");
    CHECK(resultString2.GetLength() == 10);
    CHECK(resultString2.GetStringDate() == std::string("helloworld"));
}

TEST_CASE("Првоерка оператора +=")
{
    CMyString myString = CMyString("hello");
    myString += CMyString(" world");
    CHECK(myString.GetLength() == 11);
    CHECK(myString.GetStringDate() == std::string("hello world"));

    CMyString myString1 = CMyString("123");
    myString1 += myString1;
    CHECK(myString1.GetLength() == 6);
    CHECK(myString1.GetStringDate() == std::string("123123"));
}

TEST_CASE("Проверка оператора ==")
{
    CMyString myString("hello");
    CMyString myString1("hello");
    CMyString myString2("world");
    CHECK(myString == myString1);
    CHECK(!(myString == myString2));
}

TEST_CASE("Проверка оператора !=")
{
    CMyString myString("hello");
    CMyString myString1("hello");
    CMyString myString2("world");
    CHECK(myString1 != myString2);
    CHECK(!(myString1 != myString));
}

TEST_CASE("Првоерка оператора <")
{
    CMyString myString("hello world");
    CMyString myString1("hello");
    CMyString myString2("a");
    CHECK(myString1 < myString);
    CHECK(myString2 < myString1);
    CHECK(!(myString1 < myString2));
}

TEST_CASE("Првоерка оператора >")
{
    CMyString myString("hello world");
    CMyString myString1("hello");
    CMyString myString2("a");
    CHECK(myString > myString2);
    CHECK(myString > myString1);
    CHECK(!(myString1 > myString));
}

TEST_CASE("Првоерка оператора <=")
{
    CMyString myString("hello world");
    CMyString myString1("hello");
    CMyString myString2("a");
    CMyString myString3("hello");
    CHECK(myString1 <= myString);
    CHECK(myString2 <= myString1);
    CHECK(myString1 <= myString3);
    CHECK(!(myString <= myString2));
    CHECK(!(myString <= myString1));
}

TEST_CASE("Првоерка оператора >=")
{
    CMyString myString("hello world");
    CMyString myString1("hello");
    CMyString myString2("a");
    CMyString myString3("hello");
    CHECK(myString >= myString1);
    CHECK(myString3 >= myString1);
    CHECK(myString3 >= myString2);
    CHECK(!(myString2 >= myString3));
    CHECK(!(myString1 >= myString));
}

TEST_CASE("Проверка []")
{
    CMyString myString("hello");
    CHECK(myString[0] == 'h');
    myString[3] = 'p';
    CHECK(myString == std::string("helpo"));

    CHECK_THROWS_AS(myString[10], std::runtime_error);
}

TEST_CASE("Проверка оператора <<")
{
    CMyString myString;
    std::stringstream ss;
    ss << "hello";
    ss >> myString;
    CHECK(myString.GetLength() == 5);
    CHECK(myString.GetStringDate() == std::string("hello"));
}

TEST_CASE("Првоерка оператора >>")
{
    CMyString myString("hello", 5);
    std::stringstream ss;
    ss << myString;
    CHECK(ss.str() == std::string("hello"));
}

