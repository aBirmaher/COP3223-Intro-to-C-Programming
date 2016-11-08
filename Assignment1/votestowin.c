//Alan Birmaher
//COP 3223-0002
//Assignment #1 Problem B
//1/13/12
//Purpose: Tells user what percent of remaining electoral votes are needed
//to win the campaign.

#include <stdio.h>
#include <stdlib.h>

int main() {
	
	//Instantiating variables
    double allvotes = 538;
	double ihave, hehas, need, remain, required;
	
	//Prompt user for number of secured votes
	printf("How many electoral votes does your candidate have already?\n");
	scanf("%lf", &ihave);
	
	//Prompt user for number of unsecured votes
	printf("How many electoral votes does your opponent have already?\n");
	scanf("%lf", &hehas);
	
	//Calculations
	need = 270 - ihave;
	remain = 538 - (ihave + hehas);
	required = (need/remain)*100;
	
	//Percentage needed to win
	printf("%.2lf percent of the remaining vote is needed to win!\n", required);
	
	
	//Prints statment depending on the percentage of votes needed
	if ( required < 50.00 )
	    printf("This should be easy.\n");
	else 
	{
	    printf("An uphill battle.\n");
	}

	//Keep output on screen
	system("pause");

	return 0;
}
