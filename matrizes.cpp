/* 
 * File:   main.cpp
 * Author: Victória A. Tambasco
 *
 * Created on 13 de junho de 2025, 08:02
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*MATRIZES(variável composta multidimensional)
 \\declaração
 <tipo> identificador[dim1][dim2]...[dim n];
 dim1 == dim2 == ... == dim n == tamanho

 \\utilização como uma variável simples
 ... identificador[ind1][ind2]...[ind n]...;
ind1 == ind2 == ... == ind n == -> valor inteiro
                                -> variável
                                -> expressão aritmetica inteiro

Exemplo:
int imagem [1024][1024];
.
. 
. 
... imagem[i][j]... 

Exercício:
1- Faça a leitura de 2 matrizes, calcule a soma numa 3 matriz e apresente o resultado
 
 */
int main() {
    int i,j;
int gatinhos[3][3] = {{1,4,9},{2,5,9},{7,8,1}};
int cachorrinhos[3][3] = {{5,4,1},{9,0,2},{5,5,1}};
int cachorrinhos_e_gatinhos[3][3];
int muitos_cachorrinhos_e_muitos_gatinhos[3][3] = {0}; 

    //escrita de matriz
    /* for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            printf("matriz[%d][%d]:", i+1, j+1);
            scanf("%d", imagem [i][j]);
        }
     }
    */
    
    //leitura da matriz
    for(int i = 0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("gatinhos[%d][%d]=%d\t", i+1, j+1, gatinhos[i][j]);
        }
        printf("\n\n");
    }

    printf("\n\n");
    
    //leitura da matriz
    for(int i = 0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("cachorrinhos[%d][%d]=%d\t", i+1, j+1, cachorrinhos[i][j]);
        }
        printf("\n\n");
    }

    printf("\n\nSoma de Matrizes:\n");

    //soma de matrizes
    for(int i = 0; i<3; i++){
        for(int j=0; j<3; j++){
            cachorrinhos_e_gatinhos[i][j] = cachorrinhos[i][j] + gatinhos[i][j];
            printf("%d\t", cachorrinhos_e_gatinhos[i][j]);
        }
        printf("\n\n");
    }

    printf("\n\nMultiplicação de Matrizes:\n");

    // Multiplicação de Matrizes
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                muitos_cachorrinhos_e_muitos_gatinhos[i][j] += gatinhos[i][k] * cachorrinhos[k][j];
            }
            printf("%d\t", muitos_cachorrinhos_e_muitos_gatinhos[i][j]);
        }
        printf("\n\n");
    }
    

    return 0;
}