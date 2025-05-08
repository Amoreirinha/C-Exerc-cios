/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 8 de maio de 2025, 09:38
 * 
 * Joaquim Pedro
 * 
 * Código para gerar alturas para o projeto 1
 */

#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    float num;
    int quant, inf, max;
    
    ofstream alturas ("alturas.txt"); 
    
    if(!alturas.is_open()){
        cout<<"\nErro: Arquivo não encontrado.\n";
        return 1;
    }
    
    // Inicializa gerador de números aleatórios
    srand(time(NULL));

    cout << "Bem vindo ao gerador de números inteiros!" << endl << "Quantos números quer gerar?" << endl;
    cin >> quant;
    cout << "Qual o menor valor que quer gerar?" << endl;
    cin >> inf;
    cout << "Qual o maior valor que quer gerar?" << endl;
    cin >> max;
    
    srand(time(NULL));
    
    while(quant > 0){
        num = ((rand()%(max - inf + 1))+inf);
        alturas << num << endl;        
        quant--;
    }
    
    alturas << 0;
    
    alturas.close();
    
    return 0;
}

