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
int buttonsPressed(int b1,int b2, int b3, int b4);

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab03-2.c -o lab03-2
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -b | ./lab03-2

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	int t,s,x,c;
    while (1)
    {
	scanf("%d, %d, %d, %d", &t, &c, &x, &s);
	printf("There are %d buttons being pressed\n", buttonsPressed(t,c,x,s));
    }

    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */
int buttonsPressed(int b1,int b2, int b3, int b4){
	return b1 + b2 + b3 + b4;
	
	
}