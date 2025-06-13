

#include <iostream>

using namespace std;
//Função (void). Corpo da listagem do vetor 

void listagem(int v[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        cout << i + 1 << "º valor " << v[i] << endl;
    }
}
//Algoritmo BubbleSort

void bubblesort(int v[], int tam) {
    int i, j, aux; //Variáveis locais.
    for (i = tam - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {//Se verdadeiro realiza a troca.
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

//Algoritmo Insertion sort

void insertionsort(int v[], int tam) {
    int i, j, aux;
    for (i = 1; i < tam; i++) {
        j = i;
        while (j > 0 && v[j]< v[j - 1]) {
            aux = v[j];
            v[j] = v[j - 1];
            v[j - 1] = aux;
            j -= 1;
        }
    }
}