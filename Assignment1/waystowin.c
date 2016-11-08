//Alan Birmaher
//COP 3223-0002
//Assignment #1 Problem C
//1/12/12
//Purpose: To calculate which of the two states you would need in order to win
//the election as well as how many combinations your candidate can win with.

#include <stdio.h>
#include <stdlib.h>

//Defines the minimum number of votes needed to win
#define MIN_VOTES 270

int main(void){

    //Instantiates Variables
	int won, evotes1, evotes2, op1, op2, op3, ways;
	char state1 [25], state2 [25];
	
	//Collect number of votes already won
	printf("How many electroal votes has your candidate won?\n");
	scanf("%d", &won);
	
	//Collect State 1 Information
	printf("What is the name of the first state in contention?\n");
	scanf("%s", &state1);
	printf("How many electroal votes does it have?\n");
	scanf("%d", &evotes1);
	
	//Collect State 2 Information
	printf("What is the name of the second state in contention?\n");
	scanf("%s", &state2);
	printf("How many electoral votes does it have?\n");
	scanf("%d", &evotes2);
	
	//States needed to win
	if (won+evotes1 >= MIN_VOTES) {
		printf("Your candidate wins if he/she wins %s.\n", state1);
		op1 = 1;
	}
	else {
		op1 = 0;
	}
	
	if (won+evotes2 >= MIN_VOTES) {
		printf("Your candidate wins if he/she wins %s.\n", state2);
		op2 = 1;
	}
	else {
		op2 = 0;
	}
	
	if (won+evotes1+evotes2 >= MIN_VOTES) {
		printf("Your candidate wins if he/she wins %s and %s.\n", state1, state2);
		op3 = 1;
	}
	else {
		op3 = 0;
	}
	
	//Calculate how many ways candidate can win
	ways= op1+op2+op3;
	
	//Print how many ways you can win
	printf("Your candidate can win in %d number of way/s.\n", ways);
	
	//Keep output on screen
	system("pause");

	return 0;
	
}
