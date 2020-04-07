#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

const int NOT_USED = -1;
const int ROOT = 0;
const char CHAR_ROOT = '~';

typedef map <string, string> Replacement;

struct BohrVertex
{
	int nextVertex[255]{};
	string *ptr = nullptr; // указатель на строку в params
	int parent{}; // родитель
	int autoMove[255]{}; // переход автомата от текущей вершины
	int suffLink{}; // суффиксальная ссылка
	int suffFlink{}; // "хорошая" суффиксальная ссылка
	char symbol{}; // символ на ребре от родителя
	bool isTerminal = false;
};

string ExpandTemplate(const string& tpl, const Replacement& params);