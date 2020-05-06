#include "../Shapes/CShapeProcessor.h"
#include "../catch.hpp"


TEST_CASE("HandleCommand от всех доустпных фигур, возвращает true, если есть формат ввода правильный, иначе false")
{
    // корректный ввод
    std::string inputString = "Rectangle 100 100 20 60 000000 FFFFFF";
    CShapeProcessor processor;
    CHECK(processor.HandleCommand(inputString));

    inputString = "Circle 0 0 200 00FF00 ff00ff";
    CHECK(processor.HandleCommand(inputString));

    inputString = "LineSegment 0 0 200 200 ff00ff";
    CHECK(processor.HandleCommand(inputString));

    inputString = "Triangle 0 0 0 4 3 0 000000 ffffff";
    CHECK(processor.HandleCommand(inputString));

    // неверный ввод

    // c маленькой буквы название
    inputString = "rectangle 100 100 20 60 000000 FFFFFF";
    CHECK(!processor.HandleCommand(inputString));

    // пропущены координаты
    inputString = "Circle 200 00FF00 ff00ff";
    CHECK(!processor.HandleCommand(inputString));

    // лишний цвет
    inputString = "LineSegment 0 0 200 200 ff00ff ffffff";
    CHECK(!processor.HandleCommand(inputString));

    // неправильно введет цвет контура
    inputString = "Triangle 0 0 0 4 3 0 00 ffffff";
    CHECK(!processor.HandleCommand(inputString));

    // неизветный ввод
    inputString = "none";
    CHECK(!processor.HandleCommand(inputString));
}