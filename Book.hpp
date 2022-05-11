#pragma once
#include "includes.hpp"

class Book {
private:
  int id, quantity;
  char title[MAX_LENG], author[MAX_LENG];

public:
  Book(int);
  Book();

  int getId() { return id; }
  int getQuantity() { return quantity; }
  string getTitle() { return string(title); }
  string getAuthor() { return string(author); }

  void ghi(ofstream &);
  void doc(ifstream &);

  bool update(TrangThai);

  friend void chuanhoaIdBook(vector<Book> &);

  friend istream &operator>>(istream &i, Book &b) {
    cout << "Title: ";
    i.getline(b.title, MAX_LENG);
    cout << "Author: ";
    i.getline(b.author, MAX_LENG);
    cout << "Quantity: ";
    cin >> b.quantity;
    getchar();
    return i;
  }

  friend ostream &operator<<(ostream &o, Book &b) {
    o << "\nID: " << b.id << endl
      << "Title: " << b.title << "\n"
      << "Author: " << b.author << "\n"
      << "Quantity: " << b.quantity << "\n";
    return o;
  }
};
