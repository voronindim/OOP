#include <iostream>
#include <string>
#include "ControlForCCar.h"
#include "ControlAutoPilot.h"

using namespace std;

int main()
{
	CCar car;
	ControlForCCar control(car);
	std::string commandLine;
	while (getline(cin, commandLine))
	{
		if (commandLine == "toAutoPilot")
		{
			auto carAutoPilot = CAutoPilot(car);
			ControlAutoPilot controlAutoPilot(carAutoPilot);

			while(getline(cin, commandLine))
			{
				if (commandLine == "toCar")
				{
					break;
				}
				if (!controlAutoPilot.HandleCommand(commandLine))
				{
					std::cout << "Неизвестная команда" << std::endl;
				}
			}
		}
		else if(!control.HandleCommand(commandLine))
		{
			std::cout << "Неизвестная команда" << std::endl;
		}
	}
	return 0;
}
