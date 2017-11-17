/*Hieu Ngo
10/10/2017
Part 3 of homework 2, cis 190
find three largest integer out of 20 integers using Pass By Reference
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void find3BiggestNum(int *,int *,int *);//find the 3 largest integers
void counting(int *,int *,int *,int *,int *,int *);//count the occurences of the largest integer
void printResult(int *,int *,int *,int *,int *,int *); //print the results on the screen

int main(void)
{
	//declare variables to store 3 biggest number and the times they appear
	int firstNum=0,secondNum=0,thirdNum=0;
	int countFirstNum=0,countSecondNum=0,countThirdNum=0;
	
	//find three largest numbers
	find3BiggestNum(&firstNum,&secondNum,&thirdNum);
	//find the occurences
	counting(&firstNum,&secondNum,&thirdNum,&countFirstNum,&countSecondNum,&countThirdNum);
	//print out the results
	printResult(&firstNum,&countFirstNum,&secondNum,&countSecondNum,&thirdNum,&countThirdNum);
	return 0;
}

void find3BiggestNum(int *first,int *second, int *third)	//find three largest integers
{	
	int i=0,temp;
	//open input.txt
	FILE *input =  fopen("input.txt","r+");

	//find the largest number from 20 input
	for(i=0;i<20;i++)
	{
		//scan input from the file
		fscanf(input,"%d",&temp);
		if (i==0)
		{
			*first = temp;
			*second = temp;
			*third = temp;
		}
		//if there is a number less than firstnum, take that value as the value of secondnum
		if (*second==*first && temp<*first)
			*second = temp;
		//if there is a number less than firstnum or secondnum, take that value as the value of 		thirdnum
		if (*third==*first && temp<*first)
			*third=temp;
		if (*third==*second && temp<*second)
			*third = temp;

		//find 3 largest number and store them in 3 variable
		if (temp > *first)
		{	
			//push values down to second and third
			//store the new largest value
			*third = *second;
			*second = *first;
			*first = temp;
		}
		else if(temp < *first && temp > *second)
		{
			//push value down to third 
			//store the new second largest value
			*third = *second;
			*second = temp;
		}
		else if(temp < *second && temp > *third)
		{
			//store the new third largest value
			*third = temp;
		}
	}
	//close file
	fclose(input);
	return;
}
//count the occurences of the largest integer
void counting(int *first,int *second,int *third,int *countFirst,int *countSecond,int *countThird)	
{
	int i=0,temp;
	//open input.txt
	FILE *input =  fopen("input.txt","r+");
	//count the occurences of the 3 largest integer
	for(i=0;i<20;i++)
	{
		//scan the file
		fscanf(input,"%d",&temp);
		//count every when a matching number appear
		if (temp == *first)
			*countFirst +=1;
		else if (temp == *second)
			*countSecond+=1;
		else if (temp == *third)
			*countThird+=1;
	}
	//close file
	fclose(input);
	return;
}

void printResult(int *firstNum, int *countFirstNum,int *secondNum,int *countSecondNum,int *thirdNum,int *countThirdNum)
{
	if (*firstNum == *secondNum)
	{
		printf("The largest number is %d and it appears %d times\n",*firstNum,*countFirstNum);	
		printf("There is no second or third biggest numbers.\n");
	}
	else if(*secondNum == *thirdNum)
	{
	printf("The largest number is %d and it appears %d times\n",*firstNum,*countFirstNum);
	printf("The second largest number is %d and it appears %d times\n",*secondNum,*countSecondNum);
	printf("There is no third biggest numbers.\n");	
	}
	else
	{
	printf("The largest number is %d and it appears %d times\n",*firstNum,*countFirstNum);
	printf("The second largest number is %d and it appears %d times\n",*secondNum,*countSecondNum);
	printf("The third largest number is %d and it appears %d times\n",*thirdNum,*countThirdNum);
	}
	return;
}




