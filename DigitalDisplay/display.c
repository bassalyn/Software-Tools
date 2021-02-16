#include<stdio.h>

char segments[10][3][3] = { { {' ', '_',' '}, {'|', ' ', '|'}, {'|', '_', '|'}},
			    { {' ', ' ', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'} },      /* 2d array of chars for digits of display */
							{ {' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '} },
							{ {' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'} },
							{ {' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'} },
							{ {' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'} },
							{ {' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'} },
							{ {' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'} },
							{ {' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'} },
							{ {' ', '_', ' '}, {'|', '_', '|'}, {' ', ' ', '|'} }};
							
int length(char* num){        /* function counts the length of the inputted integer and returns int */
  int count;
  for (count=0;num[count]!= '\0'; count++);
  return count;
}



int display(char* num){        /*function displays the integer in seven segment form using several for loops */
  int i,j,n,k;
  n = length(num);               /*sets n to be length */
  if (num[0]!='-'){
    for (i=0; i<3; i++){
      for (k=0; k<n; k++){
	for (j=0; j<3; j++){
	  printf("%c", segments[num[k]-'0'][i][j]);  /*loops through the 2d array printing all digits in the int */
	}
      }	
      
      
      printf("\n");
    }
  }else{
    for (i=0; i<3; i++){     /*same as before but for negative integer inputs */
      if (i%2==0){
	printf(" ");             /*prints the negative sign before the digit display */
      }else{
	printf("-");            
      }
      for (k=1; k<n; k++){
	for (j=0; j<3; j++){
	  printf("%c", segments[num[k]-'0'][i][j]);     /* loops through and displays int in display form from 2d array */
	}
      }
      
      printf("\n");
    }
  }
  printf("\n");
  return 0;
}

int main(){
	char num[100];
	char ch;
	do{
	  printf("Please enter an integer :\n");
	  scanf(" %[^\t\n]s", &num);                   /*main function asks for and recieves user input for integer */
	  display(num);
	  printf ("Do you want to continue: Y/N\n");
	  scanf (" %c", &ch);
	}while (ch == 'Y');                            /*continues displaying ints until user enters a key */
}
									

									
