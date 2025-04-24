/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 21 de março de 2025, 08:13
 */

#include <cstdlib>
#include <stdio.h>

/*
 Exercício 1 - 21/03/2025
 Faça um projeto para informar qual o tipo de triângulo para 3 valores dados pelo usuário, correspondem aos tamanhos dos lados.
 Condicional:
    - Escaleno: 3 lados diferentes
    - Isósceles: 2 lados iguais
    - Equilátero: 3 lados iguais
 
 Joaquim Pedro do Nascimento Moreira de Jesus
 2025.1.08.014
 */

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Variáveis / Dados
    float lado1, lado2, lado3, hip, cateto1, cateto2;
    
    //Entrada
    printf("\nBem-vindo ao identificador de triângulos!\nDigite o valor do primeiro lado do triângulo:\n");
    scanf("%f",&lado1);
    printf("\nDigite o valor do segundo lado do triângulo:\n");
    scanf("%f",&lado2);
    printf("\nDigite o valor do terceiro lado do triângulo:\n");
    scanf("%f",&lado3);
    
    //Processamento e Saída

    //Verificando se os valores são maiores que zero e se é possível formar um triângulo com eles
    if (lado1+lado2 <=lado3 || lado1+lado3 <=lado2 || lado2+lado3 <= lado1 || lado1<=0 || lado2<=0 || lado3<=0 ){
        printf("Esse triângulo não é possível");
    }else{
        //Definindo quais dos lados são catetos e qual é a hipotenusa
        if(lado1>lado2 && lado1>lado3){
            hip = lado1*lado1;
            cateto1 = lado2*lado2;
            cateto2 = lado3*lado3;                
        }else{
            if(lado2>lado1 && lado2>lado3){
                hip = lado2*lado2;
                cateto1 = lado1*lado1;
                cateto2 = lado3*lado3;     
            }else{
                if(lado3>lado1 && lado3>lado2){
                    hip = lado3*lado3;
                    cateto1 = lado1*lado1;
                    cateto2 = lado2*lado2;  
                }
            }
        }
        //Teste de se é um triângulo Escaleno
        if(lado1!=lado2 && lado2!=lado3 && lado3!=lado1){
            printf("O triângulo com lados %.2f, %.2f e %.2f é Escaleno", lado1, lado2, lado3);
            //Testando se é um triângulo Escaleno e Retângulo
            if(cateto1+cateto2==hip){
                printf("\nO triângulo com lados %.2f, %.2f e %.2f também é um triângulo Retângulo", lado1, lado2, lado3);
            }
        }else{
            //Testando se é um Triângulo Isósceles
            if(lado1 == lado2 && lado1!=lado3 || lado2 == lado3 && lado3!=lado1 || lado1 == lado3 && lado3 != lado2){
                printf("O triângulo com lados %.2f, %.2f e %.2f é Isósceles", lado1, lado2, lado3);
                //Testando se é um triângulo Isósceles e Retângulo
                if(cateto1+cateto2==hip){
                    printf("\nO triângulo com lados %.2f, %.2f e %.2f também é um triângulo Retângulo", lado1, lado2, lado3);
                }
            //Se for um triângulo possível, que não é nem Escaleno e nem Isósceles, então é um Equilátero.    
            }else{
                printf("O triângulo com lados %.2f, %.2f e %.2f é Equilátero", lado1, lado2, lado3);
            }
        }
    }
     

    return 0;
}

