#include "myMenu.h"

void myMenu::menuArray()
{
	myArray userArray;

	char opt;
	std::string fileName;
	int index, value;

	do {
		displayStructureMenu("--- TABLICA ---");
		opt = _getche();
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
			std::cin >> value;
			//myTab.generateTable(value);
			userArray.showArray();
			break;

		case '6':  //tutaj wyswietlanie tablicy
			userArray.showArray();
			break;

		case '7': //tutaj nasza funkcja do eksperymentow (pomiary czasow i generowanie daneych) - nie b�dzie testowana przez prowadz�cego 
				  // mozna sobie tu dodac wlasne case'y
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
		opt = _getche();
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
			std::cin >> value;
			//myTab.generateTable(value);
			userList.showList();
			break;

		case '6':  //tutaj wyswietlanie listy
			userList.showList();
			break;

		case '7': //tutaj nasza funkcja do eksperymentow (pomiary czasow i generowanie daneych) - nie b�dzie testowana przez prowadz�cego 
				  // mozna sobie tu dodac wlasne case'y
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
		opt = _getche();
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
			std::cin >> value;
			//myTab.generateTable(value);
			userHeap.showHeap();
			break;

		case '6':  //tutaj wyswietlanie listy
			userHeap.showHeap();
			break;

		case '7': //tutaj nasza funkcja do eksperymentow (pomiary czasow i generowanie daneych) - nie b�dzie testowana przez prowadz�cego 
				  // mozna sobie tu dodac wlasne case'y
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
	char option;
	do {
		std::cout << std::endl;
		std::cout << "==== MENU GLOWNE ===" << std::endl;
		std::cout << "1.Tablica" << std::endl;
		std::cout << "2.Lista" << std::endl;
		std::cout << "3.Kopiec" << std::endl;
		std::cout << "0.Wyjscie" << std::endl;
		std::cout << "Podaj opcje:";
		option = _getche();
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
