#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <cstring>


const int NOT_USED = -1;
const int ROOT = 0;
const char CHAR_ROOT = '~';

typedef std::map <std::string, std::string> Replacement;

struct BohrVertex
{
	int nextVertex[255]{-1};
	std::string *ptr = nullptr; // указатель на строку в params
	int parent{}; // родитель
	int autoMove[255]{-1}; // показывает ссылку на сына от последнего перехода
	int suffixLink{}; // суффиксальная ссылка
	int suffixGoodLink{}; // "хорошая" суффиксальная ссылка
	char symbol{}; // символ на ребре от родителя
	bool isTerminal = false;
};

std::string ExpandTemplate(const std::string& tpl, const Replacement& params);

std::vector<BohrVertex> CreateBohr(const Replacement& params);

int GetSuffixLink(int vertex, std::vector<BohrVertex>& bohr);

int GetAutoMove(int vertex, char symbol, std::vector<BohrVertex>& bohr);