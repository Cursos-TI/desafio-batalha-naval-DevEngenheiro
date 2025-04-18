// Desafio Batalha Naval
// Nível Mestre - Habilidades Especiais com Matrizes
// Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
// Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para água, 3 para navios e 5 para áreas afetadas pela habilidade.
// Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
// Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.

#include <stdio.h>
#define TAM 10  // Tamanho do tabuleiro (10x10)

// Função para desenhar o Cone (3x5) no tabuleiro.
// Formato do Cone (matriz 3x5):
// 0 0 1 0 0 
// 0 1 1 1 0 
// 1 1 1 1 1
// O ponto central fixo é (1,2) – isto é, segunda linha e terceira coluna da matriz.
// Essa célula será alinhada com (lin, col) passado à função.
void desenharCone(int tab[TAM][TAM], int lin, int col) {
    int cone[3][5];
    // Preenche a matriz "cone" de acordo com o formato desejado.
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            cone[i][j] = 0; // Valor padrão: não afetado.
            if (i == 0 && j == 2) {
                cone[i][j] = 1;
            }
            else if (i == 1 && j >= 1 && j <= 3) {
                cone[i][j] = 1;
            }
            else if (i == 2) {
                cone[i][j] = 1;
            }
        }
    }
    // Centro da matriz de habilidade é (1,2)
    int centroLinha = 1, centroColuna = 2;
    // Sobrepõe a matriz "cone" no tabuleiro, alinhando o centro (1,2) com (lin, col)
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            if (cone[i][j] == 1) {
                int posLinha = lin + (i - centroLinha);
                int posCol = col + (j - centroColuna);
                if (posLinha >= 0 && posLinha < TAM && posCol >= 0 && posCol < TAM) {
                    if (tab[posLinha][posCol] == 0)
                        tab[posLinha][posCol] = 5;
                }
            }
        }
    }
}

// Função para desenhar a Cruz (3x5) no tabuleiro.
// Formato da Cruz:
// 0 0 1 0 0
// 1 1 1 1 1
// 0 0 1 0 0
// O ponto central é (1,2) e será alinhado com (lin, col) do tabuleiro.
void desenharCruz(int tab[TAM][TAM], int lin, int col) {
    int cruz[3][5];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            cruz[i][j] = 0;
            if (i == 1)
                cruz[i][j] = 1;
            if (j == 2)
                cruz[i][j] = 1;
        }
    }
    int centroLinha = 1, centroColuna = 2;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            if (cruz[i][j] == 1) {
                int posLinha = lin + (i - centroLinha);
                int posCol = col + (j - centroColuna);
                if (posLinha >= 0 && posLinha < TAM && posCol >= 0 && posCol < TAM) {
                    if (tab[posLinha][posCol] == 0)
                        tab[posLinha][posCol] = 5;
                }
            }
        }
    }
}

// Função para desenhar o Octaedro (3x5) no tabuleiro.
// Formato do Octaedro:
// 0 0 1 0 0
// 0 1 1 1 0
// 0 0 1 0 0
// O ponto central da matriz é (1,2), que será alinhado com (lin, col) no tabuleiro.
void desenharOctaedro(int tab[TAM][TAM], int lin, int col) {
    int oct[3][5];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            oct[i][j] = 0;
            if (i == 0 && j == 2)
                oct[i][j] = 1;
            else if (i == 1 && j >= 1 && j <= 3)
                oct[i][j] = 1;
            else if (i == 2 && j == 2)
                oct[i][j] = 1;
        }
    }
    int centroLinha = 1, centroColuna = 2;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            if (oct[i][j] == 1) {
                int posLinha = lin + (i - centroLinha);
                int posCol = col + (j - centroColuna);
                if (posLinha >= 0 && posLinha < TAM && posCol >= 0 && posCol < TAM) {
                    if (tab[posLinha][posCol] == 0)
                        tab[posLinha][posCol] = 5;
                }
            }
        }
    }
}

