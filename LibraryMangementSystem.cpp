

//LIBRARY MANAGMENT SYSTEM//

#include<iostream>
#include"LibraryMangementSystem.h"

using namespace std;


int main()
{
    LibraryManagementSystem Admin;
    Librarian newLibrarian= Admin.createLibrarian();
    newLibrarian.logIn();
    newLibrarian.VerifyLibrarian("vaneeza", 390, "vultomanio");
    LibraryDatabase LD;
    //Creating 10 books to be added by librarian
    Book books[10];
    for (int i = 0; i < 5; i++)
    {
        books[i].setTitle("Lord of Flies");
        books[i].setAuthor("waltt grey");
        books[i].setISBN("444778799");
    }

    for (int i = 5; i < 10; i++)
    {
        books[i].setTitle("The Nightingale");
        books[i].setAuthor("james thorne");
        books[i].setISBN("097409859");
    }

    Student S1, S2;
    Staff st1;
    for (int i = 0; i < 10; i++)
    {
        LD.Add(&books[i]);
    }

    if (newLibrarian.SearchBook("The Great Gatsby", "daled", "787", LD)==false)
    {
        cout << "\nThis book , The Great Gatsby cannot be issued.\n";
    }

    S2.issueBook("The Nightingale", "james thorne", "097409859");
    st1.issueBook("Lord of Flies", "waltt grey", "444778799");
    st1.issueBook("The Nightingale", "james thorne", "097409859");
    S1.returnBook(2);//number of books returned
    S2.returnBook(3);
    st1.returnBook(2);
    Admin.LogOut();
}
