#pragma once

#include "myArray.h"
#include "myHeap.h"
#include "myList.h"

#include <functional>
#include <typeinfo>

class StructureTest
{

public:
	static void runAllTests();

	static void testMyArray();

	static void testMyList();

	static void testMyHeap();
};


