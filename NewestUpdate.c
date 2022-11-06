#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tab printf("\n\t\t\t\t")

// Declare Procedure

void ChooseRole(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void MenuOwner(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void GetChoiceOfOwner(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void MenuCustomer(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void GetChoiceOfCustomer(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void MenuSort(); 
void MenuSubSort();
void MenuFind();
void GetChoiceOfSubSort(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
 
// Declare Function & SubFunction 
int isEmpty(int n);
void DisplayFood(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void AddNewFood(int*nums,int*Rno,int rno,char*Names[],char getname[],int*Price,int price,int*Quantity,int quantity,char*mfg[],char getmfg[],char*exp[],char getexp[]);
void SwapInt(int*p1,int*p2);
void SwapChar(char* str1,char* str2);
void Sort(int choice1,int choice2,int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void FindByName(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],char getname[]);
void FindByPrice(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],int price);
void DeleteFood(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],char getname[]);
void DeleteAllFood(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void ChangePrice(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],char getname[],int NPrice);
void BuyFood(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],char getname[],int BQuantity,float *Money,int * NumInCart);
/* Declare File Function */
void ReadFile(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void WriteFile(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);


// Process Of Procedure Menu

void ChooseRole(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	int userChoice;
	tab;printf(" ===============================================");
	tab;printf(" |                ENTER ROLE                   |");
	tab;printf(" ===============================================\n");
	tab;printf("   1. SHOP OWNER\n");
	tab;printf("   2. CUSTOMER\n ");
	tab;printf("   3. EXIT \n");
	tab;printf(" ===============================================\n\n");
	tab;printf("Enter your role: ");
	scanf("%d",&userChoice);
	while (userChoice>3 || userChoice <0) {
		tab;printf("Enter again (1 - 3): ");
		scanf("%d",&userChoice);
	}
	switch(userChoice) {
		case 1:
			system("cls");
			MenuOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
		case 2:
			system("cls");
			MenuCustomer(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
		case 3:
			tab;printf("The Program Will Exit !!!");
			exit(1);
			break;
	}
}

void MenuOwner(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	
	tab;printf(" ===============================================");
	tab;printf(" |                MENU SHOP OWNER              |");
	tab;printf(" ===============================================\n");
	tab;printf("   1. Display all Food                 \n");
	tab;printf("   2. Add new Food                     \n");
	tab;printf("   3. Sort all Food 				   \n");
	tab;printf("   4. Looking for Food         \n");
	tab;printf("   5. Delete Food       \n");
	tab;printf("   6. Delete All Food       \n");
	tab;printf("   7. Edit Price Of Food       \n");
	tab;printf("   8. Write to text file      \n");
	tab;printf("   9. Back to Role Menu      \n");
	tab;printf("   10. EXIT      \n");
	tab;printf(" ===============================================\n\n");
	tab;printf("Enter your choice: ");
	GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
		
}


void GetChoiceOfOwner(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	int userChoice,NPrice;
	/* Declare for Check Day */
	int daymfg,dayexp,monthmfg,monthexp,yearmfg,yearexp;  
	
	/* Declared for get input value to add  */
	char getname[20],getmfg[20],getexp[20];
	int rno,price,quantity,i;
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
							MenuOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
							GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
						} else printf("\n\nThe Program Will Exit!!!"); exit(1); break;
				} 
				else {
					DisplayFood(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
					fflush(stdin);
					MenuOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
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
			MenuOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
			
		case 3:
				if(isEmpty(*NumOfFood)) {
					system("cls");
					printf("\n<===============|SORT FOOD|===============>\n");
					printf("\nMini Market doestn't have any food to sort!\n");
					printf("\nBack to Menu Shop Owner (y/n): ");
					userChoice = getch();
						if(userChoice==121) {
							system("cls");
							MenuOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
							GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
						} else printf("\n\nThe Program Will Exit!!!"); exit(1); break;
				}
				GetChoiceOfSubSort(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
				fflush(stdin);
				MenuOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
				GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
		case 4:
			if(isEmpty(*NumOfFood)) {
					system("cls");
					printf("\n<===============|FIND-FOOD|===============>\n");
					printf("\nMini Market doestn't have any food to find!\n");
					printf("\nBack to Menu Shop Owner (y/n): ");
					userChoice = getch();
						if(userChoice==121) {
							system("cls");
							MenuOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
							GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
						} else printf("\n\nThe Program Will Exit!!!"); exit(1); break;
				}
			system("cls");
			MenuFind();
			scanf("%d", &userChoice);
			if(userChoice==1) {
				system("cls");
				printf("<=======================|FIND-FOOD|=======================>\n");
				printf("\nEnter name of food you wanna looking for: ");
				fflush(stdin);
				scanf("%20[^\n]s",getname);
				while(getname[0]==' ') {
				
						for(i=0;i<strlen(getname);i++) {
							getname[i] = getname[i+1];
						}
				
				}
				while(strlen(getname)<20) {
					strncat(getname, " ",20-strlen(getname));
				}
				FindByName(NumOfFood,Rno,Names,Price,Quantity,mfg,exp,getname);
				MenuOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
				GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
				
			} else if(userChoice==2) {
				printf("Enter Price Of Food you wanna looking for: ");
				scanf("%d",&price);
				FindByPrice(NumOfFood,Rno,Names,Price,Quantity,mfg,exp,price);
				MenuOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
				GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			} else {
				fflush(stdin);
				MenuOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
				GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			}
			break;
		case 5:
			if(isEmpty(*NumOfFood)) {
					system("cls");
					printf("\n<===============|DELETE-FOOD|===============>\n");
					printf("\nMini Market doestn't have any food to delete!\n");
					printf("\nBack to Menu Shop Owner (y/n): ");
					userChoice = getch();
						if(userChoice==121) {
							system("cls");
							MenuOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
							GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
						} else printf("\n\nThe Program Will Exit!!!"); exit(1); break;
				}
			printf("\nEnter name of food you wanna delete: ");
			fflush(stdin);
			scanf("%[^\n]s",getname);
			while(getname[0]==' ') {
				
						for(i=0;i<strlen(getname);i++) {
							getname[i] = getname[i+1];
						}
				}
			while(strlen(getname)<20) {
				strncat(getname, " ",20-strlen(getname));
			}
			DeleteFood(NumOfFood,Rno,Names,Price,Quantity,mfg,exp,getname);
			DisplayFood(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			MenuOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
		case 6:
			DeleteAllFood(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			DisplayFood(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			MenuOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
		case 7:
			system("cls");
			DisplayFood(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			printf("\nEnter name of food you wanna looking for: ");
				fflush(stdin);
				scanf("%20[^\n]s",getname);
			printf("\nEnter new price: ");
			scanf("%d", &NPrice);
				while(strlen(getname)<20) {
					strncat(getname, " ",20-strlen(getname));
				}
			ChangePrice(NumOfFood,Rno,Names,Price,Quantity,mfg,exp,getname,NPrice);
			DisplayFood(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			MenuOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
		case 8:
			WriteFile(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
		case 9:
			system("cls");
			ChooseRole(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
		default:
			tab;printf("The Program Will Exit !!!");
			exit(1);
	}	
}

void MenuCustomer(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	
	tab;printf(" ===============================================");
	tab;printf(" |                MENU CUSTOMER                |");
	tab;printf(" ===============================================\n");
	tab;printf("   1. Display all Food                 \n");
	tab;printf("   2. Buy Food \n");
	tab;printf("   3. Back To Role Menu  \n");
	tab;printf("   4. EXIT      \n");
	tab;printf(" ===============================================\n\n");
	tab;printf("Enter your choice: ");
	GetChoiceOfCustomer(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
	 
}

void GetChoiceOfCustomer(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	int userChoice,i,Bquantity,NumInCart;
	float Money,userMoney,userBanking;
	char getname[20];
	scanf("%d", &userChoice);
	switch(userChoice) {
		case 1:
				do {
					system("cls");
					printf("\nWelcome to Group 6's Mini Market!!\n");
					if(isEmpty(*NumOfFood)) {
						printf("Mini Market doestn't have any food to show!\n");
						printf("\nBack to Menu Shop Owner (y/n): ");
						userChoice = getch();
							if(userChoice==121) {
								system("cls");
								MenuCustomer(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
								GetChoiceOfCustomer(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
							} else printf("\n\nThe Program Will Exit!!!"); exit(1); break;
					} 
					else {
						DisplayFood(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
						fflush(stdin);
						MenuCustomer(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
						GetChoiceOfCustomer(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
					}
				} while(userChoice==121);

			break;
	
		case 2:
			
			do {
					system("cls");
					printf("\nWelcome to Group 6's Mini Market!!\t\t\t\t\t\t\t\t\tYour cart: %d\n", NumInCart);
					DisplayFood(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
					printf("\nEnter name of food you wanna buy: ");
					fflush(stdin);
					scanf("%20[^\n]s",getname);
					while(strlen(getname)<20) {
						strncat(getname, " ",20-strlen(getname));
					}
					printf("\nEnter quantity of food you wanna buy: ");
					scanf("%d", &Bquantity);
					BuyFood(NumOfFood,Rno,Names,Price,Quantity,mfg,exp,getname,Bquantity,&Money,&NumInCart);
					printf("\nPress 1 to Buy Continue or Press any button to get bill\n");
					userChoice = getch();
			} while(userChoice==49);
			if (NumInCart==0) {
					MenuCustomer(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
					GetChoiceOfCustomer(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			}
			else{ 
					printf("\nEnter your cash: ");
					scanf("%f", &userMoney);
					while(userMoney<Money) {
					printf("\nYou don't have enough cash to pay!\n\nYou must cash from your banking\n");
					printf("\nEnter your cash: ");
					scanf("%f", &userBanking);
					userMoney+=userBanking;
					
					}
					printf("\nPay Successfully! \n");
					printf("\nYour money remaining: %f VND", userMoney - Money);
					MenuCustomer(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
					GetChoiceOfCustomer(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
				}
			break;
			
		case 3: 
		system("cls");
		ChooseRole(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
		GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
		break;	
	
		default:
			tab;printf("Thank you for choosing our mini market!!!");
			exit(1);
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
						MenuOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
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
			MenuSubSort(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
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
			MenuOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
		}
	} while (CSort > 0 && CSort < 8);
	
}

/*    Function 1: Display     */

int isEmpty(int n) {
	return n == 0;
}


void DisplayFood(int*NumOfFood,int*Rno,char *Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	int i =0;
	printf("\t\t\t\t\t\t|MENU FOOD|");
	printf("\n===================================================================================="
	"====================================\n");
	printf("\nNO\t    NAME\t\tPRICE\t\t  QUANTITY\t     Manufacturing_Date    Expiry_Date\n\n");
	for(i=0;i<*NumOfFood;i++) {
		
		printf("%-10d  ",Rno[i]);
		printf("%-20s",Names[i]);
		printf("%-20d",Price[i]);
		printf("%-20d",Quantity[i]);
		printf("%-20s",mfg[i]);
		printf("%-10s\n",exp[i]);
		
	}
	printf("\n===================================================================================="
	"====================================\n");
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
   strcpy(temp,str1);
   strcpy(str1,str2);
   strcpy(str2,temp);
}

void Sort(int choice1,int choice2,int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	int i,j;
	char d[2],m[2],y[4];
	int day1,month1,year1,day2,month2,year2;
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
					if (strcmp(Names[i],Names[j])>0) {
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
					if (strcmp(Names[i],Names[j])<0) {
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
				for(i=0;i<(*NumOfFood)-1;i++) { //dd/mm/yyyy//
					strncpy(d, mfg[i], 2); day1 = atoi(d);
					strncpy(m, mfg[i]+3,2); month1 = atoi(m);
					strncpy(y, mfg[i]+6, 4); year1 = atoi(y);
					
						for(j=i+1;j<*NumOfFood;j++) {
						strncpy(d, mfg[j], 2); day2 = atoi(d);
						strncpy(m, mfg[j]+3,2); month2 = atoi(m);
						strncpy(y, mfg[j]+6, 4); year2 = atoi(y);
		
							if(year1>year2) {
								SwapInt(&Rno[i],&Rno[j]);
								SwapInt(&Price[i],&Price[j]);
								SwapInt(&Quantity[i],&Quantity[j]);
								SwapChar(Names[i],Names[j]);
								SwapChar(mfg[i],mfg[j]);
								SwapChar(exp[i],exp[j]);
							} else if (year1 == year2) {
								if (month1>month2) {
									SwapInt(&Rno[i],&Rno[j]);
									SwapInt(&Price[i],&Price[j]);
									SwapInt(&Quantity[i],&Quantity[j]);
									SwapChar(Names[i],Names[j]);
									SwapChar(mfg[i],mfg[j]);
									SwapChar(exp[i],exp[j]);
								} else if (month1 == month2) {
									if (day1 > day2) {
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
				} } else {
					for(i=0;i<(*NumOfFood)-1;i++) { 	/*dd/mm/yyyy*/
					strncpy(d, mfg[i], 2); day1 = atoi(d);
					strncpy(m, mfg[i]+3,2); month1 = atoi(m);
					strncpy(y, mfg[i]+6, 4); year1 = atoi(y);
					
						for(j=i+1;j<*NumOfFood;j++) {
						strncpy(d, mfg[j], 2); day2 = atoi(d);
						strncpy(m, mfg[j]+3,2); month2 = atoi(m);
						strncpy(y, mfg[j]+6, 4); year2 = atoi(y);
					
							if(year1<year2) {
								SwapInt(&Rno[i],&Rno[j]);
								SwapInt(&Price[i],&Price[j]);
								SwapInt(&Quantity[i],&Quantity[j]);
								SwapChar(Names[i],Names[j]);
								SwapChar(mfg[i],mfg[j]);
								SwapChar(exp[i],exp[j]);
							} else if (year1 == year2) {
								if (month1<month2) {
									SwapInt(&Rno[i],&Rno[j]);
									SwapInt(&Price[i],&Price[j]);
									SwapInt(&Quantity[i],&Quantity[j]);
									SwapChar(Names[i],Names[j]);
									SwapChar(mfg[i],mfg[j]);
									SwapChar(exp[i],exp[j]);
								} else if (month1 == month2) {
									if (day1 < day2) {
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
					}
				}	
				break;
		case 5:
			if(choice2==1) {
				for(i=0;i<(*NumOfFood)-1;i++) { //dd/mm/yyyy//
					strncpy(d, mfg[i], 2); day1 = atoi(d);
					strncpy(m, mfg[i]+3,2); month1 = atoi(m);
					strncpy(y, mfg[i]+6, 4); year1 = atoi(y);
					
						for(j=i+1;j<*NumOfFood;j++) {
						strncpy(d, mfg[j], 2); day2 = atoi(d);
						strncpy(m, mfg[j]+3,2); month2 = atoi(m);
						strncpy(y, mfg[j]+6, 4); year2 = atoi(y);
					
							if(year1<year2) {
								SwapInt(&Rno[i],&Rno[j]);
								SwapInt(&Price[i],&Price[j]);
								SwapInt(&Quantity[i],&Quantity[j]);
								SwapChar(Names[i],Names[j]);
								SwapChar(mfg[i],mfg[j]);
								SwapChar(exp[i],exp[j]);
							} else if (year1 == year2) {
								if (month1<month2) {
									SwapInt(&Rno[i],&Rno[j]);
									SwapInt(&Price[i],&Price[j]);
									SwapInt(&Quantity[i],&Quantity[j]);
									SwapChar(Names[i],Names[j]);
									SwapChar(mfg[i],mfg[j]);
									SwapChar(exp[i],exp[j]);
								} else if (month1 == month2) {
									if (day1 < day2) {
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
				} } else {
					for(i=0;i<(*NumOfFood)-1;i++) { 	/*dd/mm/yyyy*/
					strncpy(d, mfg[i], 2); day1 = atoi(d);
					strncpy(m, mfg[i]+3,2); month1 = atoi(m);
					strncpy(y, mfg[i]+6, 4); year1 = atoi(y);
					
						for(j=i+1;j<*NumOfFood;j++) {
						strncpy(d, mfg[j], 2); day2 = atoi(d);
						strncpy(m, mfg[j]+3,2); month2 = atoi(m);
						strncpy(y, mfg[j]+6, 4); year2 = atoi(y);
					
							if(year1>year2) {
								SwapInt(&Rno[i],&Rno[j]);
								SwapInt(&Price[i],&Price[j]);
								SwapInt(&Quantity[i],&Quantity[j]);
								SwapChar(Names[i],Names[j]);
								SwapChar(mfg[i],mfg[j]);
								SwapChar(exp[i],exp[j]);
							} else if (year1 == year2) {
								if (month1>month2) {
									SwapInt(&Rno[i],&Rno[j]);
									SwapInt(&Price[i],&Price[j]);
									SwapInt(&Quantity[i],&Quantity[j]);
									SwapChar(Names[i],Names[j]);
									SwapChar(mfg[i],mfg[j]);
									SwapChar(exp[i],exp[j]);
								} else if (month1 == month2) {
									if (day1 > day2) {
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
			MenuOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			GetChoiceOfOwner(NumOfFood,Rno,Names,Price,Quantity,mfg,exp);
			break;
	}
}
/* File Processing */

void ReadFile(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
		char getexp[20],getmfg[20], getname[20];
		int rno,price,quantity;
			Names[*NumOfFood] = malloc(strlen(getname) + 1);
	   		mfg[*NumOfFood] = malloc(strlen(getmfg) + 1);
	  		exp[*NumOfFood] = malloc(strlen(getexp) + 1);
		int i = 0;
		FILE* fp;
		fp = fopen("MyFood1.txt", "r");
		if(fp) {
			while(fscanf(fp, "%10d %20[^\n] %20d %20d %20[^\n] %10[^\n]\n",&rno,getname,&price,&quantity,getmfg,getexp)==6) {
				
				Names[*NumOfFood] = malloc(strlen(getname) + 1);
	   			mfg[*NumOfFood] = malloc(strlen(getmfg) + 1);
	  			exp[*NumOfFood] = malloc(strlen(getexp) + 1);
				Rno[*NumOfFood] = rno;
				Price[*NumOfFood] = price;
				Quantity[*NumOfFood] = quantity;
				strcpy(Names[*NumOfFood],getname);
				strcpy(mfg[*NumOfFood],getmfg);
				strcpy(exp[*NumOfFood],getexp);

				(*NumOfFood)++;
				/* Read until end of file */
				if(feof(fp)) {
					break;
				}	
			}
		}
		fclose(fp);
	}


void WriteFile (int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	getchar();
	char fName[26];
	printf("Enter FileName: ");
	gets(fName);
	FILE* fp = fopen(fName, "a");
	int i;
	for(i = 0; i < *NumOfFood; i++) {
		fprintf(fp, "%-10d %-20s %-10d %-10d %-20s %-20s \n",Rno[i], Names[i], Price[i], Quantity[i], mfg[i], exp[i]);
	}
	fclose(fp);
}


/* Function 4: Looking Food */

	void MenuFind() {
	
		tab;printf(" ===============================================");
		tab;printf(" |                  FIND-FOOD                  |");
		tab;printf(" ===============================================\n");
		tab;printf("   1. Find food depend on Name                 \n");
		tab;printf("   2. Find food depend on Price \n"); 
		tab;printf("   3. Back to Shop Owner Menu     \n");
		tab;printf(" ===============================================\n\n");
		tab;printf("Enter your choice: ");

	}
	
	void FindByName(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],char getname[]) {
		int a;
		int i,check=0;
		
		for(i=0;i<*NumOfFood;i++) {
			a = strcmp(strlwr(Names[i]),strlwr(getname));
			if (a==0) {
				check=1;
				printf("\n===================================================================================="
				"====================================\n");
				printf("NO\t    NAME\t\tPRICE\t\t  QUANTITY\t     Manufacturing_Date    Expiry_Date\n\n");
					
					printf("%-10d  ",Rno[i]);
					printf("%-20s",Names[i]);
					printf("%-20d",Price[i]);
					printf("%-20d",Quantity[i]);
					printf("%-20s",mfg[i]);
					printf("%-10s\n",exp[i]);
					
				
				printf("\n===================================================================================="
				"====================================\n");
			}
		} 
		if(check==0) {
			printf("\nNOT FOUND!\n");
		} 
	}


	void FindByPrice(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],int price) {
		int i,check=0;
		
		for(i=0;i<*NumOfFood;i++) {
			if (Price[i]==price) {
				check=1;
				printf("\n===================================================================================="
				"====================================\n");
				printf("NO\t    NAME\t\tPRICE\t\t  QUANTITY\t     Manufacturing_Date    Expiry_Date\n\n");
			
					printf("%-10d  ",Rno[i]);
					printf("%-20s",Names[i]);
					printf("%-20d",Price[i]);
					printf("%-20d",Quantity[i]);
					printf("%-20s",mfg[i]);
					printf("%-10s\n",exp[i]);
				
				printf("\n===================================================================================="
				"====================================\n");
	
			}
		}
		if(check==0) {
			printf("\nNOT FOUND!\n");
		}
	}
	
	
/* Function 5,6: Delete */

void DeleteFood(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],char getname[]) {
	int i,check=0,j,a;
	for(i=0;i<*NumOfFood;i++) {
		a = strcmp(strlwr(Names[i]),strlwr(getname));
		if (a==0) { check=1;
			for(j=i+1;j<*NumOfFood;j++) {
				Rno[j-1] = Rno[j];
				Price[j-1] = Price[j];
				Quantity[j-1] = Quantity[j];
				strcpy(Names[j-1],Names[j]);
				strcpy(mfg[j-1],mfg[j]);
				strcpy(exp[j-1],exp[j]);
			}
			(*NumOfFood)--;
		}
	} 
	if(check==0) {
			printf("\nNOT FOUND!\n");
		} else {
			printf("\nDELETED SUCCESSFULLY!!!\n");
		}
		
}

void DeleteAllFood(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	(*NumOfFood)=0;
	int*Rno_=realloc(Rno,0*sizeof(int));
	int*Price_=realloc(Price,0*sizeof(int));
	int*Quantity_=realloc(Quantity,0*sizeof(int));
	char**Names_=realloc(Names,0*sizeof(char*));
	char**mfg_=realloc(mfg,0*sizeof(char*));
	char**exp_=realloc(exp,0*sizeof(char*));
	free(Rno_);
	free(Price_);
	free(Quantity_);
	free(Names_);
	free(mfg_);
	free(exp_);
	
}



/* Function 7: Change Price  */

void ChangePrice(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],char getname[],int NPrice) {
	int a;
		int i,check=0;
		
		for(i=0;i<*NumOfFood;i++) {
			a = strcmp(strlwr(Names[i]),strlwr(getname));
			if (a==0) {
				check=1;
				Price[i] = NPrice;
			}
		} 
		if(check==0) {
			printf("\nNOT FOUND!\n\n");
		} else {
			printf("\nChange Price Successfully!\n\n");
		}
}


/* CUSTOMER PROCESSING */

void BuyFood(int*NumOfFood,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],char getname[],int BQuantity,float *Money,int * NumInCart) {
	int a;
		int i,check=0;
		if (BQuantity==0) {
			printf("\nPls Behave Like a Human :)))))\n");
		}
		for(i=0;i<*NumOfFood;i++) {
			a = strcmp(strlwr(Names[i]),strlwr(getname));
			if (a==0) {
				check=1;
				Quantity[i]=Quantity[i]-BQuantity;
				(*Money)+=(Price[i]*BQuantity);
					(*NumInCart)++;
			}
		} 
		if(check==0 && BQuantity!=0) {
			printf("\nNOT FOUND!\n");
		} else if (check!=0 && BQuantity!=0) {
			printf("\nBuy Successfully\n");
		}	
		
}


/*   Main Function  */

int main() {
	
/* Declare for count element, dynamic allocate */
	int NumberOfFood=0,i;

/* Declare dynamic array */
	int*Rno = (int*)calloc(10,sizeof(int));
	int*Price = (int*)calloc(10,sizeof(int));
	int*Quantity = (int*)calloc(10,sizeof(int));
	
/* Declare array of char pointer */
	char **Names = (char**)calloc(10,sizeof(char*));
	char **MFG = (char**)calloc(10,sizeof(char*));
	char **EXP = (char**)calloc(10,sizeof(char*));
	

/* Get value from file and store into each array */
	ReadFile(&NumberOfFood,Rno,Names,Price,Quantity,MFG,EXP);
		
/*=====================================================*/
	ChooseRole(&NumberOfFood,Rno,Names,Price,Quantity,MFG,EXP);
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
