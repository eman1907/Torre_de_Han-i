#include "pilha.h"

int main(){
    Pilha* p[3];
    for (int i = 0; i < 3; i++){
        p[i] = pilha_cria(); 
    }

    int N; //N = quantidade de discos 
    printf("Indique o numero a quantidade de discos N: ");
    scanf("%d" , &N);

    for (int i = N; i > 0; i--){
        pilha_push(p[0], i);
    }

    for (int i = 1; i < N ; i++){
        printf("%d\n" , i);
    }
    printf("%d 0 0\n" , N);
    printf("- - -\n1 2 3\n"); 
    //imprime pilha inicial para usário ter noção das dimensões

    int ini, fim, transf, cont_jogadas;
    cont_jogadas = 0; 
    while(1){
        printf("\njogada: ");
        scanf("%d, %d" , &ini, &fim); 
        printf("\n"); 
        ini--;
        fim--;

        if (ini == fim ||
            (ini < 0 || ini > 2 || fim < 0 || fim > 2) ||
             p[ini]->topo == NULL || 
            (p[fim]->topo && valor_topo(p[ini]) > valor_topo(p[fim]))){
            printf("Jogada invalida!\n");

        } else {

        transf = pilha_pop(p[ini]);
        pilha_push(p[fim], transf);
        cont_jogadas++;

        imprime_pilhas(p[0], p[1], p[2]);
        printf("- - -\n");
        printf("1 2 3\n"); 


        if (tamanho_pilha(p[1]) == N || tamanho_pilha(p[2]) == N) break; 
        }
    }
    printf("\nVoce venceu com %d jogadas!\n" , cont_jogadas); 

    for (int i = 0; i < 3; i++)
        libera_pilha(p[i]);
    
    return 0; 
}
