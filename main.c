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
void criar_tabuleiro() {    
    printf("\nTabuleiro de Batalha Naval (0 = agua, 3 = navio):\n\n");
    int tab[LIN][COL];
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
            tab[i][j] = 0; // Inicializa todas as posições com 0 (água)
            printf("%d   ", tab[i][j]);
        }
        printf("\n");
    }
}

int main() {
    system("cls"); // Limpa a tela antes de exibir o tabuleiro
    criar_tabuleiro();
    printf("\n");
    return 0;
}