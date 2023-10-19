
/* 
Team xx (please insert your team number instead of xx)
Team member 1 "Analyn Seeman" | "33%"
Team member 2 "Jaden Burke" | "33%"
Team member 3 "Sierra Izumi Brown" | "33%"
*/

/*-----------------------------------------------------------------------------
Compile and Run:
gcc RealFinalProject.c -o ./final -lncurses
./final wordList.txt
-----------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <time.h>

/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/

#define NUMWORDS 100

/* Screen Geometry */
#define COLUMNS 100
#define ROWS 40

/*-----------------------------------------------------------------------------
-								Structs
-----------------------------------------------------------------------------*/

typedef struct word{
	char word[100];
	int x;
	int y;
} word;

typedef struct AddedWords{
	
	char addedWords[50];
	
} AddedWords;

/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/

void drawGrid(int grid[ROWS][COLUMNS]);
void draw_character(int x, int y, char use);
void addWords(int* startIndex, int numWords,int totalWords, word currentWords[NUMWORDS], word allWords[NUMWORDS]);

/*-----------------------------------------------------------------------------
-								Main Function
-----------------------------------------------------------------------------*/

int main() {
	
 	/* Sets up adding words and counter for word usage */
	FILE* wordList = NULL;
	char askUser = 'X';
	int wordCount = 1000;
	int minWordLen = 0;
	int counter = 0;
	AddedWords tempWord[80];
	int i = 0;
	
	/*-----------------------------------------------------------------------------
	-							User Starts Gamer
	-----------------------------------------------------------------------------*/
	
	/* Creating Ncurses Environment */
	initscr();
    refresh();
	
	/* Random Seeding */
	srand(time(NULL));
	
	/* Opens File for Appending */ 
	wordList = fopen("wordList.txt", "a");
	
	/* Checks if File Will Open */ 	
	if(wordList == NULL){
		mvprintw(0, 0, "%c", 'E');
		exit(-1);
	}
	
	while(1){
		/* Makes sure the beginning prints only once.
		Index is used for formatting purposes. */ 
		if(i == 0){
			mvprintw(1, 0, "Hello, this is a typing game. You will need to type the words as they appear.");
			refresh();
			mvprintw(2, 0, "Would you like to play or add a word? (P/W)\n");
			refresh();
			scanw("%c", &askUser);
		}
		else{
			mvprintw((8 + (i * 4)), 0, "There are now %d words. Would you like to play or add another word? (P/W)\n", wordCount);
			scanw("%c", &askUser);
		}
		if(askUser == 'P'){
			mvprintw(25, 0, "You currently have %d words that can be used.\n", wordCount);
			refresh();
			mvprintw(26, 0, "What would you like you minimum word length to be?\n");
			refresh();
			scanw("%d", &minWordLen);
			break;
		}
		if(askUser == 'W'){
			if(i == 0){
				mvprintw((5 + (i * 4)), 0, "You currently have %d words that can be used", wordCount);
				refresh();
				mvprintw((6 + (i * 4)), 0, "What word would you like to add?\n");
				refresh();
				scanw("%s", tempWord[i].addedWords);
				fprintf(wordList, "\n%s", tempWord[i].addedWords);
				wordCount += 1;
				i++;
			}
			else{
				mvprintw((10 + (i * 4)), 0, "What word would you like to add?\n");
				scanw("%s", tempWord[i].addedWords);
				fprintf(wordList, "\n%s", tempWord[i].addedWords);
				wordCount += 1;
				i++;
			}
		}
	}

	/* Close txt file to make sure words are added */
	fclose(wordList);
	
	/*-----------------------------------------------------------------------------
	-							Game Board & Game Logic
	-----------------------------------------------------------------------------*/
	
	/* Declare new variables that will hold 
		the amount of words user wants to use */
	word allWords[wordCount];
	AddedWords tempHold[wordCount];
	
	/* Opens txt File for Reading Only */
	wordList = fopen("wordList.txt", "r");
	
	/* Checks if File Will Open */
	if(wordList == NULL){
		mvprintw(0, 0, "%c", 'E');
		exit(-1);
	}
	
	/* Scans Amount and actual Words Onto Array */
	for(i = 0; i <= wordCount; i++){
		fscanf(wordList, "%s\n", &tempHold[i].addedWords);
	}
	
	/* Checks for minimum word length user wants */
	int count = 0;
	for(i = 0; i <= wordCount; i++){
		if(strlen(tempHold[i].addedWords) >= minWordLen){
			strcpy(allWords[count].word, tempHold[i].addedWords);
			counter++;
			count++;
		}
	}
	
	/* Close txt file for remainder of the program */
	fclose(wordList);
	
	/* Filling all word list */
	for(i = 0; i < wordCount; i++){
		fscanf(wordList, "%s\n", allWords[i].word);
		allWords[i].x = (rand() % (97 - strlen(allWords[i].word)) + 1);
	}
	
	/* Random Seeding */
	srand(time(NULL));
	
	/* Grid variable */
	int grid[ROWS][COLUMNS];
	
	/* Setting Up Time Variables */
	time_t current;
	current = time(NULL);
	time_t start;
	time_t veryStart;
	veryStart = current;
	start = current;
	
	/* Index to be used later */
	int index = 0;
	
	/* Variable to check if loop should still run */
	int running = 1;
	
	/* Creating a clear line string */
	char clear[98];
	
	for(int i = 0;i< 98;i++){
		clear[i] = ' ';
	}
	
	char userWord[80];
	word currentWords[wordCount];
	
	/* Creating Ncurses Environment */
	initscr();
    refresh();
	
	/* Drawing grid */
	drawGrid(grid);
	
	/* Converts the grid of integers into the appropriate grid of characters */
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
	
	/* Adding First Word */
	addWords(&index, 1,counter, currentWords, allWords);
	
	while(running){
		/* Prints all the words with at their correct x and y */
		for(int i = 0; i < NUMWORDS;i++){
			mvprintw(currentWords[i].y,currentWords[i].x,"%s", currentWords[i].word);
		}
		refresh();
		
		/* Scanning user input */
		mvscanw(60,0,"%s" , userWord);
		
		/* Checks to see if user input matches any words in list,
		if it does, changes the word in list to be empty */
		for(int i = 0; i < NUMWORDS;i++){
			if(strcmp(userWord,currentWords[i].word) == 0){
				strcpy(currentWords[i].word,"");
			}
		}
		
		/* clears the line of the user input */
		mvprintw(60 ,0,"%s", clear);
		refresh();
		
		/* Clears all the words off the board */
		for(int i = 0; i < NUMWORDS;i++){
			if(currentWords[i].y != 0){
				mvprintw(currentWords[i].y ,1,"%s", clear);
			}
		}
		
		/* Gets current time */
		current = time(NULL);
		
		/* If the word in the list is not empty, 
			adjusts the y by how long it took for user input */
		addWords(&index, current - start,counter, currentWords, allWords);
		
		/* Re-assigns the start time */
		start = current;
		
		/* Breaks the loop if the y of any word is 40 or higher */
		for(int i = 0; i < NUMWORDS;i++){
			if(currentWords[i].y >= 39){
				running = 0;
			}
		}
		
	}
	/* Cleanup Ncurses Environment */ 
	endwin();
	
	/* Gets current time */
	current = time(NULL);
	
	/* Print out game time to the player */
	printf("You lasted %d seconds", current - veryStart);
	
	return 0;
}

