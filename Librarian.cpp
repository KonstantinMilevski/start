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

void strTolower(std::string& s)
{
	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) {
			return std::tolower(c); }
	);
}

void Librarian::addBookToLibrary(std::istream& is)
{
	Book temp;
	read(is, temp);
	auto tmp = std::unique_ptr<Book>(new Book(temp));
	this->allBooks.push_back(std::move(tmp));
}

void Librarian::addReadersFromFile(std::istream& is)
{
	{
		Reader temp;
		while (read(is, temp))
		{
			auto tmp = std::unique_ptr<Reader>(new Reader(temp));

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

Reader_t Librarian::findReaders(std::string& searchString)
{
	Reader_t vecReadersIter;
	strTolower(searchString);
	for (auto it = this->allReaders.cbegin(); it != this->allReaders.cend(); it++)
	{
		std::string returnFullName = (*it)->getName() + " " + (*it)->getSurname();
		strTolower(returnFullName);
		if (returnFullName.find(searchString) != std::string::npos)
		{
			vecReadersIter.push_back(it);
		}
	}
	return  vecReadersIter;
}

Reader_iter Librarian::selectReader()
{
	std::cout << "Reader: enter a search phrase " << std::endl;
	std::string str;
	std::getline(std::cin, str);

	Reader_t  vecReadersIter = this->findReaders(str);
	if (vecReadersIter.empty())
	{
		std::cout << "No rezult, try again " << std::endl;
	}
	else
	{
		unsigned int count = 1;
		for (auto book : vecReadersIter)
		{
			std::cout << count << ". " << (**book) << std::endl;
			count++;
		}
		std::cout << "Select the row" << std::endl;
		unsigned int row(0);
		if (!(std::cin >> row && row > 0 && row <= vecReadersIter.size()))
		{
			std::cin.ignore(UINT_MAX, '\n');
			std::cout << "Incorrect input, try again " << std::endl;
			//throw out_of_range(msg);
		}
		else
		{
			std::cin.ignore(UINT_MAX, '\n');
			return vecReadersIter.at(row - 1);
		}
	}
}

Book_t Librarian::findBooks(std::string& searchString)
{
	Book_t vecBooksIter;
	strTolower(searchString);
	for (auto it = this->allBooks.cbegin(); it != this->allBooks.cend(); it++)
	{
		std::string returnFullName = (*it)->getAuther() + " " + (*it)->getTitle();
		strTolower(returnFullName);
		if (returnFullName.find(searchString) != std::string::npos)
		{
			vecBooksIter.push_back(it);
		}
	}
	return  vecBooksIter;
}
// throw out_of_range(msg);
Book_iter Librarian::selectBook()
{
	std::cout << "Book: enter a search phrase " << std::endl;
	std::string str;
	std::getline(std::cin, str);

	Book_t  vecBooksIter = this->findBooks(str);
	if (vecBooksIter.empty())
	{
		std::cout << "No rezult, try again " << std::endl;
	}
	else
	{
		unsigned int count = 1;
		for (auto book : vecBooksIter)
		{
			std::cout << count << ". " << (**book) << std::endl;
			count++;
		}
		std::cout << "Select the row" << std::endl;
		unsigned int row(0);
		if (!(std::cin >> row && row > 0 && row <= vecBooksIter.size()))
		{
			std::cin.ignore(UINT_MAX, '\n');
			std::cout << "Incorrect input, try again " << std::endl;
			//throw out_of_range(msg);
		}
		else
		{
			std::cin.ignore(UINT_MAX, '\n');
			return vecBooksIter.at(row - 1);
		}
	}
}


std::map<Reader_iter, std::vector<Book_iter>> Librarian::giveBook()
{
	std::map<Reader_iter, std::vector<Book_iter>> readersWithBooks;

	Reader_iter r = this->selectReader();
	Book_iter b=this->selectBook();

	std::vector<Book_iter> vecReadBooksIter;
	vecReadBooksIter.push_back(b);

	readersWithBooks.insert(std::make_pair(r, vecReadBooksIter));
	////
	std::multimap<Reader_iter, std::vector<Book_iter>>::iterator it;
	for (it = readersWithBooks.begin(); it != readersWithBooks.end(); ++it)
		std::cout << std::left << "---" << (*(it->first))->getName() << std::left << "---" << (*((it->second).at(0)))->getTitle()  << std::endl;


	return readersWithBooks;
}

