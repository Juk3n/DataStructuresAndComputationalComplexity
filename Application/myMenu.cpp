#include "myMenu.h"


void myMenu::menuProject1() {
	char option;
	do {
		std::cout << std::endl;
		std::cout << "==== MENU GLOWNE ===" << std::endl;
		std::cout << "1.Tablica" << std::endl;
		std::cout << "2.Lista" << std::endl;
		std::cout << "3.Kopiec" << std::endl;
		std::cout << "0.Wyjscie" << std::endl;
		std::cout << "Podaj opcje:";
		option = getchar();
		std::cout << std::endl;

		switch (option) {
		case '1':
			menuArray();
			break;

		case '2':
			menuList();
			break;

		case '3':
			menuHeap();
			break;
		}

	} while (option != '0');
}

void myMenu::menuProject2() {
	
}

void myMenu::menuArray()
{
	myArray userArray;

	char opt;
	std::string fileName;
	int index, value;

	do {
		displayStructureMenu("--- TABLICA ---");
		opt = getchar();
		std::cout << std::endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie  tablicy z pliku
			myOutput::displayOnScreen(" Podaj nazwe zbioru:");
			std::cin >> fileName;
			userArray.loadFromFile(fileName);
			userArray.showArray();
			break;

		case '2': //tutaj usuwanie elementu z tablicy
			myOutput::displayOnScreen(" podaj index:");
			std::cin >> index;
			userArray.pop(index);
			userArray.showArray();
			break;

		case '3': //tutaj dodawanie elemetu do tablicy
			myOutput::displayOnScreen(" podaj index:");
			std::cin >> index;
			myOutput::displayOnScreen(" podaj waertosc:");
			std::cin >> value;
			userArray.push(value, index);
			userArray.showArray();
			break;

		case '4': //tutaj znajdowanie elemetu w tablicy
			myOutput::displayOnScreen(" podaj wartosc:");
			std::cin >> value;
			if (userArray.find(value))
				myOutput::displayOnScreen("poadana wartosc jest w tablicy");
			else
				myOutput::displayOnScreen("poadanej wartosci NIE ma w tablicy");
			break;

		case '5':  // tutaj generowanie  tablicy
			myOutput::displayOnScreen("Podaj ilosc elementow tablicy:");
			std::cin >> index;
			userArray.generateRandom(index);
			userArray.showArray();
			break;

		case '6':  //tutaj wyswietlanie tablicy
			userArray.showArray();
			break;

		case '7': // eksperymenty
			std::cout << "### Array size: 1000 ###" << std::endl;
			myArray::testArray(1000);
			std::cout << std::endl;

			std::cout << "### Array size: 2000 ###" << std::endl;
			myArray::testArray(2000);
			std::cout << std::endl;

			std::cout << "### Array size: 3000 ###" << std::endl;
			myArray::testArray(3000);
			std::cout << std::endl;

			std::cout << "### Array size: 5000 ###" << std::endl;
			myArray::testArray(5000);
			std::cout << std::endl;

			std::cout << "### Array size: 8000 ###" << std::endl;
			myArray::testArray(8000);
			std::cout << std::endl;

			std::cout << "### Array size: 13000 ###" << std::endl;
			myArray::testArray(13000);
			std::cout << std::endl;

			std::cout << "### Array size: 21000 ###" << std::endl;
			myArray::testArray(21000);
			std::cout << std::endl;

			std::cout << "### Array size: 34000 ###" << std::endl;
			myArray::testArray(34000);
			std::cout << std::endl;
			

			break;
		}

	} while (opt != '0');
}

void myMenu::menuList()
{
	myList userList;

	char opt;
	std::string fileName;
	int index, value;

	do {
		displayStructureMenu("--- LISTA ---");
		opt = getchar();
		std::cout << std::endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie listy z pliku
			myOutput::displayOnScreen(" Podaj nazwe zbioru:");
			std::cin >> fileName;
			userList.loadFromFile(fileName);
			userList.showList();
			break;

		case '2': //tutaj usuwanie elementu z listy
			myOutput::displayOnScreen(" podaj index:");
			std::cin >> index;
			userList.pop(index);
			userList.showList();
			break;

		case '3': //tutaj dodawanie elemetu do listy
			myOutput::displayOnScreen(" podaj index:");
			std::cin >> index;
			myOutput::displayOnScreen(" podaj waertosc:");
			std::cin >> value;
			userList.push(value, index);
			userList.showList();
			break;

		case '4': //tutaj znajdowanie elemetu w liscie
			myOutput::displayOnScreen(" podaj wartosc:");
			std::cin >> value;
			if (userList.find(value))
				myOutput::displayOnScreen("poadana wartosc jest w tablicy");
			else
				myOutput::displayOnScreen("poadanej wartosci NIE ma w tablicy");
			break;

		case '5':  // tutaj generowanie  listy
			myOutput::displayOnScreen("Podaj ilosc elementow tablicy:");
			std::cin >> index;
			userList.generateRandom(index);
			userList.showList();
			break;

		case '6':  //tutaj wyswietlanie listy
			userList.showList();
			break;

		case '7': 
			std::cout << "### List size: 1000 ###" << std::endl;
			myList::testList(1000);
			std::cout << std::endl;

			std::cout << "### List size: 2000 ###" << std::endl;
			myList::testList(2000);
			std::cout << std::endl;

			std::cout << "### List size: 3000 ###" << std::endl;
			myList::testList(3000);
			std::cout << std::endl;

			std::cout << "### List size: 5000 ###" << std::endl;
			myList::testList(5000);
			std::cout << std::endl;

			std::cout << "### List size: 8000 ###" << std::endl;
			myList::testList(8000);
			std::cout << std::endl;

			std::cout << "### List size: 13000 ###" << std::endl;
			myList::testList(13000);
			std::cout << std::endl;

			std::cout << "### List size: 21000 ###" << std::endl;
			myList::testList(21000);
			std::cout << std::endl;

			std::cout << "### List size: 34000 ###" << std::endl;
			myList::testList(34000);
			std::cout << std::endl;
			break;
		}

	} while (opt != '0');
}

