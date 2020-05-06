#include "../Shapes/CRectangle.h"
#include "../catch.hpp"
#include "CMockedCanvas.h"

TEST_CASE("Проверка методов Get у фигуры Rectangle")
{
    CPoint leftUpperPoint = {40, 40};
    CPoint bottomRightPoint = {60, 35};
    double width = 20;
    double height = 5;
    uint32_t outlineColor = 000000;
    uint32_t  fillColor = 0xffffff;

    CRectangle rectangle(leftUpperPoint, width, height, fillColor, outlineColor);

    CHECK(rectangle.GetOutlineColor() == outlineColor);
    CHECK(rectangle.GetFillColor() == fillColor);
    CHECK(rectangle.GetHeight() == height);
    CHECK(rectangle.GetWight() == width);
    CHECK(rectangle.GetBottomRightPoint().x == bottomRightPoint.x);
    CHECK(rectangle.GetBottomRightPoint().y == bottomRightPoint.y);
}

TEST_CASE("Методы Rectangle, возвращают периметр, площадь прямоугольника")
{
    CPoint leftUpperPoint = {40, 40};
    CPoint bottomRightPoint = {60, 35};
    double width = 20;
    double height = 5;
    uint32_t outlineColor = 000000;
    uint32_t  fillColor = 0xffffff;

    CRectangle rectangle(leftUpperPoint, width, height, fillColor, outlineColor);

    CHECK(rectangle.GetPerimeter() == Approx(50.0).epsilon(0.001));
    CHECK(rectangle.GetArea() == Approx(100).epsilon(0.001));
}

TEST_CASE("Метод Draw у прямоугольника")
{
    CMockedCanvas canvas;
    CPoint leftUpperPoint = {40, 40};
    CPoint bottomRightPoint = {60, 35};
    double width = 20;
    double height = 5;
    uint32_t outlineColor = 000000;
    uint32_t  fillColor = 0xffffff;

    CRectangle rectangle(leftUpperPoint, width, height, fillColor, outlineColor);
    rectangle.Draw(canvas);

    std::vector<std::string> resultActionHistory = {"FillPolygon", "DrawLine", "DrawLine", "DrawLine", "DrawLine"};
    CHECK(canvas.GetActionHistory() == resultActionHistory);
}