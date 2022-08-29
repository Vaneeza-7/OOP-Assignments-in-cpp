

//LIBRARY MANAGMENT SYSTEM//

#pragma once

#include<iostream>
#include<ctime>
using namespace std;

class Page
{
	string Text;
	int Page_no;

public:
	Page()
	{
		Text = '\0';
		Page_no = 0;
	}

	Page(string txt, int pgNo)
	{
		Text=txt;
		Page_no = pgNo;
	}

	void setText(string txt)
	{
		Text = txt;
	}

	void setPageNo(int pgNo)
	{
		Page_no = pgNo;
	}

	string getText()
	{
		return Text;
	}

	int getPageNo()
	{
		return Page_no;
	}
};


class Book
{
	string Title, Author, ISBN;
	Page page;
public:
	Book()
	{
		Title = "Undefined";
		Author = "Undefined";
		ISBN = "Undefined";
		page.setText("Preface");
		page.setPageNo(1);
	}

	Book(string t, string a, string isbn, string txt, int pgno)
	{
		Title = t;
		Author = a;
		ISBN = isbn;
		page.setText(txt);
		page.setPageNo(pgno);
	}

	Book(string t, string a, string isbn)
	{
		Title = t;
		Author = a;
		ISBN = isbn;
	}

	void setTitle(string title)
	{
		Title = title;
	}

	void setAuthor(string author)
	{
		Author = author;
	}

	void setISBN(string isbn)
	{
		ISBN = isbn;
	}

	string getTitle()
	{
		return Title;
	}

	string getAuthor()
	{
		return Author;
	}

	string getISBN()
	{
		return ISBN;
	}

	/*void Show_due_date()
	{	
		char ans;
		cout << "Are you a student? (y/n) ";
		cin >> ans;
		if (ans == 'y')
		{
			time_t now = time(0) + (86400 * 14);
			char* dt = ctime(&now);
			cout << "Due date is " << dt << endl;
		}

		else
		{
			time_t now = time(0) + (86400 * 112);
			char* dt = ctime(&now);
			cout << "Due date is " << dt << endl;
		}
	}*/

	/*void Reservation_status()
	{
		if()
	}*/

};

class LibraryDatabase
{
	Book* List_of_books;
	//Account* List_of_accounts;

public:
	LibraryDatabase()
	{
		cout << " \n";
	}

	void setListofBooks(Book* book)
	{
		List_of_books = book;
	}

	Book* getListofBooks()
	{
		return this->List_of_books;
	}

	void Add(Book* book)
	{
		List_of_books = book;
		cout << book->getTitle() << " has been added to database.\n";
	}

	void Delete(Book* book)
	{
		if (List_of_books == book)
		{
			cout << book->getTitle() << " has been deleted.\n";
		}
	}

	bool Search(Book* book)
	{
		if (List_of_books == book)
			return true;
		else
			return false;
	}

	/*void Update()
	{
		if()
	}*/


};


class Librarian
{
	string Name;
	int ID;
	string Password;
	LibraryDatabase* DBbooks;

public:
	Librarian()
	{
		Name = "Bibliophile";
		ID = 0;
		Password = "\0";
	}

	Librarian(string name, int id, string pswd)
	{
		Name = name;
		ID = id;
		Password = pswd;
	}

	void setName(string n)
	{
		Name = n;
	}

	void setID(int id)
	{
		ID = id;
	}

	void setPassword(string pswd)
	{
		Password = pswd;
	}

	string getName()
	{
		return Name;
	}

	int getID()
	{
		return ID;
	}

	string getPassword()
	{
		return Password;
	}

	bool VerifyLibrarian(string name, int id, string pswd)
	{
		bool flag = true;

		if (name != Name || pswd!=Password)
		{
			cout << "Verification Failed. " << name << " is not a verified Librarian.\n";
			flag = false;
		}

		else
			cout << "Verification Successful. " << name << " is a verified Librarian.\n";

		return flag;
	}

	bool logIn()
	{
		string a, b;
		cout << "Enter UserName: ";
		cin >> a;
		setName(a);
		cout << "Enter Password: ";
		cin >> b;
		setPassword(b);
		return true;
	}


	bool SearchBook(string bookname, string Author, string ISBN, LibraryDatabase& DBbooks)
	{
		Book B1(bookname, Author, ISBN);
		bool found = false;
		for (int i = 0; i < 10; i++)
		{
			if (DBbooks.Search(&B1) == true)
				found = true;
		}
		if (found == false)
		{
			cout << "Book not found.";
		}

		return found;
	}
};

class Account
{
	int no_borrowed_books, no_lost_books, no_reserved_books;
	float fine_amount;
public:
	Account()
	{
		no_borrowed_books = 0;
		no_lost_books = 0;
		no_reserved_books = 0;
		fine_amount = 0;
	}

	Account(int borrow, int lost, int reserv, float fine)
	{
		no_borrowed_books = borrow;
		no_lost_books = lost;
		no_reserved_books = reserv;
		fine_amount = fine;
	}

	void set_borrowed_books(int borrow)
	{
		no_borrowed_books = borrow;
	}

	void set_lost_books(int lost)
	{
		no_lost_books = lost;
	}

	void set_reserved_books(int reserv)
	{
		no_reserved_books = reserv;
	}

	void set_fine_amount(float fine)
	{
		fine_amount = fine;
	}

	int get_borrowed_books()
	{
		return no_borrowed_books;
	}

	int get_lost_books()
	{
		return no_lost_books;
	}

	int get_reserved_books()
	{
		return no_reserved_books;
	}

	float get_fine_amount()
	{
		return fine_amount;
	}

	float Calculate_fine()
	{

	}

};

