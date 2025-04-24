/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 27 de março de 2025, 08:14
 */

#include <cstdlib>
#include <stdio.h>

/*
 * Joaquim Pedro do Nascimento Moreira de Jesus - 2025.1.08.014
 * 27/03/2025
 * Tema: Repetições
 * 
 * while (condição){
 *      <Comandos>
 * 
 * }
 * 
 * Exemplo: Calcular a média de alturas de um grupo de 10 pessoas.
 * 
 * Obs:
 *      Configurado o programa para puxar as alturas das pessoas do arquivo entrada.txt.
 *      Para criar o arquivo entrada.txt, clique com o botão direito no projeto, depois clique em new, others, others de novo, e, lá no final da listagem, clique no arquivo empty e salve como <nome genérico>.txt
 *      Depois, para fazer com que o programa puxe os valores do arquivo criado, clique com o botão direito no projeto, depois em properties, depois na área Run, depois clique nos 3 pontinhos (...) em Run Command para editar esse comando.
 *      Adicione > <nome genérico>.txt e clique em Ok e Ok de novo.
 *      Agora seu programa vai puxar os valores desse arquivo ".txt" que criamos.
 */

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    float soma, media, altura;
    int quantpessoas, contpessoas;
    
    quantpessoas = 10;
    contpessoas = 0;
    soma = 0;
    
    printf("\nBem vindo a calculadora de media de alturas de um grupo de 10 pessoas!\n");
    
    while(quantpessoas>0){
        contpessoas = contpessoas + 1;
        printf("\nDigite a altura da %d° pessoa:\n",contpessoas);
        scanf("%f",&altura);
        if(altura<=0 || altura>3){
            printf("Valor inválido para altura, digite novamente");
            contpessoas = contpessoas -1;
        }else{
            soma = soma + altura;
            quantpessoas = quantpessoas -1;
        }
    }
    
    quantpessoas = contpessoas;
    media = soma / quantpessoas;
    
    printf("\nA média de alturas desse grupo de 10 pessoas é %.2fm",media);
    
    return 0;
}

