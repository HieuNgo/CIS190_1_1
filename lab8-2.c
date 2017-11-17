/*Hieu Ngo
10/30/2017
Lab 7 second part*/

#include <stdio.h>

void recursiveFunc(int); //print num recursively

int main()
{
	int num;
	//take user's input
	printf("Enter a number: ");
	scanf(" %d",&num);
	recursiveFunc(num);		//print number reversely
	return 0;
}

void recursiveFunc(int num) //print num recursively
{
	//print the last digit
	printf("%d\n",num%10);
	//end if it is the first digit of the number
	if(num<10)
		return;
	//divide by 10 and pass it to the function again
	//until it reaches the first digit
	recursiveFunc(num/10);
}
