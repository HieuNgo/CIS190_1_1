/*Hieu Ngo
10/10/2017
Part 1 of homework 2, cis 190
find sum, average, and square root of users entered inputs
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sumOfInt(int *,int); //calculate sum of inputs
float averageOfInt(int,int); //calculate the average of inputs
void isLessThan20(int *,int); //check if there is any number less than 20
void is10To90(int *,int); //check if all the number is 10 to 90
void printResult(int*,int *,float *,int *,int *);

int main()
{	
	//declare variables
	int temp, sumInt=0, count=0, boo = 0,isBetween10And90=1,i=0;
	float average;
	float tempo;	

	do
	{
		//ask user for input	
		printf("Enter an integer to add to the list(enter a negative number if you want to stop): ");
		scanf("%d",&temp);

		//validate user input, end if less than or equal to 0
		if(temp < 0) 
		{
			break;	
		}
		count++; //count the number of inputs
		sumOfInt(&sumInt,temp); //calculate sum of inputs
		average = averageOfInt(sumInt,count); //calculate the average of inputs
		
		//check if the number is less than 20
		isLessThan20(&boo,temp);
		//check if all the numbers are between 10 and 90
		is10To90(&isBetween10And90,temp);
		//store sqrt values in a file then print it out at the end.		
		printf("The square root of %d is %.2lf\n",temp,sqrt((double)temp));
	}
	while(temp >= 0); //stop taking integer if user enter 0	
	//print out the result
	printResult(&count,&sumInt,&average,&boo,&isBetween10And90);
	return 0;
}

//calculate sum of inputs
void sumOfInt (int *sum,int num)
{
	*sum = *sum + num;
	return;
}

//calculate the average of inputs
float averageOfInt(int sum, int totalNum)
{
	float average = (float)sum / (float)totalNum;
	return average;
}

void isLessThan20(int *boo,int num) //check if there is any number less than 20	
{
	//if number is less than 20, store 1(true)
	if(num<20)
		*boo = 1;
	//if number is not < 20, keep the variable result
	return;
}

void is10To90(int *boo,int num) //check if all the numbers are between 10 and 90	
{
	//if number is less than 10, store 0(false)
	if(num<10)
		*boo = 0;
	else if(num>90) //if number is greater than 90, store 0(false)
		*boo = 0;
	//if number is not < 10 or >90, keep the variable result
	return;
}

//print out the results
void printResult(int *count,int *sumInt,float *average,int *boo1,int *boo2)
{
	printf("The number of the integers is:\t\t%d\n", *count);
	printf("The sum of the integers is:\t\t%d\n", *sumInt);
	printf("The average of the integers is:\t\t%5.2f\n", *average);
	
	//print true if boo1, boo2 is 1. print false if it is 0.
	if(*boo1)
	{	
		printf("At lease one number was <20:\t\ttrue\n");
	}
	else
	{
		printf("At lease one number was <20:\t\tfalse\n");
	}

	if(*boo2)
	{	
		printf("All numbers were between 10 and 90:\ttrue\n");
	}
	else
	{
		printf("All numbers were between 10 and 90:\tfalse\n");
	}
	
	return;
}
