#include <utility>
#include <string>
#include <map>

enum Protocol
{
    HTTP,
    HTTPS
};

const std::map<Protocol, unsigned short> DEFAULT_PORT
{
    {Protocol::HTTP, 80},
    {Protocol::HTTPS, 443}
};

class CHttpUrl
{
public:

    CHttpUrl(std::string const& url);

    CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol = Protocol::HTTP);

    CHttpUrl(std::string const& domain, std::string const& document, Protocol Protocol, unsigned short port);

    [[nodiscard]] std::string GetURL() const;

    [[nodiscard]] std::string GetDomain() const;

    [[nodiscard]] std::string GetDocument() const;

    [[nodiscard]] Protocol GetProtocol() const;

    [[nodiscard]] static std::string GetProtocolToString(const Protocol& protocol) ;

    [[nodiscard]] unsigned short GetPort() const;

private:

    void ParseURL(std::string const& url);

    static Protocol GetProtocol(std::string const& protocol);

    static unsigned short GetPort(const std::string& port, const Protocol& protocol);

    static unsigned short GetDefaultPort(const Protocol& protocol);

    static std::string GetDocumentByUrl(const std::string& document);

    std::string m_domain;

    std::string m_document;

    Protocol m_protocol;

    unsigned short m_port{};

};
