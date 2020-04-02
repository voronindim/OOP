#include "vocabulary.h"

#include <utility>

bool Save(const string& vocabularyFileName, const Dictionary& vocabulary)
{
	ofstream file;
	file.open(vocabularyFileName);
	if (!file.is_open())
	{
		cout << "Файл для сохранения не был открыт!" << endl;
		return false;
	}

	for( const auto& item : vocabulary)
	{
		file << "[" << item.first << "] ";
		for(auto iter = item.second.begin(); iter != item.second.end();iter++)
		{
			file << *iter;
			if (iter != item.second.end() - 1)
			{
				file << ", ";
			}
		}
		file << endl;
	}
	return true;
}

void AskAndSaveChanges(const string& vocabularyFileName, const Dictionary &vocabulary)
{
	string str;
	cout << "В словарь Были внесены изменения. Введите Y или y для сохранения перед выходом" << endl;
	getline(cin, str);
	if (str == "Y" || str == "y")
	{
		if (vocabularyFileName.empty())
		{
			cout << "Введите название файла для сохранения" << endl;
			getline(cin, str);
		}
		if (Save(vocabularyFileName, vocabulary))
		{
			cout << "Изменения сохранены в " << vocabularyFileName << ". До свидания." << endl;
		}
	}
}

Translation SearchTranslation(string searchWord, const Dictionary& vocabulary)
{
	transform(searchWord.begin(), searchWord.end(), searchWord.begin(), towlower);
	auto iter = vocabulary.find(searchWord);
	if (iter == vocabulary.end())
	{
		return (Translation){};
	}
	return iter->second;
}

bool PrintTranslation(string searchWord, const Dictionary& vocabulary)
{
	Translation translation;
	translation = SearchTranslation(move(searchWord), vocabulary);
	if (translation.empty())
	{
		return false;
	}
	for(auto iter = translation.begin(); iter != translation.end(); iter++)
	{
		cout << *iter;
		if (iter != translation.end() - 1)
		{
			cout << ", ";
		}
	}
	cout << endl;
	return true;
}

void AddWordToVocabulary(string word, Dictionary& vocabulary, const string& translation)
{
	transform(word.begin(), word.end(), word.begin(), towlower);
	Translation translate;
	translate.push_back(translation);
	vocabulary[word] = translate;
}

void TranslationOfWords(const string& vocabularyFileName, Dictionary &vocabulary)
{
	bool changesInVocabulary = false;
	string searchWord;
	while(getline(cin, searchWord))
	{
		if (searchWord == "...")
		{
			if (changesInVocabulary)
			{
				AskAndSaveChanges(vocabularyFileName, vocabulary);
			}
			break;
		}

		if (!PrintTranslation(searchWord, vocabulary))
		{
			cout << "Незиветсное слово \"" << searchWord << "\" Введите перевод или пустую строку для отказа" << endl;
			string translation;
			getline(cin, translation);
			if (!translation.empty())
			{
				AddWordToVocabulary(searchWord, vocabulary, translation);
				changesInVocabulary = true;
				cout << "Слово \"" <<  searchWord << "\" сохранено в словарь как \"" << translation << "\"." << endl;
			}
			else
			{
				cout << "\"" << searchWord << "\"" << " проигнорировано." << endl;
			}
		}
	}
}

void CopyStringToVocabulary(Dictionary &vocabulary, const string& str)
{
	stringstream ss(str);
	string word, wordValue;
	Translation wordTranslation;
	ss >> word;
	while (ss >> wordValue)
	{
		if (wordValue[wordValue.size() - 1] == ',')
		{
			wordValue.erase(wordValue.end() - 1);
		}
		wordTranslation.push_back(wordValue);
	}
	word = word.substr(1, word.size() - 2);
	vocabulary[word] = wordTranslation;
}

bool CreatingVocabulary(const string& vocabularyFileName, Dictionary &vocabulary)
{
	ifstream file;
	file.open(vocabularyFileName);
	if (!file.is_open())
	{
		cout << "Словарь не открыт!" << endl;
	}

	string str;
	while (getline(file, str))
	{
        CopyStringToVocabulary(vocabulary, str);
	}
	return true;
}