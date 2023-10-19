   
// Lab 09 DS4Talker Skeleton Code       

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses/ncurses.h>
#define WORDLENGTH 11
#define MAXWORDS 100
#define DEBUGM 1   // Set this to 0 to disable debug output

// Reads words from the file into WL and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int read_words(char* WL[MAXWORDS], char* file_name);
void undo(char sentence[],char undo[]);

void trimws(char* str);

void draw_character(int x, int y, char use);

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordcount;
	int i;
	int time, triangle,circle,cross,square, ljoyX,ljoyY,rjoyX,rjoyY;
	int leftJPress,rightJPress, share,options,rT,rB,lT,lB;
	int curWordX = 1,curWordY = 0;
	int pastWordX = 0,pastWordY = 0;
	int time2 = 0;
	char sentence[80] = "";
	char undoSentence[160];
	char clear[80];
	for(int i = 0; i < 80;i++){
		clear[i] =' ';
	}
	
	
	wordcount = read_words(wordlist, argv[1]);
	int rows = wordcount / 5;
	if (DEBUGM) {
		printf("Read %d words from %s \n", wordcount, argv[1]);
		for (i = 0; i < wordcount; i++) {
			printf("%s,", wordlist[i]);

		}
		printf("\n");
	}

	// most of your code goes here. Do not forget to include the ncurses library 
	initscr();
    refresh();
	int wordPrinted = 0;
		for(int i = 0;i < 5;i++){
			for(int j = 0;j<= rows;j++){
				if(wordPrinted == 76){
					break;
				}
				mvprintw(j, i*15, "%15s",wordlist[wordPrinted]);
				
				wordPrinted++;
				refresh();
			}
		}
	while(1){
		scanf("%d, %d,%d,%d,%d, %d,%d,%d,%d,%d,%d,%d,%d, %d,%d,%d,%d",&time,&triangle,&circle,&cross,&square,&rightJPress,
		&leftJPress,&options,&share,&rT,&lT,&rB,&lB,&ljoyX,&ljoyY,&rjoyX,&rjoyY);
		draw_character(curWordX*16,curWordY,'*');
		mvprintw(50,0,"%s",sentence);
		mvprintw(49,0,"%s",undoSentence);
		if(pastWordX != curWordX*16 || pastWordY != curWordY){
			draw_character(pastWordX,pastWordY,' ');
		}
		if(time-time2 > 500){
			time2=time;
			pastWordX = curWordX*16;
			pastWordY = curWordY;
			if(ljoyX < -100 && curWordX > 1){
				curWordX--;
			} else if(ljoyX > 100 && curWordX < 5){
				curWordX++;
			} else if(ljoyY < -100 && curWordY > 0){
				curWordY--;
			} else if(ljoyY > 100 && curWordY < rows - 1){
				curWordY++;
			}
			
			if(triangle == 1){
				strcat(sentence, " ");
				strcat(sentence, wordlist[curWordY+(curWordX-1)*16]);
				strcat(undoSentence, "[");
				strcat(undoSentence, " ");
				strcat(undoSentence, wordlist[curWordY+(curWordX-1)*16]);
				
			} 
			if(square == 1){
				strcat(sentence, wordlist[curWordY+(curWordX-1)*16]);
				strcat(undoSentence, "[");
				strcat(undoSentence, wordlist[curWordY+(curWordX-1)*16]);
				
			} 
			if(leftJPress == 1){
				strcpy(sentence, "");
				mvprintw(50,0,"%s",clear);
			}
			if(cross == 1){
				undo(sentence,undoSentence);
				mvprintw(50,0,"%s",clear);
			}
				
			
		}
		
		
	}
	
	endwin();
	return 0;
}

// DO NOT MODIFY THIS FUNCTION!
void trimws(char* str) {
	int length = strlen(str);
	int x;
	if (length == 0) return;
	x = length - 1;
	while (isspace(str[x]) && (x >= 0)) {
		str[x] = '\0';
		x -= 1;
	}
}


// DO NOT MODIFY THIS FUNCTION!
int read_words(char* WL[MAXWORDS], char* file_name)
{
	int numread = 0;
	char line[WORDLENGTH];
	char *p;
	FILE* fp = fopen(file_name, "r");
	while (!feof(fp)) {
		p = fgets(line, WORDLENGTH, fp);
		if (p != NULL) 
		{
			trimws(line);
			WL[numread] = (char *)malloc(strlen(line) + 1);
			strcpy(WL[numread], line);
			numread++;
		}
	}
	fclose(fp);
	return numread;
}

void draw_character(int x, int y, char use)
{
    mvaddch(y,x,use);
    refresh();
}

void undo(char sentence[],char undo[]){
	char lastWord[50];
	char holder[80];
	
	
	strcpy(lastWord, strrchr(undo,'[') + 1);
	
	strncat(holder,sentence,strlen(sentence) - strlen(lastWord));
	strcpy(sentence,holder);
	strcpy(holder, "");
	strcpy(lastWord, strrchr(undo,'['));
	strncat(holder,undo,strlen(undo) - strlen(lastWord));
	strcpy(undo,holder);
	
	
}

