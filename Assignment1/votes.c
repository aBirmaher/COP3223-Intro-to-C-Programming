//Alan Birmaher
//COP 3223-0002
//Assignment #1 Problem A
//1/12/12
//Purpose: Calculate the seats the state gets in the House of reps by population
//as well as with the new possible amound of seats in the house.

#include <stdio.h>
#include <stdlib.h>

//Define constant for the population (in thousands)
#define US_POPULATION 309000

int main(void){

    //Create variables
	int statepop, statepopconv, seats, seatsamend;
	
	//State population input
	printf("What is the population of your state?  \n");
	scanf("%d", &statepop);
	
	//Convert user input to thousands from millions
	statepopconv = statepop / 1000;
	
	//Calculate amount of seats that the state curently has
	seats = (statepopconv*435)/US_POPULATION;
	seats += 2;
	
	//Calculate the amount of seats that the state could have with the amendment
	seatsamend = (statepopconv*601)/US_POPULATION;
	seatsamend += 2;
	
	//Output
	printf("Your state gets %d electoral votes.", seats); 
	printf("The amended number is %d.\n", seatsamend);
	
	//Keep information on screen
	system("pause");
	
	return 0;
}
