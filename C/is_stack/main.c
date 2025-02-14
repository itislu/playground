#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static int g;

// Stupid way to guess if an address is on the stack or heap
bool is_stack(void *ptr)
{
    int a;
    int b;

    if (&a < &b) {
        return (ptr < (void*)&a);
    }
    else {
        return (ptr > (void*)&a);
    }
}

int main(int argc, char *argv[])
{
	void *stack = &argc;
	void *heap = malloc(100);
	void *global = &g;

	if (is_stack(stack)) {
		printf("Correct, %p is stack!\n", stack);
	}
	else {
		printf("Incorrect, %p is not heap!\n", stack);
	}

	if (is_stack(heap)) {
		printf("Incorrect, %p is not stack!\n", heap);
	}
	else {
		printf("Correct, %p is heap!\n", heap);
	}

	if (is_stack(global)) { // Incorrect
		printf("Correct, %p is stack!\n", global);
	}
	else {
		printf("Incorrect, %p is not heap!\n", global);
	}

	free(heap);
}
