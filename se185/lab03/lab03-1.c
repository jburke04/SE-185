/*----------------------------------------------------------------------------
-		    SE 185: Lab 03 - Introduction to the DS4 and Functions	    	 -
-	Name:Jaden Burke														 -
- 	Section:2																 -
-	NetID:jadenb04														     -
-	Date:9/13/2022															 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
double magnitude(double x, double y, double z);
int minutes(int time);
int seconds(int time1);
int milliseconds(int time2);
/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab03-1.c -o lab03-1
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -a | ./lab03-1

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int t;
    double ax, ay, az;

    while (1)
    {
        scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);

        /* CODE SECTION 0 */
        printf("Echoing output: %08.4lf, %07.3lf, %07.3lf, %07.3lf\n", (double)((t/1000) % 60) +(double)((t % 1000)) / 1000 , ax, ay, az);


        /* 	CODE SECTION 1 */
         printf("At %d ms, the acceleration's magnitude was: %lf\n", t, magnitude(ax, ay, az));


        /* 	CODE SECTION 2 */
			
            printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n",
            minutes(t), seconds(t), milliseconds(t), magnitude(ax, ay, az));
        
    }

    return 0;
}

/* Put your functions here */
int minutes(int time){
	
	return (time/60000) %60;
}

int seconds(int time1){
	
	return (time1/1000) %60;
}

int milliseconds(int time2){
	
	return (time2 % 1000); 
}
/**
 * Calculates and returns the magnitude of three given values.
 *
 * @param x - The x-axis scanned values from the DS4 controller.
 * @param y - The y-axis scanned values from the DS4 controller.
 * @param z - The z-axis scanned values from the DS4 controller.
 * @return - The magnitude of the given values.
 */
double magnitude(double x, double y, double z)
{
    // Step 8, uncomment and modify the next line
    return sqrt(pow(x,2) + pow(y,2) + pow(z,2) );
}

