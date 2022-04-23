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
    int elem[8];
} Pilha;

//Métodos de Pilha
void InicializaPilha(Pilha* pilha) {
    pilha->topo = -1;
}

int PilhaVazia(Pilha* pilha) {
    return pilha->topo == -1;
}

int PilhaCheia(Pilha pilha) {
    return pilha.topo == (pilha.tamMax - 1);
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
int GerarNumeroAleatorioAte(int maximum) {
    //Exclui zero e inclui maximo
    int val = 1 + rand()%(maximum);
    return val;
}

int ExisteValorRepetido(Pilha* pilha, int numero_aleatorio) {
    if(!PilhaVazia(pilha)) {
        for (int i = 0; i < (*pilha).tamMax; i++) {
            if ((*pilha).elem[i] == numero_aleatorio) {
                return 1;
            }
        }
    }
    printf("Nao existe valor repetido \n");
    return 0;
}

void GerarValoresNaPilha(Pilha* pilha) {
    printf("Gerando valores da pilha...\n");
    for (int slot_pilha = 0; slot_pilha < pilha->tamMax; slot_pilha++) {
        int num_Aleatorio = GerarNumeroAleatorioAte(pilha->tamMax);
        while(ExisteValorRepetido(pilha, num_Aleatorio)) {
            num_Aleatorio = GerarNumeroAleatorioAte(pilha->tamMax);
        }
        Empilha(pilha, num_Aleatorio);
    }
}


Pilha* InicializarPilhasJogo(int tamanhoPilhas) {
    srand(time(NULL));
    printf("Inicializando pilhas do jogo...\n");
    Pilha pilhas[tamanhoPilhas+2];
    for (int i = 0; i < tamanhoPilhas+2; i++) {
        pilhas[i].tamMax = (tamanhoPilhas);
        InicializaPilha(&pilhas[i]);
        if (i < tamanhoPilhas) {
            printf("Entrando para gerar valores na pilha %d...\n", i);
            GerarValoresNaPilha(&pilhas[i]);
        }
        printf("Topo da pilha %d: %d \n", i, pilhas[i].topo);
    }
    PrintarPilhas(pilhas);
    return pilhas;
}

Pilha* SelecionarDificuldade() {
    printf("Selecione a dificuldade do jogo: \n 1) Facil \n 2) Medio \n 3) Dificil \nsua resposta ->");
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
       printf("PILHA %d: [", pos_pilha + 1);
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
