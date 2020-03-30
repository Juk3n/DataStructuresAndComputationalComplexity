#pragma once

#include <iostream>
#include <random> 
#include <ctime> 

#include "myFile.h"

class myHeap
{
    int* pointerToHeap;
    int size;
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    const int maxSize{ 1000 };

    int getLeftChildIndex(int parentIndex);
    int getRightChildIndex(int parentIndex);
    int getParentIndex(int childIndex);
    void fixHeapDown(int index);
    void fixHeapUp(int index);
    bool isHeap(); // zwraca czy tablica spelnia warunki kopca
    bool isHeap(int index); // zwracza czy tablica spelnia lokalne warunki kopca 
    void swapValues(int* first, int* second);
    int find(int value);

public:
    myHeap();
    ~myHeap();

    void loadFromFile(std::string fileName);
    void generateRandom(int size);

    void clear();

    void showHeap();

    void add(int value);
    void remove(int value);

    bool isInHeap(int value);

    static void testHeap();
};

