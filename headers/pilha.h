//
// Created by rafae on 15/04/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int PilhaVazia(Pilha* pilha) {
    printf("Valor do topo da pilha: %d \n", pilha->topo);
    return pilha->topo == -1;
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
    if (!PilhaVazia(pilha)) {
        remElem = pilha->elem[pilha->topo];
        pilha->topo--;
    }
}

int ElementoDoTopo(Pilha* pilha) {
    if (!PilhaVazia(pilha)) {
        return pilha->elem[pilha->topo];
    } else {
        printf("Nao existe nenhum elemento no topo da pilha...");
        return NULL;
    }
}

//Métodos para o jogo
int GerarNumeroAleatorioEntre(int minimum, int maximum) {
    int val = rand()%(maximum+1);
    if (val == 0) {
        return 1;
    }
    return val;
}

int ExisteValorRepetido(Pilha* pilha, int numero_aleatorio) {
    printf("Pilha vazia: %d \n", PilhaVazia(pilha));
    if(!PilhaVazia(pilha)) {
        for (int slot_pilha = 0; slot_pilha < pilha->topo; slot_pilha++) {
            if (pilha->elem[slot_pilha] == numero_aleatorio) {
                printf("Existe valor repetido no indice: %d \n", slot_pilha);
                return 1;
            }
        }
    }
    printf("Nao existe valor repetido \n");
    return 0;
}

void GerarValoresNaPilha(Pilha* pilha) {
    for (int slot_pilha = 0; slot_pilha < pilha->tamMax; slot_pilha++) {
        int num_Aleatorio;
        do {
            int num_Aleatorio = GerarNumeroAleatorioEntre(1, pilha->tamMax);
            printf("Numero gerado: %d \n", num_Aleatorio);
        } while(ExisteValorRepetido(pilha, num_Aleatorio));
        Empilha(pilha, num_Aleatorio);
    }
}


Pilha* InicializarPilhasJogo(int tamanhoPilhas) {
    srand(time(NULL));
    Pilha* pilhas[tamanhoPilhas+2];
    for (int i = 0; i < tamanhoPilhas+2; i++) {
        pilhas[i] = malloc(sizeof(Pilha) + (sizeof(int[tamanhoPilhas])));
        pilhas[i]->tamMax = tamanhoPilhas;
        InicializaPilha(pilhas[i]);
        if (i < tamanhoPilhas) {
            GerarValoresNaPilha(pilhas[i]);
        }
        printf("Topo da pilha %d: %d \n", i, pilhas[i]->topo);
    }
    PrintarPilhas(*pilhas);
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
   for (int pos_pilha = 0; pos_pilha < pilhas[0].tamMax+2; pos_pilha++) {
       printf("PILHA %d: [", pos_pilha);
       for (int pivot = 0; pivot < pilhas[pos_pilha].tamMax; pivot++) {
            if (pivot > pilhas[pos_pilha].topo) {
                printf("| - |");
            } else {
                printf("| %d |", pilhas[pos_pilha].elem[pivot]);
            }
       }
       printf("] \n");
   }
}
