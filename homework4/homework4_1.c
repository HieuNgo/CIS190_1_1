/*Hieu Ngo
11/8/2017
C program to calculate weight to support in human pyramid*/
#include <stdio.h>
#define SIZE 20
float calc(float [][SIZE],int,int);		 //calculate the weight one each person's knees 
int main()
{
	int bottom,i,j;
	float humanPyramid[SIZE][SIZE] = {0};
	//take user's input
	printf("How many people are on the bottom row? ");
	scanf(" %d",&bottom);
	printf("Each person's own weight: \n");
	//fill the array, starting from row 1, col 1 to row bottom, col bottom
	for (i=0;i<bottom;i++)
	{
		for(j=0;j<bottom;j++)
		{
			if(j>i)
			{
				break;
			}
			scanf(" %f",&humanPyramid[i][j]);
		}
		printf("\n");	
	}
	printf("Weight on each person's knees: \n");
	for (i=0;i<bottom;i++)
	{	
		for(j=0;j<bottom;j++)
		{
			if(j>i)
			{
				break;
			}
			printf(" %.2f",calc(humanPyramid, i, j));
		}
		printf("\n");	
	}
	
	return 0;
}

float calc(float humanPyramid[][SIZE],int i,int j)	 //calculate the weight one each person's knees 
{	
	float weightOnKnee;
	//2 terminating condition
	if(j>i)
		return 0;
	if(i==0 && j == 0)
	{
		return humanPyramid[0][0];
	}
	//when j = 0, only calculate the first person on the row above
	else if(j==0)
	{
		weightOnKnee = humanPyramid[i][j] + (calc(humanPyramid,i-1,j))/2;
	}
	//calculate the weight on kness of the person in the middle of the row
	else
	{
		weightOnKnee = humanPyramid[i][j] + (calc(humanPyramid,i-1,j-1))/2 + (calc(humanPyramid,i-1,j))/2;
	}
	return weightOnKnee;
}

