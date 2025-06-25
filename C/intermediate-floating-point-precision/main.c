/**
 * Source: https://randomascii.wordpress.com/2012/03/21/intermediate-floating-point-precision/
 */

#include <stdio.h>

static void DemoOfDanger()
{
    const float three = 3.0F;
    const float seven = 7.0F;

	const float calc = three / seven;
	if (calc == three / seven) {
		printf("They're equal!\n");
	}
	else {
		printf("They're not equal!\n");
	}
}

int main() 
{ 
    DemoOfDanger();
}
