#include <check.h>
#include "rpn.c"

void test_calc()
{
	printf("%s\n", "TEST CALC");
	int stack[2];
	stack[0] = 1;
	stack[1] = 2;
	int pointer = 2;
	calc(stack, pointer, '+');
	printf("%s\n", "should return 3");
	printf("%d\n", stack[0]);
	printf("%s\n", "should return 0");
	printf("%d\n", stack[1]);

	stack[0] = 1;
	stack[1] = 2;
	pointer = 2;
	calc(stack, pointer, '-');
	printf("%s\n", "should return -1");
	printf("%d\n", stack[0]);
}

void test_operator()
{
	printf("%s\n", "TEST OPERATOR");
	printf("%s\n", "should return 1");
    printf("%d\n", operator('+'));
    printf("%d\n", operator('*'));
    printf("%d\n", operator('-'));
    printf("%d\n", operator('/'));
    printf("%s\n", "should return 0");
    printf("%d\n", operator('1'));
    printf("%d\n", operator('0'));
    printf("%d\n", operator('a'));
    printf("%d\n", operator('z'));
    printf("%d\n", operator('#'));
}

int main(void)
{
	test_operator();
	test_calc();
}