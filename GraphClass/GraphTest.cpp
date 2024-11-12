#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "Vertex.hpp"
#include "Iterator.hpp"
#include "Graph.hpp"

using namespace std;

TEST(GraphTest, NewGraph){
    Graph<int> FirstGraph;
    ASSERT_TRUE(FirstGraph.Graph<int>::Empty());
}

TEST(GraphTest, NewGraphVertex){
    Graph<int> FirstGraph;
    FirstGraph.Graph<int>::AddVertex(20);
    FirstGraph.Graph<int>::AddVertex(15);
    ASSERT_FALSE(FirstGraph.Graph<int>::Empty());
    ASSERT_EQ(FirstGraph.Graph<int>::VertexAmount(), 2);
}

TEST(GraphTest, ClearGraph){
    Graph<int> FirstGraph;
    FirstGraph.Graph<int>::AddVertex(8);
    FirstGraph.Graph<int>::AddVertex(15);
    ASSERT_FALSE(FirstGraph.Graph<int>::Empty());
    FirstGraph.Graph<int>::Clear();
    ASSERT_TRUE(FirstGraph.Graph<int>::Empty());
}

TEST(GraphTest, IndexOperator){
    Graph<int> FirstGraph;
    FirstGraph.Graph<int>::AddVertex(0);
    FirstGraph.Graph<int>::AddVertex(15);
    ASSERT_EQ(FirstGraph[0]->GetValue(), 0);
    ASSERT_EQ(FirstGraph[1]->GetValue(), 15);
}

TEST(GraphTest, IsVertexExist){
    Graph<int> FirstGraph;
    FirstGraph.Graph<int>::AddVertex(8);
    FirstGraph.Graph<int>::AddVertex(15);
    Vertex NewVertex(15);
    ASSERT_TRUE(FirstGraph[1]->GetValue() == NewVertex.GetValue());
}

TEST(GraphTest, GraphBeginEnd){
    Graph<int> FirstGraph;
    FirstGraph.Graph<int>::AddVertex(7);
    FirstGraph.Graph<int>::AddVertex(15);
    ASSERT_EQ(FirstGraph.Graph<int>::begin(), FirstGraph[0]);
    ASSERT_EQ(FirstGraph.Graph<int>::end(), FirstGraph[1]);
}

TEST(GraphTest, GraphDeleteVertex){
    Graph<string> FirstGraph;
    FirstGraph.Graph<string>::AddVertex("hi");
    FirstGraph.Graph<string>::AddVertex("good");
    ASSERT_EQ(FirstGraph.Graph<string>::VertexAmount(), 2);
    FirstGraph.Graph<string>::DeleteVertex(FirstGraph[0]);
    ASSERT_EQ(FirstGraph.Graph<string>::VertexAmount(), 1);
}

TEST(GraphTest, GraphAddOrientedEdge){
    Graph<int> FirstGraph;
    FirstGraph.Graph<int>::AddVertex(13);
    FirstGraph.Graph<int>::AddVertex(12);
    ASSERT_EQ(FirstGraph.Graph<int>::EdgesAmount(), 0);
    FirstGraph.Graph<int>::AddOrientedEdge(FirstGraph[0], FirstGraph[1]);
    ASSERT_EQ(FirstGraph.Graph<int>::EdgesAmount(), 1);
}

TEST(GraphTest, GraphVertexDegree){
    Graph<int> FirstGraph;
    FirstGraph.Graph<int>::AddVertex(10);
    FirstGraph.Graph<int>::AddVertex(3);
    FirstGraph.Graph<int>::AddVertex(2);
    FirstGraph.Graph<int>::AddOrientedEdge(FirstGraph[1], FirstGraph[0]);
    FirstGraph.Graph<int>::AddOrientedEdge(FirstGraph[1], FirstGraph[2]);
    ASSERT_EQ(FirstGraph.Graph<int>::VertexDegree(FirstGraph[1]), 2);
}

TEST(GraphTest, GraphEdgeCardinality){
    Graph<int> FirstGraph;
    FirstGraph.Graph<int>::AddVertex(9);
    FirstGraph.Graph<int>::AddVertex(67);
    FirstGraph.Graph<int>::AddVertex(90);
    FirstGraph.Graph<int>::AddOrientedEdge(FirstGraph[0], FirstGraph[1]);
    FirstGraph.Graph<int>::AddOrientedEdge(FirstGraph[0], FirstGraph[1]);
    FirstGraph.Graph<int>::AddOrientedEdge(FirstGraph[1], FirstGraph[0]);
    ASSERT_EQ(FirstGraph.Graph<int>::EdgeCardinality(FirstGraph[0], FirstGraph[1]), 2);
}

TEST(GraphTest, GraphDeleteEdge){
    Graph<int> FirstGraph;
    FirstGraph.Graph<int>::AddVertex(67);
    FirstGraph.Graph<int>::AddVertex(45);
    FirstGraph.Graph<int>::AddVertex(7);
    FirstGraph.Graph<int>::AddOrientedEdge(FirstGraph[0], FirstGraph[1]);
    FirstGraph.Graph<int>::AddOrientedEdge(FirstGraph[0], FirstGraph[1]);
    FirstGraph.Graph<int>::AddOrientedEdge(FirstGraph[1], FirstGraph[0]);
    ASSERT_EQ(FirstGraph.Graph<int>::EdgesAmount(), 3);
    FirstGraph.Graph<int>::DeleteOrientedEdge(FirstGraph[1], FirstGraph[0]);
    ASSERT_EQ(FirstGraph.Graph<int>::EdgesAmount(), 2);
}

TEST(GraphTest, IsOrientedEdgeExist){
    Graph<double> FirstGraph;
    FirstGraph.Graph<double>::AddVertex(13.2);
    FirstGraph.Graph<double>::AddVertex(56.87);
    FirstGraph.Graph<double>::AddVertex(-87.5E+5);
    FirstGraph.Graph<double>::AddOrientedEdge(FirstGraph[0], FirstGraph[1]);
    FirstGraph.Graph<double>::AddOrientedEdge(FirstGraph[0], FirstGraph[1]);
    FirstGraph.Graph<double>::AddOrientedEdge(FirstGraph[1], FirstGraph[0]);
    ASSERT_TRUE(FirstGraph.Graph<double>::IsOrientedEdgeExist(FirstGraph[1], FirstGraph[0]));
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}