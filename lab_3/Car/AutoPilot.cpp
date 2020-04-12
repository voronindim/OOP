#include "AutoPilot.h"
#include <iostream>

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

void AutoPilot::IncreaseSpeed(int speed)
{
	while (speed != m_speed)
	{
		SetGear(m_gear + 1);
		if (!CCar::SetSpeed(speed))
		{
			int maxSpeedInCurrentRange = ReturnSpeedRange(m_gear).second;
			CCar::SetSpeed(maxSpeedInCurrentRange);
		}
	}
}

void AutoPilot::DecreaseSpeed(int speed)
{
	while (speed != m_speed)
	{
		SetGear(m_gear - 1);
		if (!CCar::SetSpeed(speed))
		{
			int maxSpeedInCurrentRange = ReturnSpeedRange(m_gear).first;
			CCar::SetSpeed(maxSpeedInCurrentRange);
		}
	}
}

bool AutoPilot::SetSpeed(int speed)
{
	if (speed > MAX_SPEED)
	{
		return false;
	}
	if (!CCar::SetSpeed(speed))
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
