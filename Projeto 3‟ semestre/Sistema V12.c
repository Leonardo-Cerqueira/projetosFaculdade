#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
//-----------------------------------------------------------------Estruturas criadas------------------------------------------------------------------------------------------------------------------------------
typedef struct cadCli{
	int  CodCli;s
	char Nome          [31];
	char Nome2         [31];
	char Nome_Usuario  [31];
	char Nome_Usuario2 [31];
	char Email         [31];
	char Email2        [31];
	char Senha         [31];
	char Senha2        [31];
	char Senha3        [31];
	char  NumeroTel    [31];  
	char  NumeroTel2   [31];
	char CPF           [14];
}cadCli;
 cadCli Cli[30];
typedef struct cadCart{
		int   codCart;
		char  codSeg     [4];
		char  codSeg2    [4]; 
		char  numCartao  [15]; 
		char  numCartao2 [15];
		char  numVal     [5];
		char  numVal2    [5];
		char  nomeCart   [31];
		char  nomeCart2  [31];
}cadCart;
 cadCart Cart[30];
typedef struct cadEnd{
	int  codEnd, numEndereco;
	char nomeRua   [31];
	char nomeRua2  [31];
	char nomeEst   [31];
	char nomeEst2  [31];
	char nomeCid   [31];
	char nomeCid2  [31];
	char complet   [31];
	char complet2  [31];
	char ref       [31];
	char ref2      [31];
	char bairro    [31];
	char bairro2   [31];
	char numCep    [12];
	char numCep2   [12];
	char UF        [3];
	char casa      [4];
	char casa2     [4];
	char numCas    [5];
	char numCas2   [5];
}cadEnd;
 cadEnd End[30];
typedef struct cadJogo{
	int    count, codJogo, codJogo2; 
	char   prodJogo  [31];
	char   prodJogo2 [31];
	char   nomeJogo  [31];
	char   nomeJogo2 [31];
	char   DatLan    [9];
	char   DatLan2   [9];
	double precoJogo;
	double precoJogo2;
}cadJogo;
 cadJogo Jogo[30]; // Na Struct, armazenamos os dados dentro de um vetor da Struct cadJogo[], e dentro dele h� outros vetores que armazenam outras informa��es de cadstros.
typedef struct Pedido{
	double preco;
	int A, B, codPed, codPed2, qtd, pgto, codcart, codbol, codbanc, codcont, codend, codusuc;
 }Pedido;
 Pedido pedido[30];
typedef struct Boleto{
	double A, B, C;
}Boleto;
 Boleto boleto[4]; 
 //Acima fizemos uma estrutura para cada fun��o que criamos no c�digo adiante.  
 
//------------------------------------------------------------------------Menus------------------------------------------------------------------------------------------------------------------------------------
 main (){
	setlocale(LC_ALL, "portuguese");
	char usuc   [4];
	char usuc2  [4] = "ADM";  
	char senha  [9];
	char senha2 [9] = "12345678"; 
//Aqui nessa parte do c�digo foi feito o definido o usu�rio e senha ADM, deixando ele como o �nico usu�rio para acesso ao sistema.
	do {
	system("cls");
	printf("========================================================TRINITY GAMES==================================================\n\n");
	printf("Digite o seu usu�rio:\n\n");
	fflush(stdin);
	scanf("%s", &usuc);
	
	printf("\nDigite sua senha de acesso:\n\n");
	scanf("%s", &senha);
	
//Comandos para entrada de dados de usu�rio e senha definidos como char/strings.
	
	if ((strcmp(usuc, usuc2) == 0) || (strcmp (senha, senha2)==0)){ 
		printf("\nLogin efetuado com sucesso!\n\n");
		sleep(2,0); 
		menuPrincipal();	
}
//Caso o usu�rio digite os valores corretos (Usu�rio="ADM", e Senha= "12345678"), o comando strcmp(compara os valores definidos nos vetores e os digitados pelo usu�rio) retornar� 0 caso forem iguais.
// ap�s a entrada na cl�usula if, e retorno 0 do comando strcmp, ser� apresentada uma mensagem que ficara por 2 segundos gra�as o comando sleep, e acessar� o menu princilpal do sistema.

	 else ((strcmp(usuc, usuc2) != 0) || (strcmp (senha, senha2)!=0));{
		  printf("\nLogin inv�lido, revise usu�rio e senha e tente novamente\n\n");
		  sleep(2,0);
	}
//Caso o strcmp n�o retorne o valor 0, a cl�usula else apresentar� uma mensagem dizendo que o login n�o foi efetuado e entrar� no While, que vai fazer o c�digo voltar ao in�cio.
 } while ((strcmp(usuc, usuc2) != 0) || (strcmp (senha, senha2)!=0)); //Comando Do while que ir� repetir a fun��o de login caso a senha ou usu�rio estejam erradas
}

