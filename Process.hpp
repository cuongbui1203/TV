#pragma once
#include "includes.hpp"
#include "Borrowing.hpp"
#include "Book.hpp"
#include "Member.hpp"

#define FILE_PATH "data/data.dat"

void seach(vector<Book> &);
void deleteBook(vector<Book> &);
void sortBook(vector<Book> &);

void chuanhoaIdBook(vector<Book> &);

int showMenu();

void addNewBooks(vector<Book> &);
void addNewMembers(vector<Member> &);

void showAllBooks(vector<Book>);
void showAllMenbers(vector<Member>);

bool outToFile(vector<Book>, vector<Member>);
bool getInFile(vector<Book> &, vector<Member> &);

void xl();