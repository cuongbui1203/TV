#include "Member.hpp"
#include "Process.hpp"

Member::Member(int id) { this->id = id; }
Member::Member() {}

void Member::doc(ifstream &in) {
  in.read(reinterpret_cast<char *>(&id), sizeof(int));
  in.read(name, sizeof(name));
  int n;
  in.read(reinterpret_cast<char *>(&n), sizeof(int));
  for (int i = 0; i < n; i++) {
    Borrowing tg;
    tg.doc(in);
    borrows.push_back(tg);
  }
}

void Member::ghi(ofstream &out) {
  out.write(reinterpret_cast<char *>(&id), sizeof(int));
  out.write(name, sizeof(name));
  int n = borrows.size();
  out.write(reinterpret_cast<char *>(&n), sizeof(int));
  for (Borrowing i : borrows) {
    i.ghi(out);
  }
}

void Member::borrowBook(vector<Book> &books) {
  char c;

  do {

    if (borrows.size() > 50) {
      borrows.erase(borrows.begin());
      chuanhoaIdBook(books);
    }
    fflush(stdin);
    borrowBook2(books);
    cout << "\nBan co muon muon tiep khong (y/n)? ";
    cin >> c;
  } while (c == 'y');
}

void Member::borrowBook2(vector<Book> &books) {
  string bookname = "";
  cout << "Nhap ten sach muon muon:";
  getline(cin, bookname);
  fflush(stdin);
  for (Book &i : books) {
    if (i.getTitle().find(bookname) != string::npos) {
      fflush(stdin);
      cout << i << endl << endl;
      cout << "Ban co muon muon khong (y/n)? ";
      char c;
      cin >> c;
      if (c == 'n') {
        continue;
      }
      if (i.update(TrangThai::muon)) {
        borrows.push_back(Borrowing(this->getId(), i.getId()));
      } else {
        cout << "Vui long chon quyen khac!\n";
      }
      return;
    }
  }
  cout << "khong tim dc sach bn muon muon." << endl;
}

void Member::returnedBook(vector<Book> &books) {
  for (Borrowing &i : borrows) {
    if (!i.isReturned())
      i.returnBook(books);
  }
}

void Member::returnedBook(vector<Book> &books, string bookName) {
  for (Borrowing &i : borrows) {
    if (!i.isReturned() &&
        books.at(i.getIdBook()).getTitle().find(bookName) != string::npos) {
      i.returnBook(books);
      return;
    }
  }
}