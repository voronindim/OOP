#include "ExpandTemplate.h"

using namespace std;

BohrVertex MakeBohrVertex(int parent, char symbol)
{
	BohrVertex vertex{};
	memset(reinterpret_cast<void*>(vertex.nextVertex), 255, sizeof(vertex.nextVertex));
	memset(reinterpret_cast<void*>(vertex.autoMove), 255, sizeof(vertex.autoMove));
	vertex.isTerminal = false;
	vertex.suffixLink = NOT_USED;
	vertex.suffixGoodLink = NOT_USED;
	vertex.parent = parent;
	vertex.symbol = symbol;
	return vertex;
}

int GetSuffixLink(int vertex, vector<BohrVertex>& bohr)
{
	int &suffixLink = bohr[vertex].suffixLink;
	int &parent = bohr[vertex].parent;

	if (suffixLink == NOT_USED)
	{
		if (vertex == ROOT || parent == ROOT)
		{
			suffixLink = ROOT;
		}
		else
		{
			suffixLink = GetAutoMove(GetSuffixLink(parent, bohr), bohr[vertex].symbol, bohr);
		}
	}
	return suffixLink;
}

int GetAutoMove(int vertex, char symbol, vector<BohrVertex>& bohr)
{
	int &nextVertex = bohr[vertex].nextVertex[symbol];
	int &suffixFromLastTransition = bohr[vertex].autoMove[symbol];

	if (suffixFromLastTransition == NOT_USED)
	{
		if (nextVertex != NOT_USED)
		{
			suffixFromLastTransition = nextVertex;
		}
		else
		{
			if (vertex == ROOT)
			{
				suffixFromLastTransition = ROOT;
			}
			else
			{
				suffixFromLastTransition = GetAutoMove(GetSuffixLink(vertex, bohr), symbol, bohr);
			}
		}
	}
	return suffixFromLastTransition;
}

int GetGoodSuffixLink(int vertex, vector<BohrVertex>& bohr)
{
	int &suffixFlink = bohr[vertex].suffixGoodLink;

	if (suffixFlink == NOT_USED)
	{
		int u = GetSuffixLink(vertex, bohr);
		if (u == ROOT)
		{
		    suffixFlink = ROOT;
		}
		else
		{
		    suffixFlink = (bohr[u].isTerminal) ? u : GetGoodSuffixLink(u, bohr);
		}
	}
	return suffixFlink;
}

void AddStringToBohr(const string * ptr, vector<BohrVertex>& bohr)
{
	int num = 0;
	string str = *ptr;
	for (char ch : str)
	{
		if (bohr[num].nextVertex[ch] == NOT_USED)
		{
			bohr.push_back(MakeBohrVertex(num, ch));
			bohr[num].nextVertex[ch] = int(bohr.size() - 1);
		}
		num = bohr[num].nextVertex[ch];
	}
	bohr[num].isTerminal = true;
	bohr[num].ptr = const_cast<string*>(ptr);
}

void Check(int vertex, int startStr, vector<BohrVertex>& bohr, map<int, string>& substrings)
{
	for(int u = vertex; u != 0; u = GetGoodSuffixLink(u, bohr))
	{
		string &stringToReplace = *(bohr[u].ptr);
		if (bohr[u].isTerminal)
		{
			substrings[startStr - stringToReplace.length()] = stringToReplace;
		}
	}
}

vector<BohrVertex> CreateBohr(const Replacement& params)
{
	vector<BohrVertex> bohr;
	bohr.push_back(MakeBohrVertex(-1, CHAR_ROOT));
	for(const auto& item : params)
	{
		AddStringToBohr(&(item.first), bohr);
	}
	return bohr;
}

map<int, string> SearchSubstrings(const string& tpl, vector<BohrVertex>& bohr)
{
	map<int, string> substrings;
	int u = 0;
	for(int i = 0; i < tpl.length(); i++)
	{
		u = GetAutoMove(u, tpl[i], bohr);
		Check(u, i + 1, bohr, substrings);
	}
	return substrings;
}

string ExpandTemplate(const string& tpl, const Replacement& params)
{
    vector<BohrVertex> bohr = CreateBohr(params);
    map<int, string> substrings = SearchSubstrings(tpl, bohr);
    string resultStr, stringToReplace;
    int startSubstring;
    int pos = 0;
    for(auto & substring : substrings)
    {
        startSubstring = substring.first;
        stringToReplace = substring.second;
        if (startSubstring >= pos)
        {
            resultStr += tpl.substr(pos, startSubstring - pos);
            pos = startSubstring;
            resultStr += params.find(stringToReplace)->second;
            pos += stringToReplace.length();
        }
	}
    resultStr += tpl.substr(pos, tpl.length() - pos);
    return resultStr;
}


