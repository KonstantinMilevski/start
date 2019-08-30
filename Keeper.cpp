#include "Keeper.h"

Keeper::Keeper(Librarian* lib)
{
	this->lib = lib;
}
std::string book_last_name = "Books_end.xml";  //"Books_end.xml"
std::string  book_first_name = "Books_end.xml";  //"Books_first.xml"

std::string reader_last_name = "Readers_end.xml";
std::string  reader_first_name = "Readers_first.xml";


std::string links_last_name = "Links_end.xml";



void Keeper::saveBookToXML()
{
	
	XMLDocument doc=new XMLDocument;
	XMLNode* root = doc.NewElement("Books");
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

	if (doc.SaveFile(book_last_name.c_str()) == XML_SUCCESS)
	{
		std::cout << "Books  saved:" << book_last_name << std::endl;
	}
	
}

void Keeper::readBookFromXML()
{
	

	XMLDocument doc = new XMLDocument;
	// add 
	if (!(doc.LoadFile(book_first_name.c_str()) == XML_SUCCESS))
	{
		std::cout << "Bad open " << book_first_name << std::endl;
		//throw - 1;
	}
	else
	{
		std::cout << "File open: " << book_first_name << std::endl;
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

void Keeper::saveReaderToXML()
{
	XMLDocument doc = new XMLDocument;
	XMLNode* root = doc.NewElement("Readers");
	doc.InsertFirstChild(root);

	for (const auto& item : lib->allReaders)
	{
		XMLElement* el = doc.NewElement("Reader");
		//el->SetAttribute("All books", "5");
		XMLElement* id = doc.NewElement("Id");
		id->SetText(item->getId().c_str());
		el->InsertEndChild(id);

		XMLElement* auther = doc.NewElement("name");
		auther->SetText(item->getName().c_str());
		el->InsertEndChild(auther);

		XMLElement* title = doc.NewElement("surname");
		title->SetText(item->getSurname().c_str());
		el->InsertEndChild(title);

		root->InsertEndChild(el);
	}
	if (doc.SaveFile(reader_last_name.c_str()) == XML_SUCCESS)
	{
		std::cout << "Readers  saved:" << reader_last_name << std::endl;
	}
}

void Keeper::readReaderFromXML()
{

	XMLDocument doc = new XMLDocument;
	// add 
	if (!(doc.LoadFile(reader_first_name.c_str()) == XML_SUCCESS))
	{
		std::cout << "Bad open " << reader_first_name << std::endl;
		//throw - 1;
	}
	else
	{
		std::cout << "File open: " << reader_first_name << std::endl;
		XMLNode* root = doc.FirstChildElement();
		if (root == nullptr)
			throw - 1;
		XMLElement* reader = root->FirstChildElement();//"Reader"
		while (reader)
		{
			XMLElement* id = reader->FirstChildElement(); //"Id"
			//std::cout << id->GetText() << std::endl;
			XMLElement* name = id->NextSiblingElement();
			//std::cout << auther->GetText() << std::endl;
			XMLElement* surname = name->NextSiblingElement();
			//std::cout << title->GetText() << std::endl;
			Reader temp;
			temp.setReader(id->GetText(), name->GetText(), surname->GetText());
			auto tmp = std::unique_ptr<Reader>(new Reader(temp));
			this->lib->allReaders.push_back(std::move(tmp));
			reader = reader->NextSiblingElement();
		}
	}
}

void Keeper::saveSingleBookToXML(Book& book)
{
	XMLDocument doc = new XMLDocument;
	doc.LoadFile(book_last_name.c_str());

	XMLNode* root = doc.FirstChildElement("Books");
	if (root)
	{
		doc.InsertFirstChild(root);
		XMLElement* el = doc.NewElement("Book");
		XMLElement* id = doc.NewElement("Id");
		id->SetText(book.getId().c_str());
		el->InsertEndChild(id);

		XMLElement* auther = doc.NewElement("auther");
		auther->SetText(book.getAuther().c_str());
		el->InsertEndChild(auther);

		XMLElement* title = doc.NewElement("title");
		title->SetText(book.getTitle().c_str());
		el->InsertEndChild(title);

		root->InsertEndChild(el);
	}
	else
	{
		XMLNode* root = doc.NewElement("Books");
		doc.InsertFirstChild(root);
		
		XMLElement* el = doc.NewElement("Book");
		XMLElement* id = doc.NewElement("Id");
		id->SetText(book.getId().c_str());
		el->InsertEndChild(id);

		XMLElement* auther = doc.NewElement("auther");
		auther->SetText(book.getAuther().c_str());
		el->InsertEndChild(auther);

		XMLElement* title = doc.NewElement("title");
		title->SetText(book.getTitle().c_str());
		el->InsertEndChild(title);

		root->InsertEndChild(el);
	}

	if (doc.SaveFile(book_last_name.c_str()) == XML_SUCCESS)
	{
		std::cout << "Books  saved:" << std::endl;
	}
}

void Keeper::delBookFromXML(const std::string& compare)
{
	
	XMLDocument doc = new XMLDocument;
	doc.LoadFile(book_last_name.c_str());
	if (doc.Error())
		return;
	XMLNode* root = doc.FirstChildElement();
	XMLElement* el;
	for (el = root->FirstChildElement(); el; el = el->NextSiblingElement())
	{
		if (compare == el->FirstChild()->FirstChild()->Value())
		{
			root->DeleteChild(el);
			break;
		}
	}
	if (doc.SaveFile(book_last_name.c_str()) == XML_SUCCESS)
	{
		std::cout << "Book remove. Books  saved:" << book_last_name << std::endl;
	}

}

void Keeper::saveGivenBookToXML(const std::multimap<Reader_iter, Book_iter>& givenBook)
{
	XMLDocument doc = new XMLDocument;
	XMLNode* root = doc.NewElement("GivenBooks");
	doc.InsertFirstChild(root);

	
	for (auto it = givenBook.begin(); it != givenBook.end(); ++it)
	{
		XMLElement* el = doc.NewElement("Link");
		//el->SetAttribute("All books", "5");
		XMLElement* readerId = doc.NewElement("ReaderId");
		readerId->SetText((*(it->first))->getId().c_str());
		el->InsertEndChild(readerId);

		XMLElement* bookId = doc.NewElement("BookId");
		bookId->SetText((*(it->second))->getId().c_str());
		el->InsertEndChild(bookId);
			   
		root->InsertEndChild(el);
	}

	
	if (doc.SaveFile(links_last_name.c_str()) == XML_SUCCESS)
	{
		std::cout << "Links  saved:" << links_last_name << std::endl;
	}
}

std::multimap<std::string, std::string> Keeper::readGivenBookfromXML()
{
	std::multimap<std::string, std::string> givenBooks;
	XMLDocument doc = new XMLDocument;
	doc.LoadFile(links_last_name.c_str());
	if (!doc.Error())
	{
		XMLNode* root = doc.FirstChildElement();

		for (auto link = root->FirstChildElement(); link; link = link->NextSiblingElement())
		{
			std::cout << link->FirstChild()->FirstChild()->Value() << std::endl;
			std::cout << link->FirstChild()->NextSiblingElement()->FirstChild()->Value() << std::endl;
			givenBooks.emplace(link->FirstChild()->FirstChild()->Value(), link->FirstChild()->NextSiblingElement()->FirstChild()->Value());

		}
		return givenBooks;
	}
}


