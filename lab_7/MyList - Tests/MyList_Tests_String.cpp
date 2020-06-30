#include "../catch.hpp"
#include "../MyList/MyList.h"

TEST_CASE("Стандартный конструктор")
{
	MyList<std::string> list;
	CHECK(list.GetSize() == 0);
	CHECK(list.IsEmpty());
	CHECK(list.begin() == list.end());

	CHECK_THROWS_AS(*list.begin(), std::runtime_error);
	CHECK_THROWS_AS(++list.begin(), std::runtime_error);
}

TEST_CASE("Проверка метода PushBack")
{
	MyList<std::string> list;
	list.PushBack("hello");
	CHECK(list.GetSize() == 1);
	CHECK(list.GetBackElement() == "hello");

	list.PushBack("world");
	CHECK(list.GetSize() == 2);
	CHECK(list.GetBackElement() == "world");
}

TEST_CASE("Проверка метода PushFront")
{
	MyList<std::string> list;
	list.PushFront("hello");
	CHECK(list.GetSize() == 1);
	CHECK(list.GetFrontElement() == "hello");

	list.PushFront("world");
	CHECK(list.GetSize() == 2);
	CHECK(list.GetFrontElement() == "world");
}

TEST_CASE("Тестирование const списка")
{
	MyList<std::string> list;
	list.PushBack("1");
	list.PushBack("2");
	list.PushBack("3");

	const MyList<std::string> list1(list);
	CHECK(list1.GetFrontElement() == "1");
	CHECK(list1.GetBackElement() == "3");
}

TEST_CASE("Проверка метода Clear")
{
	MyList<std::string> list;
	list.PushBack("1");
	list.PushBack("2");
	list.PushBack("3");

	list.Clear();

	CHECK(list.IsEmpty());
	CHECK(list.GetSize() == 0);
	CHECK(list.begin() == list.end());
}

TEST_CASE("Проверка копирующего конструктора")
{
	MyList<std::string> list;
	list.PushBack("1");
	list.PushBack("2");
	list.PushBack("3");

	MyList<std::string> list1(list);

	CHECK_FALSE(list1.IsEmpty());
	CHECK(list1.GetSize() == 3);

	std::string result;
	for (const std::string& string : list1)
	{
	result += string;
	}
	CHECK(result == "123");
}

TEST_CASE("Проверка оператора =")
{
	MyList<std::string> list;

	list.PushBack("hello ");
	list.PushBack("world ");
	list.PushBack("people");

	MyList<std::string> list1 = list;

	CHECK_FALSE(list1.IsEmpty());
	CHECK(list1.GetSize() == 3);
	std::string result;
	for (const  std::string &string : list1)
	{
	result += string;
	}
	CHECK(result == "hello world people");
}

TEST_CASE("Тестирование перемещающего конструктор")
{
	MyList<std::string> list;

	list.PushBack("hello ");
	list.PushBack("world ");
	list.PushBack("people");

	MyList<std::string> list1(std::move(list));

	CHECK(list.IsEmpty());
	CHECK(list.GetSize() == 0);
	CHECK(list.begin() == list.end());

	CHECK_FALSE(list1.IsEmpty());
	CHECK(list1.GetSize() == 3);

	std::string result;
	for (const  std::string &string : list1)
	{
	result += string;
	}
	CHECK(result == "hello world people");
}

TEST_CASE("Перемещающий оператор = ")
{
	MyList<std::string> list;

	list.PushBack("hello ");
	list.PushBack("world ");
	list.PushBack("people");

	MyList<std::string> list1 = std::move(list);

	CHECK(list.IsEmpty());
	CHECK(list.GetSize() == 0);
	CHECK(list.begin() == list.end());

	CHECK_FALSE(list1.IsEmpty());
	CHECK(list1.GetSize() == 3);

	std::string result;
	for (const  std::string &string : list1)
	{
	result += string;
	}
	CHECK(result == "hello world people");

	list1 = std::move(list1);

	CHECK_FALSE(list1.IsEmpty());
	CHECK(list1.GetSize() == 3);

	result = "";
	for (const std::string &string1 : list1)
	{
	result += string1;
	}

	CHECK(result == "hello world people");
}

TEST_CASE("Тестирование итераторов")
{
	MyList<std::string> list;
	list.PushBack("1");
	list.PushBack("2");
	list.PushBack("3");

	CHECK_THROWS_AS(*list.end(), std::runtime_error);
	CHECK_THROWS_AS(++list.end(), std::runtime_error);

	CHECK(*(++list.begin()) == "2");
	CHECK(*(--list.end()) == "3");

	auto iter = list.begin();

	CHECK(*(iter++) == "1");
	CHECK(*iter == "2");

	CHECK(*list.cbegin() == "1");
	CHECK_THROWS_AS(*list.cend(), std::runtime_error);

}

TEST_CASE("Тестирование обратных итераторов")
{
	MyList<std::string> list;
	list.PushBack("1");
	list.PushBack("2");
	list.PushBack("3");

	CHECK_THROWS_AS(*list.rend(), std::runtime_error);

	CHECK(*(--list.rend()) == "1");
	CHECK(*(++list.rbegin()) == "2");

	auto iter = list.rbegin();

	CHECK(*(iter++) == "3");
	CHECK(*iter == "2");

	CHECK(*(iter--) == "2");
	CHECK(*iter == "3");

	CHECK(*list.cbegin() == "1");
	CHECK(*list.crbegin() == "3");
	CHECK_THROWS_AS(*list.crend(), std::runtime_error);
}

TEST_CASE("Проверка метода Insert")
{
	MyList<std::string> list;

	list.PushBack("1");
	list.PushBack("2");
	list.PushBack("3");

	list.Insert(list.begin(), "0");
	CHECK(list.GetSize() == 4);
	CHECK(*list.begin() == "0");

	list.Insert(list.end(), "4");
	CHECK(list.GetSize() == 5);
	CHECK(*(--list.end()) == "4");

	list.Insert(++list.begin(), "1`");
	CHECK(list.GetSize() == 6);
	CHECK(*(++list.begin()) == "1`");

	std::string result;
	for (const std::string &string1 : list)
	{
	result += string1;
	}

	CHECK(result == "01`1234");
}

TEST_CASE("Проверка метода Delete")
{
	MyList<std::string> list;

	list.PushBack("1");
	list.PushBack("2");
	list.PushBack("3");

	CHECK(list.GetSize() == 3);
	CHECK(list.GetFrontElement() == "1");
	CHECK(list.GetBackElement() == "3");

	list.Delete(--list.end());
	CHECK(list.GetSize() == 2);
	CHECK(list.GetBackElement() == "2");
}








