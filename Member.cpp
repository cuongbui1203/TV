#include "Member.hpp"
#include "Process.hpp"

Member::Member(int id) { this->id = id; }
Member::Member() {}

void Member::doc(ifstream &in) {
  in.read(reinterpret_cast<char *>(this), sizeof(Member));
}

void Member::ghi(ofstream &out) {
  out.write(reinterpret_cast<char *>(this), sizeof(Member));
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