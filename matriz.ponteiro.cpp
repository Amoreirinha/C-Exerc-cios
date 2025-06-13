/*
 * File:   main.cpp
 * Author: Victória A. Tambasco
 *
 * Created on 13 de junho de 2025, 08:02
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

int main()
{
    int pisa_na_bosta[3][3] = {{1, 4, 9}, {2, 5, 9}, {7, 8, 1}};
    int cai_na_lama[3][3] = {{5, 4, 1}, {9, 0, 2}, {5, 5, 1}};
    int cai_na_bosta[3][3];
    int nado_na_bosta[3][3] = {0};

    // Leitura de matriz com ponteiro - CORREÇÃO: trocado *p por p no scanf
    /*printf("Digite os valores da matriz pisa_na_bosta:\n");
    for(int *p = &pisa_na_bosta[0][0]; p < &pisa_na_bosta[0][0]+3*3; p++){
        printf("digite o valor do pixel: ");
        scanf("%d", p);  // Corrigido: removido o *
    }
    */
    // Escrita da matriz com ponteiros - CORREÇÃO: adicionado formatação
    printf("\nMatriz pisa_na_bosta:\n");
    for(int *p = &pisa_na_bosta[0][0], i = 0; p < &pisa_na_bosta[0][0]+3*3; p++, i++){
        printf("%d\t", *p);
        if((i+1) % 3 == 0) printf("\n");  // Quebra linha a cada 3 elementos
    }

    // Soma de matrizes com ponteiros - CORREÇÃO: sintaxe do for e condições
    printf("\nSoma das matrizes:\n");
    for(int *p = &pisa_na_bosta[0][0], *q = &cai_na_lama[0][0], *r = &cai_na_bosta[0][0];
        p < &pisa_na_bosta[0][0]+3*3;  // Corrigido: removida vírgula extra
        p++, q++, r++){
        *r = *p + *q;
    }
    
    // Exibição do resultado - CORREÇÃO: adicionado formatação
    for(int *p = &cai_na_bosta[0][0], i = 0; p < &cai_na_bosta[0][0]+3*3; p++, i++){
        printf("%d\t", *p);
        if((i+1) % 3 == 0) printf("\n");  // Quebra linha a cada 3 elementos
    }

    return 0;
}