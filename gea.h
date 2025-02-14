// https://www.freecodecamp.org/portuguese/news/todos-os-emojis-lista-de-emojis-para-copiar-e-colar/

#ifndef __GEA__
#define __GEA__

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include "keyboard.h"
#include "constantes.h"

typedef struct
{
    int mapa[ALT][LAR];
    int numVida;
    int numZumbi;
    int numMonstros;
    int numRobo;
    int numBorbeman;
    long int tempo;
} Jogo;

Jogo tab;

int pl = 1, pc = 1, ca = 1, cl = 1, mat[ALT][LAR], armazena = PAREDE, aux = 0, pos, saida;
int czumbi = 0, cvida = 0, cmons = 0, crobo = 0, cbomb = 0, sair = 1;

void menuPrincipal(int op);
void exibirMapa();
void atualizarMapa(int op);
void iniciarMapa();
void editarMapa(int);
void salvarMapa();
int condicao(int op);
int contagem(int cont);
void movimentoMonstros();
void carregarMapas(int op);

void menuPrincipal(int op)
{

    system("clear");
    printf("🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱\n");
    printf("🧱🧱🧱  BOMBERMAN 🧱🧱🧱🧱\n");
    printf("🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱\n");
    if (op == 1)
    {
        printf("🧱🧱 💣");
    }
    else
    {
        printf("🧱🧱   ");
    }
    printf(" Jogar         🧱🧱\n");
    if (op == 2)
    {
        printf("🧱🧱 💣");
    }
    else
    {
        printf("🧱🧱   ");
    }
    printf(" Editar Mapa   🧱🧱\n");
    if (op == 3)
    {
        printf("🧱🧱 💣");
    }
    else
    {
        printf("🧱🧱   ");
    }
    printf(" Carregar Mapa 🧱🧱\n");
    if (op == 4)
    {
        printf("🧱🧱 💣");
    }
    else
    {
        printf("🧱🧱   ");
    }
    printf(" Continuar Game🧱🧱\n");
    if (op == 5)
    {
        printf("🧱🧱 💣");
    }
    else
    {
        printf("🧱🧱   ");
    }
    printf(" Sair          🧱🧱\n");
    printf("🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱\n");
    printf("🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱\n");
}

void exibirMapa()
{
    for (int lin = 0; lin < ALT; lin++)
    {
        for (int col = 0; col < LAR; col++)
        {
            if (map[lin][col] == CAMINHO)
            {
                EMOJI_CAMI
            }
            else if (map[lin][col] == PAREDE)
            {
                EMOJI_PARE
            }
            else if (map[lin][col] == BOMBERMAN)
            {
                EMOJI_BOM1
            }
            else if (map[lin][col] == VIDA)
            {
                EMOJI_VIDA
            }
            else if (map[lin][col] == ZUMBI)
            {
                EMOJI_ZUMB
            }
            else if (map[lin][col] == ROBO)
            {
                EMOJI_ROBO
            }
            else if (map[lin][col] == MONSTRO)
            {
                EMOJI_MONS
            }
        }
        printf("\n");
    }
    printf("\n VIDAS %d/3\t ZUMBIS %d/3\t MONSTROS %d/3\t ROBOS %d/3", cvida, czumbi, cmons, crobo);
}
void atualizarMapa(int mov)
{
    if (mov == CIMA)
    {
        if (pl > 0 && map[pl - 1][pc] == CAMINHO || map[pl - 1][pc] == VIDA)
        {
            map[pl][pc] = CAMINHO;
            pl--;
            if (map[pl][pc] == VIDA)
            {
                cvida++;
                map[pl][pc] = BOMBERMAN;
            }
            map[pl][pc] = BOMBERMAN;
        }
    }
    else if (mov == BAIXO)
    {
        if (pl < ALT - 1 && map[pl + 1][pc] == CAMINHO || map[pl + 1][pc] == VIDA)
        {
            map[pl][pc] = CAMINHO;
            pl++;
            if (map[pl][pc] == VIDA)
            {
                cvida++;
            }
            map[pl][pc] = BOMBERMAN;
        }
    }
    else if (mov == ESQUERDA)
    {
        if (pc > 0 && map[pl][pc - 1] == CAMINHO || map[pl][pc - 1] == VIDA)
        {
            map[pl][pc] = CAMINHO;
            pc--;
            if (map[pl][pc] == VIDA)
            {
                cvida++;
                map[pl][pc] = BOMBERMAN;
            }
            map[pl][pc] = BOMBERMAN;
        }
    }
    else if (mov == DIREITA)
    {
        if (pc < LAR - 1 && map[pl][pc + 1] == CAMINHO || map[pl][pc + 1] == VIDA)
        {
            map[pl][pc] = CAMINHO;
            pc++;
            if (map[pl][pc] == VIDA)
            {
                cvida++;
                map[pl][pc] = BOMBERMAN;
            }
            map[pl][pc] = BOMBERMAN;
        }
    }
    //movimentoMonstros();
    fflush(stdout);
    __fpurge(stdin);
}

