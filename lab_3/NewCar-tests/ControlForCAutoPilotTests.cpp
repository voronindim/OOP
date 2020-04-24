#include "../NewCar/CAutoPilot.h"
#include "../NewCar/ControlAutoPilot.h"
#include "../catch.hpp"
#include "MockedCar.h"

TEST_CASE("HandleCommand для AutoPilot возращает false, встречена неизвестная команда.")
{
	MockedCar car;
	auto autoPilot = CAutoPilot(car);
	ControlAutoPilot control(autoPilot);
	std::string commandLine = "Неизвестная команда";
	CHECK(!control.HandleCommand(commandLine));
}

TEST_CASE("HandleCommand для AutoPilot (\"EngineOn\") возращает true, если команда найдена")
{
	MockedCar car;
	auto autoPilot = CAutoPilot(car);
	ControlAutoPilot control(autoPilot);
	std::string commandLine = "EngineOn";
	CHECK(control.HandleCommand(commandLine));
}

TEST_CASE("HandleCommand для AutoPilot (\"EngineOff\") возращает true, если команда найдена")
{
	MockedCar car;
	auto autoPilot = CAutoPilot(car);
	ControlAutoPilot control(autoPilot);
	std::string commandLine = "EngineOff";
	CHECK(control.HandleCommand(commandLine));
}

TEST_CASE("HandleCommand для AutoPilot (\"Neutral\") возращает true, если команда найдена")
{
	MockedCar car;
	auto autoPilot = CAutoPilot(car);
	ControlAutoPilot control(autoPilot);
	std::string commandLine = "Neutral";
	CHECK(control.HandleCommand(commandLine));
}

TEST_CASE("HandleCommand для AutoPilot (\"Back\") возращает true, если команда найдена")
{
	MockedCar car;
	auto autoPilot = CAutoPilot(car);
	ControlAutoPilot control(autoPilot);
	std::string commandLine = "Back";
	CHECK(control.HandleCommand(commandLine));
}

TEST_CASE("HandleCommand для AutoPilot (\"Forward\") возращает true, если команда найдена")
{
	MockedCar car;
	auto autoPilot = CAutoPilot(car);
	ControlAutoPilot control(autoPilot);
	std::string commandLine = "Forward";
	CHECK(control.HandleCommand(commandLine));
}

TEST_CASE("HandleCommand для AutoPilot (\"SetSpeed\") возращает true, если команда найдена")
{
	MockedCar car;
	auto autoPilot = CAutoPilot(car);
	ControlAutoPilot control(autoPilot);
	std::string commandLine = "SetSpeed";
	CHECK(control.HandleCommand(commandLine));
}

TEST_CASE("HandleCommand для AutoPilot (\"Info\") возращает true, если команда найдена")
{
	MockedCar car;
	auto autoPilot = CAutoPilot(car);
	ControlAutoPilot control(autoPilot);
	std::string commandLine = "Info";
	CHECK(control.HandleCommand(commandLine));
}