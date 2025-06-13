#include <cstdlib>
#include <stdio.h>
#include <iostream>

/* Tema aula: Ordenação,Função e Biblioteca
Este projeto ordena vetores com varios algoritmos
aula 30/05
Gabrela Mazon

*/

using namespace std;

//Assinatura da função listagem do vetor, ordenção do vetor
void listagem(int v[], int tam);
void bubblesort(int v[], int tam);


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

    //Vetor crescente

        cout<<endl<<"Estado do vetor antes da ordenação"<<endl;
    //Chamada da função listagem do vetor
    listagem (vCresc, TAM);

    //Ordenação BubbleSort.
   bubblesort(vCresc,TAM);

    cout<<endl<<"Estado do vetor depois da ordenação"<<endl;
    //Chamada da função listagem do vetor
    listagem (vCresc, TAM);

    //Vetor decrescente

    cout<<endl<<"Estado do vetor antes da ordenação"<<endl;
        //Chamada da função listagem do vetor
    listagem (vDecre, TAM);

    //Ordenação BubbleSort.
   bubblesort(vDecre,TAM);

    cout<<endl<<"Estado do vetor depois da ordenação"<<endl;
    //Chamada da função listagem do vetor
    listagem (vDecre, TAM);

    return 0;
}

//Função (void). Corpo da listagem do vetor 

void listagem(int v[], int tam){
    int i;
    for (i=0; i<tam;i++){
        cout<<i+1<< "º valor "<< v[i]<<endl;
    }
}
//Função de Ordenação BubbleSort

void bubblesort(int v[], int tam){
    int i,j,aux; //Variáveis locais.
 for (i=tam-1;i>0;i--){
        for (j=0;j < i;j++){
            if (v[j] > v[j+1]){//Se verdadeiro realiza a troca.
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }
}