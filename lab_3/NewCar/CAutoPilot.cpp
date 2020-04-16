#include "CAutoPilot.h"

CAutoPilot::CAutoPilot(IManualGearVehicle* car)
	: m_car(car)
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
	if (!m_isEngineOn)
	{
		m_isEngineOn = true;
		return true;
	}
	return false;
}

bool CAutoPilot::TurnOffEngine()
{
	if (m_isEngineOn && m_gear == 0 && m_speed == 0)
	{
		m_isEngineOn = false;
		return true;
	}
	return false;
}

bool CAutoPilot::IsSpeedInRange(const std::pair<int, int>& speedRange, int speed) const
{
	return speed >= speedRange.first && speed <= speedRange.second;
}

bool CAutoPilot::CurrentSpeedInGearSpeedRange(int speed, int gear) const
{
	return (gear == -1 && IsSpeedInRange(REVERSE_SPEED_RANGE, speed)) ||
		   (gear == 0 && IsSpeedInRange(NEUTRAL_SPEED_RANGE, speed)) ||
		   (gear == 1 && IsSpeedInRange(FIRST_SPEED_RANGE, speed)) ||
		   (gear == 2 && IsSpeedInRange(SECOND_SPEED_RANGE, speed)) ||
		   (gear == 3 && IsSpeedInRange(THIRD_SPEED_RANGE, speed)) ||
		   (gear == 4 && IsSpeedInRange(FOURTH_SPEED_RANGE, speed)) ||
		   (gear == 5 && IsSpeedInRange(FIFTH_SPEED_RANGE, speed));
}

bool CAutoPilot::MechanicalSetSpeed(int speed)
{
	if (m_gear == 0 && speed > m_speed)
	{
		return false;
	}

	if (!CurrentSpeedInGearSpeedRange(speed, m_gear))
	{
		return false;
	}
	m_speed = speed;
	m_direction = (speed == 0) ? Direction::Stand :
				  (speed > 0 && m_gear == -1) ? Direction::Back :
				  (speed > 0 && m_gear > 0) ? Direction::Forward :
				  m_direction;
	return true;
}

bool CAutoPilot::CorrectGearShift(int gear) const
{
	return (gear == -1 && m_direction == Direction::Stand) ||
		   (gear == 1 && m_direction != Direction::Back) ||
		   (gear > 1 && m_direction == Direction::Forward) ||
		   (gear == 0);
}

bool CAutoPilot::SetGear(int gear)
{
	if (!m_isEngineOn && gear != 0)
	{
		return false;
	}
	if (!CurrentSpeedInGearSpeedRange(m_speed, gear))
	{
		return false;
	}
	if (!CorrectGearShift(gear))
	{
		return false;
	}
	m_gear = gear;
	return true;
}

void CAutoPilot::IncreaseSpeed(int speed)
{
	while (speed != m_speed)
	{
		SetGear(m_gear + 1);
		if (!CAutoPilot::MechanicalSetSpeed(speed))
		{
			int maxSpeedInCurrentRange = ReturnSpeedRange(m_gear).second;
			CAutoPilot::MechanicalSetSpeed(maxSpeedInCurrentRange);
		}
	}
}

void CAutoPilot::DecreaseSpeed(int speed)
{
	while (speed != m_speed)
	{
		SetGear(m_gear - 1);
		if (!CAutoPilot::MechanicalSetSpeed(speed))
		{
			int maxSpeedInCurrentRange = ReturnSpeedRange(m_gear).first;
			CAutoPilot::MechanicalSetSpeed(maxSpeedInCurrentRange);
		}
	}
}

bool CAutoPilot::SetSpeed(int speed)
{
	if (speed > MAX_SPEED || (m_gear == -1 && speed > REVERSE_SPEED_RANGE.second))
	{
		return false;
	}

	if (!CAutoPilot::MechanicalSetSpeed(speed))
	{
		if (m_direction != Direction::Back && speed > m_speed)
		{
			IncreaseSpeed(speed);
		}
		else if (m_direction != Direction::Back && speed < m_speed)
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
	if (m_direction != Direction::Back)
	{
		CAutoPilot::SetSpeed(0);
		CAutoPilot::SetGear(-1);
		return true;
	}
	return false;
}

bool CAutoPilot::ForwardGear()
{
	if (m_direction != Direction::Forward)
	{
		CAutoPilot::SetSpeed(0);
		CAutoPilot::SetGear(1);
		return true;
	}
	return false;
}

int CAutoPilot::ReturnCurrentSpeed()
{
	return m_speed;
}

int CAutoPilot::ReturnCurrentGear()
{
	return m_gear;
}

Direction CAutoPilot::ReturnCurrentDirection()
{
	return m_direction;
}

bool CAutoPilot::ReturnEngineOn() const
{
	return m_isEngineOn;
}
