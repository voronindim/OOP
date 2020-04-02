#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

typedef vector<string> Translation;
typedef map <string, Translation> Dictionary;

bool CreatingVocabulary(const string& vocabularyFileName, Dictionary &vocabulary);

void CopyStringToVocabulary(Dictionary &vocabulary, const string& str);

void TranslationOfWords(const string &vocabularyFileName, Dictionary &vocabulary);

bool Save(const string& vocabularyFileName, const Dictionary& vocabulary);

Translation SearchTranslation(string searchWord, const Dictionary& vocabulary);

void AddWordToVocabulary(string word, Dictionary& vocabulary, const string& translation);