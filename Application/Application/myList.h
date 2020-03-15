#pragma once


/*
    Usuwanie z listy- zostanie podana wartosc, która musi zostaæ usuniêta
    Dodawanie do listy - zostanie podana wartosc i indeks gdzie trzeba dodac
    Usuwanie/Dodawanie z poczatku/konca
*/


#include <iostream>

struct ElementOfList
{
	int data;
	ElementOfList* next;
	ElementOfList* prev;
};


class myList
{
    ElementOfList* head;

public:
    myList();

    void showList();
    
    void pushFront(int value);
    void popFront();

    void pushBack(int value);
    void popBack();

    void push(int value, int position);
    void pop(int value);

    static void testList();
};
