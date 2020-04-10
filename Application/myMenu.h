#ifndef myMenu_H
#define myMenu_H

// Wykorzystano przkładowe menu ze strony:
// http://jaroslaw.mierzwa.staff.iiar.pwr.edu.pl/sdizo/menu.cpp

#include <cstdio>
#include <string>

#include "myArray.h"
#include "myHeap.h"
#include "myList.h"
#include "myTimer.h"
#include "myOutput.h"


class myMenu
{
	void menuProject1();
	void menuProject2();
	
	void menuArray();
	void menuList();
	void menuHeap();
	void displayStructureMenu(std::string info);
public:
	void displayMenu();
};

#endif myMenu_H