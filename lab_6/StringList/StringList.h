#include<string>
#include <utility>

class StringList
{
	class Node
	{
	public:
		Node(Node *prev, Node *next)
		{
			this->prev = prev;
			this->next = next;
		}
		virtual ~Node() = default;
		virtual std::string &GetData()
		{
			throw std::runtime_error("Невозможно извлечь данные! :(");
		}
		Node *prev, *next;
	};

	class NodeWithData : public Node
	{
	public:
		NodeWithData(const std::string &string, Node *prev, Node *next)
			: Node(prev, next)
		{
			this->m_string = string;
		}
		std::string &GetData() override
		{
			return m_string;
		}
		std::string m_string;
	};

public:
	StringList();
	StringList(const StringList& list);
	StringList(StringList&& list) noexcept;
	~StringList() noexcept;

	StringList& operator=(const StringList& list);
	StringList& operator=(StringList&& list) noexcept;

	void PushBack(const std::string &string);
	void PushFront(const std::string &string);

	[[nodiscard]] size_t GetSize() const;
	[[nodiscard]] bool IsEmpty() const;

	void Clear();

	class Iterator
	{
	public:
		Iterator() = delete;

		std::string & operator*() const;

		Iterator & operator++();
		Iterator operator++(int);

		Iterator & operator--();
		Iterator operator--(int);

		bool operator==(const Iterator& other) const;
		bool operator!=(const Iterator& other) const;
	private:

		friend StringList;

		explicit Iterator(Node *node, bool isReverse = false);

		Node *m_node;
		bool m_isReverse;
	};

	std::string& GetBackElement();
	[[nodiscard]] std::string const& GetBackElement() const;

	std::string& GetFrontElement();
	[[nodiscard]] std::string const& GetFrontElement() const;

	[[nodiscard]] Iterator begin() const;
	[[nodiscard]] Iterator end() const;

	[[nodiscard]] const Iterator cbegin() const;
	[[nodiscard]] const Iterator cend() const;

	[[nodiscard]] Iterator rbegin() const;
	[[nodiscard]] Iterator rend() const;

	[[nodiscard]] const Iterator crbegin() const;
	[[nodiscard]] const Iterator crend() const;

	void Insert(const Iterator &iterator, const std::string &string);
	void Delete(const Iterator &iterator);

private:
	size_t m_size{};
	Node *m_first{}, *m_last{};
	void ThrowEmptyList() const;
};
