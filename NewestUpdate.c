#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tab printf("\n\t\t\t\t")

// Declare Procedure

void ChooseRole();
void MenuOwner();
void GetChoiceOfOwner(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void MenuCustomer();
void GetChoiceOfCustomer();
void MenuSort();
void GetChoiceOfSort();
int isEmpty(int n);


// Declare Function

void DisplayFood();
void AddNewFood(int*nums,int*Rno,int rno,char*Names[],char getname[],int*Price,int price,int*Quantity,int quantity,char*mfg[],char getmfg[],char*exp[],char getexp[]);


// Process Of Procedure Menu

void ChooseRole() {
	int userChoice;
	tab;printf(" ===============================================");
	tab;printf(" |                ENTER ROLE                   |");
	tab;printf(" ===============================================\n");
	tab;printf("   1. SHOP OWNER\n");
	tab;printf("   2. CUSTOMER\n ");
	tab;printf("   3. EXIT \n");
	tab;printf(" ===============================================\n\n");
	tab;printf("Enter your role: ");
	userChoice = getch();
	switch(userChoice) {
		case 49:
			system("cls");
			MenuOwner();
			break;
		case 50:
			system("cls");
			MenuCustomer();
			break;
		default:
			tab;printf("The Program Will Exit !!!");
	}
}

void MenuOwner() {
	
	tab;printf(" ===============================================");
	tab;printf(" |                MENU SHOP OWNER              |");
	tab;printf(" ===============================================\n");
	tab;printf("   1. Display all Food                 \n");
	tab;printf("   2. Add new Food                     \n");
	tab;printf("   3. Sort all Food for each information\n");
	tab;printf("   4. Looking for Food         \n");
	tab;printf("   5. Delete Food       \n");
	tab;printf("   6. Delate All Food       \n");
	tab;printf("   7. Back to Role Menu      \n");
	tab;printf("   8. EXIT      \n");
	tab;printf(" ===============================================\n\n");
	tab;printf("Enter your choice: ");
	
}


void GetChoiceOfOwner(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	int userChoice;
	/* Declare for Check Day */
	int daymfg,dayexp,monthmfg,monthexp,yearmfg,yearexp;  
	
	/* Declared for get value input to add  */
	char getname[20],getmfg[20],getexp[20];
	int rno,price,quantity;
	
	scanf("%d", &userChoice);
	switch(userChoice) {
		case 1:
//			if(isEmpty())
//			DisplayFood();
			break;
		case 2:
			do {
				system("cls");
			printf("\n<===============|ADD FOOD|===============>\n");
			printf("\nEnter RollNo: ");
			scanf("%d",&rno);
			printf("\nEnter name: ");
			fflush(stdin);
			fgets(getname,sizeof(char)*20, stdin);
			printf("\nEnter Price Of Food: ");
			scanf("%d",&price);
			printf("\nEnter Quantity Of Food: ");
			scanf("%d",&quantity);
			printf("\nEnter Manufacturing Date (dd/mm/yyyy) ");
			fflush(stdin);
			fgets(getmfg,sizeof(char)*20, stdin);
			while(!CheckDay(getmfg,&daymfg,&monthmfg,&yearmfg)) {
								printf("\nInvalid Manufacturing Date!\n");
								printf("\nEnter Manufacturing Date Of Food Again (dd/mm/yyyy): ");
								fflush(stdin);
								fgets(getmfg,sizeof(char)*20, stdin);
							}
			printf("\nEnter Expiry Date (dd/mm/yyyy) ");
			fflush(stdin);
			fgets(getexp,sizeof(char)*20, stdin);
			while(!CheckDay(getexp,&dayexp,&monthexp,&yearexp)) {
								printf("\nInvalid Expiry Date!\n");
								printf("\nEnter Expiry Date Of Food Again (dd/mm/yyyy): ");
								fflush(stdin);
								fgets(getexp,sizeof(char)*20, stdin);
							}
								if(yearexp<yearmfg) {
									printf("\nThe year of the expiry date must be greater than the year of the manufacture date\n");
									printf("\nEnter Expiry Date Of Food Again (dd/mm/yyyy): ");
									fflush(stdin);
									fgets(getexp,sizeof(char)*20, stdin);
								} else {
									if(monthexp<monthexp) {
										printf("\nThe year of the expiry date must be greater than the year of the manufacture date");
										printf("\nEnter Expiry Date Of Food Again (dd/mm/yyyy): ");
										fflush(stdin);
										fgets(getexp,sizeof(char)*20, stdin);
									} else {
										if(dayexp<dayexp) {
											printf("\nThe year of the expiry date must be greater than the year of the manufacture date");
											printf("\n\nEnter Expiry Date Of Food Again (dd/mm/yyyy): ");
											fflush(stdin);
											fgets(getexp,sizeof(char)*20, stdin);
										}
									}
								}
			AddNewFood(NumOfFood,Rno,rno,Names,getname,Price,price,Quantity,quantity,mfg,getmfg,exp,getexp);
			printf("\nADDED!!!");
			printf("\n\nDo you want to add more (y/n): ");
			fflush(stdin);
			userChoice = getch();	
			} while(userChoice==121);
			
			printf("\n=======================\n");
			printf("%d       sssssss",*NumOfFood);
			break;
		case 3:
//			MenuSort();
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
		
			break;
		
		case 7: 
		
			break;
		default:
			tab;printf("The Program Will Exit !!!");
	}
}


void MenuCustomer() {
	
	tab;printf(" ===============================================");
	tab;printf(" |                MENU CUSTOMER                |");
	tab;printf(" ===============================================\n");
	tab;printf("   1. Display all Food                 \n");
	tab;printf("   2. Buy Food \n"); // Sort depend on price 1. Mua luon hay khong a. Mua = remove, b. Khong mua = ... 2. Chinh sua don hang
	tab;printf("   3. Back to Role Menu      \n");
	tab;printf("   4. EXIT      \n");
	tab;printf(" ===============================================\n\n");
	tab;printf("Enter your choice: ");
	GetChoiceOfCustomer();
	 
}

void GetChoiceOfCustomer() {
	int userChoice;
	scanf("%d", &userChoice);
	switch(userChoice) {
		case 1:
			
			break;
			
		case 2:
		
			break;
			
		case 3:
		
			break;	
		
		default:
			tab;printf("The Program Will Exit !!!");
	}
}

/*    Function 1: Display     */
int isEmpty(int n) {
	return n == 0;
}



/*    Function 2: Add Food     */

int CheckDay(char a[],int*pd,int*pm,int*py) {
	
	char d[2],m[2],y[4];
	
	strncpy(d, a, 2); 
	strncpy(m, a+3, 2);
	strncpy(y, a+6, 4);
	
	*(pd) = atoi(d);
	*(pm) = atoi(m);
	*(py) = atoi(y);
	
	int maxd = 31;
    if (((*pd) < 1) || ((*pd) > 31) || ((*pm) < 1) || ((*pm) > 12))
    	return 0;
    if (((*pm) == 4) || ((*pm) == 6) || ((*pm) == 9) || ((*pm) == 11))
        maxd = 30;
    if ((*pm) == 2)
	{
        if (((*py) % 400 == 0) || (((*py) % 4 == 0) && ((*py) % 100 != 0)))
 	    	maxd = 29;
        else
        	maxd = 28; 
	}
	return (*pd) <= maxd;
}



void AddNewFood(int*nums,int*Rno,int rno,
				char*Names[],char getname[],
				int*Price,int price,int*Quantity,int quantity,
				char*mfg[],char getmfg[],char*exp[],char getexp[]) {
	

	 Names[*nums] = malloc(strlen(getname) + 1);
	   mfg[*nums] = malloc(strlen(getmfg) + 1);
	   exp[*nums] = malloc(strlen(getexp) + 1);
	   Rno[*nums] = rno;
 	 Price[*nums] = price;
  Quantity[*nums] = quantity;
	strcpy(Names[*nums], getname);
	strcpy( mfg[*nums], getmfg);
	strcpy( exp[*nums], getexp);
	++(*nums);
}





void MenuSort() {
	
	tab;printf(" ===============================================");
	tab;printf(" |                  MENU SORT                  |");
	tab;printf(" ===============================================\n");
	tab;printf("   1. Sort depend on Roll NO                 \n");
	tab;printf("   2. Sort depend on Price \n"); 
	tab;printf("   3. Sort depend on Manufacturing Date       \n");
	tab;printf("   4. Sort depend on Expiry_Date     \n");
	tab;printf("   5. Sort depend on Quantity     \n");
	tab;printf(" ===============================================\n\n");
	tab;printf("Enter your choice: ");
//	GetChoiceOfSort();
	
}

//void GetChoiceOfSort() {
//	int userChoice;
//	userChoice = getch();
//	switch(userChoice) {
//		case: 49
//			
//			break;
//		case:
//	}
//}






/*   Main Function  */

int main() {
/* Declare for count element, dynamic allocate */
	int NumberOfFood=0;

/* Declare dynamic array */
	int*Rno = (int*)calloc(NumberOfFood,sizeof(int));
	int*Price = (int*)calloc(NumberOfFood,sizeof(int));
	int*Quantity = (int*)calloc(NumberOfFood,sizeof(int));
	
/* Declare array of char pointer */
	char *Names[NumberOfFood];
	char *MFG[NumberOfFood];
	char *EXP[NumberOfFood];

	
/*=====================================*/

	ChooseRole();
	GetChoiceOfOwner(&NumberOfFood,Rno,Names,Price,Quantity,MFG,EXP);
	
	free(Rno);
	free(Price);
	free(Quantity);
	return 0;
}
