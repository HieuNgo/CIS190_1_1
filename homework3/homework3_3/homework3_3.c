/*Hieu Ngo
10/26/2017
C program to find number of pipes needed
take 4 first, plus with every number after it so that you get the biggest sum possible
repeat it

move to 3

*/

#include <stdio.h>

void pipeCal(int *,int,int [],int,int,int);	//calculate the number of pipe to buy
void	takeInput(int *,int *);				//take user input
void fillArray(int,int []);						//fill the array
int main()
{
	int listNum,i,maxLength,temp=0,count = 0;
	takeInput(&maxLength,&listNum);	//take user input
	int pipeNeeded[listNum];	//create an array to store the size of the pipe's length needed
	fillArray(listNum,pipeNeeded);	//fill the Array
	for(i=0;i<listNum;i++)			//calculate the number of pipes to buy
	{
		if(pipeNeeded[i]==0 )
			continue;
		pipeCal(&count,i,pipeNeeded,listNum,temp,maxLength);
	}
	//print result
	printf("You need to buy %d stock pipes of %d feet length from the store.\n", count, maxLength);
	return 0;
}

void pipeCal(int *count,int posInArray,int pipeArray[],int size,int sum,int maximum)	//calculate the number of pipe to buy
{	
	int beginSum = sum,i,rememberI=posInArray;
	//if the first element is 0, ignore it,start with the next number.
	if(pipeArray[posInArray] == 0)
	{
		if(posInArray == size - 1)
			return;
		pipeCal(&(*count),posInArray+1,pipeArray,size,sum,maximum);
		return;
	}
	//find the first possible number to add to sum such that sum is in range
	//that number will be the starting point of the next loop
	for(i=posInArray;i<size;i++)
	{
		if(sum + pipeArray[i] <= maximum && (sum + pipeArray[i]) != beginSum)
		{
			sum += pipeArray[i];
			posInArray = i;
			break;
		}
	}
	//scan from posInArray to end of array to find the biggest number that can add to sum such that sum is in range, remember its position
	for(i=posInArray+1;i<size;i++)
	{
		if(sum < (pipeArray[posInArray] + pipeArray[i]) && (pipeArray[posInArray] + pipeArray[i]) <= maximum )
		{
			sum = pipeArray[posInArray] + pipeArray[i];
			rememberI = i;
		}
	}
	//if the beginning sum and the end sum is the same, end the func, increment count by 1
	if(beginSum == sum){
			(*count)++;
			return;
		}
	//set the number you just find and the 1st to 0
	//so we can ignore them after ===> remove them from the array
	else{
	pipeArray[posInArray] = 0;
	pipeArray[rememberI] = 0;
	//call the func again to find the 3rd,4th,... number if possible
	pipeCal(&(*count),posInArray+1,pipeArray,size,sum,maximum);
	}	
}

void	takeInput(int *maxLength,int *listNum)				//take user input
{
	//ask for the maximum size of stock pipe and the number of pipes needed
	printf("Enter the stock pipe's length in the store: ");
	scanf(" %d",&(*maxLength));
	printf("Enter the number of stock pipes in your list: ");
	scanf(" %d",&(*listNum));

}

void fillArray(int size,int pipeNeeded[])				//fill the array
{
	for(int i=0;i<size;i++)
	{
	printf("Enter the stock pipe's length that you need: ");
	scanf(" %d",&pipeNeeded[i]);
	}
}
