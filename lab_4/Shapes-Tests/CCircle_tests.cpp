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