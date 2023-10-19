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

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int integer_result;
    double decimal_result;

    integer_result = 77 / 5;
	//the printf below is using %lf instead of %d 
    printf("The value of 77/5 is %d, using integer math.\n", integer_result);
	
    integer_result = 2 + 3;
	//the printf below does not have a second parameter for the %d
    printf("The value of 2+3 is %d.\n", integer_result);

    decimal_result = 1.0 / 22.0;
	//the printf below is using &d instead of %lf
    printf("The value 1.0/22.0 is %lf.\n", decimal_result);

    return 0;
}
