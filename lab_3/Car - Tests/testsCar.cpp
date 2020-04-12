#include "../catch.hpp"
#include "../Car/AutoPilot.h"

TEST_CASE("CCar::TurnOnEngine должна включить двигатель, если он был выключен, иначе ошибка.")
{
	CCar car;
	CHECK(car.CCar::TurnOnEngine());
	CHECK(!car.CCar::TurnOnEngine());
}

TEST_CASE("CCar::TurnOffEngine должна выключить двигатель, если он был включен, иначе ошибка.")
{
	CCar car;
	car.CCar::TurnOnEngine();
	CHECK(car.CCar::TurnOffEngine());
	CHECK(!car.CCar::TurnOffEngine());

}

TEST_CASE("CCar::SetGear переключает передачу, если это возможно, иначе ошибка.")
{
	CCar car;
	car.CCar::TurnOnEngine();
	CHECK(car.CCar::SetGear(1));
	CHECK(!car.CCar::SetGear(5));
}

TEST_CASE("CCar::SetSpeed переключает скорость, если это возможно, иначе ошибка.")
{
	CCar car;
	car.CCar::TurnOnEngine();
	CHECK(car.CCar::SetGear(1));
	int speed = 10;
	CHECK(car.CCar::SetSpeed(speed));
	speed = 100;
	CHECK(!car.CCar::SetSpeed(speed));
}

TEST_CASE("AutoPilot::SetSpeed переключает скорость, если это возможно, иначе ошибка.")
{
	AutoPilot car;
	car.AutoPilot::TurnOnEngine();
	int speed = 10;
	CHECK(car.AutoPilot::SetSpeed(speed));
	speed = 100;
	CHECK(car.AutoPilot::SetSpeed(speed));

	speed = 5;
	CHECK(car.AutoPilot::SetSpeed(speed));
}