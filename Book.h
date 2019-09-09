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

	void setBook();
	void setBook(std::string id, std::string auther, std::string title);
	void setBookId(std::string id);
	const std::string getId() const;
	const std::string getAuther() const;
	const std::string getTitle() const;
	void show() const;
	bool isEmpty() const;
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

