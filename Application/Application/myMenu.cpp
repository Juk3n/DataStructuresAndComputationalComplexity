#include "myMenu.h"

void myMenu::menuArray()
{
	myArray myTab; //myTab moe by dynamiczna, moze byc zadeklarowana w manu_table 

	char opt;
	std::string fileName;
	int index, value;


	do {
		displayStructureMenu("--- TABLICA ---");
		opt = getche();
		std::cout << std::endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie  tablicy z pliku
			myOutput::displayOnScreen(" Podaj nazwe zbioru:");
			std::cin >> fileName;
			//myTab.loadFromFile(fileName);
			//myTab.display();
			break;

		case '2': //tutaj usuwanie elemenu z tablicy
			myOutput::displayOnScreen(" podaj index:");
			std::cin >> index;
			//myTab.deleteFromTable(index);
			//myTab.display();
			break;

		case '3': //tutaj dodawanie elemetu do tablicy
			myOutput::displayOnScreen(" podaj index:");
			std::cin >> index;
			myOutput::displayOnScreen(" podaj waertosc:");
			std::cin >> value;

			//myTab.addValue(index, value);
			//myTab.display();
			break;

		case '4': //tutaj znajdowanie elemetu w tablicy
			myOutput::displayOnScreen(" podaj waertosc:");
			std::cin >> value;
			//if (myTab.IsValueInTable(value))
				//std::cout << "poadana wartosc jest w tablicy";
			//else
				//std::cout << "poadanej wartosci NIE ma w tablicy";
			break;

		case '5':  //tutaj generowanie  tablicy
			myOutput::displayOnScreen("Podaj ilosc elementow tablicy:");
			std::cin >> value;
			//myTab.generateTable(value);
			//myTab.display();
			break;

		case '6':  //tutaj wyswietlanie tablicy
			//myTab.display();
			break;

		case '7': //tutaj nasza funkcja do eksperymentow (pomiary czasow i generowanie daneych) - nie b�dzie testowana przez prowadz�cego 
				  // mozna sobie tu dodac wlasne case'y
			break;
		}

	} while (opt != '0');
}

void myMenu::menuList()
{
}

void myMenu::menuHeap()
{
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
		option = getche();
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
