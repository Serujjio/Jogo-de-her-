#include <stdio.h>
#include <stdlib.h> //srand() e rand()
#include <string.h>
#include <time.h>

typedef struct {
    char nome[20];
    int vida;
    int ataque;
    int defesa;
} Heroi;

void cadastrarherois( Heroi hero[]){

    char* ch;
    srand(time(NULL));

    for (int i = 0; i < 2; i++)
    {
          printf("\nCADASTRE SEU HEROI: JOGADOR %d\n", i+1);
          printf("\n\nNome do herói: ");
          fgets(hero[i].nome,sizeof(hero[i].nome),stdin);

         if ( (ch = strchr(hero[i].nome,'\n')) != NULL)
         {
             *ch = '\0'; //limpando o \n do vetor com o nome do herói.
         }

         hero[i].vida = rand()%51 + 50;
         hero[i].ataque = rand()%21 + 10;
         hero[i].defesa = rand()%16 + 5;
          
          printf("\nVida: %d", hero[i].vida);
          printf("\n\nAtaque: %d", hero[i].ataque);
          printf("\n\nDefesa: %d", hero[i].defesa);
          printf("\n----------------------------\n");
    }
    
  
}

int main() {

    srand(time(NULL));

    Heroi heroi[2];

    cadastrarherois(heroi);

    return 0;

}