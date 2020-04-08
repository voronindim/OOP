#include "catch.hpp"
#include "../ExpandTemplate/ExpandTemplate.h"

TEST_CASE("Функция ExpandTemplate должна вернуть строку с заменой")
{
	string tpl, resultStr;
	Replacement params;

	tpl = "-AABBCCCCCABC+";
	params = {
		{"A", "[a]"},
		{"AA", "[aa]"},
		{"B", "[b]"},
		{"BB", "[bb]"},
		{"C", "[c]"},
		{"CC", "[cc]"}
	};
	resultStr = "-[aa][bb][cc][cc][c][a][b][c]+";
	CHECK(ExpandTemplate(tpl, params) == resultStr);

	tpl = "Hello. My name is %USER_NAME%";
	params = {
		{"%USER_NAME%", "Dmitrii"}
	};
	resultStr = "Hello. My name is Dmitrii";
	CHECK(ExpandTemplate(tpl, params) == resultStr);
}

TEST_CASE("Функция CreateBohr должна вернуть vector<BohrVertex>, проверка значений вершин")
{
	Replacement params = {
		{"AB", "[a]"}
	};
	vector<BohrVertex> resultBohr = CreateBohr(params);
	CHECK(resultBohr[1].symbol == 'A');
	CHECK(!resultBohr[1].isTerminal);
	CHECK(resultBohr[1].suffixGoodLink == -1);
	CHECK(resultBohr[1].parent == ROOT);
	CHECK(resultBohr[1].ptr == nullptr);
	CHECK(resultBohr[1].nextVertex['B'] == 2);

	CHECK(resultBohr[2].ptr != nullptr);
	CHECK(resultBohr[2].isTerminal);
}

TEST_CASE("Функция GetSuffixLink должна вернуть число, на которое ссылается посылаемая вершина обозначающая  номер вершины в боре")
{
	Replacement params = {
		{"AB", "[a]"},
		{"BC", "[b]"}
	};
	vector<BohrVertex> bohr = CreateBohr(params);
	int vertex = 2;
	CHECK(GetSuffixLink(vertex, bohr) == 3);

	vertex = 4;
	CHECK(GetSuffixLink(vertex, bohr) == ROOT);
}

TEST_CASE("Функция GetAutoMove должна вернуть число, которое обозначает ссылку на сына от последнего перехода")
{
	Replacement params = {
		{"abc", "1"},
		{"bbbc", "2"},
		{"bcdc", "3"},
		{"bcdd", "4"},
		{"cccb", "5"},

	};
	vector<BohrVertex> bohr = CreateBohr(params);

	int vertex = 1;
	char symbol = 'a';
	CHECK(GetAutoMove(vertex, symbol, bohr) == 1);

	vertex = 2;
	symbol = 'b';
	CHECK(GetAutoMove(vertex, symbol, bohr) == 5);

	vertex = 3;
	symbol = 'c';
	CHECK(GetAutoMove(vertex, symbol, bohr) == 13);

	vertex = 4;
	symbol = 'b';
	CHECK(GetAutoMove(vertex, symbol, bohr) == 5);

	vertex = 5;
	symbol = 'b';
	CHECK(GetAutoMove(vertex, symbol, bohr) == 6);
}
