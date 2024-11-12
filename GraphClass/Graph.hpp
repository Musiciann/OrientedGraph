#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vertex.hpp"
#include "Iterator.hpp"

using namespace std;

template<typename Value_type>
class Graph {
    private:

    int VertexCounter = 0;

    vector<Vertex<Value_type>> Vertexes;

    typedef Graph<Value_type>& graph_reference;
    typedef Vertex<Value_type>& vertex_reference;
    typedef Graph<Value_type>* graph_pointer;
    typedef Vertex<Value_type>* vertex_pointer;
    typedef const Graph<Value_type>* const_graph_pointer;
    typedef const Vertex<Value_type>* const_vertex_pointer;
    typedef const Graph<Value_type>& const_graph_reference;
    typedef const Vertex<Value_type>& const_vertex_reference;
    typedef Value_type& reference_value_type;
    typedef const Value_type& const_reference_value_type;

    bool CheckGraphVertexes(const_graph_reference OtherGraph) const;

    bool CheckVertexes(const vector<Vertex<Value_type>*>&  OtherVertexes, const vector<Vertex<Value_type>*>&  Vertexes) const;

    public:

    typedef Iterator<int> iterator;
    typedef Iterator<const int> const_iterator;

    Vertex<Value_type>* begin();

    Vertex<Value_type>* end();

    Graph();

    Graph(const_graph_reference SomeGraph);

    void Clear();

    bool Empty() const;

    int VertexAmount() const;

    unsigned int EdgesAmount() const;

    unsigned int VertexDegree(const_vertex_pointer CurrentVertex) const;

    unsigned int EdgeCardinality(const Vertex<Value_type>*  BeginVertex, const Vertex<Value_type>*  EndVertex) const;

    void AddVertex(const_reference_value_type value);

    void AddOrientedEdge(Vertex<Value_type>*  BeginVertex, Vertex<Value_type>*  EndVertex);

    void DeleteVertex(Vertex<Value_type>*  CurrentVertex);

    void DeleteOrientedEdge(Vertex<Value_type>* BeginVertex, Vertex<Value_type>*  EndVertex);

    bool IsVertexExist(const Vertex<Value_type>*  CurrentVertex) const;

    bool IsOrientedEdgeExist(const Vertex<Value_type>* BeginVertex, const Vertex<Value_type>*  EndVertex) const;

    graph_reference operator = (const_graph_reference OtherGraph);

    Vertex<Value_type>* operator [](unsigned int index);

    ~Graph();

};

#include "Graph.tpp"

