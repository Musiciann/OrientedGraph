#include <iostream>
#include <string>
#include <vector>
#include "Iterator.hpp"

using namespace std;

template <typename value_type>
value_type *m_ptr;

template <typename value_type>
Iterator<value_type>::Iterator(value_type *ptr) : m_ptr(ptr){};

template<typename value_type>
value_type Iterator<value_type>::operator*() const { return *m_ptr; };
