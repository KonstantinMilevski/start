#pragma once
#include "Librarian.h"
#include <vector>
#include "tinyxml2.h"
#include <string>
#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif
using namespace tinyxml2;

class Truck
{
public:
	Truck() {};
	explicit Truck(Librarian* );

	void SaveFileXML();
	void LoadFileXML();

private:
	Librarian* lib=nullptr;
};

