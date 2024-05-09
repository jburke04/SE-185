#include<stdio.h>
#include<math.h>
#include<string.h>

int main(void){
double DrivingCost(double drivenMiles,double milesPerGallon,double dollarsPerGallon){
	double gallonsUsed = drivenMiles / milesPerGallon;
	double dollarsUsed = gallonsUsed * dollarsPerGallon;
	
	return dollarsUsed;
}
double drivenMiles;
double milesPerGallon;
double dollarsPerGallon;

printf("\nEnter driven Miles:");
scanf("%lf",&drivenMiles);
printf("\nEnter Miles per Gallon:");
scanf("%lf",&milesPerGallon);
printf("\nEnter dollars per Gallon:");
scanf("%lf",&dollarsPerGallon);
printf("\nDriving cost= %.2lf",DrivingCost(drivenMiles,milesPerGallon,dollarsPerGallon));

return 0;
}