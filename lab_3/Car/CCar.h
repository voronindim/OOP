#include <utility>

const std::pair<int, int> REVERSE_SPEED_RANGE = { 0, 20};
const std::pair<int, int> NEUTRAL_SPEED_RANGE = { 0, 150};
const std::pair<int, int> FIRST_SPEED_RANGE = { 0, 30};
const std::pair<int, int> SECOND_SPEED_RANGE = { 20, 50};
const std::pair<int, int> THIRD_SPEED_RANGE = { 30, 60};
const std::pair<int, int> FOURTH_SPEED_RANGE = { 40, 90};
const std::pair<int, int> FIFTH_SPEED_RANGE = { 50, 150};
const int MAX_SPEED = 150;



enum class Direction
{
    Forward,
    Stand,
    Back
};

class CCar
{
public:
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool ReturnEngine() const;

	bool SetGear(int gear);
	int ReturnGear() const;

	bool SetSpeed(int speed);
	int ReturnSpeed() const;

	Direction ReturnDirection() const;
protected:

	bool m_isEngineOn = false;
	Direction m_direction = Direction::Stand;
	int m_speed = 0;
	int m_gear = 0;

};
