#ifndef myArray_H
#define myArray_H

#include <iostream>
#include <random> // for std::mt19937
#include <ctime> // for std::time

#include "myFile.h"
#include "myTimer.h"
#include "myOutput.h"

template<typename T>
class myArray
{
	T* pointerToArray;
    T* temporaryPointerToArray;
    int size;
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    
public:
    myArray();
    ~myArray();

    int getSize();

    void loadFromFile(std::string fileName);
    void generateRandom(int size);

    void clear();

    void showArray() {
		for (size_t i = 0; i < size; i++) {
			std::cout << *(pointerToArray + i) << " ";
		}
		std::cout << std::endl;	
	}

	std::string getArrayString() {
		std::string arr{};
		for (size_t i = 0; i < size; i++) {
			arr += std::to_string(*(pointerToArray + i)) + " ";
		}
		return arr;
	}

    bool find(T value); // zwraca prawde jesli element jest w tablicy
	int search(T value); //zwraca index elementu jesli istnieje w tablicy

    void pushBack(T value);
    void popBack();

    void pushFront(T value);
    void popFront();

    void push(T value, int position);
    void pop(int index);

    static void testArray(int size);
};

template<typename T>
myArray<T>::myArray()
{
	pointerToArray = new int[0];
	temporaryPointerToArray = pointerToArray;
	size = 0;
}

template<typename T>
myArray<T>::~myArray()
{
	delete[] pointerToArray;
}

template<typename T>
int myArray<T>::getSize()
{
	return size;
}

template<typename T>
void myArray<T>::loadFromFile(std::string fileName)
{
	myFile file{ fileName };
	int amountOfNumbersInFile{ file.readNextValue() };
	this->clear();
	pointerToArray = new T[amountOfNumbersInFile];
	
	
	for (int i = 0; i < amountOfNumbersInFile; i++) {
		this->pushBack(file.readNextValue());
	}
}

template<typename T>
void myArray<T>::generateRandom(int size)
{
	std::uniform_int_distribution<> die{ 1, 1000 };
	this->clear();
	pointerToArray = new int[size];

	for (int i = 0; i < size; i++) {
		this->pushBack(die(mersenne));
	}

}

template<typename T>
void myArray<T>::clear()
{
	delete[] pointerToArray;
	pointerToArray = NULL;
	size = 0;
}

template<typename T>
bool myArray<T>::find(T value)
{
	for (size_t i = 0; i < size; i++) {
		if (*(pointerToArray + i) == value) return true;
	}
	return false;
}

template<typename T>
void myArray<T>::pushBack(T value)
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

template<typename T>
void myArray<T>::popBack()
{
	size--;
	temporaryPointerToArray = new int[size];
	for (size_t i = 0; i < size; i++) {
		*(temporaryPointerToArray + i) = *(pointerToArray + i);
	}
	delete[] pointerToArray;
	pointerToArray = temporaryPointerToArray;
}

template<typename T>
void myArray<T>::pushFront(T value)
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

template<typename T>
void myArray<T>::popFront()
{
	size--;
	temporaryPointerToArray = new int[size];
	for (size_t i = 0; i < size; i++) {
		*(temporaryPointerToArray + i) = *(pointerToArray + i + 1);
	}
	delete[] pointerToArray;
	pointerToArray = temporaryPointerToArray;
}

template<typename T>
void myArray<T>::push(T value, int position)
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

template<typename T>
void myArray<T>::pop(int index)
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

template<typename T>
void myArray<T>::testArray(int size)
{
	myArray<int> experimental;
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

#endif myArray_H