#include <stdio.h>

void convert(void); /*prototype of the converter function */

int kmConvert(void)  /* converter for km function */
{
  char scale;
  float km,mile; /*initializes the variables */
      printf("What direction would you like convert from-to K or M?:\n");
      scanf(" %c%*c", &scale); /*takes user input of a char and determines what to do */
      if (scale == 'K')
	{
	  printf("Please input the value you wish to convert :\n");
	  scanf("%f%", &km);  /*takes a user input value then converts and displays it, then calls convert */
	  mile = km*0.621371;
	  printf("Your input in miles is %f\n", mile);
	  convert();
	}
      else if (scale == 'M')
	{
	  printf("Please input the value you wish to convert :\n");
	  scanf("%f", &mile);
	  km = mile*1.60934;       /* converts to other direction then displays the output */
	  printf("Your input in km is %f\n", km);
	  convert();
	}
      else {
	printf("Please input either a M of F to indicate the direction :\n");
	kmConvert();
      } 
      return 0;
}

int mfConvert(void) /* converter for mf */
{
  char scale;
  float m,ft;
      printf("What direction would you like convert from-to M or F ?:\n");
      scanf(" %c%*c", &scale);  /*takes user input of a char */
      if (scale == 'M')
	{
 	  printf("Please input the value you wish to convert :\n");
	  scanf("%f%", &m);
	  ft = m*3.28084;       /* converts input then displays it */
	  printf("Your input in Feet is %f\n", ft);
	  convert();
	}
      else if (scale == 'F')
	{
	  printf("Please input the value you wish to convert :\n");
	  scanf("%f", &ft);  /* takes input value then converts it */
	  m = ft*0.3048;
	  printf("Your input in Meters is %f\n", m);
	  convert();
	}
      else {
	printf("Please input either M or F to indicate direction :\n");
	mfConvert();             /*loops until valid input */
      }
      return 0;
}

int ciConvert(void) /*funcion to convert ci */
{
  char scale;
  float cm,in;
      printf("What direction would you like convert from-to C or I?:\n");
      scanf(" %c%*c", &scale);  /*takes user input */
      if (scale == 'C')
	{
	  printf("Please input the value you wish to convert :\n");
	  scanf("%f%", &cm);
	  in = cm*0.393701;               /*converts to other scale */
	  printf("Your input in Inches is %f\n", in);
	  convert();
	}
      else if (scale == 'I')        /*converts in other direction if I is inputed char */
	{
	  printf("Please input the value you wish to convert :\n");
	  scanf("%f%", &in);
	  cm = in*2.54;
	  printf("Your input in Centimetres is %f\n", cm);
	  convert();
	}
      else {
	printf("Please input either a C or I to indicate direction :\n");
	ciConvert();              /*loops until valid input */
      }
      return 0;
}

int cfConvert(void) /* converter of cf */
{
  char scale;
  float celsius,fh;
      printf("What direction would you like convert from-to C or F?:\n");
      scanf(" %c%*c", &scale); /*takes user input */
      if (scale == 'C')                                
	{
	  printf("Please input the value you wish to convert :\n");
	  scanf("%f%", &celsius);                /*gets input for the value */
	  fh = ((celsius*1.8)+32.0);
	  printf("Your input in Fahrenheit is %f\n", fh);
	  convert();
	}
      else if (scale == 'F')
	{
	  printf("Please input the value you wish to convert :\n");
	  scanf("%f%", &fh);
	  celsius = ((fh-32.0)*(0.5555556));             /*converts to the new scale */
	  printf("Your input in Celsius is %f\n", celsius);
	  convert();
	}
      else {
	printf("Please input either a C or F to indicate direction :\n");
	cfConvert();                                /*loops until valid input */
      }
      return 0;
}

 
void convert(void) /* converterer of different units asks user input */
{
  char option;
  option = '\0';
  printf("What do you want to do (options 1-5): ");
  scanf(" %c%*c", &option);                   /* takes the first char of user input*/
  if (option == '1')
    kmConvert();
  else if (option == '2')
    mfConvert();
  else if (option == '3')
    ciConvert();
  else if (option == '4')
    cfConvert();
  else if (option == '5')        /*calls function dependent on input, or ends if input 5, otherwise calls self */
    return;
  else
    {
    printf("error invalid input, please enter a char 1-5!\n");
    convert();  
    }
} 



int main() { /*main method calls convert function */
  convert(); 
  return 0;
}
