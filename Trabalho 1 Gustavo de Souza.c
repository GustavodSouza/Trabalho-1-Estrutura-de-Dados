#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Agenda.h"

//Gustavo de Souza 201521291.

/*Esta faltanto criar as letras conforme inserção
Insere os nome de forma ordenada.
Permite busca inserindo apenas a letra inicial.
Permite inserir nos favoritos (Agora através de ponteiros).
Remoção da lista principal
Remoção dos favoritos com alguns bugs. 
*/

//=======================================================================
//Função principal.
main()
{
	agenda *inicio = NULL; 
	indice *f_inicio = NULL;
	
	int op = 1;
	while(op != 0)
	{
		system("cls");
		printf("\t\tAGENDA TELEFONICA\tBY: Gustavo de Souza UFSM\t\n");
		printf("\n--------MENU---------\n\n");
		printf("<1> Inserir contatos\n");
		printf("<2> Remover contatos\n");
		printf("<3> Imprimir contatos\n");
		printf("\n\n------FAVORITOS------\n\n");
		printf("<4> Inserir favoritos\n");
		printf("<5> Imprimir favoritos\n");
		printf("<6> Remover favoritos\n");
		printf("\n\n<0> Sair do programa\n\n");
		printf("\nEscolha uma opcao: ");
		scanf("%d", &op);
		
		if(op == 1)
		{
			inicio = insere(inicio);
		}
		else if(op == 2)
		{
			char nome[30];
			printf("\nInforme o nome que deseja remover: ");
			fflush(stdin);
	 		gets(nome);
			inicio = retira(inicio, nome);
			f_inicio = f_retira(f_inicio, nome); //A ideia aqui é que ao remover um elemento da principal esse mesmo elemento é passado para a
												//remoção na lista de favoritos.
		}
		else if(op == 3)
		{
			imprime(inicio);
		}
		else if(op == 4)
		{
			f_inicio = marcar(inicio, f_inicio);
		}
		else if(op == 5)
		{
			imprime_f(f_inicio);
		}
		else if(op == 6)
		{
			char nome[30];
			printf("\nInforme o nome que deseja remover: ");
			fflush(stdin);
			gets(nome);
			f_inicio = f_retira(f_inicio, nome);
		}
	}
	system("cls");
	printf("ATE A PROXIMA :D\n");
	system("pause");
}
