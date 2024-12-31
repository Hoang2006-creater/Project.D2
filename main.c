#include <stdio.h>
#include <stdlib.h>
#include "function.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	struct User users[10]; 
    int userCount = 3;
    int maxUsers= 100;
    char keyword[50];
    // Danh sach ban dau
    strcpy(users[0].id, "0333928763");
    strcpy(users[0].name, "Nguyen Van A");
    strcpy(users[0].email, "A@gmail.com");
    strcpy(users[0].phone, "0999888777");
    strcpy(users[0].status, "Open");
    
    strcpy(users[1].id, "0333928764");
    strcpy(users[1].name, "Pham tien B");
    strcpy(users[1].email, "B@gmail.com");
    strcpy(users[1].phone, "0666888777");
    strcpy(users[1].status, "Open");
    
    strcpy(users[2].id, "0333928765");
    strcpy(users[2].name, "Vu thi C");
    strcpy(users[2].email, "C@gmail.com");
    strcpy(users[2].phone, "0555888777");
    strcpy(users[2].status, "Open");
	int choice;
	do{
	printMenu();
	printf("Enter the choice: ");
	scanf("%d",&choice);
	getchar(); 
	switch(choice){
		//Them nguoi dung
		case 1:
			system("cls");
			userCount = addUser(users, userCount, maxUsers);
			break;
			//Hien thi nguoi dung
		case 2:
			system("cls");
			showAllUsers(users, userCount);
			break;
			//Tim kiem nguoi dung
		case 3:
			system("cls");
			printf("Enter the search name you want: ");
			fgets(keyword, sizeof(keyword), stdin);
			keyword[strcspn(keyword,"\n")]='\0';
			searchUser( users, userCount, keyword);
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;	
		case 8:
			printf("Exit the program successfully");
			break;
		default:
                printf("Invalid choice! Please try again.\n");	
	}
	}while (choice !=8);
	return 0;
}
