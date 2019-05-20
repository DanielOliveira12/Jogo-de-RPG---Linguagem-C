#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 50

int barbaroGlobal;
int crawmeraxLifeVariavelGlobal;
char jogadorOne[TAM];
int barbaroLifeVariavelGlobal;
char classInvocadorVariavelGlobal[TAM];

void delay(int numberSeconds){ 
    // Convertendo o tempo em mili segundos
    int milliSeconds = 1000 * numberSeconds; 
  
    // Iniciando o tempo
    clock_t startTime = clock(); 
  
    // Fazendo loop até o tempo necessario não for alcançado 
    while (clock() < startTime + milliSeconds);
}

void clear(){
	system("cls");
}

int singlePlayer(char playerOne[TAM], int lifeOne, int lifeCraw, char characterOne[TAM], int rodada){
	printf("\n================================== PLACAR - FOULBOGEY ==================================\n");
	printf("+																						  \n");
	printf("+	Player01: %s 		Vida: %d 		Invocador: %s \n", playerOne, lifeOne, characterOne);
	printf("+																						  \n");
	printf("+	Inimigo: Crawmerax 		Vida: %d  		Rodada: %d\n", lifeCraw, rodada);
	printf("+																						  \n");
	printf("========================================================================================\n");
}
//int barbaro(int life, int cure, int offense, int meleeatack);
void cabecClass(void){
	printf("\n================== ESCOLHA SEU INVOCADOR ====================\n");
	printf("01 - Barbaro \n");
	printf("02 - Arqueiro");
	printf("\n03 - Mago ");
}

