#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"
#include "perguntas.h"
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
        printf("1. Jogar Quiz (Cadastrar, Jogar & Salvar)\n");
        printf("2. Ver Ranking Ordenado (Bubble Sort)\n");
        printf("3. Ver Dados do Jogador Atual\n");
        printf("4. Diagnostico de Dados Carregados\n");
        printf("0. Sair\n");
        printf("========================================\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            opcao = -1;
        }

        // Limpa o ENTER do teclado para nao saltar leituras
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                // 1. Cadastra nome, apelido e idade
                cadastrarJogador(&cadastroAtual);
                temCadastro = 1;

                // 2. Executa a partida usando os dados do cadastro
                jogar(perguntas, totalP, historico, &totalJ, &cadastroAtual);

                // 3. Grava o cadastro + pontuacao no historico.txt
                if (totalJ > 0) {
                    salvarPartida(historico[totalJ - 1]);
                }
                break;

            case 2:
                // Ordena por percentual antes de mostrar na tela
                ordenarRanking(historico, totalJ);
                exibirRanking(historico, totalJ);
                break;

            case 3:
                if (temCadastro) {
                    exibirDados(&cadastroAtual);
                } else {
                    printf("\n[AVISO] Nenhum jogador foi cadastrado nesta sessao ainda!\n");
                }
                break;

            case 4:
                printf("\n--- DIAGNOSTICO ---\n");
                printf("Perguntas lidas do ficheiro: %d/%d\n", totalP, MAX_PERGUNTAS);
                printf("Partidas lidas do historico: %d/%d\n", totalJ, MAX_JOGADORES);
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