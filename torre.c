#include "pilha.h"

Pilha* pilha_cria(){
    Pilha* p = malloc(sizeof(Pilha));
    if (p == NULL) exit(1);
    p->topo = NULL;
    return p;
}

void pilha_push(Pilha* p, int v){
    PilhaNo* n = malloc(sizeof(PilhaNo));
    if (n == NULL) exit(1);
    n->valor = v;
    n->prox = p->topo;
    p->topo = n; 
}

int pilha_pop(Pilha* p){
    PilhaNo* n = p->topo;
    int v = n->valor;
    p->topo = n->prox;
    free(n);
    return v; 
}

int tamanho_pilha(Pilha* p){
    int cont = 0; 
    PilhaNo* n;
    for (n = p->topo; n != NULL; n = n->prox) 
        cont++;
    return cont;
}

void imprime_pilhas(Pilha* p1, Pilha* p2, Pilha* p3){
    int tamanho;
    if (tamanho_pilha(p1) >= tamanho_pilha(p2) && tamanho_pilha(p1) >= tamanho_pilha(p3)){
        tamanho = tamanho_pilha(p1);
    } else if (tamanho_pilha(p2) >= tamanho_pilha(p1) && tamanho_pilha(p2) >= tamanho_pilha(p3)){
        tamanho = tamanho_pilha(p2);
    } else {
        tamanho = tamanho_pilha(p3); 
    }
    //calcula o tamanho da pilha mais alta entre as 3 

    PilhaNo* n1, *n2, *n3;
    n1 = p1->topo;
    n2 = p2->topo;
    n3 = p3->topo;
    for (int i = tamanho; i > 0; i--){
        if (tamanho_pilha(p1) >= i) {
            printf("%d " , n1->valor);
            n1 = n1->prox;
        } else if (i == 1 && p1->topo == NULL) printf("0 ");
        else printf("  ");

        if (tamanho_pilha(p2) >= i) {
            printf("%d " , n2->valor);
            n2 = n2->prox;
        } else if (i == 1 && p2->topo == NULL) printf("0 ");
        else printf("  ");

        if (tamanho_pilha(p3) >= i) {
            printf("%d " , n3->valor);
            n3 = n3->prox;
        } else if (i == 1 && p3->topo == NULL) printf("0 ");
        else printf("  ");

        printf("\n");
    }
}

int valor_topo(Pilha* p){
    return p->topo->valor; 
}

void libera_pilha(Pilha* p){
    PilhaNo* n = p->topo;
    while (n != NULL){
        PilhaNo* temp = n;
        n = n->prox;
        free(temp);
    }
    free(p);
    p = NULL;  
}
