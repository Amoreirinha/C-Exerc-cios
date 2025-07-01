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

// Função para ler uma imagem no formato PGM (Portable Graymap)
// Parâmetros:
// - imagem: ponteiro para armazenar os pixels da imagem
// - tam: dimensão da imagem (assume-se imagem quadrada: tam x tam)
void LeituraPGM(int *imagem, int tam) {
    // 1. ABERTURA DO ARQUIVO
    ifstream file("cat.pgm"); // Tenta abrir o arquivo "cat.pgm"
    if (!file.is_open()) { // Verifica se o arquivo foi aberto com sucesso
        cout << "Erro ao abrir o arquivo" << endl;
        return; // Sai da função se não conseguir abrir
    }

    string linha; // Variável para armazenar linhas lidas do arquivo
    bool cabecalho_lido = false; // Flag para controlar quando o cabeçalho foi processado

    // 2. LOOP PRINCIPAL DE LEITURA
    // Percorre todos os pixels da imagem (tam x tam)
    for(int *i = imagem; i < imagem + tam * tam; ) {
        // 2.1. LER PRÓXIMO TOKEN DO ARQUIVO
        if (!(file >> linha)) { // Tenta ler o próximo elemento
            break; // Se falhar (fim do arquivo), sai do loop
        }
        
        // 3. PROCESSAMENTO DO CABEÇALHO
        if (!cabecalho_lido) {
            // 3.1. VERIFICAÇÃO DO TIPO DE ARQUIVO (P2)
            if (linha == "P2") { // PGM ASCII deve começar com "P2"
                // Pula as próximas 3 linhas (dimensões e valor máximo)
                for(int j = 0; j < 3; j++) 
                    getline(file, linha); // Lê e descarta a linha completa
                continue; // Volta para o início do loop
            }
            // 3.2. TRATAMENTO DE COMENTÁRIOS
            else if (linha[0] == '#') {  // Linha começa com '#'
                getline(file, linha); // Lê e descarta o restante da linha de comentário
                continue; // Volta para o início do loop
            }
            else {
                cabecalho_lido = true; // Marca que o cabeçalho foi totalmente processado
            }
        }
        
        // 4. LEITURA DOS PIXELS
        // Se chegou aqui, deve ser um valor de pixel
        *i = stoi(linha); // Converte a string para inteiro
        i++; // Avança o ponteiro somente após ler um pixel válido
    }
    
    // 5. FINALIZAÇÃO
    file.close(); // Fecha o arquivo
}

void SalvandoPGM(int *imagem, int tam, string tipo){
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

    char nome_arquivo[43];
    for (int i = 0; i < 23; i++){
        nome_arquivo[i] = inicio_nome[i];
    }

    for (int i = 23; i < 37; i++){
        nome_arquivo[i] = buffer[i-23];
    }

    for (int i = 37; i < 42; i++){
        nome_arquivo[i] = fim_nome[i-37];
    }
    nome_arquivo[42] = '\0'; // Garante o final da string



    ofstream file(nome_arquivo);

    file << "P2\n"; // Cabeçalho PGM
    file << tam << " " << tam << "\n"; // Dimensões da imagem
    file << "255\n"; // Valor máximo de pixel
    file << tipo; // Escreve o tipo de imagem no cabeçalho
    for(int *i = imagem; i < imagem + tam * tam; i++){
        file << *i << " "; // Escreve o valor do pixel
    }
    cout << "Imagem salva com sucesso!" << endl;
    
    file.close();
}

void MostraValorPixel(int *imagem, int tam){
    for(int *i = imagem; i < imagem + tam * tam; i++){
        cout << *i << " "; // Exibe o valor do pixel
    }
}

void EscurecerImagem(int *imagem, int tam, int valor){
    for(int *i = imagem; i < imagem + tam * tam; i++){
        if (*i > 0) {
            if(*i < valor) {
                *i = 0; // Se o pixel for menor que o valor de escurecimento, torna-o preto
            } else {
                *i -= valor; // Caso contrário, subtrai o valor de escurecimento
            }
        }
    }
}

void ClarearImagem(int *imagem, int tam, int valor){
    for(int *i = imagem; i < imagem + tam * tam; i++){
        if (*i < 255) {
            if(*i + valor > 255) {
                *i = 255; // Se o pixel for menor que o valor de escurecimento, torna-o preto
            } else {
                *i += valor; // Caso contrário, subtrai o valor de escurecimento
            }
        }
    }
}

void NegativoImagem(int *imagem, int tam){
    for(int *i = imagem; i < imagem + tam * tam; i++){
        *i = 255 - *i; // Inverte o valor do pixel
    }
}

void BinarizarImagemLimiar(int *imagem, int tam, int valor){
    for(int *i = imagem; i < imagem + tam * tam; i++){
        if (*i >= valor) {
            *i = 255; // Se o pixel for maior ou igual ao valor de binarização, torna-o branco
        } else {
            *i = 0; // Caso contrário, torna-o preto     
        }
    }
}

