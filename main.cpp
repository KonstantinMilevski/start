﻿#include <iostream>
#include "Book.h"
#include"Reader.h"
#include "Librarian.h"

#include "Keeper.h"



int main()
{
	Librarian l;
	
	Keeper k(&l);
	k.readBookFromXML();
	//k.readReaderFromXML();
	
	//Book temp=l.createBook(std::cin);
	//l.addSingleBook(temp);
	//k.saveSingleBookToXML(temp);

	//l.showReaders();
	l.showBooks();
	std::string s;
	//l.delBook(s);
	//k.delBookFromXML(s);
	l.showBooks();
	//k.saveReaderToXML();
	//l.giveBook();
	//l.giveBook();
	//k.saveBookToXML();
	//k.saveGivenBookToXML(l.giveBook());
	
	
}
