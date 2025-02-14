#include <stdio.h>
#include <stdlib.h>

void __attribute__((constructor)) func(); // Function to call before main
void __attribute__((destructor)) func(); // Function to call after main

void func(void)
{
	printf("I'm not supposed to be here\n");
	// abort();
}

int main(void)
{
	printf("MAIN\n");
}
