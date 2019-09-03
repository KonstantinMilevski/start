#include <iostream>
#include "Book.h"
#include"Reader.h"
#include "Librarian.h"

#include "Keeper.h"
#include "Menu.h"

// check sole ID

int main()
{
	Librarian l;
	Menu m;
	Keeper k(&l);
	std::multimap<Reader_iter, Book_iter> gB;
	std::multimap<std::string, std::string> ms = k.readGivenBookfromXML();
	std::string s;

	k.readBookFromXML();
	k.readReaderFromXML();
	
	//Book temp=l.createBook(std::cin);
	//l.addSingleBook(temp);
	//k.saveSingleBookToXML(temp);
		
	//l.delBook(s);
	//k.delBookFromXML(s);

	//k.saveReaderToXML();
	//l.giveBook();
	//l.giveBook();
	//k.saveBookToXML();
	
	//k.restoreLinks(ms);
	//l.giveBook(gB);
	//k.saveGivenBookToXML(gB);
			
	unsigned int choice;
	do
	{
		choice = m.menu();
		switch (choice)
		{
		case 0:
			break;
		case 1: 
		{
			Book temp = l.createBook(std::cin);
			l.addSingleBook(temp);
			k.saveSingleBookToXML(temp);
		}
			break; 
		case 2:
		
			break;
		case 3:
			l.showBooks();
			break;
		case 4:
			l.showFoundBooks();
			break;
		case 5: 
			l.showReaders();
			break;
		case 6:
		{
			l.giveBook(gB);
			k.saveGivenBookToXML(gB);
		}
			break;
		case 7:
			l.showGivenBooks(gB);
			break;
		case 8:
			
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
		{
			l.delBook(s);
			k.delBookFromXML(s);
		}
			break;
		default: std::cout << "Try again";
		}
	} while (choice != 0);
	return 0;
}
