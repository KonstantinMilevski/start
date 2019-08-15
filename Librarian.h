#pragma once
#include "Book.h"
#include "Reader.h"
#include <iostream>
#include <vector>

using Book_t=std::vector < std::vector<std::unique_ptr<Book>>::const_iterator >;
using Reader_t = std::vector<std::vector<std::unique_ptr<Reader>>::const_iterator>;
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
	void showBooks();
	void showReaders();
	Book& selectBook();

	friend std::istream& read(std::istream&, Book&);
	friend Keeper;
//private:
	std::vector<std::shared_ptr<Book>> allBooks;
	std::vector<std::shared_ptr <Reader>> allReaders;
};

