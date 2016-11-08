//Alan Birmaher
//COP 3223-0002
//Assignment #1 Problem D
//1/12/12
//Purpose: To calculate which of the two states you would need in order to win
//the election as well as how many combinations your candidate can win with as many
//times as the user specifies.

#include <stdio.h>
#include <stdlib.h>

//Defines the number of minimum votes needed to win
#define MIN_VOTES 270

int main(void){

    //Instantiate variables
	int howmany, run, won, evotes1, evotes2, op1, op2, op3, ways;
	char state1 [25], state2 [25];
	
	//Ask user how many times they would like the program to run
	printf("How many times do you wish to run the program?\n");
	scanf("%d", &howmany);
	
	//Start the loop in which the program runs the specified number of times
	for (run = 0; run < howmany; run++)
	{
		
		//Print the number of the current run
		printf("\n");
		printf("This is run %d\n", run+1);
		printf("**************\n");
		
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
		printf("Your candidate can win in %d number of ways.\n", ways);
			
	}
	
	//Keep output on screen
	system("pause");

	return 0;
	
}
	
