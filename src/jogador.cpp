//
// Created by Paola on 07/11/2026.
//

#include <stdio.h>
#include "jogador.h"

// Exibe os dados cadastrais do jogador
void exibirDados(const JogadorCadastro *jogador) {
    if (jogador == NULL) return; // Boa prática: validação contra NULL

    printf("\n=== DADOS CADASTRAIS DO JOGADOR ===\n");
    printf("Nome: %s\n", jogador->nome);
    printf("Apelido: %s\n", jogador->apelido);
    printf("Idade: %d anos\n", jogador->idade);
    printf("===================================\n");
}

// Exibe os dados de desempenho do jogador, *jogador -> ponteiro
void exibirDadosdeJogador(const Jogador *jogador) {
    if (jogador == NULL) return; // Validação contra NULL

    printf("\n=== DESEMPENHO NO QUIZ ===\n");
    printf("Nome: %s\n", jogador->nome);
    printf("Acertos: %d/%d\n", jogador->acertos, jogador->total);
    printf("Aproveitamento: %.2f%%\n", jogador->percentual);
    printf("==========================\n");
}