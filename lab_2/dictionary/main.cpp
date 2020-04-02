#include "vocabulary.h"

int main(int argc, char* argv[])
{
	string vocabularyFileName;
	Dictionary vocabulary;
	if (argc == 2)
	{
		vocabularyFileName = argv[1];
		if (!CreatingVocabulary(vocabularyFileName, vocabulary))
		{
			return 1;
		}
	}
	else if (argc > 2)
	{
		cout << "Параметры командной строки: <name.exe> <file.txt>" << endl;
		return 1;
	}
	TranslationOfWords(vocabularyFileName, vocabulary);

	return 0;
}
