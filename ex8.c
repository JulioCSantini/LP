#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

double fatorial(int num);

int main(void)
{
    int num;
    double fat;

    printf("Valor: ");
    scanf("%i", &num);

    fat = fatorial(num);

    printf("Fatorial: %.2lf", fat);
}
double fatorial(int num)
{

    double fat = 1;
    for (int i = num; i > 1; i--)
    {
        fat *= i;
    }

    return fat;
}