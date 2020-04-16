#include "AutoPilot.h"
#include <string>

class ControlAutoPilot
{
public:
	explicit ControlAutoPilot(AutoPilot& car);

	bool HandleCommand(const std::string& commandLine);

private:
	std::string DirectionTostring(const Direction& direction) const;

	bool TurnOnEngine();
	bool TurnOffEngine();

	bool CarInformation();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	AutoPilot& m_car;
};

