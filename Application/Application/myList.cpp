#include "myList.h"

myList::myList()
{
    head = new ElementOfList{ NULL, nullptr, nullptr };
}

void myList::showList()
{
    ElementOfList* copy = head->next;
    while (copy != NULL) {
        std::cout << copy->data << std::endl;
        copy = copy->next;
    }
}

void myList::pushFront(int value)
{
    if (head == NULL) return;
    if (head->next == NULL) {
        head->next = new ElementOfList{ value, NULL, head };
    }
    else {
        head->next->next = new ElementOfList{ head->next->data, head->next->next, head->next };
        head->next->data = value;
        head->next->prev = head;
    }
}

void myList::popFront()
{
    if (head->next == NULL) return;
    ElementOfList* toDelete = head->next;
    head->next = head->next->next;
    delete toDelete;
}

void myList::pushBack(int value)
{
    if (head == NULL) return;

    ElementOfList* copy = head;
    while (copy->next != NULL)
        copy = copy->next;

    ElementOfList* newElement = new ElementOfList{ value, NULL, copy };
    copy->next = newElement;
}

void myList::popBack()
{
    if (head == NULL || head->next == NULL) return;
    ElementOfList* newLast{ head };
    ElementOfList* toDelete{ head->next };

    while (toDelete->next != NULL) {
        newLast = toDelete;
        toDelete = toDelete->next;
    }

    newLast->next = NULL;
    delete toDelete;
}

void myList::push(int value, int position)
{
    ElementOfList* headCopy = head;
    for (size_t i = 0; i < position - 1; i++)
        headCopy = headCopy->next;

    ElementOfList* movedForewardElement{ headCopy->next };
    headCopy->next = new ElementOfList{ value, movedForewardElement, headCopy };
    movedForewardElement->prev = headCopy->next;
}

void myList::pop(int position)
{
    ElementOfList* headCopy = head;
    for (size_t i = 0; i < position; i++)
        headCopy = headCopy->next;

    headCopy->prev->next = headCopy->next;
    headCopy->next->prev = headCopy->prev;
}

void myList::testList()
{
    myList testList{};
    std::cout << "List created" << std::endl;

    testList.pushFront(5); std::cout << "Pushed 5 to front" << std::endl;
    testList.pushFront(10); std::cout << "Pushed 10 to front" << std::endl;
    testList.pushBack(15); std::cout << "Pushed 15 to back" << std::endl;

    std::cout << "Showing list..." << std::endl; 
    testList.showList();
}
