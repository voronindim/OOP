#include "ExpandTemplate.h"

BohrVertex MakeBohrVertex(int parent, char symbol)
{
	BohrVertex vertex{};
	memset(reinterpret_cast<void*>(vertex.nextVertex), 255, sizeof(vertex.nextVertex));
	memset(reinterpret_cast<void*>(vertex.autoMove), 255, sizeof(vertex.autoMove));
	vertex.flag = false;
	vertex.suffLink = -1;
	vertex.suffFlink = -1;
	vertex.parent = parent;
	vertex.symbol = symbol;
	return vertex;
}

int GetAutoMove(int vertex, char symbol, vector<BohrVertex>& bohr);

int GetSuffLink(int vertex, vector<BohrVertex>& bohr)
{
	if (bohr[vertex].suffLink == -1)
	{
		if (vertex == 0 || bohr[vertex].parent == 0)
		{
			bohr[vertex].suffLink = 0;
		}
		else
		{
			bohr[vertex].suffLink = GetAutoMove(GetSuffLink(bohr[vertex].parent, bohr), bohr[vertex].symbol, bohr);
		}
	}
	return bohr[vertex].suffLink;
}

int GetAutoMove(int vertex, char symbol, vector<BohrVertex>& bohr)
{
	if (bohr[vertex].autoMove[symbol] == -1)
	{
		if (bohr[vertex].nextVertex[symbol] != -1)
		{
			bohr[vertex].autoMove[symbol] = bohr[vertex].nextVertex[symbol];
		}
		else
		{
			if (vertex == 0)
			{
				bohr[vertex].autoMove[symbol] = 0;
			}
			else
			{
				bohr[vertex].autoMove[symbol] = GetAutoMove(GetSuffLink(vertex, bohr), symbol, bohr);
			}
		}
	}
	return bohr[vertex].autoMove[symbol];
}

int GetSuffFlink(int vertex, vector<BohrVertex>& bohr)
{
	if (bohr[vertex].suffFlink == -1)
	{
		int u = GetSuffLink(vertex, bohr);
		if (u == 0)
		{
			bohr[vertex].suffFlink = 0;
		}
		else
		{
			bohr[vertex].suffFlink = (bohr[u].flag) ? u : GetSuffFlink(u, bohr);
		}
	}
	return bohr[vertex].suffFlink;
}

void AddStringToBohr(const string * ptr, vector<BohrVertex>& bohr)
{
	int num = 0;
	string str = *ptr;
	for (char ch : str)
	{
		int i = ch;

		if (bohr[num].nextVertex[i] == -1)
		{
			bohr.push_back(MakeBohrVertex(num, ch));
			bohr[num].nextVertex[i] = bohr.size() - 1;
		}
		num = bohr[num].nextVertex[i];
	}
	bohr[num].flag = true;
	bohr[num].ptr = const_cast<string*>(ptr);
}

void Check(int vertex, int startStr, vector<BohrVertex>& bohr, map<int, string>& subStrings)
{
	for(int u = vertex; u != 0; u = GetSuffFlink(u, bohr))
	{
		if (bohr[u].flag)
		{
			subStrings[startStr - (*(bohr[u].ptr)).length()] = (*(bohr[u].ptr));
		}
	}
}



string ExpendTemplate(const string& tpl, const Replacement& params)
{
    vector<BohrVertex> bohr;
    map<int, string> subStrings;
    bohr.push_back(MakeBohrVertex(-1, '~'));
    for(const auto& item : params)
	{
    	AddStringToBohr(&(item.first), bohr);
	}

    int u = 0;
    for(int i = 0; i < tpl.length(); i++)
	{
    	u = GetAutoMove(u, tpl[i], bohr);
    	Check(u, i + 1, bohr, subStrings);
	}

    string resultStr;
    int pos = 0;
    for(auto & subString : subStrings)
	{
    	if (subString.first >= pos)
		{
			resultStr += tpl.substr(pos, subString.first - pos);
			pos = subString.first;
			resultStr += params.find(subString.second)->second;
			pos += subString.second.length();
		}
	}
    resultStr += tpl.substr(pos, tpl.length() - pos);
	cout << resultStr << endl;
    return resultStr;
}


bool CopyFileWithReplace(const string& inputFileName, const string& outputFileName, const Replacement& params)
{
	ifstream inputFile;
	inputFile.open(inputFileName);
	if (!inputFile.is_open())
	{
		cout << "Input файл не открыт" << endl;
		return false;
	}
	ofstream outputFile;
	outputFile.open(outputFileName);
	if (!outputFile.is_open())
	{
		cout << "Output файл не открыт" << endl;
		return false;
	}
	string tpl;
	while (getline(inputFile, tpl))
	{
		outputFile << ExpendTemplate(tpl, params) << endl;
	}
	return true;
}