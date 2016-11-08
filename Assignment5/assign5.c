//Alan Birmaher
//COP 3223-0002
//Assignment #5
//4/16/12
//Purpose: This program to be used to pull in a file fiving names of employees, their pay per hour rate
//and their hours for a number of weeks. Then the program computes their gross pay, taxes withheld and
//the net pay that they recieve in an output file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 30
#define MAX_EMP 20

//Function to calculate net pay
double calc(double a, double b);

//Main Function
int main(){
    
    //Instantiate variables
    FILE* IFP;
    FILE* OFP;
    int n = 0, i = 0, k = 0, m = 0, p = 0, j = 0, s = 0, c = 0, r = 0, d = 0, u = 0, t = 0, g = 0;
    double hr_in=0, min_in=0, hr_out=0, min_out=0, mins=0, minutes_out=0, minutes_in=0, pay1=0, pay2=0, net_pay=0;
    char first[MAX_LEN], last[MAX_LEN], last_chk[MAX_LEN], first_chk[MAX_LEN]; 
     
    //Initiate struct
    struct employee{
             char first[MAX_LEN];
             char last[MAX_LEN];
             double payprhr;
             double gross;
             double taxes;
             double hours_in_week;
    };
    
    //Open input and output files
    IFP=fopen("clock.txt","r");
    OFP=fopen("w2.txt","w");
    
    //Reads in number of employees  
    fscanf(IFP,"%d", &n);
    
    //Create structure array of employees    
    struct employee emp[n]; 

    //Set numerical parts of structs to zero
    for(i = 0; i < n; i++) {
          emp[i].payprhr = 0;
          emp[i].gross = 0;
          emp[i].taxes = 0;
          emp[i].hours_in_week = 0;
    }

    //Loop creating structs for the employees
    for(i=0;i<n;i++){
         fscanf(IFP, "%s", emp[i].first);
         fscanf(IFP, "%s", emp[i].last);
         fscanf(IFP, "%lf",&emp[i].payprhr);                        
    }
    
    //How many weeks of info to import
    fscanf(IFP, "%d", &k);
    
    //Loop to import the given number of weeks
    for(p=0;p<k;p++){
                     
         //How many peices of info for the week
         fscanf(IFP,"%d", &m); 
         
         //Loop to import the info for the given week
         for(j=0;j<m;j++){ 
                
                //Grab all info from the line
                fscanf(IFP, "%s %s %lf %lf %lf %lf", last_chk, first_chk, &hr_in, &min_in, &hr_out, &min_out);
                
                //Set up a loop
                for(d=0;d<n;d++){
                      //if last name is found in structures
                      if(strcmp(emp[d].last, last_chk) == 0) {
                           //Calculate hours in the week
                           minutes_in= (hr_in*60)+(min_in);
                           minutes_out=(hr_out*60)+(min_out);
                           emp[d].hours_in_week += (minutes_out-minutes_in)/60;                       
                           break; // exit loop  
                      }
                }                                      
         }
         
         //Calculate all the info from the week
         for(u=0;u<m;u++){
                          
            //Calculate gross and tax
            if(emp[u].hours_in_week<40){
                  pay1=(emp[u].hours_in_week)*(emp[u].payprhr);
                  emp[u].gross += pay1;
                  emp[u].taxes += pay1*.1;
            }
            
            else{
                  pay1=(40)*(emp[u].payprhr);
                  emp[u].gross += pay1;
                  emp[u].taxes += pay1*.1;
                  pay2= (emp[u].hours_in_week-40)*(emp[u].payprhr*1.5);
                  emp[u].gross += pay2;
                  emp[u].taxes += pay2*.2;
            }
         }

            //Reset all the hours_in_week
            for(t=0;t<n;t++)          
                  emp[t].hours_in_week=0;
              
    }
            
            //Print everything needed
            fprintf(OFP, "Number of employees: %d\n\n", n);
            //Loop to print the number of employees  
            for(g=0;g<n;g++){
            
                  //Calculate Net Pay
                  net_pay=calc(emp[g].gross,emp[g].taxes);

                  //Print out infomation for each employee            
                  fprintf(OFP,"W2 Form\n");
                  fprintf(OFP,"-------\n");
                  fprintf(OFP,"Name: %s %s\n", emp[g].first, emp[g].last);
                  fprintf(OFP,"Gross Pay: %.2lf\n", emp[g].gross);
                  fprintf(OFP,"Taxes Withheld: %.2lf\n", emp[g].taxes);
                  fprintf(OFP,"Net Pay: %.2lf\n\n", net_pay);             
            }         
    
    //Close files
    fclose(IFP);
    fclose(OFP);
}


//Calculation Function
double calc(double a,double b){
 
       double c =0;
 
       c=a-b;
       
       return c;
            
}
