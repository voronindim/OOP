#include "catch.hpp"
#include "Decode.h"

TEST_CASE("Check the result of HtmlDecode()")
{
    std::string str = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
    std::string resultStr = "Cat <says> \"Meow\". M&M’s";
    CHECK(HtmlDecode(str) == resultStr);

    str = "Cat &&lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
    resultStr = "Cat &<says> \"Meow\". M&M’s";
    CHECK(HtmlDecode(str) == resultStr);

    str = "";
    resultStr = "";
    CHECK(HtmlDecode(str) == resultStr);

    str = "Cat &amp";
    resultStr = "Cat &amp";
    CHECK(HtmlDecode(str) == resultStr);
}
