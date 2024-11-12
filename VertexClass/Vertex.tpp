#include <iostream>
#include <string>
#include <vector>
#include "Vertex.hpp"

using namespace std;

template<typename Value_type>
Value_type Value;

template<typename Value_type>
vector<Vertex<Value_type>*> Neighbors;

unsigned int VertexID;

template<typename Value_type>
Vertex<Value_type>::Vertex(Value_type value){
    this->Value = value; 
}

template<typename Value_type>
vector<Vertex<Value_type>*> Vertex<Value_type>::GetNeighbors(){
    return Neighbors;
}

template<typename Value_type>
Value_type Vertex<Value_type>::GetValue(){
    return Value;
}

template<typename Value_type>
void Vertex<Value_type>::SetValue(Value_type NewValue){
    Value = NewValue;
}


