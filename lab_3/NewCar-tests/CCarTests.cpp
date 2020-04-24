#include "../NewCar/CCar.h"
#include "../catch.hpp"

TEST_CASE("TurnOnEngine после включения, двигатель всегда включен")
{
	// Меняется состояние двигателя на вкл
	CCar car;
	CHECK(car.TurnOnEngine());
	CHECK(car.ReturnEngineOn());
	// После повторного включения, состояние двигателя не меняется
	CHECK(!car.TurnOnEngine());
	CHECK(car.ReturnEngineOn());
}

TEST_CASE("TurnOffEngine выключает двигатель, до включения")
{
	// Выключает двигатель, переводит в состояние false
	CCar car;
	car.TurnOnEngine();
	CHECK(car.TurnOffEngine());
	CHECK(!car.ReturnEngineOn());

	// После повторного выключения, состояние неменяется
	CHECK(!car.TurnOffEngine());
	CHECK(!car.ReturnEngineOn());
}

TEST_CASE("SetGear переключает передачу,если это возможно, иначе состояние не меняется")
{
	// Включение первой передачи
	CCar car;
	car.TurnOnEngine();
	CHECK(car.SetGear(1));
	CHECK(car.ReturnCurrentGear() == 1);

	// Невозможное переключение не меняет состония
	CHECK(!car.SetGear(5));
	CHECK(car.ReturnCurrentGear() == 1);

	// Нельзя перелючиться на -1 передачу, если скорость не 0, даже если направление Back
	CHECK(car.SetGear(1));
	CHECK(car.SetGear(-1));
	CHECK(car.SetSpeed(10));
	CHECK(car.SetGear(0));
	CHECK(!car.SetGear(-1));
	CHECK(car.ReturnCurrentDirection() == Direction::Back);
	CHECK(car.ReturnCurrentGear() == 0);
}

TEST_CASE("SetSpeed изменяет скорость, если это возможно, иначе состояние не меняется")
{
	// Переключение скорости на первой передаче
	CCar car;
	car.TurnOnEngine();
	car.SetGear(1);
	CHECK(car.SetSpeed(30));
	CHECK(car.ReturnCurrentSpeed() == 30);

	// Переключение невозможно, остается текущая скорость
	CHECK(!car.SetSpeed(40));
	CHECK(car.ReturnCurrentSpeed() == 30);

	// Переключение скорости на второй передачи
	car.SetGear(2);
	CHECK(car.SetSpeed(50));
	CHECK(car.ReturnCurrentSpeed() == 50);

	// Переключение невозможно, остается текущая скорость
	CHECK(!car.SetSpeed(51));
	CHECK(car.ReturnCurrentSpeed() == 50);

	// Переключение скорости на третей передаче
	car.SetGear(3);
	CHECK(car.SetSpeed(60));
	CHECK(car.ReturnCurrentSpeed() == 60);

	// Переключение невозможно, остается текущая скорость
	CHECK(!car.SetSpeed(61));
	CHECK(car.ReturnCurrentSpeed() == 60);

	// Переключение на четвертой скорости
	car.SetGear(4);
	CHECK(car.SetSpeed(90));
	CHECK(car.ReturnCurrentSpeed() == 90);

	// Переключение невозомжно, остается текущая скорость
	CHECK(!car.SetSpeed(91));
	CHECK(car.ReturnCurrentSpeed() == 90);

	// Переключение на пятой передаче
	car.SetGear(5);
	CHECK(car.SetSpeed(150));
	CHECK(car.ReturnCurrentSpeed() == 150);

	// Переключение невозомжно, остается текущая скорость
	CHECK(!car.SetSpeed(151));
	CHECK(car.ReturnCurrentSpeed() == 150);
}

TEST_CASE("Переключение направлений движения")
{
	CCar car;
	car.TurnOnEngine();
	CHECK(car.ReturnCurrentDirection() == Direction::Stand);

	car.SetGear(1);
	car.SetSpeed(10);
	CHECK(car.ReturnCurrentDirection() == Direction::Forward);

	car.SetSpeed(0);
	car.SetGear(0);
	CHECK(car.ReturnCurrentDirection() == Direction::Stand);

	car.SetGear(-1);
	car.SetSpeed(10);
	CHECK(car.ReturnCurrentDirection() == Direction::Back);

}