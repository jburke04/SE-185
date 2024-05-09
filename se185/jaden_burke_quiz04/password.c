#include<stdio.h>
#include<string.h>

int main(void){
	
	//defining variable
	char userPassword[50];
	
	//asking for user input
	printf("Please enter a password: ");
	scanf("%s", userPassword);
	
	//making required changes to user inputted string
	for(int i = 0; i < strlen(userPassword); i++){
		if(userPassword[i] == 'i'){
			userPassword[i] = '1';
		} else if(userPassword[i] == 'a'){
			userPassword[i] = '@';
		} else if(userPassword[i] == 'm'){
			userPassword[i] = 'M';
		} else if(userPassword[i] == 'B'){
			userPassword[i] = '8';
		} else if(userPassword[i] == 's'){
			userPassword[i] = '$';
		}
	}
	
	//added ! to the end
	strcat(userPassword, "!");
	
	//printing result
	printf("Your updated password: %s",userPassword);
	return 0;
}