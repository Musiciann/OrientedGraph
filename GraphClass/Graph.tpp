#include <iostream>
#include <string>
#include <vector>
#include "Vertex.hpp"
#include "Iterator.hpp"
#include "Graph.hpp"

using namespace std;

    int VertexCounter = 0;

    template<typename value_type>
    vector<Vertex<value_type>> Vertexes;

    template<typename value_type>
    Vertex<value_type>* Graph<value_type>::begin() {
        return &Vertexes[0];
    }
    
    template<typename value_type>
    Vertex<value_type>* Graph<value_type>::end() {
        return &Vertexes[Vertexes.size() - 1];
    }

    template<typename value_type>
    bool Graph<value_type>::CheckGraphVertexes(const Graph& OtherGraph) const{
        for(auto SomeVertex:Vertexes){
            for(auto OtherVertex:OtherGraph.Vertexes){
                if(SomeVertex.VertexID != OtherVertex.VertexID) return false;
            }
        }
        return true;
    }

    template<typename value_type>
    bool Graph<value_type>::CheckVertexes(const vector<Vertex<value_type>*>& OtherVertexes, const vector<Vertex<value_type>*>& Vertexes) const{
        for(auto SomeVertex: OtherVertexes){
            for(auto OtherVertex: Vertexes){
                if(OtherVertexes != Vertexes) return false;
            }
        }
        return true;
    }

    template<typename value_type>
    Graph<value_type>::Graph(){}

    template<typename value_type>
    Graph<value_type>::Graph(const Graph& SomeGraph){
        Vertexes = SomeGraph.Vertexes;
    }

    template<typename value_type>
    void Graph<value_type>::Clear(){
        for(auto SomeVertex : Vertexes){
            SomeVertex.Neighbors.clear();
        }
        Vertexes.clear();
    }

    template<typename value_type>
    bool Graph<value_type>::Empty() const{
        if(Vertexes.size() == 0) return true;
        return false;
    }

    template<typename value_type>
    int Graph<value_type>::VertexAmount() const{
        return Vertexes.size();
    }

    template<typename value_type>
    unsigned int Graph<value_type>::EdgesAmount() const{
        unsigned int EdgesCounter = 0;
        for(auto SomeVertex : Vertexes){
            for(auto OtherVertex : SomeVertex.Neighbors){
                    EdgesCounter++;
            }
        }
        return EdgesCounter;
    }

    template<typename value_type>
    unsigned int Graph<value_type>::VertexDegree(const_vertex_pointer CurrentVertex) const{
        return CurrentVertex->Neighbors.size();
    }

    template<typename value_type>
    unsigned int Graph<value_type>::EdgeCardinality(const Vertex<value_type>* BeginVertex, const Vertex<value_type>* EndVertex) const{
        unsigned int CardinalityCounter = 0;
        for(auto SomeVertex : BeginVertex->Neighbors){
            if(SomeVertex == EndVertex){
                CardinalityCounter++;
            }
        }
        return CardinalityCounter;
    }

    template<typename value_type>
    void Graph<value_type>::AddVertex(const value_type& value){
        Vertex NewVertex(value);
        VertexCounter++;
        NewVertex.VertexID = VertexCounter;
        Vertexes.push_back(NewVertex);
    }

    template<typename value_type>
    void Graph<value_type>::AddOrientedEdge(Vertex<value_type>* BeginVertex, Vertex<value_type>* EndVertex){
        BeginVertex->Neighbors.push_back(EndVertex);
    }

    template<typename value_type>
    void Graph<value_type>::DeleteVertex(Vertex<value_type>* CurrentVertex){
        unsigned int Counter = 0;
        for(auto SomeVertex : Vertexes){
            if(SomeVertex.VertexID == CurrentVertex->VertexID && SomeVertex.GetValue() == CurrentVertex->GetValue()){
                Vertexes.erase(Vertexes.begin() + Counter);
            }
            Counter ++;
        }
    }

    template<typename value_type>
    void Graph<value_type>::DeleteOrientedEdge(Vertex<value_type>* BeginVertex, Vertex<value_type>* EndVertex){
        unsigned int Counter = 0;
        for(auto SomeVertex : BeginVertex->Neighbors){
            if(SomeVertex == EndVertex){
                BeginVertex->Neighbors.erase(BeginVertex->Neighbors.begin() + Counter);
            }
            Counter ++;
        }
    }

    template<typename value_type>
    bool Graph<value_type>::IsVertexExist(const Vertex<value_type>* CurrentVertex) const{
        for(auto SomeVertex : Vertexes){
            if(SomeVertex == CurrentVertex){
                return true;
            }
        }
        return false;
    }

    template<typename value_type>
    bool Graph<value_type>::IsOrientedEdgeExist(const Vertex<value_type>* BeginVertex, const Vertex<value_type>* EndVertex) const{
        for(auto SomeVertex : BeginVertex->Neighbors){
            if(SomeVertex == EndVertex){
                return true;
            }
        }
        return false;
    }

    template<typename value_type>
    Graph<value_type>& Graph<value_type>::operator = (const Graph<value_type>& OtherGraph){
        Vertexes = OtherGraph.Vertexes;
        return *this;
    }

    template<typename value_type>
    Vertex<value_type>* Graph<value_type>::operator [](unsigned int index){
            return &Vertexes[index];
    }

    template<typename value_type>
    Graph<value_type>::~Graph(){
        for(auto SomeVertex : Vertexes){
            SomeVertex.Neighbors.clear();
        }
        Vertexes.clear();
    }
