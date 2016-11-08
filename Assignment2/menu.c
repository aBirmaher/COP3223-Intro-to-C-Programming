//Alan Birmaher
//COP 3223-0002
//Assignment #2 Problem D
//2/10/12
//Purpose: Makes a menu so that the user can select which of the 3 programs from this
//assignment to run. It also gives the user the ability to exit the program as well.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FIRST_CAR_LENGTH 10
#define NORMAL_CAR_LENGTH 8
#define CAR_CAPACITY 4

int main(){
	
	//Varables for programs
	int train, people, train_calc, train_final, track, n, 
	total_trains, people_total, track_in, train_surplus, i,
	state_in, most_vote, average, difference, sum, test_train, 
	max_train, track_total, useable_track, trains_on_track, 
	people_per_train, total_people, total_train_lengths, 
	max_people, cars_needed, input;
	
	char state_name [50], most_name [50];
	
	double calculation, ratio[50], sum_ratio, final_ratio;
	
	//Starts loop to run programs until exit clause is met
	do {
	
	//Offers user choices for what to do and asks them to choose one
	printf("Select one of the following choices, to run the program and then press enter: \n");
	printf("1) Run coaster.c\n");
	printf("2) Run stateslargest.c\n");
	printf("3) Run coaster2.c\n");
	printf("4) To exit the program\n");
	printf("My choice is: ");
	scanf("%d", &input);
	printf("\n");
	printf("--------------------------------------------------------------------------");
	printf("\n");
	
	//If user specifies option 1
	if (input == 1) {
		
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
			
			printf("--------------------------------------------------------------------------\n");			
			
			system("pause");

		
	}
	
	//If user specifies option 2
	else if (input == 2) {
		
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
		
	        printf("--------------------------------------------------------------------------\n");
		
	        system("pause");
		
	}
	
	//If user specifies option 3
	else if (input == 3) {
         
         //Ask user for track length
	     printf("What is the total length of the track, in feet?\n");
	     scanf("%d", &track_total);	

	     //Calculate the amount of track that can be occupied by trains
	     useable_track= track_total / 4;
	
	     //Ask user for the maximum length of a train
	     printf("What is the maximum length of a train, in feet?\n");
	     scanf("%d", &max_train);
	
	     i=0;
	     max_people=0;
	     sum_ratio=0;
	
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
		
	printf("--------------------------------------------------------------------------\n");
		    
    system("pause");	    
		
	}
	
	//If user specifies option 4
	else if (input == 4) {
		
		printf("END\n");
		
	}
	
	
	//If user enters an invalid choice
	else
	printf("Invalid entry, try again!\n");
	printf("--------------------------------------------------------------------------\n");
	printf("\n");

	} while (input != 4);	
	
	system ("pause");
					
	return 0;

}
