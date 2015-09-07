#define N		(10)
#include <stdio.h>
#include <stdlib.h>


void calc(int stack[], int pointer, int op)
{
  	switch(op){
    	case '+':
      		stack[pointer-2] = stack[pointer-2] + stack[pointer-1];
      		break;
    	case '-':
      		stack[pointer-2] = stack[pointer-2] - stack[pointer-1];
      		break;
    	// case '*':
    	// 	stack[pointer-2] = stack[pointer-2] * stack[pointer-1];
    	// case '/':
	    // 	stack[pointer-2] = stack[pointer-2] / stack[pointer-1];
  }
  stack[pointer-1] = 0;
}

int operator(int op)
{
	return op == '+' || op == '-' || op == '*' || op == '/';
}

int digit(ch)
{
	return (ch >= '0' && ch <= '9');
}

int skip_blank(ch)
{
	ch = getchar();
	while (ch == ' ')
	{
		ch = getchar();
	}
	return ch;
}

int error(ch){
	printf("error at %c\n", ch);
	while (ch != EOF && ch != '\n')
	{
		ch = getchar();
	}
	return ch;
}

int calc_line(int stack[], int pointer, int ch)
{
	while(ch != '\n')
	{
		if(ch == EOF){
			printf("%d\n", stack[0]);
			return EOF;
		}

		if (operator(ch))
		{
			// enough_digits(stack);
			calc(stack, pointer, ch);
			pointer = pointer-1;
		}
		else if(digit(ch))
		{
			if (pointer == N)
			{
				return error(ch);
			}
			stack[pointer] = ch - '0';
			++pointer;
		}
		else //unknown character
		{
			return error(ch);
		}
		ch = skip_blank();
	}
	printf("%d\n", stack[0]);
	return getchar();
}

int main(void)
{
	int stack[N];
	int ch, pointer = 0;
	ch = getchar();
	while (ch != EOF)
	{
		ch = calc_line(stack, pointer, ch);
	}
	return 0;
}
