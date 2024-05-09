#include<stdio.h>

int main(void){
	//defining variables
	long long int phoneNum;
	int areaCode;
	int exchangeCode;
	int userNum;
	int test;
	
	
	//asks for user input of phone number
	printf("Please enter the 10 digits phone number: ");
	scanf("%lld",&phoneNum);
	
	//correctly segments the phone number its parts
	areaCode = (phoneNum / 10000000);
	exchangeCode = (phoneNum / 10000) % 1000;
	userNum = phoneNum % 10000;
	
	//prints what the area and exchange code as well as the user number is
	printf("\n\nThe area code is: %d\n",areaCode);
	printf("The exchange code is: %d\n",exchangeCode);
	printf("The user number is: %d\n",userNum);
	
	
	return 0;
	
}