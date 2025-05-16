/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 16 de maio de 2025, 08:15
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char nome[31], sobrenome[31], nomecompleto[62];
    int i = 0, j;

    nome[0] = 'J';
    nome[1] = 'o';
    nome[2] = 'a';
    nome[3] = 'q';
    nome[4] = 'u';
    nome[5] = 'i';
    nome[6] = 'm';
    nome[7] = '\0';

    printf("Nome: %s.\n", nome);

    sobrenome[0] = 'P';
    sobrenome[1] = 'e';
    sobrenome[2] = 'd';
    sobrenome[3] = 'r';
    sobrenome[4] = 'o';
    sobrenome[5] = ' ';
    sobrenome[6] = 'd';
    sobrenome[7] = 'o';
    sobrenome[8] = ' ';
    sobrenome[9] = 'N';
    sobrenome[10] = '.';
    sobrenome[11] = ' ';
    sobrenome[12] = 'M';
    sobrenome[13] = '.';
    sobrenome[14] = ' ';
    sobrenome[15] = 'd';
    sobrenome[16] = 'e';
    sobrenome[17] = ' ';
    sobrenome[18] = 'J';
    sobrenome[19] = 'e';
    sobrenome[20] = 's';
    sobrenome[21] = 'u';
    sobrenome[22] = 's';
    sobrenome[23] = '\0';

    printf("Sobrenome: %s.\n", sobrenome);

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

    printf("Nome Completo: %s.\n", nomecompleto);

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

    printf("Nome Completo Maiúsculo: %s.\n", nomecompleto);

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

    printf("Nome Completo Primeiras letras Maiúsculo: %s.\n", nomecompleto);

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

    printf("Nome Completo sem espaços: %s.\n", nomecompleto);

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
    cpf[14] = '\0';

    printf("CPF: %s\n", cpf);

    celular[0] = '(';
    celular[1] = '3';
    celular[2] = '9';
    celular[3] = ')';
    celular[4] = ' ';
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
    celular[15] = '\0';

    printf("Celular: %s\n", celular);

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

    char DNA[100];
    
    DNA[0] = 'G';
    DNA[1] = 'A';
    DNA[2] = 'T';
    DNA[3] = 'C';
    DNA[4] = 'G';
    DNA[5] = 'A';
    DNA[6] = 'A';
    DNA[7] = 'T';
    DNA[8] = 'C';
    DNA[9] = 'G';
    DNA[10] = 'T';
    DNA[11] = 'A';
    DNA[12] = 'C';
    DNA[13] = 'C';
    DNA[14] = 'G';
    DNA[15] = 'T';
    DNA[16] = 'T';
    DNA[17] = 'A';
    DNA[18] = 'G';
    DNA[19] = 'C';
    DNA[20] = 'A';
    DNA[21] = 'T';
    DNA[22] = 'G';
    DNA[23] = 'C';
    DNA[24] = 'A';
    DNA[25] = 'A';
    DNA[26] = 'T';
    DNA[27] = 'T';
    DNA[28] = 'G';
    DNA[29] = 'C';
    DNA[30] = 'A';
    DNA[31] = 'G';
    DNA[32] = 'T';
    DNA[33] = 'C';
    DNA[34] = 'A';
    DNA[35] = 'T';
    DNA[36] = 'G';
    DNA[37] = 'A';
    DNA[38] = 'C';
    DNA[39] = 'T';
    DNA[40] = 'G';
    DNA[41] = 'A';
    DNA[42] = 'C';
    DNA[43] = 'T';
    DNA[44] = 'G';
    DNA[45] = 'A';
    DNA[46] = 'T';
    DNA[47] = 'C';
    DNA[48] = 'G';
    DNA[49] = 'A';
    DNA[50] = 'T';
    DNA[51] = 'C';
    DNA[52] = 'G';
    DNA[53] = 'A';
    DNA[54] = 'T';
    DNA[55] = 'C';
    DNA[56] = 'G';
    DNA[57] = 'A';
    DNA[58] = 'T';
    DNA[59] = 'C';
    DNA[60] = 'G';
    DNA[61] = 'A';
    DNA[62] = 'T';
    DNA[63] = 'C';
    DNA[64] = 'G';
    DNA[65] = 'A';
    DNA[66] = 'T';
    DNA[67] = 'C';
    DNA[68] = 'G';
    DNA[69] = 'A';
    DNA[70] = 'T';
    DNA[71] = 'C';
    DNA[72] = 'G';
    DNA[73] = 'A';
    DNA[74] = 'T';
    DNA[75] = 'C';
    DNA[76] = 'G';
    DNA[77] = 'A';
    DNA[78] = 'T';
    DNA[79] = 'C';
    DNA[80] = 'G';
    DNA[81] = 'A';
    DNA[82] = 'T';
    DNA[83] = 'C';
    DNA[84] = 'G';
    DNA[85] = 'A';
    DNA[86] = 'T';
    DNA[87] = 'C';
    DNA[88] = 'G';
    DNA[89] = 'A';
    DNA[90] = 'T';
    DNA[91] = 'C';
    DNA[92] = 'G';
    DNA[93] = 'A';
    DNA[94] = 'T';
    DNA[95] = 'C';
    DNA[96] = 'G';
    DNA[97] = 'A';
    DNA[98] = 'T';
    DNA[99] = '\0';
    
    printf("Sequência de DNA: %s.\n", DNA);
    
    //Encontrar sequência especificada no DNA

    return 0;
}