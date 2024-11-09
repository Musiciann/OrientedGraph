#include <iostream>
#include <string>
#include <vector>
#include "Vertex.hpp"

using namespace std;

template<typename value_type>
value_type Value;

template<typename value_type>
vector<Vertex<value_type>*> Neighbors;

unsigned int VertexID;

template<typename value_type>
Vertex<value_type>::Vertex(value_type value){
    this->value = value; 
}

template<typename value_type>
vector<Vertex<value_type>*> Vertex<value_type>::GetNeighbors(){
    return Neighbors;
}

template<typename value_type>
value_type Vertex<value_type>::GetValue(){
    return Value;
}

template<typename value_type>
void Vertex<value_type>::SetValue(value_type NewValue){
    Value = NewValue;
}
