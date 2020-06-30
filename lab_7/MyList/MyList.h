#include <stdexcept>
#include "utility"

#include <iostream>
template <typename T>
class MyList
{
    class Node
    {
    public:
        Node(Node *prev, Node *next)
        {
            this->prev = prev;
            this->next = next;
        }
        virtual T &GetData()
        {
            throw std::runtime_error("Невозможно извлечь данные! :(");
        }
        virtual ~Node() = default;
        Node *prev, *next;
    };

    class NodeWithData : public Node
    {
    public:
        NodeWithData(const T& data, Node *prev, Node *next)
            : Node(prev, next)
        {
            this->data = data;
        }
        T &GetData() override
        {
            return data;
        }
        T data;
    };

    void ThrowEmptyList() const
    {
        if (IsEmpty())
        {
            throw  std::runtime_error("Нельзя взять элемент из пустого списка!");
        }
    }

public:
    MyList()
    {
        this->m_size = 0;
        this->m_first = new Node(nullptr, nullptr);
        this->m_last = new Node(m_first, nullptr);
        this->m_first->next = this->m_last;
    }

    MyList(const MyList &list)
    {
        MyList tmp;
        for (const auto & item : list)
        {
            tmp.PushBack(item);
        }
        *this = std::move(tmp);
    }
    MyList(MyList &&list) noexcept
    {
        this->m_first = list.m_first;
        this->m_last = list.m_last;
        this->m_size = list.m_size;

        list.m_size = 0;
        list.m_first = new Node(nullptr, nullptr);
        list.m_last = new Node(m_first, nullptr);
        list.m_first->next = list.m_last;
    }
    ~MyList() noexcept
    {
        Clear();
        delete m_last;
        delete m_first;
    }
    void Clear()
    {
        while (!IsEmpty())
        {
            auto iterator = begin();
            Delete(iterator);
        }
    }
    [[nodiscard]] bool IsEmpty() const
    {
        return m_size == 0;
    }
    [[nodiscard]] size_t GetSize() const
    {
        return m_size;
    }
    MyList & operator=(const MyList & list)
    {
        if (this != &list)
        {
            MyList tmp(list);
            std::swap(*this, tmp);
        }
        return *this;
    }
    MyList & operator=(MyList && list) noexcept
    {
        if (this != &list)
        {
            Clear();
            m_first = list.m_first;
            m_last = list.m_last;
            m_size = list.m_size;

            list.m_size = 0;
            list.m_first = new Node(nullptr, nullptr);
            list.m_last = new Node(m_first, nullptr);
            list.m_first->next = m_last;
        }
        return *this;
    }

    class Iterator
    {
    public:
        Iterator() = delete;

        T & operator*() const
        {
            return m_node->GetData();
        }

        Iterator & operator++()
        {
            if ((m_isReverse && this->m_node->prev == nullptr) || (!m_isReverse && this->m_node->next == nullptr))
            {
                throw std::runtime_error("Нельзя увеличить end() оператор!");
            }
            this->m_node = m_isReverse ? m_node->prev : m_node->next;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        Iterator & operator--()
        {
            if ((m_isReverse && this->m_node->next == nullptr) || (!m_isReverse && this->m_node->prev == nullptr))
            {
                throw std::runtime_error("Нельзя уменьшить end() оператор!");
            }
            this->m_node = m_isReverse ? m_node->next : m_node->prev;
            return *this;
        }
        Iterator operator--(int)
        {
            Iterator tmp(*this);
            --(*this);
            return tmp;
        }

        bool operator==(const Iterator& other) const
        {
            return m_node == other.m_node;
        }
        bool operator!=(const Iterator& other) const
        {
            return m_node != other.m_node;
        }
    private:

        friend MyList;

        explicit Iterator(Node *node, bool isReverse = false)
        {
            this->m_node = node;
            this->m_isReverse = isReverse;
        }

        Node *m_node;
        bool m_isReverse;
    };

    Iterator begin() const
    {
        return Iterator(m_first->next);
    }

    Iterator end() const
    {
        return Iterator(m_last);
    }

    const Iterator cbegin() const
    {
        return Iterator(m_first->next);
    }

    const Iterator cend() const
    {
        return Iterator(m_last);
    }

    Iterator rbegin() const
    {
        return Iterator(m_last->prev, true);
    }

    Iterator rend() const
    {
        return Iterator(m_first, true);
    }

    const Iterator crbegin() const
    {
        return Iterator(m_last->prev, true);
    }

    const Iterator crend() const
    {
        return Iterator(m_first, true);
    }

    void PushBack(const T &data)
    {
        Insert(end(), data);
    }
    void PushFront(const T &data)
    {
        Insert(begin(), data);
    }

    T & GetBackElement()
    {
        ThrowEmptyList();
        return m_last->prev->GetData();
    }
    T const & GetBackElement() const
    {
        ThrowEmptyList();
        return m_last->prev->GetData();
    }
    T & GetFrontElement()
    {
        ThrowEmptyList();
        return m_first->next->GetData();
    }
    T const& GetFrontElement() const
    {
        ThrowEmptyList();
        return m_first->next->GetData();
    }

    void Insert(const Iterator& iterator, const T& data)
    {
        auto newNode = new NodeWithData(data, iterator.m_node->prev, iterator.m_node->prev->next);
        iterator.m_node->prev->next = newNode;
        iterator.m_node->prev = newNode;
        m_size++;
    }

    void Delete(const Iterator& iterator)
    {
        if (iterator == rend() || iterator == end())
        {
            throw std::runtime_error("Нельзя удалить этот элемент!");
        }
        iterator.m_node->prev->next = iterator.m_node->next;
        iterator.m_node->next->prev = iterator.m_node->prev;
        delete iterator.m_node;
        --m_size;
    }

private:
    size_t m_size{};
    Node *m_first, *m_last;
};