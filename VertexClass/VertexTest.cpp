#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "Vertex.hpp"

using namespace std;

TEST(VertexTest, GetVertexValue){
    Vertex FirstVertex(120);
    Vertex SecondVertex("Hello");

    ASSERT_EQ(FirstVertex.Vertex::GetValue(), 120);
    ASSERT_EQ(SecondVertex.Vertex::GetValue(), "Hello");
}

TEST(VertexTest, SetVertexValue){
    Vertex FirstVertex(120);
    ASSERT_EQ(FirstVertex.Vertex::GetValue(), 120);
    FirstVertex.Vertex::GetNeighbors();
    FirstVertex.Vertex::SetValue(500);
    ASSERT_EQ(FirstVertex.Vertex::GetValue(), 500);
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}