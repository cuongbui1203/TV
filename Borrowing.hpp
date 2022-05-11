#pragma once
#include "includes.hpp"
#include "Book.hpp"

class Borrowing {
private:
  int id_member, id_book;
  tm *borrow_day, *return_day;
  bool returned;

public:
  Borrowing(int, int);

  bool isReturned() { return returned; }

  void returnBook(vector<Book> &);
  void show(vector<Book>);
};
