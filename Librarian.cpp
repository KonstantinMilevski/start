#include "Librarian.h"


void strTolower(std::string& s)
{
	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) {
			return std::tolower(c); }
	);
}

void Librarian::createBook(std::istream& is, Book& newbook)//check
{
	if (read(is, newbook))
	{
		if (newbook.isEmpty())
		{
			throw std::exception("Empty field. Try again.");
		}
	}
	else
	{
		throw std::exception("Input fail. Try again.");
	}

}

void Librarian::addSingleBook(Book& newbook)
{
	try
	{
		std::cout << "Insert book's Id, auther, title" << std::endl;
		this->createBook(std::cin, newbook);
	
		for (const auto& book : allBooks)
		{
			if (book->getId() == newbook.getId())
			{
				std::cout << "Book with such Id is in the library, try again" << std::endl;
				newbook.setBook();
				return;
			}
		}
		auto tmp = std::make_unique<Book>(newbook);
		this->allBooks.push_back(std::move(tmp));
	}
	catch (const std::exception& ex)
	{
		std::cout << "Catch " << ex.what() << std::endl;
	}
}

void Librarian::showBooks()
{
	for (const auto& book : allBooks)
		std::cout << *book<<std::endl;
}
bool Librarian::checkBookLinks(Book_iter& bookIterator, std::map<Book_iter, Reader_iter>& givenBooks)
{
	if (givenBooks.count(bookIterator))
		return false;
	else
		return true;
}
Book_iter Librarian::selectBook()
{
	std::string temp = searchWord();
	Book_t  vecBooksIter = this->findBooks(temp);
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
		}
		else
		{
			std::cin.ignore(UINT_MAX, '\n');
			return vecBooksIter.at(row - 1);
		}
	}
	return  allBooks.end() ;
}
Book_t Librarian::findBooks(std::string& searchString)
{
	Book_t vecBooksIter;
	strTolower(searchString);
	
	for (auto it = this->allBooks.cbegin(); it != this->allBooks.cend(); it++)
	{
		std::string returnFullName = (*it)->getId() + " " + (*it)->getAuther() + " " + (*it)->getTitle();
		strTolower(returnFullName);
		if (returnFullName.find(searchString) != std::string::npos)
		{
			vecBooksIter.push_back(it);
		}
	}
	return  vecBooksIter;
}
void Librarian::showFoundBooks()
{
	std::string temp = searchWord();
	Book_t  vecBooksIter = this->findBooks(temp);
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
	}

}
bool Librarian::delBook(std::string& str, std::map<Book_iter, Reader_iter>& givenBooks)
{
	Book_iter bookIterator = this->selectBook();
	if (bookIterator== allBooks.end())
	{
		std::cout << "Incorrect, try again " << std::endl;
		return false;
	}
	else if (checkBookLinks(bookIterator, givenBooks))
		{
				str = (*bookIterator)->getId();
				this->allBooks.erase(bookIterator);
				return true;
		}
		else
		{
			std::cout << "Book isreading. You can't remove it. " << std::endl;
			return false;
		}
}


////
std::string Librarian::searchWord()
{
	std::cout << "Enter a search phrase " << std::endl;
	std::string temp;
	std::getline(std::cin, temp);
	return temp;
}

