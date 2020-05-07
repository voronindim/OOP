#include "../Shapes/CLineSegment.h"
#include "../catch.hpp"
#include "CMockedCanvas.h"

TEST_CASE("Проверка методов Get у CLineSegment")
{
    CPoint from = {0,0};
    CPoint to = {100, 100};
    uint32_t color = 001100;

    CLineSegment line(from, to, color);

    CHECK(line.GetOutlineColor() == color);
    CHECK(line.GetEndPoint().x == to.x);
    CHECK(line.GetEndPoint().y == to.y);
    CHECK(line.GetStartPoint().x == from.x);
    CHECK(line.GetStartPoint().x == from.x);
}

TEST_CASE("Методы ClineSegment, возвращают периметр, площадь равную 0")
{
    CPoint from = {0,0};
    CPoint to = {100, 100};
    uint32_t color = 001100;

    CLineSegment line(from, to, color);

    CHECK(line.GetArea() == 0);
    CHECK(line.GetPerimeter() == Approx(141.421).epsilon(0.001));
}

TEST_CASE("Метод Draw у линии")
{
    CMockedCanvas canvas;
    CPoint from = {0,0};
    CPoint to = {100, 100};
    uint32_t color = 001100;

    CLineSegment line(from, to, color);

    line.Draw(canvas);
    std::vector<std::string> resultActionHistory = {"DrawLine"};
    CHECK(canvas.GetActionHistory() == resultActionHistory);
}

TEST_CASE("Метод toString вернет информацию о линии")
{
    CMockedCanvas canvas;
    CPoint from = {0,0};
    CPoint to = {100, 100};
    uint32_t color = 0xffffff;

    CLineSegment line(from, to, color);

    std::string resultString = "Начало линии: 0.000000 0.000000\n"
                               "Конец линии: 100.000000 100.000000\n"
                               "Цвет линии: ffffff\n";

    CHECK(line.ToString() == resultString);
}