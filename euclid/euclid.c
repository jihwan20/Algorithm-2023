
int recursiveEuclid(int a, int b)
{
    if (b == 0) return a;
    return recursiveEuclid(b, a % b);
}

int repetitiveEuclid(int a, int b)
{
    int gcd;

    while (b != 0) {
        gcd = b;
        b = a % b;
        a = gcd;
    }
    return a;
}