/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 14 de março de 2025, 08:12
 */

#include <cstdlib>
#include<stdio.h>
#include<string.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    float nota1, nota2, nota3, nota4, media;
    char nomedoaluno[101];
    int notadecorte;
    
    printf("\nBem vindo à calculadora de média\n\n");
    printf("Prof. Paulo Bressan\n\n");
    printf("Informe o nome do aluno (máximo de 100 caracteres):\n");
    scanf("%s", &nomedoaluno);
    printf("Informe a nota de corte da disciplina:\n");
    scanf("%d", &notadecorte);
    printf("Informe a nota da P1:\n");
    scanf("%f", &nota1);
    printf("Informe a nota da P2:\n");
    scanf("%f", &nota2);
    printf("Informe a nota da T1:\n");
    scanf("%f", &nota3);
    printf("Informe a nota da T2:\n");
    scanf("%f", &nota4);
    
    media = (nota1*3+nota2*3+nota3*2+nota4*2)/10;
    
    printf("\n\n___________________________\n\n");
    printf("\nO aluno %s teve uma média %.2f\n", nomedoaluno,media);
    /*prinft("O Aluno está aprovado, se a média for maior ou igual à 6.00\n");
    prinft("O Aluno está reprovado, se a média for menor que 6.00\n");*/
    if (media>=notadecorte){
        printf("\n\n\t O aluno %s está aprovado\n\n",nomedoaluno);
    } else{
        printf("\n\n\t O aluno %s está reprovado\n\n",nomedoaluno);
    }
    
    return 0;
}

