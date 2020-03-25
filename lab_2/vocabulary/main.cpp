#include "vocabulary.h"


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
