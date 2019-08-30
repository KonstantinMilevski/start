#include "Librarian.h"


void strTolower(std::string& s)
{
	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) {
			return std::tolower(c); }
	);
}

Book Librarian::createBook(std::istream& is)//check
{
	Book temp;
	if (read(is, temp))
	{
		return temp;
	}
}

void Librarian::addSingleBook(Book& newBook)
{
	auto tmp = std::unique_ptr<Book>(new Book(newBook));
	this->allBooks.push_back(std::move(tmp));
}

void Librarian::delBook(std::string str)
{
	Book_iter bookIterator = this->selectBook();
	str=(*bookIterator)->getId();
	this->allBooks.erase(bookIterator);
	
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
		return this->allReaders.cend();//check
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
			return this->allReaders.cend();
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


std::multimap<Reader_iter, Book_iter> Librarian::giveBook()
{
	//std::map<Reader_iter, std::vector<Book_iter>> readersWithBooks;

	std::multimap<Reader_iter, Book_iter> readersWithBooks;

	Reader_iter r = this->selectReader();
	Book_iter b=this->selectBook();

	//std::vector<Book_iter> vecReadBooksIter;
	//std::vector<Book_iter> vecReadBooksIter;
	//vecReadBooksIter.push_back(b);

	//readersWithBooks.insert(std::make_pair(r, vecReadBooksIter));

	readersWithBooks.insert(std::make_pair(r, b));
	////
	//std::multimap<Reader_iter, std::vector<Book_iter>>::iterator it;


	/*for (it = readersWithBooks.begin(); it != readersWithBooks.end(); ++it)
	{
		std::cout << (*(it->first))->getName()<< std::endl;
		for (auto v : (it->second))
			std::cout << "---" << (*v)->getTitle()<< std::endl;
	}*/

	return readersWithBooks;
}

