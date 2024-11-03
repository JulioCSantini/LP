#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define TAM 7

void montarCenario(int **m);
void exibirCenario(int **m);
int efetuarJogada(int **m, int lin, int col, int pontos);
void montarCenario(int **m)
{
    int lin, col, aux;
    srand(time(NULL));
    for (aux = 0; aux < 25;)
    {
        lin = rand() % TAM;
        col = rand() % TAM;
        if (m[lin][col] == -1)
        {
            m[lin][col] = 0;
            aux++;
        }
    }
    for (aux = 0; aux < 10;)
    {
        lin = rand() % TAM;
        col = rand() % TAM;
        if (m[lin][col] == -1)
        {
            m[lin][col] = 1;
            aux++;
        }
    }
    for (aux = 0; aux < 7;)
    {
        lin = rand() % TAM;
        col = rand() % TAM;
        if (m[lin][col] == -1)
        {
            m[lin][col] = 2;
            aux++;
        }
    }
    for (aux = 0; aux < 5;)
    {
        lin = rand() % TAM;
        col = rand() % TAM;
        if (m[lin][col] == -1)
        {
            m[lin][col] = 5;
            aux++;
        }
    }
    for (aux = 0; aux < 2;)
    {
        lin = rand() % TAM;
        col = rand() % TAM;
        if (m[lin][col] == -1)
        {
            m[lin][col] = 9;
            aux++;
        }
    }
}
void exibirCenario(int **m)
{
    int i, j;
    printf("\n");
    for (i = 0; i < TAM; i++)
    {
        printf("\n");
        for (j = 0; j < TAM; j++)
        {
            if (m[i][j] < 10)
            {
                printf("🧱");
            }
            else if (m[i][j] == 11)
            {
                printf("🤍");
            }
            else if (m[i][j] == 12)
            {
                printf("💙");
            }
            else if (m[i][j] == 15)
            {
                printf("💚");
            }
            else if (m[i][j] == 19)
            {
                printf("💛");
            }
            else if (m[i][j] == 10)
            {
                printf("  ");
            }
        }
    }
}
int efetuarJogada(int **m, int lin, int col, int pontos)
{
    int i, j;
    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            if (m[i][j] == 1)
            {
                if (i == lin && j == col)
                {
                    m[i][j] = 11;
                    pontos += 1;
                }
            }
            else if (m[i][j] == 2)
            {
                if (i == lin && j == col)
                {
                    m[i][j] = 12;
                    pontos += 2;
                }
            }
            else if (m[i][j] == 5)
            {
                if (i == lin && j == col)
                {
                    m[i][j] = 15;
                    pontos += 5;
                }
            }
            else if (m[i][j] == 9)
            {
                if (i == lin && j == col)
                {
                    m[i][j] = 19;
                    pontos += 9;
                }
            }
            else if (m[i][j] == 0)
            {
                if (i == lin && j == col)
                {
                    m[i][j] = 10;
                }
            }
        }
    }
    return pontos;
}