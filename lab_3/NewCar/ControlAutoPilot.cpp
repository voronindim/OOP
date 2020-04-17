#include "ControlAutoPilot.h"
#include "CCar.h"
#include <iostream>
#include <sstream>

ControlAutoPilot::ControlAutoPilot(CAutoPilot& car)
	: m_car(car)
{
}
bool ControlAutoPilot::HandleCommand(const std::string& commandLine)
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
	else if (action == "Back")
	{
		BackwardGear();
	}
	else if (action == "Neutral")
	{
		NeutralGear();
	}
	else if (action == "Forward")
	{
		ForwardGear();
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

bool ControlAutoPilot::TurnOnEngine()
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

bool ControlAutoPilot::TurnOffEngine()
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

std::string ControlAutoPilot::DirectionToString(const Direction& direction) const
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

bool ControlAutoPilot::CarInfo()
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

bool ControlAutoPilot::SetSpeed(int speed)
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
bool ControlAutoPilot::BackwardGear()
{
	if (m_car.BackwardGear())
	{
		std::cout << "Включена задняя передеча" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Задняя передача уже включена" << std::endl;
		return false;
	}
}

bool ControlAutoPilot::NeutralGear()
{
	if (m_car.NeutralGear())
	{
		std::cout << "Включена нейтральная передача" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Нейтральная передача не включена" << std::endl;
		return false;
	}
}

bool ControlAutoPilot::ForwardGear()
{
	if (m_car.ForwardGear())
	{
		std::cout << "Включена переднаяя передеча" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Передняя передача уже включена" << std::endl;
		return false;
	}
}
