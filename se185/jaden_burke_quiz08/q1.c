#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct imaginary{
	int real;
	int i;
} imaginary;

int main(){
	imaginary num1;
	imaginary num2;
	printf("Enter real and imaginary values of number 1: ");
	scanf("%d %d",&num1.real,&num1.i);
	printf("Enter real and imaginary values of number 2: ");
	scanf("%d %d",&num2.real,&num2.i);
	printf("ADD = %d + %di\n",num1.real + num2.real,num1.i + num2.i);
	printf("SUB = %d + %di\n",num1.real - num2.real,num1.i - num2.i);
	printf("MUL = %d + %di\n",num1.real*num2.real - num1.i*num2.i,num1.i*num2.real + num2.i*num1.real);

	return 0;
}

