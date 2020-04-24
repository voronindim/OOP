#include "../NewCar/CAutoPilot.h"
#include "MockedCar.h"
#include "../catch.hpp"
#include <iostream>

TEST_CASE("Нужная скорость достигается с помощью последовательного переключения передач и скоростей")
{
	MockedCar car;
	auto autoPilot = CAutoPilot(car);

	// переключение скорости до 100

	autoPilot.TurnOnEngine();
	autoPilot.SetSpeed(100);
    std::vector<int> resultVariants = { 1, 30, 2, 50, 3, 60, 4, 90, 5, 100 };
    CHECK(resultVariants == car.variants);
    car.variants = {};

    // переключение скорости со 100 до 30

    autoPilot.SetSpeed(0);
    resultVariants = { 50, 4, 40, 3, 30, 2, 20, 1, 0 };
    CHECK(resultVariants == car.variants);
    car.variants = {};
}

TEST_CASE("Переключить авто на нужную передачу")
{
	MockedCar car;
	auto autoPilot = CAutoPilot(car);
	autoPilot.TurnOnEngine();

	// переключение на заднюю передачу
	autoPilot.SetSpeed(150);
	car.variants = {};
	std::vector<int> resultVariants = { 50, 4, 40, 3, 30, 2, 20, 1, 0, -1, 10 };

	CHECK(autoPilot.BackwardGear());
	autoPilot.SetSpeed(10);
	CHECK(car.variants == resultVariants);
	car.variants = {};

	// включение передней передачи при скорости 10 и движении назад
	CHECK(autoPilot.ForwardGear());
	autoPilot.SetSpeed(5);
	resultVariants = { 0, 1, 5 };
	CHECK(car.variants == resultVariants);
	car.variants = {};

	// включение нейтральной передачи и выключение авто
	CHECK(!autoPilot.NeutralGear());
	autoPilot.SetSpeed(0);
	resultVariants = {0, 0};
	CHECK(autoPilot.NeutralGear());
	CHECK(car.variants == resultVariants);
	CHECK(autoPilot.TurnOffEngine());
	CHECK(!autoPilot.ReturnEngineOn());
}

