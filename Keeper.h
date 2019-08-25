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
	void saveBookToXML();
	void readBookFromXML();

	void saveReaderToXML();
	void readReaderFromXML();
private:
	Librarian* lib;
};

