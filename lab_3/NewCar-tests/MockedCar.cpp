#include "MockedCar.h"

bool MockedCar::TurnOnEngine()
{
	if (!m_isEngineOn)
	{
		m_isEngineOn = true;
		return true;
	}
	return false;
}
bool MockedCar::TurnOffEngine()
{
	if (m_isEngineOn && m_gear == 0 && m_speed == 0)
	{
		m_isEngineOn = false;
		return true;
	}
	return false;
}

bool MockedCar::IsSpeedInRange(const std::pair<int, int>& speedRange, int speed) const
{
	return speed >= speedRange.first && speed <= speedRange.second;
}

bool MockedCar::CurrentSpeedInGearSpeedRange(int speed, int gear) const
{
	return (gear == -1 && IsSpeedInRange(REVERSE_SPEED_RANGE, speed)) ||
		   (gear == 0 && IsSpeedInRange(NEUTRAL_SPEED_RANGE, speed)) ||
		   (gear == 1 && IsSpeedInRange(FIRST_SPEED_RANGE, speed)) ||
		   (gear == 2 && IsSpeedInRange(SECOND_SPEED_RANGE, speed)) ||
		   (gear == 3 && IsSpeedInRange(THIRD_SPEED_RANGE, speed)) ||
		   (gear == 4 && IsSpeedInRange(FOURTH_SPEED_RANGE, speed)) ||
		   (gear == 5 && IsSpeedInRange(FIFTH_SPEED_RANGE, speed));
}

bool MockedCar::CorrectGearShift(int gear) const
{
	return (gear == -1 && m_direction == Direction::Stand) ||
		   (gear == 1 && m_direction != Direction::Back) ||
		   (gear > 1 && m_direction == Direction::Forward) ||
		   (gear == 0);
}

bool MockedCar::SetGear(int gear)
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
	variants.push_back(m_gear);
//	std::cout << std::get<Gear>(variants.back()).value <<  std::endl;
	return true;
}

bool MockedCar::SetSpeed(int speed)
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
	variants.push_back(m_speed);
	m_direction = (speed == 0) ? Direction::Stand :
				  (speed > 0 && m_gear == -1) ? Direction::Back :
				  (speed > 0 && m_gear > 0) ? Direction::Forward :
				  m_direction;
	return true;
}

bool MockedCar::ReturnEngineOn() const
{
	return m_isEngineOn;
}

int MockedCar::ReturnCurrentGear() const
{
	return m_gear;
}

int MockedCar::ReturnCurrentSpeed() const
{
	return m_speed;
}

Direction MockedCar::ReturnCurrentDirection() const
{
	return m_direction;
}

