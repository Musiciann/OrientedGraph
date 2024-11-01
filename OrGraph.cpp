#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
class Graph {
    private:

    int VertexCounter = 0;

    class Vertex {
        private:

            T value;

            vector<Vertex*> Neighbours;
            unsigned int VertexID;

        public:

            Vertex(T value){
                this->value = value;
            }
    };

        vector<Vertex> Vertexes;

    bool CheckGraphVertexes(Graph& OtherGraph){
        for(auto SomeVertex:Vertexes){
            for(auto OtherVertex:OtherGraph->Vertexes){
                if(SomeVertex != OtherVertex) return false;
            }
        }
        return true;
    }

    bool CheckVertexes(vector<Vertex*>& OtherVertexes, vector<Vertex*>& Vertexes){
        for(auto SomeVertex: OtherVertexes){
            for(auto OtherVertex: Vertexes){
                if(OtherVertexes != Vertexes) return false;
            }
        }
        return true;
    }

    public:

    Graph(){}

    Graph(const Graph &SomeGraph){
        Vertexes = SomeGraph.Vertexes;
    }

    void Clear(){
        for(auto SomeVertex : Vertexes){
            SomeVertex.Neighbour.clear();
        }
        Vertexes.clear();
    }

    bool Empty(){
        if(Vertexes.size() == 0) return true;
        return false;
    }

    int VertexAmount(){
        return VertexCounter;
    }

    unsigned int EdgesAmount(){
        unsigned int EdgesCounter = 0;
        for(auto SomeVertex : Vertexes){
            for(auto OtherVertex : SomeVertex.Neighbours){
                if(SomeVertex == OtherVertex){
                    EdgesCounter++;
                }
            }
        }
        return EdgesCounter;
    }

    unsigned int VertexDegree(Vertex* CurrentVertex){
        return CurrentVertex->Neighbours.size();
    }

    unsigned int EdgeCardinality(Vertex* BeginVertex, Vertex* EndVertex){
        unsigned int CardinalityCounter = 0;
        for(auto SomeVertex : BeginVertex->Neighbours){
            if(SomeVertex == EndVertex){
                CardinalityCounter++;
            }
        }
        return CardinalityCounter;
    }

    void AddVertex(T value){
        Vertex NewVertex(value);
        VertexCounter++;
        NewVertex.VertexID = VertexCounter;
        Vertexes.push_back(NewVertex);
    }

    void AddOrEdge(Vertex* BeginVertex, Vertex* EndVertex){
        BeginVertex->Neighbours.push_back(EndVertex);
    }

    void DeleteVertex(Vertex* CurrentVertex){
        unsigned int Counter = 0;
        for(auto SomeVertex : Vertexes){
            if(SomeVertex == CurrentVertex){
                Vertexes.erase(Vertexes.begin() + Counter);
            }
            Counter ++;
        }
    }

    void DeleteVertexIndex(unsigned int index){
        DeleteVertex(this[index]);
    }

    void DeleteOrEdge(Vertex* BeginVertex, Vertex* EndVertex){
        unsigned int Counter = 0;
        for(auto SomeVertex : BeginVertex->Neighbours){
            if(SomeVertex == EndVertex){
                BeginVertex->Neighbours.erase(BeginVertex->Neighbours.begin() + Counter);
            }
            Counter ++;
        }
    }

    bool IsVertexExist(Vertex* CurrentVertex){
        for(auto SomeVertex : Vertexes){
            if(SomeVertex == CurrentVertex){
                return true;
            }
        }
        return false;
    }

    bool IsOrEdgeExist(Vertex* BeginVertex, Vertex* EndVertex){
        for(auto SomeVertex : BeginVertex->Neighbours){
            if(SomeVertex == EndVertex){
                return true;
            }
        }
        return false;
    }

    Graph& operator = (Graph& OtherGraph){
        Vertexes = OtherGraph.Vertexes;
        return *this;
    }

    bool operator == (Vertex* CurrentVertex){
        if(this->VertexID == CurrentVertex->VertexID) return true;
        return false;
    }

    bool operator == (Graph& CurrentGraph){
        if(CheckGraphVertexes(CurrentGraph) && CheckVertexes(this, CurrentGraph)) return true;
        return false;
    }

    bool operator != (Graph& CurrentGraph){
        if(!CheckGraphVertexes(CurrentGraph) || !CheckVertexes(this, CurrentGraph)) return true;
        return false;
    }

    Vertex* operator [](unsigned int index){
            return Vertexes[index];
    }

    ~Graph(){
        for(auto SomeVertex : Vertexes){
            SomeVertex.Neighbour.clear();
        }
        Vertexes.clear();
    }

};

int main(){



    return 0;
}