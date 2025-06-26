/*
Projeto: Biblioteca de Operações em Matrizes

Objetivo:
Implementar uma biblioteca em C++ para operações com matrizes usando ponteiros.

Descrição:
A biblioteca deve ter:

Um arquivo .H (cabeçalho) com as assinaturas das funções

Um arquivo .CPP (implementação) com os corpos das funções

Definições:

const int TAM = 128;
typedef int Vetor[TAM][TAM];

Regras:

Usar apenas TAM e Vetor para matrizes e parâmetros

Não usar índices – só ponteiros para acessar elementos

Operações:

Multiplicar matriz por um valor (escalar)

Calcular matriz transposta

Inverter colunas (horizontal: primeira ↔ última, segunda ↔ penúltima, etc.)

Inverter linhas (vertical: primeira ↔ última, segunda ↔ penúltima, etc.)

Joaquim Pedro do Nascimento Moreira de Jesus
Atividade 05 - Matrizes

*/

#include <cstdlib>             // Para usar a função system()
#include <stdio.h>             // Para usar a função printf()
#include <iostream>            // Para usar a biblioteca padrão de entrada e saída
#include <string.h>            // Para usar strings e manipulação de strings
#include "MatricesFunctions.h" // Inclui o cabeçalho com as funções de ordenação e listagem

using namespace std;

