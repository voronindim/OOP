#pragma once
#include "IManualGearVehicle.h"

class CAutoPilot
{
public:
	explicit CAutoPilot(IManualGearVehicle& car);
	bool TurnOnEngine();
	bool TurnOffEngine();
	[[nodiscard]] bool ReturnEngineOn() const;

	bool NeutralGear();
	bool BackwardGear();
	bool ForwardGear();
	bool SetSpeed(int speed);

	[[nodiscard]] int ReturnCurrentSpeed() const;
	[[nodiscard]] int ReturnCurrentGear() const;
	[[nodiscard]] Direction ReturnCurrentDirection() const;

private:
	IManualGearVehicle* m_car;

	void IncreaseSpeed(int speed);
	void DecreaseSpeed(int speed);
};

