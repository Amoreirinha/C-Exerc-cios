/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 20 de março de 2025, 08:21
 */

#include <cstdlib>
#include<stdio.h>

//Peça ao usuário dois números e exiba qual é o maior. Se forem iguais, informe isso ao usuário.
//Joaquim Pedro do Nascimento Moreira de Jesus
//20/03/2025
//2025.1.08.014

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    //Variáveis / Dados
    float num1,num2;
    
    //Entrada
    printf("\nBem-vindo ao comparador de números!\nDigite o valor do primeiro número a ser comparado:\n");
    scanf("%f",&num1);
    printf("\nDigite o valor do segundo número a ser comparado:\n");
    scanf("%f",&num2);
    
    //Processamento e Saída
    if (num1>num2){
        printf("\nO número %.2f é maior que %.2f",num1,num2);
    }else{
        if(num1<num2){
            printf("\nO número %.2f é maior que %.2f",num2,num1);
        }else{
            printf("\nOs números %.2f e %.2f são iguais",num2,num1);
        }
    }
        
    return 0;
}

