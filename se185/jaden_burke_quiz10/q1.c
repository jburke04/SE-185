#include<stdio.h>
#include <stdlib.h>

int main(){
	//open file
	FILE *fp = fopen("numbers.txt" , "w");
	int evenNums[8];
	int curr;
	//since I know the list before hand I just made an array since it doesn't
	//specify that I have to take user input to scan in the numbers
	int numList[8] = {12,7,3,0,28,74,37,299};
	int count = 0;
	int i = 0;
	
	//checking to see if file opened correctly
	if(fp == NULL){
		printf("File failed to open");
		exit(-1);
	} else{
		//putting all numbers into the file
		for(i = 0; i < 8; i++){
			fprintf(fp, "%d\n", numList[i]);
		}
	}
	
	//close file
	fclose(fp);
	//open file
	fp = fopen("numbers.txt" , "r");
	//checking to see if file opened correctly
	if(fp == NULL){
		printf("File failed to open");
		exit(-1);
	} else {
		for(i = 0; i < 8; i++){
			fscanf(fp,"%d\n",&curr);
			if(curr % 2 == 0){
				evenNums[count] = curr;
				count++;
			}
		}
	}
	for(i = 0;i < count;i++){
		printf("%d ",evenNums[i]);
	}
	return 0;

}