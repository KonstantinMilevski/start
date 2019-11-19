#include "book.h"
#include "librarian.h"
#include "reader.h"
#include <iostream>

#include "keeper.h"
#include "menu.h"

// check sole ID

int main()
{
    Librarian                               l;
    Menu                                    m(&l);
    Keeper                                  k(&l);
    std::multimap<Reader_iter, Book_iter>   givenB;
    std::multimap<std::string, std::string> ms = k.readGivenBookfromXML();
    std::string                             s;

    k.readBookFromXML();
    k.readReaderFromXML();

    givenB = l.restoreLinks(ms);

    unsigned int choice;
    do
    {
        choice = m.menu();
        switch (choice)
        {
            case 0:
                break;
            case 1:
            {
                Book temp = l.createBook(std::cin);
                l.addSingleBook(temp);
                k.saveSingleBookToXML(temp);
            }
            break;
            case 2:

                break;
            case 3:
                l.showBooks();
                break;
            case 4:
                l.showFoundBooks();
                break;
            case 5:
                l.showReaders();
                break;
            case 6:
            {
                l.giveBook(givenB);
                k.saveGivenBookToXML(givenB);
            }
            break;
            case 7:
                l.showGivenBooks(givenB);
                break;
            case 8:

                break;
            case 9:
            {
                l.returnBook(givenB);
                k.saveGivenBookToXML(givenB);
            }
            break;
            case 10:
                break;
            case 11:
            {
                l.delBook(s);
                k.delBookFromXML(s);
            }
            break;
            default:
                std::cout << "Try again";
        }
    } while (choice != 0);
    return 0;
}
