#include "menu.h"

Menu::Menu(Librarian* lib)
{
    this->lib = lib;
}

unsigned int Menu::menu()
{

    unsigned int choice;
    std::cout << std::endl;
    std::cout << "*************************************************************"
                 "*******\n";
    std::cout << "0. Exit\n";
    std::cout << "1. Add book\n";     //+
    std::cout << "2. Add reader\n";   //+
    std::cout << "3. Show books\n";   //+
    std::cout << "4. Find_book\n";    //+
    std::cout << "5. Show readers\n"; //+
    std::cout << "6. Give a book\n";  // check empty enter
    std::cout << "7. Show given books\n";
    std::cout << "8. *****Restore*******\n"; // Find reader with books
    std::cout << "9. Return book from reader\n";
    std::cout << "10. Remove reader\n";
    std::cout << "11. Remove book\n"; //+

    std::cout << "*************************************************************"
                 "*******\n";

    std::cout << "\n Choose position: ";
    while (!(std::cin >> choice))
    {
        std::cin.clear();
        std::cin.ignore(UINT_MAX, '\n');
        std::cout << "Wrong. Try again. Or '0' to exit." << std::endl;
    }
    std::cin.ignore(UINT_MAX, '\n');
    return choice;
}
