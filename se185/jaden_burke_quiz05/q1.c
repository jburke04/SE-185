//includes
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
//prototype functions
double avg(double array[], int numElements);
double weightedAvg(double homeworkAvg,double examAvg);
int main(void){
	//defining variables
	int numHomework = 5;
	int numExam = 3;
	double hw[numHomework];
	double exam[numExam];
	double grades[3];
	int i;
	
	//scanning for user input of homework and exam grades
	for(i = 1;i<numHomework + 1;i++){
		printf("Enter your grade (%%) for HW #0%d: ", i);
		scanf("%lf",&hw[i-1]);
	}
	for(i = 1;i< numExam + 1;i++){
		printf("Enter your grade (%%) for Exam #0%d: ", i);
		scanf("%lf",&exam[i-1]);
	}
	
	//inputting the averages of the grades and the weighted average into an array
	for(i = 0; i < 3; i++){
		if(i == 2){
			grades[i] = weightedAvg(grades[i-2],grades[i-1]); 
		} else if( i == 1){
			grades[i] = avg(exam,numExam);
		} else{
			grades[i] = avg(hw,numHomework);
		}
		
		
	}
	
	//outputting the final weighted grade
	printf("\nFinal Grade = %.2lf%%\n",grades[2]);
	return 0;
}

//function that just adds all the elements of an array then divides by number of elements
double avg(double array[], int numElements){
	double avg = 0;
	for(int i = 0;i< numElements;i++){
		avg += array[i];
	}
	
	return avg / numElements;
}

//function that gets weighted average using the given information from the assignement
double weightedAvg(double homeworkAvg,double examAvg){
	return ((.4 * homeworkAvg) + (.6 * examAvg));
}