#define N		(10)
#define NO_MEMORY		(-1000)
#include <stdio.h>
#include <ctype.h>

int pointer = 0;
void calc(int stack[], int op)
{
	switch(op)
	{
		case '+':
			stack[pointer-2] = stack[pointer-2] + stack[pointer-1];
			break;
		case '-':
			stack[pointer-2] = stack[pointer-2] - stack[pointer-1];
			break;
		case '*':
			stack[pointer-2] = stack[pointer-2] * stack[pointer-1];
			break;
		case '/':
			stack[pointer-2] = stack[pointer-2] / stack[pointer-1];
			break;
	}
	stack[pointer-1] = 0;
}

int operator(int op)
{
	return op == '+' || op == '-' || op == '*' || op == '/';
}

int skip_blanks(int ch)
{
	while (ch == ' ')
	{
		ch = getchar();
	}
	return ch;
}

int error(int ch){
	printf("error at %c\n", ch);
	while (ch != EOF && ch != '\n')
	{
		ch = getchar();
	}
	return ch;
}

int next_char(int memory)
{
	int ch = memory;
	if (memory == NO_MEMORY)
	{
		ch = getchar();
	}
	ch = skip_blanks(ch);
	return ch;
}

int calc_line(int ch)
{
	int memory = NO_MEMORY;
	int stack[N];
	while (ch != '\n' && ch != EOF)
	{
		if (operator(ch))
		{
			if (pointer < 2 || (ch == '/' && stack[pointer-1] == 0))
			{
				return error(ch);
			}
			calc(stack, ch);
			pointer = pointer-1;
		}
		else if (isdigit(ch))
		{
			if (pointer == N)
			{
				return error(ch);
			}
			stack[pointer] = ch - '0';
			ch = getchar();
			while (isdigit(ch))
			{
				stack[pointer] = stack[pointer]*10 + (ch - '0');
				ch = getchar();
			}
			memory = ch;
			++pointer;
		}
		else
		{
			return error(ch);
		}
		ch = next_char(memory);
		memory = NO_MEMORY;
	}
	if (pointer != 1)
	{
		printf("error at \\n\n");
	}
	else
	{
		printf("%d\n", stack[0]);
	}
	return ch;
}

int main(void)
{
	int ch;
	int inc = 1;
	ch = getchar();
	while (ch != EOF)
	{
		printf("line %d: ", inc);
		ch = calc_line(ch);
		if (ch == '\n')
		{
			ch = getchar();
		}
		pointer = 0;
		inc++;
	}
	return 0;
}
