/*----------------------------------------------------------------------------
-		         SE 185: Lab 05 - Conditionals (What's up?)	    	         -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
double magnitude(double x, double y, double z);
int orientation(double x,double y,double z);
int close_to(double tolerance,double point,double value);
int stop(int triButPressed);
int orientationChanged(char* curOrientation, char* lastOrientation);
/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab05.c -o lab05
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -a -g -b | ./lab05

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int triangle, circle, x_button, square;
    double ax, ay, az, gx, gy, gz;
	int running = 1;
	int curOrientation;
	int lastOrientation = 0;
    while (running)
    {
        scanf("%lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d",
              &ax, &ay, &az, &gx, &gy, &gz, &triangle, &circle, &x_button, &square);

        /* printf for observing values scanned in from ds4rd.exe,
         * be sure to comment or remove in final program */
		 
		 
        //printf("Echoing output: %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n",
        //       ax, ay, az, gx, gy, gz, triangle, circle, x_button, square);
			   
		
		
		curOrientation = orientation(gx,gy,gz);
		
		if(curOrientation != -1 && curOrientation != lastOrientation){
			if(curOrientation == 1){
				printf("Top\n");
				lastOrientation = curOrientation;
			} else if(curOrientation == 2){
				printf("Bottom\n");
				lastOrientation = curOrientation;
			} else if(curOrientation == 3){
				printf("Left\n");
				lastOrientation = curOrientation;
			} else if(curOrientation ==4){
				printf("Right\n");
				lastOrientation = curOrientation;
			} else if (curOrientation == 5){
				printf("Front\n");
				lastOrientation = curOrientation;
			} else if(curOrientation == 6){
				printf("Back\n");
				lastOrientation = curOrientation;
			}
		}
		/*
		if((strcmp(curOrientation,"") != 0)&&(strcmp(lastOrientation,"") != 0)){
		if(strcmp(curOrientation,lastOrientation) != 0){
		printf("%s\n", curOrientation);
		} 
		}*/
		
        /* It would be wise (mainly save time) if you copy your code to calculate
         * the magnitude from lab03-1.c. You will also need to copy your
         * prototypes and functions to the appropriate sections in this program. */
	
        //printf("The acceleration's current magnitude is: %lf\n", magnitude(ax, ay, az));
		running = stop(triangle);
    }
	
	
    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */
double magnitude(double x, double y, double z)
{
    // Step 8, uncomment and modify the next line
    return sqrt(pow(x,2) + pow(y,2) + pow(z,2) );
}
int close_to(double tolerance,double point,double value){
	if(fabs(value - point) <= tolerance){
		return 1;
	} else{
		return 0;
	}
}

int orientation(double x, double y, double z){
	if(close_to(.05,1,y)){
		return 1;
	} else if(close_to(.05,-1.0,y)){
		return 2;
	} else if(close_to(.05,1.0,x)){
		return 3;
	} else if(close_to(.05,-1.0,x)){
		return 4;
	} else if(close_to(.05,1.0,z)){
		return 5;
	} else if(close_to(.05,-1.0,z)){
		return 6;
		
	}
	else{
		return -1;
	}

}

int stop(int triButPressed){
	if(triButPressed == 1){
		return 0;
	} else {
		return 1;
	}
}

