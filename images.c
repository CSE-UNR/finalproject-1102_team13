//Authors: Uvensis Martinez, Kaitlyn Rouse
//Date:
//Purpose: Erinstagram <3

//Insert comments: 

#include<stdio.h>

#define MAXSIZE 500

void Dim(int(*)[MAXSIZE], int(*)[MAXSIZE][MAXSIZE], int, int);
void Brighten(int(*)[MAXSIZE], int(*)[MAXSIZE][MAXSIZE], int, int);
void Crop(int(*)[MAXSIZE], int(*)[MAXSIZE][MAXSIZE], int, int, int*, int*, int, int, int, int);
void getCropNums(int(*)[MAXSIZE], int, int, int*, int*, int*, int*);



int main(){
	
char userschoice, userschoice2;
int imageArray[MAXSIZE][MAXSIZE];
int colSize, rowSize;

do{
  printf("\nWelcome to Erinstagram\n");
  printf("[1]-Load Your Image\n");
  printf("[2]-Display Your Image\n");
  printf("[3]-Edit The Image\n");
  printf("[4]-Exit\n");
  scanf(" %c", &userschoice);

  if(userschoice ='4'){
    printf("\nThank you for choosing Erinstagram\n");
    printf("\nGoodbye!\n");
  }


  else if(userschoice = '3'){
  // edit image'
    
    int newArray[MAXSIZE][MAXSIZE];
    
    printf("\nChoose an option:\n[1] Brighten your image\n[2] Dim your image\n[3] crop your image\n\nEnter your option: ");
    scanf(" %c", &userschoice2);
   
    if(userschoice2 = '1'){
	// brighten
	Brighten(imageArray, &newArray, rowSize, colSize);
    }
      
    else if(userschoice2 = '2'){
	// dim
	Dim(imageArray, &newArray, rowSize, colSize);
    }

    else if(userschoice2 = '3'){
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

	    
  else if(userschoice = '2'){
	// display image
  }

	  
  else if(userschoice = '1'){
	// load image
	  
	// should return a 2D array to the int array 'imageArray' please
	// should return the column and row sizes to the int variables called 'colSize' and 'rowSize' please
  }


  // NOTE: All of these edits return 'newArray', and crop also returns 'newColSize' and 'newRowSize'
  // Good to know for the 'save image' option
	  

  else{
    printf("\nError: invalid option");
    userschoice = '4';
  }
}
while(userschoice != '4');   


return 0;
}


void getCropNums(int imageArray[][MAXSIZE], int rowSize, int colSize, int *hcrop1Ptr, int *hcrop2Ptr, int *vcrop1Ptr, int *vcrop2Ptr){
	int hcrop1, hcrop2, vcrop1, vcrop2;
	do{
		printf("\nFor the horizontal crop, enter the numbers corresponding to the sections you want to crop off. If you don't want to crop horizontally, just enter 0 and %d", rowSize+1);
		printf("\nEnter your first number: ");
		scanf("%d", &hcrop1);
		printf("\nEnter your second number: ");
		scanf("%d", &hcrop2);
	
		if(hcrop1 > hcrop2){
			int smallerhcrop = hcrop2;
			hcrop2 = hcrop1;
			hcrop1 = smallerhcrop;
		}
		if(hcrop2 > rowSize + 1 || hcrop1 < 0){
			printf("\nError: your selections are not within the boundaries of 0 and %d", rowSize+1);
		}
	}	
	while(hcrop2 > rowSize + 1 || hcrop1 < 0);

	do{
		printf("\nFor the vertical crop, enter the numbers corresponding to the sections you want to crop off. If you don't want to crop horizontally, just enter 0 and %d", colSize+1);
		printf("\nEnter your first number: ");
		scanf("%d", &vcrop1);
		printf("\nEnter your second number: ");
		scanf("%d", &vcrop2);
		if(vcrop1 > vcrop2){
			int smallervcrop = vcrop2;
			vcrop2 = vcrop1;
			vcrop1 = smallervcrop;
		}
		if(vcrop2 > colSize + 1 || vcrop1 < 0){
			printf("\nError: your selections are not within the boundaries of 0 and %d", colSize+1);
		}
	}	
	while(vcrop2 > colSize + 1 || vcrop1 < 0);
	*hcrop1Ptr = hcrop1;
	*hcrop2Ptr = hcrop2;
	*vcrop1Ptr = vcrop1;
	*vcrop2Ptr = vcrop2;
}




void Dim(int imageArray[][MAXSIZE], int (*newArrayPtr)[MAXSIZE][MAXSIZE], int rowSize, int colSize){

	for(int row_i = 0; row_i < rowSize; row_i++){
		for(int col_i = 0; col_i < colSize; col_i++){
			int new_brightness = imageArray[row_i][col_i] - 1;
			if(new_brightness < 0){
				new_brightness = 0;
			}
			*newArrayPtr[row_i][col_i] = new_brightness;
		}
	}

}

void Brighten(int imageArray[][MAXSIZE], int (*newArrayPtr)[MAXSIZE][MAXSIZE], int rowSize, int colSize){

	for(int row_i = 0; row_i < rowSize; row_i++){
		for(int col_i = 0; col_i < colSize; col_i++){
			int new_brightness = imageArray[row_i][col_i] + 1;
			if(new_brightness > 4){
				new_brightness = 4;
			}
			*newArrayPtr[row_i][col_i] = new_brightness;
		}
	}

}

void Crop(int imageArray[][MAXSIZE], int (*newArrayPtr)[MAXSIZE][MAXSIZE], int rowSize, int colSize, int *newRowSizePtr, int *newColSizePtr, int h1, int h2, int v1, int v2){
	// h1 and h2 = horizontal locations to crop. h1 is the smaller int
	// v1 and v2 = vertical locations to crop. v1 is the smaller int
	
	int newColSize, newRowSize = 0;
	
	for(int rowindex = v1; rowindex <= v2; rowindex++){
		for(int colindex = h1; colindex <= h2 ; colindex++){
			int newval = imageArray[rowindex][colindex];
			*newArrayPtr[rowindex-v1][colindex-h1] = newval;
			newColSize++;
		}
		newRowSize++;
	}
	
	*newRowSizePtr = newRowSize;
	*newColSizePtr = newColSize;	

}