int main() {

    // ------------------------- Criando o tabuleiro -------------------------  
    // Criando o tabuleiro (matriz 10x10)
    int tabuleiro[TAM][TAM]; // Declaração da matriz que representa o tabuleiro
    int i, j;
    char linha[TAM] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Array de caracteres que representa as letras das colunas (A a J)
    
    // Inicializa todas as posições do tabuleiro com 0 (representa água)
    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            tabuleiro[i][j] = 0;
        }
    }
       
    // ---------------------- Posicionamento dos Navios ----------------------
    // Cada navio terá tamanho fixo igual a 3 posições.
    const int tamanhoNavio = 3;
    
    // --- Navio Horizontal ---
    // Coordenadas iniciais para o navio horizontal
    // Posição: linha 2 (índice 2, ou seja, terceira linha) e coluna 3 (índice 3, quarta coluna)
    int linhaNavioH = 0;
    int colunaNavioH = 0;
    
    // Verifica se o navio horizontal cabe no tabuleiro (coluna inicial + tamanhoNavio - 1 < TAM)
    if (colunaNavioH + tamanhoNavio - 1 < TAM) {
        for (i = 0; i < tamanhoNavio; i++) {
            // Verifica se a posição já está ocupada para evitar sobreposição
            if (tabuleiro[linhaNavioH][colunaNavioH + i] != 0) {
                printf("Erro: sobreposição detectada no navio horizontal!\n");
                return 1;
            }
            // Posiciona o navio: valor 3 indica a presença de um navio
            tabuleiro[linhaNavioH][colunaNavioH + i] = 3;
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites!\n");
        return 1;
    }
    
    // --- Navio Vertical ---
    // Coordenadas iniciais para o navio vertical
    // Posição: linha 5 (índice 5, sexta linha) e coluna 7 (índice 7, oitava coluna)
    int linhaNavioV = 7;
    int colunaNavioV = 1;
    
    // Verifica se o navio vertical cabe no tabuleiro (linha inicial + tamanhoNavio - 1 < TAM)
    if (linhaNavioV + tamanhoNavio - 1 < TAM) {
        for (i = 0; i < tamanhoNavio; i++) {
            // Verifica se a posição já está ocupada para evitar sobreposição
            if (tabuleiro[linhaNavioV + i][colunaNavioV] != 0) {
                printf("Erro: sobreposição detectada no navio vertical!\n");
                return 1;
            }
            // Posiciona o navio: valor 3 representa a presença do navio
            tabuleiro[linhaNavioV + i][colunaNavioV] = 3;
        }
    } else {
        printf("Erro: Navio vertical fora dos limites!\n");
        return 1;
    }
    
    // --- Navio Diagonal 1 (Diagonal Crescente) ---
    // Posicionado na posição (0,0) e se estendendo para baixo e para a direita.
    int linhaNavioD1 = 4;
    int colunaNavioD1 = 0;
    if (linhaNavioD1 + tamanhoNavio - 1 < TAM && colunaNavioD1 + tamanhoNavio - 1 < TAM) {
        for (i = 0; i < tamanhoNavio; i++){
            if (tabuleiro[linhaNavioD1 + i][colunaNavioD1 + i] != 0) {
                printf("Erro: sobreposição no navio diagonal 1!\n");
                return 1;
            }
            tabuleiro[linhaNavioD1 + i][colunaNavioD1 + i] = 3;
        }
    } else {
        printf("Erro: Navio diagonal 1 fora dos limites!\n");
        return 1;
    }
        
    // --- Navio Diagonal 2 (Diagonal Decrescente) ---
    // Posicionado no canto superior direito: (0,9) e se estendendo para baixo e para a esquerda.
    int linhaNavioD2 = 0;
    int colunaNavioD2 = 9;
    if (linhaNavioD2 + tamanhoNavio - 1 < TAM && colunaNavioD2 - (tamanhoNavio - 1) >= 0) {
        for (i = 0; i < tamanhoNavio; i++){
            if (tabuleiro[linhaNavioD2 + i][colunaNavioD2 - i] != 0) {
                printf("Erro: sobreposição no navio diagonal 2!\n");
                return 1;
            }
            tabuleiro[linhaNavioD2 + i][colunaNavioD2 - i] = 3;
        }
    } else {
        printf("Erro: Navio diagonal 2 fora dos limites!\n");
        return 1;
    }
    
    // --------------------------- Sobreposição das Habilidades ---------------------------
    // Definindo os pontos de origem (centro da matriz de habilidade é (1,2)):
    // Para que o desenho fique centralizado, o valor passado à função será onde o centro (1,2)
    // da matriz 3x5 deverá ser posicionado no tabuleiro.
    // Conforme o exemplo, para obter o desenho desejado, usamos:
    // Cone em (2,3), Cruz em (6,7) e Octaedro em (8,4)
    desenharCone(tabuleiro, 2, 3);
    desenharCruz(tabuleiro, 6, 7);
    desenharOctaedro(tabuleiro, 8, 4);
    
    // --------------------------- Exibição do Tabuleiro ---------------------------
     // Mensagem de boas-vindas
    printf("\nBem vindo ao jogo da batalha naval com habilidades!\n");
     // Cabeçalho: imprime as letras das colunas (A a J)
    printf("\n TABULEIRO BATALHA NAVAL\n");
    printf("   "); // Espaço para alinhar com os números das linhas
    for (j = 0; j < TAM; j++){
        printf("%c ", linha[j]);
    }
    printf("\n");

     // Imprime cada linha do tabuleiro com o número da linha (1 a 10)
    for (i = 0; i < TAM; i++){
        printf("%2d ", i + 1); // Imprime o número da linha (usando i+1 para exibir de 1 a 10)
        for (j = 0; j < TAM; j++){
            printf("%d ", tabuleiro[i][j]); // Cada célula é impressa com um espaço separador
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }
    return 0; // Indica que o programa terminou com sucesso
}