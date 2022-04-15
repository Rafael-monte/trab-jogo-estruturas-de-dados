#include <stdio.h>
#define FACIL 1
#define MEDIO 2
#define DIFICIL 3

#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#endif // PILHA_H_INCLUDED

typedef struct Pilha {
    int topo = -1;
    int tamMax = 0;
    int elem[];
}

//Métodos de Pilha
void InicializaPilha(Pilha* pilha) {
    *pilha.topo=-1;
}

bool PilhaVazia(Pilha* pilha) {
    return *pilha.topo == -1;
}

bool PilhaCheia(Pilha* pilha) {
    return *pilha.topo == *pilha.tamMax;
}

void Empilha(Pilha* pilha, int newElem) {
    if (!PilhaCheia(pilha)) {
        *pilha.topo++;
        *pilha.elem[*pilha.topo] = newElem;
    }
}

void Desempilha(Pilha* pilha, int remElem) {
    if (!PilhaVazia(pilha)) {
        remElem = *pilha.elem[*pilha.topo];
        *pilha.topo--;
    }
}

int ElementoDoTopo(Pilha* pilha) {
    if (!PilhaVazia(pilha)) {
        return *pilha.elem[*pilha.topo];
    } else {
        printf("Nao existe nenhum elemento no topo da pilha...");
        return NULL;
    }
}

//Métodos para o jogo
Pilha* SelecionarDificuldade() {
    printf("Selecione a dificuldade do jogo: \n 1) Fácil \n 2) Medio \n 3) Dificil");
    int opcao=0;
    scanf("%d", &opcao);
    switch(opcao) {
    case FACIL:
        return InicializarPilhasJogo(3);
    case MEDIO:
        return InicializarPilhasJogo(4);
    case DIFICIL:
        return InicializarPilhasJogo(5);
    case default:
        printf("Opcao desconhecida... \n");
        return SelecionarDificuldade();
}

*Pilha InicializarPilhasJogo(int tamanhoPilhas) {
    Pilha* pilhas[tamanhoPilhas+2];
    for (int i = 0; i < tamanhoPilhas+2; i++) {
        pilhas[i] = malloc(sizeof(Pilha) + (sizeof(int[tamanhoPilhas]));
        pilhas[i].tamMax = tamanhoPilhas;
        InicializaPilha(pilhas[i]);
    }
    return pilhas;
}

void PrintarPilhas(*Pilhas pilhas) {
    //TODO: RODAR UM FOR PRINTANDO CADA ELEMENTO DAS LISTAS
}


