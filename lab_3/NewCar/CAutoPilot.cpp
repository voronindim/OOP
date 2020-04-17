#include "CAutoPilot.h"
#include "CCar.h"
#include <iostream>

using namespace std;

CAutoPilot::CAutoPilot(IManualGearVehicle& car)
	: m_car(&car)
{
}

std::pair<int, int> ReturnSpeedRange(int gear)
{
	if (gear == 0)
	{
		return NEUTRAL_SPEED_RANGE;
	}
	if (gear == 1)
	{
		return FIRST_SPEED_RANGE;
	}
	if (gear == 2)
	{
		return SECOND_SPEED_RANGE;
	}
	if (gear == 3)
	{
		return THIRD_SPEED_RANGE;
	}
	if (gear == 4)
	{
		return FOURTH_SPEED_RANGE;
	}
	if (gear == 5)
	{
		return FIFTH_SPEED_RANGE;
	}
	return {0, 0};
}

bool CAutoPilot::TurnOnEngine()
{
	return m_car->TurnOnEngine();
}

bool CAutoPilot::TurnOffEngine()
{
	return m_car->TurnOffEngine();
}

void CAutoPilot::IncreaseSpeed(int speed)
{
	while (speed != m_car->ReturnCurrentSpeed())
	{
		m_car->SetGear(m_car->ReturnCurrentGear() + 1);
		if (!m_car->SetSpeed(speed))
		{
			int maxSpeedInCurrentRange = ReturnSpeedRange(m_car->ReturnCurrentGear()).second;
			m_car->SetSpeed(maxSpeedInCurrentRange);
		}
	}
}

void CAutoPilot::DecreaseSpeed(int speed)
{
	while (speed != m_car->ReturnCurrentSpeed())
	{
		m_car->SetGear(m_car->ReturnCurrentGear() - 1);
		if (!m_car->SetSpeed(speed))
		{
			int maxSpeedInCurrentRange = ReturnSpeedRange(m_car->ReturnCurrentGear()).first;
			m_car->SetSpeed(maxSpeedInCurrentRange);
		}
	}
}

bool CAutoPilot::SetSpeed(int speed)
{
	if (speed > MAX_SPEED || (m_car->ReturnCurrentGear() == -1 && speed > REVERSE_SPEED_RANGE.second))
	{
		return false;
	}

	if (!m_car->SetSpeed(speed))
	{
		if (m_car->ReturnCurrentDirection() != Direction::Back && speed > m_car->ReturnCurrentSpeed())
		{
			IncreaseSpeed(speed);
		}
		else if (m_car->ReturnCurrentDirection() != Direction::Back && speed < m_car->ReturnCurrentSpeed())
		{
			DecreaseSpeed(speed);
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool CAutoPilot::BackWardGear()
{
	if (m_car->ReturnCurrentDirection() != Direction::Back)
	{
		CAutoPilot::SetSpeed(0);
		m_car->SetGear(-1);
		return true;
	}
	return false;
}

bool CAutoPilot::ForwardGear()
{
	if (m_car->ReturnCurrentDirection() != Direction::Forward)
	{
		CAutoPilot::SetSpeed(0);
		m_car->SetGear(1);
		return true;
	}
	return false;
}

int CAutoPilot::ReturnCurrentSpeed() const
{
	return m_car->ReturnCurrentSpeed();
}

int CAutoPilot::ReturnCurrentGear() const
{
	return m_car->ReturnCurrentGear();
}

Direction CAutoPilot::ReturnCurrentDirection() const
{
	return m_car->ReturnCurrentDirection();
}

bool CAutoPilot::ReturnEngineOn() const
{
	return m_car->ReturnEngineOn();
}
