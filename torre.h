typedef struct pilha Pilha; //nomeia a struct pilha como "Pilha"
typedef struct pilhano PilhaNo; //nomeia a struct pilhano como "PilhaNo"

struct pilha{
    PilhaNo* topo; //ponteiro para o topo da pilha
};

struct pilhano{
    int valor; //tamanho de cada pino da torre
    PilhaNo* prox; //ponteiro para o pino "de baixo"
};

Pilha* pilha_cria(); 
//cria uma estrutura de pilha, apontando o topo para NULL

void pilha_push(Pilha* p, int v);
//adiciona um elemento ao topo da pilha sempre que solicitado

int pilha_pop(Pilha* p);
//retira o elemento do topo da pilha sempre que solicitado 

void pilha_imprime(Pilha* p1, Pilha* p2, Pilha* p3); 
/*imprime as tres pilhas, que representam os pinos da torre, na sua devida 
ordem com cada disco correspondente, entretanto, se a pilha estiver vazia, 
será impresso o número "0"*/

int pilha_tamanho(Pilha* p);
/*retorna a quantidade de elementos na pilha para indicar tanto se o
usuário ganhou o jogo, quando a pilha 2 ou 3 estiver completa, quanto para 
auxiliar na impressão de cada valor dentro da função "pilha_imprime"*/
