/*Hieu Ngo
10/26/2017
C program for Tower of Hanoi using Recursion */
#include <stdio.h>
void towers(int, char, char, char);
int main()
{
	int num;
	//ask user for number of disks
	printf("Enter the number of disks : ");
	scanf("%d", &num);
	//print out the sequence of moves
	printf("The sequence of moves involved in the Tower of HaHa are :\n");
	towers(num, 'A', 'C', 'B');
 	return 0;
}

//move 1 from A to C, mover 2 from A to B, then move 1 from C to B.
//move 3 from A to C, move 1 from B to A, move 2 from B to C, finally move 1 from A to C
//repeat this process until you reach the bottom of the tower(n=0) 
void towers(int num, char frompeg, char topeg, char auxpeg)
{
	//terminating conditions
	if (num== 1)
	{
		printf("Move disk 1(red disk) from peg %c to peg %c\n", frompeg, topeg);
		return;
	}
 	towers(num- 1, frompeg, auxpeg, topeg);
	//the last disk is move from A to B only once
	printf("Move disk %d", num);
	//print yellow if num is ven, red if num is red
	if(num%2 == 0)
		printf("(yellow disk)");
	else if(num%2==1)
		printf("(red disk)");
	printf(" from peg %c to peg %c\n", frompeg, topeg);
	//call towers() recursively
 	towers(num- 1, auxpeg, topeg, frompeg);
}
