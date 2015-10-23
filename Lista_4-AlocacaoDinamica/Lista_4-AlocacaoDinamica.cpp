// Lista_4-AlocacaoDinamica.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define ARRAYSIZE 12

int *Ex1() {
	/* Implementa um vetor de tamanho arraysize com valor igual ao indice */
	int * vec = (int *)malloc(sizeof(int *) * ARRAYSIZE);
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		vec[i] = i;
	}

	return vec;
}

int *Ex2_SomaVec(int vec1[], int vec2[], int size) {
	/* Retorna um ponteiro contendo a soma dos vetores 1 e 2 em suas respectivas posições */
	int * vecSoma = (int *)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
	{
		vecSoma[i] = vec1[i] + vec2[i];
	}
	return vecSoma;
}

void Ex3_SomaVec(int vec1[], int vec2[], int soma[] ,int size) {
	/* Retorna um ponteiro contendo a soma dos vetores 1 e 2 em suas respectivas posições */
	for (int i = 0; i < size; i++)
	{
		soma[i] = vec1[i] + vec2[i];
	}
}

char * duplica(char *orig) {
	/* Buscar o tamanho total de caracteres no vetor */
	int pos = 0;
	while (orig[pos] != '\0')
	{
		pos++;
	}
	char * novoVector = (char *)malloc((sizeof(char) * pos) +1); // +1 para o '\0'
	/* Carrega o vetor antigo para o novo*/
	for (int i = 0; i < pos; i++)
	{
		novoVector[i] = orig[i];
	}
	novoVector[(sizeof(char) * pos)] = '\0'; // Última posição == \0
	return novoVector;
}

int * lista_maiores(int *vec, int size, int comparativo, int *qtd) {
	/* compara os valores maiores que comparativo e coloca em outro vetor (dinâmico) 
		A quantidade de números maiores deve ser atualizado no qtd*/

	// Conta quantos número são maiores que o comparativo
	int qtdMaiores = 0;
	for (int i = 0; i < size; i++)
	{
		if (vec[i] > comparativo)
		{
			qtdMaiores++;
		}
	}
	int *vecMaiores = (int *)malloc(sizeof(int) * qtdMaiores); // Aloca memória para o novo vetor
	if (qtdMaiores >0)
	{
		int counter = 0;
		for (int i = 0; i < size; i++)
		{
			if (vec[i] > comparativo)
			{
				vecMaiores[counter] = vec[i];
				counter++;
			}
		}
	}
	else
	{
		vecMaiores = NULL;
	}

	*qtd = qtdMaiores; // Atualiza o valor de qtdMaiores
	return vecMaiores;
}

void imprime_vetor(int* vet, int n) {
	/* Imprime o vetor */
	int i;
	printf("[");
	for (i = 0; i < n - 1; i++) {
		printf("%d, ", vet[i]);
	}
	printf("%d]\n", vet[n - 1]);
}

char * troca_letras(char *s) {
	/* Recebe um array de char e troca maiúsculas para minúsculas ( e vice-versa )
		retorna um novo array com as letras alteradas
	*/

	// TODO: Alterar caracteres acentuados, como [ç,á,ó,ô,ã,etc..]

	char * novoArray = (char *)malloc(sizeof(char) * strlen(s) +1 ); // Aloca memória para o novo arary
	if (novoArray == NULL) return novoArray; // Return NULL se não puder alocar memória

	for (int i = 0; i < strlen(s); i++)
	{
		/* Tratamento de pontuação, espaços e díigitos */
		if ((isblank(s[i])) || (ispunct(s[i])) || (isdigit(s[1])) )
		{
			novoArray[i] = s[i];
		}
		/* Tratamento de caracteres alfabéticos */
		else if (isalpha(s[i]))
		{
			if (islower(s[i]))
			{
				novoArray[i] = toupper(s[i]);
			}
			else
			{
				novoArray[i] = tolower(s[i]);
			}
		}
		else
		{
			novoArray[i] = s[i];
		}
	}
	novoArray[strlen(s)] = '\0';
	return novoArray;
}

