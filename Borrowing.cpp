#include "Borrowing.hpp"

Borrowing::Borrowing(int id_member, int id_book) {
  this->id_book = id_book;
  this->id_member = id_member;
  time_t now = time(0);
  borrow_day = localtime(&now);
  returned = false;
}

void Borrowing::returnBook(vector<Book> &books) {
  returned = true;
  time_t now = time(0);
  return_day = localtime(&now);
  books.at(id_book).update(TrangThai::tra);
}

void Borrowing::show(vector<Book> books) {
  cout << "Tieu de: " << books.at(id_book).getTitle() << " | "
       << "Ngay muon: " << borrow_day->tm_mday << "/" << 1 + borrow_day->tm_mon
       << "/" << borrow_day->tm_year + 1900 << " " << borrow_day->tm_hour << ":"
       << borrow_day->tm_min << endl;
  if (returned) {
    cout << "Da tra! | "
         << "Ngay tra: " << return_day->tm_mday << "/" << 1 + return_day->tm_mon
         << "/" << return_day->tm_year + 1900 << " " << return_day->tm_hour
         << ":" << return_day->tm_min << endl;
  } else {
    cout << "Chua tra!" << endl;
  }
}