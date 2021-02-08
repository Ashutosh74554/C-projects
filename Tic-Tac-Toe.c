/*TIC-TAC-TOE Game
Minor project*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <windows.h>


char box[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char mark[2] = {'X', 'O'};
char win;

int check_win();
void board();
void options();

void gotoxy(short x, short y)                                              
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
 	COORD pos = {x,y};
 	SetConsoleCursorPosition(hStdout, pos);
}

int main()
{
	
	char ch, play1, play2;
	
	gotoxy(20, 5);
	printf("***************Tic-Tac-Toe***************");
	while (1)
	{
		options();
		ch = getchar();
		
		switch(ch)
		{
			case '1':
				play1 = 'X';
				play2 = 'O';
				gotoxy(35, 16);
				printf("Player 1 is 'X'");
				gotoxy(35, 18);
				printf("Player 2 is 'O'");
				gotoxy(35, 20);
				printf("Press Any Key to Begin!!!!");
				getch();
				start_game(play1, play2);	 
				break;
			
			case '2':
				play1 = 'O';
				play2 = 'X';
				gotoxy(35, 16);
				printf("Player 1 is 'O'");
				gotoxy(35, 18);
				printf("Player 2 is 'X'");
				gotoxy(35, 20);
				printf("Press Any Key to Begin!!!!");
				getch();
				start_game(play1, play2);
				break;
				
			case '3': 
				exit(1);
			
		}
	}
	
}

void options()
{
	gotoxy(35, 8);
	printf("1. Player 1 as X");
	gotoxy(35, 10);
	printf("2. Player 2 as O");
	gotoxy(35, 12);
	printf("3. Exit");
	gotoxy(35, 14);
	printf("Enter your choice: ");
}


void board()
{
	system("cls");
    printf("     |     |     \n");
    printf(" %c   | %c   | %c   \n",box[1],box[2],box[3]);
    printf("_____|_____|_____\n");
    printf("     |     |      \n");
    printf(" %c   | %c   | %c   \n",box[4],box[5],box[6]);
    printf("_____|_____|_____\n");
    printf(" %c   | %c   | %c    \n",box[7],box[8],box[9]);
    printf("     |     |     \n");
}

void start_game(char play1, char play2)
{
	board();
	
	char pos1, pos2;
	
	while(1)
	{
		
		if((check_win()==1) || (check_win()==0))
		{
			break;
		}
		
		printf("\nPlayer 1, enter the position: ");
		fflush(stdin);
		pos1 = getche();
		mark_board(pos1, play1);
		board();
		
		if((check_win()==1) || (check_win()==0))
		{
			break;
		}
		
		printf("\nPlayer 2, enter the position: ");
		fflush(stdin);
		pos2 = getche();
		mark_board(pos2, play2);
		board();
		
	}
	
	if(win==0)
		printf("\n\nIt's a draw");
		
	else
	{
		if(win == play1)
			printf("\n\nPlayer 1 won");
		else
			printf("\n\nPlayer 2 won");
	}
	exit(1);
}

void mark_board( char choice, char mark)
{
    if(choice=='1' && box[1]=='1')
        box[1]=mark;
    else if(choice=='2' && box[2]=='2')
        box[2]=mark;
    else if(choice=='3' && box[3]=='3')
        box[3]=mark;
    else if(choice=='4' && box[4]=='4')
        box[4]=mark;
    else if (choice=='5' && box[5]=='5')
        box[5]=mark;
    else if (choice=='6' && box[6]=='6')
        box[6]=mark;
    else if (choice=='7' && box[7]=='7')
        box[7]=mark;
    else if (choice=='8' && box[8]=='8')
        box[8]=mark;
    else if (choice=='9' && box[9]=='9')
        box[9]=mark;
    else 
    	printf("\nInvalid Entry");
}

int check_win()
{
	if(box[1]==box[2] && box[2]==box[3])
	{
		win = box[1];
        return 1;
    }
    else if(box[4]==box[5] && box[5]==box[6])
    {
		win = box[4];
        return 1;
    }                                   
    else if (box[7]==box[8] && box[8]==box[9])
    {
		win = box[7];
        return 1;
    }
    else if (box[1]==box[4] && box[4]==box[7])
    {
		win = box[1];
        return 1;
    }
    else if(box[2]==box[5] && box[5]==box[8])
    {
		win = box[2];
        return 1;
    }
    else if(box[3]==box[6] && box[6]==box[9])
    {
		win = box[3];
        return 1;
    }
    else if(box[1]==box[5] && box[5]==box[9])
    {
		win = box[1];
        return 1;
    }
    else if(box[3]==box[5] && box[5]==box[7])
    {
		win = box[3];
        return 1;
    }
    else if(box[1]!= '1' && box[2]!= '2' && box[3]!= '3' && box[4]!= '4'&& box[5]!= '5' && box[6]!= '6'&& box[7]!= '7' && box[8]!= '8' && box[9]!='9')
        return 0;
    else
    	return -1;
}

