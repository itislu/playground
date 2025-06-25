/**
 * Undefined behavior. Compile with -O2.
 * Source: https://gist.github.com/shafik/848ae25ee209f698763cffee272a58f8
 */

#include <stdio.h>

int foo(float *f, int *i)
{ 
	*i = 1;
	*f = 0.f;

	return *i;
}

int main()
{
	int x = 0;

	printf("Before: %d\n", x);		// Expect 0
	int ret = foo((float *)&x, &x);
	printf("After:  %d\n", x);		// Expect 0
	printf("Return: %d\n", ret);	// Expect 0?
}
