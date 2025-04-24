/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 11 de abril de 2025, 09:01
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
 * Exercício: Faça um projeto que gere a cena gráfica para o exercícios 2 da aula 10
 * 
 * Observação: Faça um menu de seleção para facilitar ao usuário
 *          Estrutura do arquivo de acordo com a figura geométrica
 * 
 * cubo Lado1
 * quadrado Lado1
 * círculo Raio
 * triângulo Lado1 Lado2 Lado3
 * cilindro Lado1 Raio
 * pentágono Lado1 Altura
 * paralelepipedo Lado1 Lado2 Lado3
 * hexágono Lado1
 * heptágono Lado1 Altura
 * octógono Lado1 Altura
 * trapézio Lado1 Lado2 Altura - considerando Lado1 e Lado2 a base maior e menor do trapézio
 * fim
 * 
 */

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string figura;
    float lad1, lad2, lad3, raio, altura, volume, area;
    int num, cont, cont3d, cont2d, choice;    
    
    cout << "\nBem-vindo ao gerador de figuras para cenografias.\nAs figuras possíveis são:\n\t1 - Cubo\n\t2 - Quadrado\n\t3 - Círculo\n\t4 - Triângulo\n\t5 - Cilindro\n\t6 - Pentágono\n\t7 - Paralelepipedo\n\t8 - Hexágono\n\t9 - Heptágono\n\t10 - Octógono\n\t11 - Trapézio\n\t12 - Gerar aleatoriamente\n\nDigite o número da figura que quer gerar:\n";
    cin >> choice;
    while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9 && choice != 10 && choice != 11){
        cout << "Valor inválido inserido!!\n\nAs figuras possíveis são:\n\t1 - Cubo\n\t2 - Quadrado\n\t3 - Círculo\n\t4 - Triângulo\n\t5 - Cilindro\n\t6 - Pentágono\n\t7 - Paralelepipedo\n\t8 - Hexágono\n\t9 - Heptágono\n\t10 - Octógono\n\t11 - Trapézio\n\t12 - Gerar aleatoriamente\n\nDigite o número da figura que quer gerar:\n";
        cin >> choice;
    }
    if(choice == 1){
        figura = "cubo";
    } else {
        if (choice == 2){
            figura = "quadrado";
        } else {
            if(choice == 3){
                figura = "círculo";
            } else {
                if(choice == 4){
                    figura = "triângulo";                    
                } else {
                    if(choice == 5){
                        figura = "cilindro";
                    } else {
                        if(choice == 6){
                            figura = "pentágono";
                        } else {
                            if(choice == 7){
                                figura = "paralelepipedo";
                            } else { 
                                if(choice == 8){
                                    figura = "hexágono";
                                } else { 
                                    if(choice == 9){
                                        figura = "heptágono";
                                    } else {
                                        if(choice == 10){
                                            figura = "octógono";
                                        } else {
                                            if(choice == 11){
                                                figura = "trapézio";
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "\nDigite a quantidade de " << figura << "s que deseja criar:\n";
    cin >> num;
    
    if(choice !=12){
        while(num > cont){
            cont = cont + 1;
            
        }
    }
    
    return 0;
}

