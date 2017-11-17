/*Hieu Ngo
09/25/2017
lab3 part1
*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
	//declare variables
	int numb=0,digit1,digit2,digit3,digit4,digit5,digit6;

	//ask user for input and validate them
	do
	{
		printf("Please enter a number between 0 and 999,999: ");
		scanf("%d",&numb);
		if (numb < 0)
			printf("That number is too small.\n");

		if (numb > 999999)
			printf("That number is too large.\n");

	} while (numb < 0 || numb > 999999);

	//get the digits from user input
	digit1 = numb/100000;
	digit2 = numb/10000 % 10;
	digit3 = numb/1000 % 10;
	digit4 = numb/100 % 10;
	digit5 = numb/10 % 10;
	digit6 = numb % 10;

	// print out the results
	printf("%d\t%d\t%d\t%d\t%d\t%d\n",digit1,digit2,digit3,digit4,digit5,digit6);
	printf("%d\t%d\t%d\t%d\t%d\n",digit2,digit3,digit4,digit5,digit6);
	printf("%d\t%d\t%d\t%d\n",digit3,digit4,digit5,digit6);
	printf("%d\t%d\t%d\n",digit4,digit5,digit6);
	printf("%d\t%d\n",digit5,digit6);
	printf("%d\n",digit6);

	return 0;
}
