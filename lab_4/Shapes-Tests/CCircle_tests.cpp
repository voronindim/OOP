#include "../Shapes/CCircle.h"
#include "../catch.hpp"
#include "CMockedCanvas.h"

TEST_CASE("Проверка методов Get у фигуры Circle")
{
    CPoint center = {0, 0};
    double radius = 5;
    uint32_t outlineColor = 0xffffff;
    uint32_t fillColor = 000000;

    CCircle circle(center, radius, outlineColor, fillColor);

    CHECK(circle.GetCenter().x == center.x);
    CHECK(circle.GetCenter().y == center.y);
    CHECK(circle.GetRadius() == radius);
    CHECK(circle.GetFillColor() == fillColor);
    CHECK(circle.GetOutlineColor() == outlineColor);
}

TEST_CASE("Методы Circle, возвращают периметр, площадь круга")
{
    CPoint center = {0, 0};
    double radius = 5;
    uint32_t outlineColor = 0xffffff;
    uint32_t fillColor = 000000;

    CCircle circle(center, radius, outlineColor, fillColor);

    CHECK(circle.GetPerimeter() == Approx(31.415).epsilon(0.0001));
    CHECK(circle.GetArea() == Approx(78.539).epsilon(0.001));
}

TEST_CASE("Метод Draw у круга")
{
    CMockedCanvas canvas;
    CPoint center = {0, 0};
    double radius = 5;
    uint32_t outlineColor = 0xffffff;
    uint32_t fillColor = 000000;

    CCircle circle(center, radius, outlineColor, fillColor);
    circle.Draw(canvas);

    std::vector<std::string> resultActionHistory = {"DrawCircle", "FillCircle"};
    CHECK(canvas.GetActionHistory() == resultActionHistory);
}

TEST_CASE("Метод toString вернет информацию о фигуре")
{
    CPoint center = {0, 0};
    double radius = 5;
    uint32_t outlineColor = 0xffffff;
    uint32_t fillColor = 0x001100;

    CCircle circle(center, radius, outlineColor, fillColor);

    std::string resultString = "Координаты центра окружности: 0.000000 0.000000\n"
                               "Радиус: 5.000000\n"
                               "Плоащдь: 78.539816\n"
                               "Периметр: 31.415927\n"
                               "Цвет контура: ffffff\n"
                               "Цвет заливки: 1100\n";
    CHECK(circle.ToString() == resultString);
}