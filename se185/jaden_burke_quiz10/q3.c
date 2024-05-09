#include<stdio.h>
#include <stdlib.h>
int stringlen(char string[], int i);

int main(){
	char string[100];
	int index = 0;
	
	printf("Enter a string: ");
	scanf(" %s",&string);
	printf("The length of ""%s"" = %d",string,stringlen(string,index));
	
	return 0;
}

//uses end of line character as my base case
//if its not the end of the line, add 1 to length and re-run
int stringlen(char string[], int i){
	int length = 0;
	char c = string[i];
	if(c == '\0'){
		return length;
	} else {
		length++;
		return length + stringlen(string, i + 1);
	}
}