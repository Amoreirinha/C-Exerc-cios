#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include "functions.h"

using namespace std;

int main() {
    const int TAM = 1024; // Define o tamanho da imagem
    typedef int imagePGM[TAM][TAM];
    static imagePGM imagem;
    int choice = 0;
    bool loop = true;
    string resposta;

    LeituraPGM(&imagem[0][0], TAM); // Lê a imagem PGM

    while(loop){
        limpartela(); // Limpa a tela
                cout << "Bem-vindo ao editor de imagens PGM!" << endl;
                cout << "Escolha uma opção:" << endl;
                cout << "1. Redefinir imagem PGM original" << endl;
                cout << "2. Exibir valores dos pixels" << endl;
                cout << "3. Escurecer imagem" << endl;
                cout << "4. Clarear imagem" << endl;
                cout << "5. Gerar negativo da imagem" << endl;
                cout << "6. Binarizar imagem" << endl;
                cout << "7. Rotacionar imagem 90° para a esquerda" << endl;
                cout << "8. Rotacionar imagem 90° para a direita" << endl;
                cout << "9. Rotação Vertical" << endl;
                cout << "10. Rotação Horizontal" << endl;
                cin >> choice; // Lê a escolha do usuário
                while (choice < 1 || choice > 10) { // Verifica se a escolha é válida
                    cout << "Escolha inválida. Tente novamente." << endl;
                    cin >> choice; // Lê a escolha do usuário novamente
                }
        switch (choice){
            case 1:
                limpartela(); // Limpa a tela       
                LeituraPGM(&imagem[0][0], TAM); // Lê a imagem PGM
                SalvandoPGM(&imagem[0][0], TAM); // Salva a imagem
            break;
            case 2:
                limpartela(); // Limpa a tela
                MostraValorPixel(&imagem[0][0], TAM); // Exibe os valores dos pixels
                SalvandoPGM(&imagem[0][0], TAM); // Salva a imagem
            break;
            case 3:
                limpartela(); // Limpa a tela
                EscurecerImagem(&imagem[0][0], TAM); // Escurece a imagem
                SalvandoPGM(&imagem[0][0], TAM); // Salva a imagem
            break;
            case 4:
                limpartela(); // Limpa a tela
                ClarearImagem(&imagem[0][0], TAM); // Clareia a imagem
                SalvandoPGM(&imagem[0][0], TAM); // Salva a imagem
            break;
            case 5:
                limpartela(); // Limpa a tela
                NegativoImagem(&imagem[0][0], TAM); // Gera o negativo da imagem
                SalvandoPGM(&imagem[0][0], TAM); // Salva a imagem
            break;
            case 6:
                limpartela(); // Limpa a tela
                BinarizarImagem(&imagem[0][0], TAM); // Binariza a imagem
                SalvandoPGM(&imagem[0][0], TAM); // Salva a imagem
            break;
            case 7:
                limpartela(); // Limpa a tela
                RotacaoEsquerda(&imagem[0][0], TAM); // Rotaciona a imagem 90° para a esquerda
                SalvandoPGM(&imagem[0][0], TAM); // Salva a imagem
            break;
            case 8:
                limpartela(); // Limpa a tela
                RotacaoDireita(&imagem[0][0], TAM); // Rotaciona a imagem 90° para a direita
                SalvandoPGM(&imagem[0][0], TAM); // Salva a imagem
            break;
            case 9:
                limpartela(); // Limpa a tela
                RotacaoVertical(&imagem[0][0], TAM); // Inverte as colunas da imagem
                SalvandoPGM(&imagem[0][0], TAM); // Salva a imagem
            break;
            case 10:
                limpartela(); // Limpa a tela
                RotacaoHorizontal(&imagem[0][0], TAM); // Inverte as linhas da imagem
                SalvandoPGM(&imagem[0][0], TAM); // Salva a imagem
            break;
        }
        cout << "Deseja voltar para o menu? Digite 's' para sim e 'n' para não: ";
        cin >> resposta;
        while (resposta != "s" && resposta != "n") { // Verifica se a resposta é válida
            cout << "Resposta inválida. Digite 's' para sim e 'n' para não: ";
            cin >> resposta; // Lê a resposta novamente
        }
        if (resposta == "n") {
            loop = false; // Encerra o loop se a resposta for diferente de 's'
        }
    }

    cout << "Saindo do programa..." << endl;

    return 0;
}
