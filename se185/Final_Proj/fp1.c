//SE 185: Final Project Template//
/////////////////////////
/* 
Team xx (please insert your team number instead of xx)
Team member 1 "Analyn Seeman" | "33%"
Team member 2 "Sierra Brown" | "33%"
Team member 3 "Jaden Burke" | "33%"
Team member 4 "Name" | "Percentage of Contribution to The Project"
*/

////////////////////
#include<stdio.h>//
//add more here////
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses/ncurses.h>
#include <time.h>
//////////////////////
//Struct Definition//
////////////////////
typedef struct word{
	char word[100];
	int x;
	int y;
} word;

//global variables
#define COLUMNS 100
#define ROWS 40
#define NUMWORDS 1000
/////////////////////////////////////
//User Defined Functions Prototype//
//List prototypes here and define//
//tehm below the main function////
/////////////////////////////////
void draw_character(int x, int y, char use);
void drawGrid(int grid[ROWS][COLUMNS]);
void addWords(int* startIndex, int numWords, word currentWords[NUMWORDS], word allWords[NUMWORDS]);
int main(){
	
	
	//list of all words
	word allWords[NUMWORDS];
	//list of words to print
	word currentWords[NUMWORDS];
	//filling all word list 
	for(int i = 0; i < NUMWORDS; i ++){
		strcpy(allWords[i].word,"test");
		allWords[i].x = rand() % (98 - strlen(allWords->word));
	}
	
	//seeding random
	srand(time(NULL));
	//grid variable
	int grid[ROWS][COLUMNS];
	//setting up time variables
	time_t current;
	current = time(NULL);
	time_t start;
	time_t veryStart;
	veryStart = current;
	start = current;
	
	//index to be used later
	int index = 0;
	//variable to check if loop should still run
	int running = 1;
	//creating a clear line string
	char clear[98];
	for(int i = 0;i< 98;i++){
		clear[i] = ' ';
	}
	char userWord[80];
	
	//creating ncurses environment
	initscr();
    refresh();
	
	//drawing grid
	drawGrid(grid);
	//converts the grid of integers into the appropriate grid of characters
	for(int r = 0; r < ROWS; r++){
		for(int c = 0;c < COLUMNS; c++){
			if(grid[r][c] == 1){
				draw_character(c,r,'_');
			} else if(grid[r][c] == 2){
				draw_character(c,r,'|');
			} else{
				draw_character(c,r,' ');
			}
		}
	}
	//adding first word
	addWords(&index, 1, currentWords, allWords);
	
	
	while(running){
		//prints all the words with at their correct x and y
		for(int i = 0; i < NUMWORDS;i++){
			mvprintw(currentWords[i].y,currentWords[i].x,"%s", currentWords[i].word);
		}
		refresh();
		
		//scanning user input
		mvscanw(60,0,"%s" , userWord);
		
		//checks to see if user input matches any words in list
		//if it does, changes the word in list to be empty
		for(int i = 0; i < NUMWORDS;i++){
			if(strcmp(userWord,currentWords[i].word) == 0){
				strcpy(currentWords[i].word,"");
			}
		}
		
		//clears the line of the user input
		mvprintw(60 ,0,"%s", clear);
		refresh();
		
		//clears all the words off the board
		for(int i = 0; i < NUMWORDS;i++){
			if(currentWords[i].y != 0){
				mvprintw(currentWords[i].y ,1,"%s", clear);
			}
		}
		
		//gets current time
		current = time(NULL);
		//if the word in the list is not empty, adjusts the y by how long it took for user input
		addWords(&index, current - start, currentWords, allWords);
		
		//re-assigns the start time
		start = current;
		
		//breaks the loop if the y of any word is 40 or higher
		for(int i = 0; i < NUMWORDS;i++){
			if(currentWords[i].y >= 39){
				running = 0;
			}
		}
	}
	endwin();
	current = time(NULL);
	printf("You lasted %d seconds", current - veryStart);
	return 0;
}

///////////////////////////////////////
//User Defined Functions' Definition//
/////////////////////////////////////

void draw_character(int x, int y, char use)
{
    mvaddch(y,x,use);
    refresh();
}

//makes of grid of integers based on if it is the top or bottom row
// or if it is the right most or left most collumn
void drawGrid(int grid[ROWS][COLUMNS]){
	for(int r = 0; r < ROWS; r++){
		for(int c = 0;c < COLUMNS; c++){
			if(r == 0 || r == ROWS - 1){
				grid[r][c] = 1;
			} else if(c == 0 || c == COLUMNS - 1){
				grid[r][c] = 2;
			} else {
				grid[r][c] = 0;
			}
		}
	}
	
}

void addWords(int* startIndex, int numWords, word currentWords[NUMWORDS], word allWords[NUMWORDS]){
	//this is used to put the added words at the right y when first printed
	int startY = 0;
	//copies word of an index from allwords into currentWords
	//randomizes the x of the word struct in currentWords
	//sets the y to numWords - startY
	//this is because the y of the first words needs to be bigger than the later words
	//increments y
	for(int i = *startIndex; i < *startIndex + numWords; i++){
		strcpy(currentWords[i].word,allWords[i].word);
		currentWords[i].x = allWords[i].x;
		currentWords[i].y += numWords - startY;
		startY++;
		
	}
	//increments the y of all words in currentWords by number of words
	// number of words is just time elapsed
	for(int i = 0; i < *startIndex; i++){
		if(strcmp(currentWords[i].word,"") != 0){
			currentWords[i].y = currentWords[i].y + numWords;
		}
		
	}
	//increments the starting index for future use
	*startIndex += numWords;
}