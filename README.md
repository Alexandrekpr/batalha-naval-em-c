# Batalha Naval em C - Desafio de Programação

![Status](https://img.shields.io/badge/status-conclu%C3%ADdo-green)

Este repositório contém a implementação de um jogo de Batalha Naval em linha de comando, desenvolvido em Linguagem C. O projeto foi construído seguindo uma série de desafios progressivos, partindo de uma base simples até a inclusão de mecânicas mais complexas como navios na diagonal e habilidades especiais com área de efeito.

## 🚀 Funcionalidades

-   **Tabuleiro 10x10:** Representação do campo de batalha através de uma matriz bidimensional.
-   **Posicionamento de Navios:** Suporte para posicionar navios na horizontal, vertical e diagonal.
-   **Validação de Posições:** O sistema valida se os navios estão dentro dos limites do tabuleiro e se não há sobreposição entre eles.
-   **Habilidades Especiais:** Implementação de 3 habilidades com áreas de efeito distintas para visualização estratégica:
    -   **Cone:** Área de efeito em formato de triângulo.
    -   **Cruz:** Área de efeito que afeta uma linha e uma coluna inteira.
    -   **Octaedro:** Área de efeito em formato de losango (ou diamante).
-   **Visualização no Console:** Exibição clara do tabuleiro, diferenciando água, navios e áreas de efeito com caracteres distintos (`~`, `#`, `*`).

## 📈 Evolução do Projeto

O código foi desenvolvido em três etapas principais:

1.  **Nível Novato:** Criação do tabuleiro 10x10 e posicionamento de dois navios (um na horizontal e outro na vertical), com validação de limites.
2.  **Nível Intermediário:** Adição de mais dois navios, com suporte ao posicionamento na diagonal, e aprimoramento da lógica de validação de sobreposição.
3.  **Nível Avançado:** Implementação das matrizes de habilidades (Cone, Cruz, Octaedro) e da lógica para sobrepor suas áreas de efeito no tabuleiro principal.

## 📂 Estrutura do Repositório

```
.
├── bin/
├── src/
│   └── batalha_naval.c
├── .gitignore
└── README.md
```

-   `src/`: Contém todo o código-fonte do projeto.
-   `bin/`: Destino dos arquivos executáveis após a compilação. (Esta pasta é ignorada pelo Git).

## ⚙️ Como Compilar e Executar

Para compilar e executar este projeto, você precisará de um compilador C, como o GCC.

1.  **Clone o repositório:**
    ```sh
    git clone https:https://github.com/Alexandrekpr/batalha-naval-em-c.git
    cd batalha-naval-c
    ```

2.  **Compile o programa:**
    O comando a seguir compilará o código-fonte da pasta `src` e criará um executável chamado `batalha_naval` dentro da pasta `bin`.
    ```sh
    gcc src/batalha-naval.c -o bin/batalha-naval -lm
    ```
    *(A flag `-lm` é incluída para linkar a biblioteca matemática, necessária para funções como `abs()`)*

3.  **Execute o programa:**
    ```sh
    ./bin/batalha_naval
    ```

## 🛠️ Tecnologias Utilizadas

-   **Linguagem C**

## 👨‍💻 Autor

**Alexandre Pacheco**
