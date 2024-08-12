/*
    create a bookshelf in cpp in which everytime you remove a book from the
   middle and display the bookshelf again, also enter the middle book into a
   seperate bookshelf. repeat the process atleast twice.
*/
#include <iostream>
#include <vector>

using namespace std;

class Book {
 private:
  string title;
  string author;

 public:
  Book() {}
  Book(string title, string author) : title(title), author(author) {}
  void display() {
    cout << "Title: " << title << "\t|\tAuthor: " << author << endl;
  }
};

int main() {
  int n;
  cout << "Enter number of books: ";
  cin >> n;

  vector<Book> bookshelf1;
  vector<Book> bookshelf2;

  for (int i = 0; i < n; i++) {
    string title;
    string author;
    cout << "Enter details of book " << i + 1 << endl;
    cout << "\ttitle: ";
    cin >> title;
    cout << "\tauthor: ";
    cin >> author;
    bookshelf1.push_back(Book(title, author));
    // bookshelf1.push_back(Book("Title" + to_string(i), "Author" +
    // to_string(i)));
  }

  cout << "Enter number of iteration to remove from middle: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    if (bookshelf1.size()) {
      int mid = bookshelf1.size() / 2;
      Book transfer = bookshelf1[mid];
      bookshelf1.erase(bookshelf1.begin() + mid);
      bookshelf2.push_back(transfer);
    } else {
      cout << "Bookshelf1 Underflowed" << endl;
    }
  }

  cout << "Bookshelf 1" << endl;
  for (Book book : bookshelf1) {
    book.display();
  }
  if (bookshelf1.empty()) {
    cout << "Empty" << endl;
  }
  cout << "Bookshelf 2" << endl;
  for (Book book : bookshelf2) {
    book.display();
  }
  if (bookshelf2.empty()) {
    cout << "Empty" << endl;
  }

  cout << "Yash Gupta\t23BCS11317" << endl;

  return 0;
}