#include "CCar.h"
#include <utility>

class AutoPilot : public ICar
{
public:
	bool TurnOnEngine() override;
	bool TurnOffEngine() override;
	[[nodiscard]] bool ReturnEngine() const override;

	[[nodiscard]] int ReturnGear() const override;

	bool SetSpeed(int speed) override;
	[[nodiscard]] int ReturnSpeed() const override;

	[[nodiscard]] Direction ReturnDirection() const override;

private:
	[[nodiscard]] bool CorrectGearShift(int gear) const;
	[[nodiscard]] bool CurrentSpeedInGearSpeedRange(int speed, int gear) const;
	[[nodiscard]] bool IsSpeedInRange(const std::pair<int, int>& speedRange, int speed) const;
	bool SetGear(int gear) override;
	void DecreaseSpeed(int speed);
	void IncreaseSpeed(int speed);
	bool MechanicalSetSpeed(int speed);

	bool m_isEngineOn = false;
	Direction m_direction = Direction::Stand;
	int m_speed = 0;
	int m_gear = 0;
};
