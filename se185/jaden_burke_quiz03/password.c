#include<stdio.h> 
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

int main(void){
//defining variables
char correctUser[] = "se185@iastate.edu";
char correctPassword[] = "ds4rd";
char inputUser[50];
char inputPassword[50];

//asking for user input
printf("Enter your username: ");
scanf("%s",&inputUser);
printf("Enter your password: ");
scanf("%s",&inputPassword);

//comparing the strings then outputting the result
if(strcmp(correctUser,inputUser) == 0){
	printf("Success!");
} else {
	printf("Username or password is incorrect.");
}
return 0;
}