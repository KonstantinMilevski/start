#include <iostream>
#include "Book.h"
#include"Reader.h"
#include "Librarian.h"


int main()
{
	Librarian l;
	

	std::ifstream fread_books("books.txt" /*std::fstream::ate*/);
	if (!fread_books)
		std::cout << "error opening file books.txt \nBooks not added to library." << std::endl;
	else
	{
		l.addItemFromFile<Book>(fread_books);
		std::cout << "Books added to library." << std::endl;
		fread_books.close();
	}
	l.showBooks();
	std::ifstream fread_readers("readers.txt"/*, std::fstream::ate*/);
	if (!fread_readers)
		std::cout << "error opening file readers.txt \nReaders not added to library." << std::endl;
	else
	{
		l.addItemFromFile<Reader>(fread_readers);
		std::cout << "Readers added to library." << std::endl;
		fread_readers.close();
	}
    
}
