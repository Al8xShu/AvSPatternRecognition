#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include "menu.h"

using namespace std;

mutex mtx;

Menu::Menu() {}

Menu::~Menu() {}

void Menu::displayMainMenu()
{
	mtx.lock();

	string menu = "\t********** AVS Pattern Recognition **********";

	for (char x : menu)
	{
		this_thread::sleep_for(chrono::milliseconds(30));
		cout << x << flush;
	}

	this_thread::sleep_for(chrono::milliseconds(50));
	cout << endl << endl << "\t\t\tMenu:" << endl << endl;

	this_thread::sleep_for(chrono::milliseconds(50));

	cout << "\t\t1. Add file to process: " << endl;
	cout << "\t\t2. Quit" << endl << endl;

	string select = "\t\tSelect command: ";

	for (char x : select)
	{
		this_thread::sleep_for(chrono::milliseconds(30));
		cout << x << flush;
	}

	mtx.unlock();
}