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
		carControl.HandleCommand(commandLine);
	}
	return 0;
}
