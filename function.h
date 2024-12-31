#include "datatypes.h"
//Ham in menu 
void printMenu();
//Ham In danh sach nguoi dung 
void showAllUsers(struct User users[],int count);
//Ham kiem tra chuoi co rong khong 
bool isEmpty(const char* str);
//Ham kiem tra do dai hop le cua chuoi
bool isValidLength(const char* str, int maxLength);
//Ham kiem tra do dai cho ID va so dien thoai 
bool isValidLengthForIdPhone(const char* str, int maxLength);
//Ham kiem tra trung lap ID,Email,Phone,Name 
bool isDuplicate(struct User users[], int count, const char* id, const char* email, const char* phone, const char* name);
//Ham them nguoi dung 
int addUser(struct User users[], int count, int maxUsers);
//Ham tim kiem nguoi dung 
void searchUser(struct User users[], int count, const char*keyword);
