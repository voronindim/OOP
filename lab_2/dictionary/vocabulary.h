#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>

typedef std::vector<std::string> Translation;
typedef std::map <std::string, Translation> Dictionary;

bool CreatingVocabulary(const std::string& vocabularyFileName, Dictionary &vocabulary);

void CopyStringToVocabulary(Dictionary &vocabulary, const std::string& str);

void TranslationOfWords(const std::string &vocabularyFileName, Dictionary &vocabulary);

bool Save(const std::string& vocabularyFileName, const Dictionary& vocabulary);

Translation SearchTranslation(std::string searchWord, const Dictionary& vocabulary);

void AddWordToVocabulary(std::string word, Dictionary& vocabulary, const std::string& translation);