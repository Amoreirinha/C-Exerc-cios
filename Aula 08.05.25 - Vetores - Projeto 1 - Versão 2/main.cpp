/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 8 de maio de 2025, 12:36
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>


using namespace std;

/*
 * 
 */
void lerarquivo(vector<float> alturas){
    // Declaração do vetor
    vector<float> alturas; // Vetor dinâmico

    // Declaração e inicialização de variáveis
    float valor;

    ifstream arquivo_alturas("alturas.txt");

    if (!arquivo_alturas.is_open()) {
        cout << "\nErro: Arquivo não encontrado.\n";
        return 1;
    }

    // Leitura dos valores
    while (true) {
        arquivo_alturas >> valor;

        if (valor == 0) {
            break;
        }

        alturas.push_back(valor); // Adiciona o valor ao vetor
    }
    
    return alturas;
}

void mostraralturas() {
    // Declaração do vetor
    vector<float> alturas; // Vetor dinâmico

    // Declaração e inicialização de variáveis
    float valor;

    ifstream arquivo_alturas("alturas.txt");

    if (!arquivo_alturas.is_open()) {
        cout << "\nErro: Arquivo não encontrado.\n";
        return;
    }

    // Leitura dos valores
    while (true) {
        arquivo_alturas >> valor;

        if (valor == 0) {
            break;
        }

        alturas.push_back(valor); // Adiciona o valor ao vetor
    }

    // Exibição dos valores lidos
    for (int i = 0; i < alturas.size(); i++) {
        cout << "A altura " << (i + 1) << "° valor é " << alturas[i] << endl;
    }

    arquivo_alturas.close();
}

void geraaltura() {
    float num;
    int quant;
    string loopquest = "x";

    ofstream alturas("alturas.txt");

    if (!alturas.is_open()) {
        cout << "\nErro: Arquivo não encontrado.\n";
        return;
    }

    // Inicializa gerador de números aleatórios
    srand(time(NULL));

    cout << "Bem vindo ao gerador de números inteiros!" << endl << "Quantos números quer gerar?" << endl;
    cin >> quant;

    while (quant > 0) {
        num = ((rand() % (230 - 30 + 1)) + 30)*0.01;
        alturas << num << endl;
        quant--;
    }

    alturas << 0;

    alturas.close();


    cout << "Gostaria de Visualizar as alturas geradas? Digite 's' para SIM e 'n' para NÃO:\n";
    cin >> loopquest;

    while (loopquest != "s" && loopquest != "n") {
        cout << "\n\nVALOR INVÁLIDO INSERIDO\n\n";
        cout << "Gostaria de Visualizar as alturas geradas? Digite 's' para SIM e 'n' para NÃO:\n";
        cin >> loopquest;
    }

    if (loopquest == "s") {
        mostraralturas();
    }
}

void media() {
    // Declaração do vetor
    vector<float> alturas = lerarquivo; // Vetor dinâmico

    // Declaração e inicialização de variáveis
    float soma = 0, media;
    int contmedia = 0;

    for (float altura : alturas) {
        soma += altura;
    }

    //Media
    media = soma / alturas.size();
    cout << "Média das alturas: " << media << endl;
}

void mediaanalise() {
    // Declaração do vetor
    vector<float> alturas; // Vetor dinâmico
    vector<float> acimamedias;

    // Declaração e inicialização de variáveis
    float soma = 0, media, valor, altin;
    int contmedia = 0, contmaioraltin = 0, contaltin = 0, contmenoraltin = 0;

    ifstream arquivo_alturas("alturas.txt");

    if (!arquivo_alturas.is_open()) {
        cout << "\nErro: Arquivo não encontrado.\n";
        return;
    }

    // Leitura dos valores
    while (true) {
        arquivo_alturas >> valor;

        if (valor == 0) {
            break;
        }

        alturas.push_back(valor); // Adiciona o valor ao vetor
        soma += valor;
    }

    //Media
    media = soma / alturas.size();

    // Contagem de valores acima da média
    for (float altura : alturas) {
        if (altura > media) {
            contmedia++;
            acimamedias.push_back(altura);
        }
    }
    cout << "Média das alturas: " << media << endl;
    cout << "Quantidade de valores acima da média: " << contmedia << endl << endl;

    for (int i = 0; i < acimamedias.size(); i++) {
        cout << "A " << (i + 1) << "ª altura maior que a média tem valor " << acimamedias[i] << endl;
    }

    arquivo_alturas.close();
}

