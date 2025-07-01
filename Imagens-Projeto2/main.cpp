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
    typedef int iconPGM[ICON][ICON];
    static iconPGM icone;
    static imagePGM imagem;
    int choice = 0;
    bool loop = true;
    string resposta;
    string alteracoes = "#Alterações realizadas na imagem PGM\n";
    int cont_alteracoes = 0; // Contador de alterações
    int valor;
    int escolha;


    LeituraPGM(&imagem[0][0], TAM); // Lê a imagem PGM

    while(loop){
        limpartela(); // Limpa a tela
                setColor(1,35); // Roxo
                cout << "Bem-vindo ao editor de imagens PGM!" << endl;
                resetColor();
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
                    setColor(1,31); // Vermelho
                    cout << "Escolha inválida. Tente novamente." << endl;
                    resetColor();
                    cout << "Digite o número da opção desejada (1-12): ";
                    cin >> choice; // Lê a escolha do usuário novamente
                }
        switch (choice){
            case 1:
                // Redefine a imagem PGM original
                limpartela(); // Limpa a tela
                setColor(1,35);
                cout << "Redefinindo imagem PGM original..." << endl;
                resetColor();
                cout << "A imagem original será lida novamente." << endl;
                cout << "Certifique-se de que o arquivo 'cat.pgm' está no diretório correto." << endl;
                LeituraPGM(&imagem[0][0], TAM); // Lê a imagem PGM
                cont_alteracoes++; // Incrementa o contador de alterações
                alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem redefinida.\n"; // Adiciona a alteração ao histórico
                SalvandoPGM(&imagem[0][0], TAM, alteracoes); // Salva a imagem
                setColor(1,32);
                cout << "\n\nImagem redefinida com sucesso!" << endl << endl;
                resetColor();
            break;
            case 2:
                // Exibe os valores dos pixels
                limpartela(); // Limpa a tela
                setColor(1,35);
                cout << "Mostrando Pixels da imagem...\n\n";
                resetColor();
                MostraValorPixel(&imagem[0][0], TAM); // Exibe os valores dos pixels
                setColor(1,32);
                cout << "\n\nPixels da imagem mostrados com sucesso!" << endl << endl;
                resetColor();
            break;
            case 3:
                // Escurece a imagem
                limpartela(); // Limpa a tela
                setColor(1,35);
                cout << "Escurecer imagem...\n";
                resetColor();
                cout << "Digite o valor de escurecimento (0-255): ";
                cin >> valor;
                while(valor < 0 || valor > 255) {
                    setColor(1,31); // Vermelho
                    cout << "Valor inválido.";
                    resetColor();
                    cout << "Digite um valor entre 0 e 255: ";
                    cin >> valor;
                }
                cout << "Escurecendo a imagem..." << endl;
                EscurecerImagem(&imagem[0][0], TAM, valor); // Escurece a imagem
                cont_alteracoes++; // Incrementa o contador de alterações
                alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem Escurecida.\n";
                SalvandoPGM(&imagem[0][0], TAM, alteracoes); // Salva a imagem
                setColor(1,32);
                cout << "\n\nImagem escurecida com sucesso!" << endl << endl;
                resetColor();
            break;
            case 4:
                // Clareia a imagem
                limpartela(); // Limpa a tela
                setColor(1,35);
                cout << "Clarear imagem...\n";
                resetColor();
                cout << "Digite o valor de clareamento (0-255): ";
                cin >> valor;
                while(valor < 0 || valor > 255) {
                    setColor(1,31); // Vermelho
                    cout << "Valor inválido.";
                    resetColor();
                    cout << "Digite um valor entre 0 e 255: ";
                    cin >> valor;
                }
                cout << "Clareando a imagem..." << endl;
                ClarearImagem(&imagem[0][0], TAM, valor); // Clareia a imagem
                cont_alteracoes++; // Incrementa o contador de alterações
                alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem Clareada.\n";
                SalvandoPGM(&imagem[0][0], TAM, alteracoes); // Salva a imagem
                setColor(1,32);
                cout << "\n\nImagem clareada com sucesso!" << endl << endl;
                resetColor();
            break;
            case 5:
                // Gera o negativo da imagem
                limpartela(); // Limpa a tela
                setColor(1,35);
                cout << "Negativar imagem...\n";
                resetColor();
                cout << "Gerando negativo da imagem..." << endl;
                NegativoImagem(&imagem[0][0], TAM); // Gera o negativo da imagem
                cont_alteracoes++; // Incrementa o contador de alterações
                alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem Negativa.\n";
                SalvandoPGM(&imagem[0][0], TAM, alteracoes); // Salva a imagem
                setColor(1,32);
                cout << "\n\nImagem negativada com sucesso!" << endl << endl;
                resetColor();
            break;
            case 6:
                // Binariza a imagem
                limpartela(); // Limpa a tela
                setColor(1,35);
                cout << "Binarizar imagem...\n";
                resetColor();
                cout << "Digite 1 para binarizar de acordo com um valor limiar ou 2 para binarizar de acordo com a média dos pixels: ";
                cin >> escolha;
                while(escolha != 1 && escolha != 2) {
                    setColor(1,31); // Vermelho
                    cout << "Escolha inválida.";
                    resetColor();
                    cout << "Digite 1 para binarizar de acordo com um valor fixo ou 2 para binarizar de acordo com a média dos pixels: ";
                    cin >> escolha;
                }
                if (escolha == 1){
                    cout << "Digite o valor de binarização (0-255): ";
                    cin >> valor;
                    while(valor < 0 || valor > 255) {
                        cout << "Valor inválido.";
                        cout << "Digite um valor entre 0 e 255: ";
                        cin >> valor;
                    }
                    cout << "Binarizando a imagem de acordo com limiar..." << endl;
                    BinarizarImagemLimiar(&imagem[0][0], TAM, valor);
                    cont_alteracoes++; // Incrementa o contador de alterações
                    alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem Binarizada Limiar.\n";
                } else {
                    cout << "Binarizando a imagem de acordo com a média dos pixels...\n";
                    BinarizarImagemMedia(&imagem[0][0],TAM);
                    cont_alteracoes++; // Incrementa o contador de alterações
                    alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem Binarizada Média.\n";
                }                
                SalvandoPGM(&imagem[0][0], TAM, alteracoes); // Salva a imagem
                setColor(1,32);
                cout << "\n\nImagem binarizada com sucesso!" << endl << endl;
                resetColor();
            break;
            case 7:
                // Rotaciona a imagem 90° para a esquerda
                limpartela(); // Limpa a tela
                setColor(1,35);
                cout << "Rotacionar a imagem para a esquerda...\n";
                resetColor();
                cout << "Executando rotação 90° anti-horária..." << endl;
                RotacaoEsquerda(&imagem[0][0], TAM); // Rotaciona a imagem 90° para a esquerda
                cont_alteracoes++; // Incrementa o contador de alterações
                alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem Rotacionada para a Esquerda.\n";
                SalvandoPGM(&imagem[0][0], TAM, alteracoes); // Salva a imagem
                setColor(1,32);
                cout << "\n\nImagem rotacionada para a esquerda com sucesso!" << endl << endl;
                resetColor();
            break;
            case 8:
                // Rotaciona a imagem 90° para a direita
                limpartela(); // Limpa a tela
                setColor(1,35);
                cout << "Rotacionar a imagem para a direita...\n";
                resetColor();
                cout << "Executando rotação 90° horária..." << endl;
                RotacaoDireita(&imagem[0][0], TAM); // Rotaciona a imagem 90° para a direita
                cont_alteracoes++; // Incrementa o contador de alterações
                alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem Rotacionada para a Direita.\n";
                SalvandoPGM(&imagem[0][0], TAM, alteracoes); // Salva a imagem
                setColor(1,32);
                cout << "\n\nImagem rotacionada para a direita com sucesso!" << endl << endl;
                resetColor();
            break;
            case 9:
                // Rotaciona a imagem verticalmente
                limpartela(); // Limpa a tela
                setColor(1,35);
                cout << "Rotacionar a imagem verticalmente...\n";
                resetColor();
                cout << "Rotacionando no eixo vertical..." << endl;
                RotacaoVertical(&imagem[0][0], TAM); // Inverte as colunas da imagem
                cont_alteracoes++; // Incrementa o contador de alterações
                alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem Rotacionada Verticalmente.\n";
                SalvandoPGM(&imagem[0][0], TAM, alteracoes); // Salva a imagem
                setColor(1,32);
                cout << "\n\nImagem rotacionada verticalmente com sucesso!" << endl << endl;
                resetColor();
            break;
            case 10:
                // Rotaciona a imagem horizontalmente
                limpartela(); // Limpa a tela
                setColor(1,35);
                cout << "Rotacionar a imagem horizontalmente...\n";
                resetColor();
                cout << "Rotacionando no eixo horizontal..." << endl;
                RotacaoHorizontal(&imagem[0][0], TAM); // Inverte as linhas da imagem
                cont_alteracoes++; // Incrementa o contador de alterações
                alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem Rotacionada Horizontalmente.\n";
                SalvandoPGM(&imagem[0][0], TAM, alteracoes); // Salva a imagem
                setColor(1,32);
                cout << "\n\nImagem rotacionada horizontalmente com sucesso!" << endl << endl;
                resetColor();
            break;
            case 11:
                // Iconiza a imagem
                limpartela(); // Limpa a tela
                setColor(1,35);
                cout << "Iconizar a imagem...\n";
                resetColor();
                cout << "Iconizando imagem..." << endl;
                IconizarImagem(&imagem[0][0],&icone[0][0],TAM,ICON);
                cont_alteracoes++; // Incrementa o contador de alterações
                alteracoes += "#" + to_string(cont_alteracoes) + " - Imagem Iconizada.\n";
                SalvandoPGM(&icone[0][0], ICON, alteracoes); // Salva a imagem
                setColor(1,32);
                cout << "\n\nImagem iconizada com sucesso!" << endl << endl;
                resetColor();
            break;
            case 12:
                // Encerra o programa
                limpartela(); // Limpa a tela
                setColor(1,35);
                cout << "Obrigado por usar o editor de imagens PGM!" << endl;
                resetColor();
                loop = false; // Encerra o loop
            break;
        }
        cout << "Deseja voltar para o menu? Digite 's' para sim e 'n' para não: ";
        cin >> resposta;
        while (resposta != "s" && resposta != "n") { // Verifica se a resposta é válida
            setColor(1,31);
            cout << "Resposta inválida.";
            resetColor();
            cout << "Digite 's' para sim e 'n' para não: ";
            cin >> resposta; // Lê a resposta novamente
        }
        if (resposta == "n") {
            loop = false; // Encerra o loop se a resposta for diferente de 's'
        }
    }

    setColor(1,35);
    cout << "Saindo do programa..." << endl;
    resetColor();

    return 0;
}
