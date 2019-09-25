#include "Keeper.h"

Keeper::Keeper(Librarian* lib)
{
	this->lib = lib;
}
std::string book_last_name = "Books.xml";  
std::string reader_last_name = "Readers.xml";
std::string links_last_name = "Links.xml";

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
	
	if (!(doc.LoadFile(book_last_name.c_str()) == XML_SUCCESS))
	{
		std::cout << "Fail open " << book_last_name << std::endl;
		return;
	}
	else
	{
		XMLNode* root = doc.FirstChildElement();
		if (root == nullptr)
		{
			std::cout << "Can't reading or empty: " << reader_last_name << std::endl;
			return;
		}
		XMLElement* book = root->FirstChildElement();
		while (book)
		{
			XMLElement* id = book->FirstChildElement(); 
			XMLElement* auther = id->NextSiblingElement();
			XMLElement* title = auther->NextSiblingElement();
			Book temp(id->GetText(), auther->GetText(), title->GetText());;
			auto tmpUnique = std::make_unique<Book>(temp);
			this->lib->allBooks.push_back(std::move(tmpUnique));
			book = book->NextSiblingElement();
		}
	}
}

void Keeper::saveSingleBookToXML(const Book& book)
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
	if (!(doc.LoadFile(reader_last_name.c_str()) == XML_SUCCESS))
	{
		std::cout << "Fail open " << reader_last_name << std::endl;
		return;
	}
	else
	{
		XMLNode* root = doc.FirstChildElement();
		if (root == nullptr)
		{
			std::cout << "Can't reading or empty: " << reader_last_name << std::endl;
			return;
		}
			
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

void Keeper::saveSingleReaderToXML(Reader& reader)
{
	XMLDocument doc = new XMLDocument;
	if (!(doc.LoadFile(reader_last_name.c_str()) == XML_SUCCESS))
	{
		std::cout << "Bad open " << reader_last_name << std::endl;
		return;
	}

	XMLNode* root = doc.FirstChildElement("Readers");
	if (root)
	{
		doc.InsertFirstChild(root);
		XMLElement* el = doc.NewElement("Reader");
		XMLElement* id = doc.NewElement("Id");
		id->SetText(reader.getId().c_str());
		el->InsertEndChild(id);

		XMLElement* name = doc.NewElement("name");
		name->SetText(reader.getName().c_str());
		el->InsertEndChild(name);

		XMLElement* surname = doc.NewElement("surname");
		surname->SetText(reader.getSurname().c_str());
		el->InsertEndChild(surname);

		root->InsertEndChild(el);
	}
	else
	{
		XMLNode* root = doc.NewElement("Readers");
		doc.InsertFirstChild(root);

		XMLElement* el = doc.NewElement("Reader");
		XMLElement* id = doc.NewElement("Id");
		id->SetText(reader.getId().c_str());
		el->InsertEndChild(id);

		XMLElement* name = doc.NewElement("name");
		name->SetText(reader.getName().c_str());
		el->InsertEndChild(name);

		XMLElement* surname = doc.NewElement("surname");
		surname->SetText(reader.getSurname().c_str());
		el->InsertEndChild(surname);

		root->InsertEndChild(el);
	}

	if (doc.SaveFile(reader_last_name.c_str()) == XML_SUCCESS)
	{
		std::cout << "Readers  saved:" << std::endl;
	}
}

void Keeper::delReaderFromXML(const std::string& compare)
{
	XMLDocument doc = new XMLDocument;
	doc.LoadFile(reader_last_name.c_str());
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
	if (doc.SaveFile(reader_last_name.c_str()) == XML_SUCCESS)
	{
		std::cout << "Reader remove. Change  saved:" << book_last_name << std::endl;
	}
}

void Keeper::saveGivenBookToXML(const std::map<Book_vect_iter, Reader_vect_iter>& givenBooks)
{
	XMLDocument doc = new XMLDocument;
	XMLNode* root = doc.NewElement("GivenBooks");
		
		for (auto itPair = givenBooks.cbegin(); itPair != givenBooks.cend(); ++itPair)
		{
			XMLElement* el = doc.NewElement("Link");
			XMLElement* readerId = doc.NewElement("BookId");
			readerId->SetText((*(itPair->first))->getId().c_str());
			el->InsertEndChild(readerId);

			XMLElement* bookId = doc.NewElement("ReaderId");
			bookId->SetText((*(itPair->second))->getId().c_str());
			el->InsertEndChild(bookId);

			root->InsertEndChild(el);
		}
		doc.InsertEndChild(root);
	if (doc.SaveFile(links_last_name.c_str()) == XML_SUCCESS)
	{
		std::cout << "Links  saved:" << links_last_name << std::endl;
	}
}

std::map<std::string, std::string> Keeper::readGivenBookfromXML()
{
	std::map<std::string, std::string> mapStringId;
	XMLDocument doc = new XMLDocument;
	doc.LoadFile(links_last_name.c_str());
	if (!doc.Error())
	{
		XMLNode* root = doc.FirstChildElement();
		for (auto link = root->FirstChildElement(); link; link = link->NextSiblingElement())
		{
			
			mapStringId.emplace(link->FirstChild()->FirstChild()->Value(),
								link->FirstChild()->NextSiblingElement()->FirstChild()->Value());
		}
		
	}
	else
	{
		std::cout << "Can't read links." << links_last_name << std::endl;
	}
	/*if (mapStringId.empty())
		throw std::exception("Links are empty");*/
	return mapStringId;
}


