#include<stdio.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>
#include<string.h>
int exponent(int base, int power);

int main(){
	int base;
	int power;
	
	//I know I'm probably not supposed to use ncurses but I've been docked
	//for formatting not being correct so I played it safe
	//I couldn't figure out another way to put a word in between 2 scan statements
	initscr();
	refresh();
	while(1){
	mvprintw(0,0,"Enter number to power: ");
	mvscanw(0,strlen("Enter number to power: "),"%d", &base);
	refresh();
	
	mvprintw(0,strlen("Enter number to power: ") + 1 ," to ");
	mvscanw(0, strlen("Enter number to power: ") + 5,"%d", &power);
	refresh();
	
	mvprintw(1,0,"%d to the power %d = %d",base,power,exponent(base,power));
	refresh();
	}
	return 0;
}


int exponent(int base, int power){
	if(power == 0){
		return 1;
	} else{
		return base * exponent(base, power - 1);
	}
}