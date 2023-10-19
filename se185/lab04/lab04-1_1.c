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
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab04-1_1.c -o lab04-1_1
// Run with ./lab04-1_1
/* This program outputs if a integer will divide into another integer with no remainder. */

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int i, j;

    //printf("Enter an integer: ")
	//missing semicolon
	printf("Enter an integer: ");
    scanf("%d", &i);

    //printf("Enter another integer: );
	//missing "
	printf("Enter another integer: ");
	//missing semicolon
    //scanf("%d", &j)
	scanf("%d", &j);

    if (j % i == 0)
    {
        printf("%d divides %d\n", i, j);

    } //else
		//missing bracket
	else {

        //pritf("%d does not divide %d\n", i, j);
		//spelled printf wrong
		printf("%d does not divide %d\n", i, j);
        printf("%d %% %d is %d\n", j, i, (j % i));
    }

    return 0;
}
