#include <iostream>
#include "switcher.h"
#include "commands.h"

using namespace std;

Switcher::Switcher() {}

Switcher::~Switcher() {};

void Switcher::switchMenu()
{
	cin >> command;
	cout << endl;

	cin.clear();
	while (cin.get() != '\n')
	{
		continue;
	}

	switch (command)
	{
	case 1:
		cmd.addFilePath();
		break;
	case 2:
		cout << "Exit is complete, good by!" << endl << endl;
		exit(0);
		break;
	default:
		clearScreen();
		cout << endl << "Insert Command was not right, please try again! " << endl;
		cout << endl << "To return in main menu, press Enter! ";
		cin.get();
		break;
	}
}