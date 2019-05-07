#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define TAM 50
/*
void flush_in() {
    int ch;
    do {
        ch = fgets(stdin);
    } while (ch != EOF && ch != '\n');
}
*/
int multiPlayers(char playerOne[TAM], char playerTwo[TAM], int lifeOne, int lifeTwo, int lifeCraw){
	printf("=========================================================\n");
	printf("        BEM VINDO AO LEAGUE OF POBRE - Orc Detestavel         \n");
	printf("=========================================================\n");
	printf("Player01: %c   Vida: %d \n", playerOne, lifeOne);
	printf("Player02: %c   Vida: %d \n", playerTwo, lifeTwo);
	printf("INIMIGO: Crawmerax       Vida: &d \n", lifeCraw);
	printf("=========================================================\n");
}
int singlePlayer(char playerOne[TAM], int lifeOne, int lifeCraw){
	printf("=========================================================\n");
	printf("Player01: %c   Vida: %d \n", playerOne, lifeOne);
	printf("INIMIGO: Crawmerax       Vida: %d \n", lifeCraw);
	printf("=========================================================\n");
}
//int barbaro(int life, int cure, int offense, int meleeatack){}
int classCharacter(){
	int classe;
	printf("Qual sua classe?:  \n");
	printf("03 - Bar \n");
	printf("04 - Arqueiro \n");
	printf("05 - Mago \n");
	printf("Escolha: ");
	scanf("%d\n", &classe);
	switch(classe){
		case 03:break;
		case 04:break;
		case 05:break;
		default:
			printf("Opcao invalida! \n");
	}
}

int main(void){
	int op;
	char playerOne[TAM], playerTwo[TAM];

	printf("=========================================================\n");
	printf("        BEM VINDO AO FOUL BOGEY - Orc Detestavel         \n");
	printf("================SELECIONE UMA DAS OPCOES=================\n");
	printf("01 - Single Player\n");
	printf("02 - Multi Player");
	printf("\nEscolha: ");
	scanf("%d", &op);
	switch(op){
		case 01:
			printf("player 01 - Digite seu nome: \n"); 
			fgets(playerTwo, TAM, stdin);
			singlePlayer(playerOne, 100, 100);
			break;
		case 02: 
			printf("Player 01 - Digite seu nome: ");
			fgets(playerOne, TAM, stdin);
			multiPlayers(playerOne, playerTwo, 100, 100, 100);
			
			break;
		default:
			printf("Opcao invalida \n");
		}	
	classCharacter();
	return 0;
}