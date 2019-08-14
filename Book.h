#pragma once
#include <string>
#include <fstream>

class Book
{
public:
	Book();
	explicit Book(std::string id);
	Book(std::string id, std::string auther, std::string title);
	Book(std::istream&);
	void setBook(std::string id, std::string auther, std::string title);

	friend std::ostream& operator<<(std::ostream&, const Book&);
	friend std::istream& read(std::istream&, Book&);
	//friend std::ostream& print(std::ostream&, const Book&);
	
private:
	std::string id;
	std::string auther;
	std::string title;

};

