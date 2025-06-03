/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */
/*
 * Controle e Estatísticas de Base de Dados
 * 
 * Joaquim Pedro do Nascimento Moreira de Jesus - 2025.1.08.014
 * Júlia Rocha - 2025.1.08.015
 * 
 * Projeto de Aplicativo para Gestão de Imóveis
 * 
 * Objetivo:
 * Desenvolver habilidades na manipulação de registros armazenados em vetores, utilizando estruturas de controle para gerar estatísticas com variáveis simples.
 * 
 * Descrição Geral:
 * O aplicativo terá como função principal a leitura e escrita de dados a partir de um arquivo-texto contendo informações sobre imóveis disponíveis para venda ou locação.
 * No início da execução, os dados devem ser lidos do arquivo “BD_Imoveis2.txt” e armazenados em um vetor de registros com capacidade máxima de 200 imóveis. Cada linha do arquivo representa um único imóvel e deve ser carregada na ordem em que aparece. No encerramento da execução, os dados atualizados devem ser gravados de volta no mesmo arquivo.
 * É essencial que o vetor de registros não contenha espaços vazios (“buracos”): ao excluir um imóvel, os registros seguintes devem ser deslocados para a esquerda para manter a sequência contínua.
 * 
 * Funcionalidades do Aplicativo:
 * O sistema deverá exibir um menu de opções para que o usuário possa executar as seguintes operações:
 *      Inclusão de um novo imóvel na base de dados.
 *      Busca de imóveis por faixa de valores (locação, venda ou temporada).
 *      Busca de imóveis pelas características:
 *          Armários embutidos
 *          Ar-condicionado
 *          Aquecedor
 *          Ventilador
 * 
 *      Busca por número de quartos e suítes.
 * 
 * Relatório estatístico contendo:
 *      Percentual de imóveis por finalidade (venda, locação, temporada)
 *      Percentual de casas com suítes
 *      Percentual de salas comerciais com piso cerâmico
 *      Listagem de todos os imóveis disponíveis.
 * 
 * Formato do Arquivo de Imóveis:
 * O arquivo conterá até 200 linhas, onde cada linha apresenta 22 campos separados por espaços, com as seguintes informações:
 *      Tipo
 *      Finalidade
 *      Endereço
 *      Bairro
 *      Cidade
 *      Área
 *      Valor
 *      IPTU
 *      Quartos
 *      Suítes
 *      Banheiros
 *      Vagas
 *      Cozinha
 *      Sala
 *      Varanda
 *      Área de serviço
 *      Piso
 *      Conservação
 *      Armários
 *      Ar-condicionado
 *      Aquecedor
 *      Ventilador
 *      
 * Observações:
 * A primeira linha do arquivo deve ser ignorada.
 * A última linha, que contém a palavra “fim” no campo do tipo de imóvel, não deve ser considerada nos cálculos.
 * 
 * 
 * Funcionamento de comandos novos:
 * 
 * getline(fonte_de_dados, variavel_destino);
 *      fonte_de_dados: um objeto de entrada como cin (teclado) ou ifstream (arquivo).
 *      variavel_destino: uma variável std::string onde o conteúdo da linha será armazenado.
 * 
 */

#include <cstdlib>    // Para funções padrão
#include <fstream>    // Para manipulação de arquivos
#include <iostream>   // Para entrada/saída
#include <string.h>   // Para manipulação de strings
#include <cmath>    // Para fórmulas matemáticas

using namespace std;

/*
 * 
 */

 void limparTela() {
    // Limpa a tela do console
    cout << "\033[H\033[J"; // ANSI escape code para limpar a tela
}

