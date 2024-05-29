// Aula 16/05


// declaracao do no(node) da lista encadeada simples
struct node {
    char info;
    struct node *next;
};

// definicao do tipo Node
typedef struct node Node;

struct fila {
	Node *primeiro;
	Node *ultimo;
}

typedef struct fila Fila;

Node *newNode(){
	Node *n;

	n= malloc(sizeof(Node));

	return n;
}

void deleteNode(Node *n){
	if (n != NULL) free(n);
}

Fila *criar(){
	Fila *F;

	F = malloc(sizeof(Fila));
	if(F != NULL){
		F->primeiro = NULL;
		F->ultimo = NULL;
	}

	return F;
}

int cheia(Fila *F){
	return 0;
}

int vazia(Fila *F){
	// Basta verificar se um dos ponteiros é nulo
	// Caso seja, a fila está vazia...
	if (F->primeiro == NULL) return 1;
	else return 0;
}

int inserir(Fila *F, char X){
	if(cheia(F) =! 1)
		Node *Faux;
		Faux = newNode(); // poderia ser tudo em uma linha: Node *Paux = newNode();
		Faux->info = X;
		Faux->next = NULL;	// campo next de todo novo nó sempre é nulo
		if(vazia(F) == 1){
			F->primeiro = Faux;
			F->ultimo = Faux;
			return 1;
		}
		else{
			F->ultimo->next = Faux;
			F->ultimo = Faux;
			return 1;
		}

	else
		return 0;	
}

int retira(Fila *F, char *X){
	if(vazia(F) != 1){
		*X = F->primeiro->info;
		F->primeiro = F->primeiro->next;
		if(F->primeiro == NULL)			// fila tinha um unico elemento
			F->ultimo == NULL;
		return 1;
	}else
		return 0;
}

int main()
{
    Fila *F;
    char valor;
    
    // Criar a pilha
    F = criar();
    if (F == NULL) {
        printf("Erro ao criar a fila\n");
        exit(1);
    }
    
    printf("%d\n", empilhar(F, 'A'));
    printf("%d\n", empilhar(F, 'B'));
    printf("%d\n", empilhar(F, 'C'));
    
    // alternativa: while(!vazia(P)) {
    while(vazia(P) != 1) {
    	desempilhar(P, &valor);
    	printf("%c ", valor);
    }
    printf("\n");
        
    return 0;
}
