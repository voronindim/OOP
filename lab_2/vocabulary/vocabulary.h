#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

typedef vector <string> Translation;
typedef map <string, Translation> Dictionary;

const  string STRING_SAVE = "...";

bool OpeningInputFileAndCreatingDictionary(const string& fileName, Dictionary &vocabulary);

void TranslationOfWords( string& vocabularyFileName, Dictionary& vocabulary);

