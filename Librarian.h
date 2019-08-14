#pragma once
#include "Book.h"
#include "Reader.h"
#include <iostream>
#include <vector>

class Track;
class Librarian
{
public:
	//template<typename T>
	void addItemToLibrary(std::istream& is);

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


	friend std::istream& read(std::istream&, Book&);
	friend Track;
//private:
	std::vector<std::shared_ptr<Book>> allBooks;
	std::vector<std::shared_ptr <Reader>> allReaders;
};

