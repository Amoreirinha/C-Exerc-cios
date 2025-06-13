/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.006
 *
 * Created on 16 de maio de 2025, 08:06
 */

#include <cstdlib>
#include <stdio.h>
using namespace std;

/* Aula 15 - Vetores
 * Exercícios
 * -> Coloque o nome e sobrenome na variável nome completo, com espaço separando.
 * -> Em nome completo, transforme todos os caracteres para maiúsculas;
 * -> Em nome completo, com excessão das primeiras letras, transforme os caracteres em minúsculas
 * -> Remova todos os espaços de uma cadeia de caracteres
 * -> Retire a acentuação de uma cadeia de dígitos
 * -> Encontre um nome dentro de um nome completo
 * 
 */
int main(int argc, char** argv) {

    char nome[30], sobrenome[30], nomecompleto[60];
    int i = 0, j;

    nome[0] = 'G';
    nome[1] = 'a';
    nome[2] = 'b';
    nome[3] = 'r';
    nome[4] = 'i';
    nome[5] = 'e';
    nome[6] = 'l';
    nome[7] = 'a';
    nome[8] = '\0';


    sobrenome[0] = 'M';
    sobrenome[1] = 'a';
    sobrenome[2] = 'z';
    sobrenome[3] = 'o';
    sobrenome[4] = 'n';
    sobrenome[5] = ' ';
    sobrenome[6] = 'R';
    sobrenome[7] = 'a';
    sobrenome[8] = 'b';
    sobrenome[9] = 'e';
    sobrenome[10] = 'l';
    sobrenome[11] = 'l';
    sobrenome[12] = 'o';
    sobrenome[13] = ' ';
    sobrenome[14] = 'd';
    sobrenome[15] = 'e';
    sobrenome[16] = ' ';
    sobrenome[17] = 'S';
    sobrenome[18] = 'o';
    sobrenome[19] = 'u';
    sobrenome[20] = 'z';
    sobrenome[21] = 'a';
    sobrenome[22] = '\0';


    while (nome[i] != '\0') {
        nomecompleto[i] = nome[i];
        i++;
    }
    nomecompleto[i] = ' ';
    j = i + 1;
    i = 0;
    while (sobrenome[i] != '\0') {
        nomecompleto[j + i] = sobrenome[i];
        i++;
    }
    nomecompleto[j + i] = '\0';

    printf("\nNome: %s.\n", nome);
    printf("\nSobrenome: %s.\n", sobrenome);
    printf("\nNome Completo: %s.\n", nomecompleto);

    i = 0;
    while (nomecompleto[i] != '\0') {
        if (
                nomecompleto[i] >= 97 &&
                nomecompleto[i] <= 122 &&
                nomecompleto[i] != ' ' &&
                nomecompleto[i] != '.'
                ) {
            nomecompleto[i] = nomecompleto[i] - 32;
        }
        i++;
    }

    printf("Nome Completo Maíusculo: %s.\n", nomecompleto);

    i = 0;
    while (nomecompleto[i] != '\0') {
        if (
                nomecompleto[i] >= 65 &&
                nomecompleto[i] <= 90 &&
                nomecompleto[i] != ' ' &&
                nomecompleto[i] != '.'
                ) {
            nomecompleto[i] = nomecompleto[i] + 32;
        }
        i++;
    }

    printf("Nome Completo Minúsculo: %s.\n", nomecompleto);

    i = 0;
    nomecompleto[i] = nomecompleto[i] - 32;
    i++;
    while (nomecompleto[i] != '\0') {
        if (nomecompleto[i] == ' ') {
            nomecompleto[i + 1] = nomecompleto[i + 1] - 32;
        }
        i++;
    }

    printf("Nome Completo com as Primeiras letras Maiúsculas: %s.\n", nomecompleto);

    i = 0;
    while (nomecompleto[i] != '\0') {
        if (nomecompleto[i] == ' ') {
            j = i;
            while (nomecompleto[j] != '\0') {
                nomecompleto[j] = nomecompleto[j + 1];
                j++;
            }
        } else {
            i++;
        }
    }
    printf("Nome Completo sem Espaço: %s.\n", nomecompleto);


    char cpf[20], celular[20];

    cpf[0] = '1';
    cpf[1] = '2';
    cpf[2] = '3';
    cpf[3] = '.';
    cpf[4] = '4';
    cpf[5] = '5';
    cpf[6] = '6';
    cpf[7] = '.';
    cpf[8] = '7';
    cpf[9] = '8';
    cpf[10] = '9';
    cpf[11] = '-';
    cpf[12] = '0';
    cpf[13] = '1';
    printf("CPF: %s.\n", cpf);

    celular[0] = '(';
    celular[1] = '0';
    celular[2] = '3';
    celular[3] = '5';
    celular[4] = ')';
    celular[5] = '9';
    celular[6] = '9';
    celular[7] = '9';
    celular[8] = '9';
    celular[9] = '9';
    celular[10] = '-';
    celular[11] = '1';
    celular[12] = '2';
    celular[13] = '3';
    celular[14] = '4';
    printf("Celular: %s.\n", celular);

    i = 0;
    while (cpf[i] != '\0') {
        if (cpf[i] >= 32 && cpf[i] <= 47) {
            j = i;
            while (cpf[j] != '\0') {
                cpf[j] = cpf[j + 1];
                j++;
            }
        } else {
            i++;
        }
    }

    printf("CPF sem caractéres especiais: %s\n", cpf);

    i = 0;
    while (celular[i] != '\0') {
        if (celular[i] >= 32 && celular[i] <= 47) {
            j = i;
            while (celular[j] != '\0') {
                celular[j] = celular[j + 1];
                j++;
            }
        } else {
            i++;
        }
    }

    printf("Celular sem caractéres especiais: %s\n", celular);

// Parte para procurar um nome dentro do nome completo
char nomeProcurado[31];
int encontrou = 0; 

printf("\nDigite um nome para procurar no nome completo: ");
scanf("%30s", nomeProcurado);

if(nomeProcurado[0] >= 'a' && nomeProcurado[0] <= 'z') {
    nomeProcurado[0] -= 32;
}
i = 0;
while(nomecompleto[i] != '\0') {
    j = 0;
    while(nomeProcurado[j] != '\0' && nomecompleto[i + j] != '\0' && 
           nomeProcurado[j] == nomecompleto[i + j]) {
        j++;
    }
    
    if(nomeProcurado[j] == '\0') {
        encontrou = 1;
        break;
    }
    i++;
}

if(encontrou) {
    printf("O nome '%s' foi encontrado no nome completo!\n", nomeProcurado);
}else {
    printf("O nome '%s' NAO foi encontrado no nome completo.\n", nomeProcurado);
}
   return 0;
}
