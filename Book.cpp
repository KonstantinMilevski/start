#include "Book.h"

Book::Book():Book(""){}

Book::Book(std::string id) : id(id) {}

Book::Book(std::string id, std::string auther, std::string title)
	: id(id), auther(auther), title(title) {}

Book::Book(std::istream& is) { read(is, *this); }

void Book::setBook(std::string id, std::string auther, std::string title)
{
	this->id= id;
	this->auther = auther;
	this->title = title;
}

void Book::setBookId(std::string id)
{
	this->id = id;
}

const std::string Book::getId()
{
	return this->id;
}

const std::string Book::getAuther()
{
	return this->auther;
}

const std::string Book::getTitle()
{
	return this->title;
}

void Book::show()
{
	std::cout << this->id << " - " << this->auther << " - " << this->title << std::endl;
}

bool Book::isEmpty()
{
	if (this->getId() == "" || this->getAuther() == "" || this->getTitle() == "")
		return true;
	else
		return false; 
}


std::ostream& operator<<(std::ostream& os, const Book& book)
{
	os << book.id <<" : "<< book.auther <<" : "<< book.title;
	return os;
}
std::istream& read(std::istream& is, Book& item)
{
	std::getline(is, item.id);
	std::getline(is, item.auther);
	std::getline(is, item.title);
	return is;
}
