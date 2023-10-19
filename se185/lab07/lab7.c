/*-----------------------------------------------------------------------------
-					          SE 185 Lab 07 - The DS4 Equalizer
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name:Jaden Burke
- 	Section:2
-	NetID:jadenb
-	Date:10/18/22
-
-   This file provides the outline for your program
-   Please implement the functions given by the prototypes below and
-   complete the main function to make the program complete.
-   You must implement the functions which are prototyped below exactly
-   as they are requested.
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include<stdlib.h>

/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
#define PI 3.141592653589

/* NO GLOBAL VARIABLES ALLOWED */


/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------
    PRE: Arguments must point to double variables or int variables as appropriate
    This function scans a line of DS4 data, and returns
    True when left button is pressed
    False Otherwise
    POST: it modifies its arguments to return values read from the input line.
------------------------------------------------------------------------------------*/
int read_input( int* time,
                double* g_x, double* g_y, double* g_z,
                int* button_T, int* button_C, int* button_X, int* button_S,
                int* l_joy_x, int* l_joy_y, int* r_joy_x, int* r_joy_y );

/*-----------------------------------------------------------------------------
    PRE: ~(-1.0) <= mag <= ~(1.0)
    This function scales the roll/pitch value to fit on the screen.
    Input should be capped at either -1.0 or 1.0 before the rest of your
    conversion.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleMagForScreen(double rad);

/*-----------------------------------------------------------------------------
    PRE: -128 <= mag <= 127
    This function scales the joystick value to fit on the screen.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleJoyForScreen(int rad);

/*----------------------------------------------------------------------------
    PRE: -39 <= number <= 39
    Uses print_chars to graph a number from -39 to 39 on the screen.
    You may assume that the screen is 80 characters wide.
----------------------------------------------------------------------------*/
void graph_line(int number);

/*-----------------------------------------------------------------------------
    PRE: num >= 0
    This function prints the character "use" to the screen "num" times
    This function is the ONLY place printf is allowed to be used
    POST: nothing is returned, but "use" has been printed "num" times
-----------------------------------------------------------------------------*/
void print_chars(int num, char use);


/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
int main()
{
    double x, y, z;                     /* Values of x, y, and z axis*/
    int t;                              /* Variable to hold the time value */
    int b_Up, b_Down, b_Left, b_Right;  /* Variables to hold the button statuses */
    int j_LX, j_LY, j_RX, j_RY;         /* Variables to hold the joystick statuses */
    int scaled_pitch, scaled_roll; 	    /* Value of the roll/pitch adjusted to fit screen display */
    int scaled_joy;                     /* Value of joystick adjusted to fit screen display */
	int running;						//Keeps track of whether while loop should continue
	int whichGraph = 0;					//keeps track of what graph to run
    /* Put pre-loop preparation code here */

    do
    {
        /* Scan a line of input */
		running = !read_input( &t, &x, &y, &z, &b_Up, &b_Right, &b_Down, &b_Left, &j_LX, &j_LY, &j_RX, &j_RY);
	
        /* Calculate and scale for pitch AND roll AND joystick */
		scaled_roll = scaleMagForScreen(x);
		scaled_pitch = scaleMagForScreen(z);
		scaled_joy = scaleJoyForScreen(j_RX);
        /* Switch between roll, pitch, and joystick with the up, down, and right button, respectivly */
		
        /* Output your graph line */
		if(b_Up){
			whichGraph = 0;
		} else if(b_Down){
			whichGraph = 1;
		} else if(b_Right){
			whichGraph = 2;
		}
		if(whichGraph == 0){
			graph_line(scaled_roll);
		} else if(whichGraph == 1){
			graph_line(scaled_pitch);
		} else if(whichGraph == 2){
			graph_line(scaled_joy);
		}
        fflush(stdout);

    } while (running); /* Modify to stop when left button is pressed */

    return 0;

}
int read_input( int* time,
                double* g_x, double* g_y, double* g_z,
                int* button_T, int* button_C, int* button_X, int* button_S,
                int* l_joy_x, int* l_joy_y, int* r_joy_x, int* r_joy_y ){
	scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d", time, g_x, g_y, g_z, button_T, 
	button_C, button_X, button_S, l_joy_x, l_joy_y, r_joy_x,r_joy_y);
	return *button_S;
	}

int scaleMagForScreen(double rad){
	if(rad >= -1 && rad <= 1){
		return (int)(rad * 39);
	} else{
		return 0;
	}
}
int scaleJoyForScreen(int rad){
	double holder = (double)rad / 128.0;
	if(holder >= -1 && holder <= 1){
		return holder * 39;
	} else{
		return 0;
	}
}
void graph_line(int number){
	
	if(80 - number > 90){
		print_chars(40, ' ');
		print_chars(abs(number), 'R');
		print_chars(1, '\n');
	} else if(80 + number == 80 || 80 - number == 80){
		print_chars(39, ' ');
		print_chars(1, '0');
		print_chars(1, '\n');
	} else{
		print_chars(39 - number, ' ');
		print_chars(number, 'L');
		print_chars(1, '\n');
	}
}
void print_chars(int num, char use){
	
	for(int i = 0; i < num; i++){
		printf(" %c", use);
	}
	
}