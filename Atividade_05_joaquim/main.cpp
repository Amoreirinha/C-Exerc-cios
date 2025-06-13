#include <cstdlib>
#include <stdio.h>
#include <iostream>

using namespace std;

/*
 * 
 */

//Função (void). Corpo da listagem do vetor 

void listagem(int v[], int tam){
    int *i;
    for (i = v; i < v + tam; i++){
        printf("Valor do endereço %p é %d\n", i, *i);
    }
}

//Função de Ordenação BubbleSort

void bubblesort(int v[], int tam){
    int *i, *j, aux;
    for (i = v + tam - 1; i > v; i--){
        for (j = v; j < i; j++){
            if (*j > *(j + 1)){
                aux = *j;
                *j = *(j + 1);
                *(j + 1) = aux;
            }
        }
    }
}

int barra(int choice){
    if (choice == 1){
        printf("\n______________________________________\n");
    } else if(choice == 2){
        printf("\n-------------------------------------\n");
    } else if(choice == 3)
}

int main(int argc, char** argv) {



using namespace std;

//Assinatura da função listagem do vetor, ordenção do vetor
void listagem(int v[], int tam);
void bubblesort(int v[], int tam);
 

    const int TAM=10;
    
    int vAlet[] = {17,14,16,12,20,15,19,11,13,18}; //Caso que mais ocorre.
    int vCresc[] = {11,12,13,14,15,16,17,18,19,20}; //melhor caso.
    int vDecre[] = {20,19,18,17,16,15,14,13,12,11}; //Pior caso.


    //Vetor aleatório
    
    cout << "\n\nOrdenação por bubble sort\n\nVetor de ordem aleatória:\n";

    cout<<endl<<"Estado do vetor antes da ordenação"<<endl;
    //Chamada da função listagem do vetor
    listagem (vAlet, TAM);

    //Ordenação BubbleSort.
    bubblesort(vAlet,TAM);

    cout<<endl<<"Estado do vetor depois da ordenação por bubble sort"<<endl;
    //Chamada da função listagem do vetor
    listagem (vAlet, TAM);
    
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




    return 0;
}
