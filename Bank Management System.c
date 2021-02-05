/*Bank Management System
  MINOR Project */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
void gotoxy(short x, short y);
void main()
{
	FILE *fp, *ft;
	char choice, another;
	struct customer
	{
		char name[20];
		int acc_no;
		int balance;
	};
	struct customer c;
	char customername[20];
	long int rec_size;
	
	fp = fopen("BANKDBMS.DAT", "r+");
	if (fp==NULL)
	{
		fp= fopen("BANKDBMS.DAT", "a+");
		if(fp==NULL)
		{
			puts("Can't open file");
			exit(1);
		}
	}
	rec_size= sizeof(c);
	while(1)
	{
		system("cls");
		gotoxy(20,10);
		printf("1. Add customer");
		gotoxy(20,12);
		printf("2. List customers");
		gotoxy(20,14);
		printf("3. Update record");
		gotoxy(20,16);
		printf("4. Add money");
		gotoxy(20,18);
		printf("5. Withdraw money");
		gotoxy(20,20);
		printf("6. Delete customer");
		gotoxy(20,22);
		printf("0. EXIT");
		gotoxy(20,24);
		printf("Your choice: ");
		fflush(stdin);
		choice=getche();
		switch(choice)
		{
			case '1':
				fseek(fp, 0, SEEK_END);
				another = 'Y';
				while(another == 'y' || another == 'Y')
				{
					printf("\n\t\tEnter name, Account number and Amount: ");
					scanf("%s %d %d", c.name, &c.acc_no, &c.balance);
					fwrite(&c, rec_size, 1, fp);
					printf("\n\t\tAdd another customer (Y/N): ");
					fflush(stdin);
					another=getche();
				}
				break;
			case '2':
				rewind(fp);
				while(fread(&c, rec_size, 1, fp)==1)
					printf("\n\n\t\t%s %d %d", c.name, c.acc_no, c.balance);
				
				printf("\nType q to return to main menu: ");
				char q= getche();
				if(q=='Q' || q=='q')
					break;
			case '3':
				another = 'y';
				while(another=='Y' || another=='y')
				{
					printf("\n\n\t\tEnter name of customer to update: ");
					scanf("%s", customername);
					rewind(fp);
					int count = 0;
					while(fread(&c, rec_size, 1, fp)==1)
					{
						if(strcmp(c.name, customername)==0)
						{
							printf("\n\t\tEnter new name, Account number: ");
							scanf("%s %d", c.name, &c.acc_no);
							fseek(fp, -rec_size, SEEK_CUR);
							fwrite(&c, rec_size, 1, fp);
							count++;
							break;
						}
					}
					if(count==0)
						printf("Record not found\n");
					printf("\nModify another record (Y/N): ");
					fflush(stdin);
					another=getche();
				}
				break;
			case '4':
				another = 'y';
				while(another=='y' || another=='Y')
				{
					printf("\n\n\t\tEnter name of the customer: ");
					scanf("%s", customername);
					rewind(fp);
					int add;
					while(fread(&c, rec_size, 1, fp)==1)
					{	
						if(strcmp(customername,c.name)==0)
						{
							printf("\n\t\tEnter the amount: ");
							scanf("%d", add);
							c.balance+=add;
							fseek(fp, -rec_size, SEEK_CUR);
							fwrite(&c, rec_size, 1, fp);
							printf("\n\t\tYour current balance: %d", c.balance);	
						}
					}
					printf("\nAdd to another account (Y/N): ");
					fflush(stdin);
					another=getche();
			    }
			    break;
			case '5':
					while(fread(&c, rec_size, 1, fp)==1)
				another = 'y';
				while(another=='y' || another=='Y')
				{
					printf("\n\n\t\tEnter name of customer: ");
					scanf("%s", customername);
					rewind(fp);
					int deduct;
					while(fread(&c, rec_size, 1, fp)==1)
					{	
						if(strcmp(customername,c.name)==0)
						{
							printf("\n\t\tEnter the amount: ");
							scanf("%d", deduct);
							c.balance-=deduct;
							fseek(fp, -rec_size, SEEK_CUR);
							fwrite(&c, rec_size, 1, fp);
							printf("\n\t\tYour current balance: %d", c.balance);	
						}
				    }
				    printf("\n\t\tWithdraw from another account (Y/N): ");
				    fflush(stdin);
				    another=getche();
	   		   }
	   		   break;
	   		case '6':
	   			another='Y';
				int count1=0, count2=0;
				while(another=='Y' || another=='y')
				{
					printf("\n\n\t\tEnter name of customer to delete: ");
					scanf("%s", customername);
					ft=fopen("TBANK.DAT", "w");
					rewind(fp);
					while(fread(&c, rec_size, 1, fp)==1)
					{
						count1++;
						if(strcmp(c.name, customername)!=0)
						{
							count2++;
							fwrite(&c, rec_size,1 ,ft);
						}	
					}
					fclose( fp );
					fclose( ft );
					if(count1==count2)
						printf("\nRecord not found\n");
					remove ("BANKDBMS.DAT");
					rename ("TBANK.DAT", "BANKDBMS.DAT");
					fp = fopen ("BANKDBMS.DAT", "rb+");
					printf("\n\n\t\tDelete another record (Y/N): ");
					fflush (stdin);
					another = getche();
				}
				break;
			case '0':
				fclose (fp);
				exit (0);
	}
}
}
void gotoxy(short x, short y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x, y };
	SetConsoleCursorPosition( hStdout, pos );
}
