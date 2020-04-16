#include "AutoPilot.h"
#include <string>
#include <any>


class Control
{
public:
	explicit Control(CCar& car);

	bool HandleCommand(const std::string& commandLine);

protected:
	bool TurnOnEngine();
	bool TurnOffEngine();

	bool CarInformation();

	bool SetGear(int gear);
	bool SetSpeed(int speed);
private:
	CCar& m_car;
};
