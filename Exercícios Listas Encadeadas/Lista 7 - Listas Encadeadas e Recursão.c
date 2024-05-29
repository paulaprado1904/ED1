#Questão 1

int pertence_auxiliar(char X, Node *P)
{
	if (P == NULL) return 0;	// false
	else if (P->info == X) return 1;	// true
	else pertence_auxiliar(X, P->next);
}

int pertence(char X, Lista *L)
{
	// P = L->head;
	// return pertence_auxiliar(X, P);
	return pertence_auxiliar(X, L->head);


#Questão 2

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

#Questão 3

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


#Questão 4

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


#Questão 5


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

#Questão 6

int comprimento_cauda(Node *P, int n)
{
	if (P == NULL) return n;
	else {
		return comprimento_cauda(P, n+1);
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