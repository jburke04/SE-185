/*----------------------------------------------------------------------------
-		                    SE 185: Lab 06 - Bop-It!	    	             -
-	Name:Jaden Burke														 -
- 	Section:2																 -
-	NetID:jadenb04														     -
-	Date:10/11/2022															 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
int gameStart(int t,int c, int x, int s);
void printButton();
void runGame(int t,int c, int x, int s);
/*----------------------------------------------------------------------------
-	                            Notes                                        -
-----------------------------------------------------------------------------*/
// Compile with gcc lab06.c -o lab06
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -b | ./lab06

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
//declaring a bunch of global variables instead of messing with pointers
int rounds = 0;
int wrongButtonPressed = 0;
int rightButton;
//defining time variables
int timeLimit = 10000;
int startTime;
int curTime;
int main(int argc, char *argv[])
{
	//defining variables for the buttons
	int triangle, circle, x_button, square;
	
	
	
	
	int start = 1;
    srand(time(NULL)); /* This will ensure a random game each time. */
	printf("Please press a button to start the game\n");

	while(1){
		//scanning button values
		scanf("%d, %d, %d, %d, %d",&curTime,&triangle, &circle, &x_button, &square);
		if(start){
			start = !(gameStart(triangle, circle, x_button, square) > 0);
			continue;
		}
		
		
		
		if(rounds == 0){
			printButton();
		}
		
		if((curTime - startTime) > timeLimit){
			printf("You ran out of time. :(\n");
			printf("Thanks for playing!\n");
			printf("You made it through %d rounds!\n", rounds);
			break;
		} else if(wrongButtonPressed){
			printf("Wrong button! :(\n");
			printf("You lose!\n");
			printf("You made it through %d rounds!\n", rounds);
			break;
		} 
		runGame(triangle, circle, x_button, square);
		//printf("time:%d\n %d %d %d %d\n",curT, triangle, circle, x_button,square);
	}
    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */
//the function i use in order to just check if a button has been pressed to start the game
int gameStart(int t,int c, int x, int s){
	return t + c + x + s;
}
//randomly prints which button to press and prints it and how much time you have
//also is where i keep track of rounds and the start time
void printButton(){
	rounds += 1;
	startTime = curTime;
	rightButton = rand() % 4;
	if(rightButton == 0){
		printf("Press the triangle button!\n");
	}else if(rightButton == 1){
		printf("Press the circle button!\n");
	} else if(rightButton == 2){
		printf("Press the cross button!\n");
	} else if(rightButton == 3){
		printf("Press the square button!\n");
	}
	printf("You have %d milliseconds to respond!\n", timeLimit);
	timeLimit -= 500;
	
}
//checks to see if a button has been pressed and theres been enough of a buffer since the last press
//then checks to see if you hit the right button or not
void runGame(int t,int c, int x, int s){
	
	if((t + c + x + s) != 0 && (curTime - startTime) > 250){
		if(t == 1 && rightButton == 0){
		printButton();
	} else if(c == 1 && rightButton == 1){
		printButton();
	} else if(x == 1 && rightButton == 2){
		printButton();
	} else if(s == 1 && rightButton == 3){
		printButton();
	} else{
		wrongButtonPressed = 1;
	}
	} 
}
