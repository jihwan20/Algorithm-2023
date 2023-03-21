#include <stdio.h>

int euclid(int a, int b)
{
    // If (b=0) return a
    if (b == 0) return a;
    // return Euclid(b, a mod b)
    return euclid(b, a % b);
}

int test_euclid()
{
    int gcd = 0;

    gcd = euclid(34, 48);
    printf("Hello World! %d \n", gcd);

    return 0;
}

int main(int argc, char* argv[])
{
    test_euclid();
}