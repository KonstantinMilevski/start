#pragma once
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
	void setReaderId(std::string );
	std::string getId();

	friend std::ostream& operator<<(std::ostream&, const Reader&);
	friend std::istream& read(std::istream&, Reader&);
private:
	std::string id;
	std::string name;
	std::string surname;
};

