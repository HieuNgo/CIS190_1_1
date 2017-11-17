//Hieu Ngo
//09/11/2017
//lab 1

#include <stdio.h>

int main(void) 
{
  //define 2 integers and assign values to them.
  int num1, num2;
  num1 = 101;
  num2 = 12;
  //define 4 int and assign them to 0.
  int sum=0, difference=0, product=0, quotient=0;
  //perform addition, subtraction, multiplication, and division on num1 and num 2
  //store the results in sum, difference, product, and quotient.
  sum = num1 + num2;
  difference = num1 - num2;
  product = num1 * num2;
  quotient = num1 / num2;
  //print out the result.
printf("Hello World\nMy name is Hieu Ngo\n");
 printf("My numbers are %d and %d.\n",num1,num2);
 printf("the sum of %d and %d is %d.\n",num1,num2,sum);
 printf("the difference of %d and %d is %d.\n",num1,num2,difference);
 printf("the product of %d and %d is %d.\n",num1,num2,product);
 printf("the quotient of %d and %d is %d.\n",num1,num2,quotient);

return 0;
}
