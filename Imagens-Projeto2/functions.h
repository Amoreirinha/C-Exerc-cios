#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <time.h>

using namespace std;

void limpartela(){
    cout << "\033[2J\033[1;1H";  // Limpa a tela do terminal
}

void setColor(int estilo, int corTexto, int corFundo = -1) {
    if (corFundo == -1)
        printf("\033[%d;%dm", estilo, corTexto);      // Sem fundo
    else
        printf("\033[%d;%d;%dm", estilo, corTexto, corFundo); // Com fundo
}

void resetColor() {
    printf("\033[0m");
}

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

void NegativoImagem(int *imagem, int tam){
    cout << "Gerando negativo da imagem..." << endl;
    for(int *i = imagem; i < imagem + tam * tam; i++){
        *i = 255 - *i; // Inverte o valor do pixel
    }
    cout << "Negativo gerado com sucesso!" << endl;
}

void BinarizarImagem(int *imagem, int tam){
    cout << "Digite 1 para binarizar de acordo com um valor fixo ou 2 para binarizar de acordo com a média dos pixels: ";
    int escolha;
    cin >> escolha;
    while(escolha != 1 && escolha != 2) {
        cout << "Escolha inválida. Digite 1 para binarizar de acordo com um valor fixo ou 2 para binarizar de acordo com a média dos pixels: ";
        cin >> escolha;
    }
    if(escolha == 1){
        cout << "Digite o valor de binarização (0-255): ";
        int valor;
        cin >> valor;
        while(valor < 0 || valor > 255) {
            cout << "Valor inválido. Digite um valor entre 0 e 255: ";
            cin >> valor;

        }
        cout << "Binarizando a imagem com valor fixo..." << endl;
        for(int *i = imagem; i < imagem + tam * tam; i++){
            if (*i >= valor) {
                *i = 255; // Se o pixel for maior ou igual ao valor de binarização, torna-o branco
            } else {
                *i = 0; // Caso contrário, torna-o preto     
            }
        }
    } else {
        int soma = 0;
        for(int *i = imagem; i < imagem + tam * tam; i++){
            soma += *i; // Soma todos os valores dos pixels
        }
        int media = soma / (tam * tam); // Calcula a média dos pixels
        cout << "Média dos pixels: " << media << endl;
        cout << "Binarizando a imagem com base na média..." << endl;
        for(int *i = imagem; i < imagem + tam * tam; i++){
            if (*i >= media) {
                *i = 255; // Se o pixel for maior ou igual à média, torna-o branco
            } else {
                *i = 0; // Caso contrário, torna-o preto     
            }
        }
    }
}

void RotacaoEsquerda(int *matriz, int tam) {
    int rotacao[tam][tam] = {0}; // Matriz auxiliar para armazenar a rotação
    cout << "Realizando Rotação de 90° sentido anti-horário (Esquerda)..." << endl;
    for (int *i = matriz, *t = &rotacao[0][0]; i < matriz + tam * tam; i += tam, t++) {
        for (int *j = i, *k = t; j < i + tam; j++, k += tam) {
            *k = *j;
        }
    }
    // Copia a matriz rotacionada de volta para a matriz original
    for (int *i = matriz, *k = &rotacao[0][0]; i < matriz + tam * tam; i++, k++) {
        *i = *k;
    }
    cout << "Rotação concluída com sucesso!" << endl;
}

void RotacaoDireita(int *matriz, int tam) {
    int rotacao[tam][tam] = {0}; // Matriz auxiliar para armazenar a rotação
    cout << "Realizando Rotação de 90° sentido horário (Direita)..." << endl;
    for (int *i = matriz, *t = &rotacao[0][0] + tam * tam; i < matriz + tam * tam; i += tam, t--) {
        for (int *j = i, *k = t; j < i + tam; j++, k -= tam) {
            *k = *j;
        }
    }
    // Copia a matriz rotacionada de volta para a matriz original
    for (int *i = matriz, *k = &rotacao[0][0]; i < matriz + tam * tam; i++, k++) {
        *i = *k;
    }
    cout << "Rotação concluída com sucesso!" << endl;
}

void RotacaoVertical(int *imagem, int tam) {
    cout << "Rotacionando no eixo vertical..." << endl;
    int rotacao[tam][tam] = {0}; // Matriz auxiliar para armazenar a rotação
    // A matriz original é percorrida linha por linha
    // A matriz de destino é preenchida coluna por coluna, mas invertendo a ordem das colunas
    // A matriz de destino é preenchida de trás para frente, começando do final da primeira linha e avançando para o início da próxima linha invertida.
    // Ponteiro para início da matriz de destino
    int *dst = &rotacao[0][0] + tam - 1; // Começa do final da primeira linha
    // Copia invertendo as colunas
    for (int *linha = imagem; linha < imagem + tam * tam; linha += tam) {
        for (int *elem = linha; elem < linha + tam; elem++) {
            *dst = *elem;
            // Avança o ponteiro de destino de trás para frente
            if (elem < linha + tam - 1) {
                dst--;
            } else {
                dst += 2 * tam - 1; // Pula para o início da próxima linha invertida
            }
        }
    }
    // Copia a matriz rotacionada de volta para a matriz original
    for (int *i = imagem, *k = &rotacao[0][0]; i < imagem + tam * tam; i++, k++) {
        *i = *k;
    }
    cout << "Colunas invertidas com sucesso!" << endl;
}

void RotacaoHorizontal(int *imagem, int tam) {
    int rotacao[tam][tam] = {0}; // Matriz auxiliar para armazenar a rotação
    cout << "Invertendo linhas..." << endl;
    int *dst = &rotacao[0][0] + tam * (tam - 1);

    // Percorre cada linha da matriz original
    for (int *linha = imagem; linha < imagem + tam * tam; linha += tam) {
        int *elem = linha;
        while (elem < linha + tam) {
            *dst = *elem;  // Copia o elemento
            dst++;         // Avança na matriz de destino
            elem++;        // Avança na matriz original
        }
        dst -= 2 * tam;
    }
    // Copia a matriz rotacionada de volta para a matriz original
    for (int *i = imagem, *k = &rotacao[0][0]; i < imagem + tam * tam; i++, k++) {
        *i = *k;
    }
    cout << "Linhas invertidas com sucesso!" << endl;       
}

#endif // SORTING_H