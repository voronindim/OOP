#include "AutoPilot.h"

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

bool AutoPilot::IsSpeedInRange(const std::pair<int, int>& speedRange, int speed) const
{
	return speed >= speedRange.first && speed <= speedRange.second;
}

bool AutoPilot::CurrentSpeedInGearSpeedRange(int speed, int gear) const
{
	return (gear == -1 && IsSpeedInRange(REVERSE_SPEED_RANGE, speed)) ||
		   (gear == 0 && IsSpeedInRange(NEUTRAL_SPEED_RANGE, speed)) ||
		   (gear == 1 && IsSpeedInRange(FIRST_SPEED_RANGE, speed)) ||
		   (gear == 2 && IsSpeedInRange(SECOND_SPEED_RANGE, speed)) ||
		   (gear == 3 && IsSpeedInRange(THIRD_SPEED_RANGE, speed)) ||
		   (gear == 4 && IsSpeedInRange(FOURTH_SPEED_RANGE, speed)) ||
		   (gear == 5 && IsSpeedInRange(FIFTH_SPEED_RANGE, speed));
}

bool AutoPilot::MechanicalSetSpeed(int speed)
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

bool AutoPilot::CorrectGearShift(int gear) const
{
	return (gear == -1 && m_direction == Direction::Stand) ||
		   (gear == 1 && m_direction != Direction::Back) ||
		   (gear > 1 && m_direction == Direction::Forward) ||
		   (gear == 0);
}

bool AutoPilot::SetGear(int gear)
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

void AutoPilot::IncreaseSpeed(int speed)
{
	while (speed != m_speed)
	{
		SetGear(m_gear + 1);
		if (!AutoPilot::MechanicalSetSpeed(speed))
		{
			int maxSpeedInCurrentRange = ReturnSpeedRange(m_gear).second;
			AutoPilot::MechanicalSetSpeed(maxSpeedInCurrentRange);
		}
	}
}

void AutoPilot::DecreaseSpeed(int speed)
{
	while (speed != m_speed)
	{
		SetGear(m_gear - 1);
		if (!AutoPilot::MechanicalSetSpeed(speed))
		{
			int maxSpeedInCurrentRange = ReturnSpeedRange(m_gear).first;
			AutoPilot::MechanicalSetSpeed(maxSpeedInCurrentRange);
		}
	}
}

bool AutoPilot::SetSpeed(int speed)
{
	if (speed > MAX_SPEED || (m_gear == -1 && speed > REVERSE_SPEED_RANGE.second))
	{
		return false;
	}

	if (!AutoPilot::MechanicalSetSpeed(speed))
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


bool AutoPilot::TurnOnEngine()
{
	if (!m_isEngineOn)
	{
		m_isEngineOn = true;
		return true;
	}
	return false;
}

bool AutoPilot::TurnOffEngine()
{
	if (m_isEngineOn && m_gear == 0 && m_speed == 0)
	{
		m_isEngineOn = false;
		return true;
	}
	return false;

}

bool AutoPilot::ReturnEngine() const
{
	return m_isEngineOn;
}

int AutoPilot::ReturnGear() const
{
	return m_gear;
}
int AutoPilot::ReturnSpeed() const
{
	return m_speed;
}

Direction AutoPilot::ReturnDirection() const
{
	return m_direction;
}

