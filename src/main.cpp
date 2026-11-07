#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"
#include "quiz.h"
#include "ranking.h"

int main() {
    // Vetores para guardar perguntas e historico na memoria
    Pergunta perguntas[MAX_PERGUNTAS];
    Jogador historico[MAX_JOGADORES];

    JogadorCadastro cadastroAtual;
    int temCadastro = 0;

    // Le os ficheiros .txt assim que o programa abre
    int totalP = carregarPerguntas(perguntas);
    int totalJ = carregarHistorico(historico);

    int opcao;

    do {
        printf("\n========================================\n");
        printf("           QUIZ INTEGRADOR EM C         \n");
        printf("========================================\n");
        printf("1. Jogar Quiz (Cadastrar & Jogar)\n");
        printf("2. Ver Ranking Ordenado\n");
        printf("3. Ver Dados do Jogador Atual\n");
        printf("4. Diagnostico de Dados Carregados\n");
        printf("0. Sair\n");
        printf("========================================\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            opcao = -1;
        }

        // Limpa a tecla ENTER do teclado para nao saltar leituras
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                // Pede os dados do jogador e arranca com as perguntas
                cadastrarJogador(&cadastroAtual);
                temCadastro = 1;

                jogar(perguntas, totalP, historico, &totalJ, &cadastroAtual);

                // Grava o resultado da partida no ficheiro de historico
                if (totalJ > 0) {
                    salvarPartida(historico[totalJ - 1]);
                }
                break;

            case 2:
                // Ordena o ranking por pontuacao antes de mostrar na tela
                ordenarRanking(historico, totalJ);
                exibirRanking(historico, totalJ);
                break;

            case 3:
                if (temCadastro) {
                    exibirDados(&cadastroAtual);
                } else {
                    printf("\n[AVISO] Nenhum jogador foi cadastrado ainda!\n");
                }
                break;

            case 4:
                printf("\n--- DIAGNOSTICO ---\n");
                printf("Perguntas lidas do ficheiro: %d/%d\n", totalP, MAX_PERGUNTAS);
                printf("Partidas no historico: %d/%d\n", totalJ, MAX_JOGADORES);
                break;

            case 0:
                printf("\nA fechar o Quiz... Ate a proxima!\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}