#pragma once

#include <iostream>
#include <string>
#include <vector>

template<typename Value_type>
class Graph;

template<typename Value_type>
class Iterator: public std::iterator<std::input_iterator_tag, Value_type>
{

    friend class Graph<Value_type>;

private:

public:

    Iterator(Value_type* ptr);

    Value_type operator*() const;

    friend bool operator== (const Iterator& a, const Iterator& b){ return a.m_ptr == b.m_ptr; }
    friend bool operator!= (const Iterator& a, const Iterator& b){ return a.m_ptr != b.m_ptr; }

private:
    Value_type* m_ptr;
};

#include "Iterator.tpp"