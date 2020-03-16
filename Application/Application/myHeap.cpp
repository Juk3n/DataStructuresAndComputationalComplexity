#include "myHeap.h"

void myHeap::fixHeapDown(int arr[], int index, int arrayLength)
{
}

myHeap::myHeap()
{
	size = 0;
	pointerToHeap = new int[maxSize];
}

void myHeap::createHeap(int arr[], int arrayLength)
{
}

void myHeap::showHeap()
{
	for (size_t i = 0; i < size; i++)
		std::cout << *(pointerToHeap + i) << " ";
	std::cout << std::endl;
}

void myHeap::add(int value)
{
}

void myHeap::remove()
{
}

bool myHeap::isInHeap(int value)
{
	for (size_t i = 0; i < size; i++) {
		if (*(pointerToHeap + i) == value) return true;
	}
	return false;
}

void myHeap::testHeap()
{
}
