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

		if (!isHeap(i))
			fixHeapDown(i);
	}
}

void myHeap::fixHeapUp(int index)
{
	while (index > 0) {
		int indexOfParent{ static_cast<int>((index - 1) / 2) };
		if (*(pointerToHeap + index) > * (pointerToHeap + indexOfParent)) {
			swapValues(pointerToHeap + indexOfParent, pointerToHeap + index);
			swapValues(&indexOfParent, &index);
		}
		else
			return;
	}
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

bool myHeap::isHeap(int index)
{
	for (size_t i = 0; i < index; i++)
	{
		int leftChildIndex{ getLeftChildIndex(i) };
		int rightChildIndex{ getRightChildIndex(i) };
		if (leftChildIndex < size && pointerToHeap[i] < pointerToHeap[leftChildIndex])
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

myHeap::~myHeap()
{
	delete[] pointerToHeap;
}

void myHeap::loadFromFile(std::string fileName)
{
	myFile file{ fileName };
	int amountOfNumbersInFile{ file.readNextValue() };
	this->clear();
	
	for (int i = 0; i < amountOfNumbersInFile; i++) {
		this->add(file.readNextValue());
	}
}

void myHeap::generateRandom(int size)
{
	std::uniform_int_distribution<> die{ 1, 1000 };
	this->clear();
	

	for (int i = 0; i < size; i++) {
		this->add(die(mersenne));
	}
}

void myHeap::clear()
{
	delete[] pointerToHeap;
	pointerToHeap = new int[maxSize];
	size = 0;
}

void myHeap::showHeap()
{
	int jumpToNewLineIndex{};
	
	int maxIndexToNotChangeLines{ 1 };
	for(; size - 1 > maxIndexToNotChangeLines; maxIndexToNotChangeLines *= 2);

	int numberOfLines{};
	for (; maxIndexToNotChangeLines >= 1; maxIndexToNotChangeLines /= 2)
		numberOfLines++;

	int distanceBeetwenNumbers{ static_cast<int>(pow(2, numberOfLines)) };

	for (size_t i = 0; i < size; i++) {
		
		for (int j = 0; j < distanceBeetwenNumbers; j++) std::cout << " ";
		std::cout << *(pointerToHeap + i);
		for(int j = 0; j < distanceBeetwenNumbers; j++) std::cout << " ";
		
		
		if (i == jumpToNewLineIndex) {
			std::cout << std::endl;
			jumpToNewLineIndex = 2 * i + 2;
			distanceBeetwenNumbers /= 2;
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
	fixHeapUp(size - 1);
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
