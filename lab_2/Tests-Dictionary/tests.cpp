#include "catch.hpp"
#include "../dictionary/vocabulary.h"

using namespace std::literals;

TEST_CASE("В словаре после функции 'CopyStringToVocabulary' должна повится запись строки str")
{
    Dictionary vocabulary;
    string str = "[cat] кот, кошка"s;
    CopyStringToVocabulary(vocabulary, str);
	Dictionary resultVocabulary = {
            {"cat"s, {"кот"s, "кошка"s}}
    };
    CHECK(resultVocabulary == vocabulary);
}

TEST_CASE("Функция 'SearchTranslation' дожна вернуть вектор с переводом")
{
	Dictionary vocabulary = {
		{"dog", {"собака"}},
		{"cat", {"кот", "кошка"}}
	};
	string word = "dog";
	Translation translation = {"собака"};
	CHECK(SearchTranslation(word, vocabulary) == translation);

	word = "cat";
	translation = {"кот", "кошка"};
    CHECK(SearchTranslation(word, vocabulary) == translation);
}

TEST_CASE("Функция 'AddWordToVocabulary' должна добавить в словарь запись")
{
	string word = "house";
	string translation = {"дом"};
	Dictionary vocabulary;
	Dictionary resultVocabulary = {
		{"house", {"дом"}}
	};
	AddWordToVocabulary(word, vocabulary, translation);
	CHECK(vocabulary == resultVocabulary);
}

TEST_CASE("В файле после функции 'Save' должно появиться содержимое словаря")
{
	Dictionary vocabulary = {
		{"dog", {"собака"}},
		{"cat", {"кот", "кошка"}}
	};
	string fileName = "output.txt";
	Save(fileName, vocabulary);
	ifstream file;
	file.open(fileName);
	string str;
	int count = 0;
	while (getline(file, str))
	{
		count += 1;
	}
	CHECK(count == vocabulary.size());
}