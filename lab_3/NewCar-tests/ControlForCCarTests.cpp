#include "../NewCar/ControlForCCar.h"
#include "../catch.hpp"

TEST_CASE("HandleCommand  возращает false, встречена неизвестная команда.")
{
	CCar car;
	ControlForCCar control(car);
	std::string commandLine = "Неизвестная команда";
	CHECK(!control.HandleCommand(commandLine));
}

TEST_CASE("HandleCommand(\"EngineOn\") возращает true, если команда найдена")
{
	CCar car;
	ControlForCCar control(car);
	std::string commandLine = "EngineOn";
	CHECK(control.HandleCommand(commandLine));
}

TEST_CASE("HandleCommand(\"EngineOff\") возращает true, если команда найдена")
{
	CCar car;
	ControlForCCar control(car);
	std::string commandLine = "EngineOff";
	CHECK(control.HandleCommand(commandLine));
}

TEST_CASE("HandleCommand(\"SetGear\") возращает true, если команда найдена")
{
	CCar car;
	ControlForCCar control(car);
	std::string commandLine = "SetGear";
	CHECK(control.HandleCommand(commandLine));
}

TEST_CASE("HandleCommand(\"SetSpeed\") возращает true, если команда найдена")
{
	CCar car;
	ControlForCCar control(car);
	std::string commandLine = "SetSpeed";
	CHECK(control.HandleCommand(commandLine));
}

TEST_CASE("HandleCommand(\"Info\") возращает true, если команда найдена")
{
	CCar car;
	ControlForCCar control(car);
	std::string commandLine = "Info";
	CHECK(control.HandleCommand(commandLine));
}