//Alan Birmaher
//COP 3223-0002
//Assignment #2 Problem B
//2/1/12
//Purpose: Calculates which state is the biggest in terms of electoral
//votes. Then it computes the difference between the worth of that state
//and the average of all the other states put together.

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main (){
	
	//Instantiating Variables
	int state_in, n, i, most_vote, average, difference;
	int sum = 0;
	char state_name [50], most_name [50];
	
	//Asks user for how many states are being entered
	printf("How many states are you entering?\n");
	scanf("%d", &n);
	
	//Starts a for loop for the user to enter the states and amount of votes
	//and to calculate which state is the largest.
	for (i=1; i<=n; i++){
		
		//Asks user for name of state and amount of votes
		printf("Enter the name and electoral votes for state %d:\n", i);
		scanf("%s %d", &state_name, &state_in);
		
		//Adds the amount of electoral votes toegther
		sum += state_in;
		
		//When the loop runs the first time the first value is set as the current maximum
		if (i==1){
			most_vote = state_in;
			}
		
		//If the state entered is bigger than the current leader it is saved as the biggest	
		if(state_in >= most_vote){
			most_vote = state_in;
			strcpy (most_name, state_name);
		}
		
	}
	
    //Subtracts the number of winning votes from the sum to compute the average of
	//the other values that are not highest
	sum -= most_vote;
	
	//Computes the average of all the states except the winner
	average = sum / (n-1);
	
	//Computes the difference between the biggest state and the rest
	difference = most_vote - average;
	
	//Prints blank line
	printf("\n");
	
	//Prints the response
	printf("Response:\n");
	printf("%s with %d is the largest. It exceeds the others' \naverage by %d.\n", 
    most_name, most_vote, difference);
	
	system("pause");

	return 0;
	
}

