//
// Created by Paola on 07/11/2026.
//

#include "ranking.h"
#include "perguntas.h"
#include <stdio.h>
#include <stdlib.h>



void ordenarRanking(Jogador historico[], int totalJ) {
    int i, j;
    Jogador aux;

    for (i = 0; i < totalJ - 1; i++) {
        for (j = 0; j < totalJ                    - i - 1; j++) {
            // Compara o percentual: se o atual for menor que o proximo, troca
            if (historico[j].percentual < historico[j + 1].percentual) {
                aux = historico[j];
                historico[j] = historico[j + 1];
                historico[j + 1] = aux;
            }
        }
    }
}
void exibirRanking( Jogador historico[], int totalJ) {
    if (totalJ == 0) {
        printf("\nNenhum jogo registado no historico ainda.\n");
        return;
    }

    printf("\n=============================================\n");
    printf("           RANKING DE JOGADORES              \n");
    printf("=============================================\n");
    printf("%-3s | %-20s | %-7s | %-10s\n", "Pos", "Nome", "Acertos", "Percentual");
    printf("---------------------------------------------\n");

    for (int i = 0; i < totalJ; i++) {
        printf("%-3d | %-20s | %2d/%-4d | %6.2f%%\n",
               i + 1,
               historico[i].nome,
               historico[i].acertos,
               historico[i].total,
               historico[i].percentual);
    }
    printf("=============================================\n");
}
int carregarHistorico(Jogador historico[]) {
    FILE *arq = fopen("data/historico.txt", "r");
    if (arq == NULL) {
        return 0; // Ficheiro ainda nao existe
    }

    int count = 0;
    while (count < MAX_JOGADORES &&
           fscanf(arq, " %[^;];%d;%d;%f\n",
                  historico[count].nome,
                  &historico[count].acertos,
                  &historico[count].total,
                  &historico[count].percentual) == 4) {
        count++;
                  }

    fclose(arq); // Fechamento obrigatorio
    return count;
}

void salvarPartida(Jogador j) {
    FILE *arq = fopen("data/historico.txt", "a");
    if (arq == NULL) {
        printf("[ERRO] Nao foi possivel abrir historico.txt para escrita.\n");
        return;
    }

    fprintf(arq, "%s;%d;%d;%.2f\n", j.nome, j.acertos, j.total, j.percentual);
    fclose(arq);
}

