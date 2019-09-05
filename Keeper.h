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

	std::map<std::string, std::string> readGivenBookfromXML();//*

	void saveBookToXML();
	void readBookFromXML();
	void saveSingleBookToXML(Book&);
	void delBookFromXML(const std::string&);

	void saveReaderToXML();
	void readReaderFromXML();
		
	void saveGivenBookToXML(const std::map<Book_iter, Reader_iter>&);//*

	

private:
	Librarian* lib;
};

