#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

typedef map <string, string> Replacement;
struct BohrVertex
{
	int nextVertex[255] = {-1};
	string *ptr = nullptr; // указатель на строку в params
	int parent{}; // родитель
	int autoMove[255] = {-1};
	int suffLink{}; // суффиксальная ссылка
	int suffFlink{}; // "хорошая" суффиксальная ссылка
	char symbol{}; // символ на ребре от родителя
	bool flag = false;
};

bool  CopyFileWithReplace(const string& inputFileName, const string& outputFileName, const Replacement& params);