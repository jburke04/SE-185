#include <stdio.h>

typedef struct student{
	char studentName[50];
	double exam1;
	double exam2;
	double exam3;
} student;

double avg(double num1, double num2, double num3);

int main(){
	FILE* inFile = NULL;
	inFile = fopen("student_data.txt","w");
	student s1,s2,s3,s4;
	//student values when scanned
	student fileStudents[4];
	printf("Enter student1 name and three exam score: ");
	scanf("%s %lf %lf %lf",s1.studentName,&s1.exam1,&s1.exam2,&s1.exam3);
	printf("Enter student2 name and three exam score: ");
	scanf("%s %lf %lf %lf",s2.studentName,&s2.exam1,&s2.exam2,&s2.exam3);
	printf("Enter student3 name and three exam score: ");
	scanf("%s %lf %lf %lf",s3.studentName,&s3.exam1,&s3.exam2,&s3.exam3);
	printf("Enter student4 name and three exam score: ");
	scanf("%s %lf %lf %lf",s4.studentName,&s4.exam1,&s4.exam2,&s4.exam3);
	
	fprintf(inFile,"%s %lf %lf %lf\n",s1.studentName,s1.exam1,s1.exam2,s1.exam3);
	fprintf(inFile,"%s %lf %lf %lf\n",s2.studentName,s2.exam1,s2.exam2,s2.exam3);
	fprintf(inFile,"%s %lf %lf %lf\n",s3.studentName,s3.exam1,s3.exam2,s3.exam3);
	fprintf(inFile,"%s %lf %lf %lf\n",s4.studentName,s4.exam1,s4.exam2,s4.exam3);
	fclose(inFile);
	inFile = fopen("file.txt","r");
	
	for(int i = 0;i < 4;i++){
		
		fscanf(inFile," %s %lf %lf %lf",fileStudents[i].studentName,&fileStudents[i].exam1,
		&fileStudents[i].exam2,&fileStudents[i].exam3);
		printf("%s exam scores = %.2lf, %.2lf, %.2lf\n",fileStudents[i].studentName,fileStudents[i].exam1,
		fileStudents[i].exam2,fileStudents[i].exam3);
	}
	for(int i = 0;i < 4;i++){
		
		printf("%s exam average = %.2lf\n",fileStudents[i].studentName,avg(fileStudents[i].exam1,
		fileStudents[i].exam2,fileStudents[i].exam3));
	}

return 0;
}
double avg(double num1, double num2, double num3){
	return (num1 + num2 + num3)/3.0;
}
