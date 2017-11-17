/*Hieu Ngo
09/16/2017
lab 5 
*/
#include <stdio.h>

void calculate_a(int *,int);	//calculate a
void calculate_b(int *,int);	//calculate b
void calculate_d(int *,int);	//calculate d
void calculate_y(int *,int,int,int);	//calculate y
void print_result(int *,int *, int *, int *);	//print results

int main()
{
	//declare variables
	int n,a=0,b=0,d=0,y=0;
	// ask user input
	printf("Please enter n: ");
	scanf("%d",&n);
	//calculate a,b,d,y
	calculate_a(&a,n);
	calculate_b(&b,n);
	calculate_d(&d,n);
	calculate_y(&y,a,b,d);
	//print results
	print_result(&a,&b,&d,&y);
	return 0;
}

//calculate a
void calculate_a(int *a,int num)
{
	int i,j,product=1;
	if(num<=5)
	{
		for(i=2;i<=num;i++)
			{
				for(j=1;j<=i;j++)
				{
					product *= j+2*i;
				}
				//add the product to the sum
				*a += product;			
				//reset the product after
				product = 1;	
			}
	}
	if(num>=6 && num <10) 
	{
		for(i=1;i<=num;i++)
		{
			*a += i-1;	
		}
	}
	if(num>=10)
	{
		*a = num*26;
	}
	return;
}

//calculate b
void calculate_b(int *b,int num)
{
	if(num<10)
	{
		*b = num +1;;
	}
	else 
	{
		*b = (num+2)*(num+3);	
	}
	return;
}

//calculate d
void calculate_d(int *d,int num)
{
	switch(num)
	{
		case 1:
		case 2:
			*d = 2*num;
			break;
		case 3:
		case 4:
		case 5:
			*d = num*num;
			break;
		default:
			*d = num + 1;
	}
	return;
}

//calculate y
void calculate_y(int *y,int a,int b,int d)
{
	*y = a*(b/d)+a*b+d;
	return;
}

//print out the results
void print_result(int *a,int *b, int *d, int *y)
{
	printf("a = %d\n",*a);
	printf("b = %d\n",*b);
	printf("d = %d\n",*d);
	printf("y = %d\n",*y);
	return;
}
