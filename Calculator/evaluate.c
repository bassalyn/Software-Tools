#include<stdio.h>
#include<stdlib.h>

float get_num();

char get_op();                           /* prototypes for subsequent functions */

float m_exp(float sub_exp, char op);

float s_exp(float sub_exp, char op){     /* function for a standard expression, w/ recursive calls */
  float f1;
  char op1;
	if (op == '\n'){
	  ungetc(op, stdin);            /* if op is newline char returns and pushes char back to stdin */
	  return sub_exp;
	}else{
	  f1 = m_exp(1,'*');              /* calls m_exp to get the next num */
	  op1 = get_op();                    
	  if (op == '+'){
	    f1 = sub_exp + f1;           /* takes the operator and completes lower expression and stores */
	  }else if (op == '-'){
	    f1 = sub_exp - f1;
	  }
	  return s_exp(f1,op1);         /* return recursively calls the funtion */
	}
}

float m_exp(float sub_exp, char op){        /* function for a multiplication exp with higher ops */
  float f1;
  char op1;
  if (op == '+'|| op == '-' || op == '\n'){    /*if one of chars +,-, \n returns float and pushes back to stdin */
		ungetc(op, stdin);
		return sub_exp;
	}
	else{
	  f1 = get_num();
	  op1 = get_op();                      /* uses get function to get subsequent num and op for computation */
	  if (op =='*'){
	    f1 = sub_exp * f1;                   /*computes the result of the subexp and the operator and stores */
	  }else{
	    f1 = sub_exp / f1;
	  }
	  return m_exp(f1,op1);                  /* returns recursively calls the function */
	}
}

char get_op(){                                 /* function gets next operator */
  char op = ' ';
  while (op == ' '){
    scanf("%c", &op);                            /* while op is space function it keeps scanning until operator */
  }
  if (op == '+' || op == '-' || op == '*' || op == '/' || op == '\n'){  /* if op is valid returns */
    return op;
  }else{
    printf("Warning invalid character! Please try again :\n");        /* if invalid operator warns user and exits */
    exit(EXIT_FAILURE);
  }
}

float get_num(){                                       /* function gets the next number in stdin */
	float next;
	scanf("%f", &next);
	return next;
}

  

int main(){
  char action = 'Y';
  while (action == 'Y'){                              /* will continue until user enters a different char in our case 'N' */
    printf("Please enter:\n");
    printf("Result = %f\n", s_exp(0,'+'));            /* promts then computes simple arithmetic expression from user */
    printf("Would you like to continue (Y/N)?\n");
    scanf(" %c", &action);                             /* determines if program should continue looping */
  }
  
  return 0;
}
	
