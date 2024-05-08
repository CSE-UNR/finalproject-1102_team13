//Authors: Uvensis Martinez, Kaitlyn Rouse
//Date: 5/7/2024
//Purpose: Erinstagram <3

//Insert comments: //

#include <stdio.h>

#define MAXSIZE 500

void Dim(char imageArray[][MAXSIZE], int newArray[MAXSIZE][MAXSIZE], int rowSize, int colSize);
void Brighten(char imageArray[][MAXSIZE], int newArray[MAXSIZE][MAXSIZE], int rowSize, int colSize);
void Crop(char imageArray[][MAXSIZE], int newArray[MAXSIZE][MAXSIZE], int rowSize, int colSize, int *newRowSizePtr, int *newColSizePtr, int h1, int h2, int v1, int v2);
void getCropNums(char imageArray[][MAXSIZE], int rowSize, int colSize, int *hcrop1Ptr, int *hcrop2Ptr, int *vcrop1Ptr, int *vcrop2Ptr);

void LoadImage(char imageArray[][MAXSIZE], int* rowPtr, int* colSizePtr);
void DisplayImage(char imageArray[][MAXSIZE], int rowSize, int colSize);

int main(){
	
char userschoice, userschoice2, userschoice3;

int colSize = 0, rowSize = 0;
int newRowSize = 0, newColSize = 0;
char imageArray[MAXSIZE][MAXSIZE];
char userfilename[100];

do{
  
  printf("\nWelcome to Erinstagram\n");
  printf("[1]-Load Your Image\n");
  printf("[2]-Display Your Image\n");
  printf("[3]-Edit The Image\n");
  printf("[4]-Exit\n");
  printf("Please select a number from the brackets: ");
  scanf(" %c", &userschoice);
  
  if(userschoice == '1'){
	// load image
	  LoadImage(imageArray, &rowSize, &colSize);
	
  }
  
  else if(userschoice == '2'){
	// display image
	DisplayImage(imageArray, rowSize, colSize);
  }



  else if(userschoice == '3'){
  	// edit image
    
    int newArray[MAXSIZE][MAXSIZE];
    
    printf("\nChoose an option:\n[1] Brighten your image\n[2] Dim your image\n[3] crop your image\n\nEnter your option: ");
    scanf(" %c", &userschoice2);
   
    if(userschoice2 == '1'){
	// brighten
	Brighten(imageArray, newArray, rowSize, colSize);
    }
      
    else if(userschoice2 == '2'){
	// dim
	Dim(imageArray, newArray, rowSize, colSize);
    }

    else if(userschoice2 == '3'){
	// crop
	int hcrop1, hcrop2, vcrop1, vcrop2;
	int newArray[rowSize][colSize];
	getCropNums(imageArray, rowSize, colSize, &hcrop1, &hcrop2, &vcrop1, &vcrop2);
	Crop(imageArray, newArray, rowSize, colSize, &newRowSize, &newColSize, hcrop1, hcrop2, vcrop1, vcrop2);
    }

    else{
      printf("\nError: invalid option\n");
    }
    
    
    // saving image
    printf("\nWould you like to save your edited image to a new file?\n[1] Yes\n[2] No\n\nEnter your choice: ");
    scanf(" %c", &userschoice3);
    if(userschoice3 == '1'){
    	char outputfilename[100];
    	printf("\nEnter the name of the file (should be blank) that you want to update with your edited image:\n");
    	scanf(" %s", outputfilename);
    	
    	FILE *file = fopen(outputfilename, "w");
    	if (file == NULL){
    		printf("\nError: could not open file %s\n", outputfilename);
    	}
    	else {
    	   if(userschoice2 == '3'){
    	   	rowSize = newRowSize;
    	   	colSize = newColSize;
    	   }
    	   for (int i = 0; i < colSize; i++) {
        	for (int j = 0; j < rowSize; j++) {
        	    fprintf(file, "%c", newArray[i][j]);
       		}
        	fprintf(file, "\n");
           }
           fclose(file);
           printf("\nFile saved successfully!\n");
    	}	
    }
    }  
    
  
  
//Choice 4
  else if(userschoice == '4'){
    printf("\nThank you for choosing Erinstagram\n");
    printf("\nGoodbye!\n");
  }
	  
}while(userschoice != '4');   

return 0;
}

