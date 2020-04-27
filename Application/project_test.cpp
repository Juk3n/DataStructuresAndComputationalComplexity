#include "catch/catch.h"

#include "myArray.h"
#include "myHeap.h"
#include "myList.h"

TEST_CASE( "SizeShouldBe10AfterRadnomGeneration", "myArray" ) {
    myArray<int> experimental;
    int expectedSize{ 10 };
    experimental.generateRandom(expectedSize);
    REQUIRE( expectedSize == experimental.getSize() );
}
    
TEST_CASE( "SizeShouldBe0AtCreation", "myArray" ) {
    myArray<int> experimental;
    int expectedSize = 0;

    REQUIRE( expectedSize == experimental.getSize() );
}

TEST_CASE( "SizeShouldBe0AfterClear", "myArray" ) {
    myArray<int> experimental;
    int expectedSize = 0;
    experimental.generateRandom(10);
    experimental.clear();
    REQUIRE( expectedSize == experimental.getSize() );
}
TEST_CASE( "ArrayShouldHave1", "myArray") {
    myArray<int> experimental;
    experimental.pushBack(1);    
    REQUIRE( "1 " == experimental.getArrayString() );
}

TEST_CASE( "ArrayShouldHave12afterPopBack", "myArray") {
    myArray<int> experimental;
    experimental.pushBack(1);
    experimental.pushBack(2);
    experimental.pushBack(3);
    experimental.popBack();
    REQUIRE( "1 2 " == experimental.getArrayString() );
}

TEST_CASE( "ArrayShouldHave25afterPopFront", "myArray") {
    myArray<int> experimental;
    experimental.pushBack(1);
    experimental.pushBack(2);
    experimental.pushBack(5);
    experimental.popFront();
    REQUIRE( "2 5 " == experimental.getArrayString() );
}

TEST_CASE( "ArrayShouldHave15afterPopAtPos1", "myArray") {
    myArray<int> experimental;
    experimental.pushBack(1);
    experimental.pushBack(2);
    experimental.pushBack(5);
    experimental.pop(1);
    REQUIRE( "1 5 " == experimental.getArrayString() );
}

TEST_CASE( "ArrayShouldHave15afterDoublePushFront", "myArray") {
    myArray<int> experimental;
    experimental.pushFront(5);
    experimental.pushFront(1);
    REQUIRE( "1 5 " == experimental.getArrayString() );
}

TEST_CASE( "ArrayShouldHave125afterPushAtPos1", "myArray") {
    myArray<int> experimental;
    experimental.pushFront(5);
    experimental.pushFront(1);
    experimental.push(2, 1);
    REQUIRE( "1 2 5 " == experimental.getArrayString() );
}


TEST_CASE( "ArrayShouldHaveEmptyAfterClear", "myArray") {
    myArray<int> experimental;
    experimental.pushFront(5);
    experimental.pushFront(1);
    experimental.push(2, 1);
    experimental.clear();
    REQUIRE( "" == experimental.getArrayString() );
}


TEST_CASE( "ListShouldHave1", "myList") {
    myList<int> experimental;
    experimental.pushBack(1);
    REQUIRE( "1 " == experimental.getListString() );
}

TEST_CASE( "ListShouldHave12afterPopBack", "myList") {
    myList<int> experimental;
    experimental.pushBack(1);
    experimental.pushBack(2);
    experimental.pushBack(3);
    experimental.popBack();
    REQUIRE( "1 2 " == experimental.getListString() );
}

TEST_CASE( "ListShouldHave25afterPopFront", "myList") {
    myList<int> experimental;
    experimental.pushBack(1);
    experimental.pushBack(2);
    experimental.pushBack(5);
    experimental.popFront();
    REQUIRE( "2 5 " == experimental.getListString() );
}

TEST_CASE( "ListShouldHave15afterPopAtPos1", "myList") {
    myList<int> experimental;
    experimental.pushBack(1);
    experimental.pushBack(2);
    experimental.pushBack(5);
    experimental.pop(1);
    REQUIRE( "1 5 " == experimental.getListString() );
}

TEST_CASE( "ListShouldHave15afterDoublePushFront", "myList") {
    myList<int> experimental;
    experimental.pushFront(5);
    experimental.pushFront(1);
    REQUIRE( "1 5 " == experimental.getListString() );
}

TEST_CASE( "ListShouldHave125afterPushAtPos1", "myList") {
    myList<int> experimental;
    experimental.pushFront(5);
    experimental.pushFront(1);
    experimental.push(2, 1);
    REQUIRE( "1 2 5 " == experimental.getListString() );
}


TEST_CASE( "ListShouldHaveEmptyAfterClear", "myList") {
    myList<int> experimental;
    experimental.pushFront(5);
    experimental.pushFront(1);
    experimental.push(2, 1);
    experimental.clear();
    REQUIRE( "" == experimental.getListString() );
}





    