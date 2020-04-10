#include "StructureTest.h"

void StructureTest::runAllTests()
{

}

void StructureTest::testMyArray()
{
    myArray experimental;

    int expectedSize{ 10 };
    experimental.generateRandom(expectedSize);

    std::cout << "SizeTest ";
    if (expectedSize == experimental.getSize()) std::cout << "passed" << std::endl;
    else std::cout << "failed" << std::endl;


    experimental.clear();
    expectedSize = 0;

    std::cout << "ClearTest ";
    if (expectedSize == experimental.getSize()) std::cout << "passed" << std::endl;
    else std::cout << "failed" << std::endl;


}

void StructureTest::testMyList()
{
    myList experimental{};
    experimental.pushFront(7);
    experimental.showList();

    experimental.pushBack(10);
    experimental.showList();

    experimental.pushFront(15);
    experimental.showList();

    experimental.push(20, 3);
    experimental.showList();

    experimental.popFront();
    experimental.showList();

    experimental.popBack();
    experimental.showList();
}

void StructureTest::testMyHeap()
{
    myHeap experimental{};
    experimental.add(7);
    experimental.showHeap();

    experimental.add(10);
    experimental.showHeap();

    experimental.add(15);
    experimental.showHeap();

    experimental.add(20);
    experimental.showHeap();

    experimental.add(9);
    experimental.showHeap();

    experimental.remove(20);
    experimental.showHeap();
}
