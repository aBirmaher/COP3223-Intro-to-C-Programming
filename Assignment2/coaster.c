//Alan Birmaher
//COP 3223-0002
//Assignment #2 Problem A
//1/27/12
//Purpose: Calculates the maximum amount of people that can ride your coaster 
//at once within the user entered parameters and reports a surplus of feer of 
//train. It does this as many times as the user tells it to.

#include <stdio.h>
#include <stdlib.h>

#define FIRST_CAR_LENGTH 10
#define NORMAL_CAR_LENGTH 8
#define CAR_CAPACITY 4

int main (){

	//Instantiating Variables
	int train, people, train_calc, train_final, track, n, 
	total_trains, people_total, track_in, train_surplus, i;
	
	// Ask the user how many times he wants the program to execute
	printf("What is the value for N?\n");
	scanf("%d", &n);
	printf("\n");
	
	//Start loop in order to run the program the correct number of times
	for (i=1; i<= n; i++){
	
		//Ask user for track length
		printf("What is the total length of the track, in feet?\n");
		scanf("%d", &track_in);	

		//Calculate the amount of track that can be occupied by trains
		track= track_in / 4;
	
		//Ask user for the maximum length of a train
		printf("What is the maximum length of a train, in feet?\n");
		scanf("%d", &train);
		
		//Find how many trains there will be other than the first car
		train_calc = (train-10)/8;
	
		//Find the surplus of train length
		train_surplus = (train-10) % 8;
	
		//Calculates the amount of people per train
		people = (1 + train_calc)*CAR_CAPACITY;
	
		//Finding the actual length of each car
		train_final = (10+ (train_calc * NORMAL_CAR_LENGTH));
	
		//Finds how many trains can be out on the track at once
		total_trains = track / train_final;
	
		//Finds the total amount of people out on the track at once
		people_total = total_trains * people;
	
		//Prints out the amount of people that are out on the track at once
		printf("Your ride can have at most %d people on it at one time.\n", people_total);
	
		/*Tells you if there was a surplus of train that was entered in 
		feet and if so tells you what it was */
		if (train_surplus == 0)
			printf("Maximum length fits exactly.\n");
		else	
			printf("Maximum train length has surplus of %d feet.\n", train_surplus);
		
		//Skip line
		printf("\n");
		
	}
	
	system ("pause");
					
	return 0;
}
