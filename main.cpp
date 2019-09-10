#include <iostream>
#include "Book.h"
#include"Reader.h"
#include "Librarian.h"
#include "Menu.h"

//return restoredLinks empty?

int main()
{
	Librarian l;
	Menu m(&l);
	m.start();
	Keeper k(&l);
	
	return 0;
}
