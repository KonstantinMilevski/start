#include "Truck.h"

Truck::Truck(Librarian* lib) {	this->lib = lib;}

void Truck::SaveFileXML()
{
	tinyxml2::XMLDocument doc;
	XMLDocument xDoc = new XMLDocument();
	//XMLDeclaration* decl = new XMLDeclaration ("1.0", "", "");
	XMLNode* root = doc.NewElement("Books");
	xDoc.LinkEndChild(root);

	doc.InsertFirstChild(root);
	XMLElement* element = doc.NewElement("****Booook");
	element->SetText(10);
	element->SetAttribute("day", 26);
	element->InsertEndChild(root);
	for (const auto& book : lib->allBooks)
	{
		XMLElement* el = doc.NewElement("Book");
		XMLElement* id = doc.NewElement("Id");
		id->SetText(book->getId().c_str());
		id->InsertEndChild(el);
		XMLElement* auther = doc.NewElement("auther");
		auther->SetText(book->getId().c_str());
		auther->InsertEndChild(el);
		XMLElement* title = doc.NewElement("title");
		title->SetText(book->getId().c_str());
		title->InsertEndChild(el);
		el->InsertEndChild(root);
	}

	XMLError eResult = doc.SaveFile("Books.xml");
	///XMLCheckResult(eResult);

}
