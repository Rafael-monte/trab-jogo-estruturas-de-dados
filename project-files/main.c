#include <stdio.h>
#include "../headers/pilha.h"

Pilha* pilhasJogo;

int main() {
    printf("Bem vindo ao jogo! \n");
    pilhasJogo = SelecionarDificuldade();
}
