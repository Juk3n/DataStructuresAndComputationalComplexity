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

void myHeap::fixHeapDown(int index)
{
	for (int i = index; i < size; i++)
	{
		int leftChildIndex{ getLeftChildIndex(i) };
		int rightChildIndex{ getRightChildIndex(i) };
		int highestValueIndex{ i };

		if (leftChildIndex < size && pointerToHeap[leftChildIndex] > pointerToHeap[highestValueIndex])
			highestValueIndex = leftChildIndex;

		if (rightChildIndex < size && pointerToHeap[rightChildIndex] > pointerToHeap[highestValueIndex])
			highestValueIndex = rightChildIndex;

		if (highestValueIndex != i) {
			swapValues(pointerToHeap + i, pointerToHeap + highestValueIndex);
		}
	}
}

void myHeap::fixHeapUp(int arr[], int index)
{
}

bool myHeap::isHeap()
{
	for (size_t i = 0; i < size; i++)
	{
		int leftChildIndex{ getLeftChildIndex(i) };
		int rightChildIndex{ getRightChildIndex(i) };
		if(leftChildIndex < size && pointerToHeap[i] < pointerToHeap[leftChildIndex])
			return false;
		if (rightChildIndex < size && pointerToHeap[i] < pointerToHeap[rightChildIndex])
			return false;
	}
	return true;
}

void myHeap::swapValues(int* first, int* second)
{
	int bufor = *first;
	*first = *second;
	*second = bufor;
}

int myHeap::find(int value)
{
	for (size_t i = 0; i < size; i++)
	{
		if (pointerToHeap[i] == value)
			return i;
	}
	return -1;
}

myHeap::myHeap()
{
	size = 0;
	pointerToHeap = new int[maxSize];
}

void myHeap::createHeap(int arr[], int arrayLength)
{
	// implenetacja podczas wczytywania z pliku
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

	for (size_t i = 0; i < size; i++) {
		std::cout << *(pointerToHeap + i) << " ";		
	}
	std::cout << std::endl << std::endl;
}

void myHeap::add(int value)
{
	size++;
	*(pointerToHeap + size - 1) = value;
	//probably fix heap up in the future
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

void myHeap::remove(int value)
{
	if (isInHeap(value)) {
		int indexOfValue{ find(value) };
		size--;
		swapValues(pointerToHeap + indexOfValue, pointerToHeap + size);
		fixHeapDown(0);
	}
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
	myHeap testHeap{};
	testHeap.add(5);
	testHeap.add(7);
	testHeap.add(6);
	testHeap.showHeap();

	testHeap.add(9);
	testHeap.add(15);
	testHeap.showHeap();

	testHeap.add(8);
	testHeap.add(30);
	testHeap.showHeap();

	testHeap.remove(8);
	testHeap.remove(9);
	testHeap.showHeap();
}
