#include <stdio.h>
#include <stdlib.h>

typedef struct pilha Pilha; //nova linha de TESTE
typedef struct pilhano PilhaNo;

struct pilha{
    PilhaNo* topo;
};

struct pilhano{
    int valor;
    PilhaNo* prox;
};

Pilha* pilha_cria();
//cria uma pilha vazia 

void pilha_push(Pilha* p, int v);
//adicona um elemento no topo da pilha

int pilha_pop(Pilha* p); 
//retira o elemento do topo da pilha

int tamanho_pilha(Pilha* p);
//retorna a quantidade de elementos na pilha

void imprime_pilhas(Pilha* p1, Pilha* p2, Pilha* p3); 
//imprime as tres pilhas 

int valor_topo(Pilha* p);
//retorna o valor do topo sem o remover

void libera_pilha(Pilha* p); 
//libera a memoria alocada para a pilha
