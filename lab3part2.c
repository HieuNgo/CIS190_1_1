/*Hieu Ngo
09/25/2017
lab3 part1
*/


#include <stdlib.h>
#include <stdio.h>

int main()
{
	//declares variables
	float numb;
	int digit1,digit2,digit3,digit4,digit5,digit6;
	
	//open file to read from file
	FILE *rp = fopen("input.txt","r+");
	fscanf(rp,"%8f", &numb);	

	//validate the input from input.txt
	if ( numb < 100000.00)
	{
		printf("The number format is incorrect.\n");
		return 0;
	}

	if (numb >= 1000000.00)
	{
		numb = (int)numb % 1000000;
	}

	printf("%.2f\n",numb);

	//extract the digits from the input from file
	digit1 = (int)numb/100000;
	digit2 = (int)numb/10000 % 10;
	digit3 = (int)numb/1000 % 10;
	digit4 = (int)numb/100 % 10;
	digit5 = (int)numb/10 % 10;
	digit6 = (int)numb % 10;

	//print out the results
	printf("Odd digits printed in order – ");
	if ( digit1%2 == 1 ) printf("%d ",digit1);
	if ( digit2%2 == 1 ) printf("%d ",digit2);
	if ( digit3%2 == 1 ) printf("%d ",digit3);
	if ( digit4%2 == 1 ) printf("%d ",digit4);
	if ( digit5%2 == 1 ) printf("%d ",digit5);
	if ( digit6%2 == 1 ) printf("%d ",digit6);

	printf("\nEven digits printed in reverse order – ");
	if ( digit6%2 == 0 ) printf("%d ",digit6);
	if ( digit5%2 == 0 ) printf("%d ",digit5);
	if ( digit4%2 == 0 ) printf("%d ",digit4);
	if ( digit3%2 == 0 ) printf("%d ",digit3);
	if ( digit2%2 == 0 ) printf("%d ",digit2);
	if ( digit1%2 == 0 ) printf("%d ",digit1);
	printf("\n");
	
	//close the file
	fclose(rp);
	return 0;
}

