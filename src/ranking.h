//
// Created by Paola on 07/11/2026.
//

#ifndef RANKING_H
#define RANKING_H

#include "jogador.h" // Importa a struct Jogador

// Protótipos das funções de ranking
void ordenarRanking(Jogador historico[], int qtd);
void exibirRanking(const Jogador historico[], int qtd);
int carregarHistorico(Jogador historico[]);
void salvarPartida(Jogador j);

#endif // RANKING_H