//Acima foi feito uma fun��o de login para a acessar o menu principal.

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int menuPrincipal () {
 	setlocale(LC_ALL, "portuguese");
 	int escolha;
 	system("cls");
 	printf("========================================================TRINITY GAMES==================================================\n\n\n");
	printf("\t\t\t \t                  Menu Principal do Sistema\n\n");
	printf("\t\t   ============================================================================================\n");
	printf("\t\t   |         Op��o 1 - Menu de Jogos           |         Op��o 2 - Menu de Contas             |\n");
	printf("\t\t   ============================================================================================\n");
	printf("\t\t   |         Op��o 3 - Menu de Cart�es         |         Op��o 4 - Menu de Endere�os          |\n");
	printf("\t\t   ============================================================================================\n");
	printf("\t\t   |         Op��o 5 - Menu de Pedidos         |         Op��o 6 - Detalhes                   |\n");
	printf("\t\t   ============================================================================================");
	printf("\n\n");
	printf("Digite a op��o desejada\n\n");
	fflush(stdin);
	scanf("%d", &escolha);
	printf("\n");
	switch (escolha){
	case 1:
		menuJogos();
		menuPrincipal();
	case 2:
		menuConta();
		menuPrincipal();
	case 3:
		menuCartao();
		menuPrincipal();
	case 4:
		menuEndereco();
		menuPrincipal();
	case 5: 
		menuPedidos();
		menuPrincipal();
	case 6:
		detalhes();
	default:
		printf("Digite um op��o v�lida!\a\n");
		sleep(2,0);
		menuPrincipal();
		break;
		
//Acima o Menu Principal e apresentado ao usu�rio, e nele foi usado o comando switch, que caso cada op��o numeral for escolhida, ele chamar� cada fun��o de menus criadas no c�digo fonte.
 }		
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int menuJogos(){
	setlocale(LC_ALL, "portuguese");
 	int opcao;
 	system("cls");
	printf("\t\t\t\t                         Menu do Sistema\n\n");
	printf("\t     ==================================================================================================\n");
	printf("\t     |         Op��o 1 - Cadastro de Jogos             |          op��o 2 - Consulta de Jogos         |\n");
	printf("\t     ==================================================================================================\n");
	printf("\t     |         Op��o 3 - Alterar Cadastro de Jogos     |          op��o 4 - Excluir Jogos Cadastrados |\n");
	printf("\t     ==================================================================================================\n");
	printf("\t     |                               Op��o 5 - Voltar ao Menu Principal                               |\n");
	printf("\t     ==================================================================================================\n");
	printf("\nDigite a op��o desejada:\n\n");
	fflush(stdin);
	scanf("%d", &opcao);
	printf("\n\n");
	switch (opcao){
		case 1:
			cadastroJogo();
			menuJogos();
		case 2:
			consultaJogo();
			menuJogos();
		case 3:
			alterarJogo();
			menuJogos();
		case 4:
			exclusaoJogo();
			menuJogos();
		case 5:
			menuPrincipal();
		default:
			printf("Digite um op��o v�lida!\n");
			printf("\a");
			sleep(2,0);
			menuJogos();
			break;
					
//Em cada fun��o de menus do sistema (Jogos, cart�es, enedere�os ou conta), h� a op��o de escolher a op��o desejeda apresentada pelos printfs dentro do menu, e cada op��o escolhida chamar� uma fun��o determinada.
 }	
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int menuEndereco(){
	setlocale(LC_ALL, "portuguese");
 	int opcao;
 	system("cls");
	printf("\t\t\t\t                         Menu do Sistema\n\n");
	printf("\t     ======================================================================================================\n");
	printf("\t     |         op��o 1 - Cadastro de Endere�os         |          op��o 2 - Consulta de Endere�os         |\n");
	printf("\t     ======================================================================================================\n");
	printf("\t     |         op��o 3 - Altera cadastro de Endere�os  |          op��o 4 - Excluir cadastro de Endere�os |\n");
	printf("\t     ======================================================================================================\n");
	printf("\t     |                               Op��o 5 - Voltar ao Menu Principal                                   |\n");
	printf("\t     ======================================================================================================\n\n");
	printf("Digite a op��o desejada\n\n");
	fflush(stdin);
	scanf("%d", &opcao);
	printf("\n\n");
	switch (opcao){
		case 1:
			cadastroEndereco();
			menuEndereco();
		case 2:
			consultaEnd();
			menuEndereco();
		case 3:
			alterarEndereco();
			menuEndereco();
		case 4:
			exclusaoEndereco();
			menuEndereco();
		case 5: 
			menuPrincipal();
		default:
			printf("Digite um op��o v�lida!\n");
			printf("\a");
			sleep(2,0);
			menuEndereco();
			break;	
 }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int menuCartao(){
	setlocale(LC_ALL, "portuguese");
 	int opcao;
 	system("cls");
	printf("\t\t\t\t                        Menu do Sistema\n\n");
	printf("\t     =====================================================================================================\n");
	printf("\t     |         op��o 1 - Cadastro de Cart�o           |          op��o 2 - Consulta de Cart�o            |\n");
	printf("\t     =====================================================================================================\n");
	printf("\t     |         op��o 3 - Altera cadastro de Cart�o    |          op��o 4 - Excluir cadastro de Cart�o    |\n");
	printf("\t     =====================================================================================================\n");
	printf("\t     |                              Op��o 5 - Voltar ao Menu Principal                                   |\n");
	printf("\t     =====================================================================================================\n\n");
	printf("Digite a op��o desejada\n\n");
	fflush(stdin);
	scanf("%d", &opcao);
	printf("\n\n");
	switch (opcao){
		case 1: 
			cadastroCartao();
			menuCartao();
		case 2:
			consultaCartao();
			menuCartao();
		case 3:
			alterarCartao();
			menuCartao();
		case 4:
			exclusaoCartao();
			menuCartao();
		case 5:
			menuPrincipal();
		default:
			printf("Digite um op��o v�lida!\n");
			printf("\a");
			sleep(2,0);
			menuCartao();
			break;	
  }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int menuConta(){
	setlocale(LC_ALL, "portuguese");
 	int opcao;
 	system("cls");
	printf("\t\t\t\t                        Menu do Sistema\n\n");
	printf("\t     =====================================================================================================\n");
	printf("\t     |         op��o 1 - Cadastro de Conta            |          op��o 2 - Consulta de Conta             |\n");
	printf("\t     =====================================================================================================\n");
	printf("\t     |         op��o 3 - Alterar cadastro de Conta    |          op��o 4 - Excluir cadastro de Conta     |\n");
	printf("\t     =====================================================================================================\n");
	printf("\t     |                              Op��o 5 - Voltar ao Menu Principal                                   |\n");
	printf("\t     =====================================================================================================\n\n");
	printf("Digite a op��o desejada\n\n");
	fflush(stdin);
	scanf("%d", &opcao);
	printf("\n\n");
	switch (opcao){
		case 1:
			cadastroConta();
			menuConta();
		case 2:
			consultaConta();
			menuConta();
		case 3: 	
			alterarConta();
			menuConta();
		case 4:
			exclusaoConta();
			menuConta();
		case 5:
			menuPrincipal();
		default:
			printf("Digite um op��o v�lida!\n");
			printf("\a");
			sleep(1,0);
			menuJogos();
			break;	
  }	
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int menuPedidos(){
	setlocale(LC_ALL, "portuguese");
 	int opcao;
 	system("cls");
	printf("\t\t\t\t                        Menu do Sistema\n\n");
	printf("\t     =========================================================================================================\n");
	printf("\t     |         op��o 1 - Menu de compra                 |            op��o 2 - Detalhes de Pedido            |\n");
	printf("\t     =========================================================================================================\n");
	printf("\t     |         op��o 3 - Exclus�o de pedidos            |            op��o 4 - Menu Principal                |\n");
	printf("\t     =========================================================================================================\n\n");	
	printf("Digite a op��o desejada\n\n");
	fflush(stdin);
	scanf("%d", &opcao);
	printf("\n\n");
	switch (opcao){
		case 1:
			compra();
			menuPedidos();
		case 2:
			detalhesPedido();
			menuPedidos();
		case 3:
			exclusaoPedido();
			menuPedidos();
		case 4:
			menuPrincipal();
		default:
			printf("Digite um op��o v�lida!\n");
			printf("\a");
			sleep(2,0);
			menuPedidos();
			break;	
 }
}
//------------------------------------------------------------------------Fun��es----------------------------------------------------------------------------------------------------------------------------------
int cadastroJogo(){
	setlocale(LC_ALL, "portuguese"); //setlocale utilizado para os caracteres especiais serem apresentados corretamente.
 	char escolha = 's'; // definido a vari�vel "escolha" como S para o c�digo entrar dentro da estrutra While.
 	int A=0, i, jogo, jogofinal; //vari�veis criadas para o funcionamento da fun��o.
 	system("cls"); //comando de limpeza de tela.
	while(escolha == 'S'||escolha == 's'){ //Estrutra While para repeti��o que voltar� o programa para o in�cio caso a valida��o no final do While for s ou S.
		system("cls"); //comando de limpeza de tela.
		printf("===================================================Cadastro de Jogos===================================================\n\n");
		printf("Insira o jogo inicial para cadastro:\n\n");
		scanf("%d", &jogo);
		printf("\n");
		printf("Insira o jogo final para cadastro:\n\n");
		scanf("%d", &jogofinal);
		printf("\n");
		//Neta parte do c�digo, � poss�vel realizar o cadastro do jogo inicial e jogo final. Caso o usu�rio ADM coloque o jogo inicial como 1, e o jogo final como 3, ser� poss�vel cadastrar tr�s jogos de uma vez. Essa fun��o permite cadastro de jogos em massa.
			for (i=jogo; i<=jogofinal; i++){ //estrutura de repeti��o criada para repetir o cadastro caso o n�mero do jogo final for maior que 1.
				system("cls");		
				printf("===================================================Cadastro de Jogos===================================================\n");	
		    	printf("\nC�digo do jogo: \n\n");
				scanf("%d", &Jogo[i].count);
				//Aqui o usu�rio casdastra o c�digo do jogo (Important�ssimo porque o sistema utiliza esses c�digos para sele��o de jogos, endere�os, contas e pedidos).
				
				//O valor de i ser� definido pela a estrutra de repeti��o for, e ser� armazenado no vetor dentro da estrutura cadJogo.
				printf("\nDigite a produtora do jogo:\n\n");
				fflush(stdin);
				scanf("%[^\n]",&Jogo[i].prodJogo);
				printf("\n");
				printf("Digite o nome do jogo:\n\n");
				fflush(stdin);
				scanf("%[^\n]",&Jogo[i].nomeJogo);
				printf("\n");
				printf("Digite sua data de lan�amento (dd/mm/aa):\n\n");
				fflush(stdin);
				scanf("%[^\n]",&Jogo[i].DatLan);
				printf("\n");
				printf("Digite o pre�o do jogo:\n\n");
				fflush(stdin);
				scanf("%lf", &Jogo[i].precoJogo);
				printf("\n");
				printf("=======================================================================================================================\n");
				//Comandos de entradas de dados que ser�o armazenados nos seus vetores determinados, que por sua vez s�o armazenados na estrutura de cadastro de jogos "cadJogo".
}
	printf("\nDeseja cadastrar um outro jogo? (S/N): \n\n");
	fflush(stdin);
	scanf("%c", &escolha);
	printf("\n");
	//Entrada de dados que definir� se o c�digo voltar� ao in�cio, ou se vai sair da estrura e voltar ao Menu Jogos. Essa decis�o ser� dado pelo usu�rio que utilizar� o sistema.
 }
} 
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int consultaJogo(){
	setlocale(LC_ALL, "portuguese");
	int a, i, jogofinal, count, jogo;
	char escolha = 's';
	system("cls");
    while(escolha =='S'||escolha=='s'){
    //Os c�digos acima j� foram explicados, tornando sem sentido a explica��o novamente.
	    system("cls");
	    printf("===================================================Consulta de Jogos===================================================\n\n");
		printf("Insira o jogo inicial para a consulta:\n\n");
		scanf("%d", &jogo);
		printf("\n");
		printf("Insira o jogo  final  para a consulta:\n\n");
		scanf("%d", &jogofinal); 
		system("cls");
		//Aqui o usu�rio decidir� quais jogos que seram consultados atrav�s do c�digo cadstrado na fun��o cadastroJogo.
		printf("==================================================Jogos  Cadastrados===================================================\n\n");
			for (i=jogo; i<=jogofinal; i++){
				if (Jogo[i].count> 0){ // esse if foi feito para uma valida��o. Caso nenhum jogo esteja cadastrado, ele ir� para condi��o else. Essa valid��o s� � ativada caso o c�digo do jogo estiver sem valor no vetor definido pelo i que por sua vez ser�m definida pela estrura for.
					printf("C�digo do Jogo:.....%d\n\n",    Jogo[i].count); 
					printf("Produtora do jogo:..%s\n\n",    Jogo[i].prodJogo);
					printf("Nome do jogo:.......%s\n\n",    Jogo[i].nomeJogo);
					printf("Data de lan�amento:.%s\n\n",    Jogo[i].DatLan);
					printf("Pre�o do jogo:...R$ %.2lf\n\n", Jogo[i].precoJogo);
					//Acima � c�digo de consulta dos jogos, ele imprimir� em tela os vetores na posi��o definida pelo i na estrura for.
					printf("=======================================================================================================================\n\n");	
}
				else{
					system("cls");
					printf("===========================================Nenhum Jogo com o c�digo escolhido cadastrado!==============================\n");
					sleep(1,0);
					menuJogos();
				//Caso nenhum jogo na posi��o esteja cadastrado, a mensagem acima ser� mostrada e voltar� para o menu de jogos.
 }
}
	printf("Deseja consultar um outro jogo? (S/N):\n\n");
	fflush(stdin);
	scanf("%c", &escolha);
  }
}
//Como as estruturas de cadastro, consulta, altera��o e exclus�o s�o as mesmas para os menus de Jogos, Endere�os, Contas e Cart�es, n�o � necess�rio explicar cada fun��o de cada menu pelo fato de serem as mesmas utilizadas aqui. 
//Sendo assim explicarei as fun��es de cadastro, consulta, altera��o e exclus�o do Menu de Jogos. 
//A �nica coisa que mudar� nas fun��es e as estruturas e vetores.
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int exclusaoJogo(){
	setlocale(LC_ALL, "portuguese");
 	char escolha = 's';
 	int i,jogofinal;
 	while(escolha =='S'||escolha=='s'){
	 	system("cls");
	 	printf("=============================================Selecionar Jogos para Exclus�o=============================================\n\n");
		printf("Insira o c�digo do jogo para a exclus�o (1 � 999):\n\n");
		scanf("%d", &jogofinal);
		printf("\n");
		//estruras j� explicadas.
			for (i=1; i=jogofinal; i++){ //Coloquei a estrura for para selecionar apenas 1 jogo para exclus�o (por conta de n�o ter sido poss�vel fazer uma exclus�o em massa)
				if (Jogo[i].count>0){ //Mesma valida��o feita na consulta de Jogos. 
				system("cls");
				printf("=============================================Exclus�o de Jogos Cadastrados==============================================\n\n");
				Jogo[i] = Jogo[i-jogofinal]; //Aqui foi c�digo de exclus�o. o c�digo do jogo na posi��o escolhido ser� removido, e substitu�do por uma nova numere��o no vetor.
				printf("Jogo escolhido exclu�do!\n\n");
				printf("========================================================================================================================\n\n");
				break;
  }
			else{
				system("cls");
				printf("===========================================Nenhum Jogo com o c�digo escolhido cadastrado!==============================\n");
				sleep(2,0);
				menuJogos();
				//mesma valida��o de feita na consulta de Jogos.
 }
}
	printf("Deseja excluir um outro jogo? (S/N): \n\n");
	fflush(stdin);
	scanf("%c", &escolha);
	printf("\n");	
 }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int alterarJogo(){
	setlocale(LC_ALL, "portuguese");
 	char escolha = 's';
 	int i, jogofinal, opcao;
 	while(escolha =='S'||escolha=='s'){
 	system("cls");
 	printf("=============================================Selecionar Jogos para Altera��o============================================\n\n");
	printf("Insira o jogo para a altera��o (1 � 30):\n\n");
	scanf("%d", &jogofinal);
	printf("\n");
	//c�digos j� explicados
	for (i=1; i=jogofinal; i++){
		if (Jogo[i].count>0){ //valida~��o j� explicadas
			system("cls");
			printf("==================================================Altera��o de Jogos Cadastrados========================================\n\n");
			printf("\t\t\t\t                          Menu do Sistema\n\n");
			printf("\t     =======================================================================================================\n");
			printf("\t     |         op��o 1 - Alterar nome da Produtora      |            op��o 2 - Alterar o nome do jogo      |\n");
			printf("\t     =======================================================================================================\n");
			printf("\t     |         op��o 3 - Alterar data de lan�amento     |            op��o 4 - Alterar o Pre�o             |\n");
			printf("\t     =======================================================================================================\n");
			printf("\t     |                                Op��o 5 - Voltar ao Menu dos Jogos                                   |\n");
			printf("\t     =======================================================================================================\n\n");
			printf("Digite a op��o desejada\n\n");
			scanf("%d", &opcao);
			printf("\n");
			//Acima � mostrado em tela o menu com as op��es dispon�veis  
				switch (opcao){
					case 1:
						printf("Digite os dados da nova produtora:\n\n");
						fflush(stdin);
						scanf("%[^\n]",&Jogo[i].prodJogo2);
						printf("\n");
						strcpy(Jogo[i].prodJogo, Jogo[i].prodJogo2);
						//Como quase todas as Structs est�o em char, foi utilizado o c�digo strcpy. Ele copia os dados de uma string para outra.
						//Ex: o valor de Jogo[i].prodJogo ser� substitu�do pela nova string do vetor Jogo[i].prodJogo2. Assim, a altera��o ser� feita.
						printf("Altera��o conclu�da!\n");
						//Mensagem apresentado que a altera��o foi conclu�da.
						sleep(1,0);
						//Quantidade de tempo que a mensagem ser� apresentada em tela.
						break;
					 	// a estrutura switch foi feita por conta de ser mais f�cil de fazer o c�digo funcionar de maneira correta.
					case 2:
						printf("Digite os dados do novo nome:\n\n");
						fflush(stdin);
						scanf("%[^\n]",&Jogo[i].nomeJogo2);
						printf("\n");
						strcpy(Jogo[i].nomeJogo, Jogo[i].nomeJogo2);
						printf("Altera��o conclu�da!\n");
						sleep(1,0);
						break;
					case 3:
						printf("Digite os dados da nova data de lan�amento (dd/mm/aa):\n\n");
						scanf("%s", &Jogo[i].DatLan2);
						printf("\n");
						strcpy(Jogo[i].DatLan, Jogo[i].DatLan2);
						printf("Altera��o conclu�da!\n");
						sleep(1,0);
						break;
					case 4:
						printf("Digite os dados do novo pre�o:\n\n");
						scanf("%lf", &Jogo[i].precoJogo2);
						printf("\n");
						Jogo[i].precoJogo = Jogo[i].precoJogo2;
						printf("Altera��o conclu�da!\n");
						sleep(1,0);
						break;
					case 5: 
						menuJogos();
						//Op��o que caso selecionada, o usu�rio voltar� ao menu de jogos.
					default:
						printf("Digite um op��o v�lida!\n");
						printf("\a");
						sleep(1,0);
						break;	
						//Caso o usu�rio selecione uma op��o que n�o foi definada no menu, ele mostrar� uma mensagem e um som de aviso.
 }
}
   		else{
   			system("cls");
			printf("===========================================Nenhum Jogo com o c�digo escolhido cadastrado!==============================\n");
			sleep(2,0);
			menuJogos();
   }
  } 
 }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int cadastroEndereco(){
	setlocale(LC_ALL, "portuguese");
 	int i, end, endfinal;
 	char escolha = 's';
 	system("cls");
	while(escolha =='S'||escolha=='s'){
		system("cls");
		printf("==================================================Cadastro de Endere�o==================================================\n\n");
		printf("Insira o endere�o inicial para cadastro:\n\n");
		scanf("%d", &end);
		printf("\n");
		printf("Insira o endere�o  final  para cadastro:\n\n");
		scanf("%d", &endfinal);
		printf("\n");
		system("cls");	
		printf("\n");
			for (i=end; i<=endfinal; i++){
				system("cls");
				printf("==================================================Cadastro de Endere�o==================================================\n\n");
				printf("Digite o c�digo do Endere�o:\n\n");
				scanf("%d", &End[i].codEnd);
				printf("\nDigite o nome do Estado:\n\n");
				fflush(stdin);
				scanf("%[^\n]",&End[i].nomeEst);
				printf("\nDigite a UF do Estado:\n\n");
				fflush(stdin);
				scanf("%[^\n]",&End[i].UF);
				printf("\nDigite o nome da cidade:\n\n");
				fflush(stdin);
				scanf("%[^\n]",&End[i].nomeCid);
				printf("\nDigite o nome do bairro\n\n");
				fflush(stdin);
				scanf("%[^\n]",&End[i].bairro);
				printf("\nDigite o CEP:\n\n");
				fflush(stdin);
				scanf("%[^\n]",&End[i].numCep);
				printf("\nDigite o nome da rua:\n\n");
				fflush(stdin);
				scanf("%[^\n]",&End[i].nomeRua);
				printf("\nDigite o n�mero da casa (Rua):\n\n");
				fflush(stdin);
				scanf("%[^\n]",&End[i].numCas);
				printf("\nDigite o complemento (Caso tenha. Se n�o for necess�rio, tecle Enter):\n\n");
				fflush(stdin);
				gets(End[i].complet);
				printf("\nDigite o n�mero da casa no quintal (Caso precise. Se n�o for necess�rio, tecle Enter):\n\n");
				fflush(stdin);
				gets(End[i].casa);
				printf("\nDigite um ponto de refer�ncia (Caso tenha. Se n�o for necess�rio, tecle Enter):\n\n");
				fflush(stdin);
				gets(End[i].ref);
				printf("\n=======================================================================================================================\n\n");
}
	printf("Deseja cadastrar um outro endere�o? (S/N):\n\n");
	fflush(stdin);
	scanf("%c", &escolha);
	printf("\n");
  }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int consultaEnd(){
	setlocale(LC_ALL, "portuguese");
	int i, end, endfinal;
	char escolha = 's';
	system("cls");
	while(escolha =='S'||escolha=='s'){
		system("cls");
		printf("==================================================Consulta Endere�o==================================================\n\n");
		printf("Insira o endere�o inicial para a consulta:\n\n");
		scanf("%d", &end);
		printf("\n");
		printf("Insira o endere�o  final  para a consulta:\n\n");
		scanf("%d", &endfinal);
		printf("\n");
		system("cls");
		printf("=================================================Endere�os Cadastrados=================================================\n\n");
			for (i=end; i<=endfinal; i++){
				if (End[i].codEnd >0){
					printf("C�digo do endere�o:......%d\n\n", End[i].codEnd);
					printf("Nome do Estado:..........%s\n\n", End[i].nomeEst);
					printf("UF do Estado:............%s\n\n", End[i].UF);
					printf("Nome da cidade:..........%s\n\n", End[i].nomeCid);
					printf("Nome da Rua:.............%s\n\n", End[i].nomeRua);
					printf("Nome do bairro:..........%s\n\n", End[i].bairro);
					printf("CEP:.....................%s\n\n", End[i].numCep);
					printf("N�mero da casa(Rua):.....%s\n\n", End[i].numCas);
					printf("N�mero da casa(Quintal):.%s\n\n", End[i].casa);
					printf("Complemento:.............%s\n\n", End[i].complet);
					printf("Refer�ncia:..............%s\n\n", End[i].ref);
					printf("\n========================================================================================================================\n\n");
 }
				else {
					system("cls");
					printf("======================================Nenhum endere�o com o c�digo escolhido cadastrado!================================\n");
					sleep(1,0);
					menuEndereco();
 }
}
	printf("Deseja consultar um outro endere�o? (S/N): \n\n");
	fflush(stdin);
	scanf("%c", &escolha);
	printf("\n");
 }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int exclusaoEndereco(){
	setlocale(LC_ALL, "portuguese");
 	char escolha = 's';
 	int i, endfinal;
 	while(escolha =='S'||escolha=='s'){
 		system("cls");
 		printf("============================================Selecionar Endere�o para Exclus�o===========================================\n\n");
		printf("Insira o endere�o para a exclus�o:\n\n");
		scanf("%d", &endfinal);
		printf("\n");
			for (i=1; i=endfinal; i++){
				if(End[i].codEnd>0){
				system("cls");
				printf("===========================================Exclus�o de Endere�os Cadastrados============================================\n\n");
				End[i] = End[i-endfinal];
				printf("Endere�o escolhido exclu�do!\n\n");
				printf("========================================================================================================================\n\n");
				break;
}
			else{
				system("cls");
				printf("======================================Nenhum endere�o com o c�digo escolhido cadastrado!================================\n");
				sleep(2,0);
				menuEndereco();
 }
}
	printf("Deseja excluir um outro Endere�o? (S/N): \n\n");
	fflush(stdin);
	scanf("%c", &escolha);
	printf("\n");	
 }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int alterarEndereco(){
	setlocale(LC_ALL, "portuguese");
 	char escolha1 = 's';
 	int i, endfinal, opcao1;
 	while(escolha1 == 'S'||escolha1 == 's'){
 	system("cls");
 	printf("============================================Selecionar Endere�o para Altera��o==========================================\n\n");
	printf("Insira o endere�o para a altera��o:\n\n");
	scanf("%d", &endfinal);
	printf("\n");
	for (i=1; i=endfinal; i++){
		if(End[1].codEnd>0){
			system("cls");
			printf("=============================================Altera��o de endere�os Cadastrados=========================================\n\n");
			printf("\t\t\t\t                        Menu do Sistema\n\n");
			printf("\t  ============================================================================================================\n");
			printf("\t  |         op��o 1 - Alterar o nome do Estado        |         op��o 2 - Alterar o nome da cidade           |\n");
			printf("\t  ============================================================================================================\n");
			printf("\t  |         op��o 3 - Alterar o nome do Bairro        |         op��o 4 - Alterar o CEP                      |\n");
			printf("\t  ============================================================================================================\n");
			printf("\t  |         op��o 5 - Alterar o nome da Rua           |         op��o 6 - Alterar o n�mero da Casa (Rua)     |\n");
			printf("\t  ============================================================================================================\n");
			printf("\t  |         op��o 7 - Alterar o Complemento           |         op��o 8 - Alterar o n�mero da Casa (Quintal) |\n");
			printf("\t  ============================================================================================================\n");
			printf("\t  |         op��o 9 - Alterar o ponto de refer�ncia   |         Op��o 10 - Voltar ao Menu de endere�os       |\n");
			printf("\t  ============================================================================================================\n\n");
			printf("Digite a op��o desejada\n\n");
			scanf("%d", &opcao1);
			printf("\n");
				switch (opcao1){
					case 1:
						printf("Digite os dados do novo Estado:\n\n");
						fflush(stdin);
						scanf("%[^\n]",&End[i].nomeEst2);
						printf("\n");
						strcpy(End[i].nomeEst, End[i].nomeEst2);
						printf("Altera��o conclu�da!\n");
						sleep(1,0);
						break;
					case 2:
						printf("Digite os dados da nova Cidade:\n\n");
						fflush(stdin);
						scanf("%[^\n]",&End[i].nomeCid2);
						printf("\n");
						strcpy(End[i].nomeCid, End[i].nomeCid2);
						printf("Altera��o conclu�da!\n");
						sleep(1,0);
						break;
					case 3:
						printf("Digite os dados do novo Bairro:\n\n");
						fflush(stdin);
						scanf("%[^\n]",&End[i].bairro2);
						printf("\n");
						strcpy(End[i].bairro, End[i].bairro2);
						printf("Altera��o conclu�da!\n");
						sleep(1,0);
						break;
					case 4:
						printf("Digite os dados do novo CEP:\n\n");
						fflush(stdin);
						scanf("%[^\n]",&End[i].numCep2);
						printf("\n");
						strcpy(End[i].numCep, End[i].numCep2);
						printf("Altera��o conclu�da!\n");
						sleep(1,0);
						break;
					case 5: 
						printf("Digite os dados da nova Rua:\n\n");
						fflush(stdin);
						scanf("%[^\n]",&End[i].nomeRua2);
						printf("\n");
						strcpy(End[i].nomeRua, End[i].nomeRua2);
						printf("Altera��o conclu�da!\n");
						sleep(1,0);
						break;
					case 6:
						printf("Digite os dados do novo n�mero da casa:\n\n");
						fflush(stdin);
						scanf("%[^\n]",&End[i].numCas2);
						printf("\n");
						strcpy(End[i].numCas, End[i].numCas2);
						printf("Altera��o conclu�da!\n");
						sleep(1,0);
						break;
					case 7:
						printf("Digite os dados do novo Complemento:\n\n");
						fflush(stdin);
						scanf("%[^\n]",&End[i].complet2);
						printf("\n");
						strcpy(End[i].complet, End[i].complet2);
						printf("Altera��o conclu�da!\n");
						sleep(1,0);
						break;
					case 8:
						printf("Digite os dados do novo n�mero da casa (Quintal):\n\n");
						fflush(stdin);
						scanf("%[^\n]",&End[i].casa2);
						printf("\n");
						strcpy(End[i].casa, End[i].casa2);
						printf("Altera��o conclu�da!\n");
						sleep(1,0);
						break;
					case 9:
						printf("Digite os dados do novo Ponto de Refer�ncia:\n\n");
						fflush(stdin);
						scanf("%[^\n]",&End[i].ref2);
						printf("\n");
						strcpy(End[i].ref, End[i].ref2);
						printf("Altera��o conclu�da!\n");
						sleep(1,0);
						break;
					case 10:
						menuEndereco();
					default:
						printf("Digite um op��o v�lida!\n");
						printf("\a");
						sleep(1,0);
						break;	
 }
}
   		else{
			system("cls");
			printf("======================================Nenhum endere�o com o c�digo escolhido cadastrado!================================\n");
			sleep(2,0);
			menuEndereco();	
   }
  }
 }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int cadastroCartao(){
	setlocale(LC_ALL, "portuguese");
	char escolha = 's';
 	int i, cartao, cartaofinal;
 	system("cls");
 	while(escolha =='S'||escolha=='s'){
 		system("cls");
		printf("===================================================Cadastro de Cart�o===================================================\n\n");	
		printf("Insira o cart�o inicial para cadastro:\n\n");
		scanf("%d", &cartao);
		printf("\n");
		printf("Insira o cart�o  final  para cadastro:\n\n");
		scanf("%d", &cartaofinal);
		printf("\n");
			for (i=cartao; i<=cartaofinal; i++){	
				system("cls");
				printf("===================================================Cadastro de Cart�o===================================================\n\n");	
				printf("Digite o c�digo do cart�o:\n\n");
				scanf("%d", &Cart[i].codCart);
				printf("\n");
				printf("Digite o n�mero do cart�o (xxxx xxxx xxxx xxxx):\n\n");
				fflush(stdin);
				scanf("%[^\n]",&Cart[i].numCartao);
				printf("\n");
				printf("Digite a validade do cart�o (mm/aa):\n\n");
				fflush(stdin);
				scanf("%[^\n]",&Cart[i].numVal);
				printf("\n");
				printf("Digite o nome do propriet�rio do cart�o\n\n");
				fflush(stdin);
				scanf("%[^\n]",&Cart[i].nomeCart);
				printf("\n");
				printf("Digite o c�digo de seguran�a (xxx):\n\n");
				fflush(stdin);
				scanf("%[^\n]",&Cart[i].codSeg);
				printf("\n");
				printf("=======================================================================================================================\n\n");
}
	printf("Deseja cadastrar um outro cart�o? (S/N):\n\n");
	fflush(stdin);
	scanf("%c", &escolha);
	printf("\n");
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int consultaCartao(){
	setlocale(LC_ALL, "portuguese");
	int i, cartao, cartaofinal;
	char escolha = 's';
	while(escolha =='S'||escolha=='s'){
		system("cls");
		printf("===================================================Consulta Cart�o===================================================\n\n");	
		printf("Insira o cart�o inicial para a consulta:\n\n");
		scanf("%d", &cartao);
		printf("\n");
		printf("Insira o cart�o final para a consulta:\n\n");
		scanf("%d", &cartaofinal);
		printf("\n");
		system("cls");
		printf("===================================================Dados do Cart�o=====================================================\n");
			for (i=cartao; i<=cartaofinal; i++){
				if(Cart[i].codCart > 0){
					printf("\n");
					printf("C�digo do cart�o:.....%d\n\n", Cart[i].codCart);
					printf("Nome do Propriet�rio:.%s\n\n", Cart[i].nomeCart);
					printf("N�mero do Cart�o:.....%s\n\n", Cart[i].numCartao);
					printf("N�mero de Validade:...%s\n\n", Cart[i].numVal);
					printf("C�digo de Seguran�a:..%s\n\n", Cart[i].codSeg);
					printf("======================================================================================================================\n");
} 
				else {
					system("cls");
					printf("=====================================Nenhum cart�o com o c�digo escolhido cadastrado!==================================\n");
					sleep(1,0);
					menuCartao();
 }
}
	printf("\nDeseja consultar um outro cart�o? (S/N): \n\n");
	fflush(stdin);
	scanf("%c", &escolha);
	printf("\n");
  }
 }		
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int exclusaoCartao(){
	setlocale(LC_ALL, "portuguese");
 	char escolha = 's';
 	int i, cartao, cartaofinal;
 	while(escolha =='S'||escolha=='s'){
	 	system("cls");
	 	printf("============================================Selecionar cart�o para Exclus�o===========================================\n\n");
		printf("Insira o cart�o para a exclus�o:\n\n");
		scanf("%d", &cartaofinal);
		printf("\n");
		cartao=1;
			for (i=cartao; i=cartaofinal; i++){
				if(Cart[1].codCart>0){
					system("cls");
					printf("===========================================Exclus�o de cart�o Cadastrados============================================\n\n");
					Cart[i] = Cart[i-cartaofinal];
					printf("Cart�o escolhido exclu�do!\n\n");
					printf("========================================================================================================================\n\n");
			break;
}
				else{
					system("cls");
					printf("=====================================Nenhum cart�o com o c�digo escolhido cadastrado!==================================\n");
					sleep(2,0);
					menuCartao();		
 }
}
 	printf("Deseja excluir um outro cart�o? (S/N): \n\n");
	fflush(stdin);
	scanf("%c", &escolha);
	printf("\n");	
 }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int alterarCartao(){
	setlocale(LC_ALL, "portuguese");
 	char escolha = 's';
 	int i, conta, cartaofinal, opcao;
 	while(escolha =='S'||escolha=='s'){
	 	system("cls");
	 	printf("============================================Selecionar cart�es para Altera��o===========================================\n\n");
		printf("Insira o cart�o para a altera��o:\n\n");
		scanf("%d", &cartaofinal);
		printf("\n");
			for (i=1; i=cartaofinal; i++){
				if(Cart[i].codCart>0){
					system("cls");
					printf("==============================================Altera��o de Cart�es Cadastrados==========================================\n\n");
					printf("\t\t\t\t                        Menu do Sistema\n\n");
					printf("\t ============================================================================================================\n");
					printf("\t |  op��o 1 - Alterar n�mero do Cart�o                |   op��o 2 - Alterar a validade do Cart�o            |\n");
					printf("\t ============================================================================================================\n");
					printf("\t |  op��o 3 - Alterar nome do propriet�rio do Cart�o  |   op��o 4 - Alterar o c�digo de seguran�a do Cart�o |\n");
					printf("\t ============================================================================================================\n");
					printf("\t |                                  Op��o 5 - Voltar ao Menu dos Cart�es                                    |\n");
					printf("\t ============================================================================================================\n\n");
					printf("Digite a op��o desejada\n\n");
					scanf("%d", &opcao);
					printf("\n");
						switch (opcao){
							case 1:
								printf("Digite os dados do novo n�mero do cart�o (xxxx xxxx xxxx xxxx):\n\n");
								fflush(stdin);
								scanf("%[^\n]",&Cart[i].numCartao2);
								printf("\n");
								strcpy(Cart[i].numCartao, Cart[i].numCartao2);
								printf("Altera��o conclu�da!\n");
								sleep(1,0);
								break;
							case 2:
								printf("Digite os dados da nova validade (mm/aa):\n\n");
								fflush(stdin);
								scanf("%[^\n]",&Cart[i].numVal2);
								strcpy(Cart[i].numVal, Cart[i].numVal2);
								printf("\nAltera��o conclu�da!\n");
								sleep(1,0);
								break;
							case 3:
								printf("Digite os dados do novo nome do propriet�rio:\n\n");
								fflush(stdin);
								scanf("%[^\n]",&Cart[i].nomeCart2);
								printf("\n");
								strcpy(Cart[i].nomeCart, Cart[i].nomeCart2);
								printf("Altera��o conclu�da!\n");
								sleep(1,0);
								break;
							case 4:
								printf("Digite os dados do novo c�digo de seguran�a do cart�o (xxx):\n\n");
								fflush(stdin);
								scanf("%[^\n]",&Cart[i].codSeg2);
								printf("\n");
								strcpy(Cart[i].codSeg, Cart[i].codSeg2);
								printf("Altera��o conclu�da!\n");
								sleep(1,0);
								break;
							case 5: 
								menuCartao();
							default:
								printf("Digite um op��o v�lida!\n");
								printf("\a");
								sleep(1,0);
								break;	
 }
}
    			else{
					system("cls");
					printf("=====================================Nenhum cart�o com o c�digo escolhido cadastrado!==================================\n");
					sleep(2,0);
					menuCartao();	
	}
   }
  }
 }
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int cadastroConta(){
 	setlocale(LC_ALL, "portuguese");
 	char escolha = 's';
 	int i, conta, contafinal;
 	system("cls");
 	while(escolha =='S'||escolha=='s'){
		system("cls");
		printf("===================================================Cadastro de Conta===================================================\n\n");
		printf("Insira a conta inicial para cadastro:\n\n");
		scanf("%d", &conta);
		printf("\n");
		printf("Insira a conta final para  cadastro:\n\n");
		scanf("%d", &contafinal);
		printf("\n");
			for (i=conta; i<=contafinal; i++){	
				system("cls");
				printf("===================================================Cadastro de Conta===================================================\n\n");
				printf("Digite o C�digo da conta:\n\n");
				scanf("%d", &Cli[i].CodCli);
				printf("\n");
				printf("Digite o seu Nome e Sobrenome:\n\n");
				fflush(stdin);
				scanf("%[^\n]",&Cli[i].Nome);
				printf("\n");
				printf("Digite o seu Nome de Usu�rio:\n\n");
				fflush(stdin);
				scanf("%[^\n]",&Cli[i].Nome_Usuario);
				printf("\n");
				printf("Digite seu CPF (xxxxxxxxx-xx):\n\n");
				fflush(stdin);
				scanf("%[^\n]",&Cli[i].CPF);
				printf("\n");
				printf("Digite seu n�mero de telefone (+xx (xx) x xxxx-xxxx:)\n\n");
				fflush(stdin);
				scanf("%[^\n]",&Cli[i].NumeroTel);
				fflush(stdin);
				printf("\n");
				printf("Digite seu E-mail:\n\n");
				fflush(stdin);
				scanf("%[^\n]",&Cli[i].Email);
				fflush(stdin);
				printf("\n");
				printf("Digite sua senha:\n\n");
				fflush(stdin);
				scanf("%[^\n]",&Cli[i].Senha);
				printf("\n");
				printf("Repita a sua Senha: \n\n");
				fflush(stdin);
				scanf("%[^\n]",&Cli[i].Senha2);	
				printf("\n");
				printf("=======================================================================================================================\n\n");
}
	printf("Deseja cadastrar uma outra conta (S/N)?: \n\n");
	fflush(stdin);
	scanf("%c", &escolha);
	printf("\n");
  } 
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int consultaConta(){
	setlocale(LC_ALL, "portuguese");
 	char escolha='s';
 	int i, usuario, usuariofinal;
	while(escolha=='S'||escolha=='s') {
		system("cls");
		printf("====================================================Consulta de Conta===================================================\n\n");
		printf("Insira o conta inicial para consulta:\n\n");
		scanf("%d", &usuario);
		printf("\n");
		printf("Insira o conta  final  para consulta:\n\n");
		scanf("%d", &usuariofinal);
		printf("\n");
		system("cls");
		printf("==========================================Dados da(s) Conta(s) selecionada(s) ==========================================\n\n");
			for (i=usuario; i<=usuariofinal; i++){
				if(Cli[i].CodCli > 0){
					printf("C�digo da conta:....%d\n\n", Cli[i].CodCli);
					printf("Nome do usu�rio:....%s\n\n", Cli[i].Nome);
					printf("Nome de usu�rio:....%s\n\n", Cli[i].Nome_Usuario);
					printf("CPF:................%s\n\n", Cli[i].CPF);
					printf("Email:..............%s\n\n", Cli[i].Email);
					printf("N�mero de telefone:.%s\n\n", Cli[i].NumeroTel);
					printf("Senha:..............%s\n\n", Cli[i].Senha);
					printf("========================================================================================================================\n\n");
}
				else {
					system("cls");
					printf("=====================================Nenhuma conta com o c�digo escolhido cadastrada!==================================\n");
					sleep(1,0);
					menuConta();
 }
}
	printf("Deseja consultar uma outra conta? (S/N): \n\n");
	fflush(stdin);
	scanf("%c", &escolha);
	printf("\n");
  }
 }
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int exclusaoConta(){
	setlocale(LC_ALL, "portuguese");
 	char escolha = 's';
 	int i, conta, contafinal;
 	while(escolha =='S'||escolha=='s'){
	 	system("cls");
	 	printf("============================================Selecionar conta para Exclus�o===========================================\n\n");
		printf("Insira o conta para a exclus�o:\n\n");
		scanf("%d", &contafinal);
		printf("\n");
		conta=1;
			for (i=conta; i=contafinal; i++){
				if (Cli[i].CodCli>0){
					system("cls");
					printf("===========================================Exclus�o de conta Cadastrados===============================================\n\n");
					Cli[i] = Cli[i-contafinal];
					printf("Conta escolhida exclu�da!\n\n");
					printf("========================================================================================================================\n\n");
			break;
}
				else{
					system("cls");
					printf("=====================================Nenhuma conta com o c�digo escolhido cadastrada!==================================\n");
					sleep(2,0);
					menuConta();
 }
}	
	printf("Deseja excluir um outra conta? (S/N): \n\n");
	fflush(stdin);
	scanf("%c", &escolha);
	printf("\n");	
 }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int alterarConta(){
	setlocale(LC_ALL, "portuguese");
 	char escolha = 's';
 	int i, conta, contafinal, opcao;
 	while(escolha =='S'||escolha=='s'){
	 	system("cls");
	 	printf("============================================Selecionar Conta para Altera��o===========================================\n\n");
		printf("Insira a conta para a altera��o:\n\n");
		scanf("%d", &contafinal);
		printf("\n");
		conta=1;
		for (i=conta; i=contafinal; i++){
	 		if (Cli[i].CodCli>0){
				system("cls");
				printf("==================================================Altera��o de Contas Cadastradas======================================\n\n");
				printf("\t\t\t                              Menu do Sistema\n\n");
				printf("\t ========================================================================================================\n");
				printf("\t |  op��o 1 - Alterar Nome                          |  op��o 2 - Alterar Nome de Usu�rio                |\n");
				printf("\t ========================================================================================================\n");
				printf("\t |  op��o 3 - Alterar N�mero de Telefone            |  op��o 4 - Alterar E-mail                         |\n");
				printf("\t ========================================================================================================\n");
				printf("\t |  op��o 5 - Alterar Senha                         |  op��o 6 - Voltar ao Menu de Contas               |\n");
				printf("\t ========================================================================================================\n\n");
				printf("Digite a op��o desejada\n\n");
				scanf("%d", &opcao);
				printf("\n");
					switch (opcao){
						case 1:
							printf("Digite os dados do novo nome:\n\n");
							fflush(stdin);
							scanf("%[^\n]",&Cli[i].Nome2);
							printf("\n");
							strcpy(Cli[i].Nome, Cli[i].Nome2);
							printf("Altera��o conclu�da\n");
							sleep(1,0);
							break;
						case 2:
							printf("Digite os dados do novo nome de usu�rio:\n\n");
							fflush(stdin);
							scanf("%[^\n]",&Cli[i].Nome_Usuario2);
							printf("\n");
							strcpy(Cli[i].Nome_Usuario, Cli[i].Nome_Usuario2);
							printf("Altera��o conclu�da\n");
							sleep(1,0);
							break;
						case 3:
							printf("Digite os dados do novo n�mero de telefone:\n\n");
							fflush(stdin);
							scanf("%[^\n]",&Cli[i].NumeroTel2);
							printf("\n");
							strcpy(Cli[i].NumeroTel, Cli[i].NumeroTel2);
							printf("Altera��o conclu�da\n");
							sleep(1,0);
							break;
						case 4:
							printf("Digite os dados do novo e-mail:\n\n");
							fflush(stdin);
							scanf("%[^\n]",&Cli[i].Email2);
							printf("\n");
							strcpy(Cli[i].Email, Cli[i].Email2);
							printf("Altera��o conclu�da\n");
							sleep(1,0);
							break;
						case 5:
							printf("Digite os dados da nova senha:\n\n");
							fflush(stdin);
							scanf("%[^\n]",&Cli[i].Senha2);
							printf("\n");
							strcpy(Cli[i].Senha, Cli[i].Senha2);
							printf("Altera��o conclu�da\n");
							sleep(1,0);
							break;
						case 6: 
							menuConta();
						default:
							printf("Digite um op��o v�lida!\n");
							printf("\a");
							sleep(1,0);
							break;		
 }
}
   			else{
				system("cls");
				printf("=====================================Nenhuma conta com o c�digo escolhido cadastrada!==================================\n");
				sleep(2,0);
				menuConta();
   }
  }	
 }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int pagPix(){
	setlocale(LC_ALL, "portuguese");
	double codPix1, codPix2, codPix3;
	codPix1 = rand () % 9000000000 * 999999999999;
	codPix2 = rand () % 9000000000 * 999999999999;
	codPix3 = rand () % 9000000000 * 999999999999;
	printf("C�digo Pix: %.lf %.lf %.lf", codPix1, codPix2, codPix3);	
	//Fun��o da forma de pagameto PIX, que ser� gerado um n�mero aleat�rio.
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int compra(){
	setlocale(LC_ALL, "portuguese");
	int  a,i, cod, codPed, ped, pedfinal;
	double preco = 0;
	char escolha = 's';
	system("cls");
	while (escolha == 's' || escolha == 'S'){
	//Estruturas j� explicadas
		system("cls");
		printf("======================================================Pedidos==========================================================\n\n");	
		printf("Digite o c�digo do pedido que ser� realizados:\n\n");
		scanf("%d", &ped);
		system("cls");
		//Nesta parte do c�digo, n�o � poss�vel fazer pedidos em massa para evitar bugs no c�digo.
		printf("======================================================Menu de Compra====================================================\n\n");	
			for (i=ped; i<=ped; i++){
					if(Jogo[1].count>0){ //valida��o feita para caso n�o haja um jogo cadastrado, mostrar uma mensagem contida na cl�usula else.
						printf("N�mero do pedido: \n\n");
						scanf("%d", &pedido[i].codPed);
						//Aqui ser� cadastrado o c�digo do pedido. � uma boa pr�tica utilizar os c�digos de 1 � 30.
						printf("\nDigite o c�digo da conta para o pedido:\n\n");
						scanf("%d", &pedido[i].codusuc);
						//Sele��o  da conta para o pedido.
						printf("\nDigite o c�digo do jogo que voc� deseja comprar:\n\n");
						scanf("%d", &Jogo[i].count);
						//Sele��o do Jogo para compra com base no c�digo.
						printf("\nQual a quantidade que voc� deseja comprar?:\n\n");
						scanf("%d", &pedido[i].qtd); // Quantidade de jogos que ser�o comprados.
						pedido[i].preco = Jogo[Jogo[i].count].precoJogo * pedido[i].qtd; // c�lculo feito para o pre�o final do pedido, que por sua vez � armazenada num vetor que � armazenado em uma struct.
						printf("\t\t\t                              formas de pagamento\n\n");
						printf("\t\t    ===================================================================================\n");
						printf("\t\t    |op��o 1 - Cart�o                       | op��o 2 - PIX                           |\n");
						printf("\t\t    ===================================================================================\n");
						printf("\t\t    |                                 op��o 3 - Boleto                                |\n");
						printf("\t\t    ===================================================================================\n\n");
						printf("\nDigite a forma de pagamento desejada\n\n");
						scanf("%d", &pedido[i].pgto);
						//Menu de sele��o de formas de pagamentos
							if (pedido[i].pgto == 1){ 
								printf("\nDigite o c�digo de cadastro do cart�o desejado:\n\n");
								scanf("%d", &pedido[i].codcart);
							//Caso a forma de pagamento for 1, a fun��o para selecionar o cart�o desejado ser� mostrada.
							
}
								if (pedido[i].pgto == 2){
									printf("\n");
									printf("C�digo PIX gerado:\n\n");
									pagPix();
									sleep(2,0);
								//Caso a forma de pagamento foi 2, o c�digo PIX ser� adicionado ao pedido.
}
									if (pedido[i].pgto == 3){
										printf("\nDigite o c�digo da conta para o boleto:\n\n");
										scanf("%d", &pedido[i].codcont);
										printf("\nDigite o c�digo do endere�o para o boleto:\n\n");
										scanf("%d", &pedido[i].codend);
										printf("\nSelecione um banco para o boleto:\n\n");
										printf("\t\t\t                                    Bancos\n\n");
										printf("\t  ========================================================================================================\n");
										printf("\t  |op��o 1 - Caixa                                   | op��o 2 - Bradesco                                |\n");
										printf("\t  ========================================================================================================\n");
										printf("\t  |op��o 3 - Banco do Brasil                         | op��o 4 - Ita�                                    |\n");
										printf("\t  ========================================================================================================\n");
										printf("\t  |                                          op��o 5 - Santander                                         |\n");
										printf("\t  ========================================================================================================\n\n");
										scanf("%d", &pedido[i].codbol);
									//Caso for 3, ser� apresentado ao usu�rio algumas informa��es que seram apresentadas no boleto, e de qual banco ele ser�.
}
  	printf("\n=======================================================================================================================\n\n");
 }
				else {
					printf("\n================================Nenhum jogo com o c�digo escolhido cadastrado para realizar compras!====================\n");
					sleep(2,0);
					menuPedidos();
 }
}
  	printf("Deseja continuar? (S/N)\n\n");
	fflush(stdin);
 	scanf("%c", &escolha);	
 }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int detalhesPedido(){
	setlocale(LC_ALL, "portuguese");
	struct tm *data_hora_atual;    //Struct para mostrar a data e hora atual do sistema
	setlocale(LC_ALL, "potuguese");
	boleto[0].A = rand () % 9000000000 * 999999999999;
	boleto[1].B = rand () % 9000000000 * 999999999999; //c�digos de barras fict�cio para o boleto
	boleto[2].C = rand () % 9000000000 * 999999999999;
	time_t segundos; 
  	time(&segundos);   
  	data_hora_atual = localtime(&segundos);  //dados de data para o boleto
    srand(time(NULL)+20);
	int cod, codfinal, i;
	char escolha = 's';
	double preco;
	system("cls");
		while (escolha == 's'|| escolha == 'S'){
			printf("==================================================Detalhes do Pedido===================================================\n\n");
			system("cls");
			printf("Digite o c�digo inicial do pedido:\n\n");
			scanf("%d", &cod);
			printf("\nDigite o c�digo final do pedido para consulta:\n\n");
			scanf("%d", &codfinal);
			system("cls");
			printf("===============================================Detalhes do(s) Pedido(s)================================================\n\n");
				for(i=cod; i<=codfinal; i++){
						if (pedido[i].codPed>0){
							printf("N�mero do pedido:....%d\n\n"      ,pedido[i].codPed);
							printf("Cliente:.............%s\n\n"      ,Cli[pedido[i].codusuc].Nome);
							printf("C�digo do Jogo:......%d\n\n"      ,Jogo[Jogo[i].count].count);
							printf("Produtora do jogo:...%s\n\n"      ,Jogo[Jogo[i].count].prodJogo);
							printf("Nome do jogo:........%s\n\n"      ,Jogo[Jogo[i].count].nomeJogo);
							printf("Data de lan�amento:..%s\n"        ,Jogo[Jogo[i].count].DatLan);
							printf("\nPre�o:...............%.2lf\n\n" ,pedido[i].preco);
							printf("Quantidade:..........%d\n\n"      ,pedido[i].qtd);
							//Informa��es que ser�o mostradas ao usu�rio dos detalhes do pedidos
								if (pedido[i].pgto == 1) {
									printf("=================================================Cart�o Utilizado======================================================\n\n");
									printf("C�digo do cart�o:.....%d\n\n", Cart[pedido[i].codcart].codCart);
									printf("Nome do Propriet�rio:.%s\n\n", Cart[pedido[i].codcart].nomeCart);
									printf("N�mero do Cart�o:.....%s\n\n", Cart[pedido[i].codcart].numCartao);
									printf("N�mero de Validade:...%s\n\n", Cart[pedido[i].codcart].numVal);
									printf("C�digo de Seguran�a:..%s\n\n", Cart[pedido[i].codcart].codSeg);
}
							//Se a forma de pagamento for 1, ele mostrar� junto ao detalhes do pedidos o cart�o cadastrado que foi escolhido.
									if (pedido[i].pgto == 2){
										pagPix();
										printf("\n\n");
							// se a forma de pagamento foi 2, o c�digo pix ser� mostrado junto dos detalhes do pedido.
}
										if (pedido[i].pgto == 3){
							//Se for 3, ser� apresentado junto aos detalhes do pedido o boleto selecionado
											printf("=======================================================Boleto===========================================================\n\n");
												if (pedido[i].codbol == 1){ // if feito para cada banco que foi apresentado no menu de compra
													printf("=================================================Boleto Selecionado=====================================================\n\n");
													printf("\t\t-----------------------------------------------------------------------------------------------\n");
													printf("\t\t   Caixa        | C�digo de barras:         || |||||||| ||| ||||||| | || |||||||||||           \n");
													printf("\t\t                                            || |||||||| ||| ||||||| | || |||||||||||           \n");	
													printf("\t\t-----------------------------------------------------------------------------------------------\n");
													printf("\t\tLocal de pagamento: Pag�vel em qualquer lot�rica ou banco Caixa                                \n");
													printf("\t\t-----------------------------------------------------------------------------------------------\n");
													printf("\t\tBenefici�rio: Trinity Games                                                                    \n");
													printf("\t\tCNPJ:         95.493.124/0001-62                                                               \n");
													printf("\t\t-----------------------------------------------------------------------------------------------\n");
													printf("\t\t1| N�mero C�d Barras:       %.lf %.lf %.lf               \n", boleto[0].A, boleto[1].B, boleto[2].C); // C�digo de barras feito atrav�s dos c�digos defindos no in�cio da fun��o
													printf("\t\t-----------------------------------------------------------------------------------------------\n");
													printf("\t\tData de emiss�o:    %d/0%d/%d                                                                  \n", data_hora_atual-> tm_mday,  data_hora_atual-> tm_mon+1,  data_hora_atual-> tm_year+1900); // Estrutura para mostrar a data atual do sistema como data de emiss�o
													printf("\t\tData de vencimento: %d/0%d/%d                                                                  \n", data_hora_atual-> tm_mday + 1,  data_hora_atual-> tm_mon+1,  data_hora_atual-> tm_year+1900); //Estrutra para mostrar a data do dia seguinte do sistema como data de vencimento.
													printf("\t\t-----------------------------------------------------------------------------------------------\n");
													printf("\t\tValor do Documento: R$ %.2lf                                                                   \n", pedido[i].preco);
													printf("\t\tItens:              %s                                                                         \n", Jogo[Jogo[i].count].nomeJogo);
													printf("\t\t-----------------------------------------------------------------------------------------------\n");
													printf("\t\tQuantidade: %d                                                                                 \n", pedido[i].qtd);
													printf("\t\t-----------------------------------------------------------------------------------------------\n");
													printf("\t\tCliente: %s                                                                                    \n", Cli[pedido[i].codcont].Nome);
													printf("\t\tCPF:     %s                                                                                    \n", Cli[pedido[i].codcont].CPF);
													printf("\t\t-----------------------------------------------------------------------------------------------\n");
									   		        printf("\t\tEstado:      %s\n", End[pedido[i].codend].nomeEst);	
									   		        printf("\t\tUF:          %s\n", End[pedido[i].codend].UF);
									   		        printf("\t\tCidade:      %s\n", End[pedido[i].codend].nomeCid);
												   	printf("\t\tEndere�o     %s\n", End[pedido[i].codend].nomeRua);
									   				printf("\t\tCEP:         %s\n", End[pedido[i].codend].numCep);
									   				printf("\t\tN�mero Casa: %s\n", End[pedido[i].codend].numCas);
												    printf("\t\t-----------------------------------------------------------------------------------------------\n\n");	
}			
						 							if(pedido[i].codbol == 2){
													 	printf("===============================================Detalhes do(s) Pedido(s)================================================\n\n");
														printf("\t\t-----------------------------------------------------------------------------------------------\n");
														printf("\t\t     Bradesco   | C�digo de barras:         || |||||||| ||| ||||||| | || |||||||||||           \n");
														printf("\t\t                                            || |||||||| ||| ||||||| | || |||||||||||           \n");	
														printf("\t\t-----------------------------------------------------------------------------------------------\n");
														printf("\t\tLocal de pagamento: Pag�vel em qualquer lot�rica ou banco Caixa                                \n");
														printf("\t\t-----------------------------------------------------------------------------------------------\n");
														printf("\t\tBenefici�rio: Trinity Games                                                                    \n");
														printf("\t\tCNPJ:         95.493.124/0001-62                                                               \n");
														printf("\t\t-----------------------------------------------------------------------------------------------\n");
														printf("\t\t1| N�mero C�d Barras:       %.lf %.lf %.lf               \n", boleto[0].A, boleto[1].B, boleto[2].C);
														printf("\t\t-----------------------------------------------------------------------------------------------\n");
														printf("\t\tData de emiss�o:    %d/0%d/%d                                                                  \n", data_hora_atual-> tm_mday,  data_hora_atual-> tm_mon+1,  data_hora_atual-> tm_year+1900);
														printf("\t\tData de vencimento: %d/0%d/%d                                                                  \n", data_hora_atual-> tm_mday + 1,  data_hora_atual-> tm_mon+1,  data_hora_atual-> tm_year+1900);        
														printf("\t\t-----------------------------------------------------------------------------------------------\n");
														printf("\t\tValor do Documento: R$ %.2lf                                                                   \n", pedido[i].preco);
														printf("\t\tItens:              %s                                                                         \n", Jogo[Jogo[i].count].nomeJogo);
														printf("\t\t-----------------------------------------------------------------------------------------------\n");
														printf("\t\tQuantidade: %d                                                                                 \n", pedido[i].qtd);
														printf("\t\t-----------------------------------------------------------------------------------------------\n");
														printf("\t\tCliente: %s                                                                                    \n", Cli[pedido[i].codcont].Nome);
														printf("\t\tCPF:     %s                                                                                    \n", Cli[pedido[i].codcont].CPF);
														printf("\t\t-----------------------------------------------------------------------------------------------\n");
										   		        printf("\t\tEstado:      %s\n", End[pedido[i].codend].nomeEst);	
										   		        printf("\t\tUF:          %s\n", End[pedido[i].codend].UF);
										   		        printf("\t\tCidade:      %s\n", End[pedido[i].codend].nomeCid);
													   	printf("\t\tEndere�o     %s\n", End[pedido[i].codend].nomeRua);
										   				printf("\t\tCEP:         %s\n", End[pedido[i].codend].numCep);
										   				printf("\t\tN�mero Casa: %s\n", End[pedido[i].codend].numCas);
													    printf("\t\t-----------------------------------------------------------------------------------------------\n\n");		
}
															if(pedido[i].codbol == 3){
																printf("\t\t-----------------------------------------------------------------------------------------------\n");
																printf("\t\t Banco do Brasil | C�digo de barras:         || |||||||| ||| ||||||| | || |||||||||||          \n");
																printf("\t\t                                             || |||||||| ||| ||||||| | || |||||||||||          \n");	
																printf("\t\t-----------------------------------------------------------------------------------------------\n");
																printf("\t\tLocal de pagamento: Pag�vel em qualquer lot�rica ou banco Caixa                                \n");
																printf("\t\t-----------------------------------------------------------------------------------------------\n");
																printf("\t\tBenefici�rio: Trinity Games                                                                    \n");
																printf("\t\tCNPJ:         95.493.124/0001-62                                                               \n");
																printf("\t\t-----------------------------------------------------------------------------------------------\n");
																printf("\t\t1| N�mero C�d Barras:       %.lf %.lf %.lf               \n", boleto[0].A, boleto[1].B, boleto[2].C);
																printf("\t\t-----------------------------------------------------------------------------------------------\n");
																printf("\t\tData de emiss�o:    %d/0%d/%d                                                                  \n", data_hora_atual-> tm_mday,  data_hora_atual-> tm_mon+1,  data_hora_atual-> tm_year+1900);
																printf("\t\tData de vencimento: %d/0%d/%d                                                                  \n", data_hora_atual-> tm_mday + 1,  data_hora_atual-> tm_mon+1,  data_hora_atual-> tm_year+1900);        
																printf("\t\t-----------------------------------------------------------------------------------------------\n");
																printf("\t\tValor do Documento: R$ %.2lf                                                                   \n", pedido[i].preco);
																printf("\t\tItens:              %s                                                                         \n", Jogo[Jogo[i].count].nomeJogo);
																printf("\t\t-----------------------------------------------------------------------------------------------\n");
																printf("\t\tQuantidade: %d                                                                                 \n", pedido[i].qtd);
																printf("\t\t-----------------------------------------------------------------------------------------------\n");
																printf("\t\tCliente: %s                                                                                    \n", Cli[pedido[i].codcont].Nome);
																printf("\t\tCPF:     %s                                                                                    \n", Cli[pedido[i].codcont].CPF);
																printf("\t\t-----------------------------------------------------------------------------------------------\n");
												   		        printf("\t\tEstado:      %s\n", End[pedido[i].codend].nomeEst);	
												   		        printf("\t\tUF:          %s\n", End[pedido[i].codend].UF);
												   		        printf("\t\tCidade:      %s\n", End[pedido[i].codend].nomeCid);
															   	printf("\t\tEndere�o     %s\n", End[pedido[i].codend].nomeRua);
												   				printf("\t\tCEP:         %s\n", End[pedido[i].codend].numCep);
												   				printf("\t\tN�mero Casa: %s\n", End[pedido[i].codend].numCas);
															    printf("\t\t-----------------------------------------------------------------------------------------------\n\n");	
}
																if(pedido[i].codbol == 4){
																	printf("\t\t-----------------------------------------------------------------------------------------------\n");
																	printf("\t\t       Ita�      | C�digo de barras:         || |||||||| ||| ||||||| | || |||||||||||          \n");
																	printf("\t\t                                             || |||||||| ||| ||||||| | || |||||||||||          \n");	
																	printf("\t\t-----------------------------------------------------------------------------------------------\n");
																	printf("\t\tLocal de pagamento: Pag�vel em qualquer lot�rica ou banco Caixa                                \n");
																	printf("\t\t-----------------------------------------------------------------------------------------------\n");
																	printf("\t\tBenefici�rio: Trinity Games                                                                    \n");
																	printf("\t\tCNPJ:         95.493.124/0001-62                                                               \n");
																	printf("\t\t-----------------------------------------------------------------------------------------------\n");
																	printf("\t\t1| N�mero C�d Barras:       %.lf %.lf %.lf               \n", boleto[0].A, boleto[1].B, boleto[2].C);
																	printf("\t\t-----------------------------------------------------------------------------------------------\n");
																	printf("\t\tData de emiss�o:    %d/0%d/%d                                                                  \n", data_hora_atual-> tm_mday,  data_hora_atual-> tm_mon+1,  data_hora_atual-> tm_year+1900);
																	printf("\t\tData de vencimento: %d/0%d/%d                                                                  \n", data_hora_atual-> tm_mday + 1,  data_hora_atual-> tm_mon+1,  data_hora_atual-> tm_year+1900);        
																	printf("\t\t-----------------------------------------------------------------------------------------------\n");
																	printf("\t\tValor do Documento: R$ %.2lf                                                                   \n", pedido[i].preco);
																	printf("\t\tItens:              %s                                                                         \n", Jogo[Jogo[i].count].nomeJogo);
																	printf("\t\t-----------------------------------------------------------------------------------------------\n");
																	printf("\t\tQuantidade: %d                                                                                 \n", pedido[i].qtd);
																	printf("\t\t-----------------------------------------------------------------------------------------------\n");
																	printf("\t\tCliente: %s                                                                                    \n", Cli[pedido[i].codcont].Nome);
																	printf("\t\tCPF:     %s                                                                                    \n", Cli[pedido[i].codcont].CPF);
																	printf("\t\t-----------------------------------------------------------------------------------------------\n");
													   		        printf("\t\tEstado:      %s\n", End[pedido[i].codend].nomeEst);	
													   		        printf("\t\tUF:          %s\n", End[pedido[i].codend].UF);
													   		        printf("\t\tCidade:      %s\n", End[pedido[i].codend].nomeCid);
																   	printf("\t\tEndere�o     %s\n", End[pedido[i].codend].nomeRua);
													   				printf("\t\tCEP:         %s\n", End[pedido[i].codend].numCep);
													   				printf("\t\tN�mero Casa: %s\n", End[pedido[i].codend].numCas);
																    printf("\t\t-----------------------------------------------------------------------------------------------\n\n");	
}
																	if(pedido[i].codbol == 5){
																		printf("\t\t-----------------------------------------------------------------------------------------------\n");
																		printf("\t\t    Santander    | C�digo de barras:         || |||||||| ||| ||||||| | || |||||||||||          \n");
																		printf("\t\t                                             || |||||||| ||| ||||||| | || |||||||||||          \n");	
																		printf("\t\t-----------------------------------------------------------------------------------------------\n");
																		printf("\t\tLocal de pagamento: Pag�vel em qualquer lot�rica ou banco Caixa                                \n");
																		printf("\t\t-----------------------------------------------------------------------------------------------\n");
																		printf("\t\tBenefici�rio: Trinity Games                                                                    \n");
																		printf("\t\tCNPJ:         95.493.124/0001-62                                                               \n");
																		printf("\t\t-----------------------------------------------------------------------------------------------\n");
																		printf("\t\t1| N�mero C�d Barras:       %.lf %.lf %.lf               \n", boleto[0].A, boleto[1].B, boleto[2].C);
																		printf("\t\t-----------------------------------------------------------------------------------------------\n");
																		printf("\t\tData de emiss�o:    %d/0%d/%d                                                                  \n", data_hora_atual-> tm_mday,  data_hora_atual-> tm_mon+1,  data_hora_atual-> tm_year+1900);
																		printf("\t\tData de vencimento: %d/0%d/%d                                                                  \n", data_hora_atual-> tm_mday + 1,  data_hora_atual-> tm_mon+1,  data_hora_atual-> tm_year+1900);        
																		printf("\t\t-----------------------------------------------------------------------------------------------\n");
																		printf("\t\tValor do Documento: R$ %.2lf                                                                   \n", pedido[i].preco);
																		printf("\t\tItens:              %s                                                                         \n", Jogo[Jogo[i].count].nomeJogo);
																		printf("\t\t-----------------------------------------------------------------------------------------------\n");
																		printf("\t\tQuantidade: %d                                                                                 \n", pedido[i].qtd);
																		printf("\t\t-----------------------------------------------------------------------------------------------\n");
																		printf("\t\tCliente: %s                                                                                    \n", Cli[pedido[i].codcont].Nome);
																		printf("\t\tCPF:     %s                                                                                    \n", Cli[pedido[i].codcont].CPF);
																		printf("\t\t-----------------------------------------------------------------------------------------------\n");
														   		        printf("\t\tEstado:      %s\n", End[pedido[i].codend].nomeEst);	
														   		        printf("\t\tUF:          %s\n", End[pedido[i].codend].UF);
														   		        printf("\t\tCidade:      %s\n", End[pedido[i].codend].nomeCid);
																	   	printf("\t\tEndere�o     %s\n", End[pedido[i].codend].nomeRua);
														   				printf("\t\tCEP:         %s\n", End[pedido[i].codend].numCep);
														   				printf("\t\tN�mero Casa: %s\n", End[pedido[i].codend].numCas);
																	    printf("\t\t-----------------------------------------------------------------------------------------------\n\n");			
}
 }
						printf("=======================================================================================================================\n\n");		
}
	   				else {
					 printf("=================================================Nenhum pedido feito!==================================================\n");
					 sleep(2,0);
					 menuPedidos();
	}

}
	printf("Deseja continuar? (S/N)\n\n");
	fflush(stdin);
 	scanf("%c", &escolha);	
 } 
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int exclusaoPedido(){
	setlocale(LC_ALL, "portuguese");
 	char escolha = 's';
 	int i, ped, pedfinal;
 	while(escolha =='S'||escolha=='s'){
	 	system("cls");
	 	printf("============================================Selecionar pedido para Exclus�o=============================================\n\n");
		printf("Insira o n�mero do pedido para a exclus�o:\n\n");
		scanf("%d", &pedfinal);
		printf("\n");
		ped=1;
			for (i=ped; i=pedfinal; i++){
				if(pedido[i].codPed>0){
					system("cls");
					printf("===========================================Exclus�o de Pedidos Feitos==================================================\n\n");
					pedido[i] = pedido[i-pedfinal];
					printf("Pedido escolhido exclu�do!\n\n");
					printf("========================================================================================================================\n\n");
					break;
}
				else{
					system("cls");
					printf("=================================================Nenhuma pedido feito!=================================================\n");
					sleep(2,0);
					menuPedidos();
 }
}
	printf("Deseja excluir um outro pedido? (S/N): \n\n");
	fflush(stdin);
	scanf("%c", &escolha);
	printf("\n");	
 }
}

//Estrutura j� explicada.

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int detalhes(){
	setlocale(LC_ALL, "portuguese");	 	
	system("cls");
	printf("========================================================TRINITY GAMES==================================================\n\n");
	printf("Detalhes do software:\n\n");
	printf("Criado por:.......... Leonardo Cerqueira Gomes,   RA:921105737\n");
	printf("\n=======================================================================================================================\n\n");
	sleep(3,0);
	menuPrincipal();

}
