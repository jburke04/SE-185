#include<stdio.h>
#include<math.h>
#include<string.h>

int main(void){

//defining necessary variables
char first[50];
char last[50];
char major[50];
char year[50];
int gradYear;

//ask for user input in the format given

printf("Enter your first name: ");
scanf("%s", &first);
printf("Enter the last name: ");
scanf("%s", &last);
printf("Enter your major: ");
scanf("%s", &major);
printf("Enter year in college (ex. Freshman, sophmore, etc.): ");
scanf("%s", &year);
printf("Enter your graduation year: ");
scanf("%d", &gradYear);

//prints user input in the given format
printf("\nName (last,First): Name (%s, %s)\n",last,first);
printf("Major: %s\n",major);
printf("Year: %s\n", year);
printf("Graduation year: %d\n", gradYear);

return 0;
}