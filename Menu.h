#pragma once
#include "Librarian.h"
#include "Keeper.h"

class Menu
{
public:
	Menu(Librarian* );

	unsigned int menu();
	void start();
private:
	Librarian* lib;
};

