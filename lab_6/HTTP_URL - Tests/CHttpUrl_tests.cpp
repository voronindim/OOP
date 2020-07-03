#include "../catch.hpp"
#include "../HTTP_URL/CHttpUrl.h"
#include "../HTTP_URL//CUrlParsingError.h"

TEST_CASE("Проверка конструктора принмающего строку, должен парсить строку")
{
    CHttpUrl url("https://github.com/voronindim/OOP");
    CHECK(url.GetProtocol() == Protocol::HTTPS);
    CHECK(url.GetDomain() == "github.com");
    CHECK(url.GetPort() == 443);
    CHECK(url.GetDocument() == "/voronindim/OOP");

    CHttpUrl url1("http://github.com:80");
    CHECK(url1.GetProtocol() == Protocol::HTTP);
    CHECK(url1.GetDomain() == "github.com");
    CHECK(url1.GetPort() == 80);
    CHECK(url1.GetDocument() == "/");

    CHECK_THROWS_AS(CHttpUrl(""), CUrlParsingError);
}

TEST_CASE("Проверка конструктора принмающего параметры: [domain], [document], [protocol]")
{
    CHttpUrl url("github.com", "/voronindim/OOP", Protocol::HTTPS);
    CHECK(url.GetProtocol() == Protocol::HTTPS);
    CHECK(url.GetDomain() == "github.com");
    CHECK(url.GetPort() == 443);
    CHECK(url.GetDocument() == "/voronindim/OOP");
    CHECK(url.GetURL() == "https://github.com/voronindim/OOP");
}

TEST_CASE("Првоерка конструктора принимающего парметры: [domain], [document], [protocol], [port]")
{
    CHttpUrl url("github.com", "voronindim/OOP", Protocol::HTTPS, 80);
    CHECK(url.GetProtocol() == Protocol::HTTPS);
    CHECK(url.GetDomain() == "github.com");
    CHECK(url.GetPort() == 80);
    CHECK(url.GetDocument() == "/voronindim/OOP");
    CHECK(url.GetURL() == "https://github.com:80/voronindim/OOP");

    CHECK_THROWS_AS(CHttpUrl("github.com", "voronindim/OOP", Protocol::HTTPS, 0), std::invalid_argument);
    CHECK_THROWS_AS(CHttpUrl("github.com", "voronindim/OOP", Protocol::HTTP,  0), std::invalid_argument);
    CHECK_THROWS_AS(CHttpUrl(""), std::invalid_argument);
}

TEST_CASE("Првоерка метода GetProtocolToString(), вернет строку http или https")
{
    CHttpUrl url("https://github.com/voronindim/OOP");
    CHECK(url.GetProtocolToString(Protocol::HTTPS) == "https");

    CHttpUrl url1("http://github.com/voronindim/OOP");
    CHECK(url1.GetProtocolToString(Protocol::HTTP) == "http");
}