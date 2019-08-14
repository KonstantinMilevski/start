#include <iostream>
#include "Book.h"
#include"Reader.h"
#include "Librarian.h"
#include "Truck.h"



int main()
{
	Librarian l;
	Track* track;
	

	std::ifstream fread_books("books.txt" /*std::fstream::ate*/);
	if (!fread_books)
		std::cout << "error opening file books.txt \nBooks not added to library." << std::endl;
	else
	{
		l.addItemFromFile<Book>(fread_books);
		std::cout << "Books added to library." << std::endl;
		fread_books.close();
	}
	l.showBooks();
	std::ifstream fread_readers("readers.txt"/*, std::fstream::ate*/);
	if (!fread_readers)
		std::cout << "error opening file readers.txt \nReaders not added to library." << std::endl;
	else
	{
		l.addReadersFromFile(fread_readers);
		std::cout << "Readers added to library." << std::endl;
		fread_readers.close();
	}
	l.showReaders();


	tinyxml2::XMLDocument doc;
	
	//XMLDeclaration* decl = new XMLDeclaration ("1.0", "", "");
	XMLNode* root = doc.NewElement("Books");
	//doc.LinkEndChild(root);

	doc.InsertFirstChild(root);
	
	for (const auto& item : l.allBooks)
	{
		XMLElement* el = doc.NewElement("Book");

		XMLElement* id = doc.NewElement("Id");
		id->SetText(item->getId().c_str());
		el->InsertEndChild(id);

		XMLElement* auther = doc.NewElement("auther");
		auther->SetText(item->getId().c_str());
		el->InsertEndChild(auther);

		XMLElement* title = doc.NewElement("title");
		title->SetText(item->getId().c_str());
		el->InsertEndChild(title);

		root->InsertEndChild(el);
	}

	if (doc.SaveFile("Books.xml")==XML_SUCCESS)
	{
		std::cout << "library saved" << std::endl;
	}

	
}
