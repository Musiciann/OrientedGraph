#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "Iterator.hpp"

using namespace std;

TEST(IteratorTest, NotEqualIterators){
    string a = "10";
    string b = "NO";
    Iterator<string> FirstIter(&a);
    Iterator<string> SecondIter(&b);
    ASSERT_TRUE(FirstIter != SecondIter);
}

TEST(IteratorTest, EqualIterators){
    int a = 1;
    int b = 1;
    Iterator<int> FirstIter(&a);
    Iterator<int> SecondIter(&b);
    ASSERT_TRUE(*FirstIter == *SecondIter);
}

TEST(IteratorTest, GetValue){
    int a = 2;
    Iterator<int> FirstIter(&a);
    ASSERT_EQ(*FirstIter, a);
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}