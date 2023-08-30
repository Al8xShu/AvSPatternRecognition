#ifndef SWITCHER_H
#define SWITCHER_H

#include "commands.h"

class Switcher
{

public:

	Switcher();
	~Switcher();

	void switchMenu();

private:

	int command;
	Commands cmd;

};

#endif // SWITCHER_H