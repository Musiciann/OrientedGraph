#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename value_type>
class Graph;

template<typename value_type>
class Vertex {
    friend class Graph<value_type>;
private:

    value_type Value;
    vector<Vertex*> Neighbors;

public:

    unsigned int VertexID;

    Vertex(value_type value);

    vector<Vertex*> GetNeighbors();

    value_type GetValue();

    void SetValue(value_type NewValue);

};

#include "Vertex.tpp"