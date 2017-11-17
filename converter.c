/*Hieu Ngo
09/18/2017
lab2 part 1*/

#include <stdlib.h>
#include <stdio.h>
/*define constant for calculating */
#define FOOTCONST 12.0
#define YARDCONST 36.0
#define CENTIMETERCONST 2.54
#define METERCONST 39.37

int main()
{
	/*declare variables*/
	float inches, feet, yard, centimeter, meter;
	inches = 0;
	// ask user for a number
	printf("Please enter a length (in inches): ");
	scanf("%f", &inches);
	//use that numbers and convert it to feet, yard, cm, m
	feet = inches / FOOTCONST ;
	yard = inches / YARDCONST;
	centimeter = inches * CENTIMETERCONST;
	meter = inches / METERCONST;
	//print out the results
	printf("%.2f inches = %.2f feet\n", inches, feet);
	printf("%.2f inches = %.2f yards\n", inches, yard);
	printf("%.2f inches = %.2f centimeters\n", inches, centimeter);
	printf("%.2f inches = %.2f meters\n", inches, meter);

	//end of program
	return 0;
}
