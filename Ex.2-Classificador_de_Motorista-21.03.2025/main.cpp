/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 21 de março de 2025, 09:27
 */

#include <cstdlib>
#include <stdio.h>
/*
 Exercício 2 - 21/03/2025
 Desenvolva um algoritmo que classifica um motorista com base em sua idade, tempo de habilitação e histórico de infrações. A classificação segue estas regras:

1. Motorista Inexperiente:

    Idade menor que 18 anos.
    Ou idade entre 18 e 21 anos e menos de 2 anos de habilitação.

2. Motorista Regular:

    Idade entre 22 e 65 anos.
    Possui 2 anos ou mais de habilitação.
    E não possui infrações graves nos últimos 2 anos.

3. Motorista de Risco:

    Qualquer idade acima de 21 anos, mas com infrações graves nos últimos 2 anos.
    Ou idade maior que 65 anos.

4. Motorista Seguro:

    Idade entre 30 e 60 anos.
    Possui mais de 5 anos de habilitação.
    Nenhuma infração nos últimos 5 anos.

O programa deve receber:

    Idade do motorista
    Anos de habilitação
    Número de infrações nos últimos 5 anos
    Número de infrações graves nos últimos 2 anos

Exemplo de Entrada:
Idade: 28  
Anos de habilitação: 6  
Infrações nos últimos 5 anos: 4  
Infrações graves nos últimos 2 anos: 1  

Saída esperada:
Classificação: Motorista de Risco

Joaquim Pedro do Nascimento Moreira de Jesus
2025.1.08.014
 */

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    //Variáveis / Dados
    int idade, ano, infra5, infra2;
    
    //Entrada
    printf("\nBem-vindo ao classificador de motorista!\nEste programa tem a finalidade de definir os motoristas nas seguintes classificações:\n\t1. Motorista Inexperiente\n\t2.Motorista Regular\n\t3.Motorista de Risco\n\t4.Motorista Seguro\n\nPrecisamos de algumas informações para realizar a classificação.\nDigite a idade do motorista:\n");
    scanf("%d",&idade);
    printf("\nDigite quantos anos o motorista está habilitado:\n");
    scanf("%d",&ano);
    printf("\nDigite quantas infrações o motorista fez nos últimos 5 anos:\n");
    scanf("%d",&infra5); 
    printf("\nDigite quantas infrações o motorista fez nos últimos 2 anos:\n");
    scanf("%d",&infra2);
    
    //Processamento e Saída
    
    
    
    return 0;
}

