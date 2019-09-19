#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Librarian.h"
#include "tinyxml2.h"
#include "Book.h"

using namespace tinyxml2;
class Keeper
{
public:
	Keeper(Librarian* lib);

	std::map<std::string, std::string> readGivenBookfromXML();

	void saveBookToXML();
	void readBookFromXML();
	void saveSingleBookToXML(const Book&);
	void delBookFromXML(const std::string&);

	void saveReaderToXML();
	void readReaderFromXML();
	void saveSingleReaderToXML(Reader&);
	void delReaderFromXML(const std::string&);

	void saveGivenBookToXML(const std::map<Book_vect_iter, Reader_vect_iter>&);
	
private:
	Librarian* lib;
};

