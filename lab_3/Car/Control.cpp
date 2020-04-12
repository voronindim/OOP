#include "Control.h"
#include <iostream>
#include <sstream>

Control::Control(CCar& car)
	: m_car(car)
{
}

bool Control::HandleCommand(const std::string& commandLine)
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
		CarInformation();
	}
	return true;
}

bool Control::TurnOnEngine()
{
	if (m_car.CCar::TurnOnEngine())
	{
		std::cout << "Двигатель включен." << std::endl;
		return true;
	}
	else
	{
		std::cout << "Двигатель не был включен" << std::endl;
		return false;
	}
}

bool Control::TurnOffEngine()
{
	if (m_car.CCar::TurnOffEngine())
	{
		std::cout << "Двигатель выключен." << std::endl;
		return true;
	}
	else
	{
		std::cout << "Двигатель не был выключен" << std::endl;
		return false;
	}
}

bool Control::SetGear(int gear)
{
	if (m_car.CCar::SetGear(gear))
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

bool Control::SetSpeed(int speed)
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

std::string DirectionTostring(const Direction& direction)
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

bool Control::CarInformation()
{
	if (m_car.CCar::ReturnEngine())
	{
		std::cout << "Двигатель включен." << std::endl;
	}
	else
	{
		std::cout << "Двигатель выключен" << std::endl;
	}
	std::cout << "Передача: " << m_car.CCar::ReturnGear() << std::endl;
	std::cout << "Скорость: " << m_car.CCar::ReturnSpeed() << std::endl;
	std::cout << "Направление: " << DirectionTostring(m_car.CCar::ReturnDirection()) << std::endl;
	return true;
}
