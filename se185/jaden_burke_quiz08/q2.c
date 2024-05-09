#include<stdio.h>
#include<stdlib.h>

/*add header file*/
typedef struct time {
    int hr;
    int min;
    int sec;
} time;
/*declare functions*/
void convTime(int seconds, time *t);
void printTime(int seconds, time *t);

void main() {
    time *mileTime;
     /*allocate memory*/
	 mileTime = (time *)malloc(3*sizeof(int));
    int seconds; 
    printf("Total seconds: ");
    scanf("%d", &seconds);
    convTime(seconds,mileTime); 
    printTime(seconds, mileTime);
}
void convTime(int seconds, time *t) {
	t->hr = seconds/3600;
	t->min = (seconds/60) % 60;
	t->sec = seconds % 60;
 }
void printTime(int seconds, time *t) {
 printf("%d seconds = %d hr %d min %d sec\n",seconds,t->hr,t->min,t->sec);
}