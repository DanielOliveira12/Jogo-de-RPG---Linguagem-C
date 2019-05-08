#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 50

int barbaroGlobal;
int crawmeraxLifeVariavelGlobal;
char jogadorOne[TAM];
int barbaroLifeVariavelGlobal;


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

int criandoStructCrawmerax(int jogada, int crawmeraxLife){
	// Aqui eu estou criando minha struct com o nome crawmerax
	struct crawmerax{	
		int attackBody;
		int attackDistance;
		int cure;
		int life;
	};

	// Aqui eu estou criando um variavel (Crawmerax) do tipo (crawmerax)
	struct crawmerax Crawmerax;

	// Atribuindo valores as variaveis da minha struct crawmerax com a jogado 
	if(jogada == 4){
		Crawmerax.attackBody = 25;
		return 1;
	}else if(jogada == 2){
		Crawmerax.attackDistance = 13;
		return 2;
	}else if(jogada == 3){
		Crawmerax.cure = 13;
		return 3;
	}else if(jogada == 1){
		crawmeraxLifeVariavelGlobal = Crawmerax.life = crawmeraxLife;
		printf(">>>>>>>>>>>>>>%d", crawmeraxLifeVariavelGlobal);
		return crawmeraxLifeVariavelGlobal;
	}else{
		return 0;
	}

	return barbaroLifeVariavelGlobal;
}
int criandoStructBarbaro(int jogada, int barbaroLife){
	struct barbaro{
		int attackBody;
		int attackDistance;
		int cure;
		int life;
	};

	struct barbaro Barbaro;

	if(jogada == 4){
		barbaroLifeVariavelGlobal = Barbaro.attackBody=25;
		return barbaroLifeVariavelGlobal;
	
	}else if(jogada == 2){
		barbaroLifeVariavelGlobal = Barbaro.attackDistance = 13;
		return barbaroLifeVariavelGlobal;
	
	}else if(jogada == 3){
		barbaroLifeVariavelGlobal = Barbaro.cure = 13;
		return barbaroLifeVariavelGlobal;
	
	}else if(jogada == 1){
		barbaroLifeVariavelGlobal = Barbaro.life = barbaroLife;
		return barbaroLifeVariavelGlobal;
	
	}else{
		return 0;
	}
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
	int bLife;

	int rodada =1;
	char classe[TAM];
	// Estou chamando as funções para poder acessar os valores delas
	srand(time(NULL));
	while(1){
			//struct barbaro bar;
			if (rodada%2==1 || rodada%2==0){
				cabecalhoGameRun();
				printf("Qual sua jogada?\n");
				scanf("%d", &opcao);
				switch(opcao){
					case 1:
						criandoStructBarbaro(4, 220);
						criandoStructCrawmerax(1, 250);
						if(rodada == 1){
							singlePlayer(jogadorOne,220, 250,"BARBARO");
						}else{
							singlePlayer(jogadorOne,bLife, atLife,"BARBARO");
						}
						printf("\nataque base: %d\n", barbaroLifeVariavelGlobal);
						atBory = 1 + rand() % 5;
						printf("\nataque adicional: %d\n", atBory);
						atBory += barbaroLifeVariavelGlobal;

						printf("\nataque Final: %d\n", atBory);

						// Tirando vida do crawmerax de acordo com o ataque atBory
						ab += atBory;
						printf(">>>>>>%d\n",ab);
						atLife = crawmeraxLifeVariavelGlobal - ab;
						bLife = criandoStructBarbaro(1,220);
						printf(">>>>>>%d\n",bLife);
						rodada++;
					/* A cada vez que while da um loop o life do Crawmerx volta a ser 250
				 	* temos que ajeitar isso!
				 	*	
					*/
						break;
					//case 2:
					//	singlePlayer(jogadorOne,bLife, atLife,"BARBARO");
					//	printf("\nAtaque a distancia Base: %d\n", barbaroGlobal);
					/*	atBory = 1 + rand() % 5;
						printf("\nataque adicional: %d\n", atBory);
						atBory += barbaroGlobal;

						printf("\nataque Final: %d\n", atBory);

						// Tirando vida do crawmerax de acordo com o ataque atBory
						ab += atBory;
						atLife = crawmeraxLifeVariavelGlobal - ab;
						bLife = barbaroLifeVariavelGlobal;
						rodada++;
*/
				}

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