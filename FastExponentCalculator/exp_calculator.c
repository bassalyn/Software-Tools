#include <stdio.h>

float expcalc(float base, int exponent) /* function to calculate and exponent given a base */
{
  float temp;
  if (exponent == 0)
    return 1;                    /* if exponent 0 result is 1*/
  temp = expcalc(base, exponent/2);          /*temporary value */
  if (exponent%2 == 0)           /*if even return  square temp*/
    return temp*temp;
  else
    {
      if (exponent>0)            /*if exp positive return base * temp *temp */
	return base*temp*temp;
      else 
	return (temp*temp)/base; /*otherwise divide the base if negative */
    }
}

int main()                     /*main function */
{
        float base, result;
	int exponent;
	printf("Enter a base (float):\n");
	scanf("%f", &base);                      /* prompts user for and accepts input for base */
	while (base < 0)
	  {
	    printf("Error please enter a positive base (float)");
	    scanf("%f", &base);
	  }
	printf("Enter an exponent (int) :\n");
	scanf("%d", &exponent);                  /*prompts user and inputs exponent */
	result = expcalc(base, exponent);
	printf("The result of %f to the %d is : %f \n", base, exponent, result);   /* displays the result of the calculation*/
	return 0;
}
