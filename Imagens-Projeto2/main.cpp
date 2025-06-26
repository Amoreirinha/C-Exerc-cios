#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include "functions.h"

using namespace std;

int main(){
    const int TAM = 1024; // Define o tamanho da imagem
    typedef int imagePGM[TAM][TAM];
    imagePGM imagem;

    LeituraPGM(&imagem[0][0], TAM); // Lê a imagem PGM
    // MostraValorPixel(&imagem[0][0], TAM); // Exibe os valores dos pixels
    EscurecerImagem(&imagem[0][0], TAM); // Escurece a imagem
    SalvandoPGM(&imagem[0][0], TAM); // Salva a imagem modificada
    ClarearImagem(&imagem[0][0], TAM); // Clareia a imagem
    SalvandoPGM(&imagem[0][0], TAM); // Salva a imagem
    

    return 0;
}