/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 8 de maio de 2025, 08:10
 * 
 * Joaquim Pedro
 * 
 * Tema: Vetores
 *       (Variável Composta Unidimensional Homogênea)
 * 
 * Problema: como calcular quantos valores estão acima da média de N alturas?
 * 
 * 1° ler valores, contar e somar as alturas e calcular a média
 * 
 * 2° ler valores para contar quais estão acima da média
 * 
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    ifstream arquivo_alturas ("alturas.txt"); 
    
    if(!arquivo_alturas.is_open()){
        cout<<"\nErro: Arquivo não encontrado.\n";
        return 1;
    }
    
    // Declaração do vetor
    vector<float> alturas; // Vetor dinâmico
    vector<float> acimamedias;

    // Declaração e inicialização de variáveis
    float soma = 0, media, valor, altin;
    int contmedia = 0, contmaioraltin = 0, contaltin = 0, contmenoraltin = 0;

    // Leitura dos valores
    while (true) {        
        arquivo_alturas >> valor;

        if (valor == 0) {
            break;
        }

        alturas.push_back(valor); // Adiciona o valor ao vetor
        soma += valor;
    }

    // Exibição dos valores lidos
    for (int i = 0; i < alturas.size(); i++) {
        cout << "A altura " << (i + 1) << "° valor é " << alturas[i] << endl;
    }
    
    //Media
    media = soma / alturas.size();

    // Contagem de valores acima da média
    for (float altura : alturas) {
        if (altura > media) {
            contmedia++;
            acimamedias.push_back(altura); 
        }
    }
    
    //Busca por valores específicos
    cout << "Digite um valor de altura para ser analisado \n";
    cin >> altin;
    for (float altura : alturas) {
        if (altura > altin) {
            contmaioraltin++;
        } else if (altura < altin){
            contmenoraltin++;
        } else {
            contaltin;
        }
    }
    cout << "Média das alturas: " << media << endl;
    cout << "Quantidade de valores acima da média: " << contmedia << endl << endl;
    for (int i = 0; i < acimamedias.size(); i++) {
        cout << "A " << (i + 1) << "ª altura maior que a média tem valor " << acimamedias[i] << endl;
    }
       
    cout << "Existem " << contmaioraltin << " alturas maiores que " << altin << endl;
    cout << "Existem " << contmenoraltin << " alturas menores que " << altin << endl;
    cout << "Existem " << contaltin << " alturas iguais que " << altin << endl;
    
    

    return 0;
}

