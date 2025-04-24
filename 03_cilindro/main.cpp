/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 13 de março de 2025, 08:46
 */

/*
 * Tema: IDE, Execução passo-a-passo. variáveis, atribuição, expressão, aritmética e constantes.
 * Exercício: Faça um programa para calcular a área total e o volume de um cilindro.
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    float raio, altura,area,volume,pi;
    char  um [3]; /*unidade de medida*/

    //raio = 0.8; /*= serve como comando de atribuição, atribuindo o valor 0.8 a variável raio. Diz que raio recebe valor de 0.8*/
    //altura = 5.5;
    
    printf("\nExercício Aula 3");
    printf("\nDigite o valor do raio:\n");
    scanf("%f", &raio);
    printf("\nDigite o valor da altura:\n");
    scanf("%f", &altura);
    printf("\nDigite a unidade de medida:\n");
    scanf("%s", &um);
    
    pi = 3.14159265359;
    area = 2*pi*(raio+altura);
    volume = pi*raio*raio*altura;        
        

    printf("\nCilindro de %.2f %s de raio e %.2f %s de altura",raio,um,altura,um);
    printf("\nO Volume do cilindro é %.2f e sua área total é %.2f",volume,area);

    return 0;
}

