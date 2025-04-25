/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 25 de abril de 2025, 08:49
 */

#include <cstdlib>
#include <time.h>
#include <string.h>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string a1, a2, a3, b1, b2, b3, c1, c2, c3, comput, player1, player2, choiceplayer1, choiceplayer2, choicemachine, ganhador;
    int choice, rodada, victory;

    a1, a2, a3, b1, b2, b3, c1, c2, c3 = " ";
    rodada = 1;
    victory = 0;

    cout << "_______________________________________\n\tJOGO DA VELHA\n_______________________________________\n\n Escolha o modo de jogo:\n\t1 - Player vs Player\n\t2 - Player vs Machine\n\n";
    cin >> choice;
    while (choice != 1 && choice != 2) {
        cout << "\nValor inválido inserido!!\n\n Escolha o modo de jogo:\n\t1 - Player vs Player\n\t2 - Player vs Machine\n\n";
        cin >> choice;
    }

    if (choice == 1) {
        cout << "\nPlayer 1 selecione o seu símbolo.\nDigite X ou O:\n";
            cin >> player1;
            while (player1 != "X" && player1 != "O") {
                cout << "\nValor Inválido inserido!!\n\nPlayer 1 selecione o seu símbolo.\nDigite X ou O:\n";
                cin >> player1;
            }
            if (player1 == "X") {
                player2 = "O";
            } else if (player1 == "O") {
                player2 = "X";
            }
            cout << "\nPlayer 1 = " << player1 << "\nPlayer 2 = " << player2;
        while (victory == 0) {
            cout << "\n\nRODADA " << rodada << "\n\n";
            cout << "\t   1      2      3   \n\n\t      |      |      \nA\t   " << a1 << "   |   " << a2 << "   |  " << a3 << "   \n\t______|______|______\n\t      |      |      \nB\t   " << b1 << "   |   " << b2 << "   |  " << b3 << "    \n\t______|______|______\n\t      |      |      \nC\t   " << c1 << "   |   " << c2 << "   |  " << c3 << "   \n\t      |      |      \n\n";
            cout << "\nPlayer 1 - Digite a posição que deseja escolher:\n";
            cin >> choiceplayer1;

            while (choiceplayer1 == "A1" && a1 == "X" && a1 == "O" || choiceplayer1 == "A2" && a2 == "X" && a2 == "O" || choiceplayer1 == "A3" && a3 == "X" && a3 == "O" || choiceplayer1 == "B1" && b1 == "X" && b1 == "O" || choiceplayer1 == "B2" && b2 == "X" && b2 == "O" || choiceplayer1 == "B3" && b3 == "X" && b3 == "O" || choiceplayer1 == "C1" && c1 == "X" && c1 == "O" || choiceplayer1 == "C2" && c2 == "X" && c2 == "O" || choiceplayer1 == "C3" && c3 == "X" && c3 == "O") {
                cout << "\nCasa selecionada já está ocupada, selecione outra!\n\n";
                cout << "\t   1      2      3   \n\n\t      |      |      \nA\t   " << a1 << "   |   " << a2 << "   |  " << a3 << "   \n\t______|______|______\n\t      |      |      \nB\t   " << b1 << "   |   " << b2 << "   |  " << b3 << "    \n\t______|______|______\n\t      |      |      \nC\t   " << c1 << "   |   " << c2 << "   |  " << c3 << "   \n\t      |      |      \n\n";
                cout << "\nPlayer 1 - Digite a posição que deseja escolher:\n";
                cin >> choiceplayer1;
            }

            if (choiceplayer1 == "A1" && a1 != "X" && a1 != "O") {
                a1 = player1;
            } else if (choiceplayer1 == "A2" && a2 != "X" && a2 != "O") {
                a2 = player1;
            } else if (choiceplayer1 == "A3" && a3 != "X" && a3 != "O") {
                a3 = player1;
            } else if (choiceplayer1 == "B1" && b1 != "X" && b1 != "O") {
                b1 = player1;
            } else if (choiceplayer1 == "B2" && b2 != "X" && b2 != "O") {
                b2 = player1;
            } else if (choiceplayer1 == "B3" && b3 != "X" && b3 != "O") {
                b3 = player1;
            } else if (choiceplayer1 == "C1" && c1 != "X" && c1 != "O") {
                c1 = player1;
            } else if (choiceplayer1 == "C2" && c2 != "X" && c2 != "O") {
                c2 = player1;
            } else if (choiceplayer1 == "C3" && c3 != "X" && c3 != "O") {
                c3 = player1;
            }

            if (a1 == player1 && a2 == player1 && a3 == player1 || b1 == player1 && b2 == player1 && b3 == player1 || c1 == player1 && c2 == player1 && c3 == player1 || a1 == player1 && b2 == player1 && c3 == player1 || c1 == player1 && b2 == player1 && a3 == player1 || a1 == player1 && b1 == player1 && c1 == player1 || a2 == player1 && b2 == player1 && c2 == player1 || a3 == player1 && b3 == player1 && c3 == player1) {
                ganhador = "Player 1";
                break;
            }

            cout << "\t   1      2      3   \n\n\t      |      |      \nA\t   " << a1 << "   |   " << a2 << "   |  " << a3 << "   \n\t______|______|______\n\t      |      |      \nB\t   " << b1 << "   |   " << b2 << "   |  " << b3 << "    \n\t______|______|______\n\t      |      |      \nC\t   " << c1 << "   |   " << c2 << "   |  " << c3 << "   \n\t      |      |      \n\n";
            cout << "\nPlayer 2 - Digite a posição que deseja escolher:\n";
            cin >> choiceplayer2;

            while (choiceplayer2 == "A1" && a1 == "X" && a1 == "O" || choiceplayer2 == "A2" && a2 == "X" && a2 == "O" || choiceplayer2 == "A3" && a3 == "X" && a3 == "O" || choiceplayer2 == "B1" && b1 == "X" && b1 == "O" || choiceplayer2 == "B2" && b2 == "X" && b2 == "O" || choiceplayer2 == "B3" && b3 == "X" && b3 == "O" || choiceplayer2 == "C1" && c1 == "X" && c1 == "O" || choiceplayer2 == "C2" && c2 == "X" && c2 == "O" || choiceplayer2 == "C3" && c3 == "X" && c3 == "O") {
                cout << "\nCasa selecionada já está ocupada, selecione outra!\n\n";
                cout << "\t   1      2      3   \n\n\t      |      |      \nA\t   " << a1 << "   |   " << a2 << "   |  " << a3 << "   \n\t______|______|______\n\t      |      |      \nB\t   " << b1 << "   |   " << b2 << "   |  " << b3 << "    \n\t______|______|______\n\t      |      |      \nC\t   " << c1 << "   |   " << c2 << "   |  " << c3 << "   \n\t      |      |      \n\n";
                cout << "\nPlayer 2 - Digite a posição que deseja escolher:\n";
                cin >> choiceplayer2;
            }

            if (choiceplayer2 == "A1" && a1 != "X" && a1 != "O") {
                a1 = player2;
            } else if (choiceplayer2 == "A2" && a2 != "X" && a2 != "O") {
                a2 = player2;
            } else if (choiceplayer2 == "A3" && a3 != "X" && a3 != "O") {
                a3 = player2;
            } else if (choiceplayer2 == "B1" && b1 != "X" && b1 != "O") {
                b1 = player2;
            } else if (choiceplayer2 == "B2" && b2 != "X" && b2 != "O") {
                b2 = player2;
            } else if (choiceplayer2 == "B3" && b3 != "X" && b3 != "O") {
                b3 = player2;
            } else if (choiceplayer2 == "C1" && c1 != "X" && c1 != "O") {
                c1 = player2;
            } else if (choiceplayer2 == "C2" && c2 != "X" && c2 != "O") {
                c2 = player2;
            } else if (choiceplayer2 == "C3" && c3 != "X" && c3 != "O") {
                c3 = player2;
            }

            if (a1 == player2 && a2 == player2 && a3 == player2 || b1 == player2 && b2 == player2 && b3 == player2 || c1 == player2 && c2 == player2 && c3 == player2 || a1 == player2 && b2 == player2 && c3 == player2 || c1 == player2 && b2 == player2 && a3 == player2 || a1 == player2 && b1 == player2 && c1 == player2 || a2 == player2 && b2 == player2 && c2 == player2 || a3 == player2 && b3 == player2 && c3 == player2) {
                ganhador = "Player 2";
                break;
            }
            
            cout << "\t   1      2      3   \n\n\t      |      |      \nA\t   " << a1 << "   |   " << a2 << "   |  " << a3 << "   \n\t______|______|______\n\t      |      |      \nB\t   " << b1 << "   |   " << b2 << "   |  " << b3 << "    \n\t______|______|______\n\t      |      |      \nC\t   " << c1 << "   |   " << c2 << "   |  " << c3 << "   \n\t      |      |      \n\n";
            rodada++;
        }






    } else {
        
    }

    
    
    return 0;
}