void iniciarMapa()
{
    cbomb = 0;

    for (int i = 0; i < ALT; i++)
    {
        for (int j = 0; j < LAR; j++)
        {
            if (tab.mapa[i][j] == PAREDE)
            {
                EMOJI_PARE
            }
            else if (tab.mapa[i][j] == CAMINHO)
            {
                EMOJI_CAMI
            }
            else if (tab.mapa[i][j] == ROBO)
            {
                EMOJI_ROBO
            }
            else if (tab.mapa[i][j] == CURSOR)
            {
                EMOJI_CURS
            }
            else if (tab.mapa[i][j] == ZUMBI)
            {
                EMOJI_ZUMB
            }
            else if (tab.mapa[i][j] == MONSTRO)
            {
                EMOJI_MONS
            }
            else if (tab.mapa[i][j] == BOMBERMAN)
            {
                EMOJI_BOM1
                cbomb = 1;
            }
            else if (tab.mapa[i][j] == VIDA)
            {
                EMOJI_VIDA
            }
        }
        printf("\n");
    }
    printf("'  ' - C 🧱 - P\t🤖 - R\t👿 - M\t🧟 - Z\t🙂 - B\t💙 - V\t💾 - S\t🗑️ - EXCLUIR");
}

void editarMapa(int op)
{

    aux = contagem(BOMBERMAN);

    if (op == CIMA)
    {
        if (cl > 1)
        {
            tab.mapa[cl][ca] = armazena;
            cl--;
            armazena = tab.mapa[cl][ca];
            tab.mapa[cl][ca] = CURSOR;
        }
    }

    else if (op == BAIXO)
    {
        if (cl < ALT - 2)
        {

            tab.mapa[cl][ca] = armazena;
            cl++;
            armazena = tab.mapa[cl][ca];
            tab.mapa[cl][ca] = CURSOR;
        }
    }

    else if (op == ESQUERDA)
    {
        if (ca > 1)
        {
            tab.mapa[cl][ca] = armazena;
            ca--;
            armazena = tab.mapa[cl][ca];
            tab.mapa[cl][ca] = CURSOR;
        }
    }

    else if (op == DIREITA)
    {
        if (ca < LAR - 2)
        {
            tab.mapa[cl][ca] = armazena;
            ca++;
            armazena = tab.mapa[cl][ca];
            tab.mapa[cl][ca] = CURSOR;
        }
    }
    else if (op == 115 || op == 83)
    {
        salvarMapa();
    }
    else
    {
        aux = condicao(op);
        if (aux != -1)
        {
            armazena = aux;
        }
    }
}

int condicao(int op)
{
    if (op == 67 || op == 99)
    {
        return CAMINHO;
    }
    if (op == 80 || op == 112)
    {
        return PAREDE;
    }
    if (op == 114 || op == 82)
    {
        return ROBO;
    }
    if (op == 77 || op == 109)
    {
        return MONSTRO;
    }
    if (op == 122 || op == 90)
    {
        return ZUMBI;
    }
    if (op == 66 || op == 98)
    {
        if (cbomb < 1)
        {
            cbomb = 1;
            return BOMBERMAN;
        }
        return -1;
    }
    if (op == 86 || op == 118)
    {
        cvida++;
        return VIDA;
    }
    
    return -1;
}

void salvarMapa()
{
    system("clear");
    printf("🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱\n");
    printf("🧱🧱  QUANTO  TEMPO  DESEJA?  🧱🧱\n");
    printf("🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱\n");
    printf("🧱🧱 DIGITE AQUI EM SEGUNDOS: 🧱🧱\n");
    printf("🧱🧱 👉  ");
    scanf("%li", &tab.tempo);

    FILE *mapinhas = fopen("mapas.bin", "a+");

    tab.numVida = contagem(VIDA);
    tab.numMonstros = contagem(MONSTRO);
    tab.numRobo = contagem(ROBO);
    tab.numZumbi = contagem(ZUMBI);

    fwrite(&tab, sizeof(Jogo), 1, mapinhas);
    fclose(mapinhas);

    for (int i = 0; i < ALT; i++)
    {
        for (int j = 0; j < LAR; j++)
        {
            tab.mapa[i][j] = PAREDE;
        }
    }
    ca = 1;
    cl = 1;
    sair = 0;
}
int contagem(int cont)
{
    aux = 0;
    for (int i = 0; i < ALT; i++)
    {
        for (int j = 0; j < LAR; j++)
        {
            if (tab.mapa[i][j] == cont)
            {
                aux++;
            }
        }
    }
    return aux;
}

