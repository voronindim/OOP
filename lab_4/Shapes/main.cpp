#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <regex>
#include <sstream>
#include "CLineSegment.h"

using namespace std;

bool CreateShapeFromString(const map<string, string>& shapes, const string& inputString)
{
	smatch matches;
	stringstream ss(inputString);
	string shapeName;
	ss >> shapeName;
	if (auto it = shapes.find(shapeName); it != shapes.end())
	{
		regex rx(it->second);
		regex_match(inputString, matches, rx);
		if (shapeName == "LineSegment")
		{
			CPoint startPoint = ;
			CPoint endPoint = {};
			uint32_t outlineColor = stoul(matches[10], 0, 16);
			auto lineSegment = make_unique<CLineSegment>( startPoint,  endPoint,  outlineColor);
		}
	}
	return false;
}

int main()
{
	const map<string, string> shapes = {
		{"LineSegment", "^([[:alpha:]]+) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:xdigit:]]{6})$"},

		{"Triangle", "^([[:alpha:]]+) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) "
			   "([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:xdigit:]]{6}) ([[:xdigit:]]{6})$"},

		{"Rectangle", "^([[:alpha:]]+) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) "
				"([[:xdigit:]]{6}) ([[:xdigit:]]{6})$"},

		{"Circle", "^([[:alpha:]]+) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:xdigit:]]{6}) ([[:xdigit:]]{6})$"}
	};
	cout << "Формат ввода: " << endl;

	string inputString;
	vector <unique_ptr<IShape>> shapesSet;
	while (getline(cin, inputString))
	{
		CreateShapeFromString(shapes, inputString);
	}

	return 0;
}
