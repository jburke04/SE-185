//includes
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
int numStudents = 2;
int numAssignements = 4;
//prototype functions
char letterGrade(double grade);
double studentAverage(double studentGrades[numStudents][numAssignements],int numCols, int wantedRow);
int main(void){
	//variable declarations
	double studentGrades[numStudents][numAssignements];
	int i;
	int j;
	double holder;
	
	//getting user input
	printf("Please Enter assignement grades for student 1 and student 2\n");
	for(i = 0; i < numStudents; i++){
		for(j = 0; j < numAssignements; j++){
			printf("Student-%d Assignment-%d grade: ",i+1,j+1);
			scanf(" %lf",&studentGrades[i][j]);
		}
	}
	//outputting averages and letter grades
	
	printf("\nStudent 1 Avg = %.2lf",studentAverage(studentGrades,numAssignements,0));
	printf("\nStudent 1 Grade = %c",letterGrade(studentAverage(studentGrades,numAssignements,0)));
	printf("\nStudent 2 Avg = %.2lf",studentAverage(studentGrades,numAssignements,1));
	printf("\nStudent 2 Grade = %c",letterGrade(studentAverage(studentGrades,numAssignements,1)));
	return 0;
}
//takes the average of a given row of a 2d matrix
double studentAverage(double studentGrades[numStudents][numAssignements],int numCols, int wantedRow){
	double avg = 0;
	for(int i = 0;i < numCols;i++){
		avg += studentGrades[wantedRow][i];
	}
	return avg / (double)numCols;
}
//using given metric returns a letter grade based on score
char letterGrade(double grade){
	if(grade <=100 && grade >= 85){
		return 'A';
	} else if(grade >= 75){
		return 'B';
	} else if(grade >= 60){
		return 'C';
	} else {
		return 'F';
	} 
}