#include <stdio.h>
#include <ctype.h>


void minus();


int base = 5; //Base. So far was barely tested with the base of 10, 8, 5, and 2, but it worked.
char number1[4] = { '4', '3', '1', '2'}; //first number
char number2[4] = { '0','3','4','3' };  //second number
int pos = 0;

int main()
{
	
	for (int t = 0; t < sizeof(number1)/sizeof(char); t++)
	{
		printf("%c", number1[t]);
	}
	printf("\n - \n");
	minus();
	for (int t = 0; t < sizeof(number1) / sizeof(char); t++)
	{
		printf("%c", number2[t]);
	}
	printf("\nAnswer: ");
	for (int t = 0; t < sizeof(number1) / sizeof(char); t++)
	{
		printf("%d ", number1[t]);
	}
}



void minus()
{
	char point = 0;
	int temptotal = 0;
	for(int x = sizeof(number1)-1; x >= 0; x--)
	{
		if (number2[x] > number1[x])
		{
			
			temptotal = base - (number2[x] - '0') - point;
			number1[x] = number1[x] + temptotal - '0';
			point = 1;
		}
		else if(number2[x] < number1[x])
		{
			
			number1[x] = number1[x] - point;
			number1[x] = number1[x] - number2[x];
			point = 0;
		}
		else if (number1[x] == number2[x] && point == 1)
		{
			number1[x] = (base - 1);
		}
	}
}





