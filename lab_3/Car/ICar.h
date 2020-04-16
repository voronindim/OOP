#pragma once
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

class ICar
{
public:
	virtual bool TurnOnEngine() = 0;
	virtual bool TurnOffEngine() = 0;
	[[nodiscard]] virtual bool ReturnEngine() const = 0;

	virtual bool SetGear(int gear) = 0;
	[[nodiscard]] virtual int ReturnGear() const = 0;

	virtual bool SetSpeed(int speed) = 0;
	[[nodiscard]] virtual int ReturnSpeed() const = 0;

	[[nodiscard]] virtual Direction ReturnDirection() const = 0;
};
