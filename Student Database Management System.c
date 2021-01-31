/*Student Database Management System
  MINOR PROJECT
*/  
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
void gotoxy(short col, short row);
void main()
{
	FILE *fp, *ft;
	char another, choice;
	
	struct student
	{
		char name[20];
		int age;
		float per;
	};
	struct student s;
	char studentname[40];
	long int rec_size;
	
	fp=fopen("StudentDBMS.DAT", "rb+");
	if(fp==NULL)
	{
		fp=fopen("StudentDBMS.DAT", "ab+");
		if(fp==NULL)
		{
			puts("Can't open file");
			exit(1);
		}
	}
	rec_size = sizeof(s);
	while(1)
	{
		system("cls");
		gotoxy(30,10);
		printf("1. Add Record");
		gotoxy(30,12);
		printf("2. List Record");
		gotoxy(30,14);
		printf("3. Modify Record");
		gotoxy(30,16);
		printf("4. Delete Record");
		gotoxy(30,18);
		printf("0. Exit");
		gotoxy(30,22);
		printf("Your choice: ");
		fflush(stdin);
		choice=getche();
		switch(choice)
		{
			case '1':
				fseek(fp,0,SEEK_END);
				another= 'Y';
				while(another == 'Y' || another == 'y')
				{
					printf("\nEnter data of the student: ");
					scanf("%s %d %f", s.name, &s.age, &s.per);
					fwrite(&s, rec_size, 1, fp);
					printf("\nAdd another record (Y/N): ");
					fflush(stdin);
					another=getche();
				}
				break;
			case '2':
				rewind(fp);
				while(fread(&s, rec_size, 1, fp)==1)
					printf("\n\t\t%s %d %f", s.name , s.age, s.per);
					
				printf("\nType q to return to main menu: ");
				char q=getche();
				if(q=='Q' || q=='q')
					break;
			case '3':
				another ='Y';
				while(another=='y' || another=='Y')
				{
					printf("\nEnter name of the student to modify: ");
					scanf("%s", studentname);
					rewind(fp);
					int count=0;
					while(fread(&s, rec_size, 1, fp)==1)
					{
						if(strcmp (s.name, studentname)==0)
						{
							printf("\nEnter new data: ");
							scanf("%s %d %f", s.name, &s.age, &s.per);
							fseek(fp, -rec_size, SEEK_CUR);
							fwrite(&s, rec_size, 1, fp);
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
				another='Y';
				while(another=='Y' || another=='y')
				{
					printf("\nEnter name of student to delete: ");
					scanf("%s", studentname);
					ft=fopen("Tstudent.DAT", "wb");
					rewind(fp);
					while(fread(&s, rec_size, 1, fp)==1)
					{
						if(strcmp(s.name, studentname)!=0)
							fwrite(&s, rec_size,1 ,ft);
					}
					fclose( fp );
					fclose( ft );
					remove ("StudentDBMS.DAT");
					rename ("Tstudent.DAT", "StudentDBMS.DAT");
					fp = fopen ("StudentDBMS.DAT", "rb+");
					printf("Delete another record (Y/N): ");
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
	COORD pos ={x,y};
	SetConsoleCursorPosition(hStdout, pos);
}
