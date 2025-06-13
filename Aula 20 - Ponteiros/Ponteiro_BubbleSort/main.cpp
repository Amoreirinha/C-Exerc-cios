#include <cstdlib>
#include <stdio.h>
#include <iostream>

/* Tema aula: Ponteiro com bubble sort
aula 12/06
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



void listagem(int v[], int tam) {
    int *i; // Declara i como um ponteiro para int

    // i começa apontando para o primeiro elemento do vetor
    // O loop continua enquanto i estiver antes do final do vetor
    // i é incrementado para apontar para o próximo elemento
    for (i = v; i < v + tam; i++) {
        printf("Valor do endereço de v: %p e valor de v:%d\n", (void*)i, *i);
        // (void*)i é um cast comum para %p, para evitar warnings e garantir portabilidade.
        // Adicionei um \n para que cada valor seja impresso em uma nova linha, facilitando a leitura.
    }
}

void bubblesort(int v[], int tam) {
    int *i_limit; // Ponteiro para o limite superior (diminui a cada iteração)
    int *j_current; // Ponteiro para o elemento atual no loop interno
    int aux; // Variável auxiliar para a troca

    // Loop externo: i_limit começa no final do vetor e move-se para o início.
    // Ele marca a última posição que ainda precisa ser verificada.
    // O (v + 1) é para garantir que o loop continue até que i_limit seja v (o primeiro elemento).
    for (i_limit = v + tam - 1; i_limit > v; i_limit--) {
        // Loop interno: j_current começa no início do vetor e vai até o i_limit.
        // Ele compara elementos adjacentes e "borbulha" o maior para a direita.
        for (j_current = v; j_current < i_limit; j_current++) {
            // Se o valor apontado por j_current for maior que o próximo elemento
            if (*j_current > *(j_current + 1)) {
                // Realiza a troca usando a variável auxiliar
                aux = *j_current;
                *j_current = *(j_current + 1);
                *(j_current + 1) = aux;
            }
        }
    }
}