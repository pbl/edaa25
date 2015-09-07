#define N		(10)
#define NO_MEMORY		(-2)
#include <stdio.h>

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
	while (ch == ' ')
	{
		ch = getchar();
	}
	return ch;
}


int skip_next_line(int ch)
{
	if(ch == '\n'){
		return getchar();
	}
	return ch;
}

int error(ch){
	printf("error at %c\n", ch);
	while (ch != EOF && ch != '\n')
	{
		ch = getchar();
	}
	ch = skip_next_line(ch);
	return ch;
}

int next_char(int memory)
{
	if(memory == NO_MEMORY)
	{
		return getchar();
	}
	int ch = memory;
	memory = NO_MEMORY;
	return ch;
}


int calc_line(int stack[], int pointer, int ch)
{
	int memory = NO_MEMORY;
	while(ch != '\n' && ch != EOF)
	{
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
			ch = getchar();
			while(digit(ch))
			{
				stack[pointer] = ch - '0' + stack[pointer];
			}
			memory = ch;
			// while()
			++pointer;
		}
		else //unknown character
		{
			return error(ch);
		}
		ch = next_char(memory);
		ch = skip_blank(ch);
	}
	ch = skip_next_line(ch);
	printf("%d\n", stack[0]);
	return ch;
}

int clean_stack(int stack[])
{
	int i=0;
	for(i < N; i++;)
	{
		stack[i] = 0;
	}
}

int main(void)
{
	int stack[N];
	int ch, pointer = 0;
	ch = getchar();
	// printf("%d\n", ch != EOF);
	while (ch != EOF)
	{
		clean_stack(stack);
		ch = calc_line(stack, pointer, ch);
	}
	return 0;
}
