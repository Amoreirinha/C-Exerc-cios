/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 24 de abril de 2025, 08:08
 * 
 * Joaquim Pedro do Nascimento Moreira de Jesus
 * 
 * 24/04/2025
 * 
 * 15. Análise de Função Modular e Quadrática: considere a função:
 * 
 *          f(x, y) = |x + y| + x^2 − y
 * 
 * • Escreva um projeto que percorre todos os pares de inteiros (x, y) com:
 * 
 *      o x de -8 até 8
 *      
 *      o y de -5 até 5
 * 
 * • Encontre:
 * 
 *      o O ponto (x, y) que gera o maior valor de f(x, y)
 * 
 *      o O valor máximo
 *      
 *      o E a quantidade de vezes que esse valor máximo aparece
 */

#include <cstdlib>  // Para funções padrão
#include <iostream> // Para entrada/saída
#include <cmath>   // Para fórmulas matemáticas

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // Declarando variávies
    float x, y, xmaxponto, ymaxponto, xminponto, yminponto, result, resultmax, resultmin, maxcont, mincont;
    
    // Iniciando variáveis f(x, y) = |x + y| + x^2 − y
    maxcont = 0;
    resultmax = -100000;
    x = -8;
    y = -5;

    // Loop para calcular 
    while (x <= 8) {
        y = -5; // Retorna y para seu valor inicial para próximo loop com outro valor de x
        while (y <= 5) {            
            result = (abs(x + y))+(pow(x, 2)) - y; // Cálculo de f(x, y) = |x + y| + x^2 − y
            // Printa cada conta. Não é necessário, utilizado apenas para confirmar se x e y estão possuindo os valores corretos.
            cout << "f(" << x << ", "<< y << ") = |" << x <<" + " << y << "| + " << x << "^2 − (" << ((-1)*y) << ") = " << result << endl; 
            // Avaliação para armazenar o maior e menor valor e quantas vezes ele aparece
            if (result > resultmax) {
                resultmax = result;
                xmaxponto = x;
                ymaxponto = y;
                maxcont = 1;
            } else if (resultmax == result) {
                maxcont++;
            } else if (result < resultmin){
                resultmin = result;
                xminponto = x;
                yminponto = y;
                mincont = 1;
            } else if (result == resultmin){
                mincont++;
            }
            
            y += 0.01 ; // Incrementa y com 0.01
        }        
        x += 0.01; // Incrementa x com 0.01
    }
    
    // Resultado final
    cout << "\n\nANÁLISE DE FUNÇÃO MODULAR E QUADRÁTICA\n\n\tf(x, y) = |x + y| + x^2 − y\n\nO maior valor possível da função é: " << resultmax << "\n\nOs valores para x e y que geram o maior valor são, respectivamente, " << xmaxponto << " e " << ymaxponto << "\n\nA quantidade de vezes que esse resultado aparece são " << maxcont << "\n\nO menor valor possível da função é: " << resultmin << "\n\nOs valores para x e y que geram o maior valor são, respectivamente, " << xminponto << " e " << yminponto << "\n\nA quantidade de vezes que esse resultado aparece são " << mincont << endl;

    return 0;
}

