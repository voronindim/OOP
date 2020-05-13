#include "../Variant_3/CRational.h"
#include "../catch.hpp"
#include <sstream>

TEST_CASE("Создание дроби 0/1")
{
    CRational rational;
    CHECK(rational.GetNumerator() == 0);
    CHECK(rational.GetDenominator() == 1);
}

TEST_CASE("Создание дроби m/1")
{
    CRational rational(10);
    CHECK(rational.GetNumerator() == 10);
    CHECK(rational.GetDenominator() == 1);
}

TEST_CASE("Создание дроби m/n")
{
    CRational rational(10, 11);
    CHECK(rational.GetNumerator() == 10);
    CHECK(rational.GetDenominator() == 11);
}

TEST_CASE("Срабатывает ошибка о делении на 0")
{
    CHECK_THROWS(CRational(10, 0));
}

TEST_CASE("Числитель отрицательный")
{
    CRational rational(-1, 5);
    CHECK(rational.GetNumerator() == -1);
    CHECK(rational.GetDenominator() == 5);
}

TEST_CASE("Входная дробь имеет отрицательный знаменатель, преобразует числитель в отрицательное число, знаменатель в положительное")
{
    CRational rational(1, -5);
    CHECK(rational.GetNumerator() == -1);
    CHECK(rational.GetDenominator() == 5);
}

TEST_CASE("Числитель и знаминатель отрицательные")
{
    CRational rational(-1, -5);
    CHECK(rational.GetNumerator() == 1);
    CHECK(rational.GetDenominator() == 5);
}

TEST_CASE("Сокращение дробей")
{
    CRational rational(5, 10);
    CHECK(rational.GetNumerator() == 1);
    CHECK(rational.GetDenominator() == 2);

    CRational rational1(10, 2);
    CHECK(rational1.GetNumerator() == 5);
    CHECK(rational1.GetDenominator() == 1);
}

TEST_CASE("Приведение дроби к смешаному виду")
{
    CRational rational(13, 5);
    std::pair<int, CRational> result = rational.ToCompoundFraction();
    CHECK(result.first == 2);
    CHECK(result.second == CRational(3, 5));
}

TEST_CASE("Проверка унарного плюса, вернет число неизменным")
{
    CRational rational(-6, 7);
    CRational result = +rational;
    CHECK(result.GetNumerator() == -6);
    CHECK(result.GetDenominator() == 7);
}

TEST_CASE("Проверка унарного минуса, вернет число с противоположны знаком")
{
    CRational rational(-6, 7);
    CRational result = -rational;
    CHECK(result.GetNumerator() == 6);
    CHECK(result.GetDenominator() == 7);

    CRational rational1(6, -7);
    CRational result1 = -rational1;
    CHECK(result1.GetNumerator() == 6);
    CHECK(result1.GetDenominator() == 7);
}

TEST_CASE("Проверка бинарного плюса, складывает дроби")
{
    CRational rational(12, 6);
    CRational rational1(12, 6);
    CRational result = rational + rational1;
    CHECK(result.GetNumerator() == 4);
    CHECK(result.GetDenominator() == 1);

    CRational rational2(5, 3);
    CRational result2 = rational + rational2;
    std::pair<int, CRational> resultPair = result2.ToCompoundFraction();
    CHECK(resultPair.first == 3);
    CHECK(resultPair.second == CRational(2, 3));
}

TEST_CASE("Проверка бинарного минуса, вычетает дроби")
{
    CRational rational(12, 6);
    CRational rational1(12, 6);
    CRational result = rational - rational1;
    CHECK(result.GetNumerator() == 0);
    CHECK(result.GetDenominator() == 1);
}

TEST_CASE("ПРоверка умножение дробей")
{
    CRational rational(3, 5);
    CRational rational1(7, 10);
    CRational result = rational * rational1;
    CHECK(result.GetNumerator() == 21);
    CHECK(result.GetDenominator() == 50);
}

TEST_CASE("Проверка деление дробей")
{
    CRational rational(5);
    CRational rational1(5);
    CRational result = rational / rational1;
    CHECK(result.GetNumerator() == 1);
    CHECK(result.GetDenominator() == 1);

    CRational rational2(-5);
    CRational rational3(5);
    CRational result2 = rational2 / rational3;
    CHECK(result2.GetNumerator() == -1);
    CHECK(result2.GetDenominator() == 1);
}

TEST_CASE("Проверка += прибавение числа к числу")
{
    CRational rational(1, 5);
    CRational rational1(2, 5);
    rational += rational1;
    CHECK(rational.GetNumerator() == 3);
    CHECK(rational.GetDenominator() == 5);
}

TEST_CASE("Проверка -= вычетание дроби из дроби")
{
    CRational rational(1, 5);
    CRational rational1(2, 5);
    rational -= rational1;
    CHECK(rational.GetNumerator() == -1);
    CHECK(rational.GetDenominator() == 5);
}

TEST_CASE("Проверка *= умножение двух дробей")
{
    CRational rational(1, 6);
    CRational rational1(2, 6);
    rational *= rational1;
    CHECK(rational.GetNumerator() == 1);
    CHECK(rational.GetDenominator() == 18);
}

TEST_CASE("Проверка /= деление двух дробей")
{
    CRational rational(1, 6);
    CRational rational1(2, 6);
    rational /= rational1;
    CHECK(rational.GetNumerator() == 1);
    CHECK(rational.GetDenominator() == 2);
}

TEST_CASE("Проверка == сравнение двух дробей, возвращает true, если дроби равны, иначе false")
{
    CRational rational(3, 6);
    CRational rational1(2, 4);
    CRational rational2(2, 6);
    CHECK(rational == rational1);
    CHECK(!(rational == rational2));
}

TEST_CASE("Проверка != сравнение двух дробей, возвращает false, если дроби равны, иначе true")
{
    CRational rational(3, 6);
    CRational rational1(2, 4);
    CRational rational2(2, 6);
    CHECK(!(rational != rational1));
    CHECK(rational != rational2);
}

TEST_CASE("Проверка <= >= < > сравнение двух дробей")
{
    CRational rational(3, 6);
    CRational rational1(2, 4);
    CRational rational2(2, 6);
    CHECK(rational <= rational1);
    CHECK(rational >= rational1);
    CHECK(rational > rational2);
    CHECK(rational2 < rational);
    CHECK(!(rational <= rational2));
    CHECK(!(rational2 > rational));
    CHECK(!(rational < rational2));
}

TEST_CASE("Проверка работы дроби с потоком")
{
    CRational rational(3, 5);
    std::stringstream ss;
    ss << rational;
    CHECK(ss.str() == "3/5");

    CRational rational1;
    ss >> rational1;
    CHECK(rational1.GetNumerator() == 3);
    CHECK(rational1.GetDenominator() == 5);
}

TEST_CASE("Ошибка при неправильном вводе")
{
    std::stringstream ss;
    ss << 3.14;
    CRational rational;
    ss >> rational;
    CHECK(ss.fail());
}
