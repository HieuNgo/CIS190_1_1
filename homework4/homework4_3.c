/*Hieu Ngo
11/8/2017
C program to find possible word out of possible beginning letter*/
#include <stdio.h>
#include <math.h>
#define SIZE 10
#define SIZE1 4
void digitToLetter(int,int,char [][SIZE1]);	//digits conversion to letters

int main()
{
	int input,numDigits;
	//the keyboard
	char array[SIZE][SIZE1]= {	{},
						{},
						{'a','b','c'},
						{'d','e','f'},
						{'g','h','i'},
						{'j','k','l'},
						{'m','n','o'},
						{'p','q','r','s'},
						{'t','u','v'},
						{'w','x','y','z'}
					};
	printf("Enter number: ");
	scanf(" %d",&input);
	//find out how long is the number
	for(numDigits=1 ; ; numDigits++)
	{
		if (input/(int)pow(10,numDigits) == 0)
		break;	

	}
	printf("%d",numDigits);
	//digits conversion to letters
	digitToLetter(input,numDigits,array);
	return 0;
}

void digitToLetter(int input,int numDigits,char array[][SIZE1])	//digits conversion to letters
{
	static int j =0;
	int i = 0,numb,temp,temp2;
	if(numDigits == 0|| j>= SIZE1)
	{
		return;	
	}
	else
	{
		temp = input/(int)pow(10,numDigits-1) % 10 ;	
		numb = input % (int)pow(10,numDigits-1);
		if(numb<10)
		{
			temp2 = numb;
		}
		else
		{
			temp2 = numb/(int)pow(10,numDigits-1) % 10 ;	
		}
		for(i=0;i<SIZE1;i++)
		{
			printf("%c", array[temp][i]);


			printf("%c", array[temp][j]);
			j++;
			digitToLetter(numb,numDigits - 1 ,array);
			printf("\n");
		}
	}
	
	//step 2 is print out each digit in number
	
	 
}

/*for(;numDigits>0;numDigits--)
	{	
		//print the first line
		for(i=1;i<=numDigits;i++)
		{	
			temp = 
			printf("%c",);
			digitToLetter(  input % (int)pow(10,numDigits-1) ,array);
			//temp = input % (int)pow(10,numDigits-i);
		}
		printf("\n");
		input =;
	}
*/