int main(){
    const int TAM = 5;
    typedef int Vetor[TAM][TAM];
    Vetor matriz;
    Vetor matriz_multiplicada;
    Vetor transposta;
    Vetor coluna_inversa;
    Vetor linha_inversa;
    string voltar;
    int choice = 0;
    int valor;
    bool loop = true;

    geramatriz(&matriz[0][0], TAM); // Gera a matriz com valores aleatórios

    while (loop){
        switch (choice){
        case 0:
            limpartela(); // Limpa a tela do terminal
            setColor(1, 34); // Define a cor do texto para azul
            cout << "Escolha uma operação:" << endl << endl;
            resetColor(); // Reseta a cor do texto para o padrão
            cout << "1. Multiplicar matriz por um valor" << endl;
            cout << "2. Calcular matriz transposta" << endl;
            cout << "3. Inverter colunas" << endl;
            cout << "4. Inverter linhas" << endl;
            cout << "5. Mostrar matriz" << endl;
            cout << "6. Sair" << endl;
            cout << "Digite o número da opção desejada: ";
            cin >> choice;
            while (choice < 1 || choice > 6)
            {   
                setColor(1, 31); // Define a cor do texto para vermelho
                cout << "Opção inválida! Tente novamente." << endl;
                resetColor(); // Reseta a cor do texto para o padrão
                cout << "Digite o número da opção desejada: ";
                cin >> choice;
            }
            choice++;
            break;

        case 1:
            voltar = "x"; // Inicializa a variável voltar com um valor diferente de 's' ou 'n'
            cout << "Deseja voltar ao menu? Digite 's' para SIM e 'n' para NÃO: ";
            cin >> voltar;
            while (voltar != "s" && voltar != "n"){
                setColor(1, 31); // Define a cor do texto para vermelho
                cout << "Opção inválida! Digite 's' para voltar ao menu ou 'n' para sair: ";
                resetColor(); // Reseta a cor do texto para o padrão
                cin >> voltar;
            }
            if(voltar == "s"){
                choice = 0; // Volta ao menu principal
            } else {
                loop = false; // Sai do loop
            }
            voltar = "x";
            break;

        case 2:
            limpartela(); // Limpa a tela do terminal
            setColor(1, 34); // Define a cor do texto para azul
            cout << "Multiplicar matriz por um valor" << endl;
            resetColor(); // Reseta a cor do texto para o padrão
            cout << "Digite o valor pelo qual deseja multiplicar a matriz: ";
            cin >> valor;
            multiplicamatriz(&matriz[0][0], &matriz_multiplicada[0][0], TAM, valor); // Multiplica a matriz pelo valor
            setColor(1, 32); // Define a cor do texto para verde
            cout << "\nMatriz original:" << endl;
            resetColor(); // Reseta a cor do texto para o padrão
            mostramatriz(&matriz[0][0], TAM); // Mostra a matriz original
            setColor(1, 32); // Define a cor do texto para verde
            cout << "\nMatriz após multiplicação:" << endl;
            resetColor(); // Reseta a cor do texto para o padrão
            mostramatriz(&matriz_multiplicada[0][0], TAM); // Mostra a matriz após multiplicação

            voltar = "x"; // Inicializa a variável voltar com um valor diferente de 's' ou 'n'
            cout << "\n\nDeseja salvar a matriz multiplicada na matriz original? (s/n): ";
            cin >> voltar; // Pergunta se o usuário deseja salvar a matriz multiplicada
            while(voltar != "s" && voltar != "n"){
                setColor(1, 31); // Define a cor do texto para vermelho
                cout << "Opção inválida! Digite 's' para salvar ou 'n' para não salvar: ";
                resetColor(); // Reseta a cor do texto para o padrão
                cin >> voltar; // Lê a resposta do usuário
            }
            if(voltar == "s"){
                salvamatriz(&matriz[0][0], &matriz_multiplicada[0][0], TAM); // Salva a matriz multiplicada
            }
            voltar = "x"; // Reseta a variável voltar

            choice = 1; // Vai para o quest menu
        break;

        case 3:
            limpartela(); // Limpa a tela do terminal
            setColor(1, 34); // Define a cor do texto para azul
            cout << "Matriz Transposta" << endl;
            resetColor(); // Reseta a cor do texto para o padrão
            transposamatriz(&matriz[0][0], &transposta[0][0], TAM); // Calcula a matriz transposta
            setColor(1, 32); // Define a cor do texto para verde
            cout << "\nMatriz original:" << endl;
            resetColor(); // Reseta a cor do texto para o padrão
            mostramatriz(&matriz[0][0], TAM); // Mostra a matriz original
            setColor(1, 32); // Define a cor do texto para verde
            cout << "\nMatriz transposta:" << endl;
            resetColor(); // Reseta a cor do texto para o padrão
            mostramatriz(&transposta[0][0], TAM); // Mostra a matriz transposta

            voltar = "x"; // Inicializa a variável voltar com um valor diferente de 's' ou 'n'
            cout << "\n\nDeseja salvar a matriz transposta na matriz original? (s/n): ";
            cin >> voltar; // Pergunta se o usuário deseja salvar a matriz transposta
            while(voltar != "s" && voltar != "n"){
                setColor(1, 31); // Define a cor do texto para vermelho
                cout << "Opção inválida! Digite 's' para salvar ou 'n' para não salvar: ";
                resetColor(); // Reseta a cor do texto para o padrão
                cin >> voltar; // Lê a resposta do usuário
            }
            if(voltar == "s"){
                salvamatriz(&matriz[0][0], &transposta[0][0], TAM); // Salva a matriz transposta
            }
            voltar = "x"; // Reseta a variável voltar
    
            choice = 1; // Vai para o quest menu
        break;

        case 4:
            limpartela(); // Limpa a tela do terminal
            setColor(1, 34); // Define a cor do texto para azul
            cout << "Inverter colunas" << endl;
            resetColor(); // Reseta a cor do texto para o padrão
            invertercolunas(&matriz[0][0], &coluna_inversa[0][0], TAM); // Inverte as colunas da matriz
            setColor(1, 32); // Define a cor do texto para verde
            cout << "\nMatriz original:" << endl;
            resetColor(); // Reseta a cor do texto para o padrão
            mostramatriz(&matriz[0][0], TAM); // Mostra a matriz original
            setColor(1, 32); // Define a cor do texto para verde
            cout << "\nMatriz após inverter colunas:" << endl;
            resetColor(); // Reseta a cor do texto para o padrão
            mostramatriz(&coluna_inversa[0][0], TAM); // Mostra a matriz após inverter colunas

            voltar = "x"; // Inicializa a variável voltar com um valor diferente de 's' ou 'n'
            cout << "\n\nDeseja salvar a matriz com colunas inversas na matriz original? (s/n): ";
            cin >> voltar; // Pergunta se o usuário deseja salvar a matriz com colunas inversas
            while(voltar != "s" && voltar != "n"){
                setColor(1, 31); // Define a cor do texto para vermelho
                cout << "Opção inválida! Digite 's' para salvar ou 'n' para não salvar: ";
                resetColor(); // Reseta a cor do texto para o padrão
                cin >> voltar; // Lê a resposta do usuário
            }
            if(voltar == "s"){
                salvamatriz(&matriz[0][0], &coluna_inversa[0][0], TAM); // Salva a matriz com colunas inversas
            }
            voltar = "x"; // Reseta a variável voltar

            choice = 1; // Vai para o quest menu
        break;

        case 5:
            limpartela(); // Limpa a tela do terminal
            setColor(1, 34); // Define a cor do texto para azul
            cout << "Inverter linhas" << endl;
            resetColor(); // Reseta a cor do texto para o padrão
            inverterlinhas(&matriz[0][0], &linha_inversa[0][0], TAM); // Inverte as linhas da matriz
            setColor(1, 32); // Define a cor do texto para verde
            cout << "\nMatriz original:" << endl;
            resetColor(); // Reseta a cor do texto para o padrão
            mostramatriz(&matriz[0][0], TAM); // Mostra a matriz original
            setColor(1, 32); // Define a cor do texto para verde
            cout << "\nMatriz após inverter linhas:" << endl;
            resetColor(); // Reseta a cor do texto para o padrão
            mostramatriz(&linha_inversa[0][0], TAM); // Mostra a matriz após inverter linhas

            voltar = "x"; // Inicializa a variável voltar com um valor diferente de 's' ou 'n'
            cout << "\n\nDeseja salvar a matriz com linhas inversas na matriz original? (s/n): ";
            cin >> voltar; // Pergunta se o usuário deseja salvar a matriz com linhas inversas
            while(voltar != "s" && voltar != "n"){
                setColor(1, 31); // Define a cor do texto para vermelho
                cout << "Opção inválida! Digite 's' para salvar ou 'n' para não salvar: ";
                resetColor(); // Reseta a cor do texto para o padrão
                cin >> voltar; // Lê a resposta do usuário
            }
            if(voltar == "s"){
                salvamatriz(&matriz[0][0], &linha_inversa[0][0], TAM); // Salva a matriz com linhas inversas
            }
            voltar = "x"; // Reseta a variável voltar

            choice = 1; // Vai para o quest menu
        break;

        case 6:
            limpartela(); // Limpa a tela do terminal
            setColor(1, 34); // Define a cor do texto para azul
            cout << "Matriz:" << endl;
            resetColor(); // Reseta a cor do texto para o padrão
            mostramatriz(&matriz[0][0], TAM); // Mostra a matriz original
            choice = 1; // Vai para o quest menu
        break;

        case 7:
            loop = false; // Sai do loop
        break;

        }
    }

    setColor(1, 31); // Define a cor do texto para vermelho
    cout << "Saindo do programa..." << endl;
    resetColor(); // Reseta a cor do texto para o padrão

    return 0;
}