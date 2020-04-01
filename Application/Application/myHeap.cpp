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

		int leftChildIndex{ getLeftChildIndex(index) };
		int rightChildIndex{ getRightChildIndex(index) };
		int highestValueIndex{ index };

		if (leftChildIndex < size && pointerToHeap[leftChildIndex] > pointerToHeap[highestValueIndex])
			highestValueIndex = leftChildIndex;

		if (rightChildIndex < size && pointerToHeap[rightChildIndex] > pointerToHeap[highestValueIndex])
			highestValueIndex = rightChildIndex;

		if (highestValueIndex != index) {
			swapValues(pointerToHeap + index, pointerToHeap + highestValueIndex);

			this->fixHeapDown(highestValueIndex);
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

void myHeap::testWorking()
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
		fixHeapDown(indexOfValue);
	}
}

bool myHeap::isInHeap(int value)
{
	for (size_t i = 0; i < size; i++) {
		if (*(pointerToHeap + i) == value) return true;
	}
	return false;
}

void myHeap::testHeap(int size)
{
	myHeap experimental;
	experimental.generateRandom(size);
	myTimer timer;

	timer.start();
	experimental.add(500);
	timer.stop();
	auto actionTime{ timer.getTime(TimeType::MICROSECONDS) };
	std::cout << "Dodanie wartosci: " << actionTime << std::endl;

	timer.start();
	experimental.remove(500);
	timer.stop();
	actionTime = timer.getTime(TimeType::MICROSECONDS);
	std::cout << "Usuniecie wartosci: " << actionTime << std::endl;

	timer.start();
	experimental.find(500);
	timer.stop();
	actionTime = timer.getTime(TimeType::MICROSECONDS);
	std::cout << "Szukanie wartosci: " << actionTime << std::endl;
}
