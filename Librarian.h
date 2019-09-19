#pragma once
#include "Book.h"
#include "Reader.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using Book_vect_iter = std::vector<std::unique_ptr<Book>>::const_iterator;
using Reader_vect_iter = std::vector<std::unique_ptr<Reader>>::const_iterator;

using Vector_Book_iter= std::vector<Book_vect_iter>;
using Reader_t = std::vector<Reader_vect_iter>;

class Keeper;
class Librarian
{
public:

	void addSingleBook(Book&);
	bool delBook(std::string&, std::map<Book_vect_iter, Reader_vect_iter>& );
	void showBooks();
		
	void addSingleReader(Reader&);
	bool delReader(std::string&, std::map<Book_vect_iter, Reader_vect_iter>& );
	void showReaders();
		
	void showFoundBooks();
	
	void giveBook(std::map<Book_vect_iter, Reader_vect_iter>& );
	void showGivenBooks(const std::map<Book_vect_iter, Reader_vect_iter>&);
	void returnBook(std::map<Book_vect_iter, Reader_vect_iter>&);

	std::map<Book_vect_iter, Reader_vect_iter> restoreLinks(std::map<std::string, std::string>&);
	

	friend void strTolower(std::string&);
	friend std::istream& read(std::istream&, Book&);
	friend std::istream& read(std::istream&, Reader&);
	friend Keeper;
protected:
	void createBook(std::istream&, Book&);
	void createReader(std::istream&, Reader&);
	
private:
	bool checkBookLinks(Book_vect_iter& bookIterator, std::map<Book_vect_iter, Reader_vect_iter>&);
	Vector_Book_iter findBooks(std::string& str);
	Book_vect_iter selectBook();

	bool checkReaderLinks(Reader_vect_iter&, std::map<Book_vect_iter, Reader_vect_iter>&);
	Reader_t findReaders(std::string& str);
	Reader_vect_iter selectReader();

	Book_vect_iter restoreBookLink(const std::string&);
	Reader_vect_iter restoreReaderLink(std::string&);

	std::string searchWord();

	std::vector<std::unique_ptr<Book>> allBooks;
	std::vector<std::unique_ptr <Reader>> allReaders;
 };

