/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 14 de março de 2025, 09:04
 */

#include <cstdlib>
#include<stdio.h>
#include<string.h>


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    float altura,peso, imc;
    
    printf("\n\tCalculadora de IMC\n");
    printf("Informe sua altura(m):\n");
    scanf("%f",&altura);
    printf("Informe seu peso (kg):\n");
    scanf("%f",&peso);
    
    imc=peso/(altura*altura);
    
    if (18<=imc<25)/*poderia fazer a condicional como (imc>=18 && imc<25) ou (imc>=18 and imc<25)*/{
        printf("Você está dentro do IMC ideal");
    } else{
        if (imc<18){
        printf("Você está abaixo do IMC ideal");
        }else{
            printf("Vocês está acima do IMC ideal");
        }  
    }
            
    return 0;
}

