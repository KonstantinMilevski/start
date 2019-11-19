#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <memory>
class Reader;
class Book
{
public:
	Book();
	explicit Book(std::string id);
	Book(std::string id, std::string auther, std::string title);
	explicit Book(std::istream&);

	void setBook(std::string id, std::string auther, std::string title);
	void setBookId(std::string id);
	const std::string getId();
	const std::string getAuther();
	const std::string getTitle();
	void show();
	//void giveBook(Reader& newReader);
	friend std::ostream& operator<<(std::ostream&, const Book&);
	friend std::istream& read(std::istream&, Book&);
	//friend std::ostream& print(std::ostream&, const Book&);
	
private:
	std::string id;
	std::string auther;
	std::string title;
	//std::shared_ptr<Reader> readerWithBook;


};

