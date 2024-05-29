#include<stdlib.h>
#include<stdio.h>

#define  MAX  5

// Definir a ED pilha
struct pilha {
	int topo;
	char elementos[MAX];
};

// Definir o tipo de dados Pilha
typedef struct pilha Pilha;

/*
  Entrada: nao existe
  Saida: ponteiro para Pilha, ou NULL caso nao seja possivel cria-la
  Pre-condicao: nao existe
  Pos-condicao: nao existe
*/
Pilha *criar()
{
	
	Pilha *p;

	p = malloc(sizeof(Pilha));
	if (p != NULL)
		p->topo = -1;

	return p;
}

/* 
 * Entrada: uma pilha
 * Saida: nao existe
 * Pre-condicao: nao existe
 * Pos-condicao: memoria da pilha liberada
 */
void destruir(Pilha *p)
{
	if (p != NULL) free(p);
}

/*
 * Entrada: uma pilha
 * Saida: 1 se a pilha for vazia, 0 caso contrario
 * Pre-condicao: pilha deve ser valida
 * Pos-condicao: nao existe
 */
int vazia(Pilha *p)
{
	if (p->topo == -1) return 1; // true
	else return 0; // false
}

/*
 * Entrada: uma pilha
 * Saida: 1 se a pilha for cheia, 0 caso contrario
 * Pre-condicao: pilha deve ser valida
 * Pos-condicao: nao existe
 */
int cheia(Pilha *p)
{
	if (p->topo == (MAX-1))
		return 1; // true
	else return 0; // false
}

/*
 * Entrada: uma pilha e um caractere
 * Saida: 1 se bem sucedida, 0 caso contrario
 * Pre-condicao: pilha tem que ser valida e caractere tambem
 * Pos-condicao: conteudo da pilha alterado
 */
int empilhar(Pilha *p, char x)
{
	if (cheia(p) == 1)
		return 0;	// false
	else {
		p->topo = p->topo + 1;
		p->elementos[ p->topo ] = x;
		
		return 1;	// true
	}
}

/*
 * Entrada: uma pilha e um caractere passado por referencia
 * Saida: 1 se bem sucedida, 0 caso contrario
 * Pre-condicao: pilha tem que ser valida
 * Pos-condicao: conteudo da pilha alterado
 */
int desempilhar(Pilha *p, char *x)
{
	if (vazia(p) == 1)
		return 0;	// false
	else {
		*x = p->elementos[ p->topo ];
		p->topo = p->topo - 1;
		
		return 1;	// true
	}
}



int main()
{
	Pilha *P;
	char c;

	int teste;

	P = criar();
	if (P == NULL) {
		printf("Erro: nao foi possivel criar a pilha\n");
		exit(-1);
	}

	/*for (int i = 0; i < 8; i++) {
		printf("Digite um caractere: ");
		scanf(" %c", &c);

		teste = empilhar(P, c);
		printf("Teste = %d\n", teste);
	}*/

	while (cheia(P) == 0) {
		printf("Digite um caractere: ");
		scanf(" %c", &c);
		empilhar(P, c);
	}

	while (desempilhar(P, &c) == 1)
		printf("%c\n", c);

	destruir(P);

	return 0;
}