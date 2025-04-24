/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 23 de abril de 2025, 12:40
 */

#include <cstdlib>    // Para funções padrão
#include <fstream>    // Para manipulação de arquivos
#include <iostream>   // Para entrada/saída
#include <string.h>   // Para manipulação de strings
#include <cmath>    // Para fórmulas matemáticas

/*
 * Joaquim Pedro do Nascimento Moreira de Jesus - 2025.1.08.014
 * 20/04/2025
 * 
 * Tema: arquivos - texto
 * 
 *          CALCULADORA DE VOLUME E ÁREA DE FIGURAS
 * 
 * ifstream arquivo ("entrada.txt");
 * i - input
 * f - file
 * stream - fluxo de caracteres
 * arquivo - vatiável
 * ("entrada.txt") - caminho
 * entrada.txt - nome do arquivo nos diretórios
 * 
 * ofstream arquivo1 ("saida.txt");
 * o - output
 * f - file
 * stream - fluxo de caracteres
 * ("saida.txt") - caminho
 * saida.txt - nome do arquivo nos diretórios
 * 
 * arquivo >> figura;
 * arquivo - de onde vem
 * >> - operador de fluxo de caracteres
 * figura - variável
 * 
 * arquivo1 << numero;
 * arquivo1 - para onde vai
 * << - operador de fluxo de caracteres
 * numero - variável
 * 
 * 
 * Exercício:
 * 
 * Desenvolver um sistema composto por dois módulos interligados:
 * 
 * Módulo de Criação: Oferecerá uma interface de menu para que o usuário defina as características das formas geométricas que compõem uma cena visual, armazenando essas informações em um arquivo de texto estruturado (ex.: 'cenagrafica.txt').
 * 
 * Módulo de Análise: Lerá o arquivo gerado anteriormente para computar as propriedades matemáticas da cena (áreas e volumes cumulativos).
 * 
 * Especificações do Arquivo:
 * Cada elemento da cena ocupará uma linha no arquivo, contendo:
 *     Tipo da figura
 *     Parâmetros dimensionais relevantes (variáveis por figura)
 * 
 * O marcador 'fim' encerrará a lista de formas - qualquer conteúdo posterior será ignorado.
 * 
 * Fluxo Operacional:
 * O usuário interage com o menu do primeiro programa para construir a cena gráfica digitalmente.
 * O segundo programa processa os dados armazenados para gerar métricas espaciais da composição criada.
 * 
 * Vantagens da Abordagem:
 * 
 * Separação clara entre entrada e processamento de dados
 * Armazenamento persistente das configurações da cena
 * Capacidade de análise matemática automatizada
 * 
 * Observação: Faça um menu de seleção para facilitar ao usuário
 *          Estrutura do arquivo de acordo com a figura geométrica
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
    // Declaração de variáveis
    string figura;  // Armazena o tipo da figura lida
    float lad1, lad2, lad3, raio, altura, sherao;  // Dimensões das figuras
    float volume, area, volumtotal, areatotal, pi, raiz3;  // Cálculos geométricos
    int num, cont, cont3d, cont2d;  // Contadores
    
    // Abre arquivo para leitura
    ifstream arquivo("cenagrafica.txt");
    
    // Inicialização de variáveis
    num = 1;  // Controle do loop principal
    cont = 0;  // Contador total de figuras
    cont2d = 0;  // Contador de figuras 2D
    cont3d = 0;  // Contador de figuras 3D
    pi = 3.14159265358979323846;  // Valor de π
    volumtotal = 0;  // Acumulador de volume
    areatotal = 0;  // Acumulador de área
    raiz3 = 1.73205080757;  // √3 para cálculos
    
    // Verifica se arquivo foi aberto
    if(!arquivo.is_open()){
        cout<<"\nErro: Arquivo não encontrado.\n";
        return 1;
    }
    
    // Loop principal de leitura do arquivo
    while (num != 0){
        cont = cont + 1;
        arquivo >> figura;
        
        // Processamento para cada tipo de figura
        if(figura == "cilindro"){
            cont3d = cont3d + 1;
            arquivo >> raio;
            arquivo >> altura;
            area = (2*pi*raio*altura)+2*(pi*raio*raio); // Área total cilindro
            volume = pi*raio*raio*altura; // Volume cilindro
            areatotal = areatotal + area;
            volumtotal = volumtotal + volume;
            cout << cont << "° - " << figura << ": Área: " << area <<" | Volume: "<< volume << ";\n";
        } else {
            if(figura == "cubo"){
                cont3d = cont3d + 1;
                arquivo >> lad1;
                area = 6*(lad1*lad1); // Área cubo
                volume = lad1*lad1*lad1; // Volume cubo
                areatotal = areatotal + area;
                volumtotal = volumtotal + volume;
                cout << cont << "° - " << figura << ": Área: " << area <<" | Volume: "<< volume << ";\n";
            } else {
                if(figura == "triângulo"){
                    cont2d = cont2d + 1;
                    arquivo >> lad1;
                    arquivo >> lad2;
                    arquivo >> lad3;
                    area = sqrt(sherao * (sherao - lad1) * (sherao - lad2) * (sherao - lad3)); //Fórmula de Herão
                    areatotal = areatotal + area;
                    // Verifica tipo de triângulo e calcula área
                    if(lad1 == lad2 && lad1 == lad3){
                        cout << cont <<  "° - " << figura << " Equilátero: Área: " << area << ";\n";
                    } else {
                        // Lógica para triângulo isósceles
                        if(lad1==lad2 && lad1!=lad3 || lad1 == lad3 && lad1 != lad2 || lad2 == lad3 && lad3 != lad1){
                            cout << cont << "° - " << figura << " Isóceles: Área: " << area << ";\n";
                        } else {
                            if(lad1 != lad3 && lad1 != lad2 && lad2 != lad3){                               
                                cout << cont << "° - " << figura << " Escaleno: Área: " << area << ";\n";                              
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
                                                        cont = cont - 1; // Ajusta contador
                                                        num = 0; // Sai do loop
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
    
    // Exibe resultados finais
    cout << "\n\nO cenário possue um volume total de " << volumtotal << " e área total de " << areatotal << "\nForam contabilizados " << cont << "° figuras, sendo " << cont3d << " tridimenssionais e " << cont2d << " bidimenssionais.\n\n";
    
    //Fecha o arquivo
    arquivo.close();
    
    return 0;
}