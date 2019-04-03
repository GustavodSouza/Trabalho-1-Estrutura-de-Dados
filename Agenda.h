typedef struct Agenda
{
	char nome[30];
	char sobrenome[30];
	char email[30];
	int telefone;
	struct Agenda *prox;
}agenda;

//Struct para favoritos e seria futuramente para o indice também.
typedef struct Indice
{
	char i;
	agenda* cabeca_agenda; // cabeça da agenda.
	struct Indice *prox;
}indice;

//======================================================================
//Busca todos elementos da lista.
void l_completa(agenda *inicio)
{
	agenda *aux = inicio;
	
	while(aux != NULL)
	{
		printf("\nNome: %s\n", aux->nome);
		printf("Sobrenome: %s\n", aux->sobrenome);
		printf("Email: %s\n", aux->email);
		printf("Telefone: %d\n", aux->telefone);
				
		aux = aux->prox;
	}
}

//=======================================================================
//Função para inserir strings ordenados.
agenda *insere(agenda *inicio)
{
	agenda *novo = (agenda*)malloc(sizeof(agenda));
	agenda *ant = NULL;
		
	printf("\nInforme o nome: ");
	fflush(stdin);
	gets(novo->nome);
				
	printf("Informe o sobrenome: ");
	fflush(stdin);
	gets(novo->sobrenome);
	
	printf("Informe o email: ");
	gets(novo->email);
	
	printf("Informe o telefone: ");
	scanf("%d", &novo->telefone);
	
	novo->prox = NULL;	//Aponta o novo para nulo.

	if (inicio == NULL || strcmp(inicio->nome, novo->nome) >= 0) //Verifica se o inicio é nulo.
	{															 //E compara a string que esta no inicio com a nova.
        novo->prox = inicio;									 
        return novo;
    } 
	else 
	{ // sen?oo inserimos no meio ou final
        agenda *p = inicio;
        while (p->prox != NULL && strcmp(p->prox->nome, novo->nome) < 0) 
		{
            p = p->prox;
        }
        novo->prox = p->prox;
        p->prox = novo;
        return inicio;
    }
}

//=======================================================================
//Função para imprimir elementos.
void imprime(agenda *inicio)
{
	int op;
	printf("\n\n<1> - Imprimir por letra\n<2> - Imprimir todos contatos\n");
	printf("Escolha uma opcao: ");
	scanf("%d", &op);
	
	if(op == 1)
	{
		if(inicio == NULL)
		{
			printf("\n\nA lista nao contem elementos\n\n");	
		}
		else
		{ //=====================ARRUMAR.
			agenda *aux = inicio;
			
			char letra[1];
			printf("\nInforme uma letra: ");
			fflush(stdin);
			gets(letra);
			strupr(letra); //Se a letra digitada for minuscula ele transforma para maiuscula.
			printf("\n========= NOMES COM A LETRA %s ===========\n", letra);
			
			while(aux != NULL) //Percorre a lista.
			{
				if(aux->nome[0] != letra[0]) //Verifica se a letra inicial é diferente da que foi informada.
				{
					aux = aux->prox; //Se não for, avança o aux.
				}
				else //Se não, printa os dados e avança o aux.
				{
					printf("Nome: %s\n", aux->nome);
					printf("Sobrenome: %s\n", aux->sobrenome);
					printf("Email: %s\n", aux->email);
					printf("Telefone: %d\n", aux->telefone);
					aux = aux->prox;
				}
			}
			getch();
		}		
	}
	else if(op == 2)
	{
		if(inicio == NULL)
		{
			printf("\n\nA lista nao contem elementos\n\n");	
			getch();
		}
		else
		{
			agenda *aux = inicio;
		
			printf("\n\n==========DADOS DA AGENDA===========\n\n");
			l_completa(inicio); //Chama a função de imprimir todos.
			getch();
		}
	}	
}
//=======================================================================
//Imprimir lista de favoritos.
void imprime_f(indice *f_inicio)
{
	indice *aux = f_inicio;
	
	if(f_inicio == NULL)
	{
		printf("\nA lista nao contem elementos\n");	
		getch();
	}	
	else
	{
		printf("\n\n==========LISTA DE FAVORITOS===========\n");
		while(aux != NULL)		
		{
			printf("\nNome: %s\n", aux->cabeca_agenda->nome);
			printf("Sobrenome: %s\n", aux->cabeca_agenda->sobrenome);
			printf("Email: %s\n", aux->cabeca_agenda->email);
			printf("Telefone: %d\n", aux->cabeca_agenda->telefone);
			aux = aux->prox;
		}
		getch();
	}
}


//=======================================================================
//Remover favoritos.
indice *f_retira(indice *f_inicio, char nome[])
{
	indice *aux = f_inicio;
	indice *ant = NULL;

	while(aux != NULL && strcmp(aux->cabeca_agenda->nome, nome) < 0)
	{
		ant = aux;
		aux = aux->prox;
	}
	if(aux == NULL)
	{
		return f_inicio;
	}
	if(ant == NULL)
	{
		f_inicio = aux->prox;
	}
	else
	{
		ant->prox = aux->prox;
	}	
	free(aux);
	system("cls");
	return f_inicio;
}

//=======================================================================
//Remover da lista principal
agenda *retira(agenda *inicio, char nome[])
{	
	agenda *aux = inicio;
	agenda *ant = NULL;
		
	while(aux != NULL && strcmp(aux->nome, nome) < 0)
	{
		ant = aux;
		aux = aux->prox;
	}
	
	if(aux == NULL)
	{
		return inicio;
	}
	if(ant == NULL)
	{
		inicio = aux->prox;
	}
	else
	{
		ant->prox = aux->prox;
	}	
	free(aux);
	system("cls");
	return inicio;
}
//=======================================================================
//Marcar como favorito.
indice *marcar(agenda *inicio, indice *f_inicio)
{
	agenda *aux = inicio;
	indice *novo_f = (indice*)malloc(sizeof(indice)); //Aloca um espaço para a segunda lista.
	
	if(inicio == NULL)
	{
		printf("\nA lista nao contem elementos\n\n");
		getch();
	}
	else
	{	
		system("cls");
		//Imprime os dados da lista;
		printf("==========DADOS DA AGENDA===========\n\n");	
		l_completa(inicio); //Chama a função para imprimir todos os dados.
		
		char nome_busca[30];
		printf("\n\nInforme o nome do contato favorito: ");
		fflush(stdin);
		gets(nome_busca);
		
		while(aux != NULL) //Varre a lista.
		{
			if(strcmp(aux->nome, nome_busca)==0) //Compara o nome que esta na lista com o nome de busca.
			{
				novo_f->cabeca_agenda = aux; //Faz o novo apontar para o nome que foi buscado. 
			}
			aux = aux->prox;
		}
		novo_f->prox = f_inicio;
		
		printf("\nContato %s adicionado como favorito!!!\n", nome_busca);
		getch();
	}
	return novo_f;
}

