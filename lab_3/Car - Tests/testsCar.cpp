#include "../catch.hpp"
#include "../Car/AutoPilot.h"

TEST_CASE("CCar::TurnOnEngine после включения двигателя, двигатель всегда включен")
{
//  Меняется состояние двигателя на включенное
	CCar car;
	car.CCar::TurnOnEngine();
	CHECK(car.CCar::ReturnEngine());

//	После повтороного включения состояние не меняется
	car.CCar::TurnOnEngine();
	CHECK(car.CCar::ReturnEngine());
}

TEST_CASE("CCar::TurnOffEngine после выключения двигателя, двигатель выключен до включения")
{
//  Меняется состояние двигателя на выключенное
	CCar car;
	car.CCar::TurnOnEngine();
	car.CCar::TurnOffEngine();
	CHECK(!car.CCar::ReturnEngine());

//  После повторного выключения состояние не меняется
	CHECK(!car.CCar::ReturnEngine());

}

TEST_CASE("CCar::SetGear переключает передачу, если это возможно, иначе состояние не меняется.")
{
//  Включение допустимой передачи.
    CCar car;
    car.CCar::TurnOnEngine();
    car.CCar::SetGear(1);
    CHECK(car.CCar::ReturnGear() == 1);

//	После невозможного переключения, состояние остается прежним.
    car.CCar::SetGear(5);
    CHECK(car.CCar::ReturnGear() == 1);

//	Нельзя переключиться на заднюю передачу, если скорость не равно 0.
    car.CCar::SetSpeed(10);
    car.CCar::SetGear(0);
    car.CCar::SetGear(-1);
    CHECK(car.CCar::ReturnGear() == 0);

//	Нельзя переключиться на заднюю передачу, если скорость не равно 0, даже если направление Back.
    car.CCar::SetSpeed(0);
    car.CCar::SetGear(-1);
    car.CCar::SetSpeed(10);
    car.CCar::SetGear(0);
    car.CCar::SetGear(-1);
    CHECK(car.CCar::ReturnDirection() == Direction::Back);
    CHECK(car.CCar::ReturnGear() == 0);

}

TEST_CASE("CCar::SetSpeed переключение скорости в текущем диапазоне, если невомзожно, то скорость остается прежней")
{
//  Переключение на нужную скорость на 1 передаче
    CCar car;
    car.CCar::TurnOnEngine();
    car.CCar::SetGear(1);
    car.CCar::SetSpeed(30);
    CHECK(car.CCar::ReturnSpeed() == 30);

//  Переключение невозможно, остается текущая скорость
    car.CCar::SetSpeed(40);
    CHECK(car.CCar::ReturnSpeed() == 30);

//  Переключение на нужную скорость на 2 передаче
    car.CCar::SetGear(2);
    car.CCar::SetSpeed(50);
    CHECK(car.CCar::ReturnSpeed() == 50);

//  Переключение невозможно, остается текущая скорость
    car.CCar::SetSpeed(51);
    CHECK(car.CCar::ReturnSpeed() == 50);

//  Переключение на нужную скорость на 3 передаче
    car.CCar::SetGear(3);
    car.CCar::SetSpeed(60);
    CHECK(car.CCar::ReturnSpeed() == 60);

//  Переключение невозможно, остается текущая скорость
    car.CCar::SetSpeed(65);
    CHECK(car.CCar::ReturnSpeed() == 60);

//  Переключение на нужную скорость на 4 передаче
    car.CCar::SetGear(4);
    car.CCar::SetSpeed(90);
    CHECK(car.CCar::ReturnSpeed() == 90);

//  Переключение невозможно, остается текущая скорость
    car.CCar::SetSpeed(91);
    CHECK(car.CCar::ReturnSpeed() == 90);

//  Переключение на нужную скорость на 5 передаче
    car.CCar::SetGear(5);
    car.CCar::SetSpeed(150);
    CHECK(car.CCar::ReturnSpeed() == 150);

//  Переключение невозможно, остается текущая скорость
    car.CCar::SetSpeed(151);
    CHECK(car.CCar::ReturnSpeed() == 150);
}

TEST_CASE("Переключение направлений движения")
{
    CCar car;
    car.CCar::TurnOnEngine();
    CHECK(car.CCar::ReturnDirection() == Direction::Stand);

    car.CCar::SetGear(1);
    car.CCar::SetSpeed(10);
    CHECK(car.ReturnDirection() == Direction::Forward);

    car.CCar::SetSpeed(0);
    car.CCar::SetGear(0);
    CHECK(car.CCar::ReturnDirection() == Direction::Stand);

    car.CCar::SetGear(-1);
    car.CCar::SetSpeed(10);
    CHECK(car.CCar::ReturnDirection() == Direction::Back);

}

TEST_CASE("AutoPilot::SetSpeed переключает скорость, если она не превышает максимальнуюскорость авто, не зависит от прежней передачи")
{
//  Включает любую скорость меньше максимальной (повышение)
    AutoPilot car;
    car.AutoPilot::TurnOnEngine();
    car.AutoPilot::SetSpeed(10);
    CHECK(car.AutoPilot::ReturnSpeed() == 10);

    car.AutoPilot::SetSpeed(100);
    CHECK(car.AutoPilot::ReturnGear() == 5);
    CHECK(car.AutoPilot::ReturnSpeed() == 100);

//	Остается текущая скорость, так как, нужная скорость больше максимальной
    car.AutoPilot::SetSpeed(151);
    CHECK(car.AutoPilot::ReturnSpeed() == 100);

//	Включает любую скорость меньше максимальной (понижение)
    car.AutoPilot::SetSpeed(30);
    CHECK(car.AutoPilot::ReturnGear() == 3);
    CHECK(car.AutoPilot::ReturnSpeed() == 30);

}


