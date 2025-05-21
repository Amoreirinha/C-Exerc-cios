/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: joaquim-pedro
 *
 * Created on May 18, 2025, 2:31 PM
 * 
 * Joaquim Pedro do Nascimento Moreira de Jesus
 * 2025.1.08.014
 * 
 * AED's I - Prática
 * Prof. Paulo Alexandre Bressan
 * 
 * 
 * Objetivo: Realizar operações em um vetor de valores inteiros.
 * 
 * Descrição: Desenvolver um projeto em C/C++ que permita:
 *      - Inserir valores inteiros em um vetor de 100 posições
 *      - Operações via menu interativo:
 *          1. Contar ocorrências de um valor
 *          2. Contar valores em um intervalo
 *          3. Buscar primeira ocorrência de um valor
 *          4. Excluir primeira ocorrência de um valor
 *          5. Inserir valor em posição específica
 *          6. Remover valores duplicados
 */

#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // Declaração de constantes e variáveis
    const int TAM = 100; // Tamanho máximo do vetor
    int vetor[TAM]; // Vetor principal do programa

    // Variáveis para controle do programa
    int choice = 0; // Armazena a escolha do menu
    int valor; // Valor temporário para várias operações
    int contvalor; // Contador de valores específicos
    int posivalor; // Armazena posições no vetor
    int intervalomenor, intervalomaior; // Para operações com intervalos
    int contmenor, contmaior, contigual; // Contadores para intervalo
    int i, j; // Índices para loops
    int valormax, valormin; // Limites para valores aleatórios
    int elementospreenchidos; // Controla quantos elementos estão no vetor
    int posivalornulo; // Guarda a posição dos valores especiais representativos de nulo (valormax + 1)

    // Flags de controle
    bool loop = true; // Controla o loop principal
    bool geravetorcomespaco = true; // Controla geração de vetor com espaços

    string quest; // Armazena respostas do usuário

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Interface inicial para configurar o vetor
    cout << "\n\nAtividade 03 - Operações em Vetores\n\n";
    cout << "Selecione o menor valor inteiro a ser gerado para o vetor:\n";
    cin >> valormin;
    cout << "Selecione o maior valor inteiro a ser gerado para o vetor:\n";
    cin >> valormax;

    // Validação dos valores mínimo e máximo
    while (valormin > valormax) {
        cout << "ERROR!\n\nValor mínimo digitado maior que o valor máximo.\n\n";
        cout << "Selecione o menor valor inteiro a ser gerado para o vetor:\n";
        cin >> valormin;
        cout << "Selecione o maior valor inteiro a ser gerado para o vetor:\n";
        cin >> valormax;
    }

    // Preenchimento inicial do vetor com valores aleatórios
    elementospreenchidos = 0;
    for (i = 0; i < TAM; i++) {
        valor = ((rand() % (valormax - valormin + 1)) + valormin);
        vetor[i] = valor;
        elementospreenchidos++;
    }

    // Limpa a tela (códigos ANSI para terminal)
    cout << "\033[2J\033[1;1H";

    // Loop principal do programa
    while (loop) {
        switch (choice) {
            case 0:
                // Menu principal
                cout << "\033[2J\033[1;1H";
                cout << "\n\n______________________________________\n\n\t\tMENU\n______________________________________\n\n";
                cout << "\n\nSelecione a operação a ser feita:\n" <<
                        "\t1. Contar quantas vezes um valor específico aparece no vetor.\n" <<
                        "\t2. Contar quantos valores estão dentro de um intervalo definido.\n" <<
                        "\t3. Buscar a primeira ocorrência de um valor e retornar sua posição.\n" <<
                        "\t4. Excluir a primeira ocorrência de um valor (se existir), reorganizando o vetor sem deixar espaços vazios.\n" <<
                        "\t5. Inserir um valor em uma posição específica (caso o vetor não esteja cheio).\n" <<
                        "\t6. Remover todos os valores repetidos, mantendo apenas uma ocorrência de cada.\n";
                cin >> choice;
                choice++;

                // Validação da escolha do menu
                while (choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7) {
                    cout << "\n\nERROR - Valor inválido inserido!!\n\n";
                    cout << "\n\nSelecione a operação a ser feita:\n" <<
                            "\t1. Contar quantas vezes um valor específico aparece no vetor.\n" <<
                            "\t2. Contar quantos valores estão dentro de um intervalo definido.\n" <<
                            "\t3. Buscar a primeira ocorrência de um valor e retornar sua posição.\n" <<
                            "\t4. Excluir a primeira ocorrência de um valor (se existir), reorganizando o vetor sem deixar espaços vazios.\n" <<
                            "\t5. Inserir um valor em uma posição específica (caso o vetor não esteja cheio).\n" <<
                            "\t6. Remover todos os valores repetidos, mantendo apenas uma ocorrência de cada.\n";
                    cin >> choice;
                    choice++;
                }
                break;

            case 1:
                // Opção para continuar ou sair do programa
                quest = "x";
                cout << "\n\nGostaria de retornar ao Menu? Digite 's' para SIM e 'n' para NÃO:\n";
                cin >> quest;

                // Validação da resposta
                while (quest != "s" && quest != "n") {
                    cout << "\n\nVALOR INVÁLIDO INSERIDO\n\n";
                    cout << "Gostaria de retornar ao Menu? Digite 's' para SIM e 'n' para NÃO:\n";
                    cin >> quest;
                }

                if (quest == "s") {
                    choice = 0; // Volta ao menu
                } else {
                    loop = false; // Encerra o programa
                }
                break;

            case 2:
                // Operação 1: Contar ocorrências de um valor
                cout << "\033[2J\033[1;1H";
                cout << "\n1. Contar quantas vezes um valor específico aparece no vetor.\n\nDigite o valor a ser procurado:\n";
                cin >> valor;

                // Validação do valor inserido
                while (valor < valormin) {
                    cout << "\n\nERROR - O Valor inserido é menor que o menor valor especificado na geração dos valores do vetor\n";
                    cout << "\nDigite o valor a ser procurado:\n";
                    cin >> valor;
                }
                while (valor > valormax) {
                    cout << "\n\nERROR - O Valor inserido é maior que o maior valor especificado na geração dos valores do vetor\n";
                    cout << "\nDigite o valor a ser procurado:\n";
                    cin >> valor;
                }

                // Contagem das ocorrências
                contvalor = 0;
                for (i = 0; i < TAM; i++) {
                    if (vetor[i] == valor) {
                        contvalor++;
                    }
                }

                // Exibição dos resultados
                if (contvalor == 0) {
                    cout << "Não há ocorrência do valor " << valor << " no vetor.\n";
                } else {
                    cout << "\nO valor " << valor << " aparece " << contvalor << " vezes no vetor, sendo ele recorrente em " << (contvalor * 100) / TAM << "% do vetor.\n";
                }
                choice = 8; // Ver o vetor
                break;

            case 3:
                // Operação 2: Contar valores em um intervalo
                cout << "\033[2J\033[1;1H";
                cout << "\n2. Contar quantos valores estão dentro de um intervalo definido.\n\nDigite o menor valor do intervalo a ser procurado:\n";
                cin >> intervalomenor;

                // Validação do intervalo mínimo
                while (intervalomenor < valormin) {
                    cout << "\n\nERROR - O Valor inserido é menor que o menor valor especificado na geração dos valores do vetor\n";
                    cout << "\nDigite o menor valor do intervalo a ser procurado:\n";
                    cin >> intervalomenor;
                }

                cout << "\nDigite o maior valor do intervalo a ser procurado:\n";
                cin >> intervalomaior;

                // Validação do intervalo máximo
                while (intervalomaior > valormax) {
                    cout << "\n\nERROR - O Valor inserido é maior que o maior valor especificado na geração dos valores do vetor\n";
                    cout << "\nDigite o maior valor do intervalo a ser procurado:\n";
                    cin >> intervalomaior;
                }

                // Validação intervalo mínimo sempre menor que intervalo máximo

                while (intervalomenor > intervalomaior) {
                    cout << "\n\nERROR - o valor inserido para o menor intervalo é maior do que o valor inserido para o valor de maior intervalo\n\n";
                    cout << "Digite o menor valor do intervalo a ser procurado : \n";
                    cin >> intervalomenor;

                    // Validação do intervalo mínimo
                    while (intervalomenor < valormin) {
                        cout << "\n\nERROR - O Valor inserido é menor que o menor valor especificado na geração dos valores do vetor\n";
                        cout << "\nDigite o menor valor do intervalo a ser procurado:\n";
                        cin >> intervalomenor;
                    }

                    cout << "\nDigite o maior valor do intervalo a ser procurado:\n";
                    cin >> intervalomaior;

                    // Validação do intervalo máximo
                    while (intervalomaior > valormax) {
                        cout << "\n\nERROR - O Valor inserido é maior que o maior valor especificado na geração dos valores do vetor\n";
                        cout << "\nDigite o maior valor do intervalo a ser procurado:\n";
                        cin >> intervalomaior;
                    }
                }

                // Contagem de valores dentro, abaixo e acima do intervalo
                contigual = contmaior = contmenor = 0;
                for (i = 0; i < TAM; i++) {
                    if (vetor[i] >= intervalomenor && vetor[i] <= intervalomaior) {
                        contigual++;
                    } else if (vetor[i] > intervalomaior && vetor[i] != valormax + 1) {
                        contmaior++;
                    } else if (vetor[i] < intervalomenor) {
                        contmenor++;
                    }
                }

                // Exibição dos resultados
                if (contigual == 0) {
                    cout << "\n\nNão existem valores no vetor dentro do intervalo de " << intervalomenor << " a " << intervalomaior << ".\n\n";
                } else {
                    cout << "\n\nExistem " << contigual << " valores no vetor dentro do intervalo de " << intervalomenor << " a " << intervalomaior << ".\nIsso corresponde a " << (contigual * 100) / TAM << "% do vetor.\n\n";
                }

                if (contmenor == 0) {
                    cout << "\nNão existem valores no vetor menores do que " << intervalomenor << ".\n\n";
                } else {
                    cout << "\nExistem " << contmenor << " valores no vetor menores do que " << intervalomenor << ".\nIsso corresponde a " << (contmenor * 100) / TAM << "% do vetor.\n\n";
                }

                if (contmaior == 0) {
                    cout << "\nNão existem valores no vetor maiores do que " << intervalomaior << ".\n\n";
                } else {
                    cout << "\nExistem " << contmaior << " valores no vetor maiores do que " << intervalomaior << ".\nIsso corresponde a " << (contmaior * 100) / TAM << "% do vetor.\n\n";
                }

                choice = 8; // Ver o vetor
                break;

            case 4:
                // Operação 3: Buscar primeira ocorrência de um valor
                cout << "\033[2J\033[1;1H";
                cout << "3. Buscar a primeira ocorrência de um valor e retornar sua posição.\n\nDigite o valor a ser procurado:\n";
                cin >> valor;

                // Validação do valor inserido
                while (valor < valormin) {
                    cout << "\n\nERROR - O Valor inserido é menor que o menor valor especificado na geração dos valores do vetor\n";
                    cout << "\nDigite o valor a ser procurado:\n";
                    cin >> valor;
                }
                while (valor > valormax) {
                    cout << "\n\nERROR - O Valor inserido é maior que o maior valor especificado na geração dos valores do vetor\n";
                    cout << "\nDigite o valor a ser procurado:\n";
                    cin >> valor;
                }

                // Busca da primeira ocorrência
                posivalor = -1;
                for (i = 0; i < TAM; i++) {
                    if (vetor[i] == valor) {
                        posivalor = i + 1;
                        break;
                    }
                }

                // Exibição do resultado
                if (posivalor == -1) {
                    cout << "Não há ocorrência do valor " << valor << " no vetor.\n";
                } else {
                    cout << "\nA primeira ocorrência do valor " << valor << " é na " << posivalor << "ª posição do vetor.\n";
                }

                choice = 8; // Ver o vetor
                break;

            case 5:
                // Operação 4: Excluir primeira ocorrência de um valor
                cout << "\033[2J\033[1;1H";
                cout << "4. Excluir a primeira ocorrência de um valor (se existir), reorganizando o vetor sem deixar espaços vazios.\n\nDigite o valor a ser excluído:\n";
                cin >> valor;

                // Validação do valor inserido
                while (valor < valormin) {
                    cout << "\n\nERROR - O Valor inserido é menor que o menor valor especificado na geração dos valores do vetor\n";
                    cout << "Digite o valor a ser excluído:\n";
                    cin >> valor;
                }
                while (valor > valormax) {
                    cout << "\n\nERROR - O Valor inserido é maior que o maior valor especificado na geração dos valores do vetor\n";
                    cout << "Digite o valor a ser excluído:\n";
                    cin >> valor;
                }

                // Busca da primeira ocorrência
                posivalor = -1;
                for (i = 0; i < TAM; i++) {
                    if (vetor[i] == valor) {
                        posivalor = i + 1;
                        break;
                    }
                }

                // Remoção do elemento e reorganização do vetor
                for (j = i; j < TAM - 1; j++) {
                    vetor[j] = vetor[j + 1];
                }

                // Preenchimento da última posição com novo valor aleatório
                vetor[TAM - 1] = ((rand() % (valormax - valormin + 1)) + valormin);

                // Garante que o novo valor não seja igual ao removido
                while (vetor[TAM - 1] == valor) {
                    vetor[TAM - 1] = ((rand() % (valormax - valormin + 1)) + valormin);
                }

                // Preenche os espaços vazios do vetor se houver
                for (i = 0; i < TAM; i++) {
                    if (vetor[i] == valormax + 1) {
                        // Preenchimento da posição com novo valor aleatório
                        vetor[i] = ((rand() % (valormax - valormin + 1)) + valormin);

                        // Garante que o novo valor não seja igual ao removido
                        while (vetor[i] == valor) {
                            vetor[i] = ((rand() % (valormax - valormin + 1)) + valormin);

                        }
                        elementospreenchidos++;
                    }
                }

                // Exibição dos resultados
                if (posivalor == -1) {
                    cout << "Não há ocorrência do valor " << valor << " no vetor.\n";
                } else {
                    cout << "\nA primeira ocorrência do valor " << valor << " era na " << posivalor << "ª posição do vetor e foi removida.\nNovo vetor:\n";
                }

                choice = 8; // Vai para a opção ver vetor
                break;

            case 6:
                // Operação 5: Inserir valor em posição específica
                cout << "\033[2J\033[1;1H";
                cout << "5. Inserir um valor em uma posição específica (caso o vetor não esteja cheio).\n";
                geravetorcomespaco = true;

                // Verifica se o vetor está cheio
                while (geravetorcomespaco) {
                    if (elementospreenchidos == TAM) {
                        // Opção para gerar novo vetor com espaço
                        quest = "x";
                        cout << "O vetor está completamente preenchido.\n\nGostaria de gerar um novo vetor não completamente preenchido? Digite 's' para SIM e 'n' para não:\n";
                        cin >> quest;

                        // Validação da resposta
                        while (quest != "s" && quest != "n") {
                            cout << "\n\nERROR - Valor inválido inserido!\n";
                            cout << "O vetor está completamente preenchido.\n\nGostaria de gerar um novo vetor não completamente preenchido? Digite 's' para SIM e 'n' para não:\n";
                            cin >> quest;
                        }

                        if (quest == "s") {
                            // Geração de novo vetor com espaço
                            cout << "Selecione o menor valor inteiro a ser gerado para o vetor:\n";
                            cin >> valormin;
                            cout << "Selecione o maior valor inteiro a ser gerado para o vetor:\n";
                            cin >> valormax;

                            // Validação dos novos limites
                            while (valormin > valormax) {
                                cout << "ERROR!\n\nValor mínimo digitado maior que o valor máximo\n\n";
                                cout << "Selecione o menor valor inteiro a ser gerado para o vetor:\n";
                                cin >> valormin;
                                cout << "Selecione o maior valor inteiro a ser gerado para o vetor:\n";
                                cin >> valormax;
                            }

                            // Preenchimento do novo vetor (deixando uma posição vazia)
                            elementospreenchidos = 0;
                            for (i = 0; i < TAM - 1; i++) {
                                valor = ((rand() % (valormax - valormin + 1)) + valormin);
                                vetor[i] = valor;
                                elementospreenchidos++;
                            }
                            vetor[TAM - 1] = valormax + 1; // Preenche a última posição com o valor representativo de nulo (valormax+1)                      
                        } else if (quest == "n") {
                            geravetorcomespaco = false;
                        }
                    } else if (elementospreenchidos < TAM) {
                        // Processo de inserção no vetor
                        cout << "\nDigite o valor a ser inserido:\n";
                        cin >> valor;

                        // Validação do valor inserido
                        while (valor < valormin) {
                            cout << "\n\nERROR - O Valor inserido é menor que o menor valor especificado na geração dos valores do vetor\n";
                            cout << "\nDigite o valor a ser inserido:\n";
                            cin >> valor;
                        }
                        while (valor > valormax) {
                            cout << "\n\nERROR - O Valor inserido é maior que o maior valor especificado na geração dos valores do vetor\n";
                            cout << "\nDigite o valor a ser inserido:\n";
                            cin >> valor;
                        }

                        // Solicitação da posição para inserção
                        cout << "\nDigite a posição para inserir o valor " << valor << ":\n";
                        cin >> posivalor;
                        posivalor--;

                        // Validação da posição
                        while (posivalor < 0 || posivalor > (TAM - 1)) {
                            cout << "\n\nERROR - Valor inválido inserido!\n";
                            cout << "\nDigite a posição para inserir o valor " << valor << ":\n";
                            cin >> posivalor;
                            posivalor--;
                        }

                        // Deslocamento dos elementos para abrir espaço
                        if (vetor[posivalor] == valormax + 1) {
                            vetor[posivalor] = valor;
                            elementospreenchidos++;
                        } else {
                            for (i = posivalor; i < TAM; i++) {
                                if (vetor[i] == valormax + 1) {
                                    posivalornulo = i;
                                    break;
                                } else {
                                    posivalornulo = TAM -1;
                                }
                            }
                            for (i = posivalornulo; i > posivalor; i--) {
                                vetor[i] = vetor[i - 1];
                            }
                            // Inserção do novo valor
                            vetor[posivalor] = valor;
                            elementospreenchidos++;
                        }
                        geravetorcomespaco = false;
                    }
                }

                choice = 8; // Vai à opção ver vetor
                break;

            case 7:
                // Operação 6: Remover valores duplicados
                cout << "\033[2J\033[1;1H";
                cout << "6. Remover todos os valores repetidos, mantendo apenas uma ocorrência de cada.\n";
                cout << "Atenção! Os espaços vazios ocasionados pela remoção serão representados pelo valor especial " << valormax + 1 << " que está fora do nosso intervalo de geração do vetor\n";

                // Processo de remoção de duplicatas
                for (i = 0; i < TAM; i++) {
                    for (j = 0; j < TAM; j++) {
                        if (vetor[i] == vetor[j] && i != j && vetor[i] != valormax + 1) {
                            vetor[j] = valormax + 1; // Marca duplicatas com valor especial
                            elementospreenchidos--;
                        }
                    }
                }

                // Exibição do vetor sem duplicatas
                cout << "\n\nRemovido repetições do vetor!\nNovo vetor:\n";
                for (i = 0; i < TAM; i++) {
                    if (vetor[i] == valormax + 1) {
                        cout << "\t" << i + 1 << "° - " << endl;
                    } else {
                        cout << "\t" << i + 1 << "° - " << vetor[i] << endl;
                    }
                }

                choice = 1; // Retorna à opção de menu/sair
                break;

            case 8:
                // Opção ver ou não o vetor
                quest = "x";
                cout << "\n\nGostaria de ver o vetor? Digite 's' para SIM e 'n' para NÃO:\n";
                cin >> quest;

                // Validação da resposta
                while (quest != "s" && quest != "n") {
                    cout << "\n\nVALOR INVÁLIDO INSERIDO\n\n";
                    cout << "\n\nGostaria de ver o vetor? Digite 's' para SIM e 'n' para NÃO:\n";
                    cin >> quest;
                }

                if (quest == "s") {
                    // Exibição do vetor              
                    cout << "\n\nVetor:\n";
                    for (i = 0; i < TAM; i++) {
                        if (vetor[i] == valormax + 1) {
                            cout << "\t" << i + 1 << "° - " << endl;
                        } else {
                            cout << "\t" << i + 1 << "° - " << vetor[i] << endl;
                        }
                    }
                }

                choice = 1; // Retorna à opção de menu/sair
                break;
        }
    }

    // Mensagem de despedida
    cout << "\n\nADEUS!\n\n";

    return 0;
}