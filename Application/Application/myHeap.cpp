#include "myHeap.h"

int myHeap::getLeftChildIndex(int parentIndex)
{
	return parentIndex * 2 + 1;
}

int myHeap::getRightChildIndex(int parentIndex)
{
	return parentIndex * 2 + 2;
}

int myHeap::getParentIndex(int childIndex)
{
	return static_cast<int>((childIndex - 1) / 2);
}

void myHeap::fixHeapDown(int arr[], int index, int arrayLength)
{
}

void myHeap::fixHeapUp(int arr[], int index)
{
}

bool myHeap::isHeap()
{
	for (size_t i = 0; i < size; i++)
	{

	}
	return false;
}

void myHeap::swapValues(int* first, int* second)
{
	int bufor = *first;
	*first = *second;
	*second = bufor;
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
	int jumpToNewLineIndex{};
	for (size_t i = 0; i < size; i++) {
		std::cout << *(pointerToHeap + i);
		for(int j = 0; j < jumpToNewLineIndex; j++) std::cout << " ";
		if (i == jumpToNewLineIndex) {
			std::cout << std::endl;
			jumpToNewLineIndex = 2 * i + 2;
		}
	}
	std::cout << std::endl;
}

void myHeap::add(int value)
{
	size++;
	*(pointerToHeap + size - 1) = value;
	int indexOfNewValue{ size - 1 };
	while (indexOfNewValue > 0) {
		int indexOfParent{ static_cast<int>((indexOfNewValue - 1) / 2) };
		if (*(pointerToHeap + indexOfNewValue) > * (pointerToHeap + indexOfParent)) {
			swapValues(pointerToHeap + indexOfParent, pointerToHeap + indexOfNewValue);
			swapValues(&indexOfParent, &indexOfNewValue);
		}
		else
			return;
	}
}

void myHeap::remove()
{
	size--;
	swapValues(pointerToHeap, pointerToHeap + size);
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