void myMenu::menuHeap()
{
	myHeap userHeap;

	char opt;
	std::string fileName;
	int index, value;

	do {
		displayStructureMenu("--- LISTA ---");
		opt = getchar();
		std::cout << std::endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie listy z pliku
			myOutput::displayOnScreen(" Podaj nazwe zbioru:");
			std::cin >> fileName;
			userHeap.loadFromFile(fileName);
			userHeap.showHeap();
			break;

		case '2': //tutaj usuwanie elementu z listy
			myOutput::displayOnScreen(" podaj wartosc:");
			std::cin >> value;
			userHeap.remove(value);
			userHeap.showHeap();
			break;

		case '3': //tutaj dodawanie elemetu do listy
			myOutput::displayOnScreen(" podaj waertosc:");
			std::cin >> value;
			userHeap.add(value);
			userHeap.showHeap();
			break;

		case '4': //tutaj znajdowanie elemetu w liscie
			myOutput::displayOnScreen(" podaj wartosc:");
			std::cin >> value;
			if (userHeap.isInHeap(value))
				myOutput::displayOnScreen("poadana wartosc jest w tablicy");
			else
				myOutput::displayOnScreen("poadanej wartosci NIE ma w tablicy");
			break;

		case '5':  // tutaj generowanie  listy
			myOutput::displayOnScreen("Podaj ilosc elementow tablicy:");
			std::cin >> index;
			userHeap.generateRandom(index);
			userHeap.showHeap();
			break;

		case '6':  //tutaj wyswietlanie listy
			userHeap.showHeap();
			break;

		case '7': 
			std::cout << "### List size: 1000 ###" << std::endl;
			myHeap::testHeap(1000);
			std::cout << std::endl;

			std::cout << "### List size: 2000 ###" << std::endl;
			myHeap::testHeap(2000);
			std::cout << std::endl;

			std::cout << "### List size: 3000 ###" << std::endl;
			myHeap::testHeap(3000);
			std::cout << std::endl;

			std::cout << "### List size: 5000 ###" << std::endl;
			myHeap::testHeap(5000);
			std::cout << std::endl;

			std::cout << "### List size: 8000 ###" << std::endl;
			myHeap::testHeap(8000);
			std::cout << std::endl;

			std::cout << "### List size: 13000 ###" << std::endl;
			myHeap::testHeap(13000);
			std::cout << std::endl;

			std::cout << "### List size: 21000 ###" << std::endl;
			myHeap::testHeap(21000);
			std::cout << std::endl;

			std::cout << "### List size: 34000 ###" << std::endl;
			myHeap::testHeap(34000);
			std::cout << std::endl;
			break;
		}

	} while (opt != '0');
}

void myMenu::displayStructureMenu(std::string info)
{
	myOutput::displayOnScreen("");
	myOutput::displayOnScreen(info);
	myOutput::displayOnScreen("1.Wczytaj z pliku");
	myOutput::displayOnScreen("2.Usun");
	myOutput::displayOnScreen("3.Dodaj");
	myOutput::displayOnScreen("4.Znajdz");
	myOutput::displayOnScreen("5.Utworz losowo");
	myOutput::displayOnScreen("6.Wyswietl");
	myOutput::displayOnScreen("7.Test (pomiary)");
	myOutput::displayOnScreen("0.Powrot do menu");
	myOutput::displayOnScreen("Podaj opcje:");
}

void myMenu::displayMenu()
{
	char option1;
	do {
		std::cout << std::endl;
		std::cout << "==== MENU GLOWNE ===" << std::endl;
		std::cout << "1.Projekt 1" << std::endl;
		std::cout << "2.Projekt 2" << std::endl;
		std::cout << "0.Wyjscie" << std::endl;
		std::cout << "Podaj opcje:";
		option1 = getchar();
		std::cout << std::endl;

		switch (option1) {
		case '1':
			menuProject1();
			break;

		case '2':
			menuProject2();
			break;
		}

	} while (option1 != '0');
}
