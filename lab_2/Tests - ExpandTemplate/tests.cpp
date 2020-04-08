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
	CHECK(resultBohr[1].suffFlink == -1);
	CHECK(resultBohr[1].parent == ROOT);
	CHECK(resultBohr[1].ptr == nullptr);
}
