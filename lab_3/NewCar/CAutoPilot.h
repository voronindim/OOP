#include "IManualGearVehicle.h"

class CAutoPilot
{
public:
	explicit CAutoPilot(IManualGearVehicle& car);
	bool TurnOnEngine();
	bool TurnOffEngine();
	[[nodiscard]] bool ReturnEngineOn() const;

	bool BackWardGear();
	bool ForwardGear();
	bool SetSpeed(int speed);

	[[nodiscard]] int ReturnCurrentSpeed() const;

	[[nodiscard]] int ReturnCurrentGear() const;

	[[nodiscard]] Direction ReturnCurrentDirection() const;

private:
	IManualGearVehicle* m_car;

	bool m_isEngineOn = false;
	Direction m_direction = Direction::Stand;
	int m_speed = 0;
	int m_gear = 0;

	bool SetGear(int gear);
	void IncreaseSpeed(int speed);
	void DecreaseSpeed(int speed);
	bool MechanicalSetSpeed(int speed);
	[[nodiscard]] bool CorrectGearShift(int gear) const;
	[[nodiscard]] bool CurrentSpeedInGearSpeedRange(int speed, int gear) const;
	[[nodiscard]] bool IsSpeedInRange(const std::pair<int, int>& speedRange, int speed) const;

};