void BinarizarImagemMedia(int *imagem, int tam){
    int soma = 0;
    for(int *i = imagem; i < imagem + tam * tam; i++){
        soma += *i; // Soma todos os valores dos pixels
    }
    int media = soma / (tam * tam); // Calcula a média dos pixels
    for(int *i = imagem; i < imagem + tam * tam; i++){
        if (*i >= media) {
            *i = 255; // Se o pixel for maior ou igual à média, torna-o branco
        } else {
            *i = 0; // Caso contrário, torna-o preto     
        }
    }
}

void RotacaoEsquerda(int *matriz, int tam) {
    // Matriz temporária para armazenar o resultado
    int temp[tam][tam];
    // Ponteiro para a primeira posição da matriz temporária
    int *pStart = &temp[0][0];

    // Percorre a matriz original coluna por coluna (da direita para esquerda)
    for (int *colStart = matriz + tam - 1; colStart >= matriz; colStart--) {
        // Ponteiro que percorre a coluna atual (de cima para baixo)
        int *src = colStart;
        // Ponteiro que escreve na linha atual da matriz temporária
        int *dst = pStart;
        for (int *end_col = src + tam * tam; src < end_col; src += tam) {
            *dst++ = *src; // Copia o pixel para a posição rotacionada
        }
        // Avança para a próxima linha na matriz temporária
        pStart += tam;
    }
    // Copia de volta para a matriz original
    int *src = &temp[0][0];
    int *dst = matriz;
    for (int *end = src + tam * tam; src < end;) {
        *dst++ = *src++;
    }
}

void RotacaoDireita(int *matriz, int tam) {
    // Matriz temporária para armazenar o resultado
    int temp[tam][tam];
    // Ponteiro para a primeira posição da matriz temporária
    int *pStart = &temp[0][0];
    // Percorre a matriz original coluna por coluna (da esquerda para direita)
    for (int *colStart = matriz; colStart < matriz + tam; colStart++) {
        // Ponteiro que percorre a coluna atual (de baixo para cima)
        int *src = colStart + tam * (tam - 1);
        // Ponteiro que escreve na linha atual da matriz temporária
        int *dst = pStart;
        for (int *colEnd = colStart - tam; src > colEnd; src -= tam) {
            *dst++ = *src; // Copia o pixel para a posição rotacionada
        }
        // Avança para a próxima linha na matriz temporária
        pStart += tam;
    }
    // Copia de volta para a matriz original
    int *src = &temp[0][0];
    int *dst = matriz;
    for (int *end = src + tam * tam; src < end;) {
        *dst++ = *src++;
    }
}

void RotacaoVertical(int *imagem, int tam) {
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
}

void RotacaoHorizontal(int *imagem, int tam) {
    int rotacao[tam][tam] = {0}; // Matriz auxiliar para armazenar a rotação
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
}

// Função para reduzir uma imagem grande para um ícone menor
// Parâmetros:
// - imagem: ponteiro para a matriz de pixels da imagem original (formato linear)
// - icone: ponteiro para armazenar a imagem reduzida
// - tam: tamanho da imagem original (assume-se quadrada: tam × tam)
// - icon_tam: tamanho desejado para o ícone (ex: 64 para 64×64)
void IconizarImagem(int *imagem, int *icone, int tam, int icon_tam) {
    // Calcula o fator de redução (quantos pixels originais representarão 1 pixel no ícone)
    // Exemplo: para reduzir 1024×1024 para 64×64, fator = 1024/64 = 16
    int fator = tam / icon_tam;

    // Loop 1: Percorre as linhas da imagem original em passos de 'fator' linhas
    // - i avança de bloco em bloco vertical (cada salto = tam*fator pixels)
    for(int *i = imagem; i < imagem + tam * tam; i += tam * fator) {
        
        // Loop 2: Percorre as colunas dentro da linha atual em passos de 'fator' pixels
        // - j avança horizontalmente dentro do bloco atual
        for(int *j = i; j < i + tam; j += fator) {
            int soma = 0; // Zera a soma para cada novo bloco
            
            // Loop 3: Percorre as colunas de um bloco fator×fator
            // - k controla a coluna dentro do bloco atual
            for(int *k = j; k < j + fator; k++) {
                
                // Loop 4: Percorre as linhas dentro do bloco atual
                // - l avança verticalmente (pula 'tam' pixels para descer uma linha)
                for(int *l = k; l < k + tam * fator; l += tam) {
                    soma += *l; // Acumula o valor de cada pixel do bloco
                }
            }
            
            // Calcula a média dos valores do bloco:
            // - Divide a soma total pelo número de pixels no bloco (fator²)
            // - Armazena o resultado no ícone
            *icone = soma / (fator * fator);
            
            // Avança para a próxima posição no array do ícone
            icone++;
        }
    }
}

#endif // SORTING_H