/*-----------------------------------------------------------------------------
-								User Defined Functions' Definition
-----------------------------------------------------------------------------*/

void draw_character(int x, int y, char use)
{
    mvaddch(y,x,use);
    refresh();
}

/* Makes of grid of integers based on if it is the top or bottom row
	or if it is the right most or left most collumn */
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

void addWords(int* startIndex, int numWords,int totalWords, word currentWords[NUMWORDS], word allWords[NUMWORDS]){
	srand(time(NULL));
	/* Used to put the added words at the right y when first printed */
	int startY = 0;
	/*	- Copies word of an index from allwords into currentWords
		- Randomizes the x of the word struct in currentWords
		- Sets the y to (numWords - startY)
		- This is because the y of the first words needs to be bigger than 
		the later words increments y */
		
	for(int i = *startIndex; i < *startIndex + numWords; i++){
		strcpy(currentWords[i].word, allWords[rand() % totalWords].word);
		currentWords[i].x = allWords[i].x;
		currentWords[i].y += numWords - startY;
		startY++;
		
	}
	/* Increments the y of all words in currentWords by number of words
		number of words is just time elapsed */
	for(int i = 0; i < *startIndex; i++){
		if(strcmp(currentWords[i].word,"") != 0){
			currentWords[i].y = currentWords[i].y + numWords;
		}
		
	}
	/* Increments the starting index for future use */
	*startIndex += numWords;
}