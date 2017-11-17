/*Hieu Ngo
10/23/2017
lab 6 part 1: number pyramid
*/

#include <stdio.h>

void pyramid(int);

int main()
{
	int num = 1;
	//run 9 lines 
	for(num=1;num<9;num++)
	{
		pyramid(num);
	}
	return 0;
}

void pyramid(int num)
{	
	//declare variables
	int i,num2,j;
	//run the loop (num) time
	//increasing
	for(i=0;i<num;i++)
	{	
		//initialize num2
		num2=num+i;
		//print the spaces		
		if(i==0)
		{
			printf("\t");
			for(j=10;j>num;j--)
				printf(" ");
		}
		printf("%d",num2%10);
	}
	//decreasing 	
	for(i=1;i<num;i++)
	{	
		printf("%d",(num2 - i) % 10);
	}
	//new line at the end
	printf("\n");
}
