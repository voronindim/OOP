#include "Control.h"

class ControlWithAutopilot : public Control
{
	bool HandleCommand(const std::string& commandLine);

	bool SetSpeed();
};

