#include "CAutoPilot.h"
#include <string>
class ControlAutoPilot
{
public:
	explicit ControlAutoPilot(CAutoPilot& car);
	bool HandleCommand(const std::string& commandLine);

private:
	[[nodiscard]] std::string DirectionToString(const Direction& direction) const;

	bool TurnOnEngine();
	bool TurnOffEngine();
	bool BackwardGear();
	bool NeutralGear();
	bool ForwardGear();
	bool CarInfo();
	bool SetSpeed(int speed);
	CAutoPilot& m_car;
};

