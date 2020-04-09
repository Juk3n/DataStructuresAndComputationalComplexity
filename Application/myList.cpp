#include "myList.h"

myList::myList()
{
    head = new ElementOfList{ NULL, nullptr, nullptr };
}

myList::~myList()
{
    head = NULL;
}

void myList::loadFromFile(std::string fileName)
{
    myFile file{ fileName };
    int amountOfNumbersInFile{ file.readNextValue() };
    this->clear();
    head = new ElementOfList{ -1, NULL, NULL };


    for (int i = 0; i < amountOfNumbersInFile; i++) {
        this->pushBack(file.readNextValue());
    }
}

void myList::generateRandom(int size)
{
    std::uniform_int_distribution<> die{ 1, 1000 };
    this->clear();
    head = new ElementOfList{ -1, NULL, NULL };

    for (int i = 0; i < size; i++) {
        this->pushBack(die(mersenne));
    }
}

void myList::clear()
{
    head = NULL;
}

void myList::showList()
{
    ElementOfList* copy = head->next;
    while (copy != NULL) {
        std::cout << copy->data << " ";
        copy = copy->next;
    }
    std::cout << std::endl;
}

int myList::find(int value)
{
    int index{ 0 };
    ElementOfList* copy = head->next;
    while (copy != NULL) {
        index++;
        if (copy->data == value) return index;
        copy = copy->next;
    }
    return -1;
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
    if (position == 0)
        this->pushFront(value);

    ElementOfList* headCopy = head;
    for (size_t i = 0; i <= position - 1; i++)
        headCopy = headCopy->next;

    ElementOfList* movedForewardElement{ headCopy->next };
    headCopy->next = new ElementOfList{ value, movedForewardElement, headCopy };
    if (movedForewardElement != NULL)
        movedForewardElement->prev = headCopy->next;
}

void myList::pop(int index)
{
    ElementOfList* headCopy = head->next;
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

void myList::testList(int size)
{
    myList experimental;
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