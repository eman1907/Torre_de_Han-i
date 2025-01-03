#include <stdio.h>
#include <stdlib.h>
#include "torre.h" 

int main(){  
    Pilha* p[3];
    for(int i = 0; i < 3; i++){ 
        p[i] = pilha_cria(); //cria tres pilhas que representam os 3 discos do jogo 
    }

    printf("Indique a quantidade de discos N: "); 
    //pergunta ao usuário o número de discos que farão parte a primeira torre 

    int n;
    scanf("%d", &n);
    for (int i = n; i > 0; i--){
        pilha_push(p[0], i);  //inclui os numeros de 1 a n na primeira torre
    } 

    printf("\n");
    for (int i = 1; i <= n; i++){ 
        if (i == n) printf("%d 0 0\n" , n); 
        else printf("%d\n" , i);
    }
     printf("- - -\n");
     printf("1 2 3\n"); 
     //imprime uma simulação das tres pilhas para o usuário ter noção 
     //das dimensões do jogo


    int said, ent, num, cont; 
    cont = 0;
    printf("\njogada: "); //indica a jogada inicial
    while(scanf("%d,%d" , &said, &ent)){  
        //lê primeiro a torre que vai ter um disco retirado e depois a 
        //torre em que o mesmo será adicionado

     if ((ent > 3 || ent < 1) || (said > 3 || said < 1)){ 
        printf("Jogada indisponivel!\n"); //indica que os discos só vão de 1 a 3
     }

     else if (p[said - 1]->topo == NULL){
        printf("Jogada indisponivel!\n"); //indica que não se pode retirar discos de 
     }                                    //uma torre vazia

     else if (p[ent - 1]->topo != NULL && (p[said - 1]->topo->valor > p[ent - 1]->topo->valor)){  
        printf("Jogada indisponivel!\n");   //indica que não se pode adicionar um disco maior
     }                                      //em cima de um menor pelas regras do jogo

    else {
        said--;
        ent--;
        num = pilha_pop(p[said]);
        pilha_push(p[ent], num); 

        pilha_imprime(p[0], p[1], p[2]); 
        printf("- - -\n"); //indica ao usuário o
        printf("1 2 3\n"); //número de cada torre

        cont++; //conta o número de jogadas que o usuário
                //precisou para vencer o jogo 

    if (pilha_tamanho(p[1]) == n || pilha_tamanho(p[2]) == n){ 
        printf("Parabens, vc venceu com %d jogadas!\n\n" , cont);  
        break;  //indica a vitória do usuário quando a torre 2 ou 3 estiver completa
              } 
         }
        printf("\njogada: "); //indica as jogadas do usário com exceção da inicial 
    } 

    pilha_libera(p[0]);
    pilha_libera(p[1]);
    pilha_libera(p[3]);
    
    return 0;    
} 
