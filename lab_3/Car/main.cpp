#include "Control.h"
#include "ControlAutoPilot.h"
#include <iostream>
#include <string>

int main()
{
	std::cout << "Выберите тип автомобиля: 0 - Обычный автомобиль, 1 - Автопилот" << std::endl;
	std::string number;
	getline(std::cin, number);
	if (number == "0" || number == "1")
	{
		if (number == "0")
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
		}
		else
		{
			AutoPilot car;
			ControlAutoPilot carControl(car);
			std::string commandLine;
			while (getline( std::cin, commandLine))
			{
				if (!carControl.HandleCommand(commandLine))
				{
					std::cout << "Неизвестная команда" << std::endl;
				}
			}
		}
		return 0;
	}
	return 1;
}