void LoadImage(char imageArray[][MAXSIZE], int *rowSizePtr, int *colSizePtr) {
    char userfileName[100]; // Declare userfileName to pick names
    
    printf("\nEnter the name of the image file:\n");
    scanf(" %s", userfileName); // user chooses
    
    FILE *file = fopen(userfileName, "r"); // Open the file for reading

    if (file == NULL) {
        printf("Error: Could not open the file %s\n", userfileName);
        return;
    }
    else{
    	int col_i = 0;
    	int row_i = 0;
    	int row_size = 0;
    	char value;
    	printf("Successfully opened file %s\n", userfileName);
    
    	while(fscanf(file, "%c", &value) == 1){
    		fscanf(file, "%c", &value);
    		if(value == '\n'){
    			col_i++;
    			row_i = 0;
    		}
    		else{
    			fscanf(file, "%c", &value);
    			imageArray[row_i][col_i] = value;
    			row_i++;
    			row_size++;
    		}
        }
        *rowSizePtr = row_size;
        *colSizePtr = col_i;
        printf("row size: %d\ncol size: %d\n", row_size, col_i);
    }

    // Close the file
    fclose(file);

    printf("\nImage loaded successfully from %s.\n", userfileName);
}





void DisplayImage(char imageArray[][MAXSIZE], int rowSize, int colSize) {
    char brightnessMap[] = {' ', '.', 'o', 'O', '0'};
    
    printf("row size: %d\ncol size: %d\n", rowSize, colSize);
       
    for (int i = 0; i < colSize; i++) {
        for (int j = 0; j < rowSize; j++) {
        	printf("%c", brightnessMap[imageArray[i][j]]);
        }
        printf("\n");
    }
}


void getCropNums(char imageArray[][MAXSIZE], int rowSize, int colSize, int *hcrop1Ptr, int *hcrop2Ptr, int *vcrop1Ptr, int *vcrop2Ptr){
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




void Dim(char imageArray[][MAXSIZE], int newArray[MAXSIZE][MAXSIZE], int rowSize, int colSize){

	for(int row_i = 0; row_i < rowSize; row_i++){
		for(int col_i = 0; col_i < colSize; col_i++){
			int new_brightness = imageArray[row_i][col_i] - 1;
			if(new_brightness < 0){
				new_brightness = 0;
			}
			newArray[row_i][col_i] = new_brightness;
		}
	}

}

void Brighten(char imageArray[][MAXSIZE], int newArray[MAXSIZE][MAXSIZE], int rowSize, int colSize){

	for(int row_i = 0; row_i < rowSize; row_i++){
		for(int col_i = 0; col_i < colSize; col_i++){
			int new_brightness = imageArray[row_i][col_i] + 1;
			if(new_brightness > 4){
				new_brightness = 4;
			}
			newArray[row_i][col_i] = new_brightness;
		}
	}

}

void Crop(char imageArray[][MAXSIZE], int newArray[MAXSIZE][MAXSIZE], int rowSize, int colSize, int *newRowSizePtr, int *newColSizePtr, int h1, int h2, int v1, int v2){
	// h1 and h2 = horizontal locations to crop. h1 is the smaller int
	// v1 and v2 = vertical locations to crop. v1 is the smaller int
	
	int newColSize, newRowSize = 0;
	
	for(int rowindex = v1; rowindex <= v2; rowindex++){
		for(int colindex = h1; colindex <= h2 ; colindex++){
			int newval = imageArray[rowindex][colindex];
			newArray[rowindex-v1][colindex-h1] = newval;
			newColSize++;
		}
		newRowSize++;
	}
	
	*newRowSizePtr = newRowSize;
	*newColSizePtr = newColSize;	

}
