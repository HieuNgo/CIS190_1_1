/*Hieu Ngo
10/26/2017
C program to match bolts with nuts
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void rearranging(float [],float [],int); 		//find corresponding nuts
void compareAndArrange(float ,float [],int,int); 	//find corresponding nuts
void mixingNut(float [],int);					//mixing the nuts inside nutBox
void printBox(float [],float [],int);			//print the contents of bolt box and nut box
void takeInput(float [],float [],int);			//take user input

int main()
{

	//declare variable
	int boltNum,i;
	//ask user for the number of bolts
	printf("How many bolts do you have? ");
	scanf(" %d",&boltNum);
	float boltBox[boltNum],nutBox[boltNum];	//creating an array to store the bolts' width
	takeInput(boltBox,nutBox,boltNum);		//take user input
	mixingNut(nutBox,boltNum);			//mixing the nuts inside nutBox
	printBox(boltBox,nutBox,boltNum);		//print the contents of bolt box and nut box
	rearranging(boltBox,nutBox,boltNum);	//rearrange
	printBox(boltBox,nutBox,boltNum);		//print result after rearrangement
	printf("\n");
	return 0;
}

//rearrange
void rearranging(float boltBox[],float nutBox[],int arraySize)
{	
	int i=0,j=0;
	//find corresponding nuts of every bolts starting from the first bolt
	for(i=0;i<arraySize;i++)
	{
		compareAndArrange(boltBox[i],nutBox,i,j);
		j++;
	}
}
//find corresponding nuts
void compareAndArrange(float boltSize,float nutBox[],int boltLocation,int nutLocation)
{
	//terminating condition
	if(nutBox[nutLocation] == boltSize)
		{
			//move the corresponding nut to the location of bolt, replacing the one 
			//previously in that location	
			printf("\nMove %.1f from %d to %d and move %.1f from %d to %d",nutBox[boltLocation],boltLocation,nutLocation,nutBox[nutLocation],nutLocation,boltLocation);
			nutBox[nutLocation] = nutBox[boltLocation];
			nutBox[boltLocation] = boltSize;
		}
	else
	{
		compareAndArrange(boltSize,nutBox,boltLocation,nutLocation+1);
	}
}

void mixingNut(float nutBox[],int nutNum)	//mixing the nuts inside nutBox
{
	//set seed for rand()
	srand(time(NULL));
	int i,ranNum;
	float temp;
	for(i=0;i<nutNum;i++)
	{
		ranNum=rand()%(nutNum-i)+i;
		temp = nutBox[i] ;
		nutBox[i] = nutBox[ranNum];
		nutBox[ranNum] = temp;
	}
}

void printBox(float boltBox[],float nutBox[],int size)		//print the contents of bolt box and nut box
{
	int i;
	//print out what is inside the boltBox
	printf("\nIn the bolt box ,we have %d bolts with widths of ",size);
	for(i=0;i<size;i++)
	{
		printf("%.2f ",boltBox[i]);
	}
	//print out what is inside the nutBox
	printf("\nIn the nut box ,we have %d bolts with widths of ",size);
	for(i=0;i<size;i++)
	{
		printf("%.2f ",nutBox[i]);
	}
}

void takeInput(float boltBox[],float nutBox[],int size)	//take user input
{
	int i=0;
	float tempSize;
	do
	{
		//ask user for the widths of the bolts
		printf("Please enter the width of your bolt: ");
		scanf(" %f",&tempSize);
		//put the size of bolts in array in the same sequence as the users enter
		boltBox[i]= tempSize;
		//put the size of corresponding nuts in random sequence
		//mixing the nuts
		nutBox[size-1 - i] = tempSize;
		i++;
	}
	while(i<size);

}
