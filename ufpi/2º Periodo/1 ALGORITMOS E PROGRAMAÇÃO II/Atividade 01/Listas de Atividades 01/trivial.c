#include <stdio.h>
int rep;
rep = 0;
int mdc(int M, int N)
{
    int resto;
    while(N != 0)
    {
        resto = M % N;
        M = N;
        N = resto;
        rep++;
    }
    return A;
}
int main()
{
    int m,n;
    scanf("%i", &m);
    scanf("%i", &n);
    printf("MDC = %i\n", mdc(m,n));
    printf("Rep = %i\n", rep);
    return 0;
}