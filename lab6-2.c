/*Hieu Ngo
10/23/2017
lab 6 part 2: character pyramid
*/

#include <stdio.h>

void pyramid(int,char);

int main()
{
	int num = 1;
	char ch,ch1='A'; 
	do
	{
	ch=' ';
	//ask user input
	printf("Do you want upper case or lower case(U/L)?\n");
	scanf(" %c",&ch);
	}
	while(ch != 'U' && ch != 'L');
	//change ch1 to lower case if they want to
	if(ch=='L')
		ch1+=' ';
	//run 9 times
	for(num=0;num<9;num++)
	{
		pyramid(num,ch1+num);
	}
	return 0;
}

void pyramid(int num,char ch1)
{	
	//declare variables
	int i,j;
	char ch2;
	//run the loop (num) time
	for(i=0;i<num;i++)
	{	
		//increment the character
		ch2=ch1+i-1;
		//print the spaces		
		if(i==0)
		{
			printf("\t");
			for(j=10;j>num;j--)
				printf(" ");
		}
		//printing
		printf("%c",ch2);
	}	
	for(i=1;i<num;i++)
	{	
		//decrement the character and print it our
		printf("%c",ch2 - i);
	}
	//print new line
	printf("\n");
}
