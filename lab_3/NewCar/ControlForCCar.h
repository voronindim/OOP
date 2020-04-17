#include "CCar.h"
#include <string>

class ControlForCCar
{
public:
	explicit ControlForCCar(CCar& car);
	bool HandleCommand(const std::string& commandLine);

private:
	[[nodiscard]] std::string DirectionToString(const Direction& direction) const;

	bool TurnOnEngine();
	bool TurnOffEngine();
	bool CarInfo();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	CCar& m_car;
};

