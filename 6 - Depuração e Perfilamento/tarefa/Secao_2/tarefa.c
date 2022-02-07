#include<stdio.h>

int main()
{
    int numero = 1;
    for (int i=0; i<100; i++) {
        numero = (numero * i) % 100;
        if (numero == 0)
            numero = 1;
    }
    printf("%d", numero);
    return 0;
}
