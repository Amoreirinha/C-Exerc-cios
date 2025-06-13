/* 
 * 
 * Author: 2025.1.08.006
 * Tema: Aritmética de Ponteiros (Alocação Estática)
 * A váriável ponteiro armazena o valor de um endereço.
 * Ex: armazena o local do inteiro(endereço), não o inteiro.
 *  p=&x;  (atribui um valor inicial)
 * p=NULL; (atribui nada, endereço de controle)
 * int *p;
 * printf("O valor de p é %p",p);
 * printf("O valor de *p é %d",*p);
 * p++; 
 * ...
 * p++;
 * p++ != *p++; 
 * 
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int *p;
    int x, y, z;
    int v[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    x = 10;
    y = 12;
    z = 17;
    p = &x;
    printf("\n\n\t\tValor Inicial das  Variáveis");
    printf("\n\tO valor de p é: %p e o valor de *p é: %d", p, *p);
    printf("\n\tO valor de &x é: %p e o valor de x é: %d", &x, x);
    printf("\n\tO valor de &y é: %p e o valor de y é: %d", &y, y);
    printf("\n\tO valor de &z é: %p e o valor de z é: %d", &z, z);
    p++;

    printf("\n\n\t\tValor de p Incrementado");
    printf("\n\tO valor de p é: %p e o valor de *p é: %d", p, *p);

 /*   printf("\n\n\tValores do Vetor com Indice\n");
    for (int i = 0; i < 10; i++) {
        printf("\n\tO valor de &v[i] é: %p e o valor de v[i] é: %d", &v[i], v[i]);
    }
   */
    printf("\n\n\t\tValores do Vetor com Ponteiro");
    for (int *q = v; q < v + 10; q++) { //v é declarado como a primeira posição do vetor
        printf("\n\tO valor de q é: %p e o valor de *q é: %d", q, *q);
    }
 printf("\n\n\t\tValores do Vetor com Ponteiro");
    for (int *q = v+9; q >= v; q--) { //vetor começa no 0 e vai ate o 9 (Tamanho -1)
        printf("\n\tO valor de q é: %p e o valor de *q é: %d", q, *q);
    }

    return 0;
}

