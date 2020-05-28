#include "CHttpUrl.h"
#include <regex>
#include "CUrlParsingError.h"

CHttpUrl::CHttpUrl(const std::string &url)
{
    try
    {
        ParseURL(url);
    }
    catch (std::invalid_argument& error)
    {
        throw CUrlParsingError(error.what());
    }
}

CHttpUrl::CHttpUrl(const std::string &domain, const std::string &document, Protocol protocol)
    : CHttpUrl(domain, document, protocol, GetDefaultPort(protocol))
{
}

CHttpUrl::CHttpUrl(const std::string &domain, const std::string &document, Protocol protocol, unsigned short port)
{
    if (domain.empty())
    {
        throw std::invalid_argument("Отстутсвет Domain!");
    }
    if (port < 1 || port > 65535)
    {
        throw std::invalid_argument("Port должен находиться в отрезке [1..65535]");
    }
    this-> m_domain = domain;
    this-> m_document = GetDocumentByUrl(document);
    this-> m_protocol = protocol;
    this-> m_port = port;
}

std::string CHttpUrl::GetURL() const
{
    if (m_port != GetDefaultPort(m_protocol))
    {
        return GetProtocolToString(m_protocol) + "://" + m_domain + ":" + std::to_string(m_port) + m_document;
    }
    return GetProtocolToString(m_protocol) + "://" + m_domain + m_document;
}

std::string CHttpUrl::GetDomain() const
{
    return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
    return m_document;
}
Protocol CHttpUrl::GetProtocol() const
{
    return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
    return m_port;
}

void CHttpUrl::ParseURL(const std::string &url)
{
    std::smatch matches;
    std::regex regular("^((http[s]?)://)?([-.[:alnum:]]+)(:([[:digit:]]+))?(/(.*))?$");
    std::regex_search(url, matches, regular);

    if (matches.empty())
    {
        throw std::invalid_argument("Неверный URl");
    }

    this->m_protocol = GetProtocol(matches[2]);
    this->m_domain = matches[3];
    this->m_port = GetPort(matches[5], m_protocol);
    this->m_document = GetDocumentByUrl(matches[7]);


}

Protocol CHttpUrl::GetProtocol(const std::string &protocol)
{
    if (protocol == "https")
    {
        return Protocol::HTTPS;
    }
    return Protocol::HTTP;
}

unsigned short CHttpUrl::GetPort(const std::string &port, const Protocol &protocol)
{
    if (port.empty())
    {
        return GetDefaultPort(protocol);
    }
    int resPort = atoi(port.c_str());
    if (resPort >= 1 && resPort <= 65535)
    {
        return resPort;
    }
    throw std::invalid_argument("Несуществующий порт! Порт [1..65535]");
}

unsigned short CHttpUrl::GetDefaultPort(const Protocol &protocol)
{
    auto it = DEFAULT_PORT.find(protocol);
    if (it != DEFAULT_PORT.end())
    {
        return it->second;
    }
    throw std::runtime_error("Для данного протокола нет порта");
}

std::string CHttpUrl::GetDocumentByUrl(const std::string &document)
{
    if (document.empty() || document[0] != '/')
    {
        return '/' + document;
    }
    return document;
}

std::string CHttpUrl::GetProtocolToString(const Protocol& protocol)
{
    if (protocol == Protocol::HTTPS)
    {
        return "https";
    }
    return "http";
}





