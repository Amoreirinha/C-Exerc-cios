/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 23 de abril de 2025, 12:46
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string.h>
#include <time.h> 

/*
 * Joaquim Pedro do Nascimento Moreira de Jesus - 2025.1.08.014
 * 20/04/2025
 * 
 * Tema: arquivos - texto
 * 
 *      GERADOR DE FIGURAS
 * 
 * ifstream arquivo ("entrada.txt");
 * i - input
 * f - file
 * stream - fluxo de caracteres
 * arquivo - variável
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
    string figura, loopquest;  // Nome da figura e controle de loop
    float lad1, lad2, lad3, raio, altura, inde;  // Dimensões das figuras
    int num, cont, loop, choice, inf, max, multi; // Controles e configurações
    
    // Abre arquivo para gravação
    ofstream arquivo_gravacao ("cenagrafica.txt"); // Seed para números aleatórios baseada no tempo     
    
    // Inicializa gerador de números aleatórios
    srand(time(NULL));
    
    // Inicializa variáveis
    cont = 1;           // Contador de figuras geradas (começa em 1 para exibição)
    multi = 1;          // Fator multiplicador para conversão de inteiros para decimais
    loop = 1;           // Controle do loop principal (1 = executa, 0 = sai)
    
    // Verifica se arquivo foi aberto corretamente
    if(!arquivo_gravacao.is_open()){
        cout<<"\nErro: Arquivo não encontrado.\n";
        return 1;
    }
    
    // Menu principal
    cout << "\nBem-vindo ao gerador de figuras para cenografias.";
    
    // Exibe menu de opções
    while(loop == 1){
        /* MENU DE OPÇÕES
         * Exibe as 11 figuras disponíveis + opção aleatória
         * Valida entrada para garantir número entre 1-12 */
        cout << "\nAs figuras possíveis são:\n\t1 - Cubo\n\t2 - Quadrado\n\t3 - Círculo\n\t4 - Triângulo\n\t5 - Cilindro\n\t6 - Pentágono\n\t7 - Paralelepipedo\n\t8 - Hexágono\n\t9 - Heptágono\n\t10 - Octógono\n\t11 - Trapézio\n\t12 - Gerar aleatoriamente\n\nDigite o número da figura que quer gerar:\n";
        cin >> choice;
        
        // Valida entrada do usuário
        while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9 && choice != 10 && choice != 11 && choice != 12){
            cout << "Valor inválido inserido!!\n\nAs figuras possíveis são:\n\t1 - Cubo\n\t2 - Quadrado\n\t3 - Círculo\n\t4 - Triângulo\n\t5 - Cilindro\n\t6 - Pentágono\n\t7 - Paralelepipedo\n\t8 - Hexágono\n\t9 - Heptágono\n\t10 - Octógono\n\t11 - Trapézio\n\t12 - Gerar aleatoriamente\n\nDigite o número da figura que quer gerar:\n";
            cin >> choice;
        }
        
        // Atribui nome da figura conforme escolha
        // Mapeia a escolha numérica para o nome da figura
        if(choice == 1){
            figura = "cubo";
        } else {
            if (choice == 2){
                figura = "quadrado";
            } else {
                if(choice == 3){
                    figura = "círculo";
                } else {
                    if(choice == 4){
                        figura = "triângulo";                    
                    } else {
                        if(choice == 5){
                            figura = "cilindro";
                        } else {
                            if(choice == 6){
                                figura = "pentágono";
                            } else {
                                if(choice == 7){
                                    figura = "paralelepipedo";
                                } else { 
                                    if(choice == 8){
                                        figura = "hexágono";
                                    } else { 
                                        if(choice == 9){
                                            figura = "heptágono";
                                        } else {
                                            if(choice == 10){
                                                figura = "octógono";
                                            } else {
                                                if(choice == 11){
                                                    figura = "trapézio";
                                                } else {
                                                    figura = "figuras aleatória";
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
        
        // Solicita quantidade e dimensões das figuras
        cout << "\nDigite a quantidade de " << figura << "s que deseja criar:\n";
        cin >> num;
        while(num <= 0){
            cout << "\nValor inserido inválido!!\n\nDigite a quantidade de " << figura << "s que deseja criar:\n";
            cin >> num;
        }
        cout << "\nQual a dimensão mínima a ser gerada?\n" ;
        cin >> inf;
        while(inf <= 0){
            cout << "\nValor inserido inválido!!\n\nQual a dimensão mínima a ser gerada?\n" ;
            cin >> inf;
        }
        cout << "\nQual a dimensão máxima a ser gerada?\n" ;
        cin >> max;
        while(max <= inf){
            cout << "\nValor inserido inválido!!\n\nQual a dimensão máxima a ser gerada?\n" ;
            cin >> max;
        }
        cout << "\nDeseja dimensões inteiras ou decimais?\n\t1 - números inteiros\n\t2 - números decimais\n\n";
        cin >> inde;
        while(inde != 1 && inde!= 2){
            cout << "\nValor inserido inválido!!\n\nDeseja dimensões inteiras ou decimais?\n\t1 - números inteiros\n\t2 - números decimais\n\n";
            cin >> inde;
        }
        // 1 = inteiros | 2 = decimais (0.1 a 0.9)
        
        // Configura para números decimais se necessário
        if(inde==2){
            inde = 0.1;  // Fator de conversão para decimais
            multi = 10;  // Multiplicador para o rand()
        }
        
        // Gera figuras não aleatórias
        if(choice !=12){ // Geração específica por figura
            while(num >= cont){                
                if(figura == "cubo"){
                    /* Gera valor aleatório ajustado para:
                     * - Ficar entre [inf,max]
                     * - Respeitar a precisão escolhida */
                    lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;  // Gera dimensões aleatórias para cada tipo de figura
                    cout << cont << "° - " << figura << ": " << lad1 << endl;
                    arquivo_gravacao << figura << "\t" << lad1 << endl;
                } else {
                    if (figura == "quadrado"){
                        lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                        cout << cont << "° - " << figura << ": " << lad1 << endl;
                        arquivo_gravacao << figura << "\t" << lad1 << endl;
                    } else {
                        if(figura == "círculo"){
                            raio = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                            cout << cont << "° - " << figura << ": " << raio << endl;
                            arquivo_gravacao << figura << "\t" << raio << endl;
                        } else {
                            if(figura == "triângulo"){
                                lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                lad2 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                lad3 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                if((lad1+lad2) < lad3 || (lad1+lad3) < lad2 || (lad3+lad2) < lad2){
                                    while((lad1+lad2) < lad3 || (lad1+lad3) < lad2 || (lad3+lad2) < lad2){
                                       lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                       lad2 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                       lad3 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde; 
                                    }
                                }
                                cout << cont << "° - " << figura << ": " << lad1 << "\t" << lad2 << "\t" << lad3 << endl;
                                arquivo_gravacao << figura << "\t" << lad1 << "\t" << lad2 << "\t" << lad3 << endl;                                        
                            } else {
                                if(figura == "cilindro"){
                                    lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                    raio = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                    cout << cont << "° - " << figura << ": " << lad1 << "\t" << raio << endl;
                                    arquivo_gravacao << figura << "\t" << lad1 << "\t" << raio << endl;                                
                                } else {
                                    if(figura == "pentágono"){
                                        lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                        altura = lad1 * 0.6882; //apótema aproximada de um pentágono 
                                        cout << cont << "° - " << figura << ": " << lad1 << "\t" << altura << endl;
                                        arquivo_gravacao << figura << "\t" << lad1 << "\t" << altura << endl;   
                                    } else {
                                        if(figura == "paralelepipedo"){
                                            lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                            lad2 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                            lad3 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;                                       
                                            cout << cont << "° - " << figura << ": " << lad1 << "\t" << lad2 << "\t" << lad3 << endl;
                                            arquivo_gravacao << figura << "\t" << lad1 << "\t" << lad2 << "\t" << lad3 << endl;
                                        } else { 
                                            if(figura == "hexágono"){
                                                lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                                cout << cont << "° - " << figura << ": " << lad1 << endl;
                                                arquivo_gravacao << figura << "\t" << lad1 << endl;
                                            } else { 
                                                if(figura == "heptágono"){
                                                    lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                                    altura = lad1 * 1.03825; //apótema aproximada de um heptágono
                                                    cout << cont << "° - " << figura << ": " << lad1 << "\t" << altura << endl;
                                                    arquivo_gravacao << figura << "\t" << lad1 << "\t" << altura << endl;  
                                                } else {
                                                    if(figura == "octógono"){
                                                        lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                                        altura = lad1 * 1.2071; //apótema aproximada de um octógono
                                                        cout << cont << "° - " << figura << ": " << lad1 << "\t" << altura << endl;
                                                        arquivo_gravacao << figura << "\t" << lad1 << "\t" << altura << endl;                                                      
                                                    } else {
                                                        if(figura == "trapézio"){
                                                            lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                                            lad2 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                                            lad3 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;                                       
                                                            cout << cont << "° - " << figura << ": " << lad1 << "\t" << lad2 << "\t" << lad3 << endl;
                                                            arquivo_gravacao << figura << "\t" << lad1 << "\t" << lad2 << "\t" << lad3 << endl;
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
                cont = cont + 1;
            }
        } else {
            while(num >= cont){
                 // Gera figuras aleatórias
                int choice2;                
                choice2 =(rand()% 11)+1;    // Gera 1-11
                

                 /* Lógica similar para gerar cada figura aleatória
                 * Cada bloco gera dimensões aleatórias conforme
                 * os parâmetros configurados pelo usuário */
                if(choice2 == 1){
                figura = "cubo";
                lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                cout << cont << "° - " << figura << ": " << lad1 << endl;
                arquivo_gravacao << figura << "\t" << lad1 << endl;
                } else {
                    if (choice2 == 2){
                        figura = "quadrado";
                        lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                        cout << cont << "° - " << figura << ": " << lad1 << endl;
                        arquivo_gravacao << figura << "\t" << lad1 << endl;
                    } else {
                        if(choice2 == 3){
                            figura = "círculo";
                            raio = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                            cout << cont << "° - " << figura << ": " << raio << endl;
                            arquivo_gravacao << figura << "\t" << raio << endl;
                        } else {
                            if(choice2 == 4){
                                figura = "triângulo";
                                lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                lad2 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                lad3 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                if((lad1+lad2) < lad3 || (lad1+lad3) < lad2 || (lad3+lad2) < lad2){
                                    while((lad1+lad2) < lad3 || (lad1+lad3) < lad2 || (lad3+lad2) < lad2){
                                       lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                       lad2 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                       lad3 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde; 
                                    }
                                }
                                cout << cont << "° - " << figura << ": " << lad1 << "\t" << lad2 << "\t" << lad3 << endl;
                                arquivo_gravacao << figura << "\t" << lad1 << "\t" << lad2 << "\t" << lad3 << endl;                                        
                            } else {
                                if(choice2 == 5){
                                    figura = "cilindro";
                                    lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                    raio = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                    cout << cont << "° - " << figura << ": " << lad1 << "\t" << raio << endl;
                                    arquivo_gravacao << figura << "\t" << lad1 << "\t" << raio << endl;                                
                                } else {
                                    if(choice2 == 6){
                                        figura = "pentágono";
                                        lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                        altura = lad1 * 0.6882; //apótema aproximada de um pentágono 
                                        cout << cont << "° - " << figura << ": " << lad1 << "\t" << altura << endl;
                                        arquivo_gravacao << figura << "\t" << lad1 << "\t" << altura << endl;   
                                    } else {
                                        if(choice2 == 7){
                                            figura = "paralelepipedo";
                                            lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                            lad2 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                            lad3 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;                                       
                                            cout << cont << "° - " << figura << ": " << lad1 << "\t" << lad2 << "\t" << lad3 << endl;
                                            arquivo_gravacao << figura << "\t" << lad1 << "\t" << lad2 << "\t" << lad3 << endl;
                                        } else { 
                                            if(choice2 == 8){
                                                figura = "hexágono";
                                                lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                                cout << cont << "° - " << figura << ": " << lad1 << endl;
                                                arquivo_gravacao << figura << "\t" << lad1 << endl;
                                            } else { 
                                                if(choice2 == 9){
                                                    figura = "heptágono";
                                                    lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                                    altura = lad1 * 1.03825; //apótema aproximada de um heptágono
                                                    cout << cont << "° - " << figura << ": " << lad1 << "\t" << altura << endl;
                                                    arquivo_gravacao << figura << "\t" << lad1 << "\t" << altura << endl;  
                                                } else {
                                                    if(choice2 == 10){
                                                        figura = "octógono";
                                                        lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                                        altura = lad1 * 1.2071; //apótema aproximada de um octógono
                                                        cout << cont << "° - " << figura << ": " << lad1 << "\t" << altura << endl;
                                                        arquivo_gravacao << figura << "\t" << lad1 << "\t" << altura << endl;                                                      
                                                    } else {
                                                        if(choice2 == 11){
                                                            figura = "trapézio";
                                                            lad1 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                                            lad2 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;
                                                            lad3 = ((rand()%((max*multi) - (multi*inf) + 1))+(multi*inf))*inde;                                       
                                                            cout << cont << "° - " << figura << ": " << lad1 << "\t" << lad2 << "\t" << lad3 << endl;
                                                            arquivo_gravacao << figura << "\t" << lad1 << "\t" << lad2 << "\t" << lad3 << endl;
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
                cont = cont + 1;
            }
        }
        // Pergunta se deseja continuar
        cout << "\n\nGostaria de adicionar mais uma figura? Digite 's' para SIM e 'n' para NÃO\n";
        cin >> loopquest;
        cont = 0;
        if(loopquest=="n"){
            cout << "\nAdeus!\n";
            loop = 0; // Sai do loop principal
            //Adiciona o 'fim' no final após a criação de todas as figuras
            arquivo_gravacao << "fim";
        }
    }
    
    //Fecha o arquivo
    arquivo_gravacao.close();
    
    return 0;
}