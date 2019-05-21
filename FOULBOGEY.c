#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 50

int crawmeraxLifeVariavelGlobal;
char jogadorOne[TAM];
char classInvocadorVariavelGlobal[TAM];

//Variaveis de ambiente de teste:
int lifeGlobalG;
int attackBodyG;
int attackDistanceG;
int selfHealingG;
int classInvocadorG;
char nameClassInvocadorG[TAM];


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

int cabecalhoWinner(char playerOne[TAM], int lifeOne, int lifeCraw, char characterOne[TAM], int rodada, char defeatedPlayer[TAM]){
	printf("\n================================== PLACAR - FOULBOGEY ==================================\n");
	printf("+																						  \n");
	printf("+	Player01: %s 		Vida: %d 		Invocador: %s \n", playerOne, lifeOne, characterOne);
	printf("+																						  \n");
	printf("+	Inimigo: Crawmerax 		Vida: %d  		Rodada: %d\n", lifeCraw, rodada);
	printf("+																						  \n");
	printf("+																						  \n");
	printf("+		>>>>>>  Parabens, voce derrotou o %s  <<<<<<<					  \n", defeatedPlayer);
	printf("+																						  \n");
	printf("========================================================================================\n");
}


//int barbaro(int life, int cure, int offense, int meleeatack);
void cabecClass(void){
	printf("\n==================ESCOLHA SEU INVOCADOR ====================\n");
	printf("01 - Barbaro \n");
	printf("02 - Arqueiro");
	printf("\n03 - Mago ");
}


