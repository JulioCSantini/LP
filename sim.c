#include <stdio.h>
#include <stdlib.h>

int main() {

    int fim=0, valida, jogador=1;
    char a,b,c,d,e,f,g,h,i,x;
    a = b = c = d = e = f = g = h = i = ' ';
    char jogada;

    while (fim==0)
    {

        system("clear");	
        printf ("🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱");
        printf ("\n🧱🧱🧱🧱🧱🧱  JOGO DA VELHA 🧱🧱🧱🧱🧱🧱");	
        printf ("\n🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱");
        printf ("\n");   
        printf ("\n               🇦 🧱🇧 🧱🇨 ");      
        printf ("\n               🧱🧱🧱🧱🧱   ");            
        printf ("\n               🇩 🧱🇪 🧱🇫 ");                
        printf ("\n               🧱🧱🧱🧱🧱   ");             
        printf ("\n               🇬 🧱🇭 🧱🇮 ");              
        printf ("\n");              
        printf ("\n               ");
        if(a == ' ') printf(" "); else if(a == 'O') printf("🔴"); else printf("⚪");
        printf (" 🧱 ");
        if(b == ' '); else if(b == 'O') printf("🔴"); else printf("⚪");
        printf(" 🧱 ");
        if(c == ' '); else if(c == 'O') printf("🔴"); else printf("⚪");
        printf ("\n               🧱🧱🧱🧱🧱");
        printf ("\n               ");
        if(d == ' ') printf(" "); else if(d == 'O') printf("🔴"); else printf("⚪");
        printf (" 🧱 ");
        if(e == ' '); else if(e == 'O') printf("🔴"); else printf("⚪");
        printf(" 🧱 ");
        if(f == ' '); else if(f == 'O') printf("🔴"); else printf("⚪");
        printf ("\n               🧱🧱🧱🧱🧱");
        printf ("\n               ");
        if(g == ' ') printf(" "); else if(g == 'O') printf("🔴"); else printf("⚪");
        printf (" 🧱 ");
        if(h == ' '); else if(h == 'O') printf("🔴"); else printf("⚪");
        printf(" 🧱 ");
        if(i == ' '); else if(i == 'O') printf("🔴"); else printf("⚪");
        printf ("\n\n🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱");
        printf ("\n Jogador 01-> [🔴]    Jogador 02-> [⚪]");
        printf ("\n🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱");
        printf("\n Jogada > ");
        __fpurge(stdin);
        scanf("%c", &jogada);

        valida = 0;
        if(jogada == 'a' && a == ' ') {
            if(jogador == 1) a = 'O';
            else a = 'X';
            valida = 1;
        }
        else if(jogada == 'b' && b == ' ') {
            if(jogador == 1) b = 'O';
            else b = 'X';
            valida = 1;
        }
        else if(jogada == 'c' && c == ' ') {
            if(jogador == 1) c = 'O';
            else c = 'X';
            valida = 1;
        }   
        else if(jogada == 'd' && d == ' ') {
            if(jogador == 1) d = 'O';
            else d = 'X';
            valida = 1;
        }
        else if(jogada == 'e' && e == ' ') {
            if(jogador == 1) e = 'O';
            else e = 'X';
            valida = 1;
        }   
        else if(jogada == 'f' && f == ' ') {
            if(jogador == 1) f = 'O';
            else f = 'X';
            valida = 1;
        }   
        else if(jogada == 'g' && g == ' ') {
            if(jogador == 1) g = 'O';
            else g = 'X';
            valida = 1;
        }   
        else if(jogada == 'h' && h == ' ') {
            if(jogador == 1) h = 'O';
            else h = 'X';
            valida = 1;
        }   
        else if(jogada == 'i' && i == ' ') {
            if(jogador == 1) i = 'O';
            else i = 'X';
            valida = 1;
        }   

        // Mudo o jagador
        if(valida == 1) {
            // Vitória Jogador 1
            if(jogador == 1) {
                if(
                    (a == 'O' && b == 'O' && c == 'O') ||
                    (d == 'O' && e == 'O' && f == 'O') ||
                    (g == 'O' && h == 'O' && i == 'O') ||
                    (a == 'O' && d == 'O' && g == 'O') ||
                    (b == 'O' && e == 'O' && h == 'O') ||
                    (c == 'O' && f == 'O' && i == 'O') ||
                    (c == 'O' && e == 'O' && g == 'O') ||
                    (a == 'O' && e == 'O' && i == 'O')
                ) {
                    printf("\n\nJogador 1 Venceu!!");
                    fim = 1;
                    break;
                }
                jogador = 2;
            }
            // Vitória Jogador 2
            else {
                if(
                    (a == 'X' && b == 'X' && c == 'X') ||
                    (d == 'X' && e == 'X' && f == 'X') ||
                    (g == 'X' && h == 'X' && i == 'X') ||
                    (a == 'X' && d == 'X' && g == 'X') ||
                    (b == 'X' && e == 'X' && h == 'X') ||
                    (c == 'X' && f == 'X' && i == 'X') ||
                    (c == 'X' && e == 'X' && g == 'X') ||
                    (a == 'X' && e == 'X' && i == 'X')
                ) {
                    printf("\n\nJogador 2 Venceu!!");
                    fim = 1;
                    break;
                }
                jogador = 1;
            }

            // Velha
            if( a != ' ' && b != ' ' && c != ' ' &&
                d != ' ' && e != ' ' && f != ' ' &&
                g != ' ' && h != ' ' && i != ' ') 
            {

                printf("\n\nDeu velha!!");
                fim = 1;
            }
        }
    }

    printf("\n");

    return 0;
}