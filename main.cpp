#include <iostream>
#include "Book.h"
#include"Reader.h"
#include "Librarian.h"

#include "Keeper.h"
#include "Menu.h"

// check sole ID
// save after duable book
// add link - save given book, now rewhrite
// check link before del book,  reader



int main()
{
	Librarian l;
	Menu m(&l);
	Keeper k(&l);
	std::map<Book_iter, Reader_iter> givenB;
	std::map<std::string, std::string> ms = k.readGivenBookfromXML();
	std::string s;

	k.readBookFromXML();
	k.readReaderFromXML();
		
	givenB = l.restoreLinks(ms);
	


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
			Book temp;
			l.addSingleBook(temp);
			if (temp.isEmpty())
					break;
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
			l.giveBook(givenB);
			k.saveGivenBookToXML(givenB);
		}
			break;
		case 7:
			l.showGivenBooks(givenB);
			break;
		case 8:
		
			break;
		case 9:
		{
			l.returnBook(givenB);
			k.saveGivenBookToXML(givenB);
		}
			break;
		case 10:
			break;
		case 11:
		{
			if (l.delBook(s))
				k.delBookFromXML(s);
		}
			break;
		default: std::cout << "Try again";
		}
	} while (choice != 0);
	return 0;
}
