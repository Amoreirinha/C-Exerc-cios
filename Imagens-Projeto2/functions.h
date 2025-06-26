#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <time.h>

using namespace std;

void LeituraPGM(int *imagem, int tam){
    ifstream file("cat.pgm");
    if (!file.is_open()) {
        cout << "Erro ao abrir o arquivo" << endl;
    }
    string descarte;
    getline(file, descarte); // Lê o cabeçalho P2 e descarta
    getline(file, descarte); // Lê as dimensões da imagem e descarta
    getline(file, descarte); // Lê o valor máximo de pixel e descarta

    for(int *i = imagem; i < imagem + tam * tam; i++){
        int pixel;
        file >> pixel; // Lê o valor do pixel
        *i = pixel; // Armazena o valor do pixel na imagem
    }
    file.close();
    cout << "Imagem lida com sucesso!" << endl;
}

void SalvandoPGM(int *imagem, int tam){
    time_t tempo_atual;
    struct tm *info_tempo;
    char buffer[15];
    char inicio_nome [24]= "ImagensDosProcessos/cat";
    char fim_nome [5]= ".pgm";

    // Obtém o tempo atual em segundos desde a época (1970-01-01)
    time(&tempo_atual);

    // Converte para uma estrutura tm (contém dia, mês, ano, hora, minuto, segundo)
    info_tempo = localtime(&tempo_atual);

    // Formata a data e hora em uma string legível
    strftime(buffer, sizeof(buffer), "%d%m%Y%H%M%S", info_tempo);

    char nome_arquivo[42];
    for (int i = 0; i < 22; i++){
        nome_arquivo[i] = inicio_nome[i];
    }

    for (int i = 22; i < 36; i++){
        nome_arquivo[i] = buffer[i-22];
    }

    for (int i = 36; i < 41; i++){
        nome_arquivo[i] = fim_nome[i-36];
    }
    nome_arquivo[41] = '\0'; // Garante o final da string



    ofstream file(nome_arquivo);
    if (!file.is_open()) {
        cout << "Erro ao abrir o arquivo para escrita" << endl;
        return;
    } else {
        file << "P2\n"; // Cabeçalho PGM
        file << tam << " " << tam << "\n"; // Dimensões da imagem
        file << "255\n"; // Valor máximo de pixel
        for(int *i = imagem; i < imagem + tam * tam; i++){
            file << *i << " "; // Escreve o valor do pixel
        }
        cout << "Imagem salva com sucesso!" << endl;
    }
    
    file.close();
}

void MostraValorPixel(int *imagem, int tam){
    for(int *i = imagem; i < imagem + tam * tam; i++){
        cout << *i << " "; // Exibe o valor do pixel
    }
}

void EscurecerImagem(int *imagem, int tam){
    cout << "Digite o valor de escurecimento (0-255): ";
    int valor;
    cin >> valor;
    while(valor < 0 || valor > 255) {
        cout << "Valor inválido. Digite um valor entre 0 e 255: ";
        cin >> valor;
    }
    cout << "Escurecendo a imagem..." << endl;
    for(int *i = imagem; i < imagem + tam * tam; i++){
        if (*i > 0) {
            if(*i < valor) {
                *i = 0; // Se o pixel for menor que o valor de escurecimento, torna-o preto
            } else {
                *i -= valor; // Caso contrário, subtrai o valor de escurecimento
            }
        }
    }
    cout << "Imagem escurecida com sucesso!" << endl;
}

void ClarearImagem(int *imagem, int tam){
    cout << "Digite o valor de clareamento (0-255): ";
    int valor;
    cin >> valor;
    while(valor < 0 || valor > 255) {
        cout << "Valor inválido. Digite um valor entre 0 e 255: ";
        cin >> valor;
    }
    cout << "Clareando a imagem..." << endl;
    for(int *i = imagem; i < imagem + tam * tam; i++){
        if (*i < 255) {
            if(*i + valor > 255) {
                *i = 255; // Se o pixel for menor que o valor de escurecimento, torna-o preto
            } else {
                *i += valor; // Caso contrário, subtrai o valor de escurecimento
            }
        }
    }
    cout << "Imagem clareada com sucesso!" << endl;
}


#endif // SORTING_H