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
	Book temp ;
	if (read(is, temp))
	{
		if (temp.isEmpty())
		{
			throw std::exception("Empty field. Try again.");
		}
		return temp;
	}
	else
	{
		throw std::exception("Input fail. Try again.");
	}

}

Book Librarian::addSingleBook()
{
	Book temp;
	try
	{
		std::cout << "Insert book's Id, auther, title" << std::endl;
		temp = this->createBook(std::cin);
	

		for (const auto& book : allBooks)
		{
			if (book->getId() == temp.getId())
			{
				std::cout << "Book with such Id is in the library, try again" << std::endl;
				
			}
		}
		auto tmp = std::make_unique<Book>(temp);
		this->allBooks.push_back(std::move(tmp));
		return temp;
	}
	catch (const std::exception& ex)
	{
		std::cout << "Catch " << ex.what() << std::endl;
	}

}
void Librarian::delBook(std::string& str)
{
	Book_iter bookIterator = this->selectBook();
	str=(*bookIterator)->getId();
	this->allBooks.erase(bookIterator);
	
}
void Librarian::showBooks()
{
	for (const auto& book : allBooks)
		std::cout << *book<<std::endl;
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
			//throw out_of_range(msg);
		}
		else
		{
			std::cin.ignore(UINT_MAX, '\n');
			return vecBooksIter.at(row - 1);
		}
	}
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
void Librarian::showReaders()
{
	for (const auto& reader : allReaders)
		std::cout << *reader << std::endl;
}




//////////map<Book_ite, Reader_iter r>


void Librarian::giveBook(std::map<Book_iter, Reader_iter>& givenBook)
{
	const Reader_iter readerIt = this->selectReader();
	const Book_iter bookIt = this->selectBook();
	
	auto result=givenBook.emplace(bookIt,readerIt);
	if (!result.second)
	{
		std::cout << "Book is using, try another " << std::endl;
	}
}

void Librarian::showGivenBooks(const std::map<Book_iter, Reader_iter >& givenBooks)// check empty
{
	for (const auto& pair : givenBooks)
	{
		std::cout << **pair.first << " : " << **pair.second << std::endl;
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
	/////////////
	////////////add check
	givenBooks.erase(result);
}

////////////////
std::map<Book_iter, Reader_iter> Librarian::restoreLinks(std::map<std::string, std::string>& links)
{
	std::map<Book_iter, Reader_iter> restoredLinks;
	for (auto pair : links)
	{
		std::string book = pair.first;
		std::string reader = pair.second;
		//check return .cend  
		 Book_iter bookIt=restoreBookLink(book);
		 Reader_iter readerIt = restoreReaderLink(reader);
		
		 restoredLinks.emplace(bookIt, readerIt);
	}
	std::cout << "Links had been restored " << std::endl;
	return restoredLinks;

}

Book_iter Librarian::restoreBookLink(const std::string& id)
{

	for (auto it = this->allBooks.begin(); it != this->allBooks.end(); it++)
	{
		std::string returnFullName = (*it)->getId() + " " + (*it)->getAuther() + " " + (*it)->getTitle();
		strTolower(returnFullName);
		if (returnFullName.find(id) != std::string::npos)
		{
			return it;
		}
	}
}

Reader_iter Librarian::restoreReaderLink(std::string& id)
{
	Reader_t  vecReadersIter = this->findReaders(id);
	if (vecReadersIter.empty())
	{
		std::cout << "No rezult, try again " << std::endl;
		return this->allReaders.cend();//check
	}
	else
	{	
	 return vecReadersIter.at(0);
	}
}


