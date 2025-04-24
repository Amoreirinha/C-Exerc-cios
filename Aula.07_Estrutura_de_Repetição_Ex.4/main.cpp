/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 28 de março de 2025, 09:13
 */

/*
 * Joaquim Pedro do Nascimento Moreira de Jesus - 2025.1.08.014
 * 28/03/2025
 * Tema: Repetições
 * 
 * while (condição){
 *      <Comandos>
 * 
 * }
 * 
 * Exemplo: Calcule a somatória abaixo:
 *      S = ((50-3)/2) + ((49-5)/3) + ((48-2)/4) + ... + ((2-99)/50)
 */ 

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    float soma, num1, num2, num3;
    
    soma = 0;
    num1 = 50;
    num2 = 3;
    num3 = 2;
    
    printf("\nCalculadora de somatoria constante!\nConta:\n");
    
    while(num3<=50){
        printf("S = %.2f + ((%.2f-%.2f)/%.2f)\n",soma,num1,num2,num3);
        soma = soma + ((num1-num2)/num3);
        num1 = num1-1;
        num2 = num2 + 2;
        num3 = num3 + 1;
    }
    
    printf("\n------------------------------------\n\tResultado\n\nA soma resultou em %.2f\n\n",soma);

    return 0;
}
 
