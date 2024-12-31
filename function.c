#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "function.h"
#include "datatypes.h"
// Ham in menu 
void printMenu() {
    printf("***Student Management System Using C***\n");
    printf("\tMenu\n");
    printf("[1] Add A New user.\n");
    printf("[2] Show All users.\n");
    printf("[3] Search a user.\n");
    printf("[4] Show detail an user.\n");
    printf("[5] Lock ( Unlock) an user.\n");
    printf("[6] User Guideline.\n");
    printf("[7] About Us.\n");
    printf("[8] Exit the program.\n");
}
//Ham in danh sach nguoi dung 
void showAllUsers(struct User users[], int count) {
    printf("+---------------+----------------+-----------------+------------+-------+\n");
    printf("| ID            | Name           | Email           | Phone      | Status|\n");
    printf("+---------------+----------------+-----------------+------------+-------+\n");
    int i;
    for (i = 0; i < count; i++) {
        printf("| %-13s | %-14s | %-15s | %-10s | %-5s |\n", 
               users[i].id, users[i].name, users[i].email, users[i].phone, users[i].status);
    }
    printf("+---------------+----------------+-----------------+------------+-------+\n");
}
// Ham kiem tra chuoi co rong khong 
bool isEmpty(const char* str) {
    return str == NULL || str[0] == '\0';
}
//  Ham kiem tra do dai hop le cua chuoi
bool isValidLength(const char* str, int maxLength) {
    return strlen(str) > 0 && strlen(str) <= maxLength;
}
bool isValidLengthForIdPhone(const char* str, int maxLength) {
    return strlen(str) > 9 && strlen(str) <= maxLength;
}
// Ham kiem tra trung lap  
bool isDuplicate(struct User users[], int count, const char* id, const char* email, const char* phone, const char* name) {
	int i; 
    for ( i = 0; i < count; i++) {
        if (strcmp(users[i].id, id) == 0 || strcmp(users[i].email, email) == 0 || strcmp(users[i].phone, phone) == 0 || strcmp(users[i].name, name) == 0) {
            return true;
        }
    }
    return false;
}
// Ham them nguoi dung
int addUser(struct User users[], int count, int maxUsers) {
    if (count >= maxUsers) {
        printf("The user list is full. Cannot add more users.\n");
        return count;
    }
    struct User newUser;
    // Nhap ID 
    printf("Enter ID: ");
    fgets(newUser.id, sizeof(newUser.id), stdin);
    newUser.id[strcspn(newUser.id, "\n")] = '\0';
    if (isEmpty(newUser.id)) {
        printf("ID cannot be empty.\n");
        return count;
    }
    if (!isValidLengthForIdPhone(newUser.id, 11)) {
        printf("ID length must be 10 characters.\n");
        return count;
    }
    // Nhap Name
    printf("Enter Name: ");
    fgets(newUser.name, sizeof(newUser.name), stdin);
    newUser.name[strcspn(newUser.name, "\n")] = '\0';
    if (isEmpty(newUser.name)) {
        printf("Name cannot be empty.\n");
        return count;
    }
    if (!isValidLength(newUser.name, 50)) {
        printf("Name length must be between 1 and 50 characters.\n");
        return count;
    }
    // Nhap Email
    printf("Enter Email: ");
    fgets(newUser.email, sizeof(newUser.email), stdin);
    newUser.email[strcspn(newUser.email, "\n")] = '\0';
    if (isEmpty(newUser.email)) {
        printf("Email cannot be empty.\n");
        return count;
    }
    if (!isValidLength(newUser.email, 100)) {
        printf("Email length must be between 1 and 100 characters.\n");
        return count;
    }
    // Nhap Phone
    printf("Enter Phone: ");
    fgets(newUser.phone, sizeof(newUser.phone), stdin);
    newUser.phone[strcspn(newUser.phone, "\n")] = '\0';
    if (isEmpty(newUser.phone)) {
        printf("Phone cannot be empty.\n");
        return count;
    }
    if (!isValidLengthForIdPhone(newUser.phone, 11)) {
        printf("Phone length must be  10 characters.\n");
        return count;
    }
    // Nhap Status
    printf("Enter Status: ");
    fgets(newUser.status, sizeof(newUser.status), stdin);
    newUser.status[strcspn(newUser.status, "\n")] = '\0';
    if (isEmpty(newUser.status)) {
        printf("Status cannot be empty.\n");
        return count;
    }
    if (!isValidLength(newUser.status, 20)) {
        printf("Status length must be between 1 and 20 characters.\n");
        return count;
    }
    // Ham kiem tra trung lap
    if (isDuplicate(users, count, newUser.id, newUser.email, newUser.phone, newUser.name)) {
        printf("Duplicate ID, Email, Phone, or Name detected. Cannot add user.\n");
        return count;
    }
    // Them nguoi dung vao danh sach 
    users[count] = newUser;
    printf("User added successfully!\n");
    return count + 1;
}
// Ham tim kiem nguoi dung 
void searchUser(struct User users[], int count, const char* keyword) {
    if (keyword == NULL || strlen(keyword) == 0) {
        printf("The keyword is invalid.\n");
        return;
    }
    int found = 0;
    printf("+---------------+----------------+-----------------+------------+-------+\n");
    printf("| ID            | Name           | Email           | Phone      | Status|\n");
    printf("+---------------+----------------+-----------------+------------+-------+\n");
    int i;
    for (i = 0; i < count; i++) {
        if (strstr(users[i].name, keyword) != NULL) {
            printf("| %-13s | %-14s | %-15s | %-10s | %-5s |\n", 
                   users[i].id, users[i].name, users[i].email, users[i].phone, users[i].status);
            found = 1;
        }
    }
    if (!found) {
        printf("User not found!\n");
    } else {
        printf("+---------------+----------------+-----------------+------------+-------+\n");
    }
}
