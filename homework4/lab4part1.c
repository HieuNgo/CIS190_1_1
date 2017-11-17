/*Hieu Ngo
09/25/2017
lab4 part1
*/

#include <stdio.h>
#include <math.h>

int main()
{
	//declare variables
	int numb,numDigits=1,temp;
	int i;

	//ask user for input and validate the number
	do {	
		printf("Please enter a number: ");
		scanf("%d",&numb);
		if (numb < 0)
			printf("That number is too small.\n");
	} while(numb < 0);
	//two big steps
	//step 1 is figure out how many digits the users number has
	for(numDigits=1 ; ; numDigits++)
	{
		if (numb/(int)pow(10,numDigits) == 0)
		break;	

	}

	//step 2 is print out each digit in number
	for(;numDigits>0;numDigits--)
	{	
		//print the first line
		for(i=1;i<=numDigits;i++)
		{	
			printf("%d ",numb/(int)pow(10,numDigits-i) % 10);
			//temp = numb % (int)pow(10,numDigits-i);
		}
		printf("\n");
		numb = numb % (int)pow(10,numDigits-1);
	}
	
	//end of program
	return 0;
}
