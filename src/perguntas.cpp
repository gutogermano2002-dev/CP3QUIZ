//
// Created by Paola on 07/11/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perguntas.h"

#include <cctype>

#include "jogador.h"
#include "ranking.h"



// Salva uma única pergunta no final do ficheiro de texto (modo append "a")
void salvarPergunta(Pergunta p) {
    FILE *arq = fopen("data/perguntas.txt", "a");

    if (arq == NULL) {
        printf("[ERRO] Nao foi possivel abrir data/perguntas.txt para escrita!\n");
        return;
    }

    fprintf(arq, "%s;%s;%s;%s;%s;%c\n",
            p.enunciado,
            p.altA,
            p.altB,
            p.altC,
            p.altD,
            p.correta);

    fclose(arq);
}

// Função para ler do teclado e adicionar uma nova pergunta
void cadastrarPergunta(Pergunta perguntas[], int *totalP) {
    if (*totalP >= MAX_PERGUNTAS) {
        printf("\n[ERRO] Limite maximo de perguntas (%d) atingido!\n", MAX_PERGUNTAS);
        return;
    }

    Pergunta nova;

    printf("\n=== CADASTRO DE NOVA PERGUNTA ===\n");

    // Limpa eventuais resíduos do buffer
    getchar();

    printf("Digite o enunciado da pergunta: ");
    fgets(nova.enunciado, TAMANHO_TEXTO, stdin);
    nova.enunciado[strcspn(nova.enunciado, "\n")] = '\0'; // Remove o \n final

    printf("Digite a Alternativa A: ");
    fgets(nova.altA, TAMANHO_TEXTO, stdin);
    nova.altA[strcspn(nova.altA, "\n")] = '\0';

    printf("Digite a Alternativa B: ");
    fgets(nova.altB, TAMANHO_TEXTO, stdin);
    nova.altB[strcspn(nova.altB, "\n")] = '\0';

    printf("Digite a Alternativa C: ");
    fgets(nova.altC, TAMANHO_TEXTO, stdin);
    nova.altC[strcspn(nova.altC, "\n")] = '\0';

    printf("Digite a Alternativa D: ");
    fgets(nova.altD, TAMANHO_TEXTO, stdin);
    nova.altD[strcspn(nova.altD, "\n")] = '\0';

    // Validação da alternativa correta
    do {
        printf("Digite a alternativa correta (A/B/C/D): ");
        scanf(" %c", &nova.correta);
        nova.correta = toupper(nova.correta);

        if (nova.correta < 'A' || nova.correta > 'D') {
            printf("[ERRO] Opcao invalida! Digite apenas A, B, C ou D.\n");
        }
    } while (nova.correta < 'A' || nova.correta > 'D');

    // Guarda na memória (vetor)
    perguntas[*totalP] = nova;
    (*totalP)++;

    // Guarda no ficheiro de texto
    salvarPergunta(nova);

    printf("\n[SUCESSO] Pergunta cadastrada e salva com sucesso!\n");
}
// Função para carregar as perguntas do ficheiro de texto
int carregarPerguntas(Pergunta perguntas[]) {
    FILE *arq = fopen("data/perguntas.txt", "r");

    // Validação obrigatória contra NULL
    if (arq == NULL) {
        printf("[ERRO] Nao foi possivel abrir o ficheiro data/perguntas.txt!\n");
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

// Executa a partida utilizando os dados do cadastro do jogador
void jogar(Pergunta perguntas[], int totalP, Jogador historico[], int *totalJ, const JogadorCadastro *cadastro) {
    if (totalP == 0) {
        printf("\n[AVISO] Nenhuma pergunta disponivel para jogar!\n");
        return;
    }

    Jogador novo;

    // Copia apenas o nome (ou apelido) do cadastro para o registo da partida
    strncpy(novo.nome, cadastro->nome, TAMANHO_NOME - 1);
    novo.nome[TAMANHO_NOME - 1] = '\0';

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

        // Normaliza minusculas para maiusculas
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

    // Calculo do percentual de acertos
    novo.percentual = ((float)novo.acertos / novo.total) * 100.0f;

    printf("\n========================================\n");
    printf("Fim do jogo, %s!\n", novo.nome);
    printf("Acertos: %d/%d (%.2f%%)\n", novo.acertos, novo.total, novo.percentual);
    printf("========================================\n");

    // Adiciona ao historico na RAM
    historico[*totalJ] = novo;
    (*totalJ)++;
}