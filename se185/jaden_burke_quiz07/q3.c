#include<stdio.h>
void examScores(int scores[], int numScores);
void examStat(int scores[],double result[], int numScores, int resultLength);

int main() {
    int numExams = 30;
	int resultLength = 5;
	int midterm1Score[30];
	double result[resultLength];
	
	
	examScores(midterm1Score,numExams);
	examStat(midterm1Score,result,numExams,resultLength);
	
	printf("Midterm 1 exam average: %.2lf\n",result[0]);
	printf("Maximum score: %.2lf\n",result[1]);
	printf("Minimum score: %.2lf\n",result[2]);
	printf("Number of student fails: %.2lf\n",result[3]);
	printf("Number of student A's: %.2lf\n",result[4]);
    return 0;
}

void examStat(int scores[],double result[], int numScores, int resultLength){
	double avgHolder;
	double maxHolder = scores[0];
	double minHolder = scores[0];
	double failHolder;
	double AHolder;
	for(int i = 0; i < numScores; i++){
		avgHolder += scores[i];
		if(scores[i] > maxHolder){
			maxHolder = scores[i];
		}
		if(scores[i] < minHolder){
			minHolder = scores[i];
		} 
		
		if(scores[i] < 60){
			failHolder++;
		}
		if(scores[i] >= 93){
			AHolder++;
		}
		
	}
	result[0] = avgHolder / numScores;
	result[1] = maxHolder;
	result[2] = minHolder;
	result[3] = failHolder;
	result[4] = AHolder;
}

void examScores(int scores[], int numScores){
	for(int i = 1; i < numScores + 1;i++){
		printf("Student %d midterm exam score: ", i);
		scanf("%d" , &scores[i-1]);
	}
}