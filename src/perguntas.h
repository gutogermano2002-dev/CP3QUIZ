#ifndef QUIZ_H
#define QUIZ_H

// Constantes globais do projeto
#define MAX_PERGUNTAS 50
#define MAX_JOGADORES 100
#define TAMANHO_TEXTO 100


// pergunta
typedef struct {
    char enunciado[TAMANHO_TEXTO];
    char altA[TAMANHO_TEXTO];
    char altB[TAMANHO_TEXTO];
    char altC[TAMANHO_TEXTO];
    char altD[TAMANHO_TEXTO];
    char correta; // Guardara 'A', 'B', 'C' ou 'D'
} Pergunta;


// ponteiros
int carregarPerguntas(Pergunta perguntas[]);
int carregarHistorico(Jogador historico[]);
void salvarPartida(Jogador j);

// jogo
void jogar(Pergunta perguntas[], int totalP, Jogador historico[], int *totalJ);
void ordenarRanking(Jogador historico[], int qtd); // Bubble Sort manual
void exibirRanking(Jogador historico[], int qtd);

#endif
