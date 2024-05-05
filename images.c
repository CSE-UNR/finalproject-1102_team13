//Authors: Uvensis Martinez, 
//Date:
//Purpose:Erinstagram

//Insert comments: 

#include<stdio.h>




int main(){
char userschoice;

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
  // edit image
    char userschoice2;
    printf("\nChoose an option:\n[1] Brighten your image\n[2] Dim your image\n[3] crop your image\n\nEnter your option: ");
    scanf(" %c", &userchoice2);
   
    if(userschoice2 = '1'){
      // brighten
    }
      
    else if(userschoice2 = '2'){
      // dim
    }

    else if(userschoice2 = '3'){
      // crop
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
  }

  else{
    printf("\nError: invalid option);
    userschoice = 4;
  }
}
while(userschoice != '4');   


return 0;
}











