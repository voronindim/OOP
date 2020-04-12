#include "ControlWithAutopilot.h"
#include <sstream>

bool ControlWithAutopilot::HandleCommand(const std::string& commandLine)
{
	std::stringstream ss(commandLine);
	std::string action;
	ss >> action;
	if (action != "SetSpeed")
	{
		Control::HandleCommand(commandLine);
	}
	else
	{
		int speed;
		ss >> speed;
//		m_car.AutoPilot::SetSpeed(speed);
	}
	return false;
}
