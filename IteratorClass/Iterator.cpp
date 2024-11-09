#include <iostream>
#include <string>
#include <vector>
#include "Iterator.hpp"

using namespace std;

        template<typename Value_type>
        Value_type* p;

        template<typename Value_type>
        Iterator<Value_type>::Iterator(Value_type* p): p(p){};

        template<typename Value_type>
        bool Iterator<Value_type>::operator != (Iterator const& other) const {
            return p != other.p;
        }

        template<typename Value_type>
        bool Iterator<Value_type>::operator == (Iterator const& other) const {
            return p == other.p;
        }

        template<typename Value_type>
        typename Iterator<Value_type>::reference Iterator<Value_type>::operator*() const {
            return *p;
        }

        template<typename Value_type>
        Iterator<Value_type>& Iterator<Value_type>::operator++(){
            ++p;
            return *this;
        }