#include <stdio.h>

// Desafio Batalha Naval
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Nível Novato - Posicionamento dos Navios
// Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
// Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
// Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

int main() {

 // ------------------------- Criando o tabuleiro -------------------------  
 // Criando o tabuleiro (matriz 10x10)
 int tabuleiro[10][10]; // Declaração da matriz que representa o tabuleiro
 int i, j;
 char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Array de caracteres que representa as letras das colunas (A a J)
 
 // Inicializa todas as posições do tabuleiro com 0 (representa água)
 for (i = 0; i < 10; i++){
     for (j = 0; j < 10; j++){
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
 int linhaNavioH = 2;
 int colunaNavioH = 3;
 
 // Verifica se o navio horizontal cabe no tabuleiro (coluna inicial + tamanhoNavio - 1 < 10)
 if (colunaNavioH + tamanhoNavio - 1 < 10) {
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
 int linhaNavioV = 5;
 int colunaNavioV = 7;
 
 // Verifica se o navio vertical cabe no tabuleiro (linha inicial + tamanhoNavio - 1 < 10)
 if (linhaNavioV + tamanhoNavio - 1 < 10) {
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
 
 // ---------------------- Exibição do Tabuleiro ----------------------
 // Cabeçalho: imprime as letras das colunas
 printf("\n TABULEIRO BATALHA NAVAL\n");
 printf("   "); // Espaço para alinhar com os números das linhas
 for (j = 0; j < 10; j++){
     printf("%c ", linha[j]);
 }
 printf("\n");
 
 // Imprime cada linha do tabuleiro com o número da linha (1 a 10)
 for (i = 0; i < 10; i++){
     // Imprime o número da linha (usando i+1 para exibir de 1 a 10)
     printf("%2d ", i + 1);
     for (j = 0; j < 10; j++){
         // Cada célula é impressa com um espaço separador
         printf("%d ", tabuleiro[i][j]);
     }
     // Nova linha após cada linha do tabuleiro
     printf("\n");
 }
 
 return 0; // Indica que o programa terminou com sucesso
}