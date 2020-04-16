#include "../catch.hpp"
#include "../Car/AutoPilot.h"


TEST_CASE("AutoPilot::TurnOnEngine после включения двигателя, двигатель всегда включен")
{
//  Меняется состояние двигателя на включенное
	AutoPilot car;
	CHECK(car.AutoPilot::TurnOnEngine());
	CHECK(car.AutoPilot::ReturnEngine());

//	После повтороного включения состояние не меняется
	CHECK(!car.AutoPilot::TurnOnEngine());
	CHECK(car.AutoPilot::ReturnEngine());
}

TEST_CASE("AutoPilot::TurnOffEngine после выключения двигателя, двигатель выключен до включения")
{
//  Меняется состояние двигателя на выключенное
	AutoPilot car;
	car.AutoPilot::TurnOnEngine();
	CHECK(car.AutoPilot::TurnOffEngine());
	CHECK(!car.AutoPilot::ReturnEngine());

//  После повторного выключения состояние не меняется
	CHECK(!car.AutoPilot::ReturnEngine());
}

TEST_CASE("AutoPilot::SetGear переключает передачу, если это возможно, иначе состояние не меняется.")
{
//  Включение допустимой передачи.
	AutoPilot car;
	car.AutoPilot::TurnOnEngine();
	CHECK(car.AutoPilot::SetGear(1));
	CHECK(car.AutoPilot::ReturnGear() == 1);

//	После невозможного переключения, состояние остается прежним.
	CHECK(!car.AutoPilot::SetGear(5));
	CHECK(car.AutoPilot::ReturnGear() == 1);

//	Нельзя переключиться на заднюю передачу, если скорость не равно 0.
	car.AutoPilot::SetSpeed(10);
	CHECK(car.AutoPilot::SetGear(0));
	CHECK(!car.AutoPilot::SetGear(-1));
	CHECK(car.AutoPilot::ReturnGear() == 0);

//	Нельзя переключиться на заднюю передачу, если скорость не равно 0, даже если направление Back.
	car.AutoPilot::SetSpeed(0);
	car.AutoPilot::SetGear(-1);
	car.AutoPilot::SetSpeed(10);
	car.AutoPilot::SetGear(0);
	CHECK(!car.AutoPilot::SetGear(-1));
	CHECK(car.AutoPilot::ReturnDirection() == Direction::Back);
	CHECK(car.AutoPilot::ReturnGear() == 0);
}


TEST_CASE("AutoPilot::SetSpeed переключает скорость, если она не превышает максимальнуюскорость авто, не зависит от прежней передачи")
{
//  Включает любую скорость меньше максимальной (повышение)
	AutoPilot car;
	car.AutoPilot::TurnOnEngine();
	CHECK(car.AutoPilot::SetSpeed(10));
	CHECK(car.AutoPilot::ReturnSpeed() == 10);

	CHECK(car.AutoPilot::SetSpeed(100));
	CHECK(car.AutoPilot::ReturnGear() == 5);
	CHECK(car.AutoPilot::ReturnSpeed() == 100);

	//	Остается текущая скорость, так как, нужная скорость больше максимальной
	CHECK(!car.AutoPilot::SetSpeed(151));
	CHECK(car.AutoPilot::ReturnSpeed() == 100);

	//	Включает любую скорость меньше максимальной (понижение)
	CHECK(car.AutoPilot::SetSpeed(30));
	CHECK(car.AutoPilot::ReturnGear() == 3);
	CHECK(car.AutoPilot::ReturnSpeed() == 30);
}