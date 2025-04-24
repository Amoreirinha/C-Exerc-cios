/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 10 de abril de 2025, 08:44
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string.h>

/*
 * Joaquim Pedro do Nascimento Moreira de Jesus - 2025.1.08.014
 * 10/04/2025
 * 
 * Tema: arquivos - texto
 * 
 * Exercício: Considere um arquivo-texto de entrada com figuras geométricas 2D e 3D. Faça um projeto que percorra o arquivo, calcule área e volume das figuras e informe o volume e área total da cena no final. No final o arquivo terá a string "fim".
 */


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string figura, registro;
    float lad1, lad2, lad3, raio, altura, volume, area, volumtotal, areatotal, pi, raiz3;
    int num, cont;    
    ifstream arquivo("cenografico.txt");
    
    num = 0;
    cont = 0;
    pi = 3.141592653589793238462643383279502884197169;
    volumtotal = 0;
    areatotal = 0;
    raiz3 = 1.7320508075688772935;
    
    if(!arquivo.is_open()){
        cout<<"\nErro: Arquivo não encontrado.\n";
        return 1; //Único momento onde podemos usar o return 1, significa que aconteceu um erro
    }
    
    while (num != 0){
        cont = cont + 1;
        arquivo >> figura;
        if(figura == "cilindro"){
            arquivo >> raio;
            arquivo >> altura;
            area = (2*pi*raio*altura)+2*(pi*raio*raio);
            volume = pi*raio*raio*altura;
            areatotal = areatotal + area;
            volumtotal = volumtotal + volume;
            registro = registro + cont + "° - " + figura + ": Área: " + area +" | Volume: "+ volume + ";\n";
        } else {
            if(figura == "cubo"){
                arquivo >> lad1;
                area = 6*(lad1*lad1);
                volume = lad1*lad1*lad1;
                areatotal = areatotal + area;
                volumtotal = volumtotal + volume;
                registro = registro + cont + "° - " + figura + ": Área: " + area +" | Volume: "+ volume + ";\n";
            } else {
                if(figura == "triângulo"){
                    arquivo >> lad1;
                    arquivo >> lad2;
                    arquivo >> lad3;
                    if(lad1 == lad2 && lad1 == lad3){
                        area = ((lad1*lad1)*raiz3)/4;
                        areatotal = areatotal = areatotal + area;
                        registro = registro + cont + "° - " + figura + ": Área: " + area + ";\n";
                    } else {
                        if(lad1==lad2 && lad1!=lad3){
                            area = ((lad3*lad3)*(4*(lad1*lad1)-(lad3*lad3*)))/16;
                            areatotal = areatotal = areatotal + area;
                            registro = registro + cont + "° - " + figura + ": Área: " + area + ";\n";
                            }else{
                                if(lad1 == lad3 && lad1 != lad2){
                                    area = ((lad2*lad2)*(4*(lad1*lad1)-(lad2*lad2*)))/16;
                                    areatotal = areatotal = areatotal + area;
                                    registro = registro + cont + "° - " + figura + ": Área: " + area + ";\n";
                            }else{
                                    if(lad2 == lad3 && lad3 != lad1){
                                        area = ((lad1*lad1)*(4*(lad2*lad2)-(lad1*lad1*)))/16;
                                        areatotal = areatotal = areatotal + area;
                                        registro = registro + cont + "° - " + figura + ": Área: " + area + ";\n";
                                    }else{
                                if(lad1 != lad3 && lad1 != lad2 && lad2 != lad3){
                                    
                                }
                            }
                            }
                        }
                    }
                }
            }
        }
        
    }
    
    return 0;
}

