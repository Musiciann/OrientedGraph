#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename value_type>
class Vertex {
    friend class Graph;
private:

    value_type Value;
    vector<Vertex*> Neighbors;
    unsigned int VertexID;

public:

    Vertex(value_type value);

    vector<Vertex*> GetNeighbors();

    value_type GetValue();

    void SetValue(value_type NewValue);
};