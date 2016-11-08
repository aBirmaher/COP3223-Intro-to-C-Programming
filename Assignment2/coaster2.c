//Alan Birmaher
//COP 3223-0002
//Assignment #2 Problem C
//2/5/12
//Purpose: 

#include <stdio.h>
#include <stdlib.h>

#define FIRST_CAR_LENGTH 10
#define NORMAL_CAR_LENGTH 8
#define CAR_CAPACITY 4

int main (){
	
	//Instantiating Variables
	int test_train, max_train, track_total, useable_track, trains_on_track,
	people_per_train, i, total_people, total_train_lengths, max_people,
	cars_needed, n;
	
	double calculation, ratio[50], sum_ratio, final_ratio;
	
	//Ask user for track length
	printf("What is the total length of the track, in feet?\n");
	scanf("%d", &track_total);	

	//Calculate the amount of track that can be occupied by trains
	useable_track= track_total / 4;
	
	//Ask user for the maximum length of a train
	printf("What is the maximum length of a train, in feet?\n");
	scanf("%d", &max_train);
	
	//Setting Values
	i=0;
	max_people=0;
	sum_ratio=0;
	
	//Loop to test different train lengths
	for (test_train=10; test_train<= max_train; test_train += 8){
		
		//Find how many people fit in each train
		people_per_train = (test_train / NORMAL_CAR_LENGTH) * CAR_CAPACITY;
		
		//Find how many cars of this length fit on the track at once
		trains_on_track = useable_track/test_train;

		//Find how many people would be on the track at any one time
		total_people = (people_per_train*trains_on_track);
		
		//Finds total length of all trains on track
		total_train_lengths = trains_on_track * test_train;
		
		//Calculates our ratio
		calculation = (1.0*total_people)/total_train_lengths;
		
		//Stores the value in our ratio array
		ratio[i]= calculation;
		
		//Moves to the next space in the array for the next time the for loop is done
		i++;
		
        // Replaces the value of the max people with the new value if it 
        //is enountered. In the loop, the number of people and length of 
        //trains on the track are calculated.
		if(total_people > max_people){
                        
			max_people= total_people;
			cars_needed = test_train/NORMAL_CAR_LENGTH;
			
		}
	}
	
	//Prints the results of the most people on the track at once and the minimum
	//number of cars with which this can be acheieved.
	printf("Your ride can have at most %d people on it at one time.\n", max_people);
	printf("This can be acheieved with trains of %d cars.\n\n", cars_needed);
	
	//Adds together all values in the array
    for(n=0; n<=(i-1);n++){
		
		sum_ratio += ratio[n];
		
	}
	
	//Calculates the final ratio
	final_ratio = sum_ratio / (n);
	
	//Prints out the averag ratio
	printf("AVG Ratio: %.3lf\n", final_ratio);
	
	system("pause");
	
	return 0;
	
}
