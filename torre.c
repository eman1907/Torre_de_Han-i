#include <stdio.h>
#include <stdlib.h>
#include "torre.h" 

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

void pilha_imprime(Pilha* p1, Pilha* p2, Pilha* p3){

    int cont = 0;
    PilhaNo* n = p1->topo;
    PilhaNo* n2 = p2->topo;
    PilhaNo* n3 = p3->topo;
    while(n != NULL || n2 != NULL || n3 != NULL){
        cont++;
        if (n != NULL) n = n->prox;
        if (n2 != NULL) n2 = n2->prox;
        if (n3 != NULL) n3 = n3->prox;
    }


    PilhaNo* x = p1->topo;
    PilhaNo* x2 = p2->topo;
    PilhaNo* x3 = p3->topo;
    printf("\n");
    for (int i = cont; i > 0; i--){ 
        if (pilha_tamanho(p1) >= i){
            printf("%d " , x->valor);
            x = x->prox;
        }
        else if (i == 1 && p1->topo == NULL) printf("0 ");
        else printf("  ");

         if (pilha_tamanho(p2) >= i){
            printf("%d " , x2->valor);
            x2 = x2->prox;
        }
        else if (i == 1 && p2->topo == NULL) printf("0 ");
        else printf("  ");

         if (pilha_tamanho(p3) >= i){
            printf("%d " , x3->valor);
            x3 = x3->prox; 
        }
        else if (i == 1 && p3->topo == NULL) printf("0 ");
        else printf("  ");

        printf("\n");  
    } 
} 


int pilha_tamanho(Pilha* p){
    int cont = 0;
    PilhaNo* n;
    for (n = p->topo; n != NULL; n = n->prox){
        cont++;
    }
    return cont;
}
