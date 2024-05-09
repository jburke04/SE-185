#include<stdio.h> 
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

int main(void){
//defining my variable
int grade;

//asking for user input
printf("Please enter your grading percentage: ");
scanf("%d", &grade);

//going through a ton of if statements to check what grade you should get for the input
if(grade <= 100 && grade >= 93){
	printf("A");
} else if (grade >= 90 && grade < 93){
	printf("A-");
} else if (grade >= 87 && grade < 90){
	printf("B+");
} else if (grade >= 83 && grade < 87){
	printf("B");
} else if (grade >= 80 && grade < 83){
	printf("B-");
} else if (grade >= 77 && grade < 80){
	printf("C+");
} else if (grade >= 73 && grade < 77){
	printf("C");
} else if (grade >= 70 && grade < 73){
	printf("C-");
} else if (grade >= 67 && grade < 70){
	printf("D+");
} else if (grade >= 63 && grade < 67){
	printf("D");
} else if (grade >= 60 && grade < 63){
	printf("D-");
} else if (grade >= 0 && grade < 60){
	printf("F");
} else{
	printf("Your grade must be between 0 percent and 100 percent inclusively");
}

return 0;
}