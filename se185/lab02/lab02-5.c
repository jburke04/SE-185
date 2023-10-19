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
#include <math.h>   // Google this header file to learn more! :)

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    double a, b, c;
    double filler;

    /* Put your code after this line */
	printf("Please input a value for a ");
	scanf("%lf", &a);
	printf("Please input a value for b ");
	scanf("%lf", &b);
	
    /* This next line will calculate the square root of whatever value is
     * inside the parenthesis and assigns it to the variable filler. */
    filler = sqrt(pow(a,2) + pow(b,2));
	c = filler;
	printf("C is equal to %lf\n",c);

    return 0;
}
