#include <stdio.h>
#include <stdlib.h> // Para a função abs()

// --- Constantes Globais ---
// Tamanho do tabuleiro principal do jogo
#define LINHAS_TABULEIRO 10
#define COLUNAS_TABULEIRO 10

// Tamanho das matrizes de habilidade (use um número ímpar para ter um centro claro)
#define TAMANHO_HABILIDADE 7

// Valores para representar cada elemento no tabuleiro
#define AGUA 0
#define NAVIO 3
#define EFEITO_HABILIDADE 5


// --- Protótipos das Funções ---

// Funções do tabuleiro principal
void inicializarTabuleiro(int tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO]);
void exibirTabuleiro(int tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO]);

// Funções de criação das matrizes de habilidade
void criarMatrizCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);
void criarMatrizCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);
void criarMatrizOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);

// Função para aplicar a habilidade no tabuleiro principal
void aplicarHabilidade(int tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO],
                       int matrizHabilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                       int origemLinha, int origemColuna);


int main() {
    // Declara a matriz que representa o tabuleiro do jogo
    int tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO];

    // Inicializa o tabuleiro com água (valor 0)
    inicializarTabuleiro(tabuleiro);

    // --- Posicionamento Fixo de Navios para Contexto ---
    // Posiciona alguns navios para que possamos ver a interação com as habilidades.
    tabuleiro[2][2] = NAVIO; tabuleiro[2][3] = NAVIO; tabuleiro[2][4] = NAVIO; // Horizontal
    tabuleiro[5][8] = NAVIO; tabuleiro[6][8] = NAVIO; tabuleiro[7][8] = NAVIO; // Vertical

    // --- Criação das Matrizes de Habilidade ---
    int matrizCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int matrizCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int matrizOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Utiliza as funções para preencher as matrizes com os padrões 0 e 1
    criarMatrizCone(matrizCone);
    criarMatrizCruz(matrizCruz);
    criarMatrizOctaedro(matrizOctaedro);


    // --- Aplicação das Habilidades no Tabuleiro ---
    // Defina aqui as coordenadas de origem para cada habilidade.
    // Lembre-se que esta é a coordenada no TABULEIRO onde o CENTRO da habilidade será aplicado.

    printf("Aplicando habilidades no tabuleiro...\n");

    // Aplica a habilidade em Cone com origem em (2, 5)
    aplicarHabilidade(tabuleiro, matrizCone, 2, 5);

    // Aplica a habilidade em Cruz com origem em (7, 2)
    aplicarHabilidade(tabuleiro, matrizCruz, 7, 2);

    // Aplica a habilidade em Octaedro com origem em (6, 6)
    aplicarHabilidade(tabuleiro, matrizOctaedro, 6, 6);


    // --- Exibição do Resultado Final ---
    printf("\nTabuleiro final com navios e areas de efeito das habilidades:\n");
    exibirTabuleiro(tabuleiro);

    return 0; // Indica que o programa terminou com sucesso
}

// --- Implementação das Funções ---

/**
 * @brief Preenche todo o tabuleiro com o valor AGUA (0).
 *
 * @param tabuleiro A matriz do jogo.
 */
void inicializarTabuleiro(int tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO]) {
    for (int i = 0; i < LINHAS_TABULEIRO; i++) {
        for (int j = 0; j < COLUNAS_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

/**
 * @brief Cria um padrão de cone (triângulo) em uma matriz.
 * A origem (ponta) do cone é na linha superior central.
 *
 * @param matriz A matriz 2D a ser preenchida.
 */
void criarMatrizCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // A condição verifica se a coluna 'j' está dentro do alcance do cone
            // que se expande a cada linha 'i'.
            if (j >= centro - i && j <= centro + i) {
                matriz[i][j] = 1; // Posição afetada
            } else {
                matriz[i][j] = 0; // Posição não afetada
            }
        }
    }
}

