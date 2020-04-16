#include "../Car/ControlAutoPilot.h"
#include "../catch.hpp"

TEST_CASE("Автопилот HandleCommand возращает false, встречена неизвестная команда.")
{
	AutoPilot car;
	ControlAutoPilot carControl(car);
	std::string commandLine = "Неизвестная команда";
	CHECK(!carControl.HandleCommand(commandLine));
}

TEST_CASE("Автопилот HandleCommand(\"EngineOn\") возращает true, если команда найдена")
{
	AutoPilot car;
	ControlAutoPilot carControl(car);
	std::string commandLine = "EngineOn";
	CHECK(carControl.HandleCommand(commandLine));
}

TEST_CASE("Автопилот HandleCommand(\"EngineOff\") возращает true, если команда найдена")
{
	AutoPilot car;
	ControlAutoPilot carControl(car);
	std::string commandLine = "EngineOff";
	CHECK(carControl.HandleCommand(commandLine));
}

TEST_CASE("Автопилот HandleCommand(\"SetGear\") возращает true, если команда найдена")
{
	AutoPilot car;
	ControlAutoPilot carControl(car);
	std::string commandLine = "SetGear";
	CHECK(carControl.HandleCommand(commandLine));
}

TEST_CASE("Автопилот HandleCommand(\"SetSpeed\") возращает true, если команда найдена")
{
	AutoPilot car;
	ControlAutoPilot carControl(car);
	std::string commandLine = "SetSpeed";
	CHECK(carControl.HandleCommand(commandLine));
}

TEST_CASE("Автопилот HandleCommand(\"Info\") возращает true, если команда найдена")
{
	AutoPilot car;
	ControlAutoPilot carControl(car);
	std::string commandLine = "Info";
	CHECK(carControl.HandleCommand(commandLine));
}