////
Reader_t Librarian::findReaders(std::string& searchString)
{
	Reader_t vecReadersIter;
	strTolower(searchString);
	for (auto it = this->allReaders.cbegin(); it != this->allReaders.cend(); it++)
	{
		std::string returnFullName = (*it)->getId()+ " " + (*it)->getName() + " " + (*it)->getSurname();
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
	std::string temp = searchWord();
	Reader_t  vecReadersIter = this->findReaders(temp);
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
void Librarian::createReader(std::istream& is, Reader& newreader)
{
	if (read(is, newreader))
	{
		if (newreader.isEmpty())
		{
			throw std::exception("Empty field. Try again.");
		}
	}
	else
	{
		throw std::exception("Input fail. Try again.");
	}
}
void Librarian::addSingleReader(Reader& newreader)
{
	try
	{
		std::cout << "Insert reader's Id, auther, title" << std::endl;
		this->createReader(std::cin, newreader);

		for (const auto& reader : allReaders)
		{
			if (reader->getId() == newreader.getId())
			{
				std::cout << "Reader with such Id is in the library, try again" << std::endl;
				newreader.setReader();
				return;
			}
		}
		auto tmp = std::make_unique<Reader>(newreader);
		this->allReaders.push_back(std::move(tmp));
	}
	catch (const std::exception& ex)
	{
		std::cout << "Catch " << ex.what() << std::endl;
	}
}
bool Librarian::delReader(std::string& path, std::map<Book_iter, Reader_iter>& givenBooks)
{
	Reader_iter readerIterator = this->selectReader();
	if (readerIterator == allReaders.end())
	{
		std::cout << "Incorrect, try again " << std::endl;
		return false;
	}
	else if (checkReaderLinks(readerIterator, givenBooks))
	{
		path = (*readerIterator)->getId();
		this->allReaders.erase(readerIterator);
		return true;
	}
	else
	{
		std::cout << "Reader is reading a book. You can't remove it. " << std::endl;
		return false;
	}
}
void Librarian::showReaders()
{
	for (const auto& reader : allReaders)
		std::cout << *reader << std::endl;
}
bool Librarian::checkReaderLinks(Reader_iter& readerIterator, std::map<Book_iter, Reader_iter>& givenBooks)
{
	for (const auto& pair : givenBooks)
	{
		if (pair.second == readerIterator)
		{
			return false;
		}
	}
	return true;
}


void Librarian::giveBook(std::map<Book_iter, Reader_iter>& givenBooks)
{
	const Reader_iter readerIt = this->selectReader();
	const Book_iter bookIt = this->selectBook();
	
	auto result=givenBooks.emplace(bookIt,readerIt);
	if (!result.second)
	{
		std::cout << "Book is using, try another " << std::endl;
	}
}

void Librarian::showGivenBooks(const std::map<Book_iter, Reader_iter >& givenBooks)// check empty
{
	if (givenBooks.empty())
	{
		std::cout << "No given books"<< std::endl;
	}
	else
	{
		for (const auto& pair : givenBooks)
		{
			std::cout << **pair.first << " : " << **pair.second << std::endl;
		}
	}
}

void Librarian::returnBook(std::map<Book_iter, Reader_iter>& givenBooks)
{
	Book_iter bookIt = this->selectBook();
	auto result=givenBooks.find(bookIt);
	if (result==givenBooks.end())
	{
		std::cout << "Missmatch" << std::endl;
		return;
	}
	std::cout << "Search result - \nBook: " <<**bookIt<<"\nReader: "<<**(*result).second << std::endl;
	givenBooks.erase(result);
}

std::map<Book_iter, Reader_iter> Librarian::restoreLinks(std::map<std::string, std::string>& links)
{
	std::map<Book_iter, Reader_iter> restoredLinks;
	try
	{
		if (links.empty())
		{
			return restoredLinks;
		}
		for (auto& pair : links)
		{
			Book_iter bookIt = restoreBookLink(pair.first);
			Reader_iter readerIt = restoreReaderLink(pair.second);
			restoredLinks.emplace(bookIt, readerIt);
		}
		std::cout << "Links had been restored " << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return restoredLinks;
}

Book_iter Librarian::restoreBookLink(const std::string& id)
{

	for (auto it = this->allBooks.begin(); it != this->allBooks.end(); it++)
	{
		std::string checkId = (*it)->getId();
		if (id == checkId)
		{
			return it;
		}
	}
	throw std::exception("Empty fields. Can't restored books links.");
}

Reader_iter Librarian::restoreReaderLink(std::string& id)
{
	Reader_t  vecReadersIter = this->findReaders(id);
	if (vecReadersIter.empty())
		throw std::exception("Empty fields. Can't restored readers links.");
	else
		 return vecReadersIter.at(0);
}


