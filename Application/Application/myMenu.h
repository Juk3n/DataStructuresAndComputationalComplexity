#pragma once

// Wykorzystano przkładowe menu ze strony:
// http://jaroslaw.mierzwa.staff.iiar.pwr.edu.pl/sdizo/menu.cpp


#include<conio.h>
#include<string>

#include "myArray.h"
#include "myHeap.h"
#include "myList.h"
#include "myTimer.h"
#include "myOutput.h"


class myMenu
{
	void menuArray();
	void menuList();
	void menuHeap();
	void displayStructureMenu(std::string info);
public:
	void displayMenu();
};