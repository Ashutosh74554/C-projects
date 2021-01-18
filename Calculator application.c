//Calculator program
#include<stdio.h>
#include<math.h>
#include<conio.h>
int main()
{
	printf("\n\n\t\t\t**********Welcome to My Calculator**********");
	printf("\n\t\t\tCalculate anything from the given set of functions");
	int i=1;
	char opt;
	while(i)
	{
		options();
		printf("\n\n\t\t\t");
		opt=getch();
		switch(opt)
		{
			case '+':
				add();
				break;
			case '-':
				sub();
				break;
			case '*':
				mul();
				break;
			case '/':
				div();
				break;
			case 'r':
			case 'R':
				mod();
				break;
			case'^':
				power();
				break;
			case 's':
			case 'S':
				sqr();
				break;
			case '!':
				fact();
				break;
			case 'Q':
			case 'q': 
				exit(0);		
				break;
			case 'D':
			case 'd':
				break;
			default:
				printf("\n\t\t\tUnavailable option");

		}
	}
	return 0;
}

void options()
{
	printf("\n\n\t\t\tEnter your options: ");
	printf("\n\n\t\t\tEnter + for addition");
	printf("\n\t\t\tEnter - for subtraction");
	printf("\n\t\t\tEnter * for multiplication");
	printf("\n\t\t\tEnter / for division");
	printf("\n\t\t\tEnter r for modulus");
	printf("\n\t\t\tEnter ^ for power");
	printf("\n\t\t\tEnter s for square root");
	printf("\n\t\t\tEnter ! for factorial");
	printf("\n\t\t\tEnter q to quit");
	printf("\n\t\t\tEnter d to return to main menu");
}
void add()
{
	int a,b,sum;
	printf("\n\t\t\tEnter two integers: ");
	scanf("%d %d", &a, &b);
	sum=a+b;
	printf("\n\t\t\tSum= %d", sum);
}
void sub()
{
	int a,b,res;
	printf("\n\t\t\tEnter two integers: ");
	scanf("%d %d", &a, &b);
	res=a-b;
	printf("\n\t\t\tSubtraction result= %d", res);
}
void mul()
{
	int a,b,res;
	printf("\n\t\t\tEnter two integers: ");
	scanf("%d %d", &a, &b);
	res=a*b;
	printf("\n\t\t\tMultiplication result= %d", res);
}
void div()
{
	int a,b;
	float res;
	printf("\n\t\t\tEnter two integers: ");
	scanf("%f %f", &a, &b);
	res=a/b;
	printf("\n\t\t\tResult of division= %.3f", res);
}
void mod()
{
	int a,b,res;
	printf("\n\t\t\tEnter two integers: ");
	scanf("%d %d", &a, &b);
	res=a%b;
	printf("\n\t\t\tRemainder= %d", res);
}
void power()
{
	int a,b;
	double res;
	printf("\n\t\t\tEnter the base and power: ");
	scanf("%d %d", &a, &b);
	res=pow(a,b);
	printf("\n\t\t\tResult= %.2lf", res);
}
void sqr()
{
	int a;
	float res;
	printf("\n\t\t\tEnter the integer: ");
	scanf("%d", &a);
	res=sqrt(a);
	printf("\n\t\t\tResult of square root= %.2f", res);
}
void fact()
{
	int a,i;
	double res=1;
	printf("\n\t\t\tEnter the integer: ");
	scanf("%d", &a);
	for(i=a;i>=1;i--)
		res*=i;
	printf("\n\t\t\tResult of factorial= %.2lf", res);
}
