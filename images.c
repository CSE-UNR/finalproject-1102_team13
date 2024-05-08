//Authors: Uvensis Martinez, Kaitlyn Rouse
//Date: 5/7/2024
//Purpose: Erinstagram <3

#include<stdio.h>

#define MAXSIZE 500

void Dim(int(*)[MAXSIZE], int(*)[MAXSIZE][MAXSIZE], int, int);
void Brighten(int(*)[MAXSIZE], int(*)[MAXSIZE][MAXSIZE], int, int);
void Crop(int(*)[MAXSIZE], int(*)[MAXSIZE][MAXSIZE], int, int, int*, int*, int, int, int, int);
void getCropNums(int(*)[MAXSIZE], int, int, int*, int*, int*, int*);

void LoadImage(int imageArray[][MAXSIZE], int *rowPtr, int *colSizePtr);
void DisplayImage(int imageArray[][MAXSIZE], int rowSize, int colSize);

int main(){
	
char userschoice, userschoice2;
int imageArray[MAXSIZE][MAXSIZE];
int colSize, rowSize;

do{
  userschoice = '0';
  printf("\nWelcome to Erinstagram\n");
  printf("[1]-Load Your Image\n");
  printf("[2]-Display Your Image\n");
  printf("[3]-Edit The Image\n");
  printf("[4]-Exit\n");
  printf("Please select a number from the brackets: ");
  scanf("%c", &userschoice);

  if(userschoice == '4'){
    printf("\nThank you for choosing Erinstagram\n");
    printf("\nGoodbye!\n");
  }


  else if(userschoice == '3'){
  // edit image'
    
    int newArray[MAXSIZE][MAXSIZE];
    
    printf("\nChoose an option:\n[1] Brighten your image\n[2] Dim your image\n[3] crop your image\n\nEnter your option: ");
    scanf(" %c", &userschoice2);
   
    if(userschoice2 == '1'){
	// brighten
	Brighten(imageArray, &newArray, rowSize, colSize);
    }
      
    else if(userschoice2 == '2'){
	// dim
	Dim(imageArray, &newArray, rowSize, colSize);
    }

    else if(userschoice2 == '3'){
	// crop
	int hcrop1, hcrop2, vcrop1, vcrop2, newRowSize, newColSize;
	int newArray[rowSize][colSize];
	getCropNums(imageArray, rowSize, colSize, &hcrop1, &hcrop2, &vcrop1, &vcrop2);
	Crop(imageArray, &newArray, rowSize, colSize, &newRowSize, &newColSize, hcrop1, hcrop2, vcrop1, vcrop2);
    }

    else{
      printf("\nError: invalid option\n");
    }
  }

	    
  else if(userschoice == '2'){
	// display image
	DisplayImage(imageArray, rowSize, colSize);
  }
