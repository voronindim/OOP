#pragma once
#include "../NewCar/IManualGearVehicle.h"
#include <variant>
#include <vector>


class MockedCar : public  IManualGearVehicle
{
public:
	std::vector<int> variants;
	bool TurnOnEngine() override;
	bool TurnOffEngine() override;
	[[nodiscard]] bool ReturnEngineOn() const override;

	bool SetGear(int gear) override;
	[[nodiscard]] int ReturnCurrentGear() const override;

	bool SetSpeed(int speed) override ;
	[[nodiscard]] int ReturnCurrentSpeed() const override;

	[[nodiscard]] Direction ReturnCurrentDirection() const override;

private:
	bool m_isEngineOn = false;
	Direction m_direction = Direction::Stand;
	int m_speed = 0;
	int m_gear = 0;
	[[nodiscard]] bool IsSpeedInRange(const std::pair<int, int>& speedRange, int speed) const;
	[[nodiscard]] bool CurrentSpeedInGearSpeedRange(int speed, int gear) const;
	[[nodiscard]] bool CorrectGearShift(int gear) const;
};

