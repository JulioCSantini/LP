#include "biblio.h"

int main(void)
{
    int i, **matriz, lin, col, pontos = 0;

    matriz = malloc(TAM * sizeof(int *));
    for (i = 0; i < TAM; i++)
    {
        matriz[i] = malloc(TAM * sizeof(int));
        memset(matriz[i], -1, TAM * sizeof(int));
    }
    montarCenario(matriz);

    for (i = 0; i < TAM; i++)
    {
        printf("\n");
        for (int j = 0; j < TAM; j++)
        {
            printf("%i ", matriz[i][j]);
        }
    }
    exibirCenario(matriz);
    for (pontos = 0; pontos < 45;)
    {
        printf("\nPontos: %i", pontos);
        printf("\nJogada: ");
        scanf("%i %i", &lin, &col);
        pontos = efetuarJogada(matriz, lin, col, pontos);
        exibirCenario(matriz);
    }
    if(pontos>=45){
        printf("\nParabens, voce ganhou!!!!!!!!!!");
    }
    free(matriz[i]);
    free(matriz);
}
