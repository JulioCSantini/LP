#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define N 10

void ordenar(int *v);

int main(void)
{
    int v[N], i;
    printf("Aleatorio: ");
    for (i = 0; i < N; i++)
    {
        v[i] = rand() % 90 + 10;
        printf("%i ", v[i]);
    }
    ordenar(v);
}

void ordenar(int *v)
{
    int i, j, aux;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    printf("\nOrdenado: ");
    for (i = 0; i < N; i++)
    {
        printf("%i ", v[i]);
    }
}