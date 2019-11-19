#pragma once

#include "book.h"
#include "librarian.h"
#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <vector>

using namespace tinyxml2;
class Keeper : public Librarian
{
public:
    Keeper(Librarian* lib);

    std::multimap<std::string, std::string> readGivenBookfromXML();

    void saveBookToXML();
    void readBookFromXML();
    void saveSingleBookToXML(Book&);
    void delBookFromXML(const std::string&);

    void saveReaderToXML();
    void readReaderFromXML();

    void saveGivenBookToXML(const std::multimap<Reader_iter, Book_iter>&);

private:
    Librarian* lib;
};
