/*----------------------------------------------------------------------------
-		         SE 185: Midterm Project   	               -
- List the names of all team members, their roles, and their participation
1- Jaden Burke - Role: While loop creator, quiz Creator, debugger - Participation: 50%
Made the while loop and quiz one. Also helped debug.
2- Izumi Brown - Role: Quiz Creator and debugger - Participation: 50%
Made quiz 2 and three and helped debug
3-
4-
5-																                                     -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									                                   -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
/*----------------------------------------------------------------------------
-	                            Functions Prototypes                                   -
-----------------------------------------------------------------------------*/
int quiz1();
int quiz2();
int quiz3();
int quizSelection(int quizTaken);
int quizRandomizer();

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/

// Compile with gcc midtermProject.c -o proj

/*----------------------------------------------------------------------------
-								Implementation								                               -
-----------------------------------------------------------------------------*/

//global variables
//counts score of current run of a quiz
int currScore = 0;
//keeps track of your score over all attempts of a quiz
int finalScore = 0;
//counts how many times youve taken a specific quiz
int timesTaken = 0;
//keeps track of score for all tries of all quizzes
int overallAvg = 0;
//keeps track of how many times youve taken a quiz
int overallTimesTaken = 0;
int main(int argc, char *argv[])
{
	//defining a variable for use when asking to retake a quiz
	char takeAgain = ' ';
	//just a holder variable
	int quizTaken;
	
	
	
	
	printf("Welcome! This program will allow you to take three different quizzes.\n");
	while(1){
		//if you haven't taken a quiz or are taking another, asks for input in order to randomize which one you get
		if(timesTaken == 0){
		quizTaken = abs((quizRandomizer() * rand())) % 3;
		}
		//run a quiz depending on what is given above
		quizSelection(quizTaken);
		//if score isnt perfect, run quiz again after adding the score you got to total
		//else print the average of you scores over all quiz attempts
		if(currScore != 15){
			finalScore += currScore;
			overallAvg += currScore;
			continue;
		}  else if(currScore == 15){
			finalScore += currScore;
			overallAvg += currScore;
			printf("Your quiz average was: %.2lf", (double)finalScore / (double)timesTaken);
			
		}
		printf("\nWould you like to take another quiz? Please Answer y or n\n");
		scanf(" %c", &takeAgain);
		
		if(takeAgain == 'y'){
			finalScore = 0;
			timesTaken = 0;
		} else {
			printf("That's too bad, your overall average was: %.2lf", (double)overallAvg / (double)overallTimesTaken);
			break;
		}
	}
    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */
int quizRandomizer(){
	srand(time(NULL));
	int userSeed;
	printf("Please enter a number between 1 and 9: ");
	scanf(" %d",&userSeed);
	return userSeed;
}
int quizSelection(int quizTaken){
	
	if(quizTaken == 0){
		quiz1();
	}
	else if (quizTaken == 1){
		quiz2();
	}
	else{
		quiz3();
	}
	return 0;
}

int quiz1(){
	
	char ans1[10] = "True";
	char ans2[10] = "False";
	char ans3[10] = "True";
	char curAns[10];
	currScore = 0;
	overallTimesTaken += 1;
	timesTaken += 1;
	printf("This is Quiz 1\n");
	printf("Please Answer Questions as True or False\n");
	printf("What is the output?\n");
	printf("int x = 0;\n");
	printf("int y = 1;\n");
	printf("if(!(x) && y){\n");
	printf("\tprintf(\"True\");\n");
	printf("} else{\n");
	printf("\tprintf(\"False\");\n");
	printf("}\n");
	printf("Anwer: ");
	scanf("%s",&curAns);
	if(strcmp(curAns,ans1) == 0){
		printf("That is correct!\n");
		currScore += 5;
	} else {
		printf("That's the wrong choice! \n");
	}
	printf("This is a valid variable declaration in C\n");
	printf("int 12345;\n");
	printf("Anwer: ");
	scanf("%s",&curAns);
	if(strcmp(curAns,ans2) == 0){
		printf("That is correct!\n");
		currScore += 5;
	} else {
		printf("That's the wrong choice! \n");
	}
	printf("str1 = str2; will not successfully copy str2 to str1\n");
	printf("Anwer: ");
	scanf("%s",&curAns);
	if(strcmp(curAns,ans3) == 0){
		printf("That is correct!\n");
		currScore += 5;
	} else {
		printf("That's the wrong choice! \n");
	}
	return 0;
	
}

int quiz2(){
	char a1 = 'a';
	char b1 = 'b';
	char c1 = 'c';
	char d1 = 'd';
	char q1;
	char q2;
	char q3;
	currScore = 0;
	overallTimesTaken += 1;
	timesTaken += 1;
	
	printf("\nYou will take Quiz 2.\n");
	printf("This is a multiple choice question, please only enter a, b, c or d.\n");
	printf("\nHere is the first question: \n");
	
	printf("What is the output of the function below?: \n");
	printf("int x = 10; \n");
	printf("int x += 10; \n");
	printf("printf(\"x\");\n");
	printf("a = 20\nb = x\nc = 10\nd = 99\n");
	scanf(" %c", &q1);
	
	if (q1 == b1){
		printf("That is correct! \n");
		currScore += 5;
	}
	else{
		printf("That's the wrong choice! \n");
	}
	
	printf("How many times does the following for loop run: ");
	printf("for(int i = 0; i < 7;i++){\n");
	printf("}\n");
	printf("a: 7\nb: 6\nc: Infinitely many\nd: 0\n");
	scanf(" %c", &q2);
	
	if (q2 == a1){
		printf("That is correct!\n");
		currScore += 5;
	}
	else {
		printf("That's the wrong choice!\n");
	}
	
	printf("Why is the function in line 5 incorrect?\n");
	printf("int 1x = 52;\n");
	printf("a: There is nothing wrong\nb: 52 is not an integer\nc: integers can only contain one number\nd: The variable cannot begin with a number\n");
	scanf(" %c", &q3);
	
	if (q3 == d1){
		printf("That is correct!\n");
		currScore += 5;
	}
	else {
		printf("That's the wrong choice!\n");
	}
	return 0;
}

int quiz3(){
	char q7Ans[50];
	char q8Ans[50];
	char q9Ans[50];
	char q7Sol[50] = "syntax";
	char q8Sol[50] = "stdio.h";
	char q9Sol[50] = "<";
	currScore = 0;
	overallTimesTaken += 1;
	timesTaken += 1;
	
	printf("\nYou will take Quiz 3.\n");
	printf("This is a fill in the blank quiz.\n");
	
	printf("\nHere is the first question.\n");
	
	printf("int num1 = 4\n");
	printf("int num2 = 6\n");
	printf("nun1 = num2\n");
	printf("What kind of error is this called?: ");
	scanf(" %s", &q7Ans);
	if (strcmp(q7Ans, q7Sol) == 0){
		printf("That is correct!\n");
		currScore += 5;
	}
	else{
		printf("That is the wrong answer.\n");
	}
	
	printf("\nQuestion 2: \n");
	
	printf("The first and most common header file in C programming is #include<    >?: ");
	scanf(" %s", &q8Ans);
	if (strcmp(q8Ans, q8Sol) == 0){
		printf("That is correct!\n");
		currScore += 5;
	}
	else {
		printf("That is the wrong answer.\n");
	}
	
	printf("\nQuestion 3: \n");
	
	printf("const NUMBER = 3;");
	printf("int i;\n");
	printf("int array1 = {10, 15, 50};\n");
	printf("\nfor (i = 0, i <= NUMBER; ++i){ \n");
	printf("	if(array1[i] _?_ 20){ \n");
	printf("		array1[i] = array1[i] * 2; \n");
	printf("	} \n");
	printf("}\n");
	printf("What goes in _?_ so that the number in array1 is less than 20?: ");
	scanf(" %s", &q9Ans);
	if (strcmp(q9Ans, q9Sol) == 0){
		printf("That is correct!\n");
		currScore += 5;
	}
	else {
		printf("That is the wrong answer.\n");
	}

}
