/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 28 de março de 2025, 08:14
 */

#include <cstdlib>
#include <stdio.h>

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
 * Exemplo: Calcule a média de um grupo de pessoas. Finalize quando a altura for zero. No projeto, informe também qual a menor e qual a maior altura.
 * 
 * Obs:
 *      Configurado o programa para puxar as alturas das pessoas do arquivo entrada.txt.
 *      Para criar o arquivo entrada.txt, clique com o botão direito no projeto, depois clique em new, others, others de novo, e, lá no final da listagem, clique no arquivo empty e salve como <nome genérico>.txt
 *      Depois, para fazer com que o programa puxe os valores do arquivo criado, clique com o botão direito no projeto, depois em properties, depois na área Run, depois clique nos 3 pontinhos (...) em Run Command para editar esse comando.
 *      Adicione > <nome genérico>.txt e clique em Ok e Ok de novo.
 *      Agora seu programa vai puxar os valores desse arquivo ".txt" que criamos.
 * 
 */

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Variáveis / Dados
    float soma, media, altura, maior, menor;
    int quantpessoas, contpessoas, pessoamaior, pessoamenor;
    
    
    quantpessoas = 1;
    contpessoas = 0;
    soma = 0;
    menor = 10;
    maior = 0;
    
    printf("\nBem vindo a calculadora de media de alturas de um grupo de pessoas!\n");
    
    while(quantpessoas!=0){
        contpessoas = contpessoas + 1;
        printf("\nDigite a altura da %d° pessoa ou digite 0 para finalizar e calcular a média:\n",contpessoas);
        scanf("%f",&altura);
            while(altura<0 || altura >3){
                printf("\nValor inválido digitado");
                if(altura<0){
                    printf("\nNão existe pessoa com altura menor que 0");
                }
                if(altura>3){
                    printf("\nNão existe pessoa com altura maior que 3 metros");
                }
                printf("\nDigite novamente a altura da %d pessoa:\n",contpessoas);
                scanf("%f",&altura);
            }
            if(altura==0){
                contpessoas = contpessoas -1;
                quantpessoas = 0;
                //break; - podemos usar o break no lugar de quantpessoas = 0 para parar o while
            }else{
                soma = soma + altura;
                if(maior<altura){
                    maior = altura;
                    pessoamaior = contpessoas;
                    
                }else{
                    if(menor>altura){
                        menor = altura;
                        pessoamenor = contpessoas;
                    }
                }
            }
    }
    
    if(soma==0){
        printf("\nNenhuma altura digitada");
    }else{
        media = soma / contpessoas;
    
        printf("\nA média de alturas desse grupo de %d pessoas é %.2fm.\nA maior altura foi da %d° pessoa com %.2fm.\nA menor altura foi da %d° pessoa com %.2fm.",contpessoas,media,pessoamaior,maior,pessoamenor,menor);
    }

    return 0;
}