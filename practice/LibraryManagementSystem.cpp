#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;


class Book {
private:
    string name ;
    string isbn ;
    bool available=true;
public:
    Book(const string& n ,const string& isbn ) : name(n) , isbn(isbn) {}

    string getISBN() const {
        return isbn;
    }

    bool isAvailable() const {
        return available;
    }

    bool borrowBook(){
        if(available) {
            available = false;
            return true;
        }
        return false;
    }

    bool returnBook() {
        if (!available) {
            available = true;
            return true;
        }
        return false;
    }

    void display()
    {
        cout << "name: " << name << endl; 
        cout << "isbn: " << isbn << endl;
        cout <<  boolalpha << "AVAILABLE: " << available << endl;
        cout << endl; 
    }
};


class Member {
private:
    int memberId;
    string name;
    vector<Book*> borrowedBooks;
public:
    Member(int id, const string& name)
        : memberId(id), name(name) {}

    bool borrowBook(Book& book)
    {
        if(book.borrowBook())
        {
            borrowedBooks.push_back(&book);
            return true;
        }
        return false;
    }

    // TODO 2
    bool returnBook(Book& book)
    {
        for(auto it = borrowedBooks.begin() ; it != borrowedBooks.end() ; it++)
        {
            if(*it == &book)
            {
                if(book.returnBook())
                {
                    borrowedBooks.erase(it) ;
                    return true ;
                }
            }
        }
        return false;
    }

    // TODO 3
    void displayBorrowedBooks() const
    {
        if (borrowedBooks.empty()) {
            cout << "No books borrowed.\n";
            return;
        }
        for(auto it : borrowedBooks)
        {
            it->display();
        }
    }
};


int main() {
    Book b("Operating Systems", "ISBN001");
    Book b2("Operating Systems", "ISBN002");

    Member m = Member(12 , "abhishek");
    m.borrowBook(b);
    m.borrowBook(b2);

    m.displayBorrowedBooks();
}