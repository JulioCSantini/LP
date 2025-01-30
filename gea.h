// https://www.freecodecamp.org/portuguese/news/todos-os-emojis-lista-de-emojis-para-copiar-e-colar/

#ifndef __GEA__
#define __GEA__

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include "keyboard.h"
#include "constantes.h"

typedef struct{
    int mapa[ALT][LAR];
    int numVida;
    int numZumbi;
    int numMonstros;
    int numRobo;
    int tempo;
}Jogo;

Jogo tab;

int  pl=1, pc=1, ca=1, cl=1, mat[ALT][LAR], armazena=0;
int czumbi=0, cvida=0, cmons=0, crobo=0;

void menuPrincipal(int op);
void exibirMapa();
void atualizarMapa(int op);
void iniciarMapa();
void editarMapa(int);



void menuPrincipal(int op) {

    system("clear");
    printf("🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱\n");
    printf("🧱🧱🧱  BOMBERMAN 🧱🧱🧱🧱\n");
    printf("🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱\n");
    if(op == 1) { printf("🧱🧱 💣"); } else { printf("🧱🧱   "); }
    printf(" Jogar         🧱🧱\n");
    if(op == 2) { printf("🧱🧱 💣"); } else { printf("🧱🧱   "); }
    printf(" Editar Mapa   🧱🧱\n");
    if(op == 3) { printf("🧱🧱 💣"); } else { printf("🧱🧱   "); }
    printf(" Carregar Mapa 🧱🧱\n");
    if(op == 4) { printf("🧱🧱 💣"); } else { printf("🧱🧱   "); }
    printf(" Continuar Game🧱🧱\n");
    if(op == 5) { printf("🧱🧱 💣"); } else { printf("🧱🧱   "); }
    printf(" Sair          🧱🧱\n");
    printf("🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱\n");
    printf("🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱\n");
}

void exibirMapa(){
    for(int lin=0;lin<ALT;lin++){
        for(int col=0;col<LAR;col++){
            if(map[lin][col] == CAMINHO){
                EMOJI_CAMI
            }
            else if(map[lin][col] == PAREDE){
                EMOJI_PARE
            }
            else if (map[lin][col] == BOMBERMAN){
                EMOJI_BOM1
            }
            else if (map[lin][col] == VIDA){
                EMOJI_VIDA
            }
            else if (map[lin][col] == ZUMBI){
                EMOJI_ZUMB
            }
            else if (map[lin][col] == ROBO){
                EMOJI_ROBO
            }
            else if (map[lin][col] == MONSTRO){
                EMOJI_MONS
            }
        }
    }
    printf("\n VIDAS %d/3\t ZUMBIS %d/3\t MONSTROS %d/3\t ROBOS %d/3", cvida, czumbi, cmons, crobo);
}
void atualizarMapa(int mov) {
    if (mov == CIMA) {
        if (pl > 0 && map[pl - 1][pc] != PAREDE) {
            map[pl][pc] = CAMINHO;
            pl--;
            if(map[pl][pc] == VIDA){
                cvida++;
            }
            map[pl][pc] = BOMBERMAN;
        }
    } else if (mov == BAIXO) {
        if (pl < ALT - 1 && map[pl + 1][pc] != PAREDE) {
            map[pl][pc] = CAMINHO;
            pl++;
            if(map[pl][pc] == VIDA){
                cvida++;
            }
            map[pl][pc] = BOMBERMAN;
        }
    } else if (mov == ESQUERDA) {
        if (pc > 0 && map[pl][pc - 1] != PAREDE) {
            map[pl][pc] = CAMINHO;
            pc--;
            if(map[pl][pc] == VIDA){
                cvida++;
            }
            map[pl][pc] = BOMBERMAN;
        }
    } else if (mov == DIREITA) {
        if (pc < LAR - 1 && map[pl][pc + 1] != PAREDE) {
            map[pl][pc] = CAMINHO;
            pc++;
            if(map[pl][pc] == VIDA){
                cvida++;
            }
            map[pl][pc] = BOMBERMAN;
        }
    }
}

void iniciarMapa(){
    for(int i=0; i<ALT;i++){
        for(int j=0; j<LAR; j++ ){
            if(mat[i][j] == MAPA){
                EMOJI_MAPA
            }
            else if(mat[i][j]== CAMINHO){
                EMOJI_CAMI
            }
            else if (mat[i][j]== ROBO)
            {
                EMOJI_ROBO
            }
            
        }
        printf("\n");
    }
    printf("'  ' - C 🧱 - P\t🤖 - R\t👿 - M\t🧟 - Z\t🙂 - B\t💙 - V\t💾 - S\t🗑️ - EXCLUIR");
}

void editarMapa(int op){


    if (op == CIMA) {
        armazena = -1;
        if (cl > 1 && armazena == -1) {
            if(op == 67 || op == 99){
                armazena = ROBO;
                mat[cl][ca] = ROBO; 
            }
            cl--;
            mat[cl][ca] = CAMINHO;
        }
    } else if (op == BAIXO) {
        armazena = -1;
        if (cl < ALT - 2 && armazena == -1) {
            if(op == 67 || op == 99){
                armazena = ROBO;
                mat[cl][ca] = ROBO; 
            }
            cl++;
            mat[cl ][ca] = CAMINHO;
        }
    } else if (op == ESQUERDA) {
        armazena = -1;
        if (ca > 1 && armazena == -1) {
           if(op == 67 || op == 99){
                armazena = ROBO;
                mat[cl][ca] = ROBO; 
            }
            ca--;
            mat[cl][ca] = CAMINHO;
        }
    } else if (op == DIREITA) {
        armazena = -1;
        if (ca < LAR - 2 && armazena == -1) {
            if(op == 67 || op == 99){
                armazena = ROBO;
                mat[cl][ca] = ROBO; 
            }
            ca++;
            mat[cl][ca] = CAMINHO;
        }
    }else if(op == 67 || op == 99){
        armazena = ROBO;
        mat[cl][ca] = ROBO; 
    }
    printf("%d", armazena);
}

#endif