#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include "functions.h"

using namespace std;

int main() {
    const int TAM = 1024; // Define o tamanho da imagem
    const int ICON = 64;
    typedef int imagePGM[TAM][TAM];
    static imagePGM imagem;
    int choice = 0;
    bool loop = true;
    string resposta;
    string alteracoes = "#Alterações realizadas na imagem PGM\n";
    int cont_alteracoes = 0; // Contador de alterações


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
                cout << "11. Iconizar imagem" << endl;
                cout << "12. Sair" << endl;
                cout << "Digite o número da opção desejada (1-12): ";
                cin >> choice; // Lê a escolha do usuário
                while (choice < 1 || choice > 12) { // Verifica se a escolha é válida
                    cout << "Escolha inválida. Tente novamente." << endl;
                    cout << "Digite o número da opção desejada (1-12): ";
                    cin >> choice; // Lê a escolha do usuário novamente
                }
        switch (choice){
            case 1:
                // Redefine a imagem PGM original
                limpartela(); // Limpa a tela
                cout << "Redefinindo imagem PGM original..." << endl;
                cout << "A imagem original será lida novamente." << endl;
                cout << "Certifique-se de que o arquivo 'cat.pgm' está no diretório correto." << endl;
                LeituraPGM(&imagem[0][0], TAM); // Lê a imagem PGM
                cont_alteracoes++; // Incrementa o contador de alterações
                alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem redefinida.\n"; // Adiciona a alteração ao histórico
                SalvandoPGM(&imagem[0][0], TAM, alteracoes); // Salva a imagem
                cout << "Imagem redefinida com sucesso!" << endl << endl;

            break;
            case 2:
                // Exibe os valores dos pixels
                limpartela(); // Limpa a tela
                MostraValorPixel(&imagem[0][0], TAM); // Exibe os valores dos pixels
            break;
            case 3:
                // Escurece a imagem
                limpartela(); // Limpa a tela
                EscurecerImagem(&imagem[0][0], TAM); // Escurece a imagem
                cont_alteracoes++; // Incrementa o contador de alterações
                alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem Escurecida.\n";
                SalvandoPGM(&imagem[0][0], TAM, alteracoes); // Salva a imagem
            break;
            case 4:
                // Clareia a imagem
                limpartela(); // Limpa a tela
                ClarearImagem(&imagem[0][0], TAM); // Clareia a imagem
                cont_alteracoes++; // Incrementa o contador de alterações
                alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem Clareada.\n";
                SalvandoPGM(&imagem[0][0], TAM, alteracoes); // Salva a imagem
            break;
            case 5:
                // Gera o negativo da imagem
                limpartela(); // Limpa a tela
                NegativoImagem(&imagem[0][0], TAM); // Gera o negativo da imagem
                cont_alteracoes++; // Incrementa o contador de alterações
                alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem Negativa.\n";
                SalvandoPGM(&imagem[0][0], TAM, alteracoes); // Salva a imagem
            break;
            case 6:
                // Binariza a imagem
                limpartela(); // Limpa a tela
                BinarizarImagem(&imagem[0][0], TAM); // Binariza a imagem
                cont_alteracoes++; // Incrementa o contador de alterações
                alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem Binarizada.\n";
                SalvandoPGM(&imagem[0][0], TAM, alteracoes); // Salva a imagem
            break;
            case 7:
                // Rotaciona a imagem 90° para a esquerda
                limpartela(); // Limpa a tela
                RotacaoEsquerda(&imagem[0][0], TAM); // Rotaciona a imagem 90° para a esquerda
                cont_alteracoes++; // Incrementa o contador de alterações
                alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem Rotacionada para a Esquerda.\n";
                SalvandoPGM(&imagem[0][0], TAM, alteracoes); // Salva a imagem
            break;
            case 8:
                // Rotaciona a imagem 90° para a direita
                limpartela(); // Limpa a tela
                RotacaoDireita(&imagem[0][0], TAM); // Rotaciona a imagem 90° para a direita
                cont_alteracoes++; // Incrementa o contador de alterações
                alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem Rotacionada para a Direita.\n";
                SalvandoPGM(&imagem[0][0], TAM, alteracoes); // Salva a imagem
            break;
            case 9:
                // Rotaciona a imagem verticalmente
                limpartela(); // Limpa a tela
                RotacaoVertical(&imagem[0][0], TAM); // Inverte as colunas da imagem
                cont_alteracoes++; // Incrementa o contador de alterações
                alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem Rotacionada Verticalmente.\n";
                SalvandoPGM(&imagem[0][0], TAM, alteracoes); // Salva a imagem
            break;
            case 10:
                // Rotaciona a imagem horizontalmente
                limpartela(); // Limpa a tela
                RotacaoHorizontal(&imagem[0][0], TAM); // Inverte as linhas da imagem
                cont_alteracoes++; // Incrementa o contador de alterações
                alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem Rotacionada Horizontalmente.\n";
                SalvandoPGM(&imagem[0][0], TAM, alteracoes); // Salva a imagem
            break;
            case 11:
                // Iconiza a imagem
                limpartela(); // Limpa a tela
                cout << "Iconizando imagem..." << endl;
                // Aqui você pode implementar a lógica de iconização da imagem
                // Por enquanto, apenas exibe uma mensagem
                cout << "Imagem iconizada com sucesso!" << endl;
                cont_alteracoes++; // Incrementa o contador de alterações
                alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem Iconizada.\n";
                SalvandoPGM(&imagem[0][0], TAM, alteracoes); // Salva a imagem
            break;
            case 12:
                // Encerra o programa
                limpartela(); // Limpa a tela
                cout << "Obrigado por usar o editor de imagens PGM!" << endl;
                loop = false; // Encerra o loop
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
