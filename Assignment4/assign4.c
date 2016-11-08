//Alan Birmaher
//COP 3223-0002
//Assignment #4
//3/20/12
//Purpose: This program is an image edior that has 3 functions. It can brighten or darken
//an image by a specified amount, subtract one image from another or detect the edges of an image.
//After performing any of these functions it saves the new file.

//Defining Which .h files to include
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Defining Values
#define  BUFFER_SIZE  70
#define  TRUE          1
#define  FALSE         0

//Establishing Variables
int    numRows;
int    numCols;
int    maxVal;
int	   input;
int    brightness_change;
int    i, j;
FILE*  fo1;
int**  temppicx;
int**  temppicy;
int**  sobelout;
int**  pic1;
int**  pic2;
int**  pic3;
int**  img;

//Establishing Functions
void  addtopixels(int** imgtemp, int value);
void  writeoutpic(char* fileName, int** imgtemp);
int** readpic(char* fileName);
void  readHeader(FILE* imgFin);
int   isComment(char* line);
void  readImgID(char* line);
void  readImgSize(char* line);
void  readMaxVal(char* line);
int** setImage();
void  readBinaryData(FILE* imgFin, int** imgtemp);
void  sobelfunc(int** pic, int** edges, int** tempx, int** tempy);
void  subtractpics(int** pic1, int** pic2, int** pic3);

//Main function that runs and calls the other functions
int main()
{
        char fileName[BUFFER_SIZE];
        int i,j,rows,cols;
        char ci;
		
		//Loop used so that the user can tell the program what he wants it to do.
        while (input !=4){
		
		//Prompt user for choice
		printf("*****************************\n");
		printf("*      Image Editor         *\n");
		printf("*****************************\n");
        printf("What would you like to do?\n");
		printf("1) Add brightness\n");
		printf("2) Subtract Pictures\n");
		printf("3) Highlight The Edges\n");
		printf("4) Exit\n\n");
		printf("Choice: ");
		scanf("%d", &input);
		printf("\n");
		
		printf("*****************************\n\n");
			
			//If user selects option 1
            if (input == 1){
                      
                //Ask for file name
                printf("Enter image filename: ");
                scanf("%s", fileName);

                //Sends the file to a function where it is read
                img = readpic(fileName);

                //Lets the user know that te image has been read in correctlt
                printf("Successfully read image file '%s'\n\n", fileName);
				
				//Asks user by how much they would like to increase their brightness
                printf("How much would you like to increase the brighness by?\n(To reduce brightness enter negative variables)\n");
				scanf("%d", &brightness_change);
				printf("\n");
				
				//Sends the file and brightness change to thefunction where the operation is performed
                addtopixels(img,brightness_change);
				
				//Writes the new picture to an image called out1.pgm
                writeoutpic("out1.pgm",img);

				//Releases the image
                free(img);
				img = NULL;
				
				//Tells the user that the operation has been completed sucessfully
                printf("Your file has been brightened and sucessfully saved.\n\n");
			}
			
			//If the user selects option 2
			else if (input == 2){
                 
                 //Asks user for the first file to import
                printf("Please enter image 1 file name: ");
                scanf("%s", &fileName);
                
                //Reads the imported file
                pic1 = readpic(fileName);
                printf("\n\n");
                
                //Alerts the user that image 1 has been read sucessfully
                printf("Image 1 sucessfully imported.\n");
                
                //Asks user for the second file to import
                printf("Please enter image 2 file name: ");
                scanf("%s", &fileName);
                
                //Reads the imported file
                pic2 = readpic(fileName);
                printf("\n\n");
                
                //Alerts the user that image 2 has been read sucessfully
                printf("Image 2 sucessfully imported.\n");
                 
                //Establishes pic3
                pic3 = setImage();
                 
                //Calls the function feeiding it the information from the imported files and new picture
                subtractpics(pic1,pic2,pic3);
                 
                //Saves the result of the fucntion as a new image called out2.pgm
                writeoutpic("out2.pgm",pic3);
				            
				//Releases the image          
				free(img);
				img = NULL; 
			
			    //Alerts the user that the operation has been scessfully completed
				printf("Your subtracted image has been created and saved.\n\n");           
            
            }
			
			//If user selects option 3
            else if (input == 3){
                 
                 //Asks for the file name from the user
                 printf("Enter file name: ");
                 scanf("%s", &fileName);
                 
                 //Reads in the file
                 img = readpic(fileName);
                 
                 //Sets space aside for the picsture
                 sobelout = setImage();
                 temppicx = setImage();
                 temppicy = setImage();

                 //Call to the function feeding in necessary information
                 sobelfunc(img,sobelout,temppicx,temppicy); 

                 // Save the new picture
                 writeoutpic("out3.pgm",sobelout);
                 
                 //Relase the image
                 free(img);
				 img = NULL;
                 
                 //Alerts the user that the operation has been sucessfully completed
                 printf("Your new picture has been created and saved.\n\n");       
                 
            }
            
            //If user wants to exit the program
			else if (input == 4)
			     return(EXIT_SUCCESS);	
            
            //Alerts the user of incorrect input     		
			else
				printf("Incorect Input. Try Again.\n\n");
		
		}
}
//Function that runs through an entire image adding 
//a certain brightness to each pixel
void addtopixels(int** imgtemp, int value)
{  
        int i,j;
        
        for (i=0;i<numRows;i++)
        { for (j=0;j<numCols;j++)
                {
                    img[i][j] += value;
                }
        }
}

