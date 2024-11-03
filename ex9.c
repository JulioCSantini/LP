#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void alfabetica(char letras[5]);

int main(void)
{
   char letras[5];
    printf("Letras: ");
    gets(letras);
    alfabetica(letras);
    printf("Ordenado: %s\n", letras);

}

void alfabetica(char letras[5])
{
    char aux;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (letras[i] < letras[j])
            {
                aux = letras[i];
                letras[i] = letras[j];
                letras[j] = aux;
            }
        }
    }

}