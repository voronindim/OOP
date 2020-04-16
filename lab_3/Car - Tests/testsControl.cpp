#include "../Car/Control.h"
#include "../catch.hpp"

TEST_CASE("HandleCommand  возращает false, встречена неизвестная команда.")
{
	CCar car;
	Control carControl(car);
	std::string commandLine = "Неизвестная команда";
	CHECK(!carControl.HandleCommand(commandLine));
}

TEST_CASE("HandleCommand(\"EngineOn\") возращает true, если команда найдена")
{
	CCar car;
	Control carControl(car);
	std::string commandLine = "EngineOn";
	CHECK(carControl.HandleCommand(commandLine));
}

TEST_CASE("HandleCommand(\"EngineOff\") возращает true, если команда найдена")
{
	CCar car;
	Control carControl(car);
	std::string commandLine = "EngineOff";
	CHECK(carControl.HandleCommand(commandLine));
}

TEST_CASE("HandleCommand(\"SetGear\") возращает true, если команда найдена")
{
	CCar car;
	Control carControl(car);
	std::string commandLine = "SetGear";
	CHECK(carControl.HandleCommand(commandLine));
}

TEST_CASE("HandleCommand(\"SetSpeed\") возращает true, если команда найдена")
{
	CCar car;
	Control carControl(car);
	std::string commandLine = "SetSpeed";
	CHECK(carControl.HandleCommand(commandLine));
}

TEST_CASE("HandleCommand(\"Info\") возращает true, если команда найдена")
{
	CCar car;
	Control carControl(car);
	std::string commandLine = "Info";
	CHECK(carControl.HandleCommand(commandLine));
}
