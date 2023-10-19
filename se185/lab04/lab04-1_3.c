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
#include <time.h>
//stdio h and stdlib are not included
#include<stdio.h>
#include<stdlib.h>
/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/

void hoo();
//print_face is not defined as a prototype function
void print_face(int selection);
/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
/* This is a simple program that takes a user inputs
 * and prints out a message based on that input */
// Compile with gcc lab04-1_3.c -o lab04-1_3
// Run with ./lab04-1_3

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    srand(time(NULL));

    int selection = 0;

    printf("Enter 1 for happy, 2 for sad, 3 for neutral, any other integer for random: ");
    scanf("%d", &selection);

    if (selection < 1 || selection > 3)
    {
        selection = rand() % 4;
    }
	
    print_face(selection);

    return 0;
}

/**
 * Prints a funny face.
 *
 * @param selection - The inputted value which determines which face to print.
 */
void print_face(int selection)
{
    if (selection == 1)
    {
        printf("Have a nice day! :) \n");
    } else if (selection == 2)
    {
        printf(":(\n");
    } else if (selection == 3)
    {
        printf("Meh :\\ \n");
    } else
    {
        hoo();
    }
}

/**
 * Prints an owl face.
 */
void hoo()
{
    printf(" *___*\n {O,O}\n/)___)\n_\"__\"_\n");
}