//Function that saves the new pictures as a new file
void writeoutpic(char* fileName, int** imgtemp)
{
        int i,j;
        char ci;
        FILE* fo1;
        
        if((fo1 = fopen(fileName, "wb")) == NULL)
        {
                printf("Unable to open out image file '%s'\n", fileName);
                exit(EXIT_FAILURE);
        }

        fprintf(fo1,"P5\n");
        fprintf(fo1,"%d %d\n", numRows, numCols);
        fprintf(fo1,"255\n");

        for (i=0;i<numRows;i++)
        { for (j=0;j<numCols;j++)
                {
                  ci   =  (char) (imgtemp[i][j]);
                  fprintf(fo1,"%c", ci);
                }
        }
}

//Reads in the images we use 
int** readpic(char* fileName)
{
        FILE* imgFin;
        int** imgtemp;

        if((imgFin = fopen(fileName, "rb")) == NULL)
        {
                printf("Unable to open image file '%s'\n", fileName);
                exit(EXIT_FAILURE);
        }

        readHeader(imgFin);


        imgtemp  = setImage();

        readBinaryData(imgFin, imgtemp);

        fclose(imgFin);
        
        return  imgtemp;

}

//Reads the file header
void readHeader(FILE* imgFin)
{
        int  haveReadImgID   = FALSE;
        int  haveReadImgSize = FALSE;
        int  haveReadMaxVal  = FALSE;
        char line[BUFFER_SIZE];

        while(!(haveReadImgID && haveReadImgSize && haveReadMaxVal))
        {
                fgets(line, BUFFER_SIZE, imgFin);

                if((strlen(line) == 0) || (strlen(line) == 1))
                        continue;

                if(isComment(line))
                        continue;

                if(!(haveReadImgID))
                {
                        readImgID(line);
                        haveReadImgID = TRUE;
                }
                else if(!(haveReadImgSize))
                {
                        readImgSize(line);
                        haveReadImgSize = TRUE;
                }
                else if(!(haveReadMaxVal))
                {
                        readMaxVal(line);
                        haveReadMaxVal = TRUE;
                }
        }

}

int isComment(char *line)
{
        if(line[0] == '#')
                return(TRUE);

        return(FALSE);
}

//Reads image ID
void readImgID(char* line)
{
        if(strcmp(line, "P5\n") != 0)
        {
                printf("Invalid image ID\n");
                exit(EXIT_FAILURE);
        }
}

//Reads image size
void readImgSize(char* line)
{
        unsigned i;

        for(i = 0; i < strlen(line); ++i)
        {
                if(!((isdigit((int) line[i])) || (isspace((int) line[i]))))
                {
                        printf("Invalid image size\n");
                        exit(EXIT_FAILURE);
                }
        }

        sscanf(line, "%d %d", &numRows, &numCols);
}

//Find image max value
void readMaxVal(char* line)
{
        unsigned i;

        for(i = 0; i < strlen(line); ++i)
        {
                if(!((isdigit((int) line[i])) || (isspace((int) line[i]))))
                {
                        printf("Invalid image max value\n");
                        exit(EXIT_FAILURE);
                }
        }

        maxVal = atoi(line);
}

//Allocates space for the new images being made
int** setImage()
{
        int** imgtemp;
        unsigned i;

        imgtemp = (int**) calloc(numRows, sizeof(int*));

        for(i = 0; i < numRows; ++i)
        {
                imgtemp[i] = (int*) calloc(numCols, sizeof(int));
        }
        return imgtemp;
}

void readBinaryData(FILE* imgFin, int** imgtemp)
{
        unsigned  i;
        unsigned  j;
        for(i = 0; i < numRows; ++i)
        {
                for(j = 0; j < numCols; ++j)
                {
                            imgtemp[i][j] = 
                            fgetc(imgFin);
                }
        }
}

//Creates an image, one image is subtracted from another
void subtractpics(int** pic1, int** pic2, int** pic3){
     
     for (i=0; i<numRows; i++){
         for(j=0; j<numCols; j++){
                  pic3[i][j]=abs(pic1[i][j]-pic2[i][j]);
         }
     }
}

//Function that finds the outline of pictures
void sobelfunc(int** pic, int** edges, int** tempx, int** tempy){

        int maskx[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
        int masky[3][3] = {{1,2,1},{0,0,0},{-1,-2,-1}};
        int maxival;


        
 
        int i,j,p,q,mr,sum1,sum2;
        double threshold;
         

        mr = 1;


        for (i=mr;i<numRows-mr;i++)
        { for (j=mr;j<numCols-mr;j++)
          {
             sum1 = 0;
             sum2 = 0;
             for (p=-mr;p<=mr;p++)
             {
                for (q=-mr;q<=mr;q++)
                {
                   sum1 += pic[i+p][j+q] * maskx[p+mr][q+mr];
                   sum2 += pic[i+p][j+q] * masky[p+mr][q+mr];
                }
             }
             tempx[i][j] = sum1;
             tempy[i][j] = sum2;
          }
        }

        maxival = 0;
        for (i=mr;i<numRows-mr;i++)
        { for (j=mr;j<numCols-mr;j++)
          {
             edges[i][j]=(int) (sqrt((double)((tempx[i][j]*tempx[i][j]) +
                                      (tempy[i][j]*tempy[i][j]))));
             if (edges[i][j] > maxival)
                maxival = edges[i][j];

           }
        }



        for (i=0;i<numRows;i++)
          { for (j=0;j<numCols;j++)
            {
             edges[i][j] = ((edges[i][j]*1.0) / maxival) * 255;            
             
            }
          }
}
