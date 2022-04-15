//
// Created by rafae on 15/04/2022.
//
#include <stdio.h>
#include <stdlib.h>
#define FACIL 1
#define MEDIO 2
#define DIFICIL 3

typedef struct {
    int topo;
    int tamMax;
    int elem[];
} Pilha;

//Métodos de Pilha
void InicializaPilha(Pilha* pilha) {
    pilha->topo = -1;
}

int PilhaVazia(Pilha pilha) {
    return pilha.topo == -1;
}

int PilhaCheia(Pilha pilha) {
    return pilha.topo == pilha.tamMax;
}

void Empilha(Pilha* pilha, int newElem) {
    if (!PilhaCheia(*pilha)) {
        pilha->topo++;
        pilha->elem[pilha->topo] = newElem;
    }
}

void Desempilha(Pilha* pilha, int remElem) {
    if (!PilhaVazia(*pilha)) {
        remElem = pilha->elem[pilha->topo];
        pilha->topo--;
    }
}

int ElementoDoTopo(Pilha pilha) {
    if (!PilhaVazia(pilha)) {
        return pilha.elem[pilha.topo];
    } else {
        printf("Nao existe nenhum elemento no topo da pilha...");
        return NULL;
    }
}

//Métodos para o jogo

Pilha* InicializarPilhasJogo(int tamanhoPilhas) {
    Pilha* pilhas[tamanhoPilhas+2];
    for (int i = 0; i < tamanhoPilhas+2; i++) {
        pilhas[i] = malloc(sizeof(Pilha) + (sizeof(int[tamanhoPilhas])));
        pilhas[i]->tamMax = tamanhoPilhas;
        InicializaPilha(pilhas[i]);
        printf("Topo da pilha %d: %d \n", i, pilhas[i]->topo);
    }
    return *pilhas;
}

Pilha* SelecionarDificuldade() {
    printf("Selecione a dificuldade do jogo: \n 1) Fácil \n 2) Medio \n 3) Dificil \nsua resposta>");
    int opcao = 0;
    scanf("%d", &opcao);
    switch (opcao) {
        case FACIL:
            return InicializarPilhasJogo(3);
            break;
        case MEDIO:
            return InicializarPilhasJogo(4);
            break;
        case DIFICIL:
            return InicializarPilhasJogo(5);
            break;
        default:
            printf("Opcao desconhecida... \n");
            return SelecionarDificuldade();
    }
}
    void PrintarPilhas(Pilha* pilhas) {
        for (int linha = 0; linha < pilhas[0].tamMax; linha++) {
            for (int coluna = 0; coluna < pilhas[0].tamMax+2; coluna++) {
                if (pilhas[coluna].topo < coluna || PilhaVazia(pilhas[coluna])) {
                    printf("- ");
                } else {
                    printf("%d ", pilhas[coluna].elem[linha]);
                }
            }
            printf("\n");
        }
    }
