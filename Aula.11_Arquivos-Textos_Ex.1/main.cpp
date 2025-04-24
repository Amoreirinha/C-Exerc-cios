/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 11 de abril de 2025, 08:18
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string.h>
#include <time.h> 

/*
 * Joaquim Pedro do Nascimento Moreira de Jesus - 2025.1.08.014
 * 11/04/2025
 * 
 * Tema: arquivos - texto
 * 
 * ifstream arquivo ("entrada.txt");
 * i - input
 * f - file
 * stream - fluxo de caracteres
 * arquivo - vatiável
 * ("entrada.txt") - caminho
 * entrada.txt - nome do arquivo nos diretórios
 * 
 * ofstream arquivo1 ("saida.txt");
 * o - output
 * f - file
 * stream - fluxo de caracteres
 * ("saida.txt") - caminho
 * saida.txt - nome do arquivo nos diretórios
 * 
 * arquivo >> figura;
 * arquivo - de onde vem
 * >> - operador de fluxo de caracteres
 * figura - variável
 * 
 * arquivo1 << numero;
 * arquivo1 - para onde vai
 * << - operador de fluxo de caracteres
 * numero - variável
 * 
 * 
 * Exercício: Faça um projeto que gere números aleatórios inteiros, onde o usuário informa a quantidade, o limite e o superior.
 * 
 * Observação: 
 * 
 */

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int num,inf,max,quant, cont;
    ofstream arquivo ("saida.txt");
    
    if(!arquivo.is_open()){
        cout<<"\nErro: Arquivo não encontrado.\n";
        return 1;
    }
    
    cont = 0;
    
    cout << "Bem vindo ao gerador de números inteiros!" << endl << "Quantos números quer gerar?" << endl;
    cin >> quant;
    cout << "Qual o menor valor que quer gerar?" << endl;
    cin >> inf;
    cout << "Qual o maior valor que quer gerar?" << endl;
    cin >> max;
    
    srand(time(NULL));
    
    while(quant > cont){
        num = ((rand()%(max - inf + 1))+inf);
        cont = cont + 1;
        arquivo << cont << "°: " << num << endl;
    }
    
    arquivo.close();
    
    return 0;
}

