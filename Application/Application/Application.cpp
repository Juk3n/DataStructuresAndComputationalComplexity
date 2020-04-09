// Application.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

#include "myMenu.h"
#include "StructureTest.h"

int main()
{
    StructureTest::runAllTests();
    //myMenu menu{};
    //menu.displayMenu();
    return 0;
}

