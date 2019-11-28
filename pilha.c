#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[10];
    int idade;
}DADO;

typedef struct elemento{
    DADO dado;
    struct elemento *proximo;
} ELEM;

typedef struct{
    ELEM *topo;
}PILHA;

PILHA *criarPilha(){
    PILHA *novo = (PILHA*) malloc(sizeof(PILHA));
    if (novo != NULL){
        novo->topo = NULL; // Todo elemento da Pilha deve começar com NULL
    }
    return novo;
}

void inserirElemento(PILHA *pilha, DADO valor){

    if (pilha == NULL){
        printf("PILHA NAO ALOCADA");
        return;
    } else {
        ELEM *novo = (ELEM*) malloc(sizeof(ELEM));
        if (novo != NULL){
            novo->dado = valor;

            // SE A PILHA ESTIVER VAZIA
            if (pilha->topo == NULL){
                novo->proximo = NULL;
            // SE A PILHA NAO ESTIVER VAZIA
            } else {
                novo->proximo = pilha->topo;
            }

            pilha->topo = novo;
        }
    }
}

void removerElemento(PILHA *pilha){

    if (pilha == NULL){
        return; // PILHA NAO ALOCADA
    } else {
        // VERIFICO SE A PILHAO NAO ESTA VAZIA
        if (pilha->topo != NULL){
            ELEM *aux = pilha->topo;
            pilha->topo = pilha->topo->proximo;
            free(aux);
        } else {
            return; // PILHA VAZIA
        }
    }
}

void mostrarPilha(PILHA *pilha){

    if (pilha == NULL){
        printf("PILHA NAO ALOCADA");
        return;
    } else {
        if (pilha->topo != NULL){
            ELEM *aux = pilha->topo;

            while(aux != NULL){
                printf("DADUH - > \n");
                aux = aux->proximo;
            }
        }
    }
}

int tamanhoPilha(PILHA *pilha){

    int contador;

    if (pilha == NULL){
        printf("PILHA NAO ALOCADA");
        return -1;
    } else {
        if (pilha->topo != NULL){
            ELEM *aux = pilha->topo;

            while(aux != NULL){
                contador++;
                aux = aux->proximo;
            }
        } else {
            return 0;
        }
    }
    return contador;
}

void liberarPilha(PILHA *pilha){

    if (pilha == NULL){
        return;
    } else {
        ELEM *aux;
        while(pilha->topo != NULL){
            aux = pilha->topo;
            pilha->topo = pilha->topo->proximo;
            free(aux);
        }
        free(pilha);
    }
}


main(){


}
