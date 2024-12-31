#pragma once
#include <stdbool.h>
struct Date{			
	int month, day, year;		
};			
struct Transaction{			
	char transferId[10];		
	char receivingId[10];		
	double amount;		
	char type[10];		
	char message[50];		
	struct Date transactionDate;		
};			
struct AccountInfo{			
	char userId[20];		
	float balance;		
	bool status;		
	struct Transaction transactionHistory[];		
};			
struct User{			
	char id[50];		
	char name[50];		
	struct Date dateOfBirth;		
	bool gender;		
	char phone[50];		
	char email[50];	
	char status[10];		
};			






