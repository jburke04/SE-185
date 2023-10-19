/*----------------------------------------------------------------------------
-		                 SE 185: Lab 04 - Debugging Code	    	         -
-	Name:Jaden Burke														 -
- 	Section:2																 -
-	NetID:jadenb04														     -
-	Date:9/20/2022															 -
-----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
int sum_function(int number);

int main();

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab04-1_5.c -o lab04-1_5
// Run with ./lab04-1_5
/* This program calculates the sum of 1 to x, where x is a user input */

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int input;

    //printf("Please input a number from to sum up to: ");
	//should have from 1 to x to sum up to just for nicer readability
	printf("Please input a number from 1 to x to sum up to: ");
	
    scanf("%d", &input);

    printf("The sum of 1 to %d is %d\n", input, sum_function(input));

    return 0;
}
/*
int main(int argc, char *argv[])
{
    printf("Sum is 32!\n");
}
*/
//second definition of main
/**
 * Calculates the sum of 1 to number of a given number.
 *
 * @param number - The number that determines what the sum will stop adding at.
 * @return - The sum of 1 to the given number.
 */
int sum_function(int number)
{
    return (number * (number + 1)) / 2;
}
