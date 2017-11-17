/*Hieu Ngo
09/18/2017
lab2 part 2*/

#include <stdlib.h>
#include <stdio.h>


int main()
{
	//declare max and min
	int max = 20, min = 10;
	//start the PRNG
	srand(time(NULL));
	//assign a number to be random between 10 and 20
	int randomNumber = rand() % ((max+1)-min) + min;
	//print the number out
	printf("A random number between 10 and 20 is: %d \n", randomNumber);
	return 0;
}
