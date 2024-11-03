#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>



double pitagoras(int co, int ca);

int main(void)
{

    int co, ca;
    double hip;

    printf("Catetos: ");
    scanf("%i %i", &co, &ca);

    hip=pitagoras(co, ca);
    
    printf("Hipotenusa: %.2lf", hip);
}
double pitagoras(int co, int ca)
{
    double hip=pow(co,2)+pow(ca,2);

    return sqrt(hip);
}