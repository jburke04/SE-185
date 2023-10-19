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
int main(void)
{
    int a = 6427 + 1725;
	int b = (6971 * 3925) - 95;
	double c = 79 + 12/5;
	double d = 3640.0 / 107.9;
	int e = (22/3) * 3;
	int f = 22 / (3 * 3);
	double g = 22/(3 * 3);
	double h = 22 / 3 * 3;
	double i= (22.0 / 3) * 3.0;
	int j = 22.0 / (3 * 3.0);
	double k = 22.0 / 3.0 * 3.0;
	printf("Problem a = %d\n",a);
	printf("Problem b = %d\n",b);
	printf("Problem c = %0.2lf\n",c);
	printf("Problem d = %0.2lf\n",d);
	printf("Problem e = %d\n",e);
	printf("Problem f = %d\n",f);
	printf("Problem g = %0.2lf\n",g);
	printf("Problem h = %0.2lf\n",h);
	printf("Problem i = %0.2lf\n",i);
	printf("Problem j = %d\n",j);
	printf("Problem k = %0.2lf\n",k);
	
	//circumference problem
	double circumference = 23.567;
	//circumference formula is 2PIr so radius is circumference / 2PI
	double radius = 23.567 / (M_PI * 2);
	//area for a circle is pi r^2
	double area = M_PI * pow(radius,2);
	printf("The area of a circle with circumference %lf is %lf\n",circumference,area);
	
	//meter problem
	int feet = 14;
	//1 foot is .3048 meters
	double meters = feet * .3048;
	printf("%d feet is %lf meters\n",feet,meters);
	
	//Fahrenheit problem
	int F = 76;
	//Celsius = (Fahrenheit - 32) / 1.8
	double C = (F - 32) / 1.8;
	printf("%d Fahrenheit is %lf Celsius",F,C);
	
    return 0;
}
