/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name:Jaden Burke														 -
- 	Section:2																 -
-	NetID:jadenb04														     -
-	Date:9/6/2022															 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    /* Put your code after this line */
	int x, y, z;
	printf("Enter a width: ");
	scanf("%d", &x);
	printf("Enter a height: ");
	scanf("%d", &y);
	printf("A %d by %d rectangular cube's volume is %d\n", x, y, x*y);
	
    return 0;
}
