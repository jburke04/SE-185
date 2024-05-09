#include<stdio.h>
#include<math.h>

int main(void){
	
//creating a really simple function so that I don't have to retype the distance formula
double distance(double x1,double x2,double y1,double y2){
double result;
result = sqrt(pow(x2-x1,2)+pow(y2-y1,2));

return result;
}

//defining all the necessary variable
double dist;
double mikeX = 22.05;
double mikeY = 85.10;
double maryX = 43.25;
double maryY = 9.80;
double garyX = 2.55;
double garyY = 72.86;
double loganX = 15.15;
double loganY = 40.40;
double schoolX = 15.55;
double schoolY = 55.15;

//printing all the calculated values with the right format
printf("The E distance for Mike is: %lf\n",distance(mikeX,schoolX,mikeY,schoolY));
printf("The E distance for Mary is: %lf\n",distance(maryX,schoolX,maryY,schoolY));
printf("The E distance for Gary is: %lf\n",distance(garyX,schoolX,garyY,schoolY));
printf("The E distance for Logan is: %lf\n",distance(loganX,schoolX,loganY,schoolY));
return 0;
}