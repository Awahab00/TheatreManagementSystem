#include<stdio.h>
#include<stdlib.h>
#include"moviedetails.c"
#include"decleration.c" 
#include<strings.h>
struct moviedetails person[300];
int count=0;
int id2=1000;
int main()
{
	int **seat,choice,price=500,slection,i;
	seat=(int **)calloc(101,sizeof(int *));
	for (i=0;i<3;i++)
		*(seat+i)=(int *)calloc(101,sizeof(int ));
	int x;
	while(x!=5)
	{
		choice=choice1();
		switch(choice)
		{
			case 1:
				price=changeprize(price);
				break;
			case 2:
				details();
				break;	
			case 3:	
				slection=movie();
				reservation(seat[slection-1],price,slection);	
				count++;
				break;
			case 4:
				slection=cmovie();	
				cancel(seat[slection-1]);	
				break;
			case 5:
				x=5;
				break;
			default: 
				printf("chioce not available\n");
				break;	
		}
	}
}
int changeprize(int prize)
{
	char pass[10],pak[10]="pakistan";
	printf("enter the password to change price of ticket");
	scanf("%s",&pass);
	if (strcmp(pass,pak)==0)
	{
		printf("please enter new prize");
		scanf("%d",&prize);
	}
	else 
		printf("entered password is wrong");
	return prize;
}
void reservation(int *array,int price,int slection)
{          
		int i,j;
		printf("\n                                SCREEN\n\n\n");
		for (i=1;i<=100;i++)
		{
			if (array[i]==0)
				printf("%d\t",i);
			else 
				printf("*\t",i);	
			if(i%10==0)
				printf("\n\n");
		}
		printf("please enter your name");
		scanf(" %19[^\n]%*[^\n]",&person[count].name);
		printf("please enter your phone number");
		scanf("%u",&person[count].phone);
		printf("which seat number you want?");
		scanf("%d",&j);
		if (j>100||j<1)
			{
				printf("seat1 number is unavailable in this theater\n");
				printf("please renter seat number");
				scanf("%d",&j);
			}
		if (array[j]==1)
			{
				printf("sorry this ticket is already boocked please choose another seat\n");
				scanf("%d",&j);
			}
		else			
			array[j]=1;
		person[count].seat=j;
		if (slection==1)
			ticket1(j,person[count].name,id2,price);
		else if (slection==2) 	
			ticket2(j,person[count].name,id2,price);
		else 
			ticket3(j,person[count].name,id2,price);			
		id2++;	
}
int choice1(void)
{
	int choice;
	printf("                     Enter your choice:\n");
	printf(" ==================================================================\n");
	printf("||             1- for edit price of ticket (only admin):          ||\n");
	printf("||             2- for want to see reserved tickets (only admin):  ||\n");
	printf("||             3- for want to puchase ticket:                     ||\n");
	printf("||             4- for cancel the seat:                            ||\n");
	printf("||             5- for exit:                                       ||\n");
	printf("||================================================================||");
	scanf("%d",&choice);
	return choice;
}
void cancel(int *array)
{
      int Cseat,i,stop;
	  printf("please enter ID number of ticket");
	  scanf("%d",&Cseat);
	  for (i=0;i<300;i++)
	  {
	  		if(Cseat==person[i].id)
	  		{
					 stop=5;
					 system("cls");
					 printf("%s your seat is %d cancelled",person[i].name,person[i].seat);
					 array[person[i].seat]=0;
					 i=300;
	  		}
	  }
	  if (stop!=5)	
	  		printf("ticket ID number is incorrect please enter right one to cancel ticket\n");
}
void ticket1(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Fast & furious 8\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 15-05-2017\n");
        printf("\t                                              Time      : 08:00pm\n");
        printf("\t                                              Hall      : 02\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
		person[count].id=id2;
        printf("\t============================================================\n");
        return;
}
void details(void)
{
	int i;
	char pass[10],pak[10]="pakistan";
	printf("enter the password to see details");
	scanf("%s",&pass);
	if (strcmp(pass,pak)==0)
	{
		for (i=0;i<count;i++)
		{
			printf("seat no: %d is booked by %s booking id is %d\n",person[i].seat,person[i].name,person[i].id);
		}
	}
	else                                                 
		printf("entered password is wrong");
	
}             
int movie(void)
{
	int i;
	system("cls");
	printf("\t\t\twhich movie you want to see?\n");
	printf("\t\t\t----------------------------\n\n");
	printf("\t\t\tpress 1 for fast and furious\n\n");
	printf("\t\t\tpress 2 for bhaubhali 2\n\n");
	printf("\t\t\tpress 3 for pirates of the caribean\n");
	scanf("%d",&i);
	system("cls");
	return i;
}
void ticket2(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Bhaubhali 2\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 15-05-2017\n");
        printf("\t                                              Time      : 09:00pm\n");
        printf("\t                                              Hall      : 03\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
        person[count].id=id2;
        printf("\t============================================================\n");
        return;
}
int cmovie(void)
{
	int i;
	printf("\t\t\twhich movie ticket you want to cancel\n");
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\tpress 1 for fast and furious 8\n\n");
	printf("\t\t\tpress 2 for bahubali 2\n\n");
	printf("\t\t\tpress 3 for pirates of the caribean\n");
	scanf("%d",&i);
	return i;		
}
void ticket3(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : pirates of the caribean \n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 15-05-2017\n");
        printf("\t                                              Time      : 10:00pm\n");
        printf("\t                                              Hall      : 04\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
        person[count].id=id2;
        printf("\t============================================================\n");
        return;
}
