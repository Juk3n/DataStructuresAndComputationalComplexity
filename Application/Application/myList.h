#pragma once

#include <iostream>
#include <random> 
#include <ctime> 

#include "myFile.h"

struct ElementOfList
{
	int data;
	ElementOfList* next;
	ElementOfList* prev;

    ~ElementOfList() {
        delete next;
        delete prev;
    }
};


class myList
{
    ElementOfList* head;
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

public:
    myList();
    ~myList();

    void loadFromFile(std::string fileName);
    void generateRandom(int size);

    void clear();

    void showList();
    
    int find(int value);

    void pushFront(int value);
    void popFront();

    void pushBack(int value);
    void popBack();

    void push(int value, int position);
    void pop(int index);

    static void testList();
};
