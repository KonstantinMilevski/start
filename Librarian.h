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

	void createBook(std::istream&, Book&);
	void addSingleBook(Book&);
	bool delBook(std::string& );
	void showBooks();
	bool checkBookLinks(Book_iter& bookIterator);
	Book_t findBooks(std::string& str);
	Book_iter selectBook();
		
	void createReader(std::istream&, Reader&);
	void addSingleReader(Reader&);
	bool delReader(std::string&);
	void showReaders();
	bool checkReaderLinks(Reader_iter&);
	Reader_t findReaders(std::string& str);
	Reader_iter selectReader();

	std::string searchWord();
	
	void showFoundBooks();
	
	void giveBook(std::map<Book_iter, Reader_iter>& );
	void showGivenBooks(const std::map<Book_iter, Reader_iter>&);
	void returnBook(std::map<Book_iter, Reader_iter>&);

	std::map<Book_iter, Reader_iter> restoreLinks(std::map<std::string, std::string>&);
	Book_iter restoreBookLink(const std::string&);
	Reader_iter restoreReaderLink(std::string& );

	friend void strTolower(std::string&);
	friend std::istream& read(std::istream&, Book&);
	friend std::istream& read(std::istream&, Reader&);
	friend Keeper;
private:
	std::vector<std::unique_ptr<Book>> allBooks;
	std::vector<std::unique_ptr <Reader>> allReaders;

	std::vector<Book_iter> vecReadBooksIter;
	
};

