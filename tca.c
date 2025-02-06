#include "keyboard.h"
#include "gea.h"
#include "constantes.h"

int main() {


  int op, pmenu;

  for(int i = 0; i<ALT; i++){
    for(int j = 0; j<LAR; j++){
      tab.mapa[i][j] = PAREDE;
    }
  }
  op = 0;
  pmenu = 1;
  while(op != -1) {
    printf("teste 2\n\n\n");
    menuPrincipal(pmenu);
    // CAPTURA TECLA DIGITADA
    op = getTecla();
    if(op == BAIXO) { pmenu++; }
    else if(op == CIMA) { pmenu--; }
    // ENTER
    else if(op == ENTER) {

      switch(pmenu) {
        // JOGAR
        case 1:
            while(1){
                system("clear");
                exibirMapa();
                op = getTecla();
                atualizarMapa(op);
            }
            break;
        // EDITAR MAPA
        case 2:
          while (sair == 1){
            system("clear");
            iniciarMapa();
            op = getTecla();
            editarMapa(op);
          }
          sair = 1;
          break;
        // CARREGAR MAPA
        case 3:
            printf("7\n");
            carregarMapas(op);
            printf("8\n");
            break;
        // CONTINUAR GAME
        case 4:
            printf("CONTINUAR GAME");
            break;
        // SAIR
        case 5:
            op = -1;
            break;
      }
      if(pmenu != 5) {
        fflush(stdout);
        __fpurge(stdin);
        getchar();
      }
    }

    if(pmenu > 5) pmenu = 1;
    if(pmenu < 1) pmenu = 5;
  }

  printf("\n");
  return 0;
}

