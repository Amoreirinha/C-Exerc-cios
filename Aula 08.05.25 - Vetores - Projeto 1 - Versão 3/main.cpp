/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 9 de maio de 2025, 08:28
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    float alturas[1000000], num, soma = 0, media, altin, maior, menor;
    const int TAM = 1000000;
    int SWAP, contmedia, contmediamaior, contmediamenor, choice, contmaioraltin = 0, contaltin = 0, contmenoraltin = 0, contmaior = 0, contigual = 0, contmenor = 0;
    bool loop = true;
    string loopquest;
    choice = 0;

    //Lê o arquivo inicial
    ifstream alturas_arquivo_leitura("alturas.txt");
    if (!alturas_arquivo_leitura.is_open()) {
        cout << "\nErro: Arquivo não encontrado.\n";
        return 1;
    }

    for (SWAP = 0; SWAP < TAM; SWAP++) {
        alturas_arquivo_leitura >> num;
        alturas[SWAP] = num;
    }

    SWAP = 0;

    alturas_arquivo_leitura.close();

    cout << "Bem vindo ao sistema de análise e geração de alturas";
    while (loop == true) {
        switch (choice) {
            case 0:
                //Menu
                cout << "\nSelecione a ação a ser realizada:\n\t1 - Gerar alturas\n\t2 - Calcular Média\n\t3 - Análise referente a média\n\t4 - Visualizar Alturas\n\t5 - Análise referente a uma altura especificada\n\t6 - Análise por uma faixa de valores especificados" << endl;
                cin >> choice;
                choice++;
                while (choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7) {
                    cout << "\n\nValor Inválido Inserido!!\n\n";
                    cout << "\nSelecione a ação a ser realizada:\n\t1 - Gerar alturas\n\t2 - Calcular Média\n\t3 - Análise referente a média\n\t4 - Visualizar Alturas\n\t5 - Análise referente a uma altura especificada\n\t6 - Análise por uma faixa de valores especificados" << endl;
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
            {
                //Gerar Alturas
                cout << "\n\nGerando alturas ...\n";
                ofstream alturas_arquivo("alturas.txt");
                if (!alturas_arquivo.is_open()) {
                    cout << "\nErro: Arquivo não encontrado.\n";
                    return 1;
                }

                // Inicializa gerador de números aleatórios
                srand(time(NULL));

                for (SWAP = 0; SWAP < TAM; SWAP++) {
                    num = ((rand() % (230 - 30 + 1)) + 30)*0.01;
                    alturas_arquivo << num << endl;
                    alturas[SWAP] = num;
                }

                SWAP = 0;

                alturas_arquivo.close();

                cout << "Alturas geradas!\n";
                loopquest = "x";
                cout << "Gostaria de Visualizar as alturas geradas? Digite 's' para SIM e 'n' para NÃO:\n";
                cin >> loopquest;

                while (loopquest != "s" && loopquest != "n") {
                    cout << "\n\nVALOR INVÁLIDO INSERIDO\n\n";
                    cout << "Gostaria de Visualizar as alturas geradas? Digite 's' para SIM e 'n' para NÃO:\n";
                    cin >> loopquest;
                }

                if (loopquest == "s") {
                    choice = 5; //Quest Ver valores
                } else {
                    choice = 1; //Quest Menu
                }
                break;
            }

            case 3:
                //Média              

                // Leitura dos valores
                for (SWAP = 0; SWAP < TAM; SWAP++) {
                    soma += alturas[SWAP];
                }
                SWAP = 0;

                //Media
                media = soma / TAM;
                cout << "\nMédia das alturas: " << media << endl;
                choice = 1; //Quest Menu

                break;

            case 4:
                //Análise referente a média

                cout << "\nAnálise referente a média\n\n";

                for (SWAP = 0; SWAP < TAM; SWAP++) {
                    if (alturas[SWAP] > media) {
                        contmediamaior++;
                        cout << "A " << (SWAP + 1) << "ª altura é maior que a média e tem valor de " << alturas[SWAP] << endl;
                    }
                }

                for (SWAP = 0; SWAP < TAM; SWAP++) {
                    if (alturas[SWAP] < media) {
                        contmediamenor++;
                        cout << "A " << (SWAP + 1) << "ª altura é menor que a média e tem valor de " << alturas[SWAP] << endl;
                    }
                }

                for (SWAP = 0; SWAP < TAM; SWAP++) {
                    if (alturas[SWAP] == media) {
                        contmedia++;
                        cout << "A " << (SWAP + 1) << "ª altura é igual que a média e tem valor de " << alturas[SWAP] << endl;
                    }
                }

                cout << "Média das alturas: " << media << endl;
                cout << "\nQuantidade de alturas acima da média: " << contmediamaior << endl;
                cout << "\nQuantidade de alturas abaixo da média: " << contmediamenor << endl;
                cout << "\nQuantidade de alturas iguais a média: " << contmedia << endl;

                choice = 1; //Quest Menu

                break;

            case 5:
                //Exibição dos valores                
                cout << endl;
                for (SWAP = 0; SWAP < TAM; SWAP++) {
                    cout << "A altura " << (SWAP + 1) << "° valor é " << alturas[SWAP] << endl;
                }

                SWAP = 0;
                choice = 1; //Quest Menu

                break;
            case 6:
                //Análise referente ao uma altura especificada

                cout << "\nAnálise referente a uma altura especificada\n\n";

                //Busca por valores específicos

                cout << "Digite um valor de altura para ser analisado \n";
                cin >> altin;
                for (SWAP = 0; SWAP < TAM; SWAP++) {
                    if (alturas[SWAP] > altin) {
                        contmaioraltin++;
                    } else if (alturas[SWAP] < altin) {
                        contmenoraltin++;
                    } else if (alturas[SWAP] == altin) {
                        contaltin++;
                    }
                }


                cout << "Existem " << contmaioraltin << " alturas maiores que " << altin << endl;
                cout << "Existem " << contmenoraltin << " alturas menores que " << altin << endl;
                cout << "Existem " << contaltin << " alturas iguais que " << altin << endl;
                for (SWAP = 0; SWAP < TAM; SWAP++) {
                    if (alturas[SWAP] == altin) {
                        cout << "A primeira ocorrência da altura " << altin << " é na posição " << SWAP + 1 << endl;
                        break;
                    }
                }

                cout << "As posições de ocorrência dessa altura são:\n\n";
                for (SWAP = 0; SWAP < TAM; SWAP++) {
                    if (alturas[SWAP] == altin) {
                        cout << SWAP + 1 << "ª - " << altin << endl;
                    }
                }

                choice = 1; //Quest Menu

                break;
            case 6:
                //Análise por uma faixa de valores especificados
                cout << "\nAnálise por uma faixa de valores especificados\n";

                cout << "Digite o menor valor de altura para ser analisado: \n";
                cin >> menor;
                cout << "Digite o maior valor de altura para ser analisado: \n";
                cin >> maior;

                for (SWAP = 0; SWAP < TAM; SWAP++) {
                    if (alturas[SWAP] > maior) {
                        contmaior++;
                    } else if (alturas[SWAP] < menor) {
                        contmenor++;
                    } else if (alturas[SWAP] >= menor && alturas[SWAP] <= maior) {
                        contigual++;
                    }
                }
                cout << "Existem " << contmaior << " alturas maiores que " << maior << endl;
                cout << "Existem " << contmenor << " alturas menores que " << menor << endl;
                cout << "Existem " << contigual << " alturas entre " << menor << " e " << maior << endl;

                choice = 1; //Quest Menu

                break;
        }
    }
    return 0;
}

