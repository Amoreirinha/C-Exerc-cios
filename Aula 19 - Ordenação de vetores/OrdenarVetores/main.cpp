#include <cstdlib>
#include <iostream>
#include "ordenacao.h" //Biblioteca que tem 2 funções

/* Tema aula: Ordenação,Função e Biblioteca
Este projeto ordena vetores com varios algoritmos
aula 30/05
 * Exercício: criar o insertion e selection na biblioteca
Gabrela Mazon

*/

using namespace std;




//Função (main), uma função principal
int main (int argc, char** argv){

    const int TAM=10;
    
    int vAlet[] = {17,14,16,12,20,15,19,11,13,18}; //Caso que mais ocorre.
    int vCresc[] = {11,12,13,14,15,16,17,18,19,20}; //melhor caso.
    int vDecre[] = {20,19,18,17,16,15,14,13,12,11}; //Pior caso.


    //Vetor aleatório
    
    cout<<endl<<"Estado do vetor antes da ordenação"<<endl;
    //Chamada da função listagem do vetor
    listagem (vAlet, TAM);

    //Ordenação BubbleSort.
   bubblesort(vAlet,TAM);

    cout<<endl<<"Estado do vetor depois da ordenação"<<endl;
    //Chamada da função listagem do vetor
    listagem (vAlet, TAM);
    
     cout<<endl<<"Estado do vetor depois da ordenação"<<endl;
    //Chamada da função insertion sort
    insertionsort (vAlet, TAM);

    //Vetor crescente

        cout<<endl<<"Estado do vetor antes da ordenação"<<endl;
    //Chamada da função listagem do vetor
    listagem (vCresc, TAM);

    //Ordenação BubbleSort.
   bubblesort(vCresc,TAM);

    cout<<endl<<"Estado do vetor depois da ordenação"<<endl;
    //Chamada da função listagem do vetor
    listagem (vCresc, TAM);
    cout<<endl<<"Estado do vetor depois da ordenação"<<endl;
    //Chamada da função insertion sort
    insertionsort (vCresc, TAM);

    //Vetor decrescente

    cout<<endl<<"Estado do vetor antes da ordenação"<<endl;
        //Chamada da função listagem do vetor
    listagem (vDecre, TAM);

    //Ordenação BubbleSort.
   bubblesort(vDecre,TAM);

    cout<<endl<<"Estado do vetor depois da ordenação"<<endl;
    //Chamada da função listagem do vetor
    listagem (vDecre, TAM);
    cout<<endl<<"Estado do vetor depois da ordenação"<<endl;
    //Chamada da função insertion sort
    insertionsort (vDecre, TAM);

    return 0;
}

