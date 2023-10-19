/*-----------------------------------------------------------------------------
-					  		SE 185 Lab 08
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name:
- Section:
-	NetID:
-	Date:
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
/* Mathmatical constants */
#define PI 3.14159

/* 	Screen geometry
    Use ROWS and COLUMNS for the screen height and width (set by system)
    MAXIMUMS */
#define COLUMNS 100
#define ROWS 80

/* 	Character definitions taken from the ASCII table */
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '

/*	Number of samples taken to form an moving average for the gyroscope data
    Feel free to tweak this. */
#define NUM_SAMPLES 10

#define MAXPOINTS 10000
/*-----------------------------------------------------------------------------
-								Static Data
-----------------------------------------------------------------------------*/
/* 2D character array which the maze is mapped into */
char MAZE[COLUMNS][ROWS];


/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/
/*	POST: Generates a random maze structure into MAZE[][]
    You will want to use the rand() function and maybe use the output %100.
    You will have to use the argument to the command line to determine how
    difficult the maze is (how many maze characters are on the screen). */
void generate_maze(int difficulty);

/*	PRE: MAZE[][] has been initialized by generate_maze()
    POST: Draws the maze to the screen */
void draw_maze(void);

/*	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y */
void draw_character(int x, int y, char use);

/*	PRE: -1.0 < mag < 1.0
    POST: Returns tilt magnitude scaled to -1.0 -> 1.0
    You may want to reuse the roll function written in previous labs. */
double calc_roll(double mag);

/* 	Updates the buffer with the new_item and returns the computed
    moving average of the updated buffer */
double m_avg(double buffer[], int avg_size, double new_item);


/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
/*	Main - Run with './ds4rd.exe -t -g -b' piped into STDIN */
void main(int argc, char* argv[])
{
	int t, tempT;
	double new_x, new_y, new_z;
	int b_Up, b_Down, b_Left, b_Right;
	double avg_x, avg_y, avg_z;
	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int curCharX = 10,curCharY = 0;
	int pastCharX,pastCharY;
	int win = 0;

  if (argc != 2 )
  {
      printw("You must enter the difficulty level on the command line.");
      refresh();
      return;
  }
  else
  {
	  int dif;
	sscanf(argv[1], "%d", &dif );
    /* 	Setup screen for Ncurses
        The initscr functionis used to setup the Ncurses environment
        The refreash function needs to be called to refresh the outputs
        to the screen */
    initscr();
    refresh();

    /* WEEK 2 Generate the Maze */
	generate_maze(dif);
	draw_maze();
    /* Read gyroscope data and fill the buffer before continuing */
	for(int i = 0; i < NUM_SAMPLES; i++)
    {
       scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &new_x, &new_y, &new_z, &b_Up, &b_Right, &b_Down, &b_Left);
        x[i] = new_x;
        y[i] = new_y;
        z[i] = new_z;
    }
	tempT = t;
    /* Event loop */
    do
    {

        /* Read data, update average */
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &new_x, &new_y, &new_z, &b_Up, &b_Right, &b_Down, &b_Left);
		avg_x = m_avg(x, NUM_SAMPLES, new_x);
        avg_y = m_avg(y, NUM_SAMPLES, new_y);
        avg_z = m_avg(z, NUM_SAMPLES, new_z);

		//printf("%d %d %lf %lf %lf\n",t,tempT,new_x,new_y,new_z);
        /* Is it time to move?  if so, then move avatar */
		if(t - tempT > 500){
			tempT = t;
			pastCharX = curCharX;
			pastCharY = curCharY;
			if(avg_x > .8){

				if(MAZE[curCharY][curCharX-1] == EMPTY_SPACE && curCharX > 0){
					curCharX -= 1;
					draw_character(curCharX,curCharY,AVATAR);
					draw_character(pastCharX,pastCharY,EMPTY_SPACE);

				}


			} else if(avg_x < -.8){

				if(MAZE[curCharY][curCharX+1] == EMPTY_SPACE && curCharX < 80){

					curCharX += 1;
					draw_character(curCharX,curCharY,AVATAR);
					draw_character(pastCharX,pastCharY,EMPTY_SPACE);

				}
			} else{
				if(MAZE[curCharY+1][curCharX] == EMPTY_SPACE){

					curCharY += 1;
					draw_character(curCharX,curCharY,AVATAR);
					draw_character(pastCharX,pastCharY,EMPTY_SPACE);
				}
				draw_character(curCharX,curCharY,AVATAR);
			}

		}
		if(MAZE[curCharY][curCharX-1] == WALL && MAZE[curCharY][curCharX+1] == WALL
		&& MAZE[curCharY+1][curCharX] == WALL){
			break;
		}else if(curCharY >= 80){
			win = 1;
			break;
		}
    } while(1); // Change this to end game at right time

    /* Print the win message */


    /* This function is used to cleanup the Ncurses environment.
    Without it, the characters printed to the screen will persist
    even after the progam terminates */
    endwin();

  }
	if(win == 1){
    printf("YOU WIN!\n");
	} else {
		printf("YOU LOST!\n");
	}
}

double m_avg(double buffer[], int avg_size, double new_item)
{
	double avg = 0;
	for(int i = 0; i < avg_size - 1; i++){
		buffer[i] = buffer[i+1];
		avg += buffer[i];
	}
    buffer[avg_size-1] = new_item;
	avg += new_item;
	return (avg / avg_size);
}

void generate_maze(int difficulty){
	srand(time(NULL));
	for(int i = 0; i < ROWS;i++){
		for(int j = 0; j < COLUMNS;j++){
			int random = rand() % 100;
			if(random < difficulty){
				MAZE[i][j] = WALL;
			} else{
				MAZE[i][j] = EMPTY_SPACE;
			}
		}
	}
}

void draw_maze(void){
	for(int i = 0; i < ROWS;i++){
		for(int j = 0; j < COLUMNS;j++){
			draw_character(i,j,MAZE[j][i]);
		}
	}
}

/* 	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y
    THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
    DO NOT NEED TO CHANGE THIS FUNCTION. */
void draw_character(int x, int y, char use)
{
    mvaddch(y,x,use);
    refresh();
}
