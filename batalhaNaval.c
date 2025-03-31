#include <stdio.h>

// Desafio Batalha Naval
// Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
// Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
// Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

#define TAM 10  // Tamanho do tabuleiro (10x10)

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
 
 // Mensagem de boas-vindas
 printf("Bem vindo ao jogo da batalha naval!\n");
 
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

 // ---------------------- Exibição do Tabuleiro ----------------------
 // Cabeçalho: imprime as letras das colunas
 printf("\n TABULEIRO BATALHA NAVAL\n");
 printf("   "); // Espaço para alinhar com os números das linhas
 for (j = 0; j < TAM; j++){
     printf("%c ", linha[j]);
 }
 printf("\n");
 
 // Imprime cada linha do tabuleiro com o número da linha (1 a 10)
 for (i = 0; i < TAM; i++){
     // Imprime o número da linha (usando i+1 para exibir de 1 a 10)
     printf("%2d ", i + 1);
     for (j = 0; j < TAM; j++){
         // Cada célula é impressa com um espaço separador
         printf("%d ", tabuleiro[i][j]);
     }
     // Nova linha após cada linha do tabuleiro
     printf("\n");
 }
 
 return 0; // Indica que o programa terminou com sucesso
}