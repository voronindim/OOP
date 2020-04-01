#include "catch.hpp"
#include "../vocabulary/vocabulary.h"

TEST_CASE("Перевод слова")
{
	Dictionary vocabulary;
	vocabulary = {
		"cat", "кошка"
	};
	CHECK(TranslationOfWords("cat", vocabulary) == Translation{"кошка"})
}