#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 50

int barbaroGlobal;
int crawmeraxLifeVariavelGlobal;


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
		crawmeraxLifeVariavelGlobal = Crawmerax.attackBody = 25;
		return crawmeraxLifeVariavelGlobal;

	}else if(jogada == 2){
		crawmeraxLifeVariavelGlobal = Crawmerax.attackDistance = 13;
		return crawmeraxLifeVariavelGlobal;

	}else if(jogada == 3){
		crawmeraxLifeVariavelGlobal = Crawmerax.cure = 13;
		return crawmeraxLifeVariavelGlobal;

	}else if(jogada == 1){
		crawmeraxLifeVariavelGlobal = Crawmerax.life = crawmeraxLife;
		printf("Crawmerax(Vida): %d\n", crawmeraxLifeVariavelGlobal);
		return crawmeraxLifeVariavelGlobal;

	}else{
		return 0;
	}
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

int gameRun(){
	int opcao=0;
	int atBory;
	int atDistance;
	int atCure;
	int crawLife = 250;
	int rodadas = 1;
	// Estou chamando as funções para poder acessar os valores delas
	criandoStructBarbaro();
	srand(time(NULL));

	while(1){
		if (crawLife <= 0){
			printf("==================	CAMPO DE BATALHA  ====================\n");
			printf("Parabens voce Crawmerax\n");
			crawLife = 0;
			break;
		}else{
			if(rodadas % 2 == 1){
				cabecalhoGameRun();

				printf("Qual sua jogada?\n");
				scanf("%d", &opcao);

				switch(opcao){
					case 1:
						atBory = 1 + rand() % 6;
						atBory += barbaroGlobal;

						criandoStructCrawmerax(1, crawLife);
						crawLife = crawmeraxLifeVariavelGlobal - atBory;
						printf("\nAtaque do Barbaro: %d\n", atBory);	

				}
			}else{
				printf("Espere Crawmerax fazer sua jogada...\n");
				opcao = 1+rand()%3;
				switch(opcao){
					case 1:
						criandoStructCrawmerax(4, crawLife);
						printf(">>>>>>> Crawmerax(life): %d\n", crawLife);
						atBory = 1 + rand() % 6;
						atBory += crawmeraxLifeVariavelGlobal;
						printf(">>>>>>> Crawmerax(Dano): %d\n", atBory);

						// Falta adicionar o dano na vida do barbaro
						break;
					case 2:
						criandoStructCrawmerax(2, crawLife);
						printf(">>>>>>> Crawmerax(life): %d\n", crawLife);
						atDistance = 1 + rand() % 6;
						atDistance += crawmeraxLifeVariavelGlobal;
						printf(">>>>>>> Crawmerax(Dano): %d\n", atDistance);

						// Falta adicionar o dano na vida do barbaro
						break;
					case 3:
						criandoStructCrawmerax(3, crawLife);
						printf(">>>>>>> Crawmerax(life): %d\n", crawLife);
						atCure = 1 + rand() % 4;
						atCure += crawmeraxLifeVariavelGlobal;
						crawLife += atCure;
						printf(">>>>>>> Crawmerax(Cura): %d\n", atCure);
						printf(">>>>>>> Crawmerax(Curado): %d\n", crawLife);

						// Falta adicionar o dano na vida do barbaro
						break;



				}
			}
			
		}
		rodadas++;
	}
}
//
char *classCharacter(int classe){
	char *characOne;
	characOne = malloc(TAM*sizeof(char));
	switch(classe){
		case 01:
			strcpy(characOne, "BARBARO");
			break;
		case 02:
			strcpy(characOne, "ARQUEIRO"); 
			break;
		case 03:
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

			cabecClass(); // Chamando as classes/invocadores
			
			printf("\nEscolha: ");
			scanf("%d", &cl); // Armazenando o invocador

			strcpy(cONE, classCharacter(cl));
			printf("%s : Boa escolha!\n", cONE);

			gameRun();// Executando o jogo em single player 
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