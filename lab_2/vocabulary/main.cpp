#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;
typedef vector <string> Translation;
typedef map <string, Translation> Dictionary;

bool OpeningAndCreatingDictionary(const string& fileName, Dictionary &vocabulary)
{
	fstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		cout << "Словарь не открыт!" << endl;
		return false;
	}
	string str;
	while (getline(file, str))
	{
		int i = 0;
		stringstream ss(str);
		string wordKey;
		ss >> wordKey;
//		vocabulary[i].first = wordKey.erase(wordKey.begin(), wordKey.end() - 1);

	}

	for (auto &item: vocabulary)
	{
	}

	return true;
}

bool TranslationOfWords(const string& vocabularyFileName, Dictionary& vocabulary)
{
	string word;
	cin >> word;

}

int main(int argc, char* argv[])

{
	if (argc != 2)
	{
		cout << "Параметры ввода: <name.exe> <name vocabulary.txt>" << endl;
		return 1;
	}

	string vocabularyFileName = argv[1];
	Dictionary vocabulary;
	if (!OpeningAndCreatingDictionary(vocabularyFileName, vocabulary))
	{
		return 1;
	}

	TranslationOfWords(vocabularyFileName, vocabulary);

    return 0;
}
