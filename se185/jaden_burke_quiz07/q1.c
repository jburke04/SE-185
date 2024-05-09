#include<stdio.h>
#include<stdlib.h>

int main(){
	int num = 5;
	int* myPtr;
	myPtr = &num;
	printf("num is stored at: %p\n",  &num);
	printf("myPtr is stored at: %p\n", &myPtr);
	
	printf("num holds the value: %d\n", num);
	printf("myPtr holds the value: %p\n", &*myPtr);
		printf("myPtr points to this value: %d\n", *myPtr);
	return 0;
}