#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
	//defining variables
	char first_name[50], last_name[50]; 
	char *full_name = NULL; 
	int num_letters = 0; 
	
	//asking for user input
	printf("Whats your first name?\n");
	scanf(" %s",first_name);
	printf("Whats your last name?\n");
	scanf(" %s",last_name);
	
	//printing first and last name since nothing has to be changed
	printf("First name: %s\n",first_name);
	printf("Last name: %s\n",last_name);
	
	//allocating the memory
	full_name = (char*)malloc(sizeof(char)*(strlen(first_name) + strlen(last_name) + 1));
	
	//Putting the stuff into the full name string
	strcat(full_name, first_name);
	strcat(full_name," ");
	strcat(full_name, last_name);
	
	//printing full name
	printf("Full name: %s\n",full_name);
	
	//counting number of letters
	for(int i = 0;i < strlen(full_name);i++){
		if(isalpha(*(full_name + i)) != 0){
			num_letters++;
		}
	}
	
	//Printing number of letters, I know it doesnt say to do this but I did
	printf("Number of Letters in Name: %d",num_letters);
	
	//freeing memory
	free(full_name);
	
	return 0;
}