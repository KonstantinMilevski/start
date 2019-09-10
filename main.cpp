#include <iostream>
#include "Book.h"
#include"Reader.h"
#include "Librarian.h"
#include "Menu.h"

//return restoredLinks empty?
// enter text v find
// info save links or check save

int main()
{
	Librarian lib;
	Menu libMenu(&lib);
	libMenu.start();
	
	return 0;
}
