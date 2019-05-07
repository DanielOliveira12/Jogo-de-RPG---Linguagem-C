#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50
/*
int multiPlayers(char playerOne[TAM], char playerTwo[TAM], int lifeOne, int lifeTwo, int lifeCraw, char characterOne[TAM], char characterTwo[TAM]){
	printf("=========================================================\n");
	printf("        BEM VINDO AO LEAGUE OF POBRE - Orc Detestavel         \n");
	printf("=========================================================\n");
	printf("Player01: %c   Vida: %d  Classe: %c \n", playerOne, lifeOne, characterOne);
	printf("Player02: %c   Vida: %d  Classe: %c \n", playerTwo, lifeTwo, characterTwo);
	printf("INIMIGO: Crawmerax       Vida: %d \n", lifeCraw);
	printf("=========================================================\n");
}
*/
int singlePlayer(char playerOne[TAM], int lifeOne, int lifeCraw, char characterOne[TAM]){
	printf("=========================================================\n");
	printf("Player01: %c   Vida: %d classe: %c \n", playerOne, lifeOne, characterOne);
	printf("INIMIGO: Crawmerax       Vida: %d \n", lifeCraw);
	printf("=========================================================\n");
}
//int barbaro(int life, int cure, int offense, int meleeatack);
void cabecClass(void){
	printf("==================ESCOLHA SUA CLASSE:====================\n");
}
	
char *classCharacter(int classe){
	char *characOne;
	characOne = malloc(TAM*sizeof(char));
	switch(classe){
		case 3:
			strcpy(characOne, "BARBARO"); 
			break;
		case 4:
			strcpy(characOne, "ARQUEIRO"); 
			break;
		case 5:
			strcpy(characOne, "Mago"); 
			break;
		default:
			printf("Opcao invalida! \n");
	}
	return characOne;
}

int main(void){
	int op, cl;
	char playerOne[TAM], playerTwo[TAM];
	char cONE[TAM];
	printf("=========================================================\n");
	printf("        BEM VINDO AO LOP - League of Pobres              \n");
	printf("================SELECIONE UMA DAS OPCOES=================\n");
	printf("01 - Single Player\n");
	printf("02 - Multi Player");
	printf("\nEscolha: ");
	scanf("%d", &op);
	switch(op){
		case 01:
			printf("player 01 - Digite seu nome:"); 
			scanf("%s",playerOne);
			cabecClass();
			printf("03 - Barbaro \n");
			printf("04 - Arqueiro");
			printf("\n05 - Mago ");
			printf("\nEscolha: ");
			scanf("%d", &cl);		
			strcpy(cONE, classCharacter(cl));
			printf("%s : Boa escolha!\n", cONE);
			break;
		/*
		case 02: 
			printf("Player 01 - Digite seu nome: ");
			fgets(playerOne, TAM, stdin);
			printf("Player 02 - Digite seu nome: ");
			multiPlayers(playerOne, playerTwo, 100, 100, 100);
			break;
		*/
		default:
			printf("Opcao invalida \n");
		}
	
	//cONE = classCharacter();
	//singlePlayer(playerOne, 100, 100, cONE);
	return 0;
}