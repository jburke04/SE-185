#include<stdio.h>
#include<string.h>

int main(void){

 
//just copy pasting for reference
 /*
    char letter = ‘a’; 
 
    while(letter <= ‘z’) { 
        printf(“%c\n” , letter); 
        letter++; 
    } 
 */
	//defining necessary variables
	int i;
	char curLetter;
	
	//the while loop as a for loop
	for(i = 0;i<26;i++){
		curLetter = i + 97;
		printf("%c",curLetter);
	}
	
	
	return 0;
}