class User
{
protected:
	string Name;
	int ID;
	Account account;
	int numOfbooksIssued=0;

public:
	User()
	{
		Name = "User";
		ID = 0;
		account.set_reserved_books(0);
		account.set_borrowed_books(0);
		account.set_lost_books(0);
		account.set_fine_amount(0);
	}

	User(string name, int id, int borrow, int lost, int reserv, float fine)
	{
		account.set_borrowed_books(borrow);
		account.set_lost_books(lost);
		account.set_reserved_books(reserv);
		account.set_fine_amount(fine);
		Name = name;
		ID = id;
	}

	void setName(string name)
	{
		Name = name;
	}

	void setID(int id)
	{
		ID = id;
	}

	string getName()
	{
		return Name;
	}

	int getID()
	{
		return ID;
	}

	bool Verify(string name, int id)
	{
		bool flag = true;

		if (name != Name)
		{
			cout <<"Verification Failed. "<< name << " is not a verified user.\n";
			flag = false;
		}

		else
			cout << "Verification Successful. " << name << " is a verified user.\n";

		return flag;
	}

	void Check_Account()
	{
		cout << "Checking account for " << Name << endl;
		cout << "No. of borrowed books are " << account.get_borrowed_books() << endl;
		cout << "No. of lost books are " << account.get_lost_books() << endl;
		cout << "No. of reserved books are " << account.get_reserved_books() << endl;
		cout << "The fine amount due is " << account.get_fine_amount() << endl;
	}

	//void get_book_info()
	//{
	//	cout << "The book title is " << getTitle() << endl;

	//}

	virtual void issueBook(string bookName, string auth, string isbn)
	{
		
				numOfbooksIssued++;
			account.set_borrowed_books(numOfbooksIssued);
			cout << bookName << " book has been issued to you.\n";
	}

	void returnBook(int num)
	{
		int issuedBooks = account.get_borrowed_books();
		cout << num << " books returned.\n";
	}
};


class Student :public User
{
	string Batch, Designation;
public:
	Student()
	{
		Batch = "2021";
		Designation = "Student";
		cout << "Student has been created of batch "<<Batch<<endl;
	}

	Student(string batch, string desig)
	{
		Batch = batch;
		Designation = desig;
	}

	void setBatch(string batch)
	{
		Batch = batch;
	}

	void setDesignation(string desig)
	{
		Designation = desig;
	}

	string getDesignation()
	{
		return Designation;
	}

	string getBatch()
	{
		return Batch;
	}
};

class Staff :public User
{
	string Dept, Designation;
public:
	Staff()
	{
		Dept = "CS";
		Designation = "Student";
		cout << "Staff member created of department " << Dept<<endl;
	}

	Staff(string dept, string desig)
	{
		Dept = dept;
		Designation = desig;
	}

	void setDept(string dept)
	{
		Dept = dept;
	}

	void setDesignation(string desig)
	{
		Designation = desig;
	}

	string getDesignation()
	{
		return Designation;
	}

	string getDept()
	{
		return Dept;
	}
};







class LibraryManagementSystem
{
	int UserType;
	string UserName;
	string Password;
	Librarian librarian;
	Book book;
	User user;

public:
	LibraryManagementSystem(int usType, string usName, string pswd, Librarian lib, Book bk, User usr)
	{
		UserType = usType;
		UserName = usName;
		Password = pswd;

		string libName = lib.getName();
		librarian.setName(libName);
		int Id = lib.getID();
		librarian.setID(Id);
		string pwd = lib.getPassword();
		librarian.setPassword(pwd);

		string tiTle = bk.getTitle();
		book.setTitle(tiTle);
		string auth = bk.getAuthor();
		book.setAuthor(auth);
		string IsbN = bk.getISBN();
		book.setISBN(IsbN);

		string name = usr.getName();
		user.setName(name);
		int iD = usr.getID();
		user.setID(iD);

	}

	LibraryManagementSystem()
	{
		UserType = 1;
		UserName = "Curator";
		Password = "@library";

		librarian.setName("Bibliophile");
		librarian.setID(0);
		librarian.setPassword("\0");

		book.setTitle("undefined");
		book.setAuthor("undefined");
		book.setISBN("undefined");

		user.setName("User");
		user.setID(0);
	}

	Librarian getLibrarian()
	{
		Librarian L1;
		string libName = librarian.getName();
		L1.setName(libName);
		int Id = librarian.getID();
		L1.setID(Id);
		string pwd = librarian.getPassword();
		L1.setPassword(pwd);

		return L1;
	}

	void setUserType(int usType)
	{
		UserType = usType;
	}

	void setUserName(string UsName)
	{
		UserName = UsName;
	}

	void setPassword(string pswd)
	{
		Password = pswd;
	}

	int getUserType()
	{
		return UserType;
	}

	string getUserName()
	{
		return UserName;
	}

	string getPassword()
	{
		return Password;
	}

	bool logIn()
	{
		string a, b;
		cout << "Enter UserName: ";
		cin >> a;
		cout << "Enter Password: ";
		cin >> b;
		librarian.setName(a);
		librarian.setPassword(b);
		cout << "";
		return true;
	}

	bool Register()
	{
		string a, b;
		cout << "Enter UserName: ";
		cin >> a;
		librarian.setName(a);
		cout << "Enter Password: ";
		cin >> b;
		librarian.setPassword(b);
		cout << "";
		return true;
	}

	bool LogOut()
	{
		char ch;
		cout << "Do you want to log out? ";
		cin >> ch;
		switch (ch)
		{
		case'y':
			cout << "You have been successfully logged out.\n";
			return true;
		case'n':
			cout << "You have not logged out. \n";
			return false;
		}
	}

	Librarian createLibrarian()
	{
		Librarian L1;
		return L1;
	}
};