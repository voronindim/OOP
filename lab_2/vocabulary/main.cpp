#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

typedef vector <string> Translation;
typedef map <string, Translation> Dictionary;

const static string STRING_SAVE = "...";

bool OpeningInputFileAndCreatingDictionary(const string& fileName, Dictionary &vocabulary)
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
		stringstream ss(str);
		string wordKey, wordValue;
		ss >> wordKey;
		Translation wordTranslation;
		while (ss >> wordValue)
		{
			if (wordValue[wordValue.size() - 1] == ',')
			{
				wordValue.erase(wordValue.end() - 1);
			}
			wordTranslation.push_back(wordValue);
		}
		wordKey = wordKey.substr(1, wordKey.size() - 2);
		vocabulary[wordKey] = wordTranslation;
	}
	return true;
}

bool OpenOutputFileAndSave( string& vocabularyFileName, Dictionary& vocabulary)
{
	ofstream file;
	file.open(vocabularyFileName);
	if (!file.is_open())
	{
		cout << "Файл для сохранения не был открыт" << endl;
		return false;
	}
	for (auto & it1 : vocabulary)
	{
		file << "[" << it1.first << "] ";
		for( auto it2 = it1.second.begin(); it2 != it1.second.end(); it2 ++)
		{
			file << *it2;
			if (it2 != it1.second.end() - 1)
			{
				file << ",";
			}
		}
		file << endl;
	}
	return true;
}


void AskingAndSaveChanges(string& vocabularyFileName, Dictionary& vocabulary)
{
	string str;
	cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом." << endl;
	getline(cin, str);
	if (str == "Y" || str == "y")
	{
		if (vocabularyFileName.empty())
		{
			cout << "Введите название файла для сохранения" << endl;
			getline(cin, vocabularyFileName);
		}
		if (OpenOutputFileAndSave(vocabularyFileName, vocabulary))
		{
			cout << "Изменения сохранены в " << vocabularyFileName << ". Goodbye!" << endl;
		}
	}
	else
	{
		cout << "Изменения не сохранены. До свидания" << endl;
	}
}

bool SearchAndPrintTranslation( string word, Dictionary& vocabulary)
{
	transform(word.begin(), word.end(), word.begin(), towlower);
	auto it = (vocabulary.find(word));
	if (it != vocabulary.end())
	{
		for (int i = 0; i < it->second.size(); i++)
		{
			cout << it->second[i];
			if (i != it->second.size() - 1)
			{
				cout << ", ";
			}
		}
		cout << endl;
	}
	else
	{
		return false;
	}
	return true;
}

bool AddWord( string word, Dictionary& vocabulary, string& translation)
{
	transform(word.begin(), word.end(), word.begin(), towlower);
	Translation translate;
	translate.push_back(translation);
	vocabulary[word] = translate;
	return true;
}

void TranslationOfWords( string& vocabularyFileName, Dictionary& vocabulary)
{
	bool change = false;
	string searchWord;
	while(getline(cin, searchWord))
	{
		if (searchWord == STRING_SAVE)
		{
			if (change)
			{
				AskingAndSaveChanges(vocabularyFileName, vocabulary);
			}
			break;
		}

		if (!SearchAndPrintTranslation( searchWord, vocabulary))
		{
			cout << "Неизвестное слово \"" << searchWord << "\" " << "Введите перевод или пустую строку для отказа" << endl;
			string translation;
			getline(cin, translation);
			if (translation.empty())
			{
				cout << "\"" << searchWord << "\"" << " проигнорировано." << endl;
			}
			else
			{
				if (AddWord(searchWord, vocabulary, translation))
				{
					cout << "Слово \"" << searchWord << "\" сохраено в словарь как \"" << translation << "\"." << endl;
					change = true;
				}
			}
		}
	}
}

int main(int argc, char* argv[])

{
	string vocabularyFileName;
	Dictionary vocabulary;
	if (argc == 2)
	{
		vocabularyFileName = argv[1];
		if (!OpeningInputFileAndCreatingDictionary(vocabularyFileName, vocabulary))
		{
			return 1;
		}
	}

	TranslationOfWords(vocabularyFileName, vocabulary);

    return 0;
}
