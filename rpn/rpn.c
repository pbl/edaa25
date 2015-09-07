#define N		(10)
#define NO_MEMORY		(-1000)
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

// return the next char after a blankspace
int skip_blank(ch)
{
	while (ch == ' ')
	{
		ch = getchar();
	}
	return ch;
}

// if the char is a newline it reads the next char otherwise returns ch as it is
int skip_next_line(int ch)
{
	if(ch == '\n'){
		return getchar();
	}
	return ch;
}

// prints error and reads until char is newline or EOF
int error(ch){
	printf("error at %c\n", ch);
	while (ch != EOF && ch != '\n')
	{
		ch = getchar();
	}
	return ch;
}

// returns the next char to read. if the memory has been used it is used and skips blankspace
int next_char(int memory)
{
	int ch = memory;
	if(memory == NO_MEMORY)
	{
		ch = getchar();
	}
	ch = skip_blank(ch);
	return ch;
}

// int calc_line_finished(int stack[])
// {
// 	for(int i=1; i<N;i++)
// 	{
// 		if(stack[1] != 0)
// 		{
// 			return error
// 		}
// 	}
// 	printf("%d\n", stack[0]);
// 	return 0;
// }

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
				printf("Stack overflow error\n");
				return error(ch);
			}
			stack[pointer] = ch - '0';
			ch = getchar();
			while(digit(ch))
			{
				// printf("loop digit %c\n", ch);
				stack[pointer] = stack[pointer]*10 + (ch - '0');
				ch = getchar();
			}
			memory = ch;
			++pointer;
		}
		else //unknown character
		{
			printf("Unknown character error\n");
			return error(ch);
		}
		// printf("has memory %d\n", memory);
		// printf("before next char %d\n", ch);
		ch = next_char(memory);
		memory = NO_MEMORY;
		// printf("after next char %d\n", ch);
	}
	// calc_line_finished(stack);
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
	while (ch != EOF)
	{
		clean_stack(stack);
		ch = calc_line(stack, pointer, ch);
		ch = skip_next_line(ch);
	}
	return 0;
}
