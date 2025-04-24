/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 3 de abril de 2025, 08:07
 */

/*
 * Joaquim Pedro do Nascimento Moreira de Jesus
 * Aula 03/04/2025
 * AED's Prática
 * 
 * Tema: Características de variáveis em alocação de memória
 * Atividade: Montar uma tabela com a estrutura:
 *              Título
 * Tipo     Valor   Endereço    Tamanho
 * Int
 * Float
 * Char
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
   
    int varinteira = 47;
    float varfloat = 47.01;
    char varchar = 80; // Variáveis do tipo string usam a formulação da tabela ASCII para suas representações. Exemplo: P = 80 na tabela ASCII
    //char varchar = 'P';
    double vardouble = 47.01;
    long int varlongint = 47;
    short int varshortint = 47;
    int i, a, b;
    long int c, d;
    short int e, f;
    unsigned short int g, h;
    short float q, l;
    float k, j;
    
    //Tabela Características de variáveis em alocação de memória
    
    printf(" ___________________________________________________________________\n");
    printf("\n|        Características de variáveis em alocação de memória        |\n");  
    printf("|___________________________________________________________________|\n");
    printf("| Tipo \t\t|     Valor \t|    Endereço \t\t|  Tamanho  |\n");
    printf("|___________________________________________________________________|\n");
    printf("| Int  \t\t|  %d   \t| %p \t|     %li     |\n",varinteira, &varinteira, sizeof(int));
    printf("|___________________________________________________________________|\n");
    printf("| Float\t\t|  %.2f \t| %p  \t|     %li     |\n",varfloat, &varfloat, sizeof(float));
    printf("|___________________________________________________________________|\n");
    printf("| Char \t\t|   %c     \t| %p  \t|     %li     |\n",varchar, &varchar, sizeof(char));
    printf("|___________________________________________________________________|\n");
    printf("| Char \t\t|   %d     \t| %p  \t|     %li     |\n",varchar, &varchar, sizeof(char));
    printf("|___________________________________________________________________|\n");
    printf("| Double\t|  %.2f \t| %p  \t|     %li     |\n",varfloat, &varfloat, sizeof(double));
    printf("|___________________________________________________________________|\n");
    printf("| Long Int\t|  %d   \t| %p \t|     %li     |\n",varinteira, &varinteira, sizeof(long int));
    printf("|___________________________________________________________________|\n");
    printf("| Short Int\t|  %d   \t| %p \t|     %li     |\n",varinteira, &varinteira, sizeof(short int));
    printf("|___________________________________________________________________|\n\n\n");
    
    //Tabela ASCII
    printf(" __________________\n");
    printf("|   Tabela ASCII   |\n");
    printf("| Int \t| Caracter |\n");
    printf("|__________________|\n");  
    i = 0;
    while(i<256){
        printf("|  %d \t|     %c    |\n",i,i);
        i = i + 1;
    }
    printf("|__________________|\n\n\n"); 
    
    //Tabela Limites das Variáveis
    printf("|           Limites das Variáveis         |\n");
    printf("| Tipos \t| Inferior \t|   Superior  |\n");
    
    //Unsigned Short Int
    g = 0;
    h = 1;
    
    while(g < h){

        g = h;
        h = h + 1;
    }
    printf("| Unsigned Short Int\t| %d  \t|  %d |\n", h, g); 
    
    //Short Int
    e = 0;
    f = 1;
    
    while(e < f){

        e = f;
        f = f + 1;
    }
    printf("| Short Int\t| %d  \t|  %d |\n", f, e); 
    
    //Int
    a = 0;
    b = 1;
    
    while(a < b){

        a = b;
        b = b + 1;
    }
    printf("| Int   \t| %d  \t|  %d |\n", b, a); 
    
    //Long int
    c = 0;
    d = 1;
    while(c < d){

    c = d;
    d = d + 1;
    }
    printf("| Long Int \t| %d  \t|  %d |\n", d, c); 
    
    //Short Float
    q = 0;
    l = 1;
    while(q < l){

    q = l;
    l = l + 1;
    }
    printf("| Short Float \t| %f  \t|  %f |\n", l, q); 
    
    //Float
    k = 0;
    j = 1;
    while(k < j){

    k = j;
    j = j + 1;
    }
    printf("| Float \t| %f  \t|  %f |\n", j, k);    
    
    return 0;
}