/**
 * @brief Cria um padrão de cruz em uma matriz.
 * A origem é o centro da matriz.
 *
 * @param matriz A matriz 2D a ser preenchida.
 */
void criarMatrizCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // A condição verifica se a célula está na linha central OU na coluna central.
            if (i == centro || j == centro) {
                matriz[i][j] = 1; // Posição afetada
            } else {
                matriz[i][j] = 0; // Posição não afetada
            }
        }
    }
}

/**
 * @brief Cria um padrão de octaedro/losango em uma matriz.
 * A origem é o centro da matriz.
 *
 * @param matriz A matriz 2D a ser preenchida.
 */
void criarMatrizOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // A condição usa a "Distância de Manhattan" do centro.
            // Se a soma das distâncias vertical e horizontal do centro for menor
            // ou igual ao raio (centro), a célula faz parte do losango.
            if (abs(i - centro) + abs(j - centro) <= centro) {
                matriz[i][j] = 1; // Posição afetada
            } else {
                matriz[i][j] = 0; // Posição não afetada
            }
        }
    }
}

/**
 * @brief Sobrepõe uma matriz de habilidade no tabuleiro principal.
 *
 * @param tabuleiro O tabuleiro principal do jogo.
 * @param matrizHabilidade A matriz 2D (preenchida com 0s e 1s) da habilidade.
 * @param origemLinha A linha no tabuleiro onde o CENTRO da habilidade será posicionado.
 * @param origemColuna A coluna no tabuleiro onde o CENTRO da habilidade será posicionado.
 */
void aplicarHabilidade(int tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO],
                       int matrizHabilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                       int origemLinha, int origemColuna) {
    int centroHabilidade = TAMANHO_HABILIDADE / 2;

    // Itera pela matriz de habilidade (ex: 7x7)
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Verifica se a posição na matriz de habilidade é uma área de efeito (valor 1)
            if (matrizHabilidade[i][j] == 1) {
                // Calcula a coordenada correspondente no tabuleiro principal.
                // O cálculo subtrai o 'centro' para alinhar a matriz de habilidade
                // corretamente com a coordenada de origem.
                int linhaAlvo = origemLinha - centroHabilidade + i;
                int colunaAlvo = origemColuna - centroHabilidade + j;

                // CONDIÇÃO DE SEGURANÇA:
                // Garante que a área de efeito não seja desenhada fora dos limites do tabuleiro.
                if (linhaAlvo >= 0 && linhaAlvo < LINHAS_TABULEIRO &&
                    colunaAlvo >= 0 && colunaAlvo < COLUNAS_TABULEIRO) {
                    // Marca a posição no tabuleiro principal com o valor da habilidade.
                    // Isso substituirá a água e até mesmo os navios, para fins de visualização.
                    tabuleiro[linhaAlvo][colunaAlvo] = EFEITO_HABILIDADE;
                }
            }
        }
    }
}

/**
 * @brief Imprime o estado atual do tabuleiro no console com caracteres distintos.
 *
 * @param tabuleiro A matriz do jogo a ser exibida.
 */
void exibirTabuleiro(int tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO]) {
    // Imprime o cabeçalho com os números das colunas para referência
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    printf("  ---------------------\n");
    for (int i = 0; i < LINHAS_TABULEIRO; i++) {
        // Imprime o número da linha no início
        printf("%d| ", i);
        for (int j = 0; j < COLUNAS_TABULEIRO; j++) {
            // Usa um switch para imprimir um caractere diferente para cada valor
            switch (tabuleiro[i][j]) {
                case AGUA:
                    printf("~ "); // Água
                    break;
                case NAVIO:
                    printf("# "); // Navio
                    break;
                case EFEITO_HABILIDADE:
                    printf("* "); // Área de efeito da habilidade
                    break;
                default:
                    printf("? "); // Caractere para valores inesperados
                    break;
            }
        }
        printf("\n"); // Nova linha ao final de cada linha do tabuleiro
    }
}