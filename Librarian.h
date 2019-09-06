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
	std::map<Book_iter, Reader_iter> givenBook;//*+

	Book createBook(std::istream& );
	Book addSingleBook();
	void delBook(std::string& );
	void showBooks();


	//template<typename T>
	
	void showReaders();
	std::string searchWord();
	Reader_t findReaders(std::string& str);
	Reader_iter selectReader();
	
	Book_t findBooks(std::string& str);
	Book_iter selectBook();
	void showFoundBooks();

	

	void giveBook(std::map<Book_iter, Reader_iter>& );//*++
	void showGivenBooks(const std::map<Book_iter, Reader_iter>&);//*+
	void returnBook(std::map<Book_iter, Reader_iter>&);//*+

	std::map<Book_iter, Reader_iter> restoreLinks(std::map<std::string, std::string>&);//*+
	Book_iter restoreBookLink(const std::string&);
	Reader_iter restoreReaderLink(std::string& );

	friend void strTolower(std::string&);
	friend std::istream& read(std::istream&, Book&);
	friend Keeper;
private:
	std::vector<std::unique_ptr<Book>> allBooks;
	std::vector<std::unique_ptr <Reader>> allReaders;

	std::vector<Book_iter> vecReadBooksIter;
	
};

