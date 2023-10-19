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
#include <math.h>

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab04-1_4.c -o lab04-1_4
// Run with ./lab04-1_4
/* This program calculates the energy of one photon
 * of user-inputted wave-length of light */

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    //double speed_of_light!;
	//shouldnt have exclamation point
	double speed_of_light;
    //double wave-length;
	//shouldnt have a hyphen
	double wave_length;
    //double ~length_in_meters;
	//shouldnt have a tilda
	double length_in_meters;
    //double plank const;
	//const should be before plank not after, also should have the definition of what it is
	double const plank = 6.62606957 * pow(10, -34);  // Planck's constant
    //double 0energy;
	//variable declaration shouldnt begin with a number
	double zeroEnergy;

    //plank const = 6.62606957 * pow(10, -34); 
	//cant redefine a constant
	
    //speed_of_light! = 2.99792458 * pow(10, 8);
	//again, variable shouldnt have an exclamation point
	speed_of_light = 2.99792458 * pow(10, 8);
    //wave-length = 0;
	//shouldnt have a hyphen
	wave_length = 0;
    //~length_in_meters = 0;
	//shouldnt have a tilda
	length_in_meters = 0;
    //0energy = 0;
	//variable name shouldnt begin with a number
	zeroEnergy = 0;

    printf("Welcome! This program will give the energy, in Joules,\n");
    printf("of 1 photon with a certain wave-length.\n");
    printf("Please input a wave-length of light in nano-meters.\n");
    printf("Please do not enter a negative, or zero, wave-length.\n");

    //scanf("%lf", &wave-length);
	//wave-length should be wave_length
	scanf("%lf", &wave_length);

    //if (wave-length > 0.0)
	//wave-length should be wave_length
	if (wave_length > 0.0)
    {
        //~length_in_meters = wave-length / pow(10, 9);
		//uneccesary tildaa and hyphen in variable names
		length_in_meters = wave_length / pow(10, 9); // Converting nano-meters to meters
        //0energy = (plank const * speed_of_light!) / ~length_in_meters; 
		//wrong variable names as well as uneccesary use of const
		zeroEnergy = (plank * speed_of_light) / length_in_meters; // Calculating the energy of 1 photon
        printf("A photon with a wave-length of %08.3lf nano-meters, carries "
        //       "\napproximately %030.25lf joules of energy.", wave-length, 0energy);
		//wrong variable names
		         "\napproximately %030.25lf joules of energy.", wave_length, zeroEnergy);
    } else
    {
        printf("Sorry, you put in an invalid number.");
        printf("Please rerun the program and try again.");
    }

    return 0;
}