int main() {

    // Variáveis para manipulação de arquivos
    const int MAX_IMOVEIS = 200; // Capacidade máxima do vetor de imóveis
    struct imovel {
        string tipo; // Tipo do imóvel (casa, apartamento, sala comercial, etc.)
        string finalidade; // Finalidade (venda, locação, temporada)
        string endereco;
        string bairro;
        string cidade;
        float area;
        float valor;
        float iptu;
        int quartos;
        int suites;
        int banheiros;
        int vagas;
        string cozinha;
        string sala;
        string varanda;
        string area_servico;
        string piso;
        string conservacao;
        bool armarios_embutidos;
        bool ar_condicionado;
        bool aquecedor;
        bool ventilador;
    } imoveis[MAX_IMOVEIS]; // Vetor de registros de imóveis

    int num_imoveis = 0; // Contador de imóveis lidos
    int i; // Variável de controle para loops
    int choice = 0; // Variável para armazenar a escolha do usuário no menu
    string resposta; // Variável para armazenar a resposta do usuário
    bool continuar = true; // Variável para controlar o loop principal  

    // Leitura do arquivo de imóveis
    ifstream arquivo("BD_Imoveis2.txt");
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo BD_Imoveis2.txt" << endl;
        return 1; // Retorna erro se o arquivo não puder ser aberto
    }

    string linha;
    // Lê e descarta a primeira linha do arquivo, que contém apenas o cabeçalho (nomes das colunas).
    // Faz isso salvando a primeira linha em uma variável, mas não a utiliza.
    // Isso evita que a linha de título seja tratada como um registro de imóvel.
    getline(arquivo, linha);

    // Lê cada linha do arquivo e armazena os dados no vetor de registros
    for(i=0; i < MAX_IMOVEIS; i++) {

        arquivo >> linha; // Lê a linha do arquivo
        if (linha == "fim") break; // Interrompe a leitura se encontrar a linha "fim"
        // Preenche os campos do registro de imóvel
        imoveis[i].tipo = linha; // Tipo do imóvel
        arquivo >> imoveis[i].finalidade;
        arquivo >> imoveis[i].endereco;
        arquivo >> imoveis[i].bairro;
        arquivo >> imoveis[i].cidade;
        arquivo >> imoveis[i].area;
        arquivo >> imoveis[i].valor;
        arquivo >> imoveis[i].iptu;
        arquivo >> imoveis[i].quartos;
        arquivo >> imoveis[i].suites;
        arquivo >> imoveis[i].banheiros;
        arquivo >> imoveis[i].vagas;
        arquivo >> imoveis[i].cozinha;
        arquivo >> imoveis[i].sala;
        arquivo >> imoveis[i].varanda;
        arquivo >> imoveis[i].area_servico;
        arquivo >> imoveis[i].piso;
        arquivo >> imoveis[i].conservacao;
        string armarios, ar_condicionado, aquecedor, ventilador;
        arquivo >> armarios; // Lê se possui armários embutidos
        imoveis[i].armarios_embutidos = (armarios == "sim"); // Converte para booleano
        arquivo >> ar_condicionado; // Lê se possui ar-condicionado
        imoveis[i].ar_condicionado = (ar_condicionado == "sim"); // Converte para booleano
        arquivo >> aquecedor; // Lê se possui aquecedor
        imoveis[i].aquecedor = (aquecedor == "sim"); // Converte para booleano
        arquivo >> ventilador; // Lê se possui ventilador
        imoveis[i].ventilador = (ventilador == "sim"); // Converte para booleano
        num_imoveis++; // Incrementa o contador de imóveis lidos
    }

    arquivo.close(); // Fecha o arquivo após a leitura

    // Exibe o total de imóveis lidos
    cout << "Total de imóveis lidos: " << num_imoveis << endl;

    limparTela(); // Limpa a tela para melhor visualização
    // Exibe os dados dos imóveis lidos

    while(continuar) {
        switch(choice) {
            case 0:
                // Menu de opções
                limparTela(); // Limpa a tela antes de exibir o menu
                cout << "Menu de Opções:" << endl;
                cout << "1. Visualizar Lista de Imóveis" << endl;
                cout << "2. Inclusão de um novo imóvel" << endl;
                cout << "3. Busca de imóveis por faixa de valores" << endl;
                cout << "4. Busca de imóveis por características" << endl;
                cout << "5. Relatório estatístico" << endl;
                cout << "Escolha uma opção: ";
                cin >> choice; // Lê a escolha do usuário
                while(choice < 1 || choice > 5) { // Valida a escolha
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Opção inválida.\nPor favor, escolha uma opção entre 1 e 5.\n\n";
                    cout << "Menu de Opções:" << endl;
                    cout << "1. Visualizar Lista de Imóveis" << endl;
                    cout << "2. Inclusão de um novo imóvel" << endl;
                    cout << "3. Busca de imóveis por faixa de valores" << endl;
                    cout << "4. Busca de imóveis por características" << endl;
                    cout << "5. Relatório estatístico" << endl;
                    cout << "Escolha uma opção: ";
                    cin >> choice; // Lê a escolha do usuário
                }
                choice++; // Incrementa a escolha para corresponder ao índice do vetor de opções
                break;

            case 1:
                //Voltar para o menu principal ou sair do programa
                cout << "\n\nDeseja voltar ao menu principal? Digite 's' para SIM ou 'n' para NÃO: ";
                cin >> resposta;
                if (resposta == "s" || resposta == "S") {
                    choice = 0; // Reseta a escolha para voltar ao menu
                    limparTela(); // Limpa a tela para reiniciar o menu
                } else if (resposta == "n" || resposta == "N") {
                    continuar = false; // Encerra o loop e o programa
                } else {
                    while (resposta != "s" && resposta != "S" && resposta != "n" && resposta != "N") {
                        cout << "Opção inválida. Digite 's' para SIM ou 'n' para NÃO: ";
                        cin >> resposta; // Solicita novamente a resposta
                    }
                    if (resposta == "s" || resposta == "S") {
                        choice = 0; // Reseta a escolha para voltar ao menu
                        limparTela(); // Limpa a tela para reiniciar o menu
                    } else if (resposta == "n" || resposta == "N") {
                        continuar = false; // Encerra o loop e o programa
                    }
                }
                break;

            case 2:
                // Exibe a lista de imóveis
                cout << "Lista de Imóveis:\n";
                for (i = 0; i < num_imoveis; i++) {
                    cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", "
                        << imoveis[i].finalidade << ", "
                        << imoveis[i].endereco << ", "
                        << imoveis[i].bairro << ", "
                        << imoveis[i].cidade << ", "
                        << imoveis[i].area << " m², "
                        << "Valor: R$" << imoveis[i].valor << endl;
                }
                choice = 1; // Reseta a escolha para voltar ao menu
                break;

            case 3:
                // Inclusão de um novo imóvel
                choice = 1; // Reseta a escolha para voltar ao menu
                break;

            case 4:
                // Busca de imóveis por faixa de valores
                choice = 1; // Reseta a escolha para voltar ao menu
                break;

            case 5:
                // Busca de imóveis por características
                choice = 1; // Reseta a escolha para voltar ao menu
                break;

            case 6:
                // Relatório estatístico
                choice = 1; // Reseta a escolha para voltar ao menu
                break;

        }
    }   

    limparTela(); // Limpa a tela antes de encerrar o programa
    // Mensagem de encerramento
    cout << "\n\nPrograma encerrado.\n\n";
    return 0;
}