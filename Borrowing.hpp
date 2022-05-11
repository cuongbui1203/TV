#pragma once
#include "includes.hpp"
#include "Book.hpp"

class Borrowing {
private:
  int id_member, id_book;
  time_t borrow_day_, return_day_;
  bool returned;

public:
  Borrowing(int, int);
  Borrowing() {}

  void ghi(ofstream &);
  void doc(ifstream &);

  bool isReturned() { return returned; }
  int getIdBook() { return id_book; }

  void returnBook(vector<Book> &);
  void show(vector<Book>);
};