void valorespecifico() {
    // Declaração do vetor
    vector<float> alturas; // Vetor dinâmico
    vector<float> acimamedias;

    // Declaração e inicialização de variáveis
    float valor, altin;
    int contmaioraltin = 0, contaltin = 0, contmenoraltin = 0;

    ifstream arquivo_alturas("alturas.txt");

    if (!arquivo_alturas.is_open()) {
        cout << "\nErro: Arquivo não encontrado.\n";
        return;
    }

    // Leitura dos valores
    while (true) {
        arquivo_alturas >> valor;

        if (valor == 0) {
            break;
        }

        alturas.push_back(valor); // Adiciona o valor ao vetor
    }
    //Busca por valores específicos

    cout << "Digite um valor de altura para ser analisado \n";
    cin >> altin;
    for (float altura : alturas) {
        if (altura > altin) {
            contmaioraltin++;
        } else if (altura < altin) {
            contmenoraltin++;
        } else if (altura == altin) {
            contaltin++;
        }
    }
    cout << "Existem " << contmaioraltin << " alturas maiores que " << altin << endl;
    cout << "Existem " << contmenoraltin << " alturas menores que " << altin << endl;
    cout << "Existem " << contaltin << " alturas iguais que " << altin << endl;

    arquivo_alturas.close();
}

void faixavalores() {
    // Declaração do vetor
    vector<float> alturas; // Vetor dinâmico

    // Declaração e inicialização de variáveis
    float valor, maior, menor;
    int contmaior = 0, contigual = 0, contmenor = 0;

    ifstream arquivo_alturas("alturas.txt");

    if (!arquivo_alturas.is_open()) {
        cout << "\nErro: Arquivo não encontrado.\n";
        return;
    }

    // Leitura dos valores
    while (true) {
        arquivo_alturas >> valor;

        if (valor == 0) {
            break;
        }

        alturas.push_back(valor); // Adiciona o valor ao vetor
    }
    //Busca por valores específicos

    cout << "Digite o menor valor de altura para ser analisado: \n";
    cin >> menor;
    cout << "Digite o maior valor de altura para ser analisado: \n";
    cin >> maior;

    for (float altura : alturas) {
        if (altura > maior) {
            contmaior++;
        } else if (altura < menor) {
            contmenor++;
        } else if (altura >= menor && altura <= maior) {
            contigual++;
        }
    }
    cout << "Existem " << contmaior << " alturas maiores que " << maior << endl;
    cout << "Existem " << contmenor << " alturas menores que " << menor << endl;
    cout << "Existem " << contigual << " alturas entre " << menor << " e " << maior << endl;

    arquivo_alturas.close();
}

void menu() {
    int choice;
    cout << "Selecione a ação a ser feita:\n\t1 - Gerar alturas\n\t2 - Calcular Média\n\t3 - Analisar alturas de acordo com uma altura específica\n\t4 - Analisar alturas de acordo com uma faixa de alturas específica\n\t5 - Analisar alturas de acordo com a média\n\nDigite sua escolha:\n";
    cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) {
        cout << "\n\nVALOR INVÁLIDO INSERIDO\n\n";
        cout << "Selecione a ação a ser feita:\n\t1 - Gerar alturas\n\t2 - Calcular Média\n\t3 - Analisar alturas de acordo com uma altura específica\n\t4 - Analisar alturas de acordo com uma faixa de alturas específica\n\t5 - Analisar alturas de acordo com a média\n\nDigite sua escolha:\n";
        cin >> choice;
    }
    if (choice == 1) {
        geraaltura();
    } else if (choice == 2) {
        media();
    } else if (choice == 3) {
        valorespecifico();
    } else if (choice == 4) {
        faixavalores();
    } else if (choice == 5) {
        mediaanalise();
    }
}

int main(int argc, char** argv) {
    
    lerarquivo();

    menu();

    string loopquest = "x";

    while (loopquest != "n") {
        cout << "\nGostaria de voltar ao menu? Digite 's' para SIM e 'n' para NÃO\n";
        cin >> loopquest;
        while (loopquest != "s" && loopquest != "n") {
            cout << "\n\nVALOR INVÁLIDO INSERIDO\n\n";
            cout << "\nGostaria de voltar ao menu? Digite 's' para SIM e 'n' para NÃO\n";
            cin >> loopquest;
        }
        if (loopquest == "s") {
            menu();
        }
    }

    cout << "\n\nAdeus\n\n";

    return 0;
}