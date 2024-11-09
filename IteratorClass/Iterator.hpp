#pragma once

#include <iostream>
#include <string>
#include <vector>

template<typename Value_type>
class Iterator: public std::iterator<input_iterator_tag, value_type>
{
    friend class Graph;
private:
    Iterator(Value_type* p)
public:

    bool operator != (Iterator const& other) const;

    bool operator == (Iterator const& other) const;

    typename Iterator::reference operator*() const;

    Iterator& operator++();

private:
    Value_type* p;
};