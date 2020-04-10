#include "myArray.h"

myArray::myArray()
{
	pointerToArray = new int[0];
	temporaryPointerToArray = pointerToArray;
	size = 0;
}

myArray::~myArray()
{
	delete[] pointerToArray;
}

int myArray::getSize()
{
	return size;
}

void myArray::loadFromFile(std::string fileName)
{
	myFile file{ fileName };
	int amountOfNumbersInFile{ file.readNextValue() };
	this->clear();
	pointerToArray = new int[amountOfNumbersInFile];
	
	
	for (int i = 0; i < amountOfNumbersInFile; i++) {
		this->pushBack(file.readNextValue());
	}
}

void myArray::generateRandom(int size)
{
	std::uniform_int_distribution<> die{ 1, 1000 };
	this->clear();
	pointerToArray = new int[size];

	for (int i = 0; i < size; i++) {
		this->pushBack(die(mersenne));
	}

}

void myArray::clear()
{
	delete[] pointerToArray;
	pointerToArray = NULL;
	size = 0;
}

void myArray::showArray() { 
	for (size_t i = 0; i < size; i++) {
		std::cout << *(pointerToArray + i) << " ";
	}
	std::cout << std::endl;
}

bool myArray::find(int value)
{
	for (size_t i = 0; i < size; i++) {
		if (*(pointerToArray + i) == value) return true;
	}
	return false;
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
	size++;
	temporaryPointerToArray = new int[size];
	int changer{};
	for (size_t i = 0; i < size; i++) {
		if (position == i) {
			*(temporaryPointerToArray + i) = value;
			changer = -1;
		}
		else {
			
			*(temporaryPointerToArray + i) = *(pointerToArray + i + changer);
		}
	}
	delete[] pointerToArray;
	pointerToArray = temporaryPointerToArray;
}

void myArray::pop(int index)
{
	//potential problem when popping more than 1 value
	size--;
	temporaryPointerToArray = new int[size];
	int changer{};
	for (size_t i = 0; i < size; i++) {
		if (index == i)
			changer++;
		
		*(temporaryPointerToArray + i) = *(pointerToArray + i + changer);
		
	}
	delete[] pointerToArray;
	pointerToArray = temporaryPointerToArray;
}

void myArray::testArray(int size)
{
	myArray experimental;
	experimental.generateRandom(size);
	myTimer timer;
	timer.start();
	experimental.pushFront(10);
	timer.stop();
	auto actionTime{ timer.getTime(TimeType::MICROSECONDS) };
	std::cout << "Dodanie na poczatek: " << actionTime << std::endl;

	timer.start();
	experimental.popFront();
	timer.stop();
	actionTime = timer.getTime(TimeType::MICROSECONDS);
	std::cout << "Usuniecie z poczatku: " << actionTime << std::endl;

	timer.start();
	experimental.pushBack(10);
	timer.stop();
	actionTime = timer.getTime(TimeType::MICROSECONDS);
	std::cout << "Dodanie na koniec: " << actionTime << std::endl;

	timer.start();
	experimental.popBack();
	timer.stop();
	actionTime = timer.getTime(TimeType::MICROSECONDS);
	std::cout << "Usuniecie z konca: " << actionTime << std::endl;

	timer.start();
	experimental.push(10, size/2);
	timer.stop();
	actionTime = timer.getTime(TimeType::MICROSECONDS);
	std::cout << "Dodanie w jakiekolwiek miejsce(wybrano srodek): " << actionTime << std::endl;

	timer.start();
	experimental.pop(size/2);
	timer.stop();
	actionTime = timer.getTime(TimeType::MICROSECONDS);
	std::cout << "Usuniecie z jakiegokolwiek miejsca(wybrano srodek): " << actionTime << std::endl;

	timer.start();
	experimental.find(500);
	timer.stop();
	actionTime = timer.getTime(TimeType::MICROSECONDS);
	std::cout << "Szukanie wartosci: " << actionTime << std::endl;
}
