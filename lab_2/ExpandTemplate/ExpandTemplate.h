#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

const int NOT_USED = -1;

typedef map <string, string> Replacement;

struct BohrVertex
{
	int nextVertex[255]{};
	string *ptr = nullptr; // указатель на строку в params
	int parent{}; // родитель
	int autoMove[255]{};
	int suffLink{}; // суффиксальная ссылка
	int suffFlink{}; // "хорошая" суффиксальная ссылка
	char symbol{}; // символ на ребре от родителя
	bool flag = false;
};

bool  CopyFileWithReplace(const string& inputFileName, const string& outputFileName, const Replacement& params);