/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 4 de abril de 2025, 08:49
 */
/*
 * Joaquim Pedro do Nascimento Moreira de Jesus
 * 2025.1.08.014
 * 04/04/2025
 * AED's Prática
 * 
 * Tema: Geração de Números Aleatórios
 * 
 * Exercício: Faça um projeto para gerar n alturas entre 1.50 e 2.30
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
    int quant, cont;
    float alturas;
    
    cont = 1;
    
    srand(time(NULL));
    
    cout << "Bem vindo ao gerador de alturas!" << endl << "Esse gerador lhe dará alturas entre 1,50 e 2,30." << endl << "Quantas alturas quer gerar?" << endl;
    cin >> quant;
    
    
    while (quant > 0){
        alturas = ((rand() % 81) + 150) * 0.01;
        cout << cont << "°: " << alturas << " m" << endl;
        quant = quant - 1;
        cont = cont + 1;
    }
    
    
    return 0;
}

