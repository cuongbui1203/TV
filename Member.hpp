#pragma once
#include "includes.hpp"
#include "Borrowing.hpp"

class Member {
private:
  int id;
  char name[MAX_LENG];
  vector<Borrowing> borrows;

  void borrowBook2(vector<Book> &);

public:
  Member(int);
  Member();

  int getId() { return id; }
  string getName() { return string(name); }
  vector<Borrowing> getBorrows() { return borrows; }

  void doc(ifstream &);
  void ghi(ofstream &);

  void borrowBook(vector<Book> &);
  void returnedBook(vector<Book> &);
  void returnedBook(vector<Book> &, string);

  friend istream &operator>>(istream &is, Member &menber) {
    cout << "Nhap ten nguoi dung: ";
    is.getline(menber.name, MAX_LENG);
    return is;
  }
  friend ostream &operator<<(ostream &out, Member &menber) {
    out << "ID: " << menber.id << endl;
    out << "Name: " << menber.name << endl;
    return out;
  }
};
