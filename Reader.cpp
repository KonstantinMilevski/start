#include "Reader.h"
Reader::Reader() :Reader("") {}

Reader::Reader(std::string id) : id(id) {}

Reader::Reader(std::string id, std::string auther, std::string title)
	: id(id), name(name), surname(surname) {}

Reader::Reader(std::istream& is) { read(is, *this); }

std::istream& read(std::istream& is, Reader& item)
{
	std::getline(is, item.id);
	std::getline(is, item.name);
	std::getline(is, item.surname);
	return is;
}
std::ostream& operator<<(std::ostream& os, const Reader& Reader)
{
	os << Reader.id<<" : " << Reader.name << ", " << Reader.surname;
	return os;
}
void Reader::setReader(std::string id, std::string name, std::string surname)
{
	this->id = id;
	this->name = name;
	this->surname = surname;
}

void Reader::setReader()
{
	this->id = "";
	this->name = "";
	this->surname = "";
}

void Reader::setReaderId(std::string id)
{
	this->id = id;
}

std::string Reader::getId() const
{
	return this->id;
}

std::string Reader::getName() const
{
	return this->name;
}

std::string Reader::getSurname() const
{
	return this->surname;
}

void Reader::show() const
{
	std::cout << this->id << " - " << this->name << " - " << this->surname << std::endl;
}

bool Reader::isEmpty() const
{
	if (this->getId() == "" || this->getName() == "" || this->getSurname()== "")
			return true;
	else
			return false;
}

