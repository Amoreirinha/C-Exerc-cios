#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <stdio.h>

using namespace std;

// Função de Listagem do Vetor

void listagem(int v[], int tam)
{
    int *i, posicao = 0;
    printf("\nListagem do vetor:\n");
    for (i = v; i < v + tam; i++, posicao++)
    {
        printf("Posição %d ==> Valor do endereço %p é %d\n", posicao, i, *i);
    }
}

// Função de Restauração dos Vetores

void restaurarVetores(int vAlet[], int vCresc[], int vDecre[], int TAM)
{

    int tempAlet[TAM] = {17, 14, 16, 12, 20, 15, 19, 11, 13, 18};
    int tempCresc[TAM] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int tempDecre[TAM] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11};
    int *m = vAlet, *n = vCresc, *o = vDecre;

    for (int *i = tempAlet, *j = tempCresc, *k = tempDecre; i < tempAlet + TAM; i++, j++, k++)
    {
        *m = *i;
        *n = *j;
        *o = *k;
        m++;
        n++;
        o++;
    }
}

// Função de Ordenação BubbleSort

void bubblesort(int v[], int tam)
{
    int *i, *j, aux;
    for (i = v + tam - 1; i > v; i--)
    {
        for (j = v; j < i; j++)
        {
            if (*j > *(j + 1))
            {
                aux = *j;
                *j = *(j + 1);
                *(j + 1) = aux;
            }
        }
    }
}

// Função de Ordenação InsertionSort

void insertionsort(int v[], int tam)
{
    int *i, *j, aux;

    for (i = v + 1; i < v + tam; i++)
    {
        aux = *i;  // Armazena o valor atual
        j = i - 1; // Ponteiro para o elemento anterior

        // Move os elementos maiores que aux para frente
        while (j >= v && *j > aux)
        {
            *(j + 1) = *j;
            j--;
        }

        *(j + 1) = aux; // Insere o elemento na posição correta
    }
}

// Função de Ordenação SelectionSort

void selectionsort(int v[], int tam){
    int *i, *j, *aux;
    for (i = v; i < v + tam; i++){
        aux = i;
        for (j = i + 1; j < v + tam; j++){
            if (*j < *aux){
                aux = j;
            }
        }
        // Troca o elemento mínimo com o primeiro não ordenado
        int temp = *i;
        *i = *aux;
        *aux = temp;
    }
}

// Função de Barra de Separação

void barra(int choice)
{
    if (choice == 1)
    {
        cout << "\n______________________________________\n";
    }
    else if (choice == 2)
    {
        cout << "\n-------------------------------------\n";
    }
    else if (choice == 3)
    {
        cout << "\n=====================================\n";
    }
}

void setColor(int estilo, int corTexto, int corFundo = -1) {
    if (corFundo == -1)
        printf("\033[%d;%dm", estilo, corTexto);      // Sem fundo
    else
        printf("\033[%d;%d;%dm", estilo, corTexto, corFundo); // Com fundo
}

void resetColor() {
    printf("\033[0m");
}

#endif // SORTING_H