#include "Process.hpp"

int showMenu() {
  system("cls");
  cout << "\n\t\t\tQUAN LY THU VIEN";
  cout << "\n\tCac chuc nang:";
  cout << "\n\t\t1. Them du lieu tu file.";
  cout << "\n\t\t2. Xuat du lieu ra file.";
  cout << "\n\t\t3. Them sach moi.";
  cout << "\n\t\t4. Them thanh vien moi.";
  cout << "\n\t\t5. Hien thi tat ca sach.";
  cout << "\n\t\t6. Hien thi tat ca thanh vien.";
  cout << "\n\t\t7. Tim sach.";
  cout << "\n\t\t8. Muon sach.";
  cout << "\n\t\t9. Sap xep sach.";
  cout << "\n\t\t10. Xoa sach.";
  cout << "\n\t\t0. Thoat.";
  cout << "\nnhap lua chon cua bn: ";
  int i;
  cin >> i;
  fflush(stdin);
  return i;
}

void borrowBook(vector<Member> &member, vector<Book> &book) {
  string n;
  cout << "Nhap ten cua thanh vien muon muon: ";
  getline(cin, n);
  for (Member i : member) {
    if (i.getName().find(n) != string::npos) {
      cout << i << endl;
      i.borrowBook(book);
    }
  }
}

void addNewBooks(vector<Book> &books) {
  int n;
  cout << "\nNhap so sach bn muon them: ";
  cin >> n;
  fflush(stdin);
  for (int i = 0; i < n; i++) {
    Book tg(books.size());
    cin >> tg;
    cout << endl;
    books.push_back(tg);
  }
}

void addNewMembers(vector<Member> &members) {
  int n;
  cout << "\nNhap so nguoi bn muon them: ";
  cin >> n;
  getchar();
  for (int i = 0; i < n; i++) {
    Member tg(members.size());
    cin >> tg;
    cout << endl;
    members.push_back(tg);
  }
}

void showAllBooks(vector<Book> books) {
  for (Book i : books) {
    cout << i << endl;
  }
}

void showAllMenbers(vector<Member> members) {
  for (Member i : members) {
    cout << i << endl;
  }
}

void seach(vector<Book> &books) {
  int c;
  cout << "Ban muon tim kiem bang:\n";
  cout << "\t\t1.Title.\n";
  cout << "\t\t2.Author.\n";
  cout << "Lua chon cua ban: ";
  cin >> c;
  getchar();
  string con;
  switch (c) {
  case 2:
    cout << "Nhap Author: ";
    getline(cin, con);
    cout << "ket qua tim kiem:\n";
    for (Book i : books) {
      if (i.getAuthor().find(con) != string::npos)
        cout << i << endl;
    }
    break;
  case 1:
    cout << "Nhap Title: ";
    getline(cin, con);
    cout << "ket qua tim kiem:\n";
    for (Book i : books) {
      if (i.getTitle().find(con) != string::npos)
        cout << i << endl;
    }
    break;
  default:
    break;
  }
}

bool outToFile(vector<Book> b, vector<Member> m) {
  system("cls");
  ofstream fo(FILE_PATH, ios::binary | ios::out | ios::trunc);
  if (!fo)
    return false;

  int n_book, n_member;

  n_book = b.size();
  fo.write(reinterpret_cast<char *>(&n_book), sizeof(int));

  n_member = m.size();
  fo.write(reinterpret_cast<char *>(&n_member), sizeof(int));

  for (Book i : b) {
    i.ghi(fo);
  }

  for (Member i : m) {
    i.ghi(fo);
  }

  fo.close();
  return true;
}

bool getInFile(vector<Book> &b, vector<Member> &m) {
  system("cls");
  ifstream fi(FILE_PATH, ios::binary | ios::in);

  if (!fi)
    return false;
  int n_book, n_member;
  fi.read(reinterpret_cast<char *>(&n_book), sizeof(int));
  fi.read(reinterpret_cast<char *>(&n_member), sizeof(int));
  // cout << (int)n << endl;
  // while (!fi.eof()) {
  for (int i = 0; i < n_book; i++) {
    Book tg;
    tg.doc(fi);
    b.push_back(tg);
  }
  for (int i = 0; i < n_member; i++) {
    Member tg;
    tg.doc(fi);
    m.push_back(tg);
  }

  fi.close();
  chuanhoaIdBook(b);

  return true;
}

void chuanhoaIdBook(vector<Book> &books) {
  int n = books.size();
  for (int i = 0; i < n; i++) {
    if (i != books.at(i).id)
      books.at(i).id = i;
  }
}

void deleteBook(vector<Book> &books) {
  system("cls");
  cout << "\t\t\tXoa sach\n";
  cout << "Nhap ten ban muon xoa";
  string name;
  getline(cin, name);
  int n = books.size();
  for (int i = 0; i < n; i++) {
    if (books.at(i).getTitle().find(name) != string::npos) {
      books.erase(books.begin() + i);
    }
  }
  chuanhoaIdBook(books);
}

int compareBook(Book b1, Book b2) {
  return b1.getTitle().compare(b2.getTitle());
}

void sortBook(vector<Book> &books) {
  system("cls");
  sort(books.begin(), books.end(), compareBook);
  chuanhoaIdBook(books);
  cout << "Da xap xep sach xong\n";
}

void xl() {
  vector<Book> books;
  vector<Member> members;
  while (true) {
    switch (showMenu()) {
    case 1:
      cout << "\t\tLAY DU LIEU TU FILE\n\n"
           << (getInFile(books, members) ? "Lay du lieu thanh cong"
                                         : "Loi khi doc file")
           << "\n\nNhan ENTER de ve menu";
      cin.get();
      break;
    case 2:
      cout << "\t\tXUAT DU LIEU RA FILE\n\n"
           << (outToFile(books, members) ? "Xuat du lieu thanh cong"
                                         : "Loi khi ghi file")
           << "\n\nNhan ENTER de ve menu";
      cin.get();
      break;
    case 3:
      cout << "\t\tTHEM SACH THU CONG\n\n";
      addNewBooks(books);
      cout << "\n\nNhan ENTER de ve menu";
      cin.get();
      break;
    case 4:
      cout << "\t\tTHEM THANH VIEN THU CONG\n\n";
      addNewMembers(members);
      cout << "\n\nNhan ENTER de ve menu";
      cin.get();
      break;
    case 5:
      cout << "\t\tTOAN BO SACH\n\n";
      showAllBooks(books);
      cout << "\n\nNhan ENTER de ve menu";
      cin.get();
      break;
    case 6:
      cout << "\t\tTOAN BO THANH VIEN\n\n";
      showAllMenbers(members);
      cout << "\n\nNhan ENTER de ve menu";
      cin.get();
      break;
    case 7:
      cout << "\t\tTIM KIEM SACH\n\n";
      seach(books);
      cout << "\n\nNhan ENTER de ve menu";
      cin.get();
      break;
    case 8:
      cout << "\t\tMUON SACH\n\n";
      borrowBook(members, books);
      break;
    case 9:
      cout << "\t\tSAP XEP SACH THEO TEN\n\n";
      sortBook(books);
      cout << "\n\nNhan ENTER de ve menu";
      cin.get();
      break;
    case 10:
      cout << "\t\tXOA SACH\n\n";
      deleteBook(books);
      cout << "\n\nNhan ENTER de ve menu";
      cin.get();
      break;
    default:
      return;
    }
  }
}