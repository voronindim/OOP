#include "ExpandTemplate.h"

BohrVertex MakeBohrVertex(int parent, char symbol)
{
	BohrVertex vertex{};
	memset(reinterpret_cast<void*>(vertex.nextVertex), 255, sizeof(vertex.nextVertex));
	memset(reinterpret_cast<void*>(vertex.autoMove), 255, sizeof(vertex.autoMove));
	vertex.isTerminal = false;
	vertex.suffLink = NOT_USED;
	vertex.suffFlink = NOT_USED;
	vertex.parent = parent;
	vertex.symbol = symbol;
	return vertex;
}

int GetAutoMove(int vertex, char symbol, vector<BohrVertex>& bohr);

int GetSuffLink(int vertex, vector<BohrVertex>& bohr)
{
	int &suffLink = bohr[vertex].suffLink;
	int &parent = bohr[vertex].parent;

	if (suffLink == NOT_USED)
	{
		if (vertex == ROOT || parent == ROOT)
		{
			suffLink = ROOT;
		}
		else
		{
			suffLink = GetAutoMove(GetSuffLink(parent, bohr), bohr[vertex].symbol, bohr);
		}
	}
	return suffLink;
}

int GetAutoMove(int vertex, char symbol, vector<BohrVertex>& bohr)
{
	int &nextVertex = bohr[vertex].nextVertex[symbol];
	int &lastTransition = bohr[vertex].autoMove[symbol];

	if (lastTransition == NOT_USED)
	{
		if (nextVertex != NOT_USED)
		{
			lastTransition = nextVertex;
		}
		else
		{
			if (vertex == ROOT)
			{
				lastTransition = ROOT;
			}
			else
			{
				lastTransition = GetAutoMove(GetSuffLink(vertex, bohr), symbol, bohr);
			}
		}
	}
	return lastTransition;
}

int GetSuffFlink(int vertex, vector<BohrVertex>& bohr)
{
	int &suffFlink = bohr[vertex].suffFlink;

	if (suffFlink == NOT_USED)
	{
		int u = GetSuffLink(vertex, bohr);
		if (u == ROOT)
		{
			suffFlink = ROOT;
		}
		else
		{
			suffFlink = (bohr[u].isTerminal) ? u : GetSuffFlink(u, bohr);
		}
	}
	return suffFlink;
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
	for(int u = vertex; u != 0; u = GetSuffFlink(u, bohr))
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

string ReplaceSubstrings(const string& tpl, const map<int, string>& substrings, const Replacement& params)
{
	string resultStr;
	int pos = 0;
	for(auto & substring : substrings)
	{
		if (substring.first >= pos)
		{
			resultStr += tpl.substr(pos, substring.first - pos);
			pos = substring.first;
			resultStr += params.find(substring.second)->second;
			pos += substring.second.length();
		}
	}
	resultStr += tpl.substr(pos, tpl.length() - pos);
	cout << resultStr << endl;
	return resultStr;

}

string ExpandTemplate(const string& tpl, const Replacement& params)
{
    vector<BohrVertex> bohr = CreateBohr(params);

	map<int, string> substrings = SearchSubstrings(tpl, bohr);

	string resultStr = ReplaceSubstrings(tpl, substrings, params);
    return resultStr;
}


