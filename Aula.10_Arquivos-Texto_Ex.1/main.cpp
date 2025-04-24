/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 10 de abril de 2025, 08:14
 */

#include <cstdlib>
#include <fstream>
#include <iostream>

/*
 * Joaquim Pedro do Nascimento Moreira de Jesus - 2025.1.08.014
 * 10/04/2025
 * Tema: Arquivos-texto
 * }
 * 
 * Exemplo: Calcule a média de um grupo de pessoas. Finalize quando a altura for zero. No projeto, informe também qual a menor e qual a maior altura.
 * 
 * Obs:
 *      
 * 
 */

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Variáveis / Dados
    float soma, media, altura, maior, menor;
    int quantpessoas, contpessoas, pessoamaior, pessoamenor;
    ifstream arquivo("entrada.txt");
    
    if(!arquivo.is_open()){
        cout<<"\nErro: Arquivo não encontrado.\n";
        return 1; //Único momento onde podemos usar o return 1, significa que aconteceu um erro
    }
    
    quantpessoas = 1;
    contpessoas = 0;
    soma = 0;
    
    cout << "\nBem vindo a calculadora de media de alturas de um grupo de pessoas!\n";
    contpessoas = contpessoas + 1;
    cout << "\nDigite a altura da " << contpessoas << " pessoa ou digite 0 para finalizar e calcular a média:\n";
    arquivo >> altura;
    while(altura<0 || altura >3){
                cout << "\nValor inválido digitado";
                if(altura<0){
                    cout << "\nNão existe pessoa com altura menor que 0";
                }
                if(altura>3){
                    cout << "\nNão existe pessoa com altura maior que 3 metros";
                }
                cout << "\nDigite novamente a altura da " << contpessoas << " pessoa:\n";
                arquivo >> altura;
    }
    if(altura==0){
        contpessoas = contpessoas -1;
        quantpessoas = 0;
        //break; - podemos usar o break no lugar de quantpessoas = 0 para parar o while
    }else{
        soma = soma + altura;
            maior = altura;
            pessoamaior = contpessoas;
            menor = altura;
            pessoamenor = contpessoas;
    }
    
    while(quantpessoas!=0){
        contpessoas = contpessoas + 1;
        cout << "\nDigite a altura da "<< contpessoas <<"° pessoa ou digite 0 para finalizar e calcular a média:\n";
        arquivo >> altura;
            while(altura<0 || altura >3){
                cout << "\nValor inválido digitado";
                if(altura<0){
                    cout << "\nNão existe pessoa com altura menor que 0";
                }
                if(altura>3){
                    cout << "\nNão existe pessoa com altura maior que 3 metros";
                }
                cout << "\nDigite novamente a altura da "<< contpessoas <<" pessoa:\n";
                arquivo >> altura;
            }
            if(altura==0){
                contpessoas = contpessoas -1;
                quantpessoas = 0;
                //break; - podemos usar o break no lugar de quantpessoas = 0 para parar o while
            }else{
                soma = soma + altura;
                if(maior<altura){
                    maior = altura;
                    pessoamaior = contpessoas;
                    
                }else{
                    if(menor>altura){
                        menor = altura;
                        pessoamenor = contpessoas;
                    }
                }
            }
    }
    
    if(soma==0){
        cout << "\nNenhuma altura digitada";
    }else{
        media = soma / contpessoas;
    
        cout << "\nA média de alturas desse grupo de " << contpessoas << " pessoas é "<< media <<".\nA maior altura foi da "<< pessoamaior << "° pessoa com " << maior << ".\nA menor altura foi da " << pessoamenor << "° pessoa com "<< menor <<".";
    }

    return 0;
}