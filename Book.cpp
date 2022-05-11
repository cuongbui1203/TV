#include "Book.hpp"

Book::Book(int id) { this->id = id; }

Book::Book() {}

void Book::ghi(ofstream &out) {
  out.write(reinterpret_cast<char *>(this), sizeof(Book));
}

void Book::doc(ifstream &in) {
  in.read(reinterpret_cast<char *>(this), sizeof(Book));
}

bool Book::update(TrangThai muon) {
  if (muon == TrangThai::muon && quantity > 0) {
    quantity--;
    return true;
  } else if (quantity == 0) {
    cout << "Het sach trong thu vien.\n";
    return false;
  }
  quantity++;
  return true;
}
