#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <memory>

class Reader
{
public:
	Reader();
	explicit Reader(std::string );
	Reader(std::string , std::string , std::string );
	explicit Reader(std::istream&);

	void setReader(std::string , std::string , std::string );
	void setReader();
	void setReaderId(std::string );
	std::string getId() const;
	std::string getName() const;
	std::string getSurname() const;
	void show() const;
	
	bool isEmpty() const;
	

	friend std::ostream& operator<<(std::ostream&, const Reader&);
	friend std::istream& read(std::istream&, Reader&);
private:
	std::string id;
	std::string name;
	std::string surname;
};

