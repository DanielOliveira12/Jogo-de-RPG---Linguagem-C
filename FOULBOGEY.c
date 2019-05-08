#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 50

int barbaroGlobal;
int crawmeraxLifeVariavelGlobal;
char jogadorOne[TAM];


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
	printf("\n=========================================================\n");
	printf("Player01: %s   Vida: %d classe: %s \n", playerOne, lifeOne, characterOne);
	printf("INIMIGO: Crawmerax       Vida: %d \n", lifeCraw);
	printf("=========================================================\n");
}
//int barbaro(int life, int cure, int offense, int meleeatack);
void cabecClass(void){
	printf("==================ESCOLHA SUA CLASSE:====================\n");
	printf("01 - Barbaro \n");
	printf("02 - Arqueiro");
	printf("\n03 - Mago ");
}

void cabecalhoGameRun(){
	printf("==================	CAMPO DE BATALHA INICIADO ====================\n");
	printf("01 - Ataque Corpo a Corpo \n");
	printf("02 - Ataque a Distancia");
	printf("\n03 - Cura ");
}
char *classCharacter(int classe);
// Criando as struct para cada class BARBARO, ARQUEIRO, MAGO E CHEFÃO
/*
struct arqueiro{
	char nameArqueiro[TAM];
	int attackBody = 18;
	int attackDistance = 22;
	int cure = 17;
	int life = 200;
};

struct mago{
	char nameMago[TAM];
	int attackBody = 16;
	int attackDistance = 18;
	int cure = 20;
	int life = 180;
};
*/

int criandoStructCrawmerax(){
	// Aqui eu estou criando minha struct com o nome crawmerax
	struct crawmerax{	
		int attackBody;
		int attackDistance;
		int cure;
		int life;
	};

	// Aqui eu estou criando um variavel (Crawmerax) do tipo (crawmerax)
	struct crawmerax Crawmerax;

	// Atribuindo valores as variaveis da minha struct crawmerax 
	Crawmerax.attackBody = 25;
	Crawmerax.attackDistance = 13;
	Crawmerax.cure = 13;
	crawmeraxLifeVariavelGlobal = Crawmerax.life = 250;

	return crawmeraxLifeVariavelGlobal;
}
int criandoStructBarbaro(){
	struct barbaro{
		int attackBody;
		int attackDistance;
		int cure;
		int life;

	};

	struct barbaro Barbaro;

	barbaroGlobal = Barbaro.attackBody = 21;
	Barbaro.attackDistance = 15;
	Barbaro.cure = 17;
	Barbaro.life = 220;

	return barbaroGlobal;
}

/* A batalha rola nessa função gameRun()
* Aqui vai ser a funçao onde o usuario escolheram os ataque 
* e aqui tambem a gente pode calcular os danos igual eu fiz ali :D
*/

char *classCharacter(int classe){
	char *characOne;
	characOne = malloc(TAM*sizeof(char));
	switch(classe){
		case 01:
			strcpy(characOne, "BARBARO");
			printf("player 01 - Digite seu nome:"); 
			scanf("%s",jogadorOne);
			break;
		case 02:
			strcpy(characOne, "ARQUEIRO");
			printf("player 01 - Digite seu nome:"); 
			scanf("%s",jogadorOne); 
			break;
		case 03:
			strcpy(characOne, "Mago");
			printf("player 01 - Digite seu nome:"); 
			scanf("%s",jogadorOne); 
			break;
		default:
			printf("Opcao invalida! \n");
	}
	return characOne;
}
int gameRun(){
	int opcao;
	int atBory;
	int atDistance;
	int atCure;
	int atLife;
	int ab = 0;
	int rodada =1;
	char classe[TAM];
	// Estou chamando as funções para poder acessar os valores delas
	criandoStructBarbaro();
	criandoStructCrawmerax();

	while(1){
		cabecalhoGameRun();
		//struct barbaro bar;
		
		printf("Qual sua jogada?\n");
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
				srand(time(NULL));
				if(rodada == 1){
					printf(">>>>>>>%s", jogadorOne);
					singlePlayer(jogadorOne,200, 250,"BARBARO");
				}else{
					singlePlayer(jogadorOne,200, atLife, "BARBARO");
				}
				printf("\nataque base: %d\n", barbaroGlobal);
				atBory = 1 + rand() % 6;
				printf("\nataque rand: %d\n", atBory);
				atBory += barbaroGlobal;

				printf("\nataque Final: %d\n", atBory);

				// Tirando vida do crawmerax de acordo com o ataque atBory
				ab += atBory;
				atLife = crawmeraxLifeVariavelGlobal - ab;
				rodada++;


				/* A cada vez que while da um loop o life do Crawmerx volta a ser 250
				 * temos que ajeitar isso!
				 *	
				*/

		}

	}
}


int main(void){
	int op, cl;
	char playerOne[TAM], playerTwo[TAM];
	char classONE[TAM];
	printf("=========================================================\n");
	printf("        BEM VINDO AO LOP - League of Pobres              \n");
	printf("================SELECIONE UMA DAS OPCOES=================\n");
	printf("01 - Single Player\n");
	printf("02 - Multi Player");
	printf("\nEscolha: ");
	scanf("%d", &op);
	switch(op){
		case 01:			
			cabecClass(); // Chamando as classes/invocadores
			 // Armazenando o invocador
			printf("\nEscolha: ");
			scanf("%d", &cl);
			strcpy(classONE, classCharacter(cl));
			printf("%s : Boa escolha! %s \n", classONE, jogadorOne);
			gameRun(); 
			
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