/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 25 de abril de 2025, 08:21
 * 
 * Joaquim Pedro do Nascimento Moreira de Jesus
 * 
 * 14. Pico em Função Exponencial com Penalidade: considere a função:
 * 
 *      f(x, y) = 10.e^−(x^2+y^2)/10 − |x − y|
 *      
 *      • Avalie essa função para x e y inteiros de -5 até 5.
 *      
 *      • Mostre:
 *          
 *          o O ponto (x, y) onde a função atinge seu valor máximo
 *          
 *          o O valor máximo encontrado
 */

#include <cstdlib>  // Para funções padrão
#include <iostream> // Para entrada/saída
#include <cmath>    // Para fórmulas matemáticas

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // Declarando Variáveis
    float result, x, y, xmaxpoint, ymaxpoint, maxresult, xminpoint, yminpoint, minresult;
    
    // Iniciando Variáveis
    maxresult = -10000000000;
    minresult = 10000000000;
    x, y = -5;
    
    //Loop de cáculo
    
    while(x <= 5){  
        y = -5;
        while(y <=5){
            // f(x, y) = 10.e^−(x^2+y^2)/10 − |x − y|
            result = 10*(exp((pow(x, 2)) + (pow(y, 2)/10)))- abs(x - y);
            cout << "f("<<x<<", "<< y<<") = 10.e^−("<<x<<"^2+"<<y<<"^2)/10 − |"<<x<<" − "<< y << "| = " << result << endl;
            if(result > maxresult){
                maxresult = result;
                xmaxpoint = x;
                ymaxpoint = y;
            }else if(result < minresult){
                minresult = result;
                xminpoint =  x;
                yminpoint = y;
            }
            y += 0.001;
        }
        x += 0.001;
    }
    
    cout << "\n\n\n_______________________________________________________________\n\nPICO EM FUNÇÃO EXPONENCIAL COM PENALIDADE\n\n\tf(x, y) = 10.e^−(x^2+y^2)/10 − |x − y|\n\nO maior valor encontrado foi "<< maxresult <<" quando x e y possuem os valores de " << xmaxpoint << " e " << ymaxpoint << " respectivamente.\n\nO menor valor encontrado foi "<< minresult <<" quando x e y possuem os valores de " << xminpoint << " e " << yminpoint << " respectivamente.\n";

    return 0;
}

