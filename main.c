#include <stdio.h>
#include <stdlib.h>

#define LIN 10
#define COL 10

/* 
 * Autor: Willem de Lima Ricardo
 * Data: 2024-06-27
 * Descrição: Simulação de um tabuleiro de batalha naval em C.
*/

/*
 * Objetivo: Criar um programa em C que simule um tabuleiro de batalha naval, posicionando navios 
 * e exibindo o tabuleiro no console. Posicione os Navios: Declare e inicialize dois vetores (arrays unidimensionais) 
 * para representar os navios. Cada navio ocupará um número fixo de posições no tabuleiro (defina esse tamanho, 
 * por exemplo, 3 posições). Um navio será posicionado horizontalmente e o outro verticalmente. Represente as posições 
 * ocupadas pelos navios na matriz do tabuleiro com o valor 3. Você deverá escolher as coordenadas iniciais de cada 
 * navio e garantir que eles estejam completamente dentro dos limites do tabuleiro e não se sobreponham. 
 * Dica: O posicionamento do navio pode ser feito copiando o valor 3 de cada posição do vetor do navio para as 
 * posições correspondentes na matriz do tabuleiro, de acordo com a orientação (horizontal ou vertical) do navio.
 * 
 * Exiba o Tabuleiro: Utilize loops aninhados e o comando printf para exibir o tabuleiro no console. Mostre a matriz 
 * completa, com 0s representando água e 3s representando as partes dos navios. A saída deve ser clara e organizada, 
 * permitindo visualizar facilmente a posição dos navios. 
 * Dica: Imprima um espaço ou outro caractere separador entre os elementos da matriz para facilitar a visualização.
*/

// FUNÇÕES AUXILIARES
/* Criar tabuleiro : cria um tabuleiro com LIN linhas e COL colunas */
void criar_tabuleiro(int tab[LIN][COL]) {    
    printf("\nTabuleiro de Batalha Naval (0 = água, 3 = navio):\n\n");
    int titulo_linha[LIN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char titulo_coluna[COL] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    printf("     ");
    for (int j = 0; j < COL; j++) {
        printf(" [%c]", titulo_coluna[j]);
    }
    printf("\n");
    for (int i = 0; i < LIN; i++) {
        printf(" [%2d]  ", titulo_linha[i]);
        for (int j = 0; j < COL; j++) {
            tab[i][j] = 0;                          // Inicializa todas as posições com 0 (água)
            printf("%d   ", tab[i][j]);
        }
        printf("\n");
    }
}

void inicializar_tabuleiro(int tab[LIN][COL]) {
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            tab[i][j] = 0;                          // Inicializa todas as posições com 0 (água)
        }
    }
}

/* Imprimir tabuleiro : mostra o tabuleiro com os navios */
void imprimir_tabuleiro(int tab[LIN][COL]) {
    int titulo_linha[LIN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char titulo_coluna[COL] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    printf("\n     ");
    for (int j = 0; j < COL; j++) {
        printf(" [%c]", titulo_coluna[j]);
    }
    printf("\n");
    for (int i = 0; i < LIN; i++) {
        printf(" [%2d]  ", titulo_linha[i]);
        for (int j = 0; j < COL; j++) {
            printf("%d   ", tab[i][j]);
        }
        printf("\n");
    }
}

/* Inserir navio : insere um navio no tabuleiro de acordo com suas dimensões */
void inserir_navio(int tab[LIN][COL], int linha, int coluna, int tamanho, char orientacao) {
    linha--;                                        // Ajusta para índice baseado em 0
    coluna--;                                       // Ajusta para índice baseado em 0    
    if (orientacao == 'H') {                        // O navio está na posição horizontal
        if (linha < 0 || linha >= LIN || coluna < 0 || coluna + tamanho > COL) {    // Verifica se o navio cabe no tabuleiro
            printf("      -> Posição inválida para o navio horizontal.\n");
            return;
        }
        for (int i = 0; i < tamanho; i++) {
            if (coluna + i < COL) {
                tab[linha][coluna + i] = 3;         // Marca a posição do navio com 3
            }
        }
    } else if (orientacao == 'V') {                 // O navio está na posição vertical
        if (coluna < 0 || coluna >= COL || linha < 0 || linha + tamanho > LIN) {    // Verifica se o navio cabe no tabuleiro
            printf("      -> Posição inválida para o navio vertical.\n");
            return;
        }
        for (int i = 0; i < tamanho; i++) {
            if (linha + i < LIN) {
                tab[linha + i][coluna] = 3;         // Marca a posição do navio com 3
            }
        }
    }
}

int main() {
    system("cls");                                                          // Limpa a tela antes de exibir o tabuleiro    
    printf("\nTabuleiro de Batalha Naval (0 = água, 3 = navio):\n\n");      // Cria o tabuleiro de maneira estática
    int tab[LIN][COL];

    inicializar_tabuleiro(tab);                                             // Inicializa o tabuleiro com 0 (água)
    inserir_navio(tab, 0, 5, 3, 'H');                                       // Insere um navio horizontal de tamanho 3 na linha 2, coluna 3
    inserir_navio(tab, 11, 6, 3, 'V');                                       // Insere um navio vertical de tamanho 3 na linha 5, coluna 6
    imprimir_tabuleiro(tab);                                                // Imprime o tabuleiro inicial
    
    printf("\n");
    return 0;
}