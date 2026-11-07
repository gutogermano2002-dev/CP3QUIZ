//
// Created by Paola on 07/11/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quiz.h"

// Função para carregar as perguntas do ficheiro de texto
int carregarPerguntas(Pergunta perguntas[]) {
    FILE *arq = fopen("perguntas.txt", "r");

    // Validação obrigatória contra NULL
    if (arq == NULL) {
        printf("[ERRO] Nao foi possivel abrir o ficheiro perguntas.txt!\n");
        return 0;
    }

    int count = 0;

    // Leitura formatada com %[^;] para aceitar espaços no texto
    while (count < MAX_PERGUNTAS &&
           fscanf(arq, " %[^;];%[^;];%[^;];%[^;];%[^;];%c\n",
                  perguntas[count].enunciado,
                  perguntas[count].altA,
                  perguntas[count].altB,
                  perguntas[count].altC,
                  perguntas[count].altD,
                  &perguntas[count].correta) == 6) {
        count++;
    }

    // Fechamento obrigatório do arquivo
    fclose(arq);
    return count;
}

// Função principal de execução da partida
void jogar(Pergunta perguntas[], int totalP, Jogador historico[], int *totalJ, const JogadorCadastro *cadastro) {
    if (totalP == 0) {
        printf("\n[AVISO] Nenhuma pergunta disponivel para jogar!\n");
        return;
    }

    Jogador novo;
    // Copia os dados do cadastro para a struct da partida
    strncpy(novo.nome, cadastro->nome, TAMANHO_NOME - 1);
    novo.nome[TAMANHO_NOME - 1] = '\0';

    strncpy(novo.apelido, cadastro->apelido, TAMANHO_NOME - 1);
    novo.apelido[TAMANHO_NOME - 1] = '\0';

    novo.idade = cadastro->idade;
    novo.acertos = 0;
    novo.total = totalP;
    char resposta;

    printf("\n=== PARTIDA INICIADA PARA: %s (%s) ===\n", cadastro->nome, cadastro->apelido);

    for (int i = 0; i < totalP; i++) {
        printf("\n----------------------------------------\n");
        printf("Pergunta %d: %s\n", i + 1, perguntas[i].enunciado);
        printf("A) %s\n", perguntas[i].altA);
        printf("B) %s\n", perguntas[i].altB);
        printf("C) %s\n", perguntas[i].altC);
        printf("D) %s\n", perguntas[i].altD);
        printf("Sua resposta (A/B/C/D): ");
        scanf(" %c", &resposta);

        if (resposta >= 'a' && resposta <= 'z') {
            resposta -= 32;
        }

        if (resposta == perguntas[i].correta) {
            printf(">> Resposta CORRETA!\n");
            novo.acertos++;
        } else {
            printf(">> Resposta INCORRETA! A certa era: %c\n", perguntas[i].correta);
        }
    }

    novo.percentual = ((float)novo.acertos / novo.total) * 100.0;

    printf("\n========================================\n");
    printf("Fim do jogo, %s!\n", novo.apelido);
    printf("Acertos: %d/%d (%.2f%%)\n", novo.acertos, novo.total, novo.percentual);
    printf("========================================\n");

    historico[*totalJ] = novo;
    (*totalJ)++;
}