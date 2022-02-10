#include<stdio.h>

#define INT_MAX 2147483647

void muitos_prints()
{
    for (int i=0; i<INT_MAX; i++)
    {
        printf("%d\n", i);
    }
}

void muitas_somas()
{
    int a = 0;
    for (int i=0; i<INT_MAX; i++)
    {
        a += i;
    }
}

void muitas_multiplicacoes()
{
    int a = 0;
    for (int i=0; i<INT_MAX; i++)
    {
        a *= i;
    }
}

int main()
{
    muitos_prints();
    muitas_somas();
    muitas_multiplicacoes();
    return 0;
}
