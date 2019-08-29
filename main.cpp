#include <iostream>
#include "Book.h"
#include"Reader.h"
#include "Librarian.h"

#include "Keeper.h"



int main()
{
	Librarian l;
	
	Keeper k(&l);
	k.readBookFromXML();
	k.readReaderFromXML();
	//l.addBookToLibrary(std::cin);
	l.showReaders();
	l.showBooks();
	//k.saveReaderToXML();
	//l.giveBook();
	//l.giveBook();
	//k.saveBookToXML();
	k.saveGivenBookToXML(l.giveBook());
	
	
}
