#include <utility>
#include <string>

class CMyString
{
public:
    CMyString();
    CMyString(const char * pString);
    CMyString(const char * pString, size_t length);
    CMyString(CMyString const& other);
    CMyString(CMyString && other) noexcept;
    CMyString(std::string const& stlString);
    ~CMyString();

    [[nodiscard]] size_t GetLength() const;
    [[nodiscard]] const char* GetStringDate() const;
    [[nodiscard]] CMyString SubString(size_t start, size_t length = SIZE_MAX) const;

    void Clear();

    CMyString &operator=(const CMyString &other);
    CMyString &operator=(CMyString && other) noexcept;
    CMyString &operator+=(const CMyString &other);

    const char &operator[](size_t index) const;
    char &operator[](size_t index);

private:
    char* m_pString;
    size_t m_length;
};

CMyString operator+(const CMyString &str, const CMyString & str1);
bool operator==(CMyString &str, CMyString &str1);
bool operator!=(CMyString &str, CMyString &str1);
bool operator<(CMyString &str, CMyString &str1);
bool operator<=(CMyString &str, CMyString &str1);
bool operator>=(CMyString &str, CMyString &str1);
bool operator>(CMyString &str, CMyString &str1);

std::ostream &operator<<(std::ostream &ostream, const CMyString &str);
std::istream &operator>>(std::istream &istream, CMyString &str);

