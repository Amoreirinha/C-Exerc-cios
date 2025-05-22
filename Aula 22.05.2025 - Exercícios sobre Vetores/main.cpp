/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 22 de maio de 2025, 08:23
 * 
 * Exercícios:
 *      Crie um vetor com 20 números inteiros e coloque em um outro vetor os números sem repetição
 *      Crie um outro vetor e coloque os valores do vetor sem repetição de forma ordenada
 *      Crie outro vetor de números não repitidos para as operações abaixo:
 *         1. Crie um vetor ocm o resultado da operação de união dos vetores sem repetição
 *         2. Crie um vetor com o resultado da operação de interseção dos vetores sem repetição
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    const int TAM = 20;
    int vet[TAM]={0,2,4,5,6,1,3,4,5,5,2,3,7,8,9,10,2,10,9,3};
    int vetsemrep[TAM];
    int vetord[TAM];
    int vetordoutro[TAM]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int vetuni[2*TAM];
    int vetint[2*TAM];
    int i, j, elementosvetsemrep=0,temp, elementosuni=0, elementosint=0;
    bool repetido;
    
    cout << "\nVetor original:\n";
    
    // Exibindo o vetor
    for(i=0;i<TAM;i++){
        cout << i+1 << "° - " << vet[i] << endl;
    }
    
    for(i=0;i<TAM;i++){
        repetido = false;
        
        // Verifica se o elemento já existe no vetor sem repetição
        for(j=0;j<elementosvetsemrep;j++){
            if(vet[i] == vetsemrep[j]){
                repetido = true;
                break;
            }
        }
        
        // Se não for repetido, adiciona ao vetor sem repetição
        if(!repetido){
            vetsemrep[elementosvetsemrep] = vet[i];
            elementosvetsemrep++;
        }
    }
    

    cout << "\n\nVetor sem repetição:\n";

    for(i=0;i<elementosvetsemrep;i++){
        cout << i+1 << "° - " << vetsemrep[i] << endl;
    }
    
    // Ordenando o vetor sem repetição
    // Usando o método de ordenação por bolha (Bubble Sort)
    // Copiando os elementos do vetor sem repetição para o vetor de ordenação
    for(i=0;i<elementosvetsemrep;i++){
        vetord[i] = vetsemrep[i];
    }
    // Ordenação
    // Bubble Sort
    // O algoritmo Bubble Sort percorre o vetor várias vezes, comparando elementos adjacentes e trocando-os se estiverem na ordem errada.
    // O processo é repetido até que o vetor esteja ordenado.
    for(i=0;i<elementosvetsemrep;i++){
        for(j=i+1;j<elementosvetsemrep;j++){
            if(vetord[i]>vetord[j]){
                // Troca os elementos
                temp = vetord[i];
                vetord[i] = vetord[j];
                vetord[j] = temp;
            }
        }
    }

    cout << "\n\nVetor ordenado:\n";
    for(i=0;i<elementosvetsemrep;i++){
        cout << i+1 << "° - " << vetord[i] << endl;
    }

    // União dos vetores sem repetição
    // A união de dois conjuntos é o conjunto que contém todos os elementos que pertencem a pelo menos um dos conjuntos.

    for(i=0;i<elementosvetsemrep;i++){
        vetuni[i] = vetord[i];
    }
    
    elementosuni = elementosvetsemrep;

    for(i = 0; i < TAM; i++) {
        repetido = false;        
        // Verifica se vetordoutro[i] já está em vetuni
        for(j = 0; j < elementosuni; j++) {
            if(vetordoutro[i] == vetuni[j]) {
                repetido = true;
                break;
            }
        }
        
        // Se não for repetido, adiciona ao vetor de união
        if(!repetido) {
            vetuni[elementosuni] = vetordoutro[i];
            elementosuni++;
        }
    }

    cout << "\n\nUnião de Vetores ordenados:\n";
    for(i=0;i<elementosuni;i++){
        cout << i+1 << "° - " << vetuni[i] << endl;
    }

    // Interseção dos vetores sem repetição
    // A interseção de dois conjuntos é o conjunto que contém todos os elementos que pertencem a ambos os conjuntos.

    for(i=0;i<elementosvetsemrep;i++){
        repetido = false;

        for(j=0;j<TAM;j++){
            if(vetord[i]== vetordoutro[j]){
                repetido = true;
                break;
            } 
        }
        if(repetido){
            vetint[elementosint] = vetord[i];
            elementosint++;
            repetido = false;
        }
    }

    cout << "\n\nInterseção de Vetores ordenados:\n";
    for(i=0;i<elementosuni;i++){
        cout << i+1 << "° - " << vetint[i] << endl;
    }

    return 0;
}