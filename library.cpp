#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool available=true;

public:
    void setTitle(string newTitle) {
        title = newTitle;
    }

    void setAuthor(string newAuthor) {
        author = newAuthor;
    }

    void setISBN(string newISBN) {
        isbn = newISBN;
    }

    void setAvailable(bool status) {
        available = status;
    }

    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    string getISBN() {
        return isbn;
    }

    string getAvailable() {
        return available ? "Available" : "Checked Out";
    }

    void borrowBook() {
        if (available) {
            setAvailable(false);
            cout << "Book successfully borrowed." << endl;
        } else {
            cout << "Sorry, the book is already checked out." << endl;
        }
    }

    void returnBook() {
        if (!available) {
            setAvailable(true);
            cout << "Book successfully returned." << endl;
        } else {
            cout << "Error: The book is already available." << endl;
        }
    }
};

void removebook(Book arr[], int &size, int element) {
    for (int i = element; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --size;
    cout << "Book has been removed." << endl;
};

int main() {
    const int MAX_CAPACITY = 100;
    Book lib[MAX_CAPACITY];
    int bookCount = 0;

    cout << "\nWelcome to the library management system!" << endl;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add more book" << endl;
        cout << "2. Show list of books" << endl;
        cout << "3. Remove book" << endl;
        cout << "4. Search for book" << endl;
        cout << "5. Borrow book" << endl;
        cout << "6. Return book" << endl;
        cout << "7. Exit" << endl;

        int choice, element;
        string tell,borrow,returnn;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if (choice == 1) {
            if (bookCount < MAX_CAPACITY) {
                string title, author, isbn;
                cout << "Enter the book's title: ";
                getline(cin, title);
                cout << "Enter the book's author: ";
                getline(cin, author);
                cout << "Enter the book's ISBN: ";
                getline(cin, isbn);
                lib[bookCount].setTitle(title);
                lib[bookCount].setAuthor(author);
                lib[bookCount].setISBN(isbn);
                bookCount++;
                cout << "Book successfully added." << endl;
            } else {
                cout << "Error: The library is full. Cannot add more books." << endl;
            }

        } else if(choice==2){
            cout << "Available books:" << endl;
            for (int i = 0; i < bookCount; i++) {
                cout << "S.No" << i + 1 << ". " << "TITLE OF BOOK-" << lib[i].getTitle() << "  AUTHOR OF BOOK-" << lib[i].getAuthor() << " ISBN NUMBER-" << lib[i].getISBN() << endl;
            }
        }else if (choice == 3) {
            if (bookCount > 0) {
                
                cout << "Choose the S.No you want to delete or remove: ";
                cin >> element;
                if (element >= 1 && element <= bookCount) {
                    removebook(lib, bookCount, element - 1);
                } else {
                    cout << "Invalid S.No. No book removed." << endl;
                }
            } else {
                cout << "No books available to remove." << endl;
            }

        } else if (choice == 4) {
            cout<<"If you want to find a book enter it's ISBN number: "<<endl;
            cin>>tell;
            bool found=false;
            for(int i=0; i<=bookCount;i++){
                if(tell==lib[i].getISBN()){
                    found = true;
                    cout << "Book found:" << endl;
                    cout << "Title: " << lib[i].getTitle() << endl;
                    cout << "Author: " << lib[i].getAuthor() << endl;
                    cout << "ISBN: " << lib[i].getISBN() << endl;
                    cout << "Availability: " << lib[i].getAvailable() << endl;
                    
                    break;
                }
            }
            if (!found) {
                cout << "Book not found in the library." << endl;
            }
        
        }else if(choice==5){
            cout<<"Enter ISBN number to borrow book"<<endl;
            cin>>borrow;
            bool found=false;
            for(int i=0;i<=bookCount;i++){
                if(borrow==lib[i].getISBN()){
                    found = true;
                    lib[i].borrowBook();   
                    break;
                }
            }
            if (!found){
                    cout<<"Book not found in library."<<endl;
                }
        } else if(choice==6){
            cout<<"Enter ISBN number to return book "<<endl;
            cin >> returnn;
            bool found = false;
            for (int i = 0; i < bookCount; ++i) {
                if (lib[i].getISBN() == returnn) {
                    found = true;
                    lib[i].returnBook();
                    break;
                }
            }
                if (!found) {
                cout << "Book not found in the library." << endl;
            }
        }else if (choice == 7) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;  
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
