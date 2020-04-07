#include "ExpandTemplate.h"

BohrVertex MakeBohrVertex(int parent, char symbol)
{
	BohrVertex vertex{};
	memset(reinterpret_cast<void*>(vertex.nextVertex), 255, sizeof(vertex.nextVertex));
	memset(reinterpret_cast<void*>(vertex.autoMove), 255, sizeof(vertex.autoMove));
	vertex.flag = false;
	vertex.suffLink = NOT_USED;
	vertex.suffFlink = NOT_USED;
	vertex.parent = parent;
	vertex.symbol = symbol;
	return vertex;
}

int GetAutoMove(int vertex, char symbol, vector<BohrVertex>& bohr);

int GetSuffLink(int vertex, vector<BohrVertex>& bohr)
{
	if (bohr[vertex].suffLink == NOT_USED)
	{
		if (vertex == ROOT || bohr[vertex].parent == ROOT)
		{
			bohr[vertex].suffLink = ROOT;
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
	if (bohr[vertex].autoMove[symbol] == NOT_USED)
	{
		if (bohr[vertex].nextVertex[symbol] != NOT_USED)
		{
			bohr[vertex].autoMove[symbol] = bohr[vertex].nextVertex[symbol];
		}
		else
		{
			if (vertex == 0)
			{
				bohr[vertex].autoMove[symbol] = ROOT;
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
	if (bohr[vertex].suffFlink == NOT_USED)
	{
		int u = GetSuffLink(vertex, bohr);
		if (u == ROOT)
		{
			bohr[vertex].suffFlink = ROOT;
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

		if (bohr[num].nextVertex[i] == NOT_USED)
		{
			bohr.push_back(MakeBohrVertex(num, ch));
			bohr[num].nextVertex[i] = bohr.size() - 1;
		}
		num = bohr[num].nextVertex[i];
	}
	bohr[num].flag = true;
	bohr[num].ptr = const_cast<string*>(ptr);
}

void Check(int vertex, int startStr, vector<BohrVertex>& bohr, map<int, string>& substrings)
{
	for(int u = vertex; u != 0; u = GetSuffFlink(u, bohr))
	{
		if (bohr[u].flag)
		{
			substrings[startStr - (*(bohr[u].ptr)).length()] = (*(bohr[u].ptr));
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

string ReplaceSubstrings(const string& tpl, map<int, string>& substrings, const Replacement& params)
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


