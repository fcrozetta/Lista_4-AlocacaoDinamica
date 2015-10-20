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
	for (int i = 0; i < pos; i++)
	{
		novoVector[i] = orig[i];
	}
	novoVector[(sizeof(char) * pos) + 1] = '\0'; // Última posição == \0
	return novoVector;
}

int main()
{
	setlocale(LC_ALL, "");
	char * teste = "fernando";
	duplica(teste);

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
	char s[] = "alo alo";
	char *ps;
	ps = duplica(s);
	if (ps == NULL) {
		/* mensagem de erro e retorno que indica o erro */
		printf("Tem algo errado que não esta certo!");
	}
	s[2] = '\0';
	printf("%s - %s\n", s, ps);
	free(ps);
	
    return 0;
}

