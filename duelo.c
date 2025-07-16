#include <stdio.h>
#include <stdlib.h> //srand() e rand()
#include <string.h>
#include <time.h>

int count = 1;

typedef struct
{
    char nome[20];
    int vida;
    int ataque;
    int defesa;
} Heroi;

void cadastrarherois(Heroi hero[])
{
    char *ch;
    srand(time(NULL));

    for (int i = 0; i < 2; i++)
    {
        printf("\nCADASTRE SEU HEROI: JOGADOR %d\n", i + 1);
        printf("\n\nNome do herói: ");
        fgets(hero[i].nome, sizeof(hero[i].nome), stdin);

        if ((ch = strchr(hero[i].nome, '\n')) != NULL)
        {
            *ch = '\0'; // limpando o \n do vetor com o nome do herói.
        }

        hero[i].vida = rand() % 51 + 50;
        hero[i].ataque = rand() % 21 + 10;
        hero[i].defesa = rand() % 16 + 5;

        printf("\nVida: %d", hero[i].vida);
        printf("\n\nAtaque: %d", hero[i].ataque);
        printf("\n\nDefesa: %d", hero[i].defesa);
        printf("\n----------------------------\n");
    }
}

int rodada(Heroi *hero1, Heroi *hero2)
{

    printf("\n%s ataca o %s!\n", hero1->nome, hero2->nome);
    int dano = hero1->ataque - hero2->defesa;
    if (dano > 0)
        hero2->vida = hero2->vida - dano;

    printf("\n%s está com %d de vida!\n", hero2->nome, hero2->vida);

    if (hero2->vida <= 0)
    {
        return 1;
    }

    printf("\nAgora é a vez do %s atacar %s\n", hero2->nome, hero1->nome);
    dano = hero2->ataque - hero1->defesa;
    if (dano > 0)
        hero1->vida = hero1->vida - dano;
        
    printf("\n%s está com %d de vida!\n", hero1->nome, hero1->vida);

    if (hero1->vida <= 0)
    {
        return -1;
    }

    return 0;
}

int main()
{

    srand(time(NULL));

    Heroi heroi[2];

    cadastrarherois(heroi);

    printf("\n\n-----Inicio do Jogo-----\n\n");

    int result = 0;

    while (result == 0)
    {
        printf("\n-----Inicio da rodada %d-----\n", count);
        result = rodada(&heroi[0], &heroi[1]);
        count++;
    }

    if (result == 1)
    {
        printf("\n\n------FIM DE JOGO------");
        printf("\nO HEROI %s VENCEU COM %d DE VIDA!!!\n", heroi[0].nome, heroi[0].vida);
    }
    else if (result == -1)
    {

        printf("\n\n------FIM DE JOGO------");
        printf("\nO HEROI %s VENCEU COM %d DE VIDA!!!\n", heroi[1].nome, heroi[1].vida);
    }

    return 0;
}