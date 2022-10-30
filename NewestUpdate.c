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
void MenuSort(); // Sort depend on what 
void MenuSubSort(); // ascending / descending
void GetChoiceOfSubSort(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);


// Declare Function & SubFunction
int isEmpty(int n);
void DisplayFood(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void AddNewFood(int*nums,int*Rno,int rno,char*Names[],char getname[],int*Price,int price,int*Quantity,int quantity,char*mfg[],char getmfg[],char*exp[],char getexp[]);
void SwapInt(int*p1,int*p2);
void SwapChar(char* str1,char* str2);
void Sort(int choice1,int choice2,int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);


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
			exit(1);
			break;
	}
}

void MenuOwner() {
	
	tab;printf(" ===============================================");
	tab;printf(" |                MENU SHOP OWNER              |");
	tab;printf(" ===============================================\n");
	tab;printf("   1. Display all Food                 \n");
	tab;printf("   2. Add new Food                     \n");
	tab;printf("   3. Sort all Food \n");
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
	
	/* Declared for get input value to add  */
	char getname[20],getmfg[20],getexp[20];
	int rno,price,quantity;
		scanf("%d", &userChoice);
		switch(userChoice) {
		case 1:
			do {
				system("cls");
				printf("\n<===============|SHOW MENU FOOD|===============>\n\n");
				if(isEmpty(*NumOfFood)) {
					printf("Mini Market doestn't have any food to show!\n");
					printf("\nBack to Menu Shop Owner (y/n): ");
					userChoice = getch();
						if(userChoice==121) {
							system("cls");
							MenuOwner();
							GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
						} else printf("\n\nThe Program Will Exit!!!"); exit(1); break;
				} 
				else {
					DisplayFood(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
					fflush(stdin);
					MenuOwner();
					GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
					
				}
			} while(userChoice==121);
			break;
		case 2:
			do {
				system("cls");
				printf("\n<===============|ADD FOOD|===============>\n");
				printf("\nEnter RollNo: ");
				scanf("%d",&rno);
				printf("\nEnter name: ");
				fflush(stdin);
				scanf("%[^\n]s",getname);
				printf("\nEnter Price Of Food: ");
				scanf("%d",&price);
				printf("\nEnter Quantity Of Food: ");
				scanf("%d",&quantity);
				printf("\nEnter Manufacturing Date (dd/mm/yyyy): ");
				fflush(stdin);
				scanf("%[^\n]s",getmfg);
				while(!CheckDay(getmfg,&daymfg,&monthmfg,&yearmfg)) {
									printf("\nInvalid Manufacturing Date!\n");
									printf("\nEnter Manufacturing Date Of Food Again (dd/mm/yyyy): ");
									fflush(stdin);
									scanf("%[^\n]s",getmfg);
								}
				printf("\nEnter Expiry Date (dd/mm/yyyy): ");
				fflush(stdin);
				scanf("%[^\n]s",getexp);
				while(!CheckDay(getexp,&dayexp,&monthexp,&yearexp)) {
									printf("\nInvalid Expiry Date!\n");
									printf("\nEnter Expiry Date Of Food Again (dd/mm/yyyy): ");
									fflush(stdin);
									scanf("%[^\n]s",getexp);
								}
									if(yearexp<yearmfg) {
										printf("\nThe year of the expiry date must be greater than the year of the manufacture date\n");
										printf("\nEnter Expiry Date Of Food Again (dd/mm/yyyy): ");
										fflush(stdin);
										scanf("%[^\n]s",getexp);
									} else {
										if(monthexp<monthexp) {
											printf("\nThe year of the expiry date must be greater than the year of the manufacture date");
											printf("\nEnter Expiry Date Of Food Again (dd/mm/yyyy): ");
											fflush(stdin);
											scanf("%[^\n]s",getexp);
										} else {
											if(dayexp<dayexp) {
												printf("\nThe year of the expiry date must be greater than the year of the manufacture date");
												printf("\n\nEnter Expiry Date Of Food Again (dd/mm/yyyy): ");
												fflush(stdin);
												scanf("%[^\n]s",getexp);
											}
										}
									}
			AddNewFood(NumOfFood,Rno,rno,Names,getname,Price,price,Quantity,quantity,mfg,getmfg,exp,getexp);
			printf("\nADDED!!!");
			printf("\n\nDo you want to add more (y/n): ");
			fflush(stdin);
			userChoice = getch();	
			} while(userChoice==121);
			system("cls");
			MenuOwner();
			GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
			
		case 3:
				if(isEmpty(*NumOfFood)) {
					system("cls");
					printf("\nMini Market doestn't have any food to show!\n");
					printf("\nBack to Menu Shop Owner (y/n): ");
					userChoice = getch();
						if(userChoice==121) {
							system("cls");
							MenuOwner();
							GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
						} else printf("\n\nThe Program Will Exit!!!"); exit(1); break;
				}
				GetChoiceOfSubSort(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
				fflush(stdin);
				MenuOwner();
				GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
		
			break;
		
		case 7: 
			system("cls");
			ChooseRole();
			GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
		default:
			tab;printf("The Program Will Exit !!!");
			exit(1);
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

void MenuSort() {
	
	tab;printf(" ===============================================");
	tab;printf(" |                  MENU SORT                  |");
	tab;printf(" ===============================================\n");
	tab;printf("   1. Sort depend on Roll NO                 \n");
	tab;printf("   2. Sort depend on Name                 \n");
	tab;printf("   3. Sort depend on Price \n"); 
	tab;printf("   4. Sort depend on Manufacturing_Date       \n");
	tab;printf("   5. Sort depend on Expiry_Date     \n");
	tab;printf("   6. Sort depend on Quantity     \n");
	tab;printf("   7. Back to Shop Owner Menu     \n");
	tab;printf(" ===============================================\n\n");
	tab;printf("Enter your choice: ");

}

void MenuSubSort() {
	
	tab;printf(" ===============================================");
	tab;printf(" |                 MENU SUB SORT               |");
	tab;printf(" ===============================================\n");
	tab;printf("   1. Sort Ascending                 \n");
	tab;printf("   2. Sort Descending                 \n");
	tab;printf("   3. Back to other Sort \n"); 
	tab;printf("   4. Back to Shop Owner Menu \n"); 
	tab;printf(" ===============================================\n\n");
	tab;printf("Enter your choice: ");

}

void GetChoiceOfSubSort(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	int CSort,CSSort;
	system("cls");
	do {
		MenuSort();
		scanf("%d", &CSort);
		system("cls");
		switch(CSort) {
		case 1:
			MenuSubSort();
			scanf("%d", &CSSort);
				switch(CSSort) {
					case 1:
						system("cls");
						Sort(CSort,CSSort,NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
						DisplayFood(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
						break;
					case 2:
						system("cls");
						Sort(CSort,CSSort,NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
						DisplayFood(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
						break;
					case 3:
						system("cls");
						break;
					default:
						system("cls");
						MenuOwner();
						GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
						break;
					}
			break;
		case 2:
			MenuSubSort();
			scanf("%d", &CSSort);
			system("cls");
			Sort(CSort,CSSort,NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			DisplayFood(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
		case 3:
			MenuSubSort();
			scanf("%d", &CSSort);
			system("cls");
			Sort(CSort,CSSort,NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			DisplayFood(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
		case 4:
			MenuSubSort();
			scanf("%d", &CSSort);
			system("cls");
			Sort(CSort,CSSort,NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			DisplayFood(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
		
		case 5:
			MenuSubSort();
			scanf("%d", &CSSort);
			system("cls");
			Sort(CSort,CSSort,NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			DisplayFood(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
			
		case 6:
			MenuSubSort();
			scanf("%d", &CSSort);
			system("cls");
			Sort(CSort,CSSort,NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			DisplayFood(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
		default:
			MenuOwner();
			GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
		}
	} while (CSort > 0 && CSort < 8);
	
}

/*    Function 1: Display     */

int isEmpty(int n) {
	return n == 0;
}


void DisplayFood(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	int i;
	printf("NO\tNAME\t\tPRICE\t\tManufacturing Date\tExpiry_Date\tQUANTITY\n");
	for(i=0;i<*NumOfFood;i++) {	
		if(strlen(Names[i])>7) {
				printf("%d\t",Rno[i]);
				printf("%s\t",Names[i]);
				printf("%d\t\t",Price[i]);
				printf("%s\t\t",mfg[i]);
				printf("%s\t",exp[i]);
				printf("%d\n",Quantity[i]);
			}
		else {
			printf("%d\t",Rno[i]);
			printf("%s\t\t",Names[i]);
			printf("%d\t\t",Price[i]);
			printf("%s\t\t",mfg[i]);
			printf("%s\t",exp[i]);
			printf("%d\n",Quantity[i]);
		}

	}
	
	
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
	
/* Dynamic allocate for each pointer of array of char pointer */
	 Names[*nums] = malloc(strlen(getname) + 1);
	   mfg[*nums] = malloc(strlen(getmfg) + 1);
	   exp[*nums] = malloc(strlen(getexp) + 1);
	   
/* Adding... */	   
	   Rno[*nums] = rno;
 	 Price[*nums] = price;
  Quantity[*nums] = quantity;
  
	strcpy(Names[*nums], getname);
	strcpy( mfg[*nums], getmfg);
	strcpy( exp[*nums], getexp);
	(*nums)++;
	

}


/* Function 3: Sort */

void SwapInt(int*p1,int*p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void SwapChar(char* str1,char* str2) 
{
	char temp[20];
   strncpy(temp,str1,20);
   strncpy(str1,str2,20);
   strncpy(str2,temp,20);
}

void Sort(int choice1,int choice2,int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	int i,j;
	/*
		1.Ascending
		2.Descending
		
	*/
	switch(choice1) {
		case 1: 
			if(choice2==1) {
				for(i=0;i<(*NumOfFood)-1;i++) {
					for(j=i+1;j<*NumOfFood;j++) {
						if (Rno[i] > Rno[j]) {
							SwapInt(&Rno[i],&Rno[j]);
							SwapInt(&Price[i],&Price[j]);
							SwapInt(&Quantity[i],&Quantity[j]);
							SwapChar(Names[i],Names[j]);
							SwapChar(mfg[i],mfg[j]);
							SwapChar(exp[i],exp[j]);
					}
				}
			}
		} else {
				for(i=0;i<(*NumOfFood)-1;i++) {
					for(j=i+1;j<*NumOfFood;j++) {
					if (Rno[i] < Rno[j]) {
						SwapInt(&Rno[i],&Rno[j]);
						SwapInt(&Price[i],&Price[j]);
						SwapInt(&Quantity[i],&Quantity[j]);
						SwapChar(Names[i],Names[j]);
						SwapChar(mfg[i],mfg[j]);
						SwapChar(exp[i],exp[j]);
					}
				}
			}
		}	
			break;
		case 2:
			if(choice2==1) {
				for(i=0;i<(*NumOfFood)-1;i++) {
					for(j=i+1;j<*NumOfFood;j++) {
					if (strcmp(Names[i],Names[j])) {
						SwapInt(&Rno[i],&Rno[j]);
						SwapInt(&Price[i],&Price[j]);
						SwapInt(&Quantity[i],&Quantity[j]);
						SwapChar(Names[i],Names[j]);
						SwapChar(mfg[i],mfg[j]);
						SwapChar(exp[i],exp[j]);
					}
				}
			}
		} else {
			for(i=0;i<(*NumOfFood)-1;i++) {
				for(j=i+1;j<*NumOfFood;j++) {
					if (!strcmp(Names[i],Names[j])) {
						SwapInt(&Rno[i],&Rno[j]);
						SwapInt(&Price[i],&Price[j]);
						SwapInt(&Quantity[i],&Quantity[j]);
						SwapChar(Names[i],Names[j]);
						SwapChar(mfg[i],mfg[j]);
						SwapChar(exp[i],exp[j]);
					}
				}
			}
		}
			break;
		case 3:
			if(choice2==1) {
				for(i=0;i<(*NumOfFood)-1;i++) {
					for(j=i+1;j<*NumOfFood;j++) {
					if (Price[i] > Price[j]) {
						SwapInt(&Rno[i],&Rno[j]);
						SwapInt(&Price[i],&Price[j]);
						SwapInt(&Quantity[i],&Quantity[j]);
						SwapChar(Names[i],Names[j]);
						SwapChar(mfg[i],mfg[j]);
						SwapChar(exp[i],exp[j]);
					}
				}
			}
		} else {
			for(i=0;i<(*NumOfFood)-1;i++) {
				for(j=i+1;j<*NumOfFood;j++) {
						if (Price[i] < Price[j]) {
							SwapInt(&Rno[i],&Rno[j]);
							SwapInt(&Price[i],&Price[j]);
							SwapInt(&Quantity[i],&Quantity[j]);
							SwapChar(Names[i],Names[j]);
							SwapChar(mfg[i],mfg[j]);
							SwapChar(exp[i],exp[j]);
						}
					}
				}
			}
			break;
		case 4:
			if(choice2==1) {
				for(i=0;i<(*NumOfFood)-1;i++) {
					for(j=i+1;j<*NumOfFood;j++) {
						if (strcmp(mfg[i],mfg[j])) {
							SwapInt(&Rno[i],&Rno[j]);
							SwapInt(&Price[i],&Price[j]);
							SwapInt(&Quantity[i],&Quantity[j]);
							SwapChar(Names[i],Names[j]);
							SwapChar(mfg[i],mfg[j]);
							SwapChar(exp[i],exp[j]);
						}
					}
				}
			} else {
				for(i=0;i<(*NumOfFood)-1;i++) {
					for(j=i+1;j<*NumOfFood;j++) {
						if (!strcmp(mfg[i],mfg[j])) {
							SwapInt(&Rno[i],&Rno[j]);
							SwapInt(&Price[i],&Price[j]);
							SwapInt(&Quantity[i],&Quantity[j]);
							SwapChar(Names[i],Names[j]);
							SwapChar(mfg[i],mfg[j]);
							SwapChar(exp[i],exp[j]);
						}
					}
				}
			}
			break;
		case 5:
			if(choice2==1) {
				for(i=0;i<(*NumOfFood)-1;i++) {
					for(j=i+1;j<*NumOfFood;j++) {
						if (strcmp(exp[i],exp[j])) {
							SwapInt(&Rno[i],&Rno[j]);
							SwapInt(&Price[i],&Price[j]);
							SwapInt(&Quantity[i],&Quantity[j]);
							SwapChar(Names[i],Names[j]);
							SwapChar(mfg[i],mfg[j]);
							SwapChar(exp[i],exp[j]);
						}
					}
				}
			} else {
				for(i=0;i<(*NumOfFood)-1;i++) {
					for(j=i+1;j<*NumOfFood;j++) {
						if (!strcmp(exp[i],exp[j])) {
							SwapInt(&Rno[i],&Rno[j]);
							SwapInt(&Price[i],&Price[j]);
							SwapInt(&Quantity[i],&Quantity[j]);
							SwapChar(Names[i],Names[j]);
							SwapChar(mfg[i],mfg[j]);
							SwapChar(exp[i],exp[j]);
						}
					}
				}
			}
			break;
		case 6:
			if(choice2==1) {
				for(i=0;i<(*NumOfFood)-1;i++) {
					for(j=i+1;j<*NumOfFood;j++) {
						if (Quantity[i] > Quantity[j]) {
							SwapInt(&Rno[i],&Rno[j]);
							SwapInt(&Price[i],&Price[j]);
							SwapInt(&Quantity[i],&Quantity[j]);
							SwapChar(Names[i],Names[j]);
							SwapChar(mfg[i],mfg[j]);
							SwapChar(exp[i],exp[j]);
						}
					}
					}
				} else {
					for(i=0;i<(*NumOfFood)-1;i++) {
					for(j=i+1;j<*NumOfFood;j++) {
						if (Quantity[i] < Quantity[j]) {
							SwapInt(&Rno[i],&Rno[j]);
							SwapInt(&Price[i],&Price[j]);
							SwapInt(&Quantity[i],&Quantity[j]);
							SwapChar(Names[i],Names[j]);
							SwapChar(mfg[i],mfg[j]);
							SwapChar(exp[i],exp[j]);
						}
					}
				}
			}
			break;
		default:
			MenuOwner();
			GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
	}
}


/*   Main Function  */

int main() {
/* Declare for count element, dynamic allocate */
	int NumberOfFood=0,i;

/* Declare dynamic array */
	int*Rno = (int*)calloc(NumberOfFood,sizeof(int));
	int*Price = (int*)calloc(NumberOfFood,sizeof(int));
	int*Quantity = (int*)calloc(NumberOfFood,sizeof(int));
	
/* Declare array of char pointer */
	char **Names = (char**)calloc(NumberOfFood,sizeof(char*));
	char **MFG = (char**)calloc(NumberOfFood,sizeof(char*));
	char **EXP = (char**)calloc(NumberOfFood,sizeof(char*));

	
/*=====================================================*/

	ChooseRole();
	GetChoiceOfOwner(&NumberOfFood,Rno,Names,Price,Quantity,MFG,EXP);
	
	free(Rno);
	free(Price);
	free(Quantity);
	
	for(i=0;i<NumberOfFood;i++) {
		free(Names[i]);
		free(MFG[i]);
		free(EXP[i]);
	}
	free(Names);
	free(MFG);
	free(EXP);
	return 0;
}
