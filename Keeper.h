#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Librarian.h"
#include "tinyxml2.h"
#include "Book.h"

using namespace tinyxml2;
class Keeper:public Librarian
{
public:
	Keeper(Librarian* lib);

	void saveBookToXML();
	void readBookFromXML();
	void saveSingleBookToXML(Book&);
	void delBookFromXML(std::string&);

	void saveReaderToXML();
	void readReaderFromXML();

	

	void saveGivenBookToXML(const std::multimap<Reader_iter, Book_iter>&);

private:
	Librarian* lib;
};

