/*Hieu Ngo
10/30/2017
Lab quiz*/

#include <stdio.h>

float takeNum();		//take user's input for the number to convert
char takeType();		//take user's input for the type of conversion
void weightCon(float);		//pounds to kilograms
void lengthCon(float);		//feet to meters
void volumeCon(float);		//Cubic inches to Cubic Centimeters
void temperatureCon(float);	// Fahrenheit to Celcius
void converting(char,float); 	//do the conversion

int main()
{
	char type;
	int validation=1;
	float num;
	//print instrustions for user
	printf("Conversion: pounds to kilograms, feet to meters, Cubic inches to Cubic Centimeters, Fahrenheit to Celcius.\n");
	type = takeType();		//take user's input for the number to convert
	num = takeNum();		//take user's input for the type of conversion
	converting(type,num);	//do the conversion
	return 0;
}

float takeNum() //take user's input for the number to convert
{
	int num;
	printf("Enter the number to convert: ");
	scanf(" %d",&num);
	return num;
}
char takeType() //take user's input for the type of conversion
{
	char type;
	do
	{
	printf("Which conversions do you want to perform: \n");
	printf("(w)eight, (l)ength, (v)olume, (t)emperature, (q)uit: ");
	scanf(" %c",&type);	
	}
	while(type != 'w' && type != 'l' && type != 'v' && type != 't' && type != 'q' );
	return type;
}
void weightCon(float num)		//pounds to kilograms
{
	float result = num * 0.453592;
	printf("%.2f pounds equal %.2f kilograms\n",num,result);
}
void lengthCon(float num)		//feet to meters
{
	float result = num * 0.3048;
	printf("%.2f feet equal %.2f meters\n",num,result);

}
void volumeCon(float num)		//Cubic inches to Cubic Centimeters
{
	float result = num * 16.3871;
	printf("%.2f Cubic inches equal %.2f Cubic Centimeters\n",num,result);

}
void temperatureCon(float num)	// Fahrenheit to Celcius
{
	float result = (num-32) * 0.5556;
	printf("%.2f Fahrenheit equal %.2f Celcius\n",num,result);

}

void converting(char,float) 	//do the conversion
{
	switch(type)
	{	//weight conversion
		case 'w':
			weightCon(num);	//pounds to kilograms
			break;
		case 'l':
		lengthCon(num);		//feet to meters
			break;
		//volume conversion
		case 'v':
		volumeCon(num);		//Cubic inches to Cubic Centimeters
			break;
		//temperature conversion
		case 't':
		temperatureCon(num);	// Fahrenheit to Celcius
			break;
		case 'q':
			break;
	}
}

