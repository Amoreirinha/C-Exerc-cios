/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 20 de março de 2025, 08:33
 */

#include <cstdlib>
#include<stdio.h>
/*
 2. Peça ao usuário sua idade e classifique-a conforme as faixas etárias:

    Até 12 anos: "Criança"
    Entre 13 e 17 anos: "Adolescente"
    18 anos ou mais: "Adulto"
 
 Joaquim Pedro do Nascimento Moreira de Jesus
 20/03/2025
 2025.1.08.014
 */

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    //Variáveis / Dados
    int idade;
    
    //Entrada
    printf("\nBem-vindo ao classificador etário!\nDigite sua idade:\n");
    scanf("%d",&idade);
    
    //Processamento e Saída
    
    if (idade>=0 and idade<=12){
        printf("\nVocê é considerado Criança!");
    }else{
        if(idade>=13 and idade<=17){
           printf("\nVocê é considerado Adolescente"); 
        }else{
            if (idade>=18){
                printf("\nVocê é considerado Adulto"); 
            }else{
                printf("\nIdade Inválida"); 
            }
        }
    }

    return 0;
}

