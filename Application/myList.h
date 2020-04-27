#ifndef myList_H
#define myList_H

#include <iostream>
#include <random> 
#include <ctime> 

#include "myFile.h"
#include "myTimer.h"
#include "myOutput.h"

template<typename T>
struct ElementOfList
{
	T data;
	ElementOfList<T>* next;
	ElementOfList<T>* prev;
};

template<typename T>
class myList
{
    ElementOfList<T>* head;
    ElementOfList<T>* tail;
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };  

public:
    myList() {
        head = new ElementOfList<T>{ NULL, nullptr, nullptr };
    }
    ~myList() {
        head = NULL;
    }

    void loadFromFile(std::string fileName) {
        myFile file{ fileName };
        int amountOfNumbersInFile{ file.readNextValue() };
        this->clear();
        head = new ElementOfList<T>{ -1, NULL, NULL };


        for (int i = 0; i < amountOfNumbersInFile; i++) {
            this->pushBack(file.readNextValue());
        }
    }

    void generateRandom(int size);

    void clear();

    void showList() {
        ElementOfList<T>* copy = head->next;
        while (copy != NULL) {
            std::cout << copy->data << " ";
            copy = copy->next;
        }
        std::cout << std::endl;
    }

    std::string getListString() {
        ElementOfList<T>* copy = head->next;
        std::string list{};
        while (copy != NULL) {
            list += std::to_string(copy->data) + " ";
            copy = copy->next;
        }
        return list;
    }
    
    int find(T value);

    void pushFront(T value);
    void popFront();

    void pushBack(T value);
    void popBack();

    void push(T value, int position);
    void pop(int index);

    static void testList(int size);
};

template<typename T>
void myList<T>::generateRandom(int size)
{
    std::uniform_int_distribution<> die{ 1, 1000 };
    this->clear();
    head = new ElementOfList<T>{ -1, NULL, NULL };

    for (int i = 0; i < size; i++) {
        this->pushBack(die(mersenne));
    }
}

template<typename T>
void myList<T>::clear()
{
    head->next = NULL;
}

template<typename T>
int myList<T>::find(T value)
{
    int index{ 0 };
    ElementOfList<T>* copy = head->next;
    while (copy != NULL) {
        index++;
        if (copy->data == value) return index;
        copy = copy->next;
    }
    return -1;
}

template<typename T>
void myList<T>::pushFront(T value)
{
    if (head == NULL) return;
    if (head->next == NULL) {
        head->next = new ElementOfList<T>{ value, NULL, head };
    }
    else {
        head->next->next = new ElementOfList<T>{ head->next->data, head->next->next, head->next };
        head->next->data = value;
        head->next->prev = head;
    }
}

template<typename T>
void myList<T>::popFront()
{
    if (head->next == NULL) return;
    ElementOfList<T>* toDelete = head->next;
    head->next = head->next->next;
    delete toDelete;
}

template<typename T>
void myList<T>::pushBack(T value)
{
    if (head == NULL) return;

    ElementOfList<T>* copy = head;
    while (copy->next != NULL)
        copy = copy->next;

    ElementOfList<T>* newElement = new ElementOfList<T>{ value, NULL, copy };
    copy->next = newElement;
}

template<typename T>
void myList<T>::popBack()
{
    if (head == NULL || head->next == NULL) return;
    ElementOfList<T>* newLast{ head };
    ElementOfList<T>* toDelete{ head->next };

    while (toDelete->next != NULL) {
        newLast = toDelete;
        toDelete = toDelete->next;
    }

    newLast->next = NULL;
    delete toDelete;
}

template<typename T>
void myList<T>::push(T value, int position)
{
    if (position == 0)
        this->pushFront(value);

    ElementOfList<T>* headCopy = head;
    for (size_t i = 0; i <= position - 1; i++)
        headCopy = headCopy->next;

    ElementOfList<T>* movedForewardElement{ headCopy->next };
    headCopy->next = new ElementOfList<T>{ value, movedForewardElement, headCopy };
    if (movedForewardElement != NULL)
        movedForewardElement->prev = headCopy->next;
}

template<typename T>
void myList<T>::pop(int index)
{
    ElementOfList<T>* headCopy = head->next;
    int i{};
    while (headCopy->next != NULL) {
        if (index == i) {
            headCopy->prev->next = headCopy->next;
            headCopy->next->prev = headCopy->prev;
            break;
        }
        headCopy = headCopy->next;
        i++;
    }
    if (index == i) {
        headCopy->prev->next = headCopy->next;
    }
}

template<typename T>
void myList<T>::testList(int size)
{
    myList<int> experimental;
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
    experimental.push(10, size / 2);
    timer.stop();
    actionTime = timer.getTime(TimeType::MICROSECONDS);
    std::cout << "Dodanie w jakiekolwiek miejsce(wybrano srodek): " << actionTime << std::endl;

    timer.start();
    experimental.pop(size / 2);
    timer.stop();
    actionTime = timer.getTime(TimeType::MICROSECONDS);
    std::cout << "Usuniecie z jakiegokolwiek miejsca(wybrano srodek): " << actionTime << std::endl;

    timer.start();
    experimental.find(500);
    timer.stop();
    actionTime = timer.getTime(TimeType::MICROSECONDS);
    std::cout << "Szukanie wartosci: " << actionTime << std::endl;
}

#endif myList_H