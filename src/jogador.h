//
// Created by Paola on 07/11/2026.
//

#ifndef CP3QUIZ_JOGADOR_H
#define CP3QUIZ_JOGADOR_H
#define TAMANHO_TEXTO 100
#define TAMANHO_NOME 50


//cadastro de jogador
typedef struct {
    char nome[TAMANHO_TEXTO];
    char apelido[TAMANHO_TEXTO];
    int idade;
} JogadorCadastro;




// jogador
typedef struct {
    char nome[TAMANHO_NOME];
    int acertos;
    int total;
    float percentual;
} Jogador;
void cadastrarJogador(JogadorCadastro *jogador);
void exibirDados(const JogadorCadastro *jogador);
void exibirDadosdeJogador(Jogador *jogador);


#endif //CP3QUIZ_JOGADOR_H
