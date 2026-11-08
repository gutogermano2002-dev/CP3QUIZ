//
// Created by Paola on 07/11/2026.
//

#include <stdio.h>
#include "jogador.h"

#include <cstring>

// Realiza o cadastro dos dados pessoais do jogador
void cadastrarJogador(JogadorCadastro *jogador) {
    if (jogador == NULL) return;

    printf("\n=== CADASTRO DE JOGADOR ===\n");

    // Leitura do nome completo
    printf("Digite o nome: ");
    fgets(jogador->nome, TAMANHO_TEXTO, stdin);
    jogador->nome[strcspn(jogador->nome, "\n")] = 0; // Tira o \n do final da string

    // Leitura do apelido
    printf("Digite o apelido: ");
    fgets(jogador->apelido, TAMANHO_TEXTO, stdin);
    jogador->apelido[strcspn(jogador->apelido, "\n")] = 0; // Tira o \n do final

    // Leitura da idade
    printf("Digite a idade: ");
    scanf("%d", &jogador->idade);

    // Limpa o ENTER que fica pendente no teclado
    while (getchar() != '\n');

    printf(">> Cadastro efetuado com sucesso!\n");
}
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