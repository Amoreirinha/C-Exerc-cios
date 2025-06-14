/*
 * Projeto: Métodos de Ordenação com Ponteiros
 * 
 * Este projeto implementa métodos de ordenação utilizando exclusivamente ponteiros, sem o uso de índices em qualquer situação.
 * Todos os métodos de ordenação estão implementados em uma biblioteca separada (.h e .cpp).
 * 
 * Faça um projeto com os métodos de ordenação implementados com ponteiros. Estes métodos devem estar implementados em uma biblioteca e não podem utilizar índices em qualquer situação.
 * Na entrega, envie somente os arquivos .h e .cpp dos métodos.
 * 
 * Joaquim Pedro do Nascimento Moreira de Jesus
 * AED's - Prática
 * Atividade - Ordenação com Ponteiros
 * Data: 14/06/2025
 */

#include <cstdlib> // Para usar a função system()
#include <stdio.h> // Para usar a função printf()
#include <iostream> // Para usar a biblioteca padrão de entrada e saída
#include "ordenacaofunction.h" // Inclui o cabeçalho com as funções de ordenação e listagem

using namespace std;

int main() {
    //Declaração de variáveis
    const int TAM=10; // Tamanho do vetor

    // Vetores de teste    
    int vAlet[] = {17,14,16,12,20,15,19,11,13,18}; //Caso que mais ocorre.
    int vCresc[] = {11,12,13,14,15,16,17,18,19,20}; //melhor caso.
    int vDecre[] = {20,19,18,17,16,15,14,13,12,11}; //Pior caso.


    setColor(1, 32); // Define a cor do texto para verde
    //Vetor aleatório

    barra(3);
    
    cout << "\n\nOrdenação por bubble sort\n";

    barra(1);

    cout << "\nVetor de ordem aleatória:\n";

    cout<<endl<<"Estado do vetor antes da ordenação"<<endl;
    //Chamada da função listagem do vetor
    listagem (vAlet, TAM);

    //Ordenação BubbleSort.
    bubblesort(vAlet,TAM);

    cout<<endl<<"Estado do vetor depois da ordenação por bubble sort"<<endl;
    //Chamada da função listagem do vetor
    listagem (vAlet, TAM);
    
    barra(2);

    cout << "\nVetor de ordem crescente:\n";
    //Vetor crescente

    cout<<endl<<"Estado do vetor antes da ordenação"<<endl;
    //Chamada da função listagem do vetor
    listagem (vCresc, TAM);

    //Ordenação BubbleSort.
    bubblesort(vCresc,TAM);

    cout<<endl<<"Estado do vetor depois da ordenação por bubble sort"<<endl;
    //Chamada da função listagem do vetor
    listagem (vCresc, TAM);

    barra(2);
    
    cout << "\nVetor de ordem decrescente:\n";

    //Vetor decrescente

    cout<<endl<<"Estado do vetor antes da ordenação"<<endl;
        //Chamada da função listagem do vetor
    listagem (vDecre, TAM);

    //Ordenação BubbleSort.
   bubblesort(vDecre,TAM);

    cout<<endl<<"Estado do vetor depois da ordenação por bubble sort"<<endl;
    //Chamada da função listagem do vetor
    listagem (vDecre, TAM);

    barra(3);

    setColor(1, 34); // Define a cor do texto para azul

    //Restauração do vetor original

    restaurarVetores(vAlet, vCresc, vDecre, TAM);

    cout << "\n\nOrdenação por Insertion Sort\n";

    barra(1);

    cout << "\nVetor de ordem aleatória:\n";

    cout << endl <<"Estado do vetor antes da ordenação"<<endl;

    listagem (vAlet, TAM);

    insertionsort(vAlet, TAM);

    cout << endl <<"Estado do vetor depois da ordenação"<<endl;

    listagem (vAlet, TAM);

    barra(2);

    cout << "\nVetor de ordem crescente:\n";

    cout << endl <<"Estado do vetor antes da ordenação"<<endl;

    listagem (vCresc, TAM);

    insertionsort(vCresc, TAM);

    cout << endl <<"Estado do vetor depois da ordenação"<<endl;

    listagem (vCresc, TAM);

    barra(2);

    cout << "\nVetor de ordem decrescente:\n";

    cout << endl <<"Estado do vetor antes da ordenação"<<endl;

    listagem (vDecre, TAM);

    insertionsort(vDecre, TAM);

    cout << endl <<"Estado do vetor depois da ordenação"<<endl;

    listagem (vDecre, TAM);

    barra(3);

    setColor(1, 31); // Define a cor do texto para vermelho

    //Restauração do vetor original

    restaurarVetores(vAlet, vCresc, vDecre, TAM);

    cout << "\n\nOrdenação por Selection Sort\n";

    barra(1);

    cout << "\nVetor de ordem aleatória:\n";

    cout << endl <<"Estado do vetor antes da ordenação"<<endl;

    listagem (vAlet, TAM);

    selectionsort(vAlet, TAM);

    cout << endl <<"Estado do vetor depois da ordenação"<<endl;

    listagem (vAlet, TAM);

    barra(2);

    cout << "\nVetor de ordem crescente:\n";

    cout << endl <<"Estado do vetor antes da ordenação"<<endl;

    listagem (vCresc, TAM);

    selectionsort(vCresc, TAM);

    cout << endl <<"Estado do vetor depois da ordenação"<<endl;

    listagem (vCresc, TAM);

    barra(2);

    cout << "\nVetor de ordem decrescente:\n";

    cout << endl <<"Estado do vetor antes da ordenação"<<endl;

    listagem (vDecre, TAM);

    selectionsort(vDecre, TAM);

    cout << endl <<"Estado do vetor depois da ordenação"<<endl;

    listagem (vDecre, TAM);

    barra(3);

    cout << "\n\nFim do programa.\n";

    resetColor(); // Reseta a cor do texto para o padrão

    return 0;
}
