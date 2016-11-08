//Alan Birmaher
//COP 3223-0002
//Assignment #3
//2/20/12
//Purpose: Keep track of food in a foodbank. When donations are made as well as requests keep track.
//Also fill those requests from the inventory.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	
	//Instantiates variables and arrays
	int choice=0, found, i, don_count=0, req_count=0, don_quant, req_quant;
	char don_inv_type[100][21];
	char req_inv_type[100][21];
	int don_amt[100];
	int req_amt[100];
	int word[21];
	
	//Starts while loop for our menu
	while(choice != 5){
	//Prints out menu options
	printf("***********************************\n");
	printf("* Welcome to the Food Bank Program*\n");
	printf("* 1. Add a donation               *\n");
	printf("* 2. Add a request                *\n");
	printf("* 3. Fulfill a request            *\n");
	printf("* 4. Print status report          *\n");
	printf("* 5. Exit                         *\n");
	printf("***********************************\n");
	
	//Prompts user for choice
	printf("Enter your choice: ");
	scanf("%d", &choice);
	printf("\n");
	
        //If user selects option 1
		if (choice ==1){
			
			//prompt for word, don_quant
			printf("What are you donating? ");
			scanf("%s", &word);
			printf("\n");
			printf("How much %s are you donating? ", word);
			scanf ("%d",  &don_quant);
			printf("\n");
			
			//Sets found to -99
			found = -99;
			
			//Loops through list of donations
			for (i=0;i<don_count; i++)
				{
					//Compares the whole list to what is bring inputed
					if (strcmp(don_inv_type[i], word)==0)
     					//Changes the value of found to i if it finds it
						found = i;
				} // end-for
			
			//If the new donation isnt already in the foodbank do this
			if (found == -99)
				{
					//Sets the name of whats donated in the array and its value
					strcpy(don_inv_type[i],word);
					don_amt[i] = don_quant;
					don_count ++;
				} // end-if-found
				
			
			else //Adds the amount to what is in the food bank
    			don_amt[found] += don_quant;

			printf("Donation Added\n");
				
			system("pause");
		}
	
        //If user selects option 2	
		else if (choice == 2) {
		
			//prompt for word, req_quant
			printf("What are you requesting? ");
			scanf("%s", &word);
			printf("\n");
			printf("How much %s are you requesting? ", word);
			scanf ("%d",  &req_quant);
			printf("\n");
			
			//Save values into the list of requests
			strcpy(req_inv_type[req_count],word);
			req_amt[req_count]=req_quant;
			
			//Keeps track of how many requests are made
			req_count++;
			
			printf("Request Added\n");
			
			system("pause");
				
		}

        //If user selects option 3	
		else if (choice==3){
			
			//If no requests have been made
    		if (req_count == 0){ 
					printf("Nobody needs food.\n");
      			}
    		
    		//If no donations have been made
            else if (don_count == 0){ 
					printf("Nobody has donated.\n");
           		}
			
            // Search for donations in inventory
            else {	
				found = -99;
				
                
                //Search through all of the inventory to find requested item
                for (i=0; i<don_count; i++)
   					{
     					//Compares items to reuquest to find a match
                         if ( strcmp(don_inv_type[i],req_inv_type[0]) == 0)
							//If found save the place in the array where it is
                            found = i;
  					}
				
                //If it isnt found then print this
                if (found == -99)
   					{
						printf("No match for one or more requests in donations. \nSystem will now stall until a donation is made.\n");
                	}
             	
                 //If it is found, calculate if its equal or which is more the donation or request
                 else{
                    
                    //If the request is equal to the inventory amount
                    if (don_amt[found]==req_amt[0])
					{
   						printf("Request will be satisfied.\n");
     						//  need to delete the request by moving all the others up by 1 pos
						for (i=1;i<req_count;i++)
  							{
                            	strcpy(req_inv_type[i-1], req_inv_type[i]);
								// copy the lower value into a higher position
								req_amt[i-1] = req_amt[i];
							}
    					req_count -- ;  //we just lost an entry, so lower the counter
      									// now, need to delete the donation, as well
    					for (i=found;i<(don_count - 1);i++)
      						{
         						strcpy(don_inv_type[i], don_inv_type[i+1]);
         						don_amt[i]= don_amt[i+1];
      						}
    					//Reduces the count of donations
                        don_count -- ;
  					}
				
                //If there is more inventory than the requested amount
                else if (don_amt[found]>req_amt[0])
       				{
                        printf("Request will be satisfied.\n");
          				don_amt[found] -= req_amt[0];  //reduce the donation table's amt
                                                       //remove the request as above
          				
                          //Go through and remove the request after it has been filled
                          for (i=1;i<req_count;i++)
							{
								strcpy(req_inv_type[i-1], req_inv_type[i]);
								// copy the lower value into a higher position
								req_amt[i-1] = req_amt[i];
							}
							
					//Reduces the request count		
					req_count -- ;
					}

			//If the requests exceed the inventory, partially fill it
            else { // need to  remove donation and reduce request
                printf("Request will be parially satisfied.\n");
                
                
                //Request is partially filled and remainder is saved
                req_amt[0] -= don_amt[found];
				for (i=found;i<don_count - 1;i++)
					{
						strcpy(don_inv_type[i], don_inv_type[i+1]);
						don_amt[i]= don_amt[i+1];
					}
				
                //Decrease count of donations
                don_count -- ;
					}
				}
				}
				
				printf("\n");
			}

        //If user selects option 4	
		else if (choice == 4) {
		
			printf("Inventory:\n");
		
			//Prints what you have in stored
			for(i=0; i<don_count; i++){
				printf("%s %d\n", don_inv_type[i], don_amt[i]);
				}
			
			printf("\n");
			
			printf("Requests:\n");
	
			//prints the requests
			for(i=0; i<req_count; i++){
				printf("%s %d\n", req_inv_type[i], req_amt[i]);
				}
			
			//Pauses to keep the information on the screen
			system("pause");
			printf("\n");
		
		}

        //If user selects option 5	
		else if (choice == 5) {
			printf("Thank You for using the software. Bye for now.\n");
			system ("pause");
			}
		
        //If user selects invalid option
		else {
			printf("Invalid selection. Please enter a new option.\n");
			system ("pause");
			}

	}
}
