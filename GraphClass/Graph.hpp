#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vertex.hpp"
#include "Iterator.hpp"


using namespace std;

template<class value_type>
class Graph {
    private:

    int VertexCounter = 0;

    vector<Vertex> Vertexes;

    typedef Graph& graph_reference;
    typedef Vertex& vertex_reference;
    typedef Graph* graph_pointer;
    typedef Vertex* vertex_pointer;
    typedef const Graph* const_graph_pointer;
    typedef const Vertex* const_vertex_pointer;
    typedef const Graph& const_graph_reference;
    typedef const Vertex& const_vertex_reference;
    typedef value_type& reference_value_type;
    typedef const value_type& const_reference_value_type;

    Iterator begin() const;

    Iterator end() const;

    bool CheckGraphVertexes(const_graph_reference OtherGraph) const;

    bool CheckVertexes(const vector<vertex_pointer>& OtherVertexes, const vector<vertex_pointer>& Vertexes) const;

    public:

    typedef Iterator<int> iterator;
    typedef Iterator<const int> const_iterator;

    const size_t size;

    Graph();

    Graph(const_graph_reference SomeGraph);

    void Clear();

    bool Empty() const;

    int VertexAmount() const;

    unsigned int EdgesAmount() const;

    unsigned int VertexDegree(const_vertex_pointer CurrentVertex) const;

    unsigned int EdgeCardinality(const_vertex_pointer BeginVertex, const_vertex_pointer EndVertex) const;

    void AddVertex(const_reference_value_type value);

    void AddOrientedEdge(const_vertex_pointer BeginVertex, const_vertex_pointer EndVertex);

    void DeleteVertex(vertex_pointer CurrentVertex);

    void DeleteVertexIndex(unsigned int index);

    void DeleteOrientedEdge(const_vertex_pointer BeginVertex, const_vertex_pointer EndVertex);

    bool IsVertexExist(const_vertex_pointer CurrentVertex) const;

    bool IsOrientedEdgeExist(const_vertex_pointer BeginVertex, const_vertex_pointer EndVertex) const;

    graph_reference operator = (const_graph_reference OtherGraph);

    bool operator == (const_vertex_pointer CurrentVertex) const;

    bool operator == (const_graph_reference CurrentGraph) const;

    bool operator != (const_graph_reference CurrentGraph) const;

    vertex_pointer operator [](unsigned int index);

    ~Graph();

};

