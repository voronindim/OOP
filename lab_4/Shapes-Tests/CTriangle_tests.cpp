#include "../Shapes/CTriangle.h"
#include "../catch.hpp"
#include "CMockedCanvas.h"

TEST_CASE("Проверка методов Get у фигуры Triangle")
{
    CPoint vertex1 = {0, 0};
    CPoint vertex2 = {200, 0};
    CPoint vertex3 = {100, 300};
    uint32_t outlineColor = 000000;
    uint32_t fillColor = 0xffff00;

    CTriangle triangle(vertex1, vertex2, vertex3, outlineColor, fillColor);

    CHECK(triangle.GetFillColor() == fillColor);
    CHECK(triangle.GetOutlineColor() == outlineColor);
    CHECK(triangle.GetVertex1().x == vertex1.x);
    CHECK(triangle.GetVertex1().y == vertex1.y);

    CHECK(triangle.GetVertex2().x == vertex2.x);
    CHECK(triangle.GetVertex2().y == vertex2.y);

    CHECK(triangle.GetVertex3().x == vertex3.x);
    CHECK(triangle.GetVertex3().y == vertex3.y);
}

TEST_CASE("Методы Triangle, возвращают периметр, площадь треугольника")
{
    CPoint vertex1 = {0, 0};
    CPoint vertex2 = {4, 0};
    CPoint vertex3 = {0, 3};
    uint32_t outlineColor = 000000;
    uint32_t fillColor = 0xffff00;

    CTriangle triangle(vertex1, vertex2, vertex3, outlineColor, fillColor);

    CHECK(triangle.GetArea() == Approx(6).epsilon(0.001));
    CHECK(triangle.GetPerimeter() == Approx(12).epsilon(0.001));
}

TEST_CASE("Метод Draw у треугольника")
{
    CMockedCanvas canvas;
    CPoint vertex1 = {0, 0};
    CPoint vertex2 = {4, 0};
    CPoint vertex3 = {0, 3};
    uint32_t outlineColor = 000000;
    uint32_t fillColor = 0xffff00;

    CTriangle triangle(vertex1, vertex2, vertex3, outlineColor, fillColor);
    triangle.Draw(canvas);

    std::vector<std::string> resultActionHistory = {"FillPolygon", "DrawLine", "DrawLine", "DrawLine"};
    CHECK(canvas.GetActionHistory() == resultActionHistory);
}