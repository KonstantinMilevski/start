#include <iostream>
#include "Book.h"
#include"Reader.h"
#include "Librarian.h"

#include "Keeper.h"
#include "Menu.h"



//return restoredLinks empty?





int main()
{
	Librarian l;
	Menu m(&l);
	Keeper k(&l);
	std::map<Book_iter, Reader_iter> givenB;
	std::map<std::string, std::string> mapStringId = k.readGivenBookfromXML();
	std::string s;

	k.readBookFromXML();
	k.readReaderFromXML();
		
	givenB = l.restoreLinks(mapStringId);
	
	
	
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
		{
			Reader temp;
			l.addSingleReader(temp);
			if (temp.isEmpty())
				break;
			k.saveSingleReaderToXML(temp);
		}
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
		{
			if (l.delReader(s, givenB))
				k.delReaderFromXML(s);
		}
		break;
		case 11:
		{
			if (l.delBook(s, givenB))
				k.delBookFromXML(s);
		}
			break;
		default: std::cout << "Try again";
		}
	} while (choice != 0);
	return 0;
}
