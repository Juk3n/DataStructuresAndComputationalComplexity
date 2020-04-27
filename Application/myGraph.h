#ifndef myGraph_H
#define myGraph_H

#include "myArray.h"
#include "myList.h"

struct Edge {
    int beginNode;
    int endNode;
    int weight;
};

class myGraph {
    int size;
    myArray<bool> QS; // false - node in Q, true - node in S
    // n elementowa tablica w ktorej kazdy element jest lista
    myArray<myList<int>> AdjacencyLists;

    bool isEmptyQ();
};

#endif myGraph_H