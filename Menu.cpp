#include "Menu.h"

Menu::Menu(Librarian* lib)
{
	this->lib = lib;
}


unsigned int Menu::menu()
{
	
	unsigned int choice;
	std::cout << std::endl;
	std::cout << "********************************************************************\n";
	std::cout << "0. Exit\n";
	std::cout << "1. Add book\n";//+
	std::cout << "2. Add reader\n";//+
	std::cout << "3. Show books\n";//+
	std::cout << "4. Find_book\n";//+
	std::cout << "5. Show readers\n";//+
	std::cout << "6. Give a book\n";//check empty enter
	std::cout << "7. Show given books\n";
	std::cout << "8. *****Restore*******\n";//Find reader with books
	std::cout << "9. Return book from reader\n";
	std::cout << "10. Remove reader\n";
	std::cout << "11. Remove book\n";//+

	std::cout << "********************************************************************\n";

	std::cout << "\n Choose position: ";
	while (!(std::cin >> choice))
	{
		std::cin.clear();
		std::cin.ignore(UINT_MAX, '\n');
		std::cout << "Wrong. Try again. Or '0' to exit." << std::endl;
	}
	std::cin.ignore(UINT_MAX, '\n');
	return choice;
}

void Menu::start()
{
	Librarian lib;
	Menu libMenu(&lib);
	Keeper libKeeper(&lib);
	std::map<Book_vect_iter, Reader_vect_iter> givenBook;
	std::map<std::string, std::string> mapStringId = libKeeper.readGivenBookfromXML();
	std::string s;
	
	libKeeper.readBookFromXML();
	libKeeper.readReaderFromXML();

	givenBook = lib.restoreLinks(mapStringId);
	
	unsigned int choice;
	do
	{
		choice = libMenu.menu();
		switch (choice)
		{
		case 0:
			break;
		case 1:
		{
			Book temp;
			lib.addSingleBook(temp);
			if (temp.isEmpty())
				break;
			libKeeper.saveSingleBookToXML(temp);
		}
		break;
		case 2:
		{
			Reader temp;
			lib.addSingleReader(temp);
			if (temp.isEmpty())
				break;
			libKeeper.saveSingleReaderToXML(temp);
		}
		break;
		case 3:
			lib.showBooks();
			break;
		case 4:
			lib.showFoundBooks();
			break;
		case 5:
			lib.showReaders();
			break;
		case 6:
		{
			lib.giveBook(givenBook);
			libKeeper.saveGivenBookToXML(givenBook);
		}
		break;
		case 7:
			lib.showGivenBooks(givenBook);
			break;
		case 8:

			break;
		case 9:
		{
			lib.returnBook(givenBook);
			libKeeper.saveGivenBookToXML(givenBook);
		}
		break;
		case 10:
		{
			if (lib.delReader(s, givenBook))
				libKeeper.delReaderFromXML(s);
		}
		break;
		case 11:
		{
			if (lib.delBook(s, givenBook))
				libKeeper.delBookFromXML(s);
		}
		break;
		default: std::cout << "Try again";
		}
	} while (choice != 0);
}
