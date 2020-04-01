#pragma once

#include <iostream>
#include <random> 
#include <ctime> 

#include "myFile.h"
#include "myTimer.h"
#include "myOutput.h"

struct ElementOfList
{
	int data;
	ElementOfList* next;
	ElementOfList* prev;
};


class myList
{
    ElementOfList* head;
    ElementOfList* tail;
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    

public:
    static void testWorking();

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

    static void testList(int size);
};
