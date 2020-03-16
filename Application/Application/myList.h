#pragma once

#include <iostream>

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

public:
    myList();
    ~myList();

    void showList();
    
    void pushFront(int value);
    void popFront();

    void pushBack(int value);
    void popBack();

    void push(int value, int position);
    void pop(int value);

    static void testList();
};
