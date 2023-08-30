#include <iostream>
#include "menu.h"
#include "Switcher.h"

int main()
{
	Menu menu;
	Switcher switcher;

	while (true) {

		clearScreen();

		thread t1(menu.displayMainMenu);

		switcher.switchMenu();

		t1.join();

	}

	return EXIT_SUCCESS;
}