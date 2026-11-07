//
// Created by Paola on 07/11/2026.
//

#ifndef CP3QUIZ_PERGUNTAS_H
#define CP3QUIZ_PERGUNTAS_H
#define MAX_PERGUNTAS 50

typedef struct pergunta {
    typedef struct {
        char enunciado[100];
        char altA[0];
        char altB[0];
        char altC[0];
        char altD[0];
        char correta;
    } Pergunta;
    int carregarPerguntas(Pergunta perguntas[]);
    void exibirPergunta(Pergunta p, int numero);


#endif //CP3QUIZ_PERGUNTAS_H
