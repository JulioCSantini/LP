#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void bhaskara(int a, int b, int c, double *r1, double *r2);

int main(void)
{

    int a, b, c;
    double r1, r2;

    printf("Coeficientes: ");
    scanf("%i %i %i", &a, &b, &c);

    bhaskara(a, b, c, &r1, &r2);
    printf("Raizes: %.2lf, %.2lf", r1, r2);
}
void bhaskara(int a, int b, int c, double *r1, double *r2)
{

    int delta;

    delta = pow(b, 2) - 4 * a * c;

    *r1 = (-b + sqrt(delta)) / 2 * a;
    *r2 = (-b - sqrt(delta)) / 2 * a;
}
