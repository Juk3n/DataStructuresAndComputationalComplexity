#include "myArray.h"

myArray::myArray()
{
	pointerToArray = new int[0];
	temporaryPointerToArray = pointerToArray;
	size = 0;
}

void myArray::showArray() { 
	for (size_t i = 0; i < size; i++) {
		std::cout << *(pointerToArray + i) << " ";
	}
	std::cout << std::endl;
}

void myArray::pushBack(int value)
{
	size++;
	temporaryPointerToArray = new int[size];
	for (size_t i = 0; i < size - 1; i++) {
		*(temporaryPointerToArray + i) = *(pointerToArray + i);
	}
	*(temporaryPointerToArray + size - 1) = value;
	delete[] pointerToArray;
	pointerToArray = temporaryPointerToArray;
}

void myArray::popBack()
{
	size--;
	temporaryPointerToArray = new int[size];
	for (size_t i = 0; i < size; i++) {
		*(temporaryPointerToArray + i) = *(pointerToArray + i);
	}
	delete[] pointerToArray;
	pointerToArray = temporaryPointerToArray;
}

void myArray::pushFront(int value)
{
	size++;
	temporaryPointerToArray = new int[size];
	*temporaryPointerToArray = value;
	for (size_t i = 0; i < size - 1; i++) {
		*(temporaryPointerToArray + i + 1) = *(pointerToArray + i);
	}
	delete[] pointerToArray;
	pointerToArray = temporaryPointerToArray;
}

void myArray::popFront()
{
	size--;
	temporaryPointerToArray = new int[size];
	for (size_t i = 0; i < size; i++) {
		*(temporaryPointerToArray + i) = *(pointerToArray + i + 1);
	}
	delete[] pointerToArray;
	pointerToArray = temporaryPointerToArray;
}

void myArray::push(int value, int position)
{
}

void myArray::pop(int value)
{
}

void myArray::testArray()
{
	myArray testArray{};
	std::cout << "List created" << std::endl;

	testArray.pushFront(5); std::cout << "Pushed 5 to front" << std::endl;
	testArray.pushFront(10); std::cout << "Pushed 10 to front" << std::endl;
	testArray.pushBack(15); std::cout << "Pushed 15 to back" << std::endl;

	std::cout << "Showing array..." << std::endl;
	testArray.showArray();

	testArray.push(17, 1); std::cout << "Pushed 17 to position 1" << std::endl;

	std::cout << "Showing array..." << std::endl;
	testArray.showArray();

	testArray.pop(15); std::cout << "Popped 15 from list";

	std::cout << "Showing array..." << std::endl;
	testArray.showArray();

	testArray.pushBack(20); std::cout << "Pushed 20 to back" << std::endl;
	testArray.pushBack(1); std::cout << "Pushed 1 to back" << std::endl;

	std::cout << "Showing array..." << std::endl;
	testArray.showArray();
}
