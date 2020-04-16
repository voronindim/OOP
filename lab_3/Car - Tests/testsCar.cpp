#include "../catch.hpp"
#include "../Car/CCar.h"

TEST_CASE("CCar::TurnOnEngine после включения двигателя, двигатель всегда включен")
{
//  Меняется состояние двигателя на включенное
    CCar car;
    CHECK(car.CCar::TurnOnEngine());
    CHECK(car.CCar::ReturnEngine());

//	После повтороного включения состояние не меняется
    CHECK(!car.CCar::TurnOnEngine());
    CHECK(car.CCar::ReturnEngine());
}

TEST_CASE("CCar::TurnOffEngine после выключения двигателя, двигатель выключен до включения")
{
//  Меняется состояние двигателя на выключенное
    CCar car;
    car.CCar::TurnOnEngine();
    CHECK(car.CCar::TurnOffEngine());
    CHECK(!car.CCar::ReturnEngine());

//  После повторного выключения состояние не меняется
    CHECK(!car.CCar::ReturnEngine());
}

TEST_CASE("CCar::SetGear переключает передачу, если это возможно, иначе состояние не меняется.")
{
//  Включение допустимой передачи.
    CCar car;
    car.CCar::TurnOnEngine();
    CHECK(car.CCar::SetGear(1));
    CHECK(car.CCar::ReturnGear() == 1);

//	После невозможного переключения, состояние остается прежним.
    CHECK(!car.CCar::SetGear(5));
    CHECK(car.CCar::ReturnGear() == 1);

//	Нельзя переключиться на заднюю передачу, если скорость не равно 0.
    car.CCar::SetSpeed(10);
    CHECK(car.CCar::SetGear(0));
	CHECK(!car.CCar::SetGear(-1));
    CHECK(car.CCar::ReturnGear() == 0);

//	Нельзя переключиться на заднюю передачу, если скорость не равно 0, даже если направление Back.
    car.CCar::SetSpeed(0);
    car.CCar::SetGear(-1);
    car.CCar::SetSpeed(10);
    car.CCar::SetGear(0);
    CHECK(!car.CCar::SetGear(-1));
    CHECK(car.CCar::ReturnDirection() == Direction::Back);
    CHECK(car.CCar::ReturnGear() == 0);

}

TEST_CASE("CCar::SetSpeed переключение скорости в текущем диапазоне, если невомзожно, то скорость остается прежней")
{
//  Переключение на нужную скорость на 1 передаче
    CCar car;
    car.CCar::TurnOnEngine();
    car.CCar::SetGear(1);
    CHECK(car.CCar::SetSpeed(30));
    CHECK(car.CCar::ReturnSpeed() == 30);

//  Переключение невозможно, остается текущая скорость
    CHECK(!car.CCar::SetSpeed(40));
    CHECK(car.CCar::ReturnSpeed() == 30);

//  Переключение на нужную скорость на 2 передаче
    car.CCar::SetGear(2);
    CHECK(car.CCar::SetSpeed(50));
    CHECK(car.CCar::ReturnSpeed() == 50);

//  Переключение невозможно, остается текущая скорость
    CHECK(!car.CCar::SetSpeed(51));
    CHECK(car.CCar::ReturnSpeed() == 50);

//  Переключение на нужную скорость на 3 передаче
    car.CCar::SetGear(3);
    CHECK(car.CCar::SetSpeed(60));
    CHECK(car.CCar::ReturnSpeed() == 60);

//  Переключение невозможно, остается текущая скорость
    CHECK(!car.CCar::SetSpeed(65));
    CHECK(car.CCar::ReturnSpeed() == 60);

//  Переключение на нужную скорость на 4 передаче
    car.CCar::SetGear(4);
    CHECK(car.CCar::SetSpeed(90));
    CHECK(car.CCar::ReturnSpeed() == 90);

//  Переключение невозможно, остается текущая скорость
    CHECK(!car.CCar::SetSpeed(91));
    CHECK(car.CCar::ReturnSpeed() == 90);

//  Переключение на нужную скорость на 5 передаче
    car.CCar::SetGear(5);
    CHECK(car.CCar::SetSpeed(150));
    CHECK(car.CCar::ReturnSpeed() == 150);

//  Переключение невозможно, остается текущая скорость
    CHECK(!car.CCar::SetSpeed(151));
    CHECK(car.CCar::ReturnSpeed() == 150);
}

TEST_CASE("Переключение направлений движения")
{
    CCar car;
    car.CCar::TurnOnEngine();
    CHECK(car.CCar::ReturnDirection() == Direction::Stand);

    car.CCar::SetGear(1);
    car.CCar::SetSpeed(10);
    CHECK(car.CCar::ReturnDirection() == Direction::Forward);

    car.CCar::SetSpeed(0);
    car.CCar::SetGear(0);
    CHECK(car.CCar::ReturnDirection() == Direction::Stand);

    car.CCar::SetGear(-1);
    car.CCar::SetSpeed(10);
    CHECK(car.CCar::ReturnDirection() == Direction::Back);

}

