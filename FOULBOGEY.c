#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
	printf("+		   >>>>>>  %s  <<<<<<<					  \n", defeatedPlayer);
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
void secretAbility(char *class){
	printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("+		        (HABILIDADE ATIVADA)	        	     \n");
	printf("+	 %s Habilitou sua habilidade secreta             \n", class);
	printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
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
int funcaoCritical(int pLife, int classInvoc, int dano, int rodada){
	int porcentagem =0;
	int rod =0;
	switch(classInvoc){
		case 1: 
			if(pLife >= 45 && pLife <=88){
				porcentagem = rand()%5;
				if(porcentagem >=0 && porcentagem <=1){ 
					dano *= 2;
					printf("\nFOI ACRESCENTADO UM CRITICO DE: %d \n", dano);
					return dano;
				}else{
					dano =0;
					return dano;
				}
			}else if(pLife >=1 && pLife <=44){
				porcentagem = rand()%10;
				if(porcentagem != 8 && porcentagem !=9){
					dano *=2;
					return dano;
				}else{
					dano = 0;
					return dano;
				}
			}
			break;
		case 2:
			if(pLife >=61 && pLife <=80){
				porcentagem = rand()%1;
				if(porcentagem ==0){
					secretAbility(nameClassInvocadorG);
					rod = 1;
					return rod;
				}else{
					return rod=0;
				}
			}else if(pLife>=1 && pLife <=60){
				porcentagem = rand()%5;
				if(porcentagem != 3 && porcentagem !=4){
					secretAbility(nameClassInvocadorG);
					rod = 1;
					return rod;
				}else{
					return rod=0;
				}
			}
			break;
		case 3:
			if (pLife >= 55 && pLife <= 90){
				porcentagem = rand() % 5;
				if (porcentagem == 0 || porcentagem == 1){
					printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
					printf("+		(Habilidade Ativada)	   	      +\n");
					printf("+	Crawmerax teve seu proximo ataque bloqueado   +");
					printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
					printf(">>>>>>>>>>> %d\n", rodada);
					rodada += 1;
					printf(">>>>>>>>>>> %d\n", rodada);
				}
			}else if(pLife >= 1 && pLife <= 54){
				porcentagem = rand() % 10;
				if(porcentagem != 8 && porcentagem !=9){
					printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
					printf("+		(Habilidade Ativada)	   	      +\n");
					printf("+	Crawmerax teve seu proximo ataque bloqueado   +");
					printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
					printf(">>>>>>>>>>> %d\n", rodada);
					rodada += 1;
					printf(">>>>>>>>>>> %d\n", rodada);
				}
					
			}
			break;
	}
	return dano = 0;
}


int gameTeste(){
	int opcao;
	int atBody;
	int atDistance;
	int cure;

	int crawmeraxCarapace;
	bool chosenAction; // True quando o jogador escolhe ataque corpo a corpo
	char phraseWinner[TAM];
	int critico;

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

	}else if(classInvocadorG == 2){
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
			strcpy(phraseWinner, "Crawmerax foi destruido!");
			cabecalhoWinner(jogadorOne,personaLife, 0, nameClassInvocadorG, rodada, phraseWinner);
			break;
		}else if(personaLife <= 0){
			strcpy(phraseWinner, "voce foi destruido!");
			cabecalhoWinner(jogadorOne, 0, crawmeraxLife, nameClassInvocadorG, rodada, phraseWinner);
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
					//funcaoCritical(personalife, classInvocadorG, atBody);
					if(classInvocadorG == 1){
						funcaoCritical(personaLife, classInvocadorG, attackBodyG, rodada);
						critico = funcaoCritical(personaLife, classInvocadorG, attackBodyG, rodada);
						atBody+=critico;
					}
					atBody += attackBodyG;

					printf("\n%s: Ataque Final %d\n", nameClassInvocadorG, atBody);
					
					// Tirando vida do crawmerax de acordo com o ataque atBory
					if(crawmeraxLife <= 38){ // Validando a ativação da carapaça do Crawmerax
						printf("\n>>>> Crawmerax ativou sua Armadura e bloqueou 30%% do seu ataque <<<<\n");
						crawmeraxCarapace = (atBody * 30)/100; // Calculando o bloqueando 30% do ataque
						atBody -= crawmeraxCarapace; // Bloqueando 30% ataque
						crawmeraxLife -= atBody;
						printf("\nBloqueou -%d de dano\n", crawmeraxCarapace);
					}else{
						crawmeraxLife -= atBody;
					}
					
					//printf("Ta chegando aqui");
					chosenAction = true;
					int rod = funcaoCritical(personaLife, classInvocadorG, 0, rodada);
					//printf("\n>>>>>>>>>>>>>>>>>>>%d<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n",rod);
					rodada =(rodada+rod)+1;
					break;
				case 2:
					structPersona(classInvocadorG, 2, personaLife);
					criandoStructCrawmerax(1, crawmeraxLife);
					if(rodada == 1){
						singlePlayer(jogadorOne, personaLife, 250, nameClassInvocadorG, rodada);
					}else{
						singlePlayer(jogadorOne,personaLife, crawmeraxLife, nameClassInvocadorG, rodada);
					}

					printf("\n %s: Ataque base %d\n", nameClassInvocadorG, attackDistanceG);
					atDistance = 1+rand() % addAtkDistance;
					printf("\n %s ataque adicional +%d \n", classInvocadorVariavelGlobal, atDistance);

					funcaoCritical(personaLife, classInvocadorG, attackDistanceG, rodada);
					critico = funcaoCritical(personaLife, classInvocadorG, attackDistanceG, rodada);
				    atDistance+=critico;
					
					atDistance += attackDistanceG;
					printf("\n %s: Ataque final %d \n", classInvocadorVariavelGlobal, atDistance);

					// Tirando vida do crawmerax de acordo com o ataque atDistance
					if(crawmeraxLife <= 38){ // Validando a ativação da carapaça do Crawmerax
						printf("\n>>>> Crawmerax ativou sua Carapaça e bloqueou 30%% do seu ataque <<<<\n");
						crawmeraxCarapace = (atDistance * 30)/100; // Calculando o bloqueando 30% do ataque
						atDistance -= crawmeraxCarapace; // Bloqueando 30% ataque
						crawmeraxLife -= atDistance;
						printf("\nBloqueou -%d de dano\n", crawmeraxCarapace);
					}else{
						crawmeraxLife -= atDistance;
					}
					
					rodada++; 
					chosenAction = false;
					break;

				case 3:
					structPersona(classInvocadorG, 3, personaLife);
					criandoStructCrawmerax(1, crawmeraxLife);
					if(rodada == 1){
						singlePlayer(jogadorOne, personaLife, 250, nameClassInvocadorG, rodada);
					}else{
						singlePlayer(jogadorOne,personaLife, crawmeraxLife, nameClassInvocadorG, rodada);
					}

					printf("\n %s: cura base %d\n", nameClassInvocadorG, selfHealingG);
					cure = 1+rand() % addCure;
					printf("\n %s: cura adicional +%d \n", classInvocadorVariavelGlobal, cure);
					cure +=selfHealingG;
					printf("\n %s: cura final %d \n", classInvocadorVariavelGlobal, cure);

					funcaoCritical(personaLife, classInvocadorG, selfHealingG, rodada);

					ac += cure;
					chosenAction = false;
					rodada++; 
					break;
			}
		}else{
			int aux = 0;
			bool activateCure; 

			singlePlayer(jogadorOne,personaLife, crawmeraxLife, nameClassInvocadorG, rodada);
			printf("\n >>>> Espere Crawmerax fazer sua jogada <<<<\n");
			delay(5);

			if(crawmeraxLife <= 75){ 
				activateCure = rand() % 2; // 50% da opção ser a Cura
				if (activateCure == 0){ // ataque vai ser Cura
					opcao = 3;
				}else{ // Ataque vai ser corpo a corpo ou a distancia
					opcao = 1+rand()%2;
				}
			}else{
				opcao = 1+rand()%3;
			}

			switch(opcao){
				case 1:
					criandoStructCrawmerax(4, crawmeraxLife);
					printf("\nCRAWMERAX ESCOLHEU ATAQUE CORPO A CORPO!\n");
					printf("\nCrawmerx: Ataque Base %d\n", crawmeraxLifeVariavelGlobal);
					atBody = 1 + rand() % 5;
					printf("\nCrawmerx: Ataque Adicional +%d\n", atBody);
					atBody += crawmeraxLifeVariavelGlobal;

					if (chosenAction == true){ // validando se Crawmerax tinha recebido ataque corpo a corpo
						printf("\n>>>> Crawmerax recebeu mais 10%% de ataque adicional <<<<\n");
						atBody += (atBody * 10)/100; // adicionando mais 10% de dano no ataque
					}

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

					if (chosenAction == true){ // validando se Crawmerax tinha recebido ataque corpo a corpo
						printf("\n>>>> Crawmerax recebeu mais 10%% de ataque adicional <<<<\n");
						atDistance += (atDistance * 10)/100; // adicionando mais 10% de dano no ataque
					}

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

			gameTeste();
			break;
		case 2:
			printf("\nEm breve!\n");
			printf("\nProxima versao 1.0.1 FOULBOGEY\n");
			break;
		default:
			printf("\nOpcao invalida \n");
		
		}
	return 0;
}