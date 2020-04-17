#include "ControlForCCar.h"
#include "ControlAutoPilot.h"
#include <iostream>
#include <sstream>

ControlForCCar::ControlForCCar(CCar& car)
	: m_car(car)
{
}

bool ControlForCCar::HandleCommand(const std::string& commandLine)
{
	std::stringstream ss(commandLine);
	std::string action;
	ss >> action;
	if (action == "EngineOn")
	{
		TurnOnEngine();
	}
	else if (action == "EngineOff")
	{
		TurnOffEngine();
	}
	else if (action == "SetGear")
	{
		int gear;
		ss >> gear;
		SetGear(gear);
	}
	else if (action == "SetSpeed")
	{
		int speed;
		ss >> speed;
		SetSpeed(speed);
	}
	else if (action == "Info")
	{
		CarInfo();
	}
	else
	{
		return false;
	}
	return true;
}



bool ControlForCCar::TurnOnEngine()
{
	if (m_car.TurnOnEngine())
	{
		std::cout << "Двигатель включен" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Двигатель не включен" << std::endl;
		return false;
	}
}

bool ControlForCCar::TurnOffEngine()
{
	if (m_car.TurnOffEngine())
	{
		std::cout << "Двигатель выклюяен" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Двигатель не был выключен" << std::endl;
		return false;
	}
}

std::string ControlForCCar::DirectionToString(const Direction& direction) const
{
	if (direction == Direction::Stand)
	{
		return "Stand";
	}
	else if (direction == Direction::Back)
	{
		return "Back";
	}
	else if (direction == Direction::Forward)
	{
		return "Forward";
	}
	return "Ошибка";
}

bool ControlForCCar::CarInfo()
{
	if (m_car.ReturnEngineOn())
	{
		std::cout << "Двигатель включен." << std::endl;
	}
	else
	{
		std::cout << "Двигатель выключен" << std::endl;
	}
	std::cout << "Передача: " << m_car.ReturnCurrentGear() << std::endl;
	std::cout << "Скорость: " << m_car.ReturnCurrentSpeed() << std::endl;
	std::cout << "Направление: " << DirectionToString(m_car.ReturnCurrentDirection()) << std::endl;
	return true;
}

bool ControlForCCar::SetGear(int gear)
{
	if (m_car.SetGear(gear))
	{
		std::cout << "Передача включена." << std::endl;
		return true;
	}
	else
	{
		std::cout << "Не удалось переключить передачу." << std::endl;
		return false;
	}
}

bool ControlForCCar::SetSpeed(int speed)
{
	if (m_car.SetSpeed(speed))
	{
		std::cout << "Достигнута заданная скорость." << std::endl;
		return true;
	}
	else
	{
		std::cout << "Нужную скорость достичь невозможно" << std::endl;
		return false;
	}
}
