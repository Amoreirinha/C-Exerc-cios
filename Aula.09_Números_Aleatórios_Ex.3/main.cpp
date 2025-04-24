/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 4 de abril de 2025, 08:33
 */
/*
 * Joaquim Pedro do Nascimento Moreira de Jesus
 * 2025.1.08.014
 * 04/04/2025
 * AED's Prática
 * 
 * Tema: Geração de Números Aleatórios
 * 
 * Exercício: Faça um projeto para encontrar um número gerado entre 0 e 100
 * 
 */

#include <cstdlib>
#include <time.h> // Biblioteca para geração de números aleatórios
#include <iostream> //Biblioteca de comando de entrada e saída (tal qual stdio.h)

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int segredo, chute, cont;
    
    cont = 1;

    cout << "Número Aleatório" << endl; //endl - Final de linha | "" - Mensagem | cout - comando para printar | << - Operador
    srand(time(NULL)); // srand - Inicializa o gerador de números aleatórios com uma semente baseada no tempo atual. Não precisa repetir ele no código. Uma vez no início do código já é o suficiente

    segredo = rand() % 101; // Gera um número aleatório entre 0 e 100 e armazena em segredo

    cout << "Um número foi gerado entre 1 e 100." << endl << endl;
    cout << endl << "Tentativa " << cont << endl;    
    cout << "Qual é este valor?" << endl;    
    cin >> chute;
    
    while (segredo != chute){
        cont = cont + 1;
        
        cout << endl << "Tentativa " << cont << endl;
        if(chute > segredo){
            cout << "O valor gerado é menor que " << chute << endl;
        }else{
            if(chute < segredo){
                cout << "O valor gerado é maior que " << chute <<endl;
            }
        }        
        cout << "Qual é este valor?" << endl;
        cin >> chute;
        
    }
    
    cout << endl << endl << "Parabéns, você acertou o valor na sua " << cont << "° tentativa!" << endl << endl;
    
    cout << "   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢆⡎⠗⠧⡀⣔⡾⠓⣦⡀⠀⠀⡰⠊⠛⠳⡄⠀⠀⠟⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣹⠀⠀⠀⠈⠃⠀⠀⢡⡇⠀⡭⡀⠀⠀⡀⡛⠀⠀⠀⠙⡧⠀⠀⣠⡶⢷⡄⠀⣠⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠃⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠉⠓⠉⠁⠀⠀⠀⠀⠀⠀⠋⡍⠀⠀⠀⠈⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⠀⠀⠀⠀⠀⠀⢀⡖⠊⠀⠉⠲⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⠀⠀⠀⠀⠀⣈⠁⠀⠀⠀⠀⠀⠀⠀⠁⢆⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⠀⠀⠀⢀⡝⠁⠀⠀⠀⠀⠀⣄⣀⠀⢀⣀⡵⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "  ⠀⠀⠀⢰⠃⠀⠀⠀⠀⡠⡖⠛⠒⠐⠋⠁⠁⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣮⡟⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ " << endl;
    cout << "   ⠀⠀⢰⠇⠀⠀⠀⠠⠂⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠋⠀⠁⢷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢚⠷⢞⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⠐⡻⠀⠀⠀⠀⠃⠀⠀⠀⠀⠀ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣬⡏⠀⠀⠀⠀⠉⣣⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣇⠁⠀⠀⠇⡀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⡼⠇⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠏⠉⠀⠀⠀⠀⠀⠀⠀⠉⠉⠒⠒⠀⠄⠤⠄⣼⠏⠁⠀⠀⠀⠀⠩⡂⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠠⡇⠃⠀⠸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠠⠴⠒⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡗⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⢰⠁⠀⠀⡅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠒⠄⡀⠀⠀⠀⠀⠀⠀⠀⡤⡦⠤⠄⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠤⣦⣤⣀⠉⡧⢍⡀⠀⠀⠀⠀" << endl;
    cout << "   ⡇⠅⠀⠀⠘⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠟⠃⠀⠀⠀⠀⣸⡧⣄⣀⣰⣿⣿⣧⠀⠀⠀⠀⠀⠀⣼⡇⠀⣀⡾⣿⣿⡗⠇⠀⠘⠀⢉⢻⡇" << endl;
    cout << "   ⢀⡇⠀⠀⠈⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⠾⡷⢿⣿⡿⠃⠀⣀⣀⣀⠀⠀⠀⣿⣿⣿⣿⣏⡏⣍⣠⣬⡝⠁⠁⠀⠀" << endl;
    cout << "   ⠀⣫⡀⠀⠀⠘⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠃⢄⣀⠀⠀⠀⠀⠀⠀⠓⠛⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠛⠋⠁⠀⠀⠙⢏⣀⠀⠀⠀" << endl;
    cout << "   ⠀⠈⣥⠀⠀⠀⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠘⣒⣶⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣄⡀⡅⣿⣄⠀" << endl;
    cout << "   ⠀⠀⠀⢝⡆⡀⠀⠱⡀⠀⠀⠀⠀⢀⠀⠬⠅⠁⠀⠉⠓⠋⠉⠉⠃⠑⠒⠀⠤⠒⠂⠂⠓⠂⠁⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⠀⠀⠀⠀⡳⡵⠀⢘⡇⠏⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⠀⠀⠀⠀⠀⠘⡴⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢥⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⠀⠀⠀⠀⠀⣰⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⠀⠀⠀⠀⠀⠀⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⡇⠈⠁⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⢰⠛⠋⠉⠁⢹⠀⠀⠀⠀⢸⠉⠉⠉⠉⠁⠀⡃⠀⠀⠀⠰⡠⠤⠠⠒⠒⠒⠂⠂⠓⡇⠀⠈⠉⢻⠻⠦⢆⡄⡀⡀⢘⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⠀⠀⠀⠀⠀⢈⡄⠀⠀⠀⡄⠀⠀⠀⠀⠀⡃⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠇⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⢘⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⠀⠀⠀⠀⠀⣗⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⡇⠀⠀⠀⠸⡀⠀⠀⠀⠀⠀⠇⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⣸⠀⠀⠀                   " << endl;
    cout << "   ⠀⠀⠀⠀⠀⠀⡏⠀⠀⠀⠀⡃⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⡃⠀⠀⠀⠀⢀⠇⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⢸⠀⠀ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀    " << endl;
    cout << "   ⠀⠀⠀⠀⣠⠠⠄⠀⠀⠀⠀⡘⣀⡀⠀⠀⠀⡇⠀⠀⠀⠀⠅⠀⠀⠀⠀⢸⡇⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⣟⠀⠀⠀⢘⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⠀⡜⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡆⣷⠋⠀⠛⠀⠀⠀⠚⠉⠉⠯⣷⣀⡘⠁⠀⠀⠀⠗⠒⠑⣆⠀⠀⠀⣤⠖⠒⠂⠁⠀⠀⢽⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⠀⠛⠶⠖⠖⠀⠀⠀⠀⠀⢀⠶⠛⣟⢤⣀⣀⡀⠀⠀⠀⢠⡍⡎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⠇⠀⢇⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⣼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⠀⠀⠀⠀⠀⠫⡦⡄⢀⣸⠇⠀⠀⠀⠀⠀⠫⡓⠦⣄⣤⠏⠈⠳⠤⠴⣇⠀⠀⠀⢰⡏⠉⠉⠀⠀⠀⠀⠈⠉⠉⣭⠀⠀⠀⠀⢈⣓⠒⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠓⠦⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⡧⡀⠀⠀⠀⣃⡅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;

    return 0;
}


