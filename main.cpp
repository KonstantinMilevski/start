#include <iostream>
#include "Book.h"
#include"Reader.h"
#include "Librarian.h"

#include "Keeper.h"

// check sole ID

int main()
{
	Librarian l;
	
	Keeper k(&l);
	k.readBookFromXML();
	k.readReaderFromXML();
	
	//Book temp=l.createBook(std::cin);
	//l.addSingleBook(temp);
	//k.saveSingleBookToXML(temp);

	l.showReaders();
	std::string s;
	//l.delBook(s);
	//k.delBookFromXML(s);
	l.showBooks();
	//k.saveReaderToXML();
	//l.giveBook();
	//l.giveBook();
	//k.saveBookToXML();
	std::multimap<Reader_iter, Book_iter> gB;
	std::multimap<std::string, std::string> ms = k.readGivenBookfromXML();
	k.restoreLinks(ms);
	l.giveBook(gB);
	k.saveGivenBookToXML(gB);
		
	//k.readGivenBookfromXML(ms);
	
	return 0;
}
