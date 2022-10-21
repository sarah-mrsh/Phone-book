#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define NAMES 50
#define EMAIL 20
#define PHONE 20
#define TOWN 10
#define SIZE 500

void welcome_note();
void record();
void view();
void search();
void del_rec();
char info[SIZE];

struct addbook
{
	char name [NAMES] ;
	char sname [NAMES] ;
	char emailadd [EMAIL] ;
	char town [TOWN];
	char phone [PHONE];
} addbook;

FILE *Records;
FILE *rectemp;

int main()
{
	int choice=0;
		system("cls");
		system("color 1");
		fflush(stdin);
		welcome_note();
		printf("\nEnter your Choice here \t");
		scanf("%i",&choice);
		fflush(stdin);
		
	switch (choice)
	{

			case 1:
				{
					system("cls");
					view();
				break;
				}

			case 2:
				{
					system("cls");
					record();
				break;
				}

			case 3:
				{	system("cls");
					search();
				break;
				}

			case 4:
				{	system("cls");
					del_rec();
				break;
				}




		case 5:
			{
				system("cls");

			break;
			}
		default:
			{

				printf("Please Only Choose Between NO. 1-5\n"); system("pause");
				system("cls");
				main();
			}


	}

}

void record()
{
		char choice2;
  
       do
	{	
			Records = fopen("Records.txt","a+");


	 		
			printf("Enter Name\n");
			fflush(stdin);
			scanf("%s",addbook.name);
			

			printf("Enter Second Name\n");
			fflush(stdin);
			scanf("%s",addbook.sname);
			

			printf("Enter E-mail address\n");
			fflush(stdin);
			scanf("%s",addbook.emailadd);
			

			printf("Enter town\n");
			fflush(stdin);
			scanf("%s",addbook.town);
			

			printf("Enter Phone Number no\n");
			fflush(stdin);
			scanf("%s",addbook.phone);
			
			fprintf(Records,"%s %s %s %s %s \n",addbook.name,addbook.sname,addbook.emailadd,addbook.town,addbook.phone);

			fflush(stdin);
			
			fclose(Records);
		
			printf("WOULD LIKE TO CONTINUE? Y/N \n");
			scanf("%c",&choice2);
			fflush(stdin);

		if (choice2=='n'||choice2=='N')
		{
			system("cls");
			main();

		}
	}while(choice2=='y'||choice2=='Y');
}

void view()
{
char choice3;

		Records = fopen("Records.txt","a+");
		do
		{
			fgets(info,SIZE,Records);
			printf("%s\n",info);

		}while(!feof(Records));
			fclose(Records);
			system("pause");
			printf("Search for records??(Y/N)\n");
			scanf("%c",&choice3);
			fflush(stdin);
			if (toupper(choice3)=='Y')
			{
			search();
		}
		else if(toupper(choice3)=='N')
		{
			fclose(Records);
			system("pause");
			system("cls");
			main();
		}

		else
		{
			fclose(Records);
			system("cls");
		}
}

void welcome_note()
{
		printf("\t\t\t\t\t               **************            \n");
		printf("\t\t\t\t\t               * Phone Book *            \n");
		printf("\t\t\t\t\t ****************************************\n");
		printf("\t\t\t\t\t *                 Menu                 *\n");
		printf("\t\t\t\t\t ****************************************\n");
		printf("\t\t\t\t\t *	    CHOOSE BETWEEN (1-5)	*\n");
		printf("\t\t\t\t\t ****************************************\n");
		printf("\t\t\t\t\t *  1	        : View contacts		*\n");
		printf("\t\t\t\t\t ****************************************\n");
		printf("\t\t\t\t\t *  2		: Add contacts	        *\n");
		printf("\t\t\t\t\t ****************************************\n");
		printf("\t\t\t\t\t *  3		: Search contacts  	*\n");
		printf("\t\t\t\t\t ****************************************\n");
		printf("\t\t\t\t\t *  4		: Delete contacts	*\n");
		printf("\t\t\t\t\t ****************************************\n");
		printf("\t\t\t\t\t *  5		: EXIT			*\n");
		printf("\t\t\t\t\t ****************************************\n");
}

void search()
{

    char Target[SIZE];
	
	int Found=0;
	if((Records=fopen("Records.txt","r"))==NULL)

		printf("NO RECORDS THE FILE EMPTY!!!\n\n");
	else
	{
		system("cls");
		printf("\n\n");
		printf("\t----------------- SEARCH --------------");
		printf("\n\n");
		printf("\tEnter Name to search:");
		fflush(stdin);
		scanf("%s",Target);
		while(!feof(Records)&& Found==0)
		{
			fscanf(Records,"%s %s %s %s %s  ",addbook.name,addbook.sname,addbook.emailadd,addbook.phone);
			if(strcmp(Target,addbook.name)==0)
			Found=1;
		}
		if(Found)
		{
			printf(".......FILE FOUND\n");
			system("pause");
			system("cls");
			printf("1 FILE FOUND : \n\n\n");
			printf("First Name: %s\n",addbook.name);
			printf("Second Name: %s\n",addbook.sname);
			printf("E-mail: %s\n",addbook.emailadd);
			printf("Town: %s\n",addbook.town);
			printf("Phone Number: %s\n",addbook.phone);
			system("pause");
		main();
		}
		else if(!Found)
		{
			printf("SORRY FILE NOT FOUND\n");
			system("pause");
			main();
		}
		fclose(Records);
}
}
	void del_rec()
{
    char Target[SIZE];
	int Found=0;
		system("cls");
	rectemp=fopen("rectemp.txt","w");
	if((Records=fopen("Records.txt","r"))==NULL)
		printf("NO RECORDS FILE EMPTY!!!\n\n");

	else{
		printf("\n\n");
		printf("\t--------------- DELETE ----------------");
		printf("\n\n");
		printf("\tEnter Name to Delete: ");
		fflush(stdin);
		gets(Target);
		while(!feof(Records))
			{
			fscanf(Records,"%s %s %s %s %s ",addbook.name,addbook.sname,addbook.emailadd,addbook.town,addbook.phone);
			if(feof(Records))
				break;
			if(strcmp(Target,addbook.name)!=0)
				fprintf(rectemp,"%s %s %s %s %s  \n",addbook.name,addbook.sname,addbook.emailadd,addbook.town,addbook.phone);
			else {
				Found=1;
				printf(".......FILE FOUND\n");
				system("pause");
				printf("First Name:%s\n",addbook.name);
				printf("Second Name:%s\n",addbook.sname);
				printf("E-mail:%s\n",addbook.emailadd);
				printf("Town: %s\n",addbook.town);
				printf("Phone Number: %s\n",addbook.phone);
				fflush(stdin);
				system("pause");
				}
			}
			if (!Found)
			{
			printf("\tRECORD NOT FOUND\n");
			}
		printf("\tRECORD DELETED!!\n");

		fclose(Records);
		fclose(rectemp);
		remove("Records.txt");
		rename("rectemp.txt","Records.txt");
	main();	}

	}