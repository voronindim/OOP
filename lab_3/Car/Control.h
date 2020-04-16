#include "CCar.h"
#include <string>


class Control
{
public:
	explicit Control(CCar& car);

	bool HandleCommand(const std::string& commandLine);

private:
	std::string DirectionTostring(const Direction& direction) const;

	bool TurnOnEngine();
	bool TurnOffEngine();

	bool CarInformation();

	bool SetGear(int gear);
	bool SetSpeed(int speed);
	CCar& m_car;
};
