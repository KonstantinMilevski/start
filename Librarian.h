#pragma once
#include "Book.h"
#include "Reader.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using Book_iter = std::vector<std::unique_ptr<Book>>::const_iterator;
using Reader_iter = std::vector<std::unique_ptr<Reader>>::const_iterator;

using Book_t= std::vector<Book_iter>;
using Reader_t = std::vector<Reader_iter>;


// не дружить попробовать
class Keeper;
class Librarian
{
public:
		
	Book createBook(std::istream& );
	void addSingleBook(Book& );
	void delBook(std::string& );
	void showBooks();

	//template<typename T>
	
	void showReaders();

	Reader_t findReaders(std::string& str);
	Reader_iter selectReader();
	
	

	Book_iter takeBookField();

	Book_t findBooks(std::string& str);
	Book_iter selectBook();

	std::multimap<Reader_iter, Book_iter>  giveBook();

	friend void strTolower(std::string&);
	friend std::istream& read(std::istream&, Book&);
	friend Keeper;
private:
	std::vector<std::unique_ptr<Book>> allBooks;
	std::vector<std::unique_ptr <Reader>> allReaders;

	std::vector<Book_iter> vecReadBooksIter;
};

