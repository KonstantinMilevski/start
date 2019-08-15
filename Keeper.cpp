#include "Keeper.h"

Keeper::Keeper(Librarian* lib)
{
	this->lib = lib;
}
std::string last_name = "Books_end.xml";
std::string first_name = "Books_first.xml";

void Keeper::saveBookToXML()
{
	
	XMLDocument doc=new XMLDocument;
	XMLNode* root = doc.NewElement("Book");
	doc.InsertFirstChild(root);

	for (const auto& item : lib->allBooks )
	{
		XMLElement* el = doc.NewElement("Book");
		//el->SetAttribute("All books", "5");
		XMLElement* id = doc.NewElement("Id");
		id->SetText(item->getId().c_str());
		el->InsertEndChild(id);

		XMLElement* auther = doc.NewElement("auther");
		auther->SetText(item->getAuther() .c_str());
		el->InsertEndChild(auther);

		XMLElement* title = doc.NewElement("title");
		title->SetText(item->getTitle().c_str());
		el->InsertEndChild(title);

		root->InsertEndChild(el);
	}

	if (doc.SaveFile(last_name.c_str()) == XML_SUCCESS)
	{
		std::cout << "Books  saved:" <<last_name << std::endl;
	}
	
}

void Keeper::readBookFromXML()
{
	

	XMLDocument doc = new XMLDocument;
	// add 
	if (!(doc.LoadFile(first_name.c_str()) == XML_SUCCESS))
	{
		std::cout << "Bad open " << first_name << std::endl;
		//throw - 1;
	}
	else
	{
		std::cout << "File open: " << first_name << std::endl;
		XMLNode* root = doc.FirstChildElement();
		if (root == nullptr)
			throw - 1;
		XMLElement* book = root->FirstChildElement();//"Book"
		while (book)
		{
			XMLElement* id = book->FirstChildElement(); //"Id"
			//std::cout << id->GetText() << std::endl;
			XMLElement* auther = id->NextSiblingElement();
			//std::cout << auther->GetText() << std::endl;
			XMLElement* title = auther->NextSiblingElement();
			//std::cout << title->GetText() << std::endl;
			Book temp;
			temp.setBook(id->GetText(), auther->GetText(), title->GetText());
			auto tmp = std::unique_ptr<Book>(new Book(temp));
			this->lib->allBooks.push_back(std::move(tmp));
			book = book->NextSiblingElement();
		}
	}
}
