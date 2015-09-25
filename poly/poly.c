#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "error.h"
#include "poly.h"

struct poly_t {
	int i;
};

poly_t* new_poly_from_string(const char* a)
{
	poly_t* t = NULL;
	return t;
}

void free_poly(poly_t* p)
{
}

poly_t* mul(poly_t* p0, poly_t* p1)
{
	poly_t* t = NULL;
	return t;
}

void print_poly(poly_t* p)
{
}

// int main()
// {
// 	new_poly_from_string(NULL);
// 	free_poly(NULL);
// 	mul(NULL, NULL);
// 	print_poly(NULL);
// 	return 0;
// }