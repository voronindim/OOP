#include "AutoPilot.h"
#include <string>

class Control
{
public:
	Control(CCar& car);
	virtual bool HandleCommand(const std::string& commandLine);

protected:
	bool TurnOnEngine();
	bool TurnOffEngine();

	bool CarInformation();

	bool SetGear(int gear);
	bool SetSpeed(int speed);

	CCar& m_car;
};
