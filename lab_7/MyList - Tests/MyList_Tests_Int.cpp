#include "../catch.hpp"
#include "../MyList/MyList.h"

TEST_CASE("Проверка копирующего конструктора с числом")
{
	MyList<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);

	MyList<int> list1(list);

	CHECK_FALSE(list1.IsEmpty());
	CHECK(list1.GetSize() == 3);

	int result = 0;
	for (const int & number : list1)
	{
		result += number;
	}
	CHECK(result == 6);
}

TEST_CASE("Тестирование перемещающего конструктор c числом")
{
	MyList<int> list;

	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);

	MyList<int> list1(std::move(list));

	CHECK(list.IsEmpty());
	CHECK(list.GetSize() == 0);
	CHECK(list.begin() == list.end());

	CHECK_FALSE(list1.IsEmpty());
	CHECK(list1.GetSize() == 3);

	int result = 0;
	for (const int & number : list1)
	{
		result += number;
	}
	CHECK(result == 6);
}

TEST_CASE("Проверка метода PushBack с числом")
{
	MyList<int> list;
	list.PushBack(1);
	CHECK(list.GetSize() == 1);
	CHECK(list.GetBackElement() == 1);

	list.PushBack(2);
	CHECK(list.GetSize() == 2);
	CHECK(list.GetBackElement() == 2);
}

TEST_CASE("Проверка метода PushFront с числом")
{
	MyList<int> list;
	list.PushFront(1);
	CHECK(list.GetSize() == 1);
	CHECK(list.GetFrontElement() == 1);

	list.PushFront(2);
	CHECK(list.GetSize() == 2);
	CHECK(list.GetFrontElement() == 2);
}

TEST_CASE("Проверка метода Insert с числом")
{
	MyList<int> list;

	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);

	list.Insert(list.begin(), 0);
	CHECK(list.GetSize() == 4);
	CHECK(*list.begin() == 0);

	list.Insert(list.end(), 4);
	CHECK(list.GetSize() == 5);
	CHECK(*(--list.end()) == 4);

	list.Insert(++list.begin(), 1);
	CHECK(list.GetSize() == 6);
	CHECK(*(++list.begin()) == 1);

	int result = 0;
	for (const int &number : list)
	{
		result += number;
	}

	CHECK(result == 11);
}



