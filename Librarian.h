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
		//template<typename T>
	void addBookToLibrary(std::istream& is);
	void addReaderToLibrary(std::istream& is);

	template<typename T>
	void addItemFromFile(std::istream& is)
	{
		{
			T str;
			while (read(is, str))
			{
				auto tmp = std::shared_ptr<T>(new T(str));
			
				this->allBooks.push_back(std::move(tmp));
			}
		}
	}
	void addReadersFromFile(std::istream& is);

	void showReaders();
	Reader_t findReaders(std::string& str);
	Reader_iter selectReader();


	void showBooks();
	Book_t findBooks(std::string& str);
	Book_iter selectBook();

	std::map<Reader_iter, std::vector<Book_iter>>  giveBook();

	friend void strTolower(std::string&);
	friend std::istream& read(std::istream&, Book&);
	friend Keeper;
//private:
	std::vector<std::unique_ptr<Book>> allBooks;
	std::vector<std::unique_ptr <Reader>> allReaders;
};