void movimentoMonstros()
{
    srand(time(NULL));
    for (int i = 0; i < ALT; i++)
    {
        for (int j = 0; j < LAR; j++)
        {
            int dire = -1;
            if (map[i][j] == ZUMBI)
            {
                if (map[i + 1][j] == CAMINHO || map[i - 1][j] == CAMINHO || map[i][j + 1] == CAMINHO || map[i][j - 1] == CAMINHO)
                {

                    saida = 0;

                    while (saida == 0)
                    {

                        dire = rand() % 4;

                        if (dire == 0 && map[i - 1][j] == CAMINHO)
                        {
                            map[i - 1][j] = ZUMBI;
                            map[i][j] = CAMINHO;
                            saida = 1;
                        }
                        else if (dire == 1 && map[i + 1][j] == CAMINHO)
                        {
                            map[i + 1][j] = ZUMBI;
                            map[i][j] = CAMINHO;
                            saida = 1;
                        }
                        else if (dire == 2 && map[i][j - 1] == CAMINHO)
                        {
                            map[i][j - 1] = ZUMBI;
                            map[i][j] = CAMINHO;
                            saida = 1;
                        }
                        else if (dire == 3 && map[i][j + 1] == CAMINHO)
                        {
                            map[i][j + 1] = ZUMBI;
                            map[i][j] = CAMINHO;
                            saida = 1;
                        }
                    }
                }
            }
            /*if(map[i][j] == MONSTRO){
                if (dire == 0)
                {
                    map[i - 1][j] = MONSTRO;
                    map[i][j] = CAMINHO;
                }
                else if(dire == 1)
                {
                    map[i + 1][j] = MONSTRO;
                    map[i][j] = CAMINHO;
                }
                else if(dire == 2)
                {
                    map[i][j - 1] = MONSTRO;
                    map[i][j] = CAMINHO;
                }
                else if(dire == 3)
                {
                    map[i][j + 1] = MONSTRO;
                    map[i][j] = CAMINHO;
                }
            }
            if(map[i][j] == ROBO){
                if (dire == 0 && map[i - 1][j] == CAMINHO)
                {
                    map[i - 1][j] = ROBO;
                    map[i][j] = CAMINHO;
                }
                else if(dire == 1 && map[i + 1][j] == CAMINHO)
                {
                    map[i + 1][j] = ROBO;
                    map[i][j] = CAMINHO;
                }
                else if(dire == 2 && map[i][j - 1] == CAMINHO)
                {
                    map[i][j - 1] = ROBO;
                    map[i][j] = CAMINHO;
                }
                else if(dire == 3 && map[i][j + 1] == CAMINHO)
                {
                    map[i][j + 1] = ROBO;
                    map[i][j] = CAMINHO;
                }
            }*/
        }
        fflush(stdout);
        __fpurge(stdin);
    }
}
void carregarMapas(int op){
    printf("6\n");

    Jogo mapas[100];
    int i = 0, socorro = 1;

    FILE *mapinhas = fopen("mapas.bin", "r");
    rewind(mapinhas);

    if(mapinhas != NULL){
        socorro = fread(&mapas, sizeof(Jogo), 5, mapinhas);
        printf("%i\n", i);
        i++;
        
        //printf("4\n");
        for(int g = 0; g < 3; g++){
            cbomb = 0;

            for (int i = 0; i < ALT; i++)
            {
                for (int j = 0; j < LAR; j++)
                {
                    if (mapas[g].mapa[i][j] == PAREDE)
                    {
                        EMOJI_PARE
                    }
                    else if (mapas[g].mapa[i][j] == CAMINHO)
                    {
                        EMOJI_CAMI
                    }
                    else if (mapas[g].mapa[i][j] == ROBO)
                    {
                        EMOJI_ROBO
                    }
                    else if (mapas[g].mapa[i][j] == CURSOR)
                    {
                        EMOJI_CURS
                    }
                    else if (mapas[g].mapa[i][j] == ZUMBI)
                    {
                        EMOJI_ZUMB
                    }
                    else if (mapas[g].mapa[i][j] == MONSTRO)
                    {
                        EMOJI_MONS
                    }
                    else if (mapas[g].mapa[i][j] == BOMBERMAN)
                    {
                        EMOJI_BOM1
                        cbomb = 1;
                    }
                    else if (mapas[g].mapa[i][j] == VIDA)
                    {
                        EMOJI_VIDA
                    }
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("%i",mapas[1].numRobo);
    }

}

#endif
