/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */
/*
 * Controle e Estatísticas de Base de Dados
 *
 * Joaquim Pedro do Nascimento Moreira de Jesus - 2025.1.08.014
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

#include <cstdlib>  // Para funções padrão
#include <fstream>  // Para manipulação de arquivos
#include <iostream> // Para entrada/saída
#include <string.h> // Para manipulação de strings

using namespace std;

/*
 *
 */

void limparTela()
{
    // Limpa a tela do console
    cout << "\033[H\033[J"; // ANSI escape code para limpar a tela5
}

string barradeporcentagem(float valor)
{
    string barra = "█";                          // Caractere usado para preencher a barra
    string vazio = "░";                          // Caractere usado para representar o espaço vazio
    int tamanho = 100;                           // Tamanho total da barra
    int preenchimento = static_cast<int>(valor); // Calcula o preenchimento da barra
    string resultado = "[";
    for (int i = 0; i < tamanho; i++)
    {
        if (i < preenchimento)
        {
            resultado += barra; // Adiciona o caractere de preenchimento
        }
        else
        {
            resultado += vazio; // Adiciona o caractere vazio
        }
    }
    resultado += "]"; // Fecha a barra5
    return resultado;
}

int main()
{

    // Variáveis para manipulação de arquivos
    const int MAX_IMOVEIS = 200; // Capacidade máxima do vetor de imóveis

    struct imovel
    {
        string tipo;       // Tipo do imóvel (casa, apartamento, sala comercial, etc.)
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

    int num_imoveis = 0;                                                                                                                          // Contador de imóveis lidos
    int i;                                                                                                                                        // Variável de controle para loops
    int choice = 0;                                                                                                                               // Variável para armazenar a escolha do usuário no menu
    string resposta;                                                                                                                              // Variável para armazenar a resposta do usuário
    bool continuar = true;                                                                                                                        // Variável para controlar o loop principal
    float valor_minimo, valor_maximo;                                                                                                             // Variáveis para armazenar a faixa de valores para busca
    bool encontrou = false;                                                                                                                       // Variável para verificar se algum imóvel foi encontrado na busca
    string temp;                                                                                                                                  // Variável temporária para leitura de dados
    string endereco_temp;                                                                                                                         // Variável temporária para armazenar o endereço
    string tipo_temp;                                                                                                                             // Variável temporária para armazenar o tipo do imóvel
    string temp_bool;                                                                                                                             // Variável temporária para armazenar respostas booleanas (sim/não)
    int caract;                                                                                                                                   // Variável para armazenar a característica escolhida pelo usuário para busca
    string busca_str;                                                                                                                             // Variável para armazenar a string de busca
    float busca_float;                                                                                                                            // Variável para armazenar o valor de busca
    int busca_int;                                                                                                                                // Variável para armazenar o número de quartos ou suítes na busca
    bool busca_bool;                                                                                                                              // Variável para armazenar a resposta booleano (sim/não)
    float soma_valores = 0;                                                                                                                       // Variável para armazenar a soma dos valores dos imóveis
    float media_valores = 0;                                                                                                                      // Variável para armazenar a média dos valores dos imóveis
    int index_mais_caro = 0;                                                                                                                      // Índice do imóvel mais caro
    int index_mais_barato = 0;                                                                                                                    // Índice do imóvel mais barato
    int tipo_casa = 0, tipo_apartamento = 0, tipo_sala = 0, tipo_kitnet = 0, tipo_sobrado = 0, tipo_variados = 0, tipo_terreno = 0, tipo_galpao = 0; // Contadores para tipos de imóveis
    int finalidade_venda = 0, finalidade_locacao = 0, finalidade_temporada = 0, finalidade_aluguel = 0;                                           // Contadores para finalidades dos imóveis
    int armarios_embutidos = 0, ar_condicionado = 0, aquecedor = 0, ventilador = 0;                                                               // Contadores para características adicionais dos imóveis
    int cozinha = 0, sala = 0, varanda = 0, area_servico = 0;                                                                                     // Contadores para características de cômodos
    int conservacao_pessimo = 0, conservacao_ruim = 0, conservacao_regular = 0, conservacao_bom = 0, conservacao_otimo = 0, conservacao_novo = 0; // Contadores para estados de conservação
    int piso_ceramica = 0, piso_madeira = 0, piso_piso_frio = 0, piso_piso_quente = 0, piso_varios = 0;                                           // Contadores para tipos de piso
    int soma_area = 0, soma_iptu = 0, soma_quartos = 0, soma_suites = 0, soma_banheiros = 0, soma_vagas = 0;
    string bairro_temp; // Variável temporária para armazenar o bairro
    string cidade_temp; // Variável temporária para armazenar a cidade  

    // Leitura do arquivo de imóveis
    ifstream arquivo("BD_Imoveis2.txt");
    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo BD_Imoveis2.txt" << endl;
        return 1; // Retorna erro se o arquivo não puder ser aberto
    }

    string linha;
    // Lê e descarta a primeira linha do arquivo, que contém apenas o cabeçalho (nomes das colunas).
    // Faz isso salvando a primeira linha em uma variável, mas não a utiliza.
    // Isso evita que a linha de título seja tratada como um registro de imóvel.
    getline(arquivo, linha);

    // Lê cada linha do arquivo e armazena os dados no vetor de registros
    for (i = 0; i < MAX_IMOVEIS; i++)
    {

        arquivo >> linha; // Lê a linha do arquivo
        if (linha == "fim")
            break; // Interrompe a leitura se encontrar a linha "fim"
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
        string temp_armarios, temp_ar_condicionado, temp_aquecedor, temp_ventilador; // Variáveis temporárias para ler características adicionais dos imóveis
        arquivo >> temp_armarios;                                                    // Lê se possui armários embutidos
        imoveis[i].armarios_embutidos = (temp_armarios == "sim");                    // Converte para booleano
        arquivo >> temp_ar_condicionado;                                             // Lê se possui ar-condicionado
        imoveis[i].ar_condicionado = (temp_ar_condicionado == "sim");                // Converte para booleano
        arquivo >> temp_aquecedor;                                                   // Lê se possui aquecedor
        imoveis[i].aquecedor = (temp_aquecedor == "sim");                            // Converte para booleano
        arquivo >> temp_ventilador;                                                  // Lê se possui ventilador
        imoveis[i].ventilador = (temp_ventilador == "sim");                          // Converte para booleano
        num_imoveis++;                                                               // Incrementa o contador de imóveis lidos
    }

    arquivo.close(); // Fecha o arquivo após a leitura

    // Exibe o total de imóveis lidos
    cout << "Total de imóveis lidos: " << num_imoveis << endl;

    limparTela(); // Limpa a tela para melhor visualização
    // Exibe os dados dos imóveis lidos

    while (continuar)
    {
        switch (choice)
        {
        case 0:
            // Menu de opções
            limparTela(); // Limpa a tela antes de exibir o menu
            cout << "Menu de Opções:" << endl;
            cout << "1. Visualizar Lista de Imóveis" << endl;
            cout << "2. Inclusão de um novo imóvel" << endl;
            cout << "3. Busca de imóveis por faixa de valores" << endl;
            cout << "4. Busca de imóveis por características" << endl;
            cout << "5. Relatório estatístico" << endl;
            cout << "6. Visualizar um único imóvel" << endl;
            cout << "7. Edição de um imóvel" << endl;
            cout << "8. Exclusão de um imóvel" << endl;
            cout << "Escolha uma opção: ";
            cin >> choice; // Lê a escolha do usuário
            while (choice < 1 || choice > 8)
            {                 // Valida a escolha
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Opção inválida.\nPor favor, escolha uma opção entre 1 e 7.\n\n";
                cout << "Menu de Opções:" << endl;
                cout << "1. Visualizar Lista de Imóveis" << endl;
                cout << "2. Inclusão de um novo imóvel" << endl;
                cout << "3. Busca de imóveis por faixa de valores" << endl;
                cout << "4. Busca de imóveis por características" << endl;
                cout << "5. Relatório estatístico" << endl;
                cout << "6. Visualizar um único imóvel" << endl;
                cout << "7. Edição de um imóvel" << endl;
                cout << "8. Exclusão de um imóvel" << endl;
                cout << "Escolha uma opção: ";
                cin >> choice; // Lê a escolha do usuário
            }
            choice++; // Incrementa a escolha para corresponder ao índice do vetor de opções
            break;

        case 1:
            // Voltar para o menu principal ou sair do programa
            cout << "\n\nDeseja voltar ao menu principal? Digite 's' para SIM ou 'n' para NÃO: ";
            resposta = "x"; // Inicializa a resposta com um valor inválido
            cin >> resposta;
            if (resposta == "s" || resposta == "S")
            {
                choice = 0;   // Reseta a escolha para voltar ao menu
                limparTela(); // Limpa a tela para reiniciar o menu
            }
            else if (resposta == "n" || resposta == "N")
            {
                continuar = false; // Encerra o loop e o programa
            }
            else
            {
                while (resposta != "s" && resposta != "S" && resposta != "n" && resposta != "N")
                {
                    cout << "Opção inválida. Digite 's' para SIM ou 'n' para NÃO: ";
                    cin >> resposta; // Solicita novamente a resposta
                }
                if (resposta == "s" || resposta == "S")
                {
                    choice = 0;   // Reseta a escolha para voltar ao menu
                    limparTela(); // Limpa a tela para reiniciar o menu
                }
                else if (resposta == "n" || resposta == "N")
                {
                    continuar = false; // Encerra o loop e o programa
                }
            }
            break;

        case 2:
            // Exibe a lista de imóveis
            cout << "Lista de Imóveis:\n";
            for (i = 0; i < num_imoveis; i++)
            {
                cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", "
                     << imoveis[i].finalidade << ", "
                     << imoveis[i].endereco << ", "
                     << imoveis[i].bairro << ", "
                     << imoveis[i].cidade << ", "
                     << imoveis[i].area << " m², ";
                if (imoveis[i].finalidade == "aluguel")
                {
                    cout << "Aluguel(dia): R$" << imoveis[i].valor << endl;
                }
                else
                {
                    cout << "Venda: R$" << imoveis[i].valor << endl;
                }
            }
            choice = 1; // Vai para opção 1 para perguntar se deseja voltar ao menu principal ou sair do programa
            break;

        case 3:
            // Inclusão de um novo imóvel
            limparTela(); // Limpa a tela antes de solicitar os dados do novo imóvel
            cout << "Inclusão de um Novo Imóvel\n";
            // Verifica se o vetor de imóveis está cheio
            if (num_imoveis >= MAX_IMOVEIS)
            {
                cout << "ERROR - Banco de dados cheio. Não é possível incluir mais imóveis.\n";
                choice = 1; // Vai para a opção 1 para perguntar se deseja voltar ao menu principal ou sair do programa
                break;
            }
            else
            {
                // Solicita os dados do novo imóvel
                // Tipo do imóvel
                (limparTela()); // Limpa a tela para melhor visualização
                cout << "Digite o tipo do imóvel (Casa, Apartamento, Sala, etc.): ";
                cin.ignore(); // Limpa o buffer do cin antes do primeiro getline
                getline(cin, tipo_temp); // Lê o tipo temporariamente
                // Este laço percorre cada caractere da string endereco_temp
                // Coloca como minúscula
                if (!tipo_temp.empty())
                {
                    for (size_t j = 0; j < tipo_temp.length(); j++)
                    {
                        tipo_temp[j] = tolower(tipo_temp[j]);
                    }
                }
                // Substitui espaços por sublinhados
                for (size_t j = 0; j < tipo_temp.length(); j++)
                {
                    if (tipo_temp[j] == ' ')
                    {
                        tipo_temp[j] = '_';
                    }
                }
                imoveis[num_imoveis].tipo = tipo_temp; // Armazena o tipo do imóvel

                // Finalidade do imóvel
                cout << "Digite a finalidade (venda, locação, temporada, aluguel): ";
                cin >> imoveis[num_imoveis].finalidade; // Lê a finalidade do imóvel
                while (imoveis[num_imoveis].finalidade != "venda" && imoveis[num_imoveis].finalidade != "locação" && imoveis[num_imoveis].finalidade != "temporada" &&
                       imoveis[num_imoveis].finalidade != "aluguel")
                {                 // Enquanto a finalidade não for válida
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Finalidade inválida. Digite 'venda', 'locação' ou 'temporada'.\n";
                    cout << "Digite a finalidade (venda, locação, temporada): ";
                    cin >> imoveis[num_imoveis].finalidade; // Lê a finalidade do imóvel
                }

                // Endereço do imóvel
                cout << "Digite o endereço: ";
                getline(cin, endereco_temp); // Lê o endereço temporariamente
                // Este laço percorre cada caractere da string endereco_temp
                // Formata o endereço: espaços por sublinhado
                for (size_t j = 0; j < endereco_temp.length(); j++)
                {
                    if (endereco_temp[j] == ' ')
                    {
                        endereco_temp[j] = '_';
                    }
                }
                imoveis[num_imoveis].endereco = endereco_temp; // Lê o endereço completo

                // Bairro
                string bairro_temp;
                cout << "Digite o bairro: ";
                getline(cin, bairro_temp); // Lê o bairro
                if (!bairro_temp.empty())
                {
                    bairro_temp[0] = toupper(bairro_temp[0]);
                    for (size_t j = 1; j < bairro_temp.length(); j++)
                    {
                        bairro_temp[j] = tolower(bairro_temp[j]);
                    }
                }
                for (size_t j = 0; j < bairro_temp.length(); j++)
                {
                    if (bairro_temp[j] == ' ')
                    {
                        bairro_temp[j] = '_';
                    }
                }
                imoveis[num_imoveis].bairro = bairro_temp;

                // Cidade
                string cidade_temp;
                cout << "Digite a cidade: ";
                getline(cin, cidade_temp); // Lê a cidade
                if (!cidade_temp.empty())
                {
                    cidade_temp[0] = toupper(cidade_temp[0]);
                    for (size_t j = 1; j < cidade_temp.length(); j++)
                    {
                        cidade_temp[j] = tolower(cidade_temp[j]);
                    }
                }
                for (size_t j = 0; j < cidade_temp.length(); j++)
                {
                    if (cidade_temp[j] == ' ')
                    {
                        cidade_temp[j] = '_';
                    }
                }
                imoveis[num_imoveis].cidade = cidade_temp;

                // Área do imóvel
                cout << "Digite a área em m²: ";
                cin >> imoveis[num_imoveis].area; // Lê a área do imóvel
                while (imoveis[num_imoveis].area <= 0)
                {                 // Enquanto a área for menor ou igual a zero
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Área inválida. A área deve ser maior que zero.\n";
                    cout << "Digite a área em m²: ";
                    cin >> imoveis[num_imoveis].area; // Lê novamente a área do imóvel
                }

                // Valor do imóvel
                cout << "Digite o valor: R$";
                cin >> imoveis[num_imoveis].valor; // Lê o valor do imóvel
                while (imoveis[num_imoveis].valor <= 0)
                {                 // Enquanto o valor for menor ou igual a zero
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Valor inválido. O valor deve ser maior que zero.\n";
                    cout << "Digite o valor: R$";
                    cin >> imoveis[num_imoveis].valor; // Lê novamente o valor do imóvel
                }

                // IPTU do imóvel
                cout << "Digite o valor do IPTU: R$";
                cin >> imoveis[num_imoveis].iptu; // Lê o valor do IPTU
                while (imoveis[num_imoveis].iptu < 0)
                {                 // Enquanto o valor do IPTU for menor que zero
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Valor do IPTU inválido. O valor deve ser maior ou igual a zero.\n";
                    cout << "Digite o valor do IPTU: R$";
                    cin >> imoveis[num_imoveis].iptu; // Lê novamente o valor do IPTU
                }

                // Características do imóvel
                cout << "Digite o número de quartos: ";
                cin >> imoveis[num_imoveis].quartos; // Lê o número de quartos
                while (imoveis[num_imoveis].quartos < 0)
                {                 // Enquanto o número de quartos for menor que zero
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Número de quartos inválido. O número deve ser maior ou igual a zero.\n";
                    cout << "Digite o número de quartos: ";
                    cin >> imoveis[num_imoveis].quartos; // Lê novamente o número de quartos
                }

                // Lê o número de suítes
                cout << "Digite o número de suítes: ";
                cin >> imoveis[num_imoveis].suites; // Lê o número de suítes
                while (imoveis[num_imoveis].suites < 0)
                {                 // Enquanto o número de suítes for menor que zero
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Número de suítes inválido. O número deve ser maior ou igual a zero.\n";
                    cout << "Digite o número de suítes: ";
                    cin >> imoveis[num_imoveis].suites; // Lê novamente o número de suítes
                }

                // Lê o número de banheiros
                cout << "Digite o número de banheiros: ";
                cin >> imoveis[num_imoveis].banheiros; // Lê o número de banheiros
                while (imoveis[num_imoveis].banheiros < 0)
                {                 // Enquanto o número de banheiros for menor que zero
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Número de banheiros inválido. O número deve ser maior ou igual a zero.\n";
                    cout << "Digite o número de banheiros: ";
                    cin >> imoveis[num_imoveis].banheiros; // Lê novamente o número de banheiros
                }

                // Lê o número de vagas de garagem
                cout << "Digite o número de vagas de garagem: ";
                cin >> imoveis[num_imoveis].vagas; // Lê o número de vagas de garagem
                while (imoveis[num_imoveis].vagas < 0)
                {                 // Enquanto o número de vagas for menor que zero
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Número de vagas inválido. O número deve ser maior ou igual a zero.\n";
                    cout << "Digite o número de vagas de garagem: ";
                    cin >> imoveis[num_imoveis].vagas; // Lê novamente o número de vagas de garagem
                }

                // Características adicionais do imóvel
                // Cozinha
                cout << "Possui cozinha? (sim/não): ";
                cin >> imoveis[num_imoveis].cozinha; // Lê se possui cozinha
                while (imoveis[num_imoveis].cozinha != "sim" && imoveis[num_imoveis].cozinha != "não")
                {
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                    cout << "Possui cozinha? (sim/não): ";
                    cin >> imoveis[num_imoveis].cozinha; // Lê novamente se possui cozinha
                }

                // Sala
                cout << "Possui sala? (sim/não): ";
                cin >> imoveis[num_imoveis].sala; // Lê
                while (imoveis[num_imoveis].sala != "sim" && imoveis[num_imoveis].sala != "não")
                {
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                    cout << "Possui sala? (sim/não): ";
                    cin >> imoveis[num_imoveis].sala; // Lê novamente se possui sala
                }

                // Varanda
                cout << "Possui varanda? (sim/não): ";
                cin >> imoveis[num_imoveis].varanda;
                while (imoveis[num_imoveis].varanda != "sim" && imoveis[num_imoveis].varanda != "não")
                {
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                    cout << "Possui varanda? (sim/não): ";
                    cin >> imoveis[num_imoveis].varanda; // Lê novamente se possui varanda
                }

                // Área de serviço
                cout << "Possui área de serviço? (sim/não): ";
                cin >> imoveis[num_imoveis].area_servico;
                while (imoveis[num_imoveis].area_servico != "sim" && imoveis[num_imoveis].area_servico != "não")
                {
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                    cout << "Possui área de serviço? (sim/não): ";
                    cin >> imoveis[num_imoveis].area_servico; // Lê novamente se possui área de serviço
                }

                // Piso do imóvel
                cout << "Tipo de piso: ";
                cin >> imoveis[num_imoveis].piso;
                for (size_t j = 0; j < imoveis[num_imoveis].piso.length(); j++)
                {
                    if (imoveis[num_imoveis].piso[j] == ' ')
                    {
                        imoveis[num_imoveis].piso[j] = '_';
                    }
                    else
                    {
                        imoveis[num_imoveis].piso[j] = tolower(imoveis[num_imoveis].piso[j]);
                    }
                }

                // Estado de conservação do imóvel
                cout << "Estado de conservação: (péssimo, ruim, regular, bom, ótimo, novo) ";
                cin >> imoveis[num_imoveis].conservacao;
                while (imoveis[num_imoveis].conservacao != "péssimo" && imoveis[num_imoveis].conservacao != "ruim" &&
                       imoveis[num_imoveis].conservacao != "regular" && imoveis[num_imoveis].conservacao != "bom" &&
                       imoveis[num_imoveis].conservacao != "ótimo" && imoveis[num_imoveis].conservacao != "novo")
                {
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Estado de conservação inválido. Digite 'péssimo', 'ruim', 'regular', 'bom', 'ótimo' ou 'novo'.\n";
                    cout << "Estado de conservação: (péssimo, ruim, regular, bom, ótimo, novo) ";
                    cin >> imoveis[num_imoveis].conservacao; // Lê novamente o estado de conservação
                }

                // Características adicionais (armários, ar-condicionado, aquecedor, ventilador)
                // Armários embutidos
                cout << "Possui armários embutidos? (sim/não): ";
                cin >> temp_bool;
                while (temp_bool != "sim" && temp_bool != "não")
                {                 // Enquanto a resposta não for válida
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                    cout << "Possui armários embutidos? (sim/não): ";
                    cin >> temp_bool; // Lê novamente se possui armários embutidos
                }
                imoveis[num_imoveis].armarios_embutidos = (temp_bool == "sim");

                // Ar-condicionado
                cout << "Possui ar-condicionado? (sim/não): ";
                cin >> temp_bool;
                while (temp_bool != "sim" && temp_bool != "não")
                {                 // Enquanto a resposta não for válida
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                    cout << "Possui ar-condicionado? (sim/não): ";
                    cin >> temp_bool; // Lê novamente se possui ar-condicionado
                }
                imoveis[num_imoveis].ar_condicionado = (temp_bool == "sim");

                // Aquecedor
                cout << "Possui aquecedor? (sim/não): ";
                cin >> temp_bool;
                while (temp_bool != "sim" && temp_bool != "não")
                {                 // Enquanto a resposta não for válida
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                    cout << "Possui aquecedor? (sim/não): ";
                    cin >> temp_bool; // Lê novamente se possui aquecedor
                }
                imoveis[num_imoveis].aquecedor = (temp_bool == "sim");

                // Ventilador
                cout << "Possui ventilador? (sim/não): ";
                cin >> temp_bool;
                while (temp_bool != "sim" && temp_bool != "não")
                {                 // Enquanto a resposta não for válida
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                    cout << "Possui ventilador? (sim/não): ";
                    cin >> temp_bool; // Lê novamente se possui ventilador
                }
                imoveis[num_imoveis].ventilador = (temp_bool == "sim");

                // Após coletar todos os dados, incrementa o contador de imóveis
                num_imoveis++; // Incrementa o contador de imóveis após inclusão
                cout << "Imóvel incluído com sucesso!\n";
            }
            choice = 1; // Vai para opção 1 para perguntar se deseja voltar ao menu principal ou sair do programa
            break;

        case 4:
            // Busca de imóveis por faixa de valores
            limparTela();      // Limpa a tela antes de solicitar os valores
            encontrou = false; // Variável para verificar se algum imóvel foi encontrado na busca
            cout << "Busca de Imóveis por Faixa de Valores\n";
            cout << "Digite o valor mínimo: R$";
            cin >> valor_minimo; // Lê o valor mínimo
            // Verifica se o valor mínimo é válido
            while (valor_minimo < 0)
            {                 // Enquanto o valor mínimo for menor que zero
                limparTela(); // Limpa a tela para melhor visualização
                // Solicita novamente o valor mínimo
                cout << "ERROR - Valor mínimo não pode ser menor do que zero.\n";
                cout << "Digite o valor mínimo: R$";
                cin >> valor_minimo; // Lê o valor mínimo
            }
            cout << "Digite o valor máximo: R$";
            cin >> valor_maximo; // Lê o valor máximo
            while (valor_maximo < valor_minimo)
            {                 // Enquanto o valor máximo for menor que o valor mínimo
                limparTela(); // Limpa a tela para melhor visualização
                // Solicita novamente o valor máximo
                cout << "ERROR - Valor máximo não pode ser menor do que o valor mínimo.\n";
                cout << "Digite o valor máximo: R$";
                cin >> valor_maximo; // Lê o valor máximo
            }
            // Exibe os imóveis encontrados na faixa de valores especificada
            limparTela(); // Limpa a tela para melhor visualização
            cout << "\nImóveis encontrados na faixa de R$" << valor_minimo << " a R$" << valor_maximo << ":\n";
            if (num_imoveis == 0)
            {
                cout << "Não há imóveis no Banco de Dados.\n";
            }
            else
            {
                for (i = 0; i < num_imoveis; i++)
                {
                    cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", "
                         << imoveis[i].finalidade << ", "
                         << imoveis[i].endereco << ", "
                         << imoveis[i].bairro << ", "
                         << imoveis[i].cidade << ", "
                         << imoveis[i].area << " m², ";
                    if (imoveis[i].finalidade == "aluguel")
                    {
                        cout << "Aluguel(dia): R$" << imoveis[i].valor << endl;
                    }
                    else
                    {
                        cout << "Venda: R$" << imoveis[i].valor << endl;
                    }
                }
            }
            if (!encontrou)
            {
                cout << "Nenhum imóvel encontrado na faixa de R$" << valor_minimo << " a R$" << valor_maximo << ".\n";
            }

            choice = 1; // Vai para opção 1 para perguntar se deseja voltar ao menu principal ou sair do programa
            break;

        case 5:
            // Busca de imóveis por características
            limparTela();      // Limpa a tela antes de solicitar as características
            encontrou = false; // Variável para verificar se algum imóvel foi encontrado na busca
            cout << "Busca de Imóveis por Características\n";
            cout << "Digite a característica que deseja buscar:\n";
            cout << "1. Tipo\n";
            cout << "2. Finalidade\n";
            cout << "3. Endereço\n";
            cout << "4. Bairro\n";
            cout << "5. Cidade\n";
            cout << "6. Área\n";
            cout << "7. IPTU\n";
            cout << "8. Quartos\n";
            cout << "9. Suítes\n";
            cout << "10. Banheiros\n";
            cout << "11. Vagas\n";
            cout << "12. Cozinha\n";
            cout << "13. Sala\n";
            cout << "14. Varanda\n";
            cout << "15. Área de serviço\n";
            cout << "16. Piso\n";
            cout << "17. Conservação\n";
            cout << "18. Armários embutidos\n";
            cout << "19. Ar-condicionado\n";
            cout << "20. Aquecedor\n";
            cout << "21. Ventilador\n";
            cout << "Escolha o número da característica para pesquisar: ";
            cin >> caract;
            while (caract < 1 || caract > 21)
            {                 // Valida a escolha da característica
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Opção inválida. Por favor, escolha um número entre 1 e 21.\n";
                cout << "Escolha o número da característica para pesquisar: ";
                cin >> caract; // Lê novamente a escolha da característica
            }

            switch(caract)
            {
            case 1:
                cout << "Digite o tipo: ";
                cin.ignore();                // Limpa o buffer do cin antes de getline
                getline(cin, busca_str); // Lê o tipo do imóvel
                // Formata a string de busca para comparação
                for (size_t j = 0; j < busca_str.length(); j++)
                {
                    if (busca_str[j] == ' ')
                    {
                        busca_str[j] = '_'; // Substitui espaços por sublinhados
                    }
                    else
                    {
                        busca_str[j] = tolower(busca_str[j]); // Converte para minúsculas
                    }
                }
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].tipo == busca_str)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 2:
                cout << "Digite a finalidade: ";
                cin.ignore();                // Limpa o buffer do cin antes de getline
                getline(cin, busca_str);
                while (busca_str != "venda" && busca_str != "locação" && busca_str != "temporada" && busca_str != "aluguel")
                {                 // Enquanto a finalidade não for válida
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Finalidade inválida. Digite 'venda', 'locação', 'aluguel' ou 'temporada'.\n";
                    cout << "Digite a finalidade: ";
                    cin >> busca_str; // Lê novamente a finalidade
                }
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].finalidade == busca_str)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 3:
                cout << "Digite o endereço: ";
                cin.ignore();                // Limpa o buffer do cin antes de getline
                getline(cin, busca_str); // Lê o endereço do imóvel
                // Formata a string de busca para comparação
                // Formata a string de busca para comparação
                for (size_t j = 0; j < busca_str.length(); j++)
                {
                    if (busca_str[j] == ' ')
                    {
                        busca_str[j] = '_'; // Substitui espaços por sublinhados
                    }
                }
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].endereco == busca_str)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 4:
                cout << "Digite o bairro: ";
                cin.ignore();                // Limpa o buffer do cin antes de getline
                getline(cin, busca_str);
                // Formata a string de busca para comparação
                busca_str[0] = toupper(busca_str[0]); // Converte a primeira letra para maiúscula
                for (size_t j = 1; j < busca_str.length(); j++)
                {

                    if (busca_str[j] == ' ')
                    {
                        busca_str[j] = '_'; // Substitui espaços por sublinhados
                    } else {
                        busca_str[j] = tolower(busca_str[j]); // Converte para minúsculas
                    }
                }
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].bairro == busca_str)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 5:
                cout << "Digite a cidade: ";
                cin.ignore();                // Limpa o buffer do cin antes de getline
                getline(cin, busca_str); // Lê a cidade do imóvel
                // Formata a string de busca para comparação
                busca_str[0] = toupper(busca_str[0]); // Converte a primeira letra para maiúscula
                for (size_t j = 1; j < busca_str.length(); j++)
                {

                    if (busca_str[j] == ' ')
                    {
                        busca_str[j] = '_'; // Substitui espaços por sublinhados
                    } else {
                        busca_str[j] = tolower(busca_str[j]); // Converte para minúsculas
                    }
                }
                
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].cidade == busca_str)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 6:
                cout << "Digite a área (m²): ";
                cin >> busca_float;
                while (busca_float <= 0)
                {                 // Verifica se a área é válida
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Área inválida. A área deve ser maior que zero.\n";
                    cout << "Digite a área (m²): ";
                    cin >> busca_float; // Lê novamente a área
                }
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].area == busca_float)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 7:
                cout << "Digite o valor do IPTU: ";
                cin >> busca_float;
                while (busca_float < 0)
                {                 // Verifica se o valor do IPTU é válido
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Valor do IPTU inválido. O valor deve ser maior ou igual a zero.\n";
                    cout << "Digite o valor do IPTU: ";
                    cin >> busca_float; // Lê novamente o valor do IPTU
                }
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].iptu == busca_float)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 8:
                cout << "Digite o número de quartos: ";
                cin >> busca_int;
                while (busca_int < 0)
                {                 // Verifica se o número de quartos é válido
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Número de quartos inválido. O número deve ser maior ou igual a zero.\n";
                    cout << "Digite o número de quartos: ";
                    cin >> busca_int; // Lê novamente o número de quartos
                }

                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].quartos == busca_int)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 9:
                cout << "Digite o número de suítes: ";
                cin >> busca_int;
                while (busca_int < 0)
                {                 // Verifica se o número de suítes é válido
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Número de suítes inválido. O número deve ser maior ou igual a zero.\n";
                    cout << "Digite o número de suítes: ";
                    cin >> busca_int; // Lê novamente o número de suítes
                }
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].suites == busca_int)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 10:
                cout << "Digite o número de banheiros: ";
                cin >> busca_int;
                while (busca_int < 0)
                {                 // Verifica se o número de banheiros é válido
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Número de banheiros inválido. O número deve ser maior ou igual a zero.\n";
                    cout << "Digite o número de banheiros: ";
                    cin >> busca_int; // Lê novamente o número de banheiros
                }
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].banheiros == busca_int)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 11:
                cout << "Digite o número de vagas: ";
                cin >> busca_int;
                while (busca_int < 0)
                {                 // Verifica se o número de vagas é válido
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Número de vagas inválido. O número deve ser maior ou igual a zero.\n";
                    cout << "Digite o número de vagas: ";
                    cin >> busca_int; // Lê novamente o número de vagas
                }
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].vagas == busca_int)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 12:
                cout << "Possui cozinha? (sim/não): ";
                cin >> busca_str;
                while (busca_str != "sim" && busca_str != "não")
                {                 // Verifica se a resposta é válida
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                    cout << "Possui cozinha? (sim/não): ";
                    cin >> busca_str; // Lê novamente se possui cozinha
                }
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].cozinha == busca_str)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 13:
                cout << "Possui sala? (sim/não): ";
                cin >> busca_str;
                while (busca_str != "sim" && busca_str != "não")
                {                 // Verifica se a resposta é válida
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                    cout << "Possui sala? (sim/não): ";
                    cin >> busca_str; // Lê novamente se possui sala
                }
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].sala == busca_str)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 14:
                cout << "Possui varanda? (sim/não): ";
                cin >> busca_str;
                while (busca_str != "sim" && busca_str != "não")
                {                 // Verifica se a resposta é válida
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                    cout << "Possui varanda? (sim/não): ";
                    cin >> busca_str; // Lê novamente se possui varanda
                }
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].varanda == busca_str)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 15:
                cout << "Possui área de serviço? (sim/não): ";
                cin >> busca_str;
                while (busca_str != "sim" && busca_str != "não")
                {                 // Verifica se a resposta é válida
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                    cout << "Possui área de serviço? (sim/não): ";
                    cin >> busca_str; // Lê novamente se possui área de serviço
                }
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].area_servico == busca_str)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 16:
                cout << "Digite o tipo de piso: ";
                cin >> busca_str;
                // Formata a string de busca para comparação
                for (size_t j = 0; j < busca_str.length(); j++)
                {
                    if (busca_str[j] == ' ')
                    {
                        busca_str[j] = '_'; // Substitui espaços por sublinhados
                    }
                    else
                    {
                        busca_str[j] = tolower(busca_str[j]); // Converte para minúsculas
                    }
                }
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].piso == busca_str)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 17:
                cout << "Digite o estado de conservação: ";
                cin >> busca_str;
                while (busca_str != "péssimo" && busca_str != "ruim" &&
                       busca_str != "regular" && busca_str != "bom" &&
                       busca_str != "ótimo" && busca_str != "novo")
                {
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Estado de conservação inválido. Digite 'péssimo', 'ruim', 'regular', 'bom', 'ótimo' ou 'novo'.\n";
                    cout << "Digite o estado de conservação: ";
                    cin >> busca_str; // Lê novamente o estado de conservação
                }
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].conservacao == busca_str)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 18:
                cout << "Possui armários embutidos? (sim/não): ";
                cin >> busca_str;
                while (busca_str != "sim" && busca_str != "não")
                {                 // Verifica se a resposta é válida
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                    cout << "Possui armários embutidos? (sim/não): ";
                    cin >> busca_str; // Lê novamente se possui armários embutidos
                }
                busca_bool = (busca_str == "sim");
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].armarios_embutidos == busca_bool)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 19:
                cout << "Possui ar-condicionado? (sim/não): ";
                cin >> busca_str;
                while (busca_str != "sim" && busca_str != "não")
                {                 // Verifica se a resposta é válida
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                    cout << "Possui ar-condicionado? (sim/não): ";
                    cin >> busca_str; // Lê novamente se possui ar-condicionado
                }
                busca_bool = (busca_str == "sim");
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].ar_condicionado == busca_bool)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 20:
                cout << "Possui aquecedor? (sim/não): ";
                cin >> busca_str;
                while (busca_str != "sim" && busca_str != "não")
                {                 // Verifica se a resposta é válida
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                    cout << "Possui aquecedor? (sim/não): ";
                    cin >> busca_str; // Lê novamente se possui aquecedor
                }
                busca_bool = (busca_str == "sim");
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].aquecedor == busca_bool)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            case 21:
                cout << "Possui ventilador? (sim/não): ";
                cin >> busca_str;
                while (busca_str != "sim" && busca_str != "não")
                {                 // Verifica se a resposta é válida
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                    cout << "Possui ventilador? (sim/não): ";
                    cin >> busca_str; // Lê novamente se possui ventilador
                }
                busca_bool = (busca_str == "sim");
                for (i = 0; i < num_imoveis; i++)
                    if (imoveis[i].ventilador == busca_bool)
                    {
                        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", " << imoveis[i].finalidade << ", " << imoveis[i].endereco << endl;
                        encontrou = true;
                    }
                break;
            }
            if (!encontrou)
            {
                cout << "Nenhum imóvel encontrado com essa característica.\n";
            }
            choice = 1; // Vai para opção 1 para perguntar se deseja voltar ao menu principal ou sair do programa
            break;

        case 6:
            // Relatório estatístico
            limparTela(); // Limpa a tela antes de exibir o relatório
            cout << "Gerando Relatório\n\n\n";
            if (num_imoveis == 0)
            {
                cout << "Não há imóveis cadastrados.\n";
            }
            else
            {
                // Exibe o número total de imóveis
                cout << "\nNúmero total de imóveis cadastrados: " << num_imoveis << endl;

                // Calcula e exibe a média de valores dos imóveis
                soma_valores = 0;
                soma_area = 0;
                soma_iptu = 0;
                soma_quartos = 0;
                soma_suites = 0;
                soma_banheiros = 0;
                soma_vagas = 0;
                index_mais_caro = 0;
                tipo_casa = 0, tipo_apartamento = 0, tipo_sala = 0, tipo_kitnet = 0, tipo_sobrado = 0, tipo_variados = 0, tipo_terreno = 0, tipo_galpao = 0;
                finalidade_venda = 0, finalidade_locacao = 0, finalidade_temporada = 0;
                armarios_embutidos = 0, ar_condicionado = 0, aquecedor = 0, ventilador = 0;
                index_mais_barato = 0;
                cozinha = 0, sala = 0, varanda = 0, area_servico = 0;
                conservacao_pessimo = 0, conservacao_ruim = 0, conservacao_regular = 0, conservacao_bom = 0, conservacao_otimo = 0, conservacao_novo = 0;
                piso_ceramica = 0, piso_madeira = 0, piso_piso_frio = 0, piso_piso_quente = 0, piso_varios = 0;
                for (i = 0; i < num_imoveis; i++)
                {
                    soma_valores += imoveis[i].valor;
                    soma_area += imoveis[i].area;
                    soma_iptu += imoveis[i].iptu;
                    soma_quartos += imoveis[i].quartos;
                    soma_suites += imoveis[i].suites;
                    soma_banheiros += imoveis[i].banheiros;
                    soma_vagas += imoveis[i].vagas;
                    
                    if (imoveis[i].valor > imoveis[index_mais_caro].valor){
                        index_mais_caro = i;
                    }
                    
                    if (imoveis[i].tipo == "casa"){
                        tipo_casa++;
                    }else if (imoveis[i].tipo == "apartamento"){
                        tipo_apartamento++;
                    }else if (imoveis[i].tipo == "sala_comercial"){
                        tipo_sala++;
                    }else if (imoveis[i].tipo == "kitnet"){
                        tipo_kitnet++;
                    }else if (imoveis[i].tipo == "sobrado"){
                        tipo_sobrado++;
                    }else if (imoveis[i].tipo == "terreno"){
                        tipo_terreno++;
                    }else if (imoveis[i].tipo == "galpão"){
                        tipo_galpao++;
                    }else{
                        tipo_variados++;
                    }

                    if (imoveis[i].finalidade == "venda"){
                        finalidade_venda++;
                    }else if (imoveis[i].finalidade == "locação"){
                        finalidade_locacao++;
                    }else if (imoveis[i].finalidade == "temporada"){
                        finalidade_temporada++;
                    }else if (imoveis[i].finalidade == "aluguel"){
                        finalidade_aluguel++;
                    }

                    if (imoveis[i].armarios_embutidos){
                        armarios_embutidos++;
                    }

                    if (imoveis[i].ar_condicionado){
                        ar_condicionado++;
                    }

                    if (imoveis[i].aquecedor){
                        aquecedor++;
                    }

                    if (imoveis[i].ventilador){
                        ventilador++;
                    }

                    if (imoveis[i].valor < imoveis[index_mais_barato].valor){
                        index_mais_barato = i;
                    }

                    if (imoveis[i].cozinha == "sim"){
                        cozinha++;
                    }

                    if (imoveis[i].sala == "sim"){
                        sala++;
                    }

                    if (imoveis[i].varanda == "sim"){
                        varanda++;
                    }

                    if (imoveis[i].area_servico == "sim"){
                        area_servico++;
                    }

                    if (imoveis[i].conservacao == "péssimo"){
                        conservacao_pessimo++;
                    }else if (imoveis[i].conservacao == "ruim"){
                        conservacao_ruim++;
                    }else if (imoveis[i].conservacao == "regular"){
                        conservacao_regular++;
                    }else if (imoveis[i].conservacao == "bom"){
                        conservacao_bom++;
                    }else if (imoveis[i].conservacao == "ótimo"){
                        conservacao_otimo++;
                    }else if (imoveis[i].conservacao == "novo"){
                        conservacao_novo++;
                    }

                    if (imoveis[i].piso == "cerâmica"){
                        piso_ceramica++;
                    }else if (imoveis[i].piso == "madeira"){
                        piso_madeira++;
                    }else if (imoveis[i].piso == "piso frio"){
                        piso_piso_frio++;
                    }else if (imoveis[i].piso == "piso quente"){
                        piso_piso_quente++;
                    }else{
                        piso_varios++;
                    }
                }
                limparTela(); // Limpa a tela para melhor visualização
                // Exibe o relatório estatístico
                cout << "Relatório Estatístico\n\n\n";
                media_valores = soma_valores / num_imoveis;
                cout << "\nMédia de valores dos imóveis: R$" << media_valores << endl;
                cout << "\n\nMédia de área dos imóveis: " << (soma_area / num_imoveis) << " m²\n";
                cout << "\n\nMédia de IPTU dos imóveis: R$" << (soma_iptu / num_imoveis) << endl;
                cout << "\n\nMédia de quartos dos imóveis: " << (soma_quartos / num_imoveis) << endl;
                cout << "\n\nMédia de suítes dos imóveis: " << (soma_suites / num_imoveis) << endl;
                cout << "\n\nMédia de banheiros dos imóveis: " << (soma_banheiros / num_imoveis) << endl;
                cout << "\n\nMédia de vagas dos imóveis: " << (soma_vagas / num_imoveis) << endl;

                // Exibe o imóvel mais caro
                cout << "\nImóvel mais caro: " << imoveis[index_mais_caro].tipo
                     << ", Valor: R$" << imoveis[index_mais_caro].valor
                     << ", Endereço: " << imoveis[index_mais_caro].endereco << endl;

                // Exibe o imóvel mais barato
                cout << "\nImóvel mais barato: " << imoveis[index_mais_barato].tipo
                     << ", Valor: R$" << imoveis[index_mais_barato].valor
                     << ", Endereço: " << imoveis[index_mais_barato].endereco << endl;

                // Porcentagem de tipos de imóveis
                cout << "\n\nPorcentagem de tipos de imóveis:\n";
                cout << "Casa: " << (tipo_casa * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(tipo_casa * 100 / num_imoveis) << endl
                     << endl;
                cout << "Apartamento: " << (tipo_apartamento * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(tipo_apartamento * 100 / num_imoveis) << endl
                     << endl;
                cout << "Sala Comercial: " << (tipo_sala * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(tipo_sala * 100 / num_imoveis) << endl
                     << endl;
                cout << "Kitnet: " << (tipo_kitnet * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(tipo_kitnet * 100 / num_imoveis) << endl
                     << endl;
                cout << "Sobrado: " << (tipo_sobrado * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(tipo_sobrado * 100 / num_imoveis) << endl
                     << endl;
                cout << "Terreno: " << (tipo_terreno * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(tipo_terreno * 100 / num_imoveis) << endl
                     << endl;
                cout << "Galpão: " << (tipo_galpao * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(tipo_galpao * 100 / num_imoveis) << endl
                     << endl;
                cout << "Variados: " << (tipo_variados * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(tipo_variados * 100 / num_imoveis) << endl
                     << endl;

                cout << "\n\nPorcentagem de finalidades dos imóveis:\n";
                cout << "Venda: " << (finalidade_venda * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(finalidade_venda * 100 / num_imoveis) << endl
                     << endl;
                cout << "Locação: " << (finalidade_locacao * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(finalidade_locacao * 100 / num_imoveis) << endl
                     << endl;
                cout << "Temporada: " << (finalidade_temporada * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(finalidade_temporada * 100 / num_imoveis) << endl
                     << endl;
                cout << "Aluguel: " << (finalidade_aluguel * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(finalidade_aluguel * 100 / num_imoveis) << endl
                     << endl;

                cout << "\n\nPorcentagem de imóveis com características adicionais:\n";
                cout << "Armários embutidos: " << (armarios_embutidos * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(armarios_embutidos * 100 / num_imoveis) << endl
                     << endl;
                cout << "Ar-condicionado: " << (ar_condicionado * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(ar_condicionado * 100 / num_imoveis) << endl
                     << endl;
                cout << "Aquecedor: " << (aquecedor * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(aquecedor * 100 / num_imoveis) << endl
                     << endl;
                cout << "Ventilador: " << (ventilador * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(ventilador * 100 / num_imoveis) << endl
                     << endl;

                cout << "\n\nPorcentagem de imóveis com cômodos específicos:\n";
                cout << "Cozinha: " << (cozinha * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(cozinha * 100 / num_imoveis) << endl
                     << endl;
                cout << "Sala: " << (sala * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(sala * 100 / num_imoveis) << endl
                     << endl;
                cout << "Varanda: " << (varanda * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(varanda * 100 / num_imoveis) << endl
                     << endl;
                cout << "Área de serviço: " << (area_servico * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(area_servico * 100 / num_imoveis) << endl
                     << endl;

                cout << "\n\nPorcentagem de estados de conservação dos imóveis:\n";
                cout << "Péssimo: " << (conservacao_pessimo * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(conservacao_pessimo * 100 / num_imoveis) << endl
                     << endl;
                cout << "Ruim: " << (conservacao_ruim * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(conservacao_ruim * 100 / num_imoveis) << endl
                     << endl;
                cout << "Regular: " << (conservacao_regular * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(conservacao_regular * 100 / num_imoveis) << endl
                     << endl;
                cout << "Bom: " << (conservacao_bom * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(conservacao_bom * 100 / num_imoveis) << endl
                     << endl;
                cout << "Ótimo: " << (conservacao_otimo * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(conservacao_otimo * 100 / num_imoveis) << endl
                     << endl;
                cout << "Novo: " << (conservacao_novo * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(conservacao_novo * 100 / num_imoveis) << endl
                     << endl;

                // Tipo de piso
                cout << "\n\nPorcentagem de tipos de piso:\n";
                cout << "Cerâmica: " << (piso_ceramica * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(piso_ceramica * 100 / num_imoveis) << endl
                     << endl;
                cout << "Madeira: " << (piso_madeira * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(piso_madeira * 100 / num_imoveis) << endl
                     << endl;
                cout << "Piso frio: " << (piso_piso_frio * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(piso_piso_frio * 100 / num_imoveis) << endl
                     << endl;
                cout << "Piso quente: " << (piso_piso_quente * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(piso_piso_quente * 100 / num_imoveis) << endl
                     << endl;
                cout << "Vários: " << (piso_varios * 100 / num_imoveis) << "%\n";
                cout << barradeporcentagem(piso_varios * 100 / num_imoveis) << endl
                     << endl;

                // Pergunta se deseja salvar ou não o relatório em um arquivo txt
                cout << "\nDeseja salvar este relatório em um arquivo? (sim/não): ";
                resposta = "x";
                cin >> resposta; // Lê a resposta do usuário
                while (resposta != "sim" && resposta != "não")
                {                 // Verifica se a resposta é válida
                    limparTela(); // Limpa a tela para melhor visualização
                    cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                    cout << "Deseja salvar este relatório em um arquivo? (sim/não): ";
                    cin >> resposta; // Lê novamente a resposta do usuário
                }
                if (resposta == "sim")
                {
                    // Abre o arquivo para escrita
                    ofstream arquivo_relatorio("relatorio.txt");
                    if (arquivo_relatorio.is_open())
                    {
                        // Escreve o relatório no arquivo
                        arquivo_relatorio << "Relatório Estatístico\n\n";
                        arquivo_relatorio << "Número total de imóveis cadastrados: " << num_imoveis << endl;
                        arquivo_relatorio << "Média de valores dos imóveis: R$" << media_valores << endl;
                        arquivo_relatorio << "Média de área dos imóveis: " << (soma_area / num_imoveis) << " m²\n";
                        arquivo_relatorio << "Média de IPTU dos imóveis: R$" << (soma_iptu / num_imoveis) << endl;
                        arquivo_relatorio << "Média de quartos dos imóveis: " << (soma_quartos / num_imoveis) << endl;
                        arquivo_relatorio << "Média de suítes dos imóveis: " << (soma_suites / num_imoveis) << endl;
                        arquivo_relatorio << "Média de banheiros dos imóveis: " << (soma_banheiros / num_imoveis) << endl;
                        arquivo_relatorio << "Média de vagas dos imóveis: " << (soma_vagas / num_imoveis) << endl;
                        arquivo_relatorio << "Imóvel mais caro: " << imoveis[index_mais_caro].tipo
                                          << ", Valor: R$" << imoveis[index_mais_caro].valor
                                          << ", Endereço: " << imoveis[index_mais_caro].endereco << endl;
                        arquivo_relatorio << "Imóvel mais barato: " << imoveis[index_mais_barato].tipo
                                          << ", Valor: R$" << imoveis[index_mais_barato].valor
                                          << ", Endereço: " << imoveis[index_mais_barato].endereco << endl;
                        arquivo_relatorio << "\nPorcentagem de tipos de imóveis:\n";
                        arquivo_relatorio << "Casa: " << (tipo_casa * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << barradeporcentagem(tipo_casa * 100 / num_imoveis) << "\n";
                        arquivo_relatorio << "Apartamento: " << (tipo_apartamento * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << barradeporcentagem(tipo_apartamento * 100 / num_imoveis) << "\n";
                        arquivo_relatorio << "Sala: " << (tipo_sala * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << barradeporcentagem(tipo_sala * 100 / num_imoveis) << "\n";
                        arquivo_relatorio << "Kitnet: " << (tipo_kitnet * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << barradeporcentagem(tipo_kitnet * 100 / num_imoveis) << "\n";
                        arquivo_relatorio << "Sobrado: " << (tipo_sobrado * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << barradeporcentagem(tipo_sobrado * 100 / num_imoveis) << "\n";
                        arquivo_relatorio << "Terreno: " << (tipo_terreno * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << barradeporcentagem(tipo_terreno * 100 / num_imoveis) << "\n";
                        arquivo_relatorio << "Galpão: " << (tipo_galpao * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << barradeporcentagem(tipo_galpao * 100 / num_imoveis) << "\n";
                        arquivo_relatorio << "Variados: " << (tipo_variados * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << barradeporcentagem(tipo_variados * 100 / num_imoveis) << "\n";
                        arquivo_relatorio << "\nPorcentagem de finalidades dos imóveis:\n";
                        arquivo_relatorio << "Venda: " << (finalidade_venda * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << barradeporcentagem(finalidade_venda * 100 / num_imoveis) << "\n";
                        arquivo_relatorio << "Locação: " << (finalidade_locacao * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << barradeporcentagem(finalidade_locacao * 100 / num_imoveis) << "\n";
                        arquivo_relatorio << "Temporada: " << (finalidade_temporada * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << barradeporcentagem(finalidade_temporada * 100 / num_imoveis) << "\n";
                        arquivo_relatorio << "Aluguel: " << (finalidade_aluguel * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << barradeporcentagem(finalidade_aluguel * 100 / num_imoveis) << "\n";
                        arquivo_relatorio << "\nPorcentagem de imóveis com características adicionais:\n";
                        arquivo_relatorio << "Armários embutidos: " << (armarios_embutidos * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << barradeporcentagem(armarios_embutidos * 100 / num_imoveis) << "\n";
                        arquivo_relatorio << "Ar-condicionado: " << (ar_condicionado * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << barradeporcentagem(ar_condicionado * 100 / num_imoveis) << "\n";
                        arquivo_relatorio << "Aquecedor: " << (aquecedor * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << barradeporcentagem(aquecedor * 100 / num_imoveis) << "\n";
                        arquivo_relatorio << "Ventilador: " << (ventilador * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << barradeporcentagem(ventilador * 100 / num_imoveis) << "\n";
                        arquivo_relatorio << "\nPorcentagem de imóveis com cômodos específicos:\n";
                        arquivo_relatorio << "Cozinha: " << (cozinha * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << "Sala: " << (sala * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << "Varanda: " << (varanda * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << "Área de serviço: " << (area_servico * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << "\nPorcentagem de estados de conservação dos imóveis:\n";
                        arquivo_relatorio << "Péssimo: " << (conservacao_pessimo * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << "Ruim: " << (conservacao_ruim * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << "Regular: " << (conservacao_regular * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << "Bom: " << (conservacao_bom * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << "Ótimo: " << (conservacao_otimo * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << "Novo: " << (conservacao_novo * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << "\nPorcentagem de tipos de piso:\n";
                        arquivo_relatorio << "Cerâmica: " << (piso_ceramica * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << "Madeira: " << (piso_madeira * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << "Piso frio: " << (piso_piso_frio * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << "Piso quente: " << (piso_piso_quente * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio << "Vários: " << (piso_varios * 100 / num_imoveis) << "%\n";
                        arquivo_relatorio.close(); // Fecha o arquivo
                        cout << "Relatório salvo com sucesso em 'relatorio.txt'.\n";
                    }
                    else
                    {
                        cout << "ERROR - Não foi possível abrir o arquivo para escrita.\n";
                    }
                }
            }

            choice = 1; // Vai para opção 1 para perguntar se deseja voltar ao menu principal ou sair do programa
            break;

        case 7:
            // Visualizar um único imóvel
            limparTela(); // Limpa a tela antes de solicitar o número do imóvel
            cout << "Visualizar Imóvel\n";
            cout << "Digite o número do imóvel (1 a " << num_imoveis << "): ";
            cin >> i; // Lê o número do imóvel
            i--;      // Ajusta o índice para começar de 0
            while (i < 0 || i >= num_imoveis)
            {                 // Verifica se o número do imóvel é válido
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Número de imóvel inválido. Digite um número entre 1 e " << num_imoveis << ".\n";
                cout << "Digite o número do imóvel (1 a " << num_imoveis << "): ";
                cin >> i; // Lê novamente o número do imóvel
                i--;      // Ajusta o índice para começar de 0
            }
            // Exibe os detalhes do imóvel selecionado
            cout << "\nDetalhes do Imóvel " << (i + 1) << ":\n";
            cout << "Tipo: " << imoveis[i].tipo << endl;
            cout << "Finalidade: " << imoveis[i].finalidade << endl;
            cout << "Endereço: " << imoveis[i].endereco << endl;
            cout << "Bairro: " << imoveis[i].bairro << endl;
            cout << "Cidade: " << imoveis[i].cidade << endl;
            cout << "Área: " << imoveis[i].area << " m²" << endl;
            cout << "Valor: R$" << imoveis[i].valor << endl;
            cout << "IPTU: R$" << imoveis[i].iptu << endl;
            cout << "Quartos: " << imoveis[i].quartos << endl;
            cout << "Suítes: " << imoveis[i].suites << endl;
            cout << "Banheiros: " << imoveis[i].banheiros << endl;
            cout << "Vagas de garagem: " << imoveis[i].vagas << endl;
            cout << "Cozinha: " << imoveis[i].cozinha << endl;
            cout << "Sala: " << imoveis[i].sala << endl;
            cout << "Varanda: " << imoveis[i].varanda << endl;
            cout << "Área de serviço: " << imoveis[i].area_servico << endl;
            cout << "Piso: " << imoveis[i].piso << endl;
            cout << "Estado de conservação: " << imoveis[i].conservacao << endl;
            cout << "Armários embutidos: " << (imoveis[i].armarios_embutidos ? "sim" : "não") << endl;
            cout << "Ar-condicionado: " << (imoveis[i].ar_condicionado ? "sim" : "não") << endl;
            cout << "Aquecedor: " << (imoveis[i].aquecedor ? "sim" : "não") << endl;
            cout << "Ventilador: " << (imoveis[i].ventilador ? "sim" : "não") << endl;

            choice = 1; // Vai para opção 1 para perguntar se deseja voltar ao menu principal ou sair do programa
            break;

        case 8:
            // Editar Imóvel
            limparTela(); // Limpa a tela antes de solicitar o número do imóvel
            cout << "Editar Imóvel\n";
            cout << "Digite o número do imóvel (1 a " << num_imoveis << "): ";
            cin >> i; // Lê o número do imóvel
            i--;      // Ajusta o índice para começar de 0
            while (i < 0 || i >= num_imoveis)
            {                 // Verifica se o número do imóvel é válido
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Número de imóvel inválido. Digite um número entre 1 e " << num_imoveis << ".\n";
                cout << "Digite o número do imóvel (1 a " << num_imoveis << "): ";
                cin >> i; // Lê novamente o número do imóvel
                i--;      // Ajusta o índice para começar de 0
            }
            // Exibe os detalhes do imóvel selecionado
            cout << "\nDetalhes do Imóvel " << (i + 1) << ":\n";
            cout << "Tipo: " << imoveis[i].tipo << endl;
            cout << "Finalidade: " << imoveis[i].finalidade << endl;
            cout << "Endereço: " << imoveis[i].endereco << endl;
            cout << "Bairro: " << imoveis[i].bairro << endl;
            cout << "Cidade: " << imoveis[i].cidade << endl;
            cout << "Área: " << imoveis[i].area << " m²" << endl;
            cout << "Valor: R$" << imoveis[i].valor << endl;
            cout << "IPTU: R$" << imoveis[i].iptu << endl;
            cout << "Quartos: " << imoveis[i].quartos << endl;
            cout << "Suítes: " << imoveis[i].suites << endl;
            cout << "Banheiros: " << imoveis[i].banheiros << endl;
            cout << "Vagas de garagem: " << imoveis[i].vagas << endl;
            cout << "Cozinha: " << imoveis[i].cozinha << endl;
            cout << "Sala: " << imoveis[i].sala << endl;
            cout << "Varanda: " << imoveis[i].varanda << endl;
            cout << "Área de serviço: " << imoveis[i].area_servico << endl;
            cout << "Piso: " << imoveis[i].piso << endl;
            cout << "Estado de conservação: " << imoveis[i].conservacao << endl;
            cout << "Armários embutidos: " << (imoveis[i].armarios_embutidos ? "sim" : "não") << endl;
            cout << "Ar-condicionado: " << (imoveis[i].ar_condicionado ? "sim" : "não") << endl;
            cout << "Aquecedor: " << (imoveis[i].aquecedor ? "sim" : "não") << endl;
            cout << "Ventilador: " << (imoveis[i].ventilador ? "sim" : "não") << endl;

            // Solicita ao usuário as novas informações do imóvel
            cout << "\nDigite as novas informações do imóvel:\n";
            cout << "Digite o tipo do imóvel (Casa, Apartamento, Sala, etc.): ";
            cin.ignore();            // Limpa o buffer do cin antes de getline
            getline(cin, tipo_temp); // Lê o tipo temporariamente
            // Este laço percorre cada caractere da string tipo_temp
            // Coloca como minúscula
            if (!tipo_temp.empty())
            {
                for (size_t j = 0; j < tipo_temp.length(); j++)
                {
                    tipo_temp[j] = tolower(tipo_temp[j]);
                }
            }
            // Substitui espaços por sublinhados
            for (size_t j = 0; j < tipo_temp.length(); j++)
            {
                if (tipo_temp[j] == ' ')
                {
                    tipo_temp[j] = '_';
                }
            }
            imoveis[i].tipo = tipo_temp; // Armazena o tipo do imóvel

            // Finalidade do imóvel
            cout << "Digite a finalidade (venda, locação, temporada, aluguel): ";
            cin >> imoveis[i].finalidade; // Lê a finalidade do imóvel
            while (imoveis[i].finalidade != "venda" && imoveis[i].finalidade != "locação" && imoveis[i].finalidade != "temporada" &&
                   imoveis[i].finalidade != "aluguel")
            {                 // Enquanto a finalidade não for válida
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Finalidade inválida. Digite 'venda', 'locação', 'aluguel' ou 'temporada'.\n";
                cout << "Digite a finalidade (venda, locação, temporada, aluguel): ";
                cin >> imoveis[i].finalidade; // Lê a finalidade do imóvel
            }

            // Endereço do imóvel
            cout << "Digite o endereço: ";
            cin.ignore();                // Limpa o buffer do cin antes de getline
            getline(cin, endereco_temp); // Lê o endereço temporariamente
            // Formata o endereço: espaços por sublinhado
            for (size_t j = 0; j < endereco_temp.length(); j++)
            {
                if (endereco_temp[j] == ' ')
                {
                    endereco_temp[j] = '_';
                }
            }
            imoveis[i].endereco = endereco_temp; // Lê o endereço completo

            // Bairro
            cout << "Digite o bairro: ";
            getline(cin, bairro_temp); // Lê o bairro
            if (!bairro_temp.empty())
            {
                bairro_temp[0] = toupper(bairro_temp[0]);
                for (size_t j = 1; j < bairro_temp.length(); j++)
                {
                    bairro_temp[j] = tolower(bairro_temp[j]);
                }
            }
            for (size_t j = 0; j < bairro_temp.length(); j++)
            {
                if (bairro_temp[j] == ' ')
                {
                    bairro_temp[j] = '_';
                }
            }
            imoveis[i].bairro = bairro_temp;

            // Cidade
            cout << "Digite a cidade: ";
            getline(cin, cidade_temp); // Lê a cidade
            if (!cidade_temp.empty())
            {
                cidade_temp[0] = toupper(cidade_temp[0]);
                for (size_t j = 1; j < cidade_temp.length(); j++)
                {
                    cidade_temp[j] = tolower(cidade_temp[j]);
                }
            }
            for (size_t j = 0; j < cidade_temp.length(); j++)
            {
                if (cidade_temp[j] == ' ')
                {
                    cidade_temp[j] = '_';
                }
            }
            imoveis[i].cidade = cidade_temp;

            // Área do imóvel
            cout << "Digite a área em m²: ";
            cin >> imoveis[i].area; // Lê a área do imóvel
            while (imoveis[i].area <= 0)
            {                 // Enquanto a área for menor ou igual a zero
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Área inválida. A área deve ser maior que zero.\n";
                cout << "Digite a área em m²: ";
                cin >> imoveis[i].area; // Lê novamente a área do imóvel
            }

            // Valor do imóvel
            cout << "Digite o valor: R$";
            cin >> imoveis[i].valor; // Lê o valor do imóvel
            while (imoveis[i].valor <= 0)
            {                 // Enquanto o valor for menor ou igual a zero
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Valor inválido. O valor deve ser maior que zero.\n";
                cout << "Digite o valor: R$";
                cin >> imoveis[i].valor; // Lê novamente o valor do imóvel
            }

            // IPTU do imóvel
            cout << "Digite o valor do IPTU: R$";
            cin >> imoveis[i].iptu; // Lê o valor do IPTU
            while (imoveis[i].iptu < 0)
            {                 // Enquanto o valor do IPTU for menor que zero
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Valor do IPTU inválido. O valor deve ser maior ou igual a zero.\n";
                cout << "Digite o valor do IPTU: R$";
                cin >> imoveis[i].iptu; // Lê novamente o valor do IPTU
            }

            // Características do imóvel
            cout << "Digite o número de quartos: ";
            cin >> imoveis[i].quartos; // Lê o número de quartos
            while (imoveis[i].quartos < 0)
            {                 // Enquanto o número de quartos for menor que zero
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Número de quartos inválido. O número deve ser maior ou igual a zero.\n";
                cout << "Digite o número de quartos: ";
                cin >> imoveis[i].quartos; // Lê novamente o número de quartos
            }

            // Lê o número de suítes
            cout << "Digite o número de suítes: ";
            cin >> imoveis[i].suites; // Lê o número de suítes
            while (imoveis[i].suites < 0)
            {                 // Enquanto o número de suítes for menor que zero
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Número de suítes inválido. O número deve ser maior ou igual a zero.\n";
                cout << "Digite o número de suítes: ";
                cin >> imoveis[i].suites; // Lê novamente o número de suítes
            }

            // Lê o número de banheiros
            cout << "Digite o número de banheiros: ";
            cin >> imoveis[i].banheiros; // Lê o número de banheiros
            while (imoveis[i].banheiros < 0)
            {                 // Enquanto o número de banheiros for menor que zero
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Número de banheiros inválido. O número deve ser maior ou igual a zero.\n";
                cout << "Digite o número de banheiros: ";
                cin >> imoveis[i].banheiros; // Lê novamente o número de banheiros
            }

            // Lê o número de vagas de garagem
            cout << "Digite o número de vagas de garagem: ";
            cin >> imoveis[i].vagas; // Lê o número de vagas de garagem
            while (imoveis[i].vagas < 0)
            {                 // Enquanto o número de vagas for menor que zero
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Número de vagas inválido. O número deve ser maior ou igual a zero.\n";
                cout << "Digite o número de vagas de garagem: ";
                cin >> imoveis[i].vagas; // Lê novamente o número de vagas de garagem
            }

            // Características adicionais do imóvel
            // Cozinha
            cout << "Possui cozinha? (sim/não): ";
            cin >> imoveis[i].cozinha; // Lê se possui cozinha
            while (imoveis[i].cozinha != "sim" && imoveis[i].cozinha != "não")
            {
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                cout << "Possui cozinha? (sim/não): ";
                cin >> imoveis[i].cozinha; // Lê novamente se possui cozinha
            }

            // Sala
            cout << "Possui sala? (sim/não): ";
            cin >> imoveis[i].sala; // Lê
            while (imoveis[i].sala != "sim" && imoveis[i].sala != "não")
            {
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                cout << "Possui sala? (sim/não): ";
                cin >> imoveis[i].sala; // Lê novamente se possui sala
            }

            // Varanda
            cout << "Possui varanda? (sim/não): ";
            cin >> imoveis[i].varanda;
            while (imoveis[i].varanda != "sim" && imoveis[i].varanda != "não")
            {
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                cout << "Possui varanda? (sim/não): ";
                cin >> imoveis[i].varanda; // Lê novamente se possui varanda
            }

            // Área de serviço
            cout << "Possui área de serviço? (sim/não): ";
            cin >> imoveis[i].area_servico;
            while (imoveis[i].area_servico != "sim" && imoveis[i].area_servico != "não")
            {
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                cout << "Possui área de serviço? (sim/não): ";
                cin >> imoveis[i].area_servico; // Lê novamente se possui área de serviço
            }

            // Piso do imóvel
            cout << "Tipo de piso: ";
            cin >> imoveis[i].piso;
            for (size_t j = 0; j < imoveis[i].piso.length(); j++)
            {
                if (imoveis[i].piso[j] == ' ')
                {
                    imoveis[i].piso[j] = '_';
                }
                else
                {
                    imoveis[i].piso[j] = tolower(imoveis[i].piso[j]);
                }
            }

            // Estado de conservação do imóvel
            cout << "Estado de conservação: (péssimo, ruim, regular, bom, ótimo, novo) ";
            cin >> imoveis[i].conservacao;
            while (imoveis[i].conservacao != "péssimo" && imoveis[i].conservacao != "ruim" &&
                   imoveis[i].conservacao != "regular" && imoveis[i].conservacao != "bom" &&
                   imoveis[i].conservacao != "ótimo" && imoveis[i].conservacao != "novo")
            {
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Estado de conservação inválido. Digite 'péssimo', 'ruim', 'regular', 'bom', 'ótimo' ou 'novo'.\n";
                cout << "Estado de conservação: (péssimo, ruim, regular, bom, ótimo, novo) ";
                cin >> imoveis[i].conservacao; // Lê novamente o estado de conservação
            }

            // Características adicionais (armários, ar-condicionado, aquecedor, ventilador)
            // Armários embutidos
            cout << "Possui armários embutidos? (sim/não): ";
            cin >> temp_bool;
            while (temp_bool != "sim" && temp_bool != "não")
            {                 // Enquanto a resposta não for válida
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                cout << "Possui armários embutidos? (sim/não): ";
                cin >> temp_bool; // Lê novamente se possui armários embutidos
            }
            imoveis[i].armarios_embutidos = (temp_bool == "sim");

            // Ar-condicionado
            cout << "Possui ar-condicionado? (sim/não): ";
            cin >> temp_bool;
            while (temp_bool != "sim" && temp_bool != "não")
            {                 // Enquanto a resposta não for válida
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                cout << "Possui ar-condicionado? (sim/não): ";
                cin >> temp_bool; // Lê novamente se possui ar-condicionado
            }
            imoveis[i].ar_condicionado = (temp_bool == "sim");

            // Aquecedor
            cout << "Possui aquecedor? (sim/não): ";
            cin >> temp_bool;
            while (temp_bool != "sim" && temp_bool != "não")
            {                 // Enquanto a resposta não for válida
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                cout << "Possui aquecedor? (sim/não): ";
                cin >> temp_bool; // Lê novamente se possui aquecedor
            }
            imoveis[i].aquecedor = (temp_bool == "sim");

            // Ventilador
            cout << "Possui ventilador? (sim/não): ";
            cin >> temp_bool;
            while (temp_bool != "sim" && temp_bool != "não")
            {                 // Enquanto a resposta não for válida
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
                cout << "Possui ventilador? (sim/não): ";
                cin >> temp_bool; // Lê novamente se possui ventilador
            }
            imoveis[i].ventilador = (temp_bool == "sim");

            cout << "\nImóvel editado com sucesso!\n"; // Mensagem de sucesso
            choice = 1;                                // Vai para opção 1 para perguntar se deseja voltar ao menu principal ou sair do programa
            break;

        case 9:
            limparTela(); // Limpa a tela antes de solicitar o número do imóvel
            cout << "Digite o número do imóvel a ser removido (1 a " << num_imoveis << "): ";
            cin >> i; // Lê o número do imóvel
            i--;      // Ajusta o índice para começar de 0
            while (i < 0 || i >= num_imoveis)
            {                 // Verifica se o número do imóvel é válido
                limparTela(); // Limpa a tela para melhor visualização
                cout << "ERROR - Número de imóvel inválido. Digite um número entre 1 e " << num_imoveis << ".\n";
                cout << "Digite o número do imóvel a ser removido (1 a " << num_imoveis << "): ";
                cin >> i; // Lê novamente o número do imóvel
                i--;      // Ajusta o índice para começar de 0
            }
            // Remove o imóvel do vetor
            for (int j = i; j < num_imoveis - 1; j++)
            {
                imoveis[j] = imoveis[j + 1]; // Move os imóveis para preencher o espaço
            }
            num_imoveis--; // Decrementa o número de imóveis
            cout << "\nImóvel removido com sucesso!\n"; // Mensagem de sucesso
            choice = 1; // Vai para opção 1 para perguntar se deseja voltar ao menu principal ou sair do programa
            break;
        }
    }

    limparTela(); // Limpa a tela antes de encerrar o programa
    // Mensagem de encerramento - questiona se deseja atualizar os dados no arquivo BD_Imoveis2.txt
    cout << "\nDeseja atualizar os dados no arquivo BD_Imoveis2.txt? (s/n): ";
    cin >> resposta; // Lê a resposta do usuário
    while (resposta != "s" && resposta != "S" && resposta != "n" && resposta != "N")
    {
        cout << "ERROR - Opção inválida.\n\n";
        cout << "\nDeseja atualizar os dados no arquivo BD_Imoveis2.txt? (s/n): ";
        cin >> resposta; // Solicita novamente a resposta
    }
    if (resposta == "s" || resposta == "S")
    {
        // Atualiza os dados no arquivo BD_Imoveis2.txt
        ofstream arquivo_saida("BD_Imoveis2.txt"); // Abre o arquivo para escrita
        if (!arquivo_saida.is_open())
        {
            cerr << "Erro ao abrir o arquivo BD_Imoveis2.txt para escrita." << endl;
            return 1; // Retorna erro se o arquivo não puder ser aberto
        }
        arquivo_saida << "Tipo Finalidade Endereço Bairro Cidade Área Valor IPTU Quartos Suítes Banheiros Vagas Cozinha Sala Varanda Área_de_serviço Piso Conservação Armários Ar-condicionado Aquecedor Ventilador\n"; // Escreve o cabeçalho do arquivo
        // Escreve os dados atualizados no arquivo
        for (i = 0; i < num_imoveis; i++)
        {
            arquivo_saida << imoveis[i].tipo << " "
                          << imoveis[i].finalidade << " "
                          << imoveis[i].endereco << " "
                          << imoveis[i].bairro << " "
                          << imoveis[i].cidade << " "
                          << imoveis[i].area << " "
                          << imoveis[i].valor << " "
                          << imoveis[i].iptu << " "
                          << imoveis[i].quartos << " "
                          << imoveis[i].suites << " "
                          << imoveis[i].banheiros << " "
                          << imoveis[i].vagas << " "
                          << imoveis[i].cozinha << " "
                          << imoveis[i].sala << " "
                          << imoveis[i].varanda << " "
                          << imoveis[i].area_servico << " "
                          << imoveis[i].piso << " "
                          << imoveis[i].conservacao << " "
                          << (imoveis[i].armarios_embutidos ? "sim" : "não") << " "
                          << (imoveis[i].ar_condicionado ? "sim" : "não") << " "
                          << (imoveis[i].aquecedor ? "sim" : "não") << " "
                          << (imoveis[i].ventilador ? "sim" : "não")
                          << endl;
        }
        arquivo_saida << "fim"; // Adiciona a linha "fim" ao final do arquivo
        arquivo_saida.close();  // Fecha o arquivo após a escrita
        cout << "\nDados atualizados com sucesso no arquivo BD_Imoveis2.txt.\n";
    }
    else
    {
        cout << "\nOs dados não foram atualizados no arquivo BD_Imoveis2.txt.\n";
    }
    // Mensagem de encerramento
    cout << "\n\nPrograma encerrado.\n\n";
    return 0;
}