void cabecalhoGameRun(){
	printf("\n=============== CAMPO DE BATALHA INICIADO =================\n");
	printf("01 - Ataque Corpo a Corpo \n");
	printf("02 - Ataque a Distancia");
	printf("\n03 - Curar ");
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
int structPersona(int classe, int jogada, int lifePersona){
	struct persona{
		int attackBody;
		int attackDistance;
		int selfHealing;
		int life;
	};

	struct persona personage;
	int aB, aD, sH, lif;
	if(classe == 1){//Barbaro;
		aB = 21;
		aD = 15;
		sH = 15;
		lif = 220;
	}else if(classe == 2){
		aB = 18;
		aD = 22;
		sH = 17;
		lif = 200;
	}else if(classe == 3){
		aB = 16;
		aD = 18;
		sH = 20;
		lif = 180;
	}

	if(jogada == 4){
		attackBodyG = personage.attackBody = aB;
		return attackBodyG;

	}else if(jogada == 2){
		attackDistanceG = personage.attackDistance = aD;
		return attackDistanceG;

	}else if(jogada == 3){
		selfHealingG = personage.selfHealing = sH;
		return selfHealingG;

	}else if(jogada == 1){
		lifeGlobalG = personage.life = lif;
		return lifeGlobalG;
	}else{
		return 0;
	}
}


char *classCharacter(int classe){
	char *characOne;
	characOne = malloc(TAM*sizeof(char));

	switch(classe){
		case 01:
		strcpy(characOne, "Barbaro");
		printf("player 01 - Digite seu nome:"); 
		scanf("%s",jogadorOne);
		break;
		case 02:
		strcpy(characOne, "Arqueiro");
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


/* A batalha rola nessa função gameRun()
* Aqui vai ser a funçao onde o usuario escolheram os ataque 
* e aqui tambem a gente pode calcular os danos igual eu fiz ali :D */

int gameTeste(){
	int opcao;
	int atBody;
	int atDistance;
	int cure;

	int crawmeraxLife=250;
	int ab=0, ad = 0, ac=0;
	int personaLife;
	int dano = 0;
	int rodada =1,addAtkBody=0, addAtkDistance =0, addCure=0;
	char classe[TAM];
	// Estou chamando as funções para poder acessar os valores delas
	srand(time(NULL));

	if(classInvocadorG == 1){
		personaLife = 220;
		addAtkBody = 3;
		addAtkDistance = 2;
		addCure = 3;
		strcpy(nameClassInvocadorG, "Barbaro");

	}else if(classInvocadorG = 2){
		personaLife = 200;
		addAtkBody = 2;
		addAtkDistance = 6;
		addCure = 3;
		strcpy(nameClassInvocadorG, "Arqueiro");
	}else{
		personaLife = 180;
		addAtkBody = 2;
		addAtkDistance = 4;
		addCure = 2;
		strcpy(nameClassInvocadorG, "Mago");
	}
	while(1){
		if(crawmeraxLife <= 0){
			cabecalhoWinner(jogadorOne,personaLife, 0, nameClassInvocadorG, rodada, "Crawmerax");
			break;
		}else if(personaLife <= 0){
			cabecalhoWinner(jogadorOne, 0, crawmeraxLife, nameClassInvocadorG, rodada, nameClassInvocadorG);
			break;
		}
		if (rodada%2==1){
			cabecalhoGameRun();
			printf("\nQual sua jogada?\n");
			scanf("%d", &opcao);
			delay(1);
			clear();
			switch(opcao){
				case 1:
					structPersona(classInvocadorG, 1, personaLife);
					criandoStructCrawmerax(1, crawmeraxLife);
					if(rodada == 1){
						singlePlayer(jogadorOne, personaLife, 250, nameClassInvocadorG, rodada);
					}else{
						singlePlayer(jogadorOne,personaLife, crawmeraxLife, nameClassInvocadorG, rodada);
					}
					structPersona(classInvocadorG, 4, personaLife);
					printf("\n%s: Ataque Base %d\n", nameClassInvocadorG, attackBodyG);
					atBody = 1+ rand() % addAtkBody;
					printf("\n%s: Ataque Adicional +%d\n", nameClassInvocadorG, atBody);
					atBody += attackBodyG;

					printf("\n%s: Ataque Final %d\n", nameClassInvocadorG, atBody);

					// Tirando vida do crawmerax de acordo com o ataque atBory
					crawmeraxLife -= atBody;
					personaLife = structPersona(classInvocadorG, 1, personaLife);
					rodada++;
					break;

				case 2:
					structPersona(classInvocadorG, 1, personaLife);
					criandoStructCrawmerax(1, crawmeraxLife);
					if(rodada == 1){
						singlePlayer(jogadorOne, personaLife, 250, nameClassInvocadorG, rodada);
					}else{
						singlePlayer(jogadorOne,personaLife, crawmeraxLife, nameClassInvocadorG, rodada);
					}
					structPersona(classInvocadorG, 2, personaLife);
					printf("\n %s: Ataque base %d\n", nameClassInvocadorG, attackDistanceG);
					atDistance = 1+rand() % addAtkDistance;
					printf("\n %s ataque adicional +%d \n", classInvocadorVariavelGlobal, atDistance);
					atDistance +=attackDistanceG;
					printf("\n %s: Ataque final %d \n", classInvocadorVariavelGlobal, atDistance);

					crawmeraxLife -= atDistance;
					personaLife = structPersona(classInvocadorG, 1, personaLife);
					rodada++; 
					break;

				case 3:
					structPersona(classInvocadorG, 3, personaLife);
					criandoStructCrawmerax(1, crawmeraxLife);
					if(rodada == 1){
						singlePlayer(jogadorOne, personaLife, 250, nameClassInvocadorG, rodada);
					}else{
						singlePlayer(jogadorOne,personaLife, crawmeraxLife, nameClassInvocadorG, rodada);
					}
					structPersona(classInvocadorG, 3, personaLife);
					printf("\n %s: cura base %d\n", nameClassInvocadorG, selfHealingG);
					cure = 1+rand() % addCure;
					printf("\n %s: cura adicional +%d \n", classInvocadorVariavelGlobal, cure);
					cure +=selfHealingG;
					printf("\n %s: cura final %d \n", classInvocadorVariavelGlobal, cure);

					ac += cure;
					personaLife = structPersona(classInvocadorG, 1, personaLife);
					rodada++; 

					break;

			}
		}else{
			int aux = 0;
			singlePlayer(jogadorOne,personaLife, crawmeraxLife, nameClassInvocadorG, rodada);
			printf("\n >>>> Espere Crawmerax fazer sua jogada <<<<\n");
			delay(5);
			opcao = 1+rand()%3;
			switch(opcao){
				case 1:
					criandoStructCrawmerax(4, crawmeraxLife);
					printf("\nCRAWMERAX ESCOLHEU ATAQUE CORPO A CORPO!\n");
					printf("\nCrawmerx: Ataque Base %d\n", crawmeraxLifeVariavelGlobal);
					atBody = 1 + rand() % 5;
					printf("\nCrawmerx: Ataque Adicional +%d\n", atBody);
					atBody += crawmeraxLifeVariavelGlobal;
					printf("\nCrawmerx: Ataque Final %d\n", atBody);
					personaLife -= atBody;
					singlePlayer(jogadorOne, personaLife, crawmeraxLife, nameClassInvocadorG, rodada);
					break;
				case 2:
					criandoStructCrawmerax(2, crawmeraxLife);
					printf("\nCRAWMERAX ESCOLHEU ATAQUE A DISTANCIA!\n");
					printf("\n Crawmerax: Ataque base %d\n",crawmeraxLifeVariavelGlobal);
					atDistance = 1+rand()%5;
					printf("\n Crawmerax: Ataque adicional +%d\n",atDistance);
					atDistance += crawmeraxLifeVariavelGlobal;
					printf("\n Crawmerax: Ataque Final %d\n", atDistance);
					personaLife -=atDistance;
					singlePlayer(jogadorOne, personaLife, crawmeraxLife, nameClassInvocadorG, rodada);
					break;
				case 3:
					criandoStructCrawmerax(3, crawmeraxLife);
					printf("\nCRAWMERAX ESCOLHEU CURAR SE!\n");
					printf("\n Crawmerax: cura base %d\n",crawmeraxLifeVariavelGlobal);
					cure= 1+rand()%10;
					printf("\n Crawmerax: Cura adicional +%d\n", cure);
					cure += crawmeraxLifeVariavelGlobal;
					printf("\n Crawmerax: cura final %d\n", cure);
					crawmeraxLife +=cure;
					

					singlePlayer(jogadorOne, personaLife, crawmeraxLife, nameClassInvocadorG, rodada);
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
			classInvocadorG = cl;
			strcpy(classInvocadorVariavelGlobal, classONE);// Armazenando em variavel global a classe escolhida
			delay(1);
			clear();

			printf("\n%s o grande %s\n\nFoi uma otima escolha!\n", jogadorOne, classONE);
			printf("\n%s: E uma honra lutar ao seu lado!\n", classONE);
			delay(6);
			clear();

			//gameRun(); 
			gameTeste();
			break;
			default:
			printf("Opcao invalida \n");
		}

	//cONE = classCharacter();
	//singlePlayer(playerOne, 100, 100, cONE);
		return 0;
	}
	//Sem mago, e arqueiro, está dando 375 Linhas;