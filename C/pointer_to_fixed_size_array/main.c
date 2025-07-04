#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Pointer to fixed size array as parameter type
 */
void f(uint32_t (*arr)[1000])
{
    printf("%zu\n", sizeof(*arr));
    (*arr)[900] = 5;

    printf("%p\n", arr);
    printf("%p\n", *arr);
}

/**
 * Pointer to fixed size array as return type
 * Source: https://stackoverflow.com/a/20570097/24880406
 */
int (*get_row(int i))[10] // yes, really
{
    static int rows[5][10];
    return &rows[i % 5];
}

int main()
{
    uint32_t arr[1000] = {4, 2};
    // 1. Decays into uint32_t*.
    // 2. Inside f(), uint32_t* is the same address value as pointer to first element of array of fixed size.
    f(arr);
    printf("%d, %d\n", arr[0], arr[900]);

    // Conversion from int* to int (*)[10] is possible.
    // Seemingly "dereferences twice".
    // Highlights difference between dereference (* operator) and indexing ([] operator).
    int *p = calloc(10, sizeof(int));
    int (*p2)[10] = p;
    p[1] = 2;
    printf("%d\n", (*p2)[1]);

    int (*ret)[11] = get_row(0);
}
