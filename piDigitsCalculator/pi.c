#include <stdio.h>
#include <math.h>  
int main()
{

  double sum = 0.0;
  double epsilon;         /*declare the variables */
  double pi = 0.0;
  long long  i=1;
  long long max = 2146483647;        /*we use long long for the max integer */
  printf("Pleas enter the desired accuracy epsilon : ");
  scanf("%lf", &epsilon);           /*prompts user for desired accuracy epsilon */
  for (i=1; i<max; i++){
    if (i%2 == 0){                  /*performs the algorithm if i is odd and even until termination */
      sum = -4.0/(2.0*i-1.0);       
    }else if (i%2 ==1){
      sum = (4.0/(2.0*i-1.0));
    }
    double d1 = fabs(sum);     /*once abs of sum is less than epsilon break */
    if (d1 < epsilon){
      break;
    }
    pi += sum;                 /* adds sum to pi until desired accuracy */
  }
  printf("The value of pi approximated to epsilon : %20.18f is %20.18lf\n", epsilon, pi);
  return 0;                       /*prints the result to 18 decimal places */
}