void cabecalhoGameRun(){
	printf("\n=============== CAMPO DE BATALHA INICIADO =================\n");
	printf("01 - Ataque Corpo a Corpo \n");
	printf("02 - Ataque a Distancia");
	printf("\n03 - Cura ");
}
char *classCharacter(int classe);
// Criando as struct para cada class BARBARO, ARQUEIRO, MAGO E CHEFÃO

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
		return crawmeraxLifeVariavelGlobal;
	}else{
		return 0;
	}
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
	int randValueAttack;
	int atDistance;
	int atCure;
	int crawmeraxLife=250;
	int ab=0, ad = 0, ac=0;
	int barbaroLife = 220;

	int dano = 0;
	int rodada =1;
	char classe[TAM];
	// Estou chamando as funções para poder acessar os valores delas
	srand(time(NULL));
	while(barbaroLife > 0 || crawmeraxLife > 0){
		if (rodada%2==1){
			cabecalhoGameRun();
			printf("\nQual sua jogada?\n");
			scanf("%d", &opcao);
			delay(1);
			clear();
			switch(opcao){
				case 1:
					criandoStructBarbaro(4, barbaroLife);
					criandoStructCrawmerax(1, crawmeraxLife);
					if(rodada == 1){
						singlePlayer(jogadorOne, barbaroLife, 250, classInvocadorVariavelGlobal, rodada);
					}else{
						singlePlayer(jogadorOne,barbaroLife, crawmeraxLife, classInvocadorVariavelGlobal, rodada);
					}
					printf("\n%s: Ataque Base %d\n", classInvocadorVariavelGlobal, barbaroLifeVariavelGlobal);
					atBory = 1+ rand() % 3;
					printf("\n%s: Ataque Adicional +%d\n", classInvocadorVariavelGlobal, atBory);
					atBory += barbaroLifeVariavelGlobal;

					printf("\n%s: Ataque Final %d\n", classInvocadorVariavelGlobal, atBory);

					// Tirando vida do crawmerax de acordo com o ataque atBory
					crawmeraxLife -= atBory;
					barbaroLife = criandoStructBarbaro(1, barbaroLife);
					rodada++;
					break;
				case 2:
					criandoStructBarbaro(2, barbaroLife);
					criandoStructCrawmerax(1, crawmeraxLife);
					singlePlayer(jogadorOne,barbaroLife, crawmeraxLife, classInvocadorVariavelGlobal, rodada);
					printf("\n %s: Ataque base %d\n", classInvocadorVariavelGlobal, barbaroLifeVariavelGlobal);
					randValueAttack = rand() % 2;
					if(randValueAttack == 0){ // Validando se o ataque vai somar ou subtrair do ataque base
						atDistance = rand() % 4;
						atDistance *= (-1);
					}else{
						atDistance = rand() % 4;
					}
					printf("\n %s ataque adicional +%d \n", classInvocadorVariavelGlobal, atDistance);
					atDistance +=barbaroLifeVariavelGlobal;
					printf("\n %s: Ataque final %d \n", classInvocadorVariavelGlobal, atDistance);
					
					crawmeraxLife -= atDistance;
					barbaroLife = criandoStructBarbaro(1, barbaroLife);
					rodada++;
					break;
				case 3:
					criandoStructBarbaro(3, barbaroLife);
					criandoStructCrawmerax(1, crawmeraxLife);
					singlePlayer(jogadorOne,barbaroLife, crawmeraxLife, classInvocadorVariavelGlobal, rodada);
					printf("\n %s: Vida %d \n", classInvocadorVariavelGlobal, barbaroLife);

					atCure =1+rand()%3;
					atCure += barbaroLifeVariavelGlobal;
					printf("\n %s: Cura +%d \n", classInvocadorVariavelGlobal, atCure);
					barbaroLife += atCure;// Somando o valor da cura a vida do barbaro
					printf("\n %s: Vida %d \n", classInvocadorVariavelGlobal, barbaroLife);

					barbaroLife = criandoStructBarbaro(1, barbaroLife);
					rodada++;
					break;

			}
		}else{
			int aux = 0;
			singlePlayer(jogadorOne,barbaroLife, crawmeraxLife, classInvocadorVariavelGlobal, rodada);
			printf("...Espere Crawmerax fazer sua jogada...\n");
			delay(8);
			opcao = 1+rand()%3;
			switch(opcao){
				case 1:
					criandoStructCrawmerax(4, crawmeraxLife);

					printf("\nCrawmerx: Ataque Base %d\n", crawmeraxLifeVariavelGlobal);
					atBory = 1 + rand() % 5;
					printf("\nCrawmerx: Ataque Adicional +%d\n", atBory);
					atBory += crawmeraxLifeVariavelGlobal;
					printf("\nCrawmerx: Ataque Final %d\n", atBory);

					barbaroLife -= atBory;

					singlePlayer(jogadorOne,barbaroLife, crawmeraxLife, classInvocadorVariavelGlobal, rodada);

					break;
				case 2:
					criandoStructCrawmerax(2, crawmeraxLife);
					printf("\nCrawmerx: Ataque Base %d\n", crawmeraxLifeVariavelGlobal);
					atDistance = 1 + rand() % 6;
					printf("\nCrawmerx: Ataque Adicional +%d\n", atDistance);
					atDistance += crawmeraxLifeVariavelGlobal;
					printf("\nCrawmerx: Ataque Final %d\n", atDistance);
					barbaroLife -= atDistance;

					singlePlayer(jogadorOne,barbaroLife, crawmeraxLife, classInvocadorVariavelGlobal, rodada);
					break;
				case 3:
					criandoStructCrawmerax(3, crawmeraxLife);
					printf("\nCrawmerax: Vida %d\n", crawmeraxLife);

					atCure = 1 + rand() % 4;
					atCure += crawmeraxLifeVariavelGlobal;
					printf("\nCrawmerax: Cura +%d\n", atCure);
					crawmeraxLife += atCure;
					printf("\nCrawmerax: Vida %d\n", crawmeraxLife);

					singlePlayer(jogadorOne,barbaroLife, crawmeraxLife, classInvocadorVariavelGlobal, rodada);
					break;

			}
			rodada++;
		}
	}
}


int main(void){
	int op, cl;
	char playerOne[TAM], playerTwo[TAM];
	char classONE[TAM];
	clear();
	printf("================================================================\n");
	printf("      		      BEM VINDO - FOULBOGEY            \n");
	printf("=================== SELECIONE UMA DAS OPCOES ===================\n");
	printf("01 - Single Player\n");
	printf("02 - Multi Player");
	printf("\nEscolha: ");
	scanf("%d", &op);
	delay(1);
	clear();
	switch(op){
		case 01:			
			cabecClass(); // Chamando as classes/invocadores
			 // Armazenando o invocador
			printf("\nEscolha seu invocador: ");
			scanf("%d", &cl);
			strcpy(classONE, classCharacter(cl));
			strcpy(classInvocadorVariavelGlobal, classONE);// Armazenando em variavel global a classe escolhida
			delay(1);
			clear();

			printf("\n%s o grande %s\n\nFoi uma otima escolha!\n", jogadorOne, classONE);
			printf("\n%s: E uma honra lutar ao seu lado!\n", classONE);
			delay(6);
			clear();

			gameRun(); // Executando a função responsavel pela batalha
			
			break;
		default:
			printf("Opcao invalida \n");
		}
	return 0;
}