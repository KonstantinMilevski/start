#pragma once
#include "librarian.h"

class Menu : public Librarian
{
public:
    Menu(Librarian*);

    unsigned int menu();

private:
    Librarian* lib;
};
