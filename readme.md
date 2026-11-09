# 🧠 Quiz Game (CP3 Quiz)

> 🎥 **Vídeo de Demonstração:** [Clique aqui para assistir à apresentação do código e funcionamento](https://drive.google.com/file/d/1_k8vrJXzWMCbxTSddFchiLGQpYbmd58v/view?usp=sharing)

---

Um jogo de perguntas e respostas em linha de comando (CLI) desenvolvido em C/C++, com suporte a cadastro de jogadores, manipulação de ficheiros de dados, ordenação de ranking e estrutura modular de código.

---

## 📌 Índice

- [Sobre o Projeto](#-sobre-o-projeto)
- [Vídeo de Demonstração](#-vídeo-de-demonstração)
- [Funcionalidades](#-funcionalidades)
- [Estrutura de Diretorias](#-estrutura-de-diretorias)
- [Tecnologias Utilizadas](#-tecnologias-utilizadas)
- [Como Executar](#-como-executar)
    - [Pré-requisitos](#pré-requisitos)
    - [Opção 1: Compilação via GCC/G++](#opção-1-compilação-via-gccc)
    - [Opção 2: Compilação via CMake / CLion](#opção-2-compilação-via-cmake--clion)
- [Formato dos Ficheiros de Dados](#-formato-dos-ficheiros-de-dados)
- [Autora](#-autora)

---

## 📖 Sobre o Projeto

O **CP3 Quiz** é uma aplicação interativa de perguntas e respostas. O sistema permite registar dados do jogador, carregar um banco de perguntas armazenado em disco, processar respostas de múltipla escolha, calcular o aproveitamento percentual do participante e salvar o seu desempenho num histórico persistente.

---

## 🎥 Vídeo de Demonstração

Assista à explicação detalhada do código fonte e ao funcionamento da aplicação em execução:
👉 **[Link para o Vídeo do Projeto](https://seu-link-do-video-aqui.com)**

---

## ⚡ Funcionalidades

- [x] **Cadastro de Jogadores:** Registo de nome, apelido e idade.
- [x] **Gestão de Perguntas:**
    - Leitura dinâmica a partir de `data/perguntas.txt`.
    - Inserção e gravação de novas perguntas via terminal.
- [x] **Execução do Quiz:** Leitura de opções (A, B, C, D), conversão automática para maiúsculas e validação imediata.
- [x] **Persistência de Dados:** Gravação automática dos resultados em `data/historico.txt`.
- [x] **Ranking de Desempenho:**
    - Algoritmo manual de **Bubble Sort** ordenando por percentual de acertos.
    - Exibição tabulada de classificações.
- [x] **Painel de Diagnóstico:** Consulta rápida do número de perguntas e registos carregados na memória.

---

## 🛠️ Estrutura de Diretorias

```text
.
├── CMakeLists.txt
├── data/
│   ├── historico.txt       # Registo das pontuações dos jogadores
│   └── perguntas.txt       # Ficheiro com o banco de perguntas
├── include/
│   ├── jogador.h           # Definição das structs de jogador e protótipos
│   ├── perguntas.h         # Estrutura das perguntas e funções do jogo
│   └── ranking.h           # Protótipos de ordenação e exibição de ranking
└── src/
    ├── jogador.cpp         # Implementação do cadastro e exibição do jogador
    ├── main.cpp            # Menu principal e controlo do fluxo do programa
    ├── perguntas.cpp       # Leitura, gravação e lógica das perguntas
    └── ranking.cpp         # Ordenação por Bubble Sort e gestão do histórico

💻 Tecnologias Utilizadas
Linguagem: C++ (padrão C++11 / C++14)

Compilador: G++ / Clang / MSVC

Build System: CMake

Entrada/Saída & Ficheiros: stdio.h, stdlib.h, cstring, cctype

🔧 Como Executar
Pré-requisitos
Certifique-se de ter um compilador C++ (como g++) e o cmake instalados no seu sistema.

Opção 1: Compilação via GCC/G++
Clone o repositório:

Bash
git clone [https://github.com/seu-usuario/seu-repositorio.git](https://github.com/seu-usuario/seu-repositorio.git)
Acesse a pasta do projeto:

Bash
cd seu-repositorio
Compile incluindo a pasta de cabeçalhos (include/):

Bash
g++ -Iinclude src/main.cpp src/jogador.cpp src/perguntas.cpp src/ranking.cpp -o quiz
Execute a aplicação:

Linux / macOS:

Bash
./quiz
Windows:

DOS
quiz.exe
Opção 2: Compilação via CMake / CLion
Crie a pasta de build e execute o CMake:

Bash
mkdir build
cd build
cmake ..
make
Execute o binário gerado a partir da pasta raiz para manter o caminho correto das pastas data/:

Bash
./quiz
📄 Formato dos Ficheiros de Dados
Os ficheiros na pasta data/ utilizam delimitador por ponto e vírgula (;):

data/perguntas.txt:

Plaintext
Enunciado;Opção A;Opção B;Opção C;Opção D;RespostaCorreta
data/historico.txt:

Plaintext
Nome;Acertos;TotalDePerguntas;Percentual