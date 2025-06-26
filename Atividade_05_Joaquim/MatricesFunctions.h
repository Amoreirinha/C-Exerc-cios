#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <stdio.h>
#include <time.h> // Biblioteca para geração de números aleatórios

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

void geramatriz(int *matriz, int tam){
    cout << "Gerando matriz de " << tam << " x " << tam << " com valores aleatórios..." << endl << endl;
    cout << "Digite os valores mínimo e máximo para a geração dos números:" << endl;
    cout << "A matriz será preenchida com números inteiros entre esses valores." << endl << endl;
    srand(time(NULL));
    int inf,max;
    cout << "Qual o menor valor que quer gerar?" << endl;
    cin >> inf;
    cout << "Qual o maior valor que quer gerar?" << endl;
    cin >> max;
    while (max < inf) {
        setColor(1, 31); // Define a cor do texto para vermelho
        cout << "O maior valor deve ser maior ou igual ao menor valor. Tente novamente." << endl;
        resetColor(); // Reseta a cor do texto para o padrão
        cout << "Qual o maior valor que quer gerar?" << endl;
        cin >> max;
    }

    for(int *i = matriz; i < matriz + tam * tam; i++){
        *i = ((rand() % (max - inf + 1)) + inf);
    }
}

void mostramatriz(int *matriz, int tam){
    for(int *i = matriz; i < matriz + tam * tam; i++){
        cout << *i << "\t";
        if((i - matriz + 1) % tam == 0) cout << endl;
    }
}

void salvamatriz(int *matrizoriginal, int *matrizasalvar, int tam) {
    setColor(5,96); // Define a cor do texto para azul claro
    cout << "Salvando matriz..." << endl;
    resetColor(); // Reseta a cor do texto para o padrão
    for (int *i = matrizoriginal, *j = matrizasalvar; i < matrizoriginal + tam * tam; i++, j++) {
        *j = *i; // Copia os valores da matriz original para a matriz a salvar
    }
}

void multiplicamatriz(int *matriz, int *matriz_multiplicada, int tam, int valor){
    for (int *i = matriz, *j = matriz_multiplicada; i < matriz + tam * tam; i++, j++) {
        *j = *i; // Copia os valores da matriz original para a matriz a salvar
    }
    setColor(5,96); // Define a cor do texto para azul claro
    cout << "Multiplicando matriz por " << valor << "..." << endl;
    resetColor(); // Reseta a cor do texto para o padrão
    for(int *i = matriz_multiplicada; i < matriz + tam * tam; i++){
        *i = (*i) * valor;
    }
}

void transposamatriz(int *matriz, int *transposta, int tam) {
    setColor(5,96); // Define a cor do texto para azul claro
    cout << "Calculando matriz transposta..." << endl;
    resetColor(); // Reseta a cor do texto para o padrão
    for (int *i = matriz, *t = transposta; i < matriz + tam * tam; i += tam, t++) {
        for (int *j = i, *k = t; j < i + tam; j++, k += tam) {
            *k = *j;
        }
    }
}

void invertercolunas(int *matriz, int *coluna_inversa, int tam) {
    setColor(5,96); // Define a cor do texto para azul claro
    cout << "Invertendo colunas..." << endl;
    resetColor(); // Reseta a cor do texto para o padrão
    // A matriz original é percorrida linha por linha
    // A matriz de destino é preenchida coluna por coluna, mas invertendo a ordem das colunas
    // A matriz de destino é preenchida de trás para frente, começando do final da primeira linha e avançando para o início da próxima linha invertida.
    // Ponteiro para início da matriz de destino
    int *dst = coluna_inversa + tam - 1; // Começa do final da primeira linha
    // Copia invertendo as colunas
    for (int *linha = matriz; linha < matriz + tam * tam; linha += tam) {
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
}


void inverterlinhas(int *matriz, int *linha_inversa, int tam) {
    /*
    * Função: inverterlinhas
    * Descrição: Inverte a ordem das linhas de uma matriz quadrada usando apenas ponteiros
    * Parâmetros:
    *   - matriz: Ponteiro para a matriz original
    *   - linha_inversa: Ponteiro para a matriz que receberá o resultado invertido
    *   - tam: Tamanho da matriz (número de linhas/colunas)
    * Observação: Não utiliza índices, apenas aritmética de ponteiros
    */
    setColor(5,96); // Define a cor do texto para azul claro
    cout << "Invertendo linhas..." << endl;
    resetColor(); // Reseta a cor do texto para o padrão
    
    // Ponteiro para escrever na matriz de destino - começa do final
    // linha_inversa + tam*(tam-1) aponta para o início da última linha
    int *dst = linha_inversa + tam * (tam - 1);
    
    // Percorre cada linha da matriz original
    for (int *linha = matriz; linha < matriz + tam * tam; linha += tam) {
        // Ponteiro para percorrer os elementos da linha atual
        int *elem = linha;
        
        // Copia todos os elementos da linha atual para a posição invertida
        while (elem < linha + tam) {
            *dst = *elem;  // Copia o elemento
            dst++;         // Avança na matriz de destino
            elem++;        // Avança na matriz original
        }
        
        // Após copiar uma linha completa, retrocede o ponteiro de destino
        // em duas linhas: uma para compensar o avanço durante a cópia
        // e outra para posicionar no início da próxima linha a ser preenchida
        dst -= 2 * tam;
    }
}

#endif // SORTING_H