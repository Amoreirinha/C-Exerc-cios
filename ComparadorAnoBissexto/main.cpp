/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 21 de março de 2025, 08:04
 */

#include <cstdlib>
#include <stdio.h>

/*
4. O operador % em uma expressão aritmética retorna o resto da divisão entre dois números inteiros, por exemplo, 27 % 5 resulta no valor 2. Peça ao usuário um ano e determine se ele é bissexto. Um ano é bissexto se:
For divisível por 4 e não for divisível por 100, ou
For divisível por 400
Exemplo: 2024 é bissexto, mas 1900 não é.

Joaquim Pedro do Nascimento Moreira de Jesus
20/03/2025
2025.1.08.014
*/

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Variável / Dado
    int ano;

    //Entrada
    printf("\nBem vindo ao procurador de ano bissexto.\nFavor, digite o ano a ser considerado:\n");
    scanf("%d",&ano);

    //Processamento e Saída
    if(ano==0){
        printf("\nO ano %d não é bissexto",ano);
    }else{
        if(ano%4==0 && ano%100!=0 || ano%400==0){
            printf("\nO ano %d é bissexto",ano);
        }else{
            printf("\nO ano %d não é bissexto",ano);
        }
    }
    return 0;
}

