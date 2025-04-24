/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 28 de março de 2025, 09:00
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
 * Exemplo: Faça um projeto para construir uma tabela que reacione graus celsius com graus farenheit. O intervalo será de 0 à 100°C, de 5 em 5°C
 */ 

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    float celsius, farenheit, kelvin;
    
    celsius = 0;
    
    printf("\nBem vindo a tabela de conversão de Celsius para Farenheit e Kelvin!\n\n\t-------------------------------------------\n\tCelsius(C°):\tFarenheit(F°):\tKenvil(K):\n\t-------------------------------------------\n");
    
    while(celsius<=100){
        farenheit = (celsius*(1.8))+32;
        kelvin = celsius + 273;
        printf("\t%.2f C°  \t%.2f F°\t%.2f K\n",celsius,farenheit,kelvin);
        celsius = celsius + 5;
    }
    printf("\t-------------------------------------------\n\n");
    return 0;
}

