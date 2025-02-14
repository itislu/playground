#include <stdio.h>
#include <limits.h>

static void ub1(int argc, char *argv[]);
static void ub2(int argc, char* argv[]);
static void ub3(void);

int main(int argc, char* argv[])
{
    ub1(argc, argv);
    printf("\n");
    ub2(argc, argv);
    printf("\n");
    ub3();
}

static void ub1(int argc, char *argv[])
{
    int i = (int)(2147483648.f); // undefined behavior visible at compile time
    printf("%d\n", i); // clang happens to print address of main because previous line was fully ignored
    printf("%d - main\n", (int)(long)&main);
}

static void ub2(int argc, char* argv[])
{
    printf("%d\n", (int)(2147483648.f)); // clang happens to print address to argv
    printf("%d - argv\n", (int)(long)argv);
}

/* 
"If a converted result is larger than the maximum signed doubleword integer, 
the floating-point invalid exception is raised. If this exception is masked, 
the indefinite integer value (80000000H or 80000000_00000000H if operand size is 64 bits) 
is returned."
https://www.felixcloutier.com/x86/cvttss2si
*/
static void ub3(void)
{
    int i = INT_MAX;

    float f = i; // Gets rounded to 2147483648.f because of floating point precision
    printf("float: %.1f\n", f);
    printf("int:   %d\n", (int)f); // undefined behavior

    f += 1000;
    printf("float: %.1f\n", f); // float changed
    printf("int:   %d\n", (int)f); // same int
}
