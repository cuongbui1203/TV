#include "Borrowing.hpp"

Borrowing::Borrowing(int id_member, int id_book) {
  this->id_book = id_book;
  this->id_member = id_member;
  borrow_day_ = time(0);
  returned = false;
}

void Borrowing::returnBook(vector<Book> &books) {
  if (returned)
    return;
  returned = true;
  return_day_ = time(0);
  books.at(id_book).update(TrangThai::tra);
}

void Borrowing::show(vector<Book> books) {

  tm *borrow_day = localtime(&borrow_day_);
  cout << "Tieu de: " << books.at(id_book).getTitle() << " | "
       << "Ngay muon: " << borrow_day->tm_mday << "/" << 1 + borrow_day->tm_mon
       << "/" << borrow_day->tm_year + 1900 << " " << borrow_day->tm_hour << ":"
       << borrow_day->tm_min << endl;
  if (returned) {
    tm *return_day = localtime(&return_day_);
    cout << "Da tra! | "
         << "Ngay tra: " << return_day->tm_mday << "/" << 1 + return_day->tm_mon
         << "/" << return_day->tm_year + 1900 << " " << return_day->tm_hour
         << ":" << return_day->tm_min << endl;
  } else {
    cout << "Chua tra!" << endl;
  }
}

void Borrowing::doc(ifstream &in) {
  in.read(reinterpret_cast<char *>(this), sizeof(Borrowing));
}

void Borrowing::ghi(ofstream &out) {
  out.write(reinterpret_cast<char *>(this), sizeof(Borrowing));
}
