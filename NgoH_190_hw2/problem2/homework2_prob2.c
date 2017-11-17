/*Hieu Ngo
10/10/2017
Part 2 of homework 2, cis 190
find three largest integer out of 20 integers using Pass By Value
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findFirstNum(int);//find the largest integers
int findSecondNum(int,int);//find the secondlargest integers
int findThirdNum(int,int,int);//find the third largest integers

int countFirst(int);//count the occurences of the largest integer
int countSecond(int);//count the occurences of the second largest integer
int countThird(int);//count the occurences of the third largest integer

void printResult(int,int,int,int,int,int); //print the results on the screen

int main(void)
{
	//declare variables to store 3 biggest number and the times they appear	
	int firstNum=-32768,secondNum=-32768,thirdNum=-32768;
	int countFirstNum=0,countSecondNum=0,countThirdNum=0;
	
	//find three largest numbers
	firstNum= findFirstNum(firstNum);
	secondNum= findSecondNum(firstNum,secondNum);
	thirdNum= findThirdNum(firstNum,secondNum,thirdNum);

	//find the occurences
	countFirstNum = countFirst(firstNum);
	countSecondNum = countSecond(secondNum);
	countThirdNum = countThird(thirdNum);

	//print out the results
	printResult(firstNum,countFirstNum,secondNum,countSecondNum,thirdNum,countThirdNum);
	return 0;
}

int findFirstNum(int first)	//find three largest integers
{	
	int i=0,temp;
	//open input.txt
	FILE *input =  fopen("input.txt","r+");

	//find the largest number
	for(i=0;i<20;i++)
	{
		//scan the file
		fscanf(input,"%d",&temp);
		//store the largest number scanned until EOF
		//initialize thirdnum to the first value in the file
		if (i==0) first = temp;
		if (temp > first)
			first = temp;
	}
	//close file
	fclose(input);
	return first;
}

int findSecondNum(int first,int second)	//find the second largest integers
{
	int i=0,temp;
	//open input.txt
	FILE *input =  fopen("input.txt","r+");

	//find the second largest number
	for(i=0;i<20;i++)
	{
		//scan the file
		fscanf(input,"%d",&temp);
		//initialize thirdnum to the first value in the file
		if (i==0) second = temp;
		//if there is a number less than firstnum, take that value as the value of secondnum
		if (second==first && temp<first)
			second = temp;
		//skip if scan the largest number
		if (temp == first)
			continue;
		//otherwise, store the largest number scanned until EOF
		if (temp > second)
			second = temp;
	}

	//close file
	fclose(input);
	return second;
}

int findThirdNum(int first,int second,int third)	//find the third largest integers
{
	int i=0,temp;
	//open input.txt
	FILE *input =  fopen("input.txt","r+");

	//find the largest number
	for(i=0;i<20;i++)
	{
		//scan the file
		fscanf(input,"%d",&temp);
		//initialize thirdnum to the first value in the file
		if (i==0) third = temp;
		//if there is a number less than firstnum or secondnum, take that value as the value of 		thirdnum
		if (third==first && temp<first)
			third=temp;
		if (third==second && temp<second)
			third = temp;
		//skip if scan the largest number or the second largest number
		if (temp == first||temp == second)
			continue;
		//otherwise, store the largest number scanned until EOF
		if (temp > third)
			third = temp;
	}
	//close file
	fclose(input);
	return third;
}

int countFirst(int first)	//count the occurences of the largest integer
{
	int i=0,temp,count=0;
	//open input.txt
	FILE *input =  fopen("input.txt","r+");

	//count the occurences of the largest integer
	for(i=0;i<20;i++)
	{
		//scan the file
		fscanf(input,"%d",&temp);
		//count if there is a match
		if (temp == first)
			count++;
	}
	//close file
	fclose(input);
	return count;
}

int countSecond(int second)	//count the occurences of the second largest integer
{
	int i=0,temp,count=0;
	//open input.txt
	FILE *input =  fopen("input.txt","r+");

	//count the occurences of the largest integer
	for(i=0;i<20;i++)
	{
		//scan the file
		fscanf(input,"%d",&temp);
		//count if there is a match
		if (temp == second)
			count++;
	}
	//close file
	fclose(input);
	return count;
}

int countThird(int third)	//count the occurences of the third largest integer
{
	int i=0,temp,count=0;
	//open input.txt
	FILE *input =  fopen("input.txt","r+");

	//count the occurences of the largest integer
	for(i=0;i<20;i++)
	{
		//scan the file
		fscanf(input,"%d",&temp);
		//count if there is a match
		if (temp == third)
			count++;
	}
	//close file
	fclose(input);
	return count;
}

//print the results on the screen
void printResult(int firstNum, int countFirstNum,int secondNum,int countSecondNum,int thirdNum,int countThirdNum)
{
	if (firstNum == secondNum)
	{
		printf("The largest number is %d and it appears %d times\n",firstNum,countFirstNum);	
		printf("There is no second or third biggest numbers.\n");
	}
	else if(secondNum == thirdNum)
	{
	printf("The largest number is %d and it appears %d times\n",firstNum,countFirstNum);
	printf("The second largest number is %d and it appears %d times\n",secondNum,countSecondNum);
	printf("There is no third biggest numbers.\n");	
	}
	else
	{
	printf("The largest number is %d and it appears %d times\n",firstNum,countFirstNum);
	printf("The second largest number is %d and it appears %d times\n",secondNum,countSecondNum);
	printf("The third largest number is %d and it appears %d times\n",thirdNum,countThirdNum);
	}
	return;
}











