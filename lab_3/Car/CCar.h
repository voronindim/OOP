#include "ICar.h"
#include <utility>

class CCar : public ICar
{
public:
	bool TurnOnEngine() override;
	bool TurnOffEngine() override;
	[[nodiscard]] bool ReturnEngine() const override;

	bool SetGear(int gear) override;
	[[nodiscard]] int ReturnGear() const override;

	bool SetSpeed(int speed) override;
	[[nodiscard]] int ReturnSpeed() const override;

	[[nodiscard]] Direction ReturnDirection() const override;

private:
	[[nodiscard]] bool CorrectGearShift(int gear) const;
	[[nodiscard]] bool CurrentSpeedInGearSpeedRange(int speed, int gear) const;
	[[nodiscard]] bool IsSpeedInRange(const std::pair<int, int>& speedRange, int speed) const;

	bool m_isEngineOn = false;
	Direction m_direction = Direction::Stand;
	int m_speed = 0;
	int m_gear = 0;
};
