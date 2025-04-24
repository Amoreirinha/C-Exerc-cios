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
 * 
 * Observação:
 *      Estrutura do arquivo de acordo com a figura geométrica
 * 
 * cubo Lado1
 * quadrado Lado1
 * círculo Raio
 * triângulo Lado1 Lado2 Lado3
 * cilindro Lado1 Raio
 * pentágono Lado1 Altura
 * paralelepipedo Lado1 Lado2 Lado3
 * hexágono Lado1
 * heptágono Lado1 Altura
 * octógono Lado1 Altura
 * trapézio Lado1 Lado2 Altura - considerando Lado1 e Lado2 a base maior e menor do trapézio
 * fim
 * 
 */

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string figura;
    float lad1, lad2, lad3, raio, altura, volume, area, volumtotal, areatotal, pi, raiz3;
    int num, cont, cont3d, cont2d;    
    ifstream arquivo("cenografica.txt");
    
    num = 1;
    cont = 0;
    cont2d = 0;
    cont3d = 0;
    pi = 3.141592653589793238462643383279502884197169;
    volumtotal = 0;
    areatotal = 0;
    raiz3 = 1.7320508075688772935;
    
    if(!arquivo.is_open()){
        cout<<"\nErro: Arquivo não encontrado.\n";
        return 1;
    }
    
    while (num != 0){
        cont = cont + 1;
        arquivo >> figura;
        if(figura == "cilindro"){
            cont3d = cont3d + 1;
            arquivo >> raio;
            arquivo >> altura;
            area = (2*pi*raio*altura)+2*(pi*raio*raio);
            volume = pi*raio*raio*altura;
            areatotal = areatotal + area;
            volumtotal = volumtotal + volume;
            cout << cont << "° - " << figura << ": Área: " << area <<" | Volume: "<< volume << ";\n";
        } else {
            if(figura == "cubo"){
                cont3d = cont3d + 1;
                arquivo >> lad1;
                area = 6*(lad1*lad1);
                volume = lad1*lad1*lad1;
                areatotal = areatotal + area;
                volumtotal = volumtotal + volume;
                cout << cont << "° - " << figura << ": Área: " << area <<" | Volume: "<< volume << ";\n";
            } else {
                if(figura == "triângulo"){
                    cont2d = cont2d + 1;
                    arquivo >> lad1;
                    arquivo >> lad2;
                    arquivo >> lad3;
                    if(lad1 == lad2 && lad1 == lad3){
                        area = ((lad1*lad1)*raiz3)/4;
                        areatotal = areatotal + area;
                        cout << cont <<  "° - " << figura << " Equilátero: Área: " << area << ";\n";
                    } else {
                        if(lad1==lad2 && lad1!=lad3 || lad1 == lad3 && lad1 != lad2 || lad2 == lad3 && lad3 != lad1){
                            if(lad2 == lad3 && lad3 != lad1){
                                area = ((lad1*lad1)*(4*(lad2*lad2)-(lad1*lad1)))/16;
                            } else {
                                if(lad1==lad2 && lad1!=lad3){
                                    area = ((lad3*lad3)*(4*(lad1*lad1)-(lad3*lad3)))/16;
                                } else {
                                    if(lad1 == lad3 && lad1 != lad2){
                                        area = ((lad2*lad2)*(4*(lad1*lad1)-(lad2*lad2)))/16;
                                    }
                                }
                            }    
                            areatotal = areatotal + area;
                            cout << cont << "° - " << figura << " Isóceles: Área: " << area << ";\n";
                        } else {
                            if(lad1 != lad3 && lad1 != lad2 && lad2 != lad3){
                                area = ((lad1+lad2+lad3)/2)*(((lad1+lad2+lad3)/2)-lad1)*(((lad1+lad2+lad3)/2)-lad2)*(((lad1+lad2+lad3)/2)-lad3);
                                cout << cont << "° - " << figura << " Escaleno: Área ao quadrado: " << area << ";\n";
                            }
                        }
                    }
                } else {
                    if(figura == "quadrado"){
                        cont2d = cont2d + 1;
                        arquivo >> lad1;
                        area = lad1*lad1;
                        areatotal = areatotal + area;
                        cout << cont << "° - " << figura << ": Área: " << area << ";\n";
                    } else {
                        if(figura == "círculo"){
                            cont2d = cont2d + 1;
                            arquivo >> raio;
                            area = pi*(raio*raio);
                            areatotal = areatotal + area;
                            cout << cont << "° - " << figura << ": Área: " << area << ";\n";
                        } else {
                            if(figura == "pentágono"){
                                cont2d = cont2d + 1;
                                arquivo >> lad1;
                                arquivo >> altura;
                                area = (5*lad1*altura)/2;
                                areatotal = areatotal + area;
                                cout << cont << "° - " << figura << ": Área: " << area << ";\n";
                            } else {
                                if(figura == "paralelepipedo"){
                                    cont3d = cont3d + 1;
                                    arquivo >> lad1;
                                    arquivo >> lad2;
                                    arquivo >> lad3;
                                    area = 2*(lad1*lad2) + 2*(lad1*lad3) + 2*(lad2*lad3);
                                    volume = lad1*lad2*lad3;
                                    areatotal = areatotal + area;
                                    volumtotal = volumtotal + volume;
                                    cout << cont << "° - " << figura << ": Área: " << area <<" | Volume: "<< volume << ";\n";
                                } else {
                                    if(figura=="hexágono"){
                                        cont2d = cont2d + 1;
                                        arquivo >> lad1;
                                        area = (3*(lad1*lad1)*raiz3)/2;
                                        areatotal = areatotal + area;
                                        cout << cont << "° - " << figura << ": Área: " << area << ";\n";                                        
                                    } else {
                                        if(figura == "heptágono"){
                                            cont2d = cont2d + 1;
                                            arquivo >> lad1;
                                            arquivo >> altura;
                                            area = (7*lad1*altura)/2;
                                            areatotal = areatotal + area;
                                            cout << cont << "° - " << figura << ": Área: " << area << ";\n";
                                        } else {
                                            if(figura == "octógono"){
                                                cont2d = cont2d + 1;
                                                arquivo >> lad1;
                                                arquivo >> altura;
                                                 area = 4*lad1*altura;
                                                areatotal = areatotal + area;
                                                cout << cont << "° - " << figura << ": Área: " << area << ";\n";
                                            } else {
                                                if(figura == "trapézio"){
                                                    cont2d = cont2d + 1;
                                                    arquivo >> lad1;
                                                    arquivo >> lad2;
                                                    arquivo >> altura;
                                                    area = ((lad1+lad2)*altura)/2;
                                                    areatotal = areatotal + area;
                                                    cout << cont << "° - " << figura << ": Área: " << area << ";\n";
                                                } else {
                                                    if(figura == "fim"){
                                                        cont = cont - 1;
                                                        num = 0;
                                                    }
                                                }
                                            }                                             
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    
    cout << "\n\nO cenário possue um volume total de " << volumtotal << " e área total de " << areatotal << "\nForam contabilizados " << cont << "° figuras, sendo " << cont3d << " tridimenssionais e " << cont2d << " bidimenssionais.\n\n";
    
    arquivo.close();
    
    return 0;
}