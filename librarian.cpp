#include "librarian.h"

void strTolower(std::string& s)
{
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return std::tolower(c); });
}

Book Librarian::createBook(std::istream& is) // check
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
void Librarian::delBook(std::string& str)
{
    Book_iter bookIterator = this->selectBook();
    str                    = (*bookIterator)->getId();
    this->allBooks.erase(bookIterator);
}
void Librarian::showBooks()
{
    for (const auto& book : allBooks)
        std::cout << *book << std::endl;
}
Book_iter Librarian::selectBook()
{
    std::string temp         = searchWord();
    Book_t      vecBooksIter = this->findBooks(temp);
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
            // throw out_of_range(msg);
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
        std::string returnFullName =
            (*it)->getId() + " " + (*it)->getAuther() + " " + (*it)->getTitle();
        strTolower(returnFullName);
        if (returnFullName.find(searchString) != std::string::npos)
        {
            vecBooksIter.push_back(it);
        }
    }
    return vecBooksIter;
}
void Librarian::showFoundBooks()
{
    std::string temp         = searchWord();
    Book_t      vecBooksIter = this->findBooks(temp);
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
    for (auto it = this->allReaders.cbegin(); it != this->allReaders.cend();
         it++)
    {
        std::string returnFullName =
            (*it)->getId() + " " + (*it)->getName() + " " + (*it)->getSurname();
        strTolower(returnFullName);
        if (returnFullName.find(searchString) != std::string::npos)
        {
            vecReadersIter.push_back(it);
        }
    }
    return vecReadersIter;
}
Reader_iter Librarian::selectReader()
{
    std::string temp           = searchWord();
    Reader_t    vecReadersIter = this->findReaders(temp);
    if (vecReadersIter.empty())
    {
        std::cout << "No rezult, try again " << std::endl;
        return this->allReaders.cend(); // check
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

//////////

void Librarian::giveBook(std::multimap<Reader_iter, Book_iter>& givenBook)
{
    Reader_iter readerIt = this->selectReader();
    Book_iter   bookIt   = this->selectBook();

    for (auto pos = givenBook.cbegin(); pos != givenBook.cend(); ++pos)
    {
        if (pos->second == bookIt)
        {
            std::cout << "Book is using, try another " << std::endl;
            return;
        }
    }
    givenBook.insert(std::make_pair(readerIt, bookIt));
}

void Librarian::showGivenBooks(
    const std::multimap<Reader_iter, Book_iter>& givenBooks) // check empty
{
    for (const auto& pair : givenBooks)
    {
        std::cout << **pair.first << " : " << **pair.second << std::endl;
    }
}

void Librarian::returnBook(std::multimap<Reader_iter, Book_iter>& givenBooks)
{
    Reader_iter readerIt = this->selectReader();
    std::cout << (**readerIt) << ":" << std::endl;
    for (auto pos = givenBooks.equal_range(readerIt); pos.first != pos.second;
         ++pos.first)
    {
        std::cout << **pos.first->second << std::endl;
    }
    Book_iter bookIt = this->selectBook();
    for (auto pos = givenBooks.equal_range(readerIt); pos.first != pos.second;
         ++pos.first)
    {
        if (pos.first->second == bookIt)
        {
            givenBooks.erase(pos.first);
            break;
        }
    }
}

////////////////
std::multimap<Reader_iter, Book_iter> Librarian::restoreLinks(
    std::multimap<std::string, std::string>& links)
{
    std::multimap<Reader_iter, Book_iter> restoredLinks;
    for (auto pair : links)
    {
        std::string r   = pair.first;
        std::string b   = pair.second;
        Book_iter   bIt = restoreBookLink(b);
        //
        Reader_iter rIt = restoreReaderLink(r);
        // givenBook.emplace(restoreReaderLink(r), restoreBookLink(b));
        restoredLinks.emplace(rIt, bIt);
    }
    std::cout << "Links had been restored " << std::endl;
    return restoredLinks;
}

Book_iter Librarian::restoreBookLink(const std::string& id)
{

    for (auto it = this->allBooks.begin(); it != this->allBooks.end(); it++)
    {
        std::string returnFullName =
            (*it)->getId() + " " + (*it)->getAuther() + " " + (*it)->getTitle();
        strTolower(returnFullName);
        if (returnFullName.find(id) != std::string::npos)
        {
            return it;
        }
    }
}

Reader_iter Librarian::restoreReaderLink(std::string& id)
{
    Reader_t vecReadersIter = this->findReaders(id);
    if (vecReadersIter.empty())
    {
        std::cout << "No rezult, try again " << std::endl;
        return this->allReaders.cend(); // check
    }
    else
    {
        return vecReadersIter.at(0);
    }
}
