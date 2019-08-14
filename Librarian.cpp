#include "Librarian.h"

//void Librarian::addItemToLibrary(std::istream& is)
//{
//
//	std::cout << "Enter the name: " << std::endl;
//	Book str;
//	if (read(is, str))
//	{
//		std::cout << "You entered : " << str << std::endl;
//		auto tmp = std::unique_ptr<Book>(new Book(str));
//		this->allBook.push_back(std::move(tmp));
//		std::cout << "Book is added" << std::endl;
//	}
//	else
//		std::cerr << "No data?!" << std::endl;
//}

//void Librarian::addBookFromFile(std::istream& is)
//{
//	{
//		Book str;
//		while (read(is, str))
//		{
//			auto tmp = std::unique_ptr<Book>(new Book(str));
//			this->allBook.push_back(std::move(tmp));
//		}
//	}
//}

void Librarian::addReadersFromFile(std::istream& is)
{
	{
		Reader temp;
		while (read(is, temp))
		{
			auto tmp = std::shared_ptr<Reader>(new Reader(temp));

			this->allReaders.push_back(std::move(tmp));
		}
	}
}

void Librarian::showBooks()
{
	for (const auto& book : allBooks)
		book->show();
}

void Librarian::showReaders()
{
	for (const auto& reader : allReaders)
		reader->show();
}