char * inverte(char *s) {
	/* Retorna um array com a conteúdo do array passado de trás para frente */
	char * reverseArray = (char *)malloc(sizeof(char) * strlen(s) + 1); // Alocação dinâmica
	if (reverseArray == NULL) return reverseArray; // Return NULL se houver erro
	for (int i = strlen(s) -1; i >= 0; i--)
	{
		reverseArray[(strlen(s) - i) -1] = s[i];

	}
	reverseArray[strlen(s)] = '\0';
	return reverseArray;
}

char * ultimo_nome(char * nome_completo) {
	/* Retornar o último nome do array passado.
		Considerar que não há espaços após o último nome
		*/
	int new_size = 0;
	for (int i = strlen(nome_completo) - 1; i >= 0; i--)
	{
		if (isspace(nome_completo[i]))
		{
			break;
		}
		new_size++;
	}
	char * ultimo_nome = (char *)malloc((sizeof(char) *new_size) + 1);
	if (ultimo_nome == NULL) return ultimo_nome;

	int j = 0;
	for (int i = strlen(nome_completo) - new_size; i < strlen(nome_completo); i++)
	{
		ultimo_nome[j] = nome_completo[i];
		j++;
	}
	ultimo_nome[j] = '\0';
	return ultimo_nome;
}

int main()
{
	//TODO: Criar um menu para os exercícios, deixando tudo mais organizado!
	setlocale(LC_ALL, "");



	//printf("%d\n",Ex1());

	/* Ex. 2 - Soma de Vetores 
		A main deve mostrar erro caso não houver memória suficiente */
	/*
	int vec1[] = { 1,2,3,4,5 };
	int vec2[] = { 1,2,3,4,5 };

	int * soma = (int *)malloc(sizeof(int) *_countof(vec1));
	if (soma == NULL)
	{
		printf("Não há memória suficiente. Compre uma máquina devente");
	}
	else
	{
		soma = Ex2_SomaVec(vec1, vec2, _countof(vec1));
		for (int i = 0; i < _countof(vec1); i++)
		{
			printf("%d\n", soma[i]);
		}
	}*/

	/* Ex. 3 - Soma de vetores (modificada) 
		Alterar o ex.2 para que seja passado o vetor das somas.
		Pergunta: Onde deve ser realizado o malloc?
		Resposta: Antes de ser chamada a função de soma dos vetores*/
	/*
	int vec1[] = { 1,2,3,4,5 };
	int vec2[] = { 1,2,3,4,5 };

	int * soma = (int *)malloc(sizeof(int) *_countof(vec1));
	if (soma == NULL)
	{
		printf("Não há memória suficiente. Compre uma máquina devente");
	}
	else
	{
		Ex3_SomaVec(vec1, vec2, soma, _countof(vec1));
		for (int i = 0; i < _countof(vec1); i++)
		{
			printf("%d\n", soma[i]);
		}
	}
	*/

	/* Ex. 4 - malloc com strings */
	/*
	char s[] = "alo alo";
	char *ps;
	ps = duplica(s);
	if (ps == NULL) {
		printf("Tem algo errado que não esta certo!");
	}
	s[2] = 'O';
	printf("%s - %s\n", s, ps);
	free(ps);
	*/

	/* Ex. 5 - lista maiores vetores */
	/*
	int i;
	int numeros[10] = { 35, 10, 18, 9, 12, 60, 33, 15, 2, 8 };
	int limite;
	int* maiores;
	int n_maiores;
	printf("Vetor original = ");
	imprime_vetor(numeros, 10);
	while (1) {
		printf("Digite o valor limite (tecle -1 para sair): ");
		scanf_s("%d", &limite);
		if (limite == -1) {
			break;
		}
		maiores = lista_maiores(numeros, 10, limite, &n_maiores);
		if (maiores == NULL) {
			printf("Nada a declarar!\n");
		}
		else {
			printf("Valores maiores do que %d = ", limite);
			imprime_vetor(maiores, n_maiores);
		}
	}
	*/

	/* Ex. 6 - Troca Case de string */
	/*
	char vec[] = "aBcD ! ?.";
	printf("%s", troca_letras(vec));
	*/

	/* Ex. 7 - Inverte String */
	/*
	char vec[] = "aBcD ! ?.";
	printf("%s", inverte(vec));
	*/

	/* Ex. 8 - Ultimo Nome */
	/*
	char vec[] = "teste 1 2 3 abc";
	printf("%s", ultimo_nome(vec));
	*/
    return 0;
}

