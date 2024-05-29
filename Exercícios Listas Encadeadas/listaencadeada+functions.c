#include<stdlib.h>
#include<stdio.h>

// declaracao do no(node) da lista encadeada simples
struct node {
    int info;
    struct node *next;
};

// definicao do tipo Node
typedef struct node Node;

// declaracao da lista em si
struct lista {
    Node *head;
    //struct node *topo;
};

// definicao do tipo Lista
typedef struct lista Lista;

Node *newNode()
{
    Node *n;

    // Se nao puder alocar, retorna NULL
    n = malloc(sizeof(Node));

    return n;
}

void deleteNode(Node *n)
{
    if (n != NULL) free(n);
}

Lista *criar()
{
    Lista *L;

    L = malloc(sizeof(Lista));
    if (L != NULL) L->head = NULL; // lista vazia

    return L;
}

// Nessa versao, assume-se que nunca estara cheia
// Poderiamos limitar a quantidade de elementos...
int cheia(Lista *L)
{
    return 0;
}

int vazia(Lista *L)
{
    if (L->head == NULL) return 1;
    else return 0;
}

int inserir(Lista *L, int X)
{
	Node *Paux, *Pant; // Ponteiros auxiliares
	Node *P; // Ponteiro para o novo node

	// Se a lista esta cheia, nao pode inserir
	if (cheia(L)) return 0;

	// Cria o novo node e verifica se eh valido
	P = newNode();
	if (P == NULL) return 0;
	P->info = X;

	Paux = L->head;
	Pant = NULL;
	// Busca a possivel posicao de insercao
	while (Paux != NULL && Paux->info < X) {
		Pant = Paux;
		Paux = Paux->next;
	}

	// Elemento ja existente na lista
	if (Paux != NULL && Paux->info == X) return 0;

	if (Paux != L->head) {
		// Caso 1: Node inserido no interior da lista
		// (cauda?)
		Pant->next = P;
		P->next = Paux;
	} else {
		// Caso 2: Node inserido na primeira posicao
		// (cabeca)
		L->head = P;
		P->next = Paux;
	}

	return 1;
}

int remover(Lista *L, int X)
{
	Node *Paux, *Pant;

	Paux = L->head;
	Pant = NULL;

	// Busca o elemento a ser removido
	while (Paux != NULL && Paux->info < X) {
		Pant = Paux;
		Paux = Paux->next;
	}

	if (Paux != NULL && Paux->info == X) {
		// encontrei o elemento e vou retira-lo
		if (Paux != L->head) {
			Pant->next = Paux->next;
		} else {
			//L-head = L->head->next;
			L->head = Paux->next;
		}
		deleteNode(Paux);
		return 1;	// true, deu certo
	} else { // nao encontrei o elemento
		return 0;	// false, nao achou
	}
}

// Utiliza recursao de cauda
int comprimento_cauda(Node *P, int n)
{
	if (P == NULL) return n;
	else {
		return comprimento_auxiliar(P, n+1);
	}
}

int comprimento_auxiliar(Node *P)
{
	if (P == NULL) return 0;
	else {
		// tem ao menos um elemento
		// apontado pelo ponteiro P
		return (1 + comprimento_auxiliar(P->next));
	}
}

int comprimento(Lista *L)
{
	Node *P;
	int comp;

	P = L->head;
	//comp = comprimento_auxiliar(P);
	comp = comprimento_cauda(P, 0);

	return comp;
	// return comprimento_auxiliar(P);
}

int pertence_auxiliar(int X, Node *P)
{
	if (P == NULL) return 0;	// false
	else if (P->info == X) return 1;	// true
	else pertence_auxiliar(X, P->next);
}

int pertence(int X, Lista *L)
{
	// P = L->head;
	// return pertence_auxiliar(X, P);
	return pertence_auxiliar(X, L->head);
}

int ultimo_auxiliar (Node *P){
    if(P->next == NULL)
        return P->info;
    else
        ultimo_auxiliar(P->next);

}

int ultimo(Lista *L){
    Node *P;

    if(vazia(L))
        return 0;
    else{
	P = L->head;
	if(P->next == NULL)
        return P->info;
    else
        ultimo_auxiliar(P->next);
    }
}

int soma_auxiliar(Node *P){

    if(P->next == NULL)
        return P->info;
    else
        return (P->info + soma_auxiliar(P->next));

}

int soma (Lista *L){

    Node *P;
    P = L->head;
    if (vazia(L))
        return 0;
    else
        return soma_auxiliar(P);

}

sum_imparaux(Node *P){

    if(P->next == NULL){
        if((P->info % 2 != 0) ||(P->info % -2 != 0)){
            return P->info;}
         else
            return 0;
}
    else{
        if((P->info % 2 != 0) ||(P->info % -2 != 0)){
            return (P->info + sum_imparaux(P->next));
}
        else
           return (sum_imparaux(P->next));
    }
}

int sum_impar(Lista *L){

    Node *P;
    P = L->head;
    if (vazia(L))
        return 0;
    else
        return sum_imparaux(P);
}

int posicao_aux(Node *P, int X, int count){

    if(count <  X){
        posicao_aux(P->next, X, ++count);
    }
    else
        return P->info;
}

int posicao(Lista *L, int X){

    Node *P;
    P = L->head;
    if(vazia(L))
        return 0;
    else{
        if(X==0)
            return P->info;
        else
            return posicao_aux(P->next, X, 1);
    }

}

// NAO RESPEITA O TAD
void imprimir(Lista *L)
{
	Node *Paux;
	Paux = L->head;

	while (Paux != NULL) {
		printf("%d ", Paux->info);
		Paux = Paux->next;
	}
	printf("\n");
}

void destruir(Lista *L)
{
	// Avanca o head e deleta o Paux
	Node *Paux;

	while(!vazia(L)) {
		Paux = L->head;
		L->head = Paux->next;
		deleteNode(Paux);
	}


	free(L);
}

int main()
{
    Lista *L;

    // Criar a lista
    L = criar();
    if (L == NULL) {
        printf("Erro ao criar a lista\n");
        exit(1);
    }

    inserir(L, 1);
    imprimir(L);
    inserir(L, 2);
    imprimir(L);
    inserir(L, 3);
    imprimir(L);
    inserir(L, 4);
    imprimir(L);
    inserir(L, 7);
    imprimir(L);

    printf("O comprimento da lista eh: %d\n", comprimento(L));

    printf("O ultimo elemento eh: %d\n", ultimo(L));
    printf("A soma dos elementos eh: %d\n", soma(L));
    printf("A soma dos elementos impares eh: %d\n", sum_impar(L));
    printf("O elemento na posicao %d eh: %d\n", 3, posicao(L, 3));

    remover(L, 1);
    imprimir(L);

    printf("%d\n", remover(L, 2));
    imprimir(L);

    printf("%d\n", remover(L, 4));
    imprimir(L);

    printf("%d\n", remover(L, 7));
    imprimir(L);

    printf("O comprimento da lista eh: %d\n", comprimento(L));

    printf("O ultimo elemento eh: %d\n", ultimo(L));
    printf("A soma dos elementos eh: %d\n", soma(L));
    printf("A soma dos elementos impares eh: %d\n", sum_impar(L));
    printf("O elemento na posicao %d eh: %d\n", 3, posicao(L, 3));

    destruir(L);

    return 0;
}
