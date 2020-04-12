#include "Control.h"
#include <iostream>
#include <string>

int main()
{
	CCar car;
	Control carControl(car);
	std::string commandLine;
	while (getline( std::cin, commandLine))
	{
		if (!carControl.HandleCommand(commandLine))
		{
			std::cout << "Неизвестная команда" << std::endl;
		}
	}
	return 0;
}
