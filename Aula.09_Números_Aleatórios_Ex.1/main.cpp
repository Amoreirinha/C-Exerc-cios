/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 4 de abril de 2025, 08:07
 */
/*
 * Joaquim Pedro do Nascimento Moreira de Jesus
 * 2025.1.08.014
 * 04/04/2025
 * AED's Prática
 * 
 * Tema: Geração de Números Aleatórios
 * 
 */

#include <cstdlib>
#include <time.h> // Biblioteca para geração de números aleatórios
#include <iostream> //Biblioteca de comando de entrada e saída (tal qual stdio.h)

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int segredo, chute;

    cout << "Número Aleatório" << endl; //endl - Final de linha | "" - Mensagem | cout - comando para printar | << - Operador
    srand(time(NULL)); // srand - Inicializa o gerador de números aleatórios com uma semente baseada no tempo atual. Não precisa repetir ele no código. Uma vez no início do código já é o suficiente

    segredo = rand() % 100; // Gera um número aleatório entre 0 e 99 e armazena em segredo

    cout << "Um número foi gerado entre 1 e 99." <<endl;
    
    cout << "Qual é este valor?" << endl;
    
    cin >> chute;

    return 0;
}

