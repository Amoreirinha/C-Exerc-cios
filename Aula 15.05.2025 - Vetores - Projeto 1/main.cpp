/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 15 de maio de 2025, 08:37
 * 
 * Exercícios: vetores
 * 
 * 1. Inverta os valores de um vetor (1° com o último, 2° com o penúltimo)
 * 
 * 2. Adicione um valor o todos os elementos
 * 
 * 3. Adicione um valor a todos os elementos não divisíveis por três
 * 
 * 4. Remova do vetor a 1ª ocorrência de um vetor
 * 
 * 5. Remova do vetor todas as ocorrências de um valor
 * 
 * 6. Inserir um valor no vetor, se não estiver cheio
 * 
 * 7. Inserir um valor em uma posição determinada
 * 
 * 8. Remove todos os valores repetidos de um valor
 */

#include <cstdlib>
#include <iostream>
#include <string.h>


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    const int TAM = 1000;
    float vetor[1000], valor, troca, numremove;
    int choice = 0, i, j, valormin, valormax;
    bool loop = true, removed = false;
    string loopquest;

    // Inicializa gerador de números aleatórios
    srand(time(NULL));

    cout << "Selecione o menor valor a ser gerado:\n";
    cin >> valormin;
    cout << "Selecione o maior valor a ser gerado:\n";
    cin >> valormax;
    while (valormin > valormax) {
        cout << "ERROR!\n\nValor mínimo digitado maior que o valor máximo";
        cout << "Selecione o menor valor a ser gerado:\n";
        cin >> valormin;
        cout << "Selecione o maior valor a ser gerado:\n";
        cin >> valormax;
    }

    for (i = 0; i < TAM; i++) {
        valor = ((rand() % (valormax - valormin + 1)) + valormin);
        vetor[i] = valor;
    }
    while (loop == true) {
        switch (choice) {
            case 0:
                cout << "\nSelecione a ação a ser feita:\n\t1-Inverta os valores de um vetor (1° com o último, 2° com o penúltimo)\n\t2-Adicione um valor o todos os elementos\n\t3-Adicione um valor a todos os elementos não divisíveis por três\n\t4-Remova do vetor a 1ª ocorrência de um vetor\n";
                cin >> choice;
                choice++;
                while (choice != 2 && choice != 3 && choice != 4 && choice != 5) {
                    cout << "Valor digitado inválido\n\n";
                    cout << "\nSelecione a ação a ser feita:\n\t1-Inverta os valores de um vetor (1° com o último, 2° com o penúltimo)\n\t2-Adicione um valor o todos os elementos\n\t3-Adicione um valor a todos os elementos não divisíveis por três\n\t4-Remova do vetor a 1ª ocorrência de um vetor\n";
                    cin >> choice;
                    choice++;
                }

                break;
            case 1:
                loopquest = "x";
                cout << "\n\nGostaria de retornar ao Menu? Digite 's' para SIM e 'n' para NÃO:\n";
                cin >> loopquest;

                while (loopquest != "s" && loopquest != "n") {
                    cout << "\n\nVALOR INVÁLIDO INSERIDO\n\n";
                    cout << "Gostaria de retornar ao Menu? Digite 's' para SIM e 'n' para NÃO:\n";
                    cin >> loopquest;
                }

                if (loopquest == "s") {
                    choice = 0;
                } else {
                    cout << "\n\nADEUS!\n\n";
                    loop = false;
                }
                break;

            case 2:
                // Inverta os valores de um vetor (1° com o último, 2° com o penúltimo)
                cout << "\nInverta os valores de um vetor (1° com o último, 2° com o penúltimo)\n";
                for (i = 0; i < TAM; i++) {
                    troca = vetor[i];
                    vetor[i] = vetor[TAM - 1 - i];
                    vetor[TAM - 1 - i] = troca;
                }
                cout << "\nVetor invertido\n";
                for (i = 0; i < TAM; i++) {
                    cout << vetor[i] << endl;
                }
                choice = 1; //Quest Menu
                break;

            case 3:
                // Adicione um valor o todos os elementos
                cout << "\nAdicione um valor o todos os elementos\n";
                for (i = 0; i < TAM; i++) {
                    vetor[i]++;
                }
                cout << "\nVetor incrementado\n";
                for (i = 0; i < TAM; i++) {
                    cout << vetor[i] << endl;
                }
                choice = 1; //Quest Menu
                break;

            case 4:
                //Adicione um valor a todos os elementos não divisíveis por três
                cout << "\nAdicione um valor a todos os elementos não divisíveis por três\n";
                for (i = 0; i < TAM; i++) {
                    if (((int) vetor[i] % 3) != 0) {
                        vetor[i]++;
                    }
                }
                cout << "\nVetor incrementado\n";
                for (i = 0; i < TAM; i++) {
                    cout << vetor[i] << endl;
                }
                choice = 1; //Quest Menu                
                break;

            case 5:
                //Remova do vetor a 1ª ocorrência de um vetor
                cout << "\nRemova do vetor a 1ª ocorrência de um vetor\n\nDigite o número a ter sua primeira ocorrência removida:\n";
                cin >> numremove;
                for (i = 0; i < TAM; i++) {
                    if (numremove == vetor[i]) {
                        vetor[i] = vetor[i + 1];
                        j = i + 1;
                        removed = true;
                        break;
                    } else if (numremove == vetor[i] && i == TAM){
                        vetor[i]=0;
                        j = i + 1;
                        removed = true;
                    }
                }
                if (removed == true) {
                    for (i = j; i < TAM -1; i++) {
                        vetor[i] = vetor[i + 1];
                    }
                    vetor[TAM - 1] = 0;
                    cout << "\nPrimeira ocorrência de " << numremove << " removida\n";
                    for (i = 0; i < TAM; i++) {
                        cout << vetor[i] << endl;
                    }
                } else {
                    cout << "\nValor não encontrado\n";
                }
                choice = 1; //Quest Menu 
                break;

        }
    }
    return 0;
}

