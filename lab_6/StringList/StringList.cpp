#include "StringList.h"

StringList::StringList()
{
	this->m_size = 0;
	this->m_first = new Node(nullptr, nullptr);
	this->m_last = new Node(m_first, nullptr);
	this->m_first->next = this->m_last;
}

StringList::StringList(const StringList& list)
{
    StringList tmp;
	for (const auto & item : list)
	{
		tmp.PushBack(item);
	}
	std::swap(*this, tmp);
}
StringList::StringList(StringList&& list) noexcept
{
	this->m_first = list.m_first;
	this->m_last = list.m_last;
	this->m_size = list.m_size;

	list.m_size = 0;
	list.m_first = new Node(nullptr, nullptr);
	list.m_last = new Node(m_first, nullptr);
	list.m_first->next = list.m_last;
}

StringList::~StringList() noexcept
{
	Clear();
	delete m_last;
	delete m_first;
}

StringList& StringList::operator=(const StringList& list)
{
	if (this != &list)
	{
		StringList tmp(list);
		std::swap(*this, tmp);
	}
	return *this;
}

StringList& StringList::operator=(StringList&& list) noexcept
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

void StringList::PushBack(const std::string& string)
{
    Insert(end(), string);
}

void StringList::PushFront(const std::string& string)
{
    Insert(begin(), string);
}

size_t StringList::GetSize() const
{
	return m_size;
}

bool StringList::IsEmpty() const
{
	return m_size == 0;
}

void StringList::Clear()
{
	while (!IsEmpty())
	{
		auto iterator = begin();
		Delete(iterator);
	}
}

void StringList::Insert(const StringList::Iterator& iterator, const std::string& string)
{
	auto newNode = new NodeWithData(string, iterator.m_node->prev, iterator.m_node->prev->next);
	iterator.m_node->prev->next = newNode;
	iterator.m_node->prev = newNode;
	m_size++;
}

void StringList::Delete(const StringList::Iterator& iterator)
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

StringList::Iterator::Iterator(StringList::Node* node, bool isReverse)
{
	this->m_node = node;
	this->m_isReverse = isReverse;
}

StringList::Iterator StringList::begin() const
{
	return Iterator(m_first->next);
}

StringList::Iterator StringList::end() const
{
	return Iterator(m_last);
}

const StringList::Iterator StringList::cbegin() const
{
	return Iterator(m_first->next);
}

const StringList::Iterator StringList::cend() const
{
	return Iterator(m_last);
}

StringList::Iterator StringList::rbegin() const
{
	return Iterator(m_last->prev, true);
}

StringList::Iterator StringList::rend() const
{
	return Iterator(m_first, true);
}

const StringList::Iterator StringList::crbegin() const
{
	return Iterator(m_last->prev, true);
}

const StringList::Iterator StringList::crend() const
{
	return Iterator(m_first, true);
}

void StringList::ThrowEmptyList() const
{
	if (IsEmpty())
	{
		throw  std::runtime_error("Нельзя взять элемент из пустого списка!");
	}
}
std::string& StringList::GetBackElement()
{
	ThrowEmptyList();
	return m_last->prev->GetData();
}
std::string const& StringList::GetBackElement() const
{
	ThrowEmptyList();
	return m_last->prev->GetData();
}
std::string& StringList::GetFrontElement()
{
	ThrowEmptyList();
	return m_first->next->GetData();
}
std::string const& StringList::GetFrontElement() const
{
	ThrowEmptyList();
	return m_first->next->GetData();
}

std::string& StringList::Iterator::operator*() const
{
	return m_node->GetData();
}

StringList::Iterator& StringList::Iterator::operator++()
{
	if ((m_isReverse && this->m_node->prev == nullptr) || (!m_isReverse && this->m_node->next == nullptr))
	{
		throw std::runtime_error("Нельзя увеличить end() оператор!");
	}
	this->m_node = m_isReverse ? m_node->prev : m_node->next;
	return *this;
}

StringList::Iterator StringList::Iterator::operator++(int)
{
	Iterator tmp(*this);
	++(*this);
	return tmp;
}

StringList::Iterator& StringList::Iterator::operator--()
{
	if ((m_isReverse && this->m_node->next == nullptr) || (!m_isReverse && this->m_node->prev == nullptr))
	{
		throw std::runtime_error("Нельзя уменьшить end() оператор!");
	}
	this->m_node = m_isReverse ? m_node->next : m_node->prev;
	return *this;
}

StringList::Iterator StringList::Iterator::operator--(int)
{
	Iterator tmp(*this);
	--(*this);
	return tmp;
}

bool StringList::Iterator::operator==(const StringList::Iterator& other) const
{
	return m_node == other.m_node;
}

bool StringList::Iterator::operator!=(const StringList::Iterator& other) const
{
	return m_node != other.m_node;
}

