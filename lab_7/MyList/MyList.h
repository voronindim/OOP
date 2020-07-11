#include <memory>
#include <stdexcept>

template <typename T>
class MyList
{
    class Node
    {
    public:
        Node(Node* prev, std::unique_ptr<Node>&& next)
        {
            this->prev = prev;
            this->next = std::move(next);
        }
        virtual T &GetData()
        {
            throw std::runtime_error("Невозможно извлечь данные! :(");
        }

        virtual ~Node() = default;
        Node* prev;
        std::unique_ptr<Node> next;
    };

    class NodeWithData : public Node
    {
    public:
        NodeWithData(T const& data, Node* prev, std::unique_ptr<Node>&& next)
            : Node(prev, std::move(next))
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
            throw std::runtime_error("Нельзя взять элемент из пустого списка!");
        }
    }

    template <bool IsConst>
    class Iterator
    {
        friend MyList;

        explicit Iterator(Node* node)
        {
            this->m_node = node;
        }

    public:
        using MyType = Iterator<IsConst>;
        using value_type = std::conditional_t<IsConst, const T, T>;
        using reference = value_type&;
        using pointer = value_type*;
        using difference_type = ptrdiff_t;
        using iterator_category = std::random_access_iterator_tag;

        Iterator() = default;

        reference& operator*() const
        {
            return m_node->GetData();
        }

        MyType& operator++()
        {
            if (m_node == nullptr || m_node->next == nullptr)
            {
                throw std::runtime_error("Нельзя увеличить end() итератор!");
            }
            m_node = m_node->next.get();
            return *this;
        }

        MyType operator++(int) 
        {
            MyType tmp(*this);
            ++(*this);
            return tmp;
        }

        MyType& operator--()
        {
            if (m_node == nullptr || m_node->prev == nullptr)
            {
                throw std::runtime_error("Нельзя уменьшить begin() итератор!");
            }
            m_node = m_node->prev;
            return *this;
        }

        MyType operator--(int)
        {
            MyType tmp(*this);
            --(*this);
            return tmp;
        }

        bool operator==(const MyType& other) const
        {
            return m_node == other.m_node;
        }

        bool operator!=(const MyType& other) const
        {
            return m_node != other.m_node;
        }

    private:
        Node* m_node = nullptr;
    };

public:
    MyList()
    {
        auto lastNode = std::make_unique<Node>(nullptr, nullptr);
        Node* pLastNode = lastNode.get();

        m_first = std::make_unique<Node>(nullptr, std::move(lastNode));
        m_last = pLastNode;
        m_last->prev = m_first.get();
        m_size = 0;
    }

    MyList(const MyList &list)
    {
        MyList tmp;
        for (const auto &item : list)
        {
            tmp.PushBack(item);
        }
        std::swap(*this, tmp);
    }
    MyList(MyList &&list)
    {
        m_first = std::move(list.m_first);
        m_last = list.m_last;
        m_size = list.m_size;

        MyList tmp;
        list.m_first = std::move(tmp.m_first);
        list.m_last = tmp.m_last;
        list.m_size = tmp.m_size;
    }

    ~MyList()
    {
        Clear();
    }

    void Clear()
    {
        while (!IsEmpty())
        {
            Delete(begin());
        }
    }

    [[nodiscard]] bool IsEmpty() const noexcept
    {
        return m_size == 0;
    }

    [[nodiscard]] size_t GetSize() const noexcept
    {
        return m_size;
    }

    MyList & operator=(const MyList &list)
    {
        if (this != &list)
        {
            MyList tmp(list);
            std::swap(*this, tmp);
        }
        return *this;
    }

    MyList & operator=(MyList &&list)
    {
        if (this != &list)
        {
            Clear();

            m_first = std::move(list.m_first);
            m_last = list.m_last;
            m_size = list.m_size;

            MyList tmp;
            list.m_first = std::move(tmp.m_first);
            list.m_last = tmp.m_last;
            list.m_size = tmp.m_size;
        }
        return *this;
    }

    using iterator = Iterator<false>;
    using const_iterator = Iterator<true>;

    iterator begin()
    {
        return iterator(m_first->next.get());
    }

    iterator end()
    {
        return iterator(m_last);
    }

    const_iterator begin() const
    {
        return const_iterator(m_first->next.get());
    }

    const_iterator end() const
    {
        return const_iterator(m_last);
    }

    const_iterator cbegin() const
    {
        return const_iterator(m_first->next.get());
    }

    const_iterator cend() const
    {
        return const_iterator(m_last);
    }

    std::reverse_iterator<iterator> rbegin()
    {
        return std::reverse_iterator<iterator>(end());
    }

    std::reverse_iterator<iterator> rend()
    {
        return std::reverse_iterator<iterator>(begin());
    }

    std::reverse_iterator<const_iterator> rbegin() const
    {
        return std::reverse_iterator<const_iterator>(end());
    }

    std::reverse_iterator<const_iterator> rend() const
    {
        return std::reverse_iterator<const_iterator>(begin());
    }

    std::reverse_iterator<const_iterator> crbegin() const
    {
        return std::reverse_iterator<const_iterator>(cend());
    }
    
    std::reverse_iterator<const_iterator> crend() const
    {
        return std::reverse_iterator<const_iterator>(cbegin());
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

    T const& GetBackElement() const
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
    
    void Insert(const iterator& iterator, const T &data)
    {
        auto newNode = std::make_unique<NodeWithData>(data, iterator.m_node->prev, std::move(iterator.m_node->prev->next));
        newNode->next->prev = newNode.get();
        newNode->prev->next = std::move(newNode);
        ++m_size;
    }
    
    void Insert(const const_iterator& iterator, const T &data)
    {
        Insert(iterator(iterator.m_node), data);
    }

    void Delete(const iterator& iterator) noexcept
    {
        if (iterator == --begin() || iterator == end())
        {
            throw std::runtime_error("Нельзя удалить этот элемент!");
        }
        iterator.m_node->next->prev = iterator.m_node->prev;
        iterator.m_node->prev->next = std::move(iterator.m_node->next);
        --m_size;
    }

    void Delete(const const_iterator& it) noexcept
    {
        Delete(iterator(it.m_node));
    }

private:
    size_t m_size = 0;
    Node* m_last;
    std::unique_ptr<Node> m_first;
};