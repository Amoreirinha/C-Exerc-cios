Gerenciador de Imóveis C++
========================================

--------------------------

Descrição do Projeto
--------------------------

Este é um Aplicativo para Gestão de Imóveis desenvolvido em C++. Ele foi criado com o objetivo de aprimorar habilidades na manipulação de registros armazenados em vetores e na utilização de estruturas de controle para gerar estatísticas. O programa permite gerenciar informações sobre imóveis disponíveis para venda, locação ou temporada, lendo e escrevendo dados de um arquivo texto.

--------------------------

Funcionalidades Principais
--------------------------

O sistema oferece um menu interativo com as seguintes operações:

• Inclusão de um Novo Imóvel: Adiciona um novo registro de imóvel à base de dados.
• Busca de Imóveis por Faixa de Valores: Permite pesquisar imóveis com base em seus valores (para locação, venda ou temporada).
• Busca de Imóveis por Características: Filtra imóveis com base em características específicas, como:
     Armários embutidos
     Ar-condicionado
     Aquecedor
     Ventilador
• Busca por Número de Quartos e Suítes: Localiza imóveis que atendem a critérios de quantidade de quartos e suítes.
• Relatório Estatístico: Gera um relatório detalhado contendo:
     Percentual de imóveis por finalidade (venda, locação, temporada).
     Percentual de casas com suítes.
     Percentual de salas comerciais com piso cerâmico.
     Listagem completa de todos os imóveis disponíveis.
• Visualizar Lista de Imóveis: Exibe todos os imóveis carregados na base de dados.

--------------------------

Estrutura do Aplicativo
--------------------------

O programa inicia lendo os dados do arquivo `BDImoveis2.txt` e os armazena em um vetor de registros, com capacidade máxima de 200 imóveis. Cada linha do arquivo corresponde a um imóvel e é carregada na ordem. Ao final da execução, os dados atualizados são gravados de volta no mesmo arquivo.

Observação Importante: O vetor de registros não permite "espaços vazios". Ao excluir um imóvel, os registros subsequentes são automaticamente deslocados para a esquerda para manter a sequência contínua dos dados.

--------------------------

Formato do Arquivo de Imóveis (`BDImoveis2.txt`)
--------------------------

O arquivo de dados contém até 200 linhas, onde cada linha representa um imóvel e é composta por 22 campos, separados por espaços.

Campos por Linha:

1.  Tipo: Tipo do imóvel (ex: `casa`, `apartamento`, `salacomercial`).
2.  Finalidade: `venda`, `locacao`, `temporada`.
3.  Endereço
4.  Bairro
5.  Cidade
6.  Área: Em metros quadrados.
7.  Valor: Preço ou valor de locação.
8.  IPTU
9.  Quartos
10. Suítes
11. Banheiros
12. Vagas: Número de vagas na garagem.
13. Cozinha: (ex: `sim`/`nao` ou `padrao`/`americana`).
14. Sala: (ex: `sim`/`nao`).
15. Varanda: (ex: `sim`/`nao`).
16. Área de Serviço: (ex: `sim`/`nao`).
17. Piso: Tipo de piso (ex: `ceramico`, `madeira`).
18. Conservação: Estado de conservação (ex: `bom`, `regular`, `ruim`).
19. Armários: (`sim`/`nao`).
20. Ar-condicionado: (`sim`/`nao`).
21. Aquecedor: (`sim`/`nao`).
22. Ventilador: (`sim`/`nao`).

Regras Específicas do Arquivo:

• A primeira linha do arquivo, que geralmente contém os cabeçalhos das colunas, é ignorada durante a leitura.
• A última linha, que contém a palavra "fim" no campo do tipo de imóvel, não é considerada nos cálculos ou na base de dados de imóveis.

--------------------------

Como Compilar e Executar
--------------------------

Requisitos
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

• Compilador C++ (recomendado: g++).

Passos
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1.  Salve o código: Certifique-se de que o arquivo `.cpp` (por exemplo, `main.cpp`) e o arquivo de dados `BDImoveis2.txt` estão no mesmo diretório.
2.  Compile o código: Abra um terminal ou prompt de comando e navegue até o diretório onde você salvou os arquivos. Em seguida, compile o programa usando um compilador C++:

    [/CODE]
bash
    g++ main.cpp -o gerenciadorimoveis
    [/CODE]


    Se o nome do seu arquivo `.cpp` for diferente, substitua `main.cpp` pelo nome correto.

3.  Execute o programa: Após a compilação, você pode executar o programa:

    [/CODE]
bash
    ./gerenciadorimoveis
    [/CODE]


O programa exibirá o menu de opções, e você poderá interagir com ele através do console.

--------------------------

Tecnologias Utilizadas
--------------------------

• C++: Linguagem de programação principal.
• fstream: Para manipulação de arquivos (leitura/escrita).
• iostream: Para entrada e saída de dados no console.
• string: Para manipulação de cadeias de caracteres.

--------------------------

Explicação do Código-Fonte (main.cpp)
--------------------------
O arquivo main.cpp contém toda a lógica do programa de gerenciamento de imóveis. A seguir, descrevemos os principais blocos do código para facilitar a compreensão de sua estrutura e funcionamento.

--------------------------

Inclusão de Bibliotecas
--------------------------

[/CODE]
c++
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string.h>
[/CODE]


Essas bibliotecas oferecem funcionalidades essenciais:

• cstdlib: Funções utilitárias (como system).
• fstream: Leitura e escrita em arquivos.
• iostream: Entrada e saída de dados pelo console.
• string.h: Manipulação de strings (poderia ser substituída por <string> para uso de std::string).

--------------------------

Função limparTela
--------------------------

[/CODE]
c++
void limparTela() {
    cout << "\033[H\033[J";
}
[/CODE]


Utiliza códigos de escape ANSI para limpar o terminal, proporcionando uma melhor experiência visual ao usuário.

--------------------------

🧾 Objetivo da Função
--------------------------
A função barradeporcentagem gera uma representação visual em texto de uma barra de progresso, com base em um valor percentual (entre 0 e 100). Ela retorna uma string com 100 caracteres, que mostra graficamente o quanto está "preenchido".

📌 Assinatura da Função
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

[/CODE]
c++
string barradeporcentagem(float valor)
[/CODE]

• Parâmetro: valor → um número decimal representando a porcentagem (por exemplo, 45.7).

• Retorno: uma string com uma barra de progresso estilizada com blocos (cheios e vazios).

🧠 Funcionamento Passo a Passo
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
[/CODE]
c++
string barra = "█";
string vazio = "░";
[/CODE]

Define dois caracteres para construir a barra:

• `█` representa a parte preenchida da barra.

• `░` representa a parte vazia da barra.

[/CODE]
c++
int tamanho = 100;
[/CODE]

Define que a barra terá 100 "blocos" no total, representando 100%.

[/CODE]
c++
int preenchimento = staticcast<int>(valor);
[/CODE]

Converte o valor de porcentagem em inteiro.

Por exemplo: se valor for 75.6, preenchimento será 75.

Ou seja, os primeiros 75 blocos serão "█", os restantes 25 serão "░".

[/CODE]
c++
string resultado = "[";
[/CODE]

Inicia a construção da string com um colchete de abertura.

[/CODE]
c++
for (int i = 0; i < tamanho; i++)
{
    if (i < preenchimento)
        resultado += barra;
    else
        resultado += vazio;
}
[/CODE]

Laço que constrói a barra caractere por caractere:

Se o índice for menor que preenchimento, adiciona `█`.

Caso contrário, adiciona `░`.

[/CODE]
c++
resultado += "]";
[/CODE]

Fecha a barra com colchete final.

✅ Exemplo de Uso
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
[/CODE]
c++

cout << barradeporcentagem(42.3);
[/CODE]

Saída esperada:

[/CODE]
css

[████████████████████████████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░]
[/CODE]

(42 blocos preenchidos, 58 blocos vazios)

🎯 Resumo
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 |  Elemento  |  Função  | 
 | :--------------------------: | :--------------------------: | 
 | `█` | 	Bloco que indica preenchimento | 
 | `░` | 	Bloco que indica espaço vazio | 
 | `valor` | 	Percentual a ser visualizado (0–100) | 
 | `staticcast<int>` | 	Uma forma segura e explícita de converter tipos de dados em C++ | 
 | `Resultado final` | 	Barra como string entre colchetes

--------------------------

Definição da Estrutura imovel
--------------------------

[/CODE]
c++
struct imovel {
    string tipo, finalidade, endereco, bairro, cidade;
    float area, valor, iptu;
    int quartos, suites, banheiros, vagas;
    string cozinha, sala, varanda, areaservico;
    string piso, conservacao;
    string armarios, arcondicionado, aquecedor, ventilador;
};
[/CODE]


Cada objeto da estrutura representa um imóvel, com todos os campos refletindo os dados de uma linha do arquivo BDImoveis2.txt.

--------------------------

Função Principal [/CODE]
 main [/CODE]

--------------------------
A função `main()` é responsável por:

• Declarar o vetor de imóveis (imovel imoveis[200]).
• Chamar funções auxiliares para:
• Ler dados do arquivo.
• Apresentar o menu interativo.
• Executar as opções conforme a escolha do usuário.
• Gravar os dados atualizados de volta no arquivo.

--------------------------

Funções Auxiliares
--------------------------
O código está organizado em várias funções auxiliares que realizam tarefas específicas, como:

• Leitura e escrita no arquivo: Lê os imóveis do arquivo texto para o vetor e salva as alterações.
• Inclusão de imóvel: Adiciona um novo registro com entrada do usuário.
• Filtros de busca: Permite busca por valor, características, número de quartos, etc.
• Relatório estatístico: Gera estatísticas e percentuais com base nos imóveis cadastrados.
• Remoção: Exclui um imóvel e reorganiza o vetor para evitar espaços vazios.

--------------------------

Manipulação do Arquivo
--------------------------
A leitura do arquivo ocorre ignorando a primeira linha (cabeçalho) e a última (linha com o campo tipo igual a "fim"). Durante a execução, o vetor é atualizado em tempo real, e os dados são sobrescritos no final da execução para garantir persistência.

--------------------------

📥 Leitura dos Dados do Arquivo BDImoveis2.txt
--------------------------
Antes de exibir ou manipular os dados, o programa realiza a leitura inicial do arquivo de imóveis (BDImoveis2.txt) para carregar as informações existentes na memória.

[/CODE]
c++
    ifstream arquivo("BDImoveis2.txt");
    if (!arquivo.isopen()) {
        cerr << "Erro ao abrir o arquivo BDImoveis2.txt" << endl;
        return 1;
    }
    string linha;
    getline(arquivo, linha);
    for(i=0; i < MAXIMOVEIS; i++) {
        arquivo >> linha;
        if (linha == "fim") break;
        imoveis[i].tipo = linha;
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
        arquivo >> imoveis[i].areaservico;
        arquivo >> imoveis[i].piso;
        arquivo >> imoveis[i].conservacao;
        string temparmarios, temparcondicionado, tempaquecedor, tempventilador;
        arquivo >> temparmarios;
        imoveis[i].armariosembutidos = (temparmarios == "sim");
        arquivo >> temparcondicionado;
        imoveis[i].arcondicionado = (temparcondicionado == "sim");
        arquivo >> tempaquecedor;
        imoveis[i].aquecedor = (tempaquecedor == "sim");
        arquivo >> tempventilador;
        imoveis[i].ventilador = (tempventilador == "sim");
        numimoveis++;
    }
    arquivo.close();
    cout << "Total de imóveis lidos: " << numimoveis << endl;

    limparTela();
[/CODE]

• Observação

    O trecho do código
    [/CODE]
c++
    getline(arquivo, linha);
    [/CODE]

    lê uma linha inteira do arquivo BDImoveis2.txt e armazena o conteúdo na variável linha. No contexto desse código, ela serve para descartar a primeira linha do arquivo, que normalmente contém apenas o cabeçalho (nomes das colunas), evitando que seja processada como um imóvel válido.

    Resumo:
    `getline` lê uma linha completa do arquivo de texto, diferente do operador `>>`, que lê apenas até o próximo espaço.

Funcionamento:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. Abertura do Arquivo:
Utiliza a biblioteca fstream (ifstream) para abrir o arquivo em modo de leitura.
Se o arquivo não puder ser aberto, o programa exibe uma mensagem de erro e encerra.
2. Cabeçalho Ignorado:
A primeira linha do arquivo é lida e descartada por conter apenas os nomes das colunas. Isso evita que seja processada como um imóvel válido.
3. Leitura das Linhas de Imóveis:
Cada linha subsequente do arquivo representa um imóvel.
A leitura continua até encontrar a palavra-chave fim, que marca o fim dos registros válidos.
4. Armazenamento no Vetor de Registros:
Cada campo da linha é lido e armazenado na estrutura de dados imovel.
Os campos booleanos (armariosembutidos, arcondicionado, aquecedor, ventilador) são lidos como strings (`sim`/`nao`) e convertidos para valores `true` ou `false`.
5. Controle de Quantidade:
O vetor comporta no máximo 200 imóveis, e cada registro lido incrementa o contador numimoveis.
6. Encerramento da Leitura:
Após o término da leitura, o arquivo é fechado com segurança.
O programa então exibe no console a quantidade total de imóveis carregados.

Exemplo de Uso:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Se o arquivo contiver 50 imóveis e a linha final for "fim", o console exibirá:

[/CODE]
bash
Total de imóveis lidos: 50
[/CODE]

Observações Técnicas
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Utiliza estrutura de repetição for e controle com break para parar na linha "fim".

A conversão de campos `sim` ou `nao` para booleanos é feita com a expressão:

[/CODE]
c++
imoveis[i].armariosembutidos = (armarios == "sim");
[/CODE]


• 🧠 Como isso funciona, passo a passo:
    1. Leitura da string:
        Antes dessa linha, o código já leu o valor do campo como string:
        [/CODE]
c++
        string armarios;
        arquivo >> armarios;
        [/CODE]

        Agora, armarios pode conter "sim" ou "nao".
    2. Comparação lógica:
        [/CODE]
c++
        (armarios == "sim")
        [/CODE]

        Essa expressão compara se o conteúdo da string é exatamente igual a `sim`.
         Se for igual, o resultado da comparação é `true`.
         Se for diferente, o resultado é `false`.
    3. Atribuição do valor booleano:
        O valor `true` ou `false` é atribuído ao campo:
        [/CODE]
c++
        imoveis[i].armariosembutidos = (temparmarios == "sim");
        [/CODE]

        Assim:
         Se o texto no arquivo era `sim`, o campo armariosembutidos receberá `true`.
         Se era `nao`, o campo receberá `false`.

Essa abordagem garante que todos os imóveis válidos sejam lidos corretamente e que o vetor esteja pronto para as demais operações do sistema.

--------------------------

Estrutura do Menu
--------------------------
O menu principal é exibido no terminal, oferecendo ao usuário diversas opções numeradas para interação. Cada escolha leva a uma função correspondente, que realiza a ação desejada (inclusão, busca, estatísticas, listagem etc.).
[/CODE]
c++
case 0:
            limparTela();
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
            cin >> choice;
            while (choice < 1  |  |  choice > 8){ 
                limparTela();
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
                cin >> choice;
            }
            choice++;
            break;
[/CODE]

O código utiliza da função `limparTela()`; e cout's para mostrar um menu no terminal do usuário.

Há também uma validação de dados utilizando um loop `while` para que, caso seja selecionado um número inválido, ele não avance no código e continue pedindo uma opção válida de escolha.

Após isso, incrementa 1 a variável `choice` pois o case 1 é um caso aonde o usuário é perguntado se deseja voltar ao menu ou sair do programa.

--------------------------
`Case 1` - Voltar ao menu ou sair do programa
--------------------------

🎯 Objetivo do Código
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Este bloco pergunta ao usuário se ele deseja voltar ao menu principal ou sair do programa, e responde a isso de forma segura e interativa, com verificação de entrada.

[/CODE]
c++
case 1:
    cout << "\n\nDeseja voltar ao menu principal? Digite 's' para SIM ou 'n' para NÃO: ";
    resposta = "x";
    cin >> resposta;
    if (resposta == "s"  |  |  resposta == "S"){
        choice = 0;
        limparTela();
    }else if (resposta == "n"  |  |  resposta == "N"){
        continuar = false;
    }else{
        while (resposta != "s" && resposta != "S" && resposta != "n" && resposta != "N"){
            cout << "Opção inválida. Digite 's' para SIM ou 'n' para NÃO: ";
            cin >> resposta;
        }
        if (resposta == "s"  |  |  resposta == "S"){
            choice = 0;
            limparTela();
        }else if (resposta == "n"  |  |  resposta == "N"){
            continuar = false;
        }
    }
    break;
[/CODE]


🔍 Explicação Linha a Linha
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
[/CODE]
c++
case 1:
[/CODE]

Trata a opção 1 do menu (poderia ser, por exemplo, "Sair ou voltar").

[/CODE]
c++
cout << "\n\nDeseja voltar ao menu principal? Digite 's' para SIM ou 'n' para NÃO: ";
[/CODE]

Pergunta ao usuário o que ele deseja fazer a seguir.

[/CODE]
c++
resposta = "x"; // Inicializa a resposta com um valor inválido
cin >> resposta;
[/CODE]


Inicializa a variável resposta com algo que não é 's' nem 'n', para garantir que entre na verificação.

Em seguida, lê o que o usuário digitou.

[/CODE]
c++
if (resposta == "s"  |  |  resposta == "S")
[/CODE]

Se a resposta for "s" ou "S", então...

[/CODE]
c++
choice = 0;
limparTela();
[/CODE]

...volta ao menu principal (choice = 0) e limpa a tela com a função limparTela().

[/CODE]
c++
else if (resposta == "n"  |  |  resposta == "N"){
    continuar = false; // Encerra o loop e o programa
}
[/CODE]

Se a resposta for "n" ou "N", define continuar = false, o que provavelmente encerra o programa (já que deve haver um while(continuar) em algum lugar).

[/CODE]
c++
else {
    while (resposta != "s" && resposta != "S" && resposta != "n" && resposta != "N"){
        cout << "Opção inválida. Digite 's' para SIM ou 'n' para NÃO: ";
        cin >> resposta;
    }
[/CODE]


Se a resposta não for válida (qualquer outra coisa além de 's', 'S', 'n' ou 'N'), entra em um loop de repetição, pedindo para o usuário digitar novamente até ele acertar.


[C++ CODE]
    if (resposta == "s"  |  |  resposta == "S"){
        choice = 0;
        limparTela();
    }else if (resposta == "n"  |  |  resposta == "N"){
        continuar = false;
    }
[/CODE]


Após o loop de validação, o código executa novamente a ação correta de acordo com a resposta final.

[/CODE]
c++
break;
[/CODE]

Finaliza o case 1, voltando ao controle principal do switch.

--------------------------
Exibir lista de imóveis
--------------------------
Este trecho de código faz parte de um menu de opções de um programa em C++ voltado para o gerenciamento de imóveis. A opção case 2 é responsável por listar os imóveis cadastrados no sistema, exibindo suas principais características.
[/CODE]
c++
case 2:
    cout << "Lista de Imóveis:\n";
    for (i = 0; i < numimoveis; i++){
        cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", "
                << imoveis[i].finalidade << ", "
                << imoveis[i].endereco << ", "
                << imoveis[i].bairro << ", "
                << imoveis[i].cidade << ", "
                << imoveis[i].area << " m², ";
        if (imoveis[i].finalidade == "aluguel"){
            cout << "Aluguel(dia): R$" << imoveis[i].valor << endl;
        } else {
            cout << "Venda: R$" << imoveis[i].valor << endl;
        }
    }
    choice = 1;
    break;
[/CODE]


🧠 O que o Código Faz?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. Mostra um cabeçalho na tela
    [/CODE]
c++
    cout << "Lista de Imóveis:\n";
    [/CODE]

    Exibe o título da lista para o usuário.

2. Percorre todos os imóveis cadastrados
    [/CODE]
c++
    for (i = 0; i < numimoveis; i++)
    [/CODE]

    Usa um loop for para iterar de 0 até o número de imóveis `(numimoveis)`.

    `i` é o índice usado para acessar cada imóvel individualmente.

3. Exibe as informações de cada imóvel
    [/CODE]
c++
    cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", "
        << imoveis[i].finalidade << ", "
        << imoveis[i].endereco << ", "
        << imoveis[i].bairro << ", "
        << imoveis[i].cidade << ", "
        << imoveis[i].area << " m², ";
    [/CODE]

    Mostra:
     Número do imóvel (começando em 1)
     Tipo (ex: casa, apartamento)
     Finalidade (ex: aluguel ou venda)
     Endereço completo: endereço, bairro, cidade
     Área em metros quadrados (m²)

4. Mostra o valor com base na finalidade
    [/CODE]
c++
    if (imoveis[i].finalidade == "aluguel"){
        cout << "Aluguel(dia): R$" << imoveis[i].valor << endl;
    } else {
        cout << "Venda: R$" << imoveis[i].valor << endl;
    }
    [/CODE]

    Se a finalidade do imóvel for aluguel, mostra o valor por dia.

    Se for venda, mostra o valor total.

5. Define o próximo passo do menu
    [/CODE]
c++
    choice = 1;
    [/CODE]

    Após mostrar todos os imóveis, o programa força a próxima opção como `choice = 1`, que  leva o usuário a decidir se deseja voltar ao menu principal ou sair do sistema.

--------------------------
Inclusão de um Novo Imóvel
--------------------------
Este trecho de código refere-se ao caso 3 de um menu de sistema para inclusão de novos imóveis em um banco de dados, presumivelmente utilizando vetores e structs em C++.

Objetivo
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
O objetivo principal é coletar do usuário todas as informações necessárias para cadastrar um novo imóvel, assegurando a validação de dados e o formato padronizado.

[/CODE]
c++
case 3:
    limparTela();
    cout << "Inclusão de um Novo Imóvel\n";
    if (numimoveis >= MAXIMOVEIS){
        cout << "ERROR - Banco de dados cheio. Não é possível incluir mais imóveis.\n";
        choice = 1;
        break;
    } else {
        (limparTela());
        cout << "Digite o tipo do imóvel (Casa, Apartamento, Sala, etc.): ";
        cin.ignore();
        getline(cin, tipotemp);
        if (!tipotemp.empty()){
            for (sizet j = 0; j < tipotemp.length(); j++){
                tipotemp[j] = tolower(tipotemp[j]);
            }
        }
        for (sizet j = 0; j < tipotemp.length(); j++){
            if (tipotemp[j] == ' '){
                tipotemp[j] = '';
            }
        }
        imoveis[numimoveis].tipo = tipotemp;
        cout << "Digite a finalidade (venda, locação, temporada, aluguel): ";
        cin >> imoveis[numimoveis].finalidade;
        while (imoveis[numimoveis].finalidade != "venda" && imoveis[numimoveis].finalidade != "locação" && imoveis[numimoveis].finalidade != "temporada" && imoveis[numimoveis].finalidade != "aluguel"{
            limparTela();
            cout << "ERROR - Finalidade inválida. Digite 'venda', 'locação' ou 'temporada'.\n";
            cout << "Digite a finalidade (venda, locação, temporada): ";
            cin >> imoveis[numimoveis].finalidade;
        }
        cout << "Digite o endereço: ";
        getline(cin, enderecotemp);
        for (sizet j = 0; j < enderecotemp.length(); j++){
            if (enderecotemp[j] == ' '){
                enderecotemp[j] = '';
            }
        }
        imoveis[numimoveis].endereco = enderecotemp;
        string bairrotemp;
        cout << "Digite o bairro: ";
        getline(cin, bairrotemp);
        if (!bairrotemp.empty()){
            bairrotemp[0] = toupper(bairrotemp[0]);
            for (sizet j = 1; j < bairrotemp.length(); j++){
                bairrotemp[j] = tolower(bairrotemp[j]);
            }
        }
        for (sizet j = 0; j < bairrotemp.length(); j++){
            if (bairrotemp[j] == ' '){
                bairrotemp[j] = '';
            }
        }
        imoveis[numimoveis].bairro = bairrotemp;
        string cidadetemp;
        cout << "Digite a cidade: ";
        getline(cin, cidadetemp);
        if (!cidadetemp.empty()){
            cidadetemp[0] = toupper(cidadetemp[0]);
            for (sizet j = 1; j < cidadetemp.length(); j++){
                cidadetemp[j] = tolower(cidadetemp[j]);
            }
        }
        for (sizet j = 0; j < cidadetemp.length(); j++){
            if (cidadetemp[j] == ' '){
                cidadetemp[j] = '';
            }
        }
        imoveis[numimoveis].cidade = cidadetemp;
        cout << "Digite a área em m²: ";
        cin >> imoveis[numimoveis].area;
        while (imoveis[numimoveis].area <= 0){
            limparTela();
            cout << "ERROR - Área inválida. A área deve ser maior que zero.\n";
            cout << "Digite a área em m²: ";
            cin >> imoveis[numimoveis].area;
        }
        cout << "Digite o valor: R$";
        cin >> imoveis[numimoveis].valor;
        while (imoveis[numimoveis].valor <= 0){
            limparTela();
            cout << "ERROR - Valor inválido. O valor deve ser maior que zero.\n";
            cout << "Digite o valor: R$";
            cin >> imoveis[numimoveis].valor;
        }
        cout << "Digite o valor do IPTU: R$";
        cin >> imoveis[numimoveis].iptu;
        while (imoveis[numimoveis].iptu < 0){
            limparTela();
            cout << "ERROR - Valor do IPTU inválido. O valor deve ser maior ou igual a zero.\n";
            cout << "Digite o valor do IPTU: R$";
            cin >> imoveis[numimoveis].iptu;
        }
        cout << "Digite o número de quartos: ";
        cin >> imoveis[numimoveis].quartos;
        while (imoveis[numimoveis].quartos < 0){
            limparTela();
            cout << "ERROR - Número de quartos inválido. O número deve ser maior ou igual a zero.\n";
            cout << "Digite o número de quartos: ";
            cin >> imoveis[numimoveis].quartos;
        }
        cout << "Digite o número de suítes: ";
        cin >> imoveis[numimoveis].suites;
        while (imoveis[numimoveis].suites < 0){
            limparTela();
            cout << "ERROR - Número de suítes inválido. O número deve ser maior ou igual a zero.\n";
            cout << "Digite o número de suítes: ";
            cin >> imoveis[numimoveis].suites;
        }
        cout << "Digite o número de banheiros: ";
        cin >> imoveis[numimoveis].banheiros;
        while (imoveis[numimoveis].banheiros < 0){
            limparTela();
            cout << "ERROR - Número de banheiros inválido. O número deve ser maior ou igual a zero.\n";
            cout << "Digite o número de banheiros: ";
            cin >> imoveis[numimoveis].banheiros;
        }
        cout << "Digite o número de vagas de garagem: ";
        cin >> imoveis[numimoveis].vagas;
        while (imoveis[numimoveis].vagas < 0){
            limparTela();
            cout << "ERROR - Número de vagas inválido. O número deve ser maior ou igual a zero.\n";
            cout << "Digite o número de vagas de garagem: ";
            cin >> imoveis[numimoveis].vagas;
        }
        cout << "Possui cozinha? (sim/não): ";
        cin >> imoveis[numimoveis].cozinha;
        while (imoveis[numimoveis].cozinha != "sim" && imoveis[numimoveis].cozinha != "não"){
            limparTela();
            cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
            cout << "Possui cozinha? (sim/não): ";
            cin >> imoveis[numimoveis].cozinha;
        }
        cout << "Possui sala? (sim/não): ";
        cin >> imoveis[numimoveis].sala;
        while (imoveis[numimoveis].sala != "sim" && imoveis[numimoveis].sala != "não"){
            limparTela();
            cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
            cout << "Possui sala? (sim/não): ";
            cin >> imoveis[numimoveis].sala;
        }
        cout << "Possui varanda? (sim/não): ";
        cin >> imoveis[numimoveis].varanda;
        while (imoveis[numimoveis].varanda != "sim" && imoveis[numimoveis].varanda != "não"){
            limparTela();
            cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
            cout << "Possui varanda? (sim/não): ";
            cin >> imoveis[numimoveis].varanda;
        }
        cout << "Possui área de serviço? (sim/não): ";
        cin >> imoveis[numimoveis].areaservico;
        while (imoveis[numimoveis].areaservico != "sim" && imoveis[numimoveis].areaservico != "não"){
            limparTela();
            cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
            cout << "Possui área de serviço? (sim/não): ";
            cin >> imoveis[numimoveis].areaservico; 
        }
        cout << "Tipo de piso: ";
        cin >> imoveis[numimoveis].piso;
        for (sizet j = 0; j < imoveis[numimoveis].piso.length(); j++){
            if (imoveis[numimoveis].piso[j] == ' ')
            {
                imoveis[numimoveis].piso[j] = '';
            }
            else
            {
                imoveis[numimoveis].piso[j] = tolower(imoveis[numimoveis].piso[j]);
            }
        }
        cout << "Estado de conservação: (péssimo, ruim, regular, bom, ótimo, novo) ";
        cin >> imoveis[numimoveis].conservacao;
        while (imoveis[numimoveis].conservacao != "péssimo" && imoveis[numimoveis].conservacao != "ruim" &&
                imoveis[numimoveis].conservacao != "regular" && imoveis[numimoveis].conservacao != "bom" &&
                imoveis[numimoveis].conservacao != "ótimo" && imoveis[numimoveis].conservacao != "novo"){
            limparTela();
            cout << "ERROR - Estado de conservação inválido. Digite 'péssimo', 'ruim', 'regular', 'bom', 'ótimo' ou 'novo'.\n";
            cout << "Estado de conservação: (péssimo, ruim, regular, bom, ótimo, novo) ";
            cin >> imoveis[numimoveis].conservacao;
        }
        cout << "Possui armários embutidos? (sim/não): ";
        cin >> tempbool;
        while (tempbool != "sim" && tempbool != "não"){
            limparTela();
            cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
            cout << "Possui armários embutidos? (sim/não): ";
            cin >> tempbool;
        }
        imoveis[numimoveis].armariosembutidos = (tempbool == "sim");
        cout << "Possui ar-condicionado? (sim/não): ";
        cin >> tempbool;
        while (tempbool != "sim" && tempbool != "não"){
            limparTela();
            cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
            cout << "Possui ar-condicionado? (sim/não): ";
            cin >> tempbool;
        }
        imoveis[numimoveis].arcondicionado = (tempbool == "sim");
        cout << "Possui aquecedor? (sim/não): ";
        cin >> tempbool;
        while (tempbool != "sim" && tempbool != "não"){
            limparTela();
            cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
            cout << "Possui aquecedor? (sim/não): ";
            cin >> tempbool;
        }
        imoveis[numimoveis].aquecedor = (tempbool == "sim");
        cout << "Possui ventilador? (sim/não): ";
        cin >> tempbool;
        while (tempbool != "sim" && tempbool != "não"){
            limparTela();
            cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
            cout << "Possui ventilador? (sim/não): ";
            cin >> tempbool;
        }
        imoveis[numimoveis].ventilador = (tempbool == "sim");
        numimoveis++;
        cout << "Imóvel incluído com sucesso!\n";
    }
    choice = 1;
    break;
[/CODE]

Funcionamento Passo a Passo
1. Verificação de Capacidade do Banco
    [/CODE]
c++
    if (numimoveis >= MAXIMOVEIS)
    [/CODE]


    Verifica se o número atual de imóveis cadastrados já atingiu o limite (`MAXIMOVEIS`).

    Se sim, exibe uma mensagem de erro e volta ao menu principal (`choice = 1`).

2. Coleta de Dados do Imóvel

    a. Tipo do Imóvel
    [/CODE]
c++
    getline(cin, tipotemp);
    [/CODE]

    Lê uma linha de entrada para armazenar o tipo do imóvel (como "Casa", "Apartamento").

    [/CODE]
c++
    if (!tipotemp.empty())
    [/CODE]

    `.empty()` verifica se a string está vazia (sem caracteres).

    Se não estiver vazia, o tipo é convertido para minúsculas com `tolower()`:

    [/CODE]
c++
    tipotemp[j] = tolower(tipotemp[j]);
    [/CODE]


    `tolower(char c)` transforma um caractere maiúsculo em minúsculo.

    Útil para padronizar o formato dos dados.

    [/CODE]
c++
    if (tipotemp[j] == ' '){
        tipotemp[j] = '';
    [/CODE]


    Substitui espaços por sublinhados `` para facilitar armazenamento e comparação de dados.

    b. Finalidade

    [/CODE]
c++
    cin >> imoveis[numimoveis].finalidade;
    [/CODE]


    Pode ser: venda, locação, temporada, ou aluguel.

    Caso inválido, é solicitado novamente.

    c. Endereço

    [/CODE]
c++
    getline(cin, enderecotemp);
    [/CODE]


    Lê e formata o endereço, substituindo espaços por sublinhados.

3. Formatação de Strings: Bairro e Cidade
    [/CODE]
c++
    bairrotemp[0] = toupper(bairrotemp[0]);
    [/CODE]

    `toupper(char c)` converte o caractere para maiúsculo.

    Utilizado para capitalizar a primeira letra do bairro e cidade.

    [/CODE]
c++
    for (sizet j = 1; j < bairrotemp.length(); j++){
        bairrotemp[j] = tolower(bairrotemp[j]);
    [/CODE]

    `.length()` retorna o número de caracteres da string.

    Utilizado para converter as demais letras em minúsculas.

4. Dados Numéricos
    Coletados com validações para:
     Área (area)
     Valor (valor)
     IPTU (iptu)
     Número de quartos, suítes, banheiros, vagas

    Cada valor é validado para garantir que seja não-negativo ou positivo, conforme o campo.

5. Características Adicionais
    Campos de sim/não:

    Cozinha, sala, varanda, área de serviço

    Armários embutidos, ar-condicionado, aquecedor, ventilador

    Exemplo:

    [/CODE]
c++
    cin >> imoveis[numimoveis].cozinha;
    while (cozinha != "sim" && cozinha != "não") { ... }
    [/CODE]

6. Tipo de Piso
    [/CODE]
c++
    cin >> imoveis[numimoveis].piso;
    [/CODE]

    Convertido todo para minúsculo e espaços substituídos por ``.

7. Estado de Conservação
    Deve ser um valor válido entre: péssimo, ruim, regular, bom, ótimo, novo.

    Valida a entrada e repete em caso de erro.

8. Incremento e Confirmação
    Após todos os dados serem validados e inseridos:

    [/CODE]
c++
    numimoveis++;
    [/CODE]

    O imóvel é registrado e o contador é incrementado.

Explicação dos Comandos
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 | Comando | 	Descrição | 
 | :--------------------------: | :--------------------------: | 
 | `.empty()` | 	Verifica se a string está vazia. Retorna true se não houver caracteres. | 
 | `.length()` | 	Retorna o número de caracteres na string. | 
 | `tolower(char)` | 	Converte um caractere para minúsculo, se for uma letra maiúscula. | 
 | `toupper(char)` | 	Converte um caractere para maiúsculo, se for uma letra minúscula. | 

--------------------------

Busca de Imóveis por Faixa de Valores
--------------------------

Este trecho de código faz parte de um menu de opções de um sistema de gerenciamento de imóveis. A `case 4` trata especificamente da busca de imóveis com base em uma faixa de valores definida pelo usuário.

Etapas do Código
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

a. Inicialização

[/CODE]
c++
limparTela();
encontrou = false;
[/CODE]


`limparTela()`: limpa a tela para melhorar a visualização do processo.

`encontrou = false`: inicializa a variável booleana que indica se algum imóvel foi encontrado.

b. Entrada do Valor Mínimo

[/CODE]
c++
cout << "Digite o valor mínimo: R$";
cin >> valorminimo;
[/CODE]


O usuário é solicitado a digitar o valor mínimo desejado.

Validação
[/CODE]
c++
while (valorminimo < 0)
[/CODE]


Garante que o valor mínimo não seja negativo.

Se for, a tela é limpa e o valor é solicitado novamente até que seja válido.

c. Entrada do Valor Máximo

[/CODE]
c++
cout << "Digite o valor máximo: R$";
cin >> valormaximo;
[/CODE]


O usuário informa o valor máximo da faixa de busca.

Validação
[/CODE]
c++
while (valormaximo < valorminimo)
[/CODE]

Garante que o valor máximo seja maior ou igual ao valor mínimo.

Caso contrário, repete a solicitação até estar correto.

d. Exibição dos Resultados

[/CODE]
c++
limparTela();
cout << "\nImóveis encontrados na faixa de R$" << valorminimo << " a R$" << valormaximo << ":\n";
[/CODE]


A tela é limpa novamente.

A faixa de valores é apresentada ao usuário.

Verificação de Existência de Imóveis
[/CODE]
c++
if (numimoveis == 0){
    cout << "Não há imóveis no Banco de Dados.\n";
}
[/CODE]


Caso não haja imóveis cadastrados, exibe uma mensagem apropriada.

Loop de Busca

[/CODE]
c++
for (i = 0; i < numimoveis; i++)
[/CODE]

Percorre todos os imóveis cadastrados.

Para cada imóvel, exibe os seguintes dados:
• Tipo
• Finalidade (preço ou aluguel)
• Endereço
• Bairro
• Cidade
• Área
• Valor

[/CODE]
c++
if (imoveis[i].finalidade == "aluguel"){
    cout << "Aluguel(dia): R$" << imoveis[i].valor << endl;
} else {
    cout << "Preço: R$" << imoveis[i].valor << endl;
}
encontrou = true;
[/CODE]

Dependendo da finalidade do imóvel, exibe o valor corretamente.


e. Verificação Final

[/CODE]
c++
if (!encontrou)
{
    cout << "Nenhum imóvel encontrado na faixa de R$" << valorminimo << " a R$" << valormaximo << ".\n";
}
[/CODE]

Caso encontrou continue false, exibe uma mensagem de que nenhum imóvel foi encontrado.

Como mencionado, isso pode ocorrer mesmo se imóveis forem exibidos, pois encontrou nunca é atualizado.

f. Encaminhamento para o Menu

[/CODE]
c++
choice = 1;
[/CODE]

Retorna para a opção 1, provavelmente o menu principal.

--------------------------
📦 Busca de Imóveis por Características (case 5)
--------------------------
🧩 Visão Geral
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Este trecho de código faz parte de um sistema de gerenciamento de imóveis. Especificamente, ele implementa o menu de busca de imóveis por características específicas. O usuário escolhe uma das 21 características disponíveis para filtrar os imóveis cadastrados, e o sistema exibe os que correspondem ao critério informado.

🏗️ Estrutura Principal
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Início do case 5
[/CODE]
c++
Copy
Edit
case 5:
    limparTela();      
    encontrou = false;
[/CODE]

• `limparTela()`: função que limpa a tela para melhor legibilidade.

• `encontrou`: flag para verificar se algum imóvel foi encontrado.

🧭 Menu de Características
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
O sistema apresenta ao usuário uma lista de 21 características possíveis para busca:

[/CODE]
c++
cout << "1. Tipo\n";
cout << "2. Finalidade\n";
...
cout << "21. Ventilador\n";
[/CODE]


O número escolhido é armazenado em `caract`, e validado para garantir que esteja entre 1 e 21.

🔄 Estrutura de Busca: `switch(caract)`
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
A seguir, para cada valor de caract, é executado um bloco de código para:
• Ler o valor a ser buscado;
• Formatar esse valor, se necessário;
• Percorrer todos os imóveis cadastrados;
• Comparar a característica escolhida com a do imóvel;
• Exibir os imóveis compatíveis.

🔍 Explicações Detalhadas por Característica
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. Tipo

    [/CODE]
c++
    getline(cin, buscastr);
    [/CODE]

    Substitui espaços por `` e converte para minúsculas.

    Ex: "Apartamento Térreo" → apartamentotérreo.

2. Finalidade

    Valida se o valor é:

    "venda", "locação", "aluguel" ou "temporada".

3. Endereço

    Formata a string, substituindo espaços por ``.

4. Bairro e 5. Cidade

    Formata:
     Primeira letra em maiúscula;
     Demais em minúscula;
     Espaços viram ``.

6. Área (m²)

    Busca por float > 0.

7. IPTU

    Busca por valor float >= 0.

8. Quartos, 9. Suítes, 10. Banheiros, 11. Vagas

    Busca por valores inteiros >= 0.

12. Cozinha, 13. Sala, 14. Varanda, 15. Área de serviço

    Busca por:

    "sim" ou "não" (strings).

    Validação textual.

16. Piso

    Formata a string como no caso de "tipo", convertendo para minúsculas e ``.

17. Conservação

    Validação contra valores permitidos:

    "péssimo", "ruim", "regular", "bom", "ótimo", "novo".

18. Armários embutidos, 19. Ar-condicionado, 20. Aquecedor, 21. Ventilador

    Busca booleana:

        Entrada "sim" → true, "não" → false.

📤 Exibição dos Resultados
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Para todos os casos, quando um imóvel atende ao critério, é exibido:

[/CODE]
c++
cout << "Imóvel " << (i + 1) << ": "
     << imoveis[i].tipo << ", "
     << imoveis[i].finalidade << ", "
     << imoveis[i].endereco << endl;
[/CODE]


Se nenhum imóvel for encontrado, uma mensagem pode ser exibida (não presente no trecho, mas recomendada).

--------------------------

📊 Relatório Estatístico de Imóveis - Explicação do Código
--------------------------

##3 🧩 Contexto Geral

O trecho de código pertence ao `case 6` de um `switch`, que corresponde à opção de gerar um relatório estatístico sobre os imóveis armazenados no sistema. O relatório é exibido no console e, opcionalmente, salvo em um arquivo `.txt`.

✅ Estrutura do Código
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#### 1. Verificação Inicial

[/CODE]
c++
if (numimoveis == 0)
[/CODE]

Verifica se há imóveis cadastrados.

Caso não haja, exibe uma mensagem e termina o processo.

#### 2. Inicialização de Variáveis Acumuladoras
São zeradas variáveis responsáveis por somar valores de características dos imóveis (como área, valor, IPTU, etc.), contar tipos de imóveis, finalidades, comodidades, estados de conservação e tipos de piso.

#### 3. Laço de Processamento
[/CODE]
c++
for (i = 0; i < numimoveis; i++) { ... }
[/CODE]

Percorre todos os imóveis cadastrados e:
• Soma valores como preço, área, IPTU, número de quartos, etc.
• Identifica o imóvel mais caro e mais barato.
• Conta ocorrências de:
• Tipos de imóvel (casa, apartamento, galpão, etc.).
• Finalidade (venda, locação, etc.).
• Comodidades (armário, ar-condicionado, etc.).
• Cômodos (cozinha, sala, etc.).
• Estado de conservação (novo, bom, ruim...).
• Tipo de piso (cerâmica, madeira, etc.).

#### 4. Exibição do Relatório no Console
Após o processamento:
• Calcula médias:
     Valor médio.
     Área média.
     Média de IPTU, quartos, suítes, banheiros, vagas.
• Exibe os imóveis mais caro e mais barato.
• Mostra porcentagens e barras gráficas (geradas por barradeporcentagem()) para:
     Tipos de imóveis.
     Finalidades.
     Comodidades.
     Cômodos.
     Conservação.
     Pisos.

#### 5. Salvar em Arquivo?
[/CODE]
c++
cout << "Deseja salvar este relatório em um arquivo? (sim/não): ";
[/CODE]

Usuário decide se deseja salvar o relatório.

Se sim:

Cria o arquivo relatorio.txt.

Escreve as mesmas informações do console no arquivo, inclusive com as barras gráficas.

🧠 Funções Utilizadas
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`limparTela()` – Limpa o console para melhorar a visualização.

`barradeporcentagem(int porcentagem)` – Provavelmente retorna uma string com uma barra visual representando a porcentagem.

`ofstream` – Usado para gravar o relatório em um arquivo de texto.

--------------------------

📄 Explicação do Código: Visualização de um Único Imóvel
--------------------------

Este trecho de código faz parte de um sistema de gerenciamento de imóveis e corresponde à opção 7 de um menu switch-case, responsável por exibir os detalhes de um imóvel específico a partir da escolha do usuário.

🧩 Estrutura do Código
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

[/CODE]
c++
case 7:
    limparTela();
    cout << "Visualizar Imóvel\n";
    ...
    choice = 1;
    break;
[/CODE]


Esse bloco é executado quando o usuário escolhe a opção 7 no menu principal. A seguir, detalhamos cada parte.

🔍 Etapas Detalhadas
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#### 1. Limpeza da tela

[/CODE]
c++
limparTela();
[/CODE]


Antes de qualquer ação, a tela é limpa para melhorar a apresentação das informações ao usuário.

#### 2. Solicitação do número do imóvel

[/CODE]
c++
cout << "Digite o número do imóvel (1 a " << numimoveis << "): ";
cin >> i;
i--;
[/CODE]


O programa solicita ao usuário o número do imóvel que deseja visualizar.

Como os índices em arrays começam do zero, o valor informado é decrementado em 1 (i--) para corresponder ao índice correto no vetor imoveis.

#### 3. Validação de entrada

[/CODE]
c++
while (i < 0  |  |  i >= numimoveis) {
    limparTela();
    cout << "ERROR - Número de imóvel inválido. Digite um número entre 1 e " << numimoveis << ".\n";
    ...
    cin >> i;
    i--;
}
[/CODE]


Garante que o usuário forneça um número de imóvel válido.

Repete a solicitação enquanto o número estiver fora do intervalo válido.

#### 4. Exibição dos dados do imóvel

[/CODE]
c++
cout << "\nDetalhes do Imóvel " << (i + 1) << ":\n";
cout << "Tipo: " << imoveis[i].tipo << endl;
...
[/CODE]


Após validar o número, são exibidos todos os detalhes do imóvel correspondente, incluindo:

 | Propriedade | 	Exemplo de Conteúdo | 
 | :-: | :-: | 
 | Tipo | 	"Apartamento", "Casa" | 
 | Finalidade | 	"Venda", "Aluguel" | 
 | Endereço, Bairro, Cidade | 	Localização completa | 
 | Área, Valor, IPTU | 	Informações financeiras | 
 | Quartos, Suítes, etc. | 	Características internas | 
 | Piso, Conservação | 	Acabamento e estado geral | 
 | Itens opcionais | 	Armários, ar-condicionado, etc. | 

As variáveis booleanas são exibidas como "sim" ou "não" com uso do operador ternário:

[/CODE]
c++
cout << "Ar-condicionado: " << (imoveis[i].arcondicionado ? "sim" : "não") << endl;
[/CODE]


#### 5. Encaminhamento ao menu principal

[/CODE]
c++
choice = 1;
[/CODE]


Após exibir as informações, a variável choice é setada para 1, indicando que o fluxo do programa deve retornar ao menu principal ou perguntar se o usuário deseja sair.

--------------------------

📘 Edição de Imóvel
--------------------------

Este trecho de código implementa a funcionalidade de edição de um imóvel cadastrado no sistema. Ele é executado quando o usuário escolhe a opção 8 no menu principal do programa.

🧩 Estrutura Geral
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
[/CODE]
c++
case 8:
    // Código de edição de imóvel
    break;
[/CODE]

O case 8 está dentro de um switch, responsável por tratar a opção de menu escolhida pelo usuário. Quando essa opção é selecionada, o sistema permite modificar os dados de um imóvel previamente cadastrado.

🧼 Limpeza de Tela e Seleção de Imóvel
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Antes de iniciar a edição, a tela é limpa e o usuário é solicitado a inserir o número do imóvel que deseja editar:

[/CODE]
c++
limparTela();
cout << "Editar Imóvel\n";
cout << "Digite o número do imóvel (1 a " << numimoveis << "): ";
cin >> i;
i--; // Índice ajustado (vetores começam em 0)
[/CODE]


Se o número for inválido, um laço while obriga o usuário a digitar novamente até que um número válido seja fornecido.

📋 Exibição dos Dados Atuais
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Depois de selecionar um imóvel válido, o programa exibe todos os dados atuais do imóvel escolhido:

[/CODE]
c++
cout << "\nDetalhes do Imóvel " << (i + 1) << ":\n";
[/CODE]


🛠️ Edição dos Dados
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#### 🔤 Campos de Texto
• Tipo do imóvel: é convertido para minúsculas e espaços são trocados por ``.

• Finalidade: o usuário precisa digitar um valor válido dentre as opções permitidas.

• Endereço, Bairro e Cidade: os espaços são convertidos para  e a capitalização é ajustada.

#### 📏 Campos Numéricos
Para campos como área, valor, IPTU, quartos, suítes, banheiros e vagas, o sistema:

1. Solicita o valor ao usuário.

2. Valida se o número é positivo (ou não-negativo, dependendo do campo).

3. Solicita novamente caso contrário.

#### ✅ Campos de Presença (sim/não)
Campos como cozinha, sala, varanda, área de serviço e características como armários embutidos, ar-condicionado, aquecedor, ventilador são preenchidos com valores "sim" ou "não".

Validação é feita através de while que garante que apenas essas duas opções sejam aceitas.

#### 🎨 Piso
O tipo de piso é lido como uma string e:

Convertido para minúsculas.

Tem os espaços substituídos por .

#### 🧱 Estado de Conservação
O estado de conservação deve ser uma das opções fixas:

[/CODE]
c++
péssimo, ruim, regular, bom, ótimo, novo
[/CODE]


Se a entrada não for uma dessas, o programa exibe um erro e solicita novamente.

#### ✅ Confirmação Final
Ao final do processo, o sistema exibe uma mensagem de sucesso:

[/CODE]
c++
cout << "\nImóvel editado com sucesso!\n";
[/CODE]

E altera a variável choice para 1, retornando ao menu principal.

--------------------------

📦  Remover Imóvel
--------------------------
Este trecho de código faz parte de um sistema de gerenciamento de imóveis em C++. O case 9 é responsável por remover um imóvel cadastrado com base em seu número.

🔁 Estrutura do Case
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
[/CODE]
c++
case 9:
[/CODE]

Este case é uma opção de um switch-case, normalmente dentro de um menu principal. A opção 9 corresponde à remoção de um imóvel.

🧹 Limpeza da Tela
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
[/CODE]
c++
limparTela();
[/CODE]

Função chamada para limpar a tela, geralmente para deixar a interface do usuário mais limpa antes de interagir com ele.

📥 Solicitação do Número do Imóvel
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
[/CODE]
c++
cout << "Digite o número do imóvel a ser removido (1 a " << numimoveis << "): ";
cin >> i;
i--;
[/CODE]

Solicita ao usuário o número do imóvel a ser removido.

Como os vetores começam no índice 0, é feito um ajuste (i--) para converter o número do usuário (1-based) para o índice interno (0-based).

🧾 Validação da Entrada
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
[/CODE]
c++
while (i < 0  |  |  i >= numimoveis)
[/CODE]

Garante que o índice está dentro do intervalo válido.

Caso não esteja, o sistema:

• Limpa a tela;

• Exibe uma mensagem de erro;

• Solicita novamente a entrada.

❌ Remoção do Imóvel
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
[/CODE]
c++
for (int j = i; j < numimoveis - 1; j++)
{
    imoveis[j] = imoveis[j + 1];
}
[/CODE]

Esse for desloca todos os elementos do vetor uma posição para trás, sobrescrevendo o imóvel a ser removido.

Isso mantém a integridade da estrutura do vetor após a exclusão.

🔻 Decremento do Total de Imóveis
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
[/CODE]
c++
numimoveis--;
[/CODE]

Após remover o item e reorganizar o vetor, o total de imóveis cadastrados é atualizado.

✅ Mensagem de Sucesso
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
[/CODE]
c++
cout << "\nImóvel removido com sucesso!\n";
[/CODE]

Confirma ao usuário que a operação foi realizada com êxito.

🔁 Retorno ao Menu
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
[/CODE]
c++
choice = 1;
[/CODE]

Define a variável choice para 1, o que provavelmente faz o programa retornar ao menu principal ou perguntar ao usuário o que deseja fazer em seguida.

📝 Resumo
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 | Ação	 | Propósito | 
 | :-: | :-: | 
 | limparTela() | 	Melhorar visualização para o usuário | 
 | Solicitação do número	 | Identificar o imóvel a ser removido | 
 | Validação	 | Evitar índice inválido no vetor | 
 | Loop de remoção | 	Sobrescreve o imóvel e reorganiza o vetor | 
 | numimoveis-- | 	Atualiza o total de imóveis após a exclusão | 
 | Mensagem de sucesso	 | Feedback para o usuário | 
 | choice = 1 | 	Controla o fluxo do programa para continuar a execução | 

--------------------------

Salvamento Condicional dos Dados
--------------------------
Ao finalizar o programa, o sistema realiza um processo interativo para confirmar com o usuário se deseja ou não atualizar os dados no arquivo BDImoveis2.txt.

[/CODE]
c++
    limparTela();
    cout << "\nDeseja atualizar os dados no arquivo BDImoveis2.txt? (s/n): ";
    cin >> resposta;
    while (resposta != "s" && resposta != "S" && resposta != "n" && resposta != "N"){
        cout << "ERROR - Opção inválida.\n\n";
        cout << "\nDeseja atualizar os dados no arquivo BDImoveis2.txt? (s/n): ";
        cin >> resposta;
    }
    if (resposta == "s"  |  |  resposta == "S"){
        ofstream arquivosaida("BDImoveis2.txt");
        if (!arquivosaida.isopen()){
            cerr << "Erro ao abrir o arquivo BDImoveis2.txt para escrita." << endl;
            return 1; 
        }
        arquivosaida << "Tipo Finalidade Endereço Bairro Cidade Área Valor IPTU Quartos Suítes Banheiros Vagas Cozinha Sala Varanda Áreadeserviço Piso Conservação Armários Ar-condicionado Aquecedor Ventilador\n";
        for (i = 0; i < numimoveis; i++){
            arquivosaida << imoveis[i].tipo << " "
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
                          << imoveis[i].areaservico << " "
                          << imoveis[i].piso << " "
                          << imoveis[i].conservacao << " "
                          << (imoveis[i].armariosembutidos ? "sim" : "não") << " "
                          << (imoveis[i].arcondicionado ? "sim" : "não") << " "
                          << (imoveis[i].aquecedor ? "sim" : "não") << " "
                          << (imoveis[i].ventilador ? "sim" : "não")
                          << endl;
        }
        arquivosaida << "fim";
        arquivosaida.close();
        cout << "\nDados atualizados com sucesso no arquivo BDImoveis2.txt.\n";
    }else{
        cout << "\nOs dados não foram atualizados no arquivo BDImoveis2.txt.\n";
    }
    cout << "\n\nPrograma encerrado.\n\n";
    return 0;
[/CODE]


🔄 Funcionamento
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. Limpeza da tela: Antes de exibir a pergunta final, a tela é limpa com a função limparTela(), proporcionando uma interface mais limpa para o encerramento.
2. Pergunta ao usuário: O programa exibe a seguinte mensagem no terminal:
[/CODE]
text
Deseja atualizar os dados no arquivo BDImoveis2.txt? (s/n):
[/CODE]

3. Validação de entrada: Se o usuário digitar algo diferente de s, S, n ou N, será informado que a opção é inválida e será solicitado novamente até uma resposta válida ser fornecida.
4. Atualização dos dados:
• Se o usuário optar por "sim", o programa:
     Abre o arquivo BDImoveis2.txt em modo de escrita.
     Escreve o cabeçalho na primeira linha do arquivo (linha ignorada).
     Sobrescreve o conteúdo com os dados atualizados dos imóveis.
     Conclui o arquivo com a palavra fim, que sinaliza o fim da base de dados.
     Informa que a atualização foi realizada com sucesso.
• Se o usuário escolher "não", o programa apenas exibe uma mensagem informando que os dados não foram alterados.

5. Encerramento: Após essa etapa, uma mensagem de encerramento é exibida e o programa termina sua execução.

💡 Importante
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Esse mecanismo garante que o usuário tenha controle total sobre a persistência das alterações feitas durante a sessão, evitando alterações acidentais nos dados salvos.

Utilização de Operador Ternário
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
O trecho:

[/CODE]
c++
(imoveis[i].armariosembutidos ? "sim" : "nao")
[/CODE]


é um operador ternário que serve para simplificar uma estrutura condicional if-else.

#### ✅ O que ele faz:
Esse código verifica se o campo armariosembutidos do imóvel atual (imoveis[i]) é true (ou seja, possui armários embutidos). Se for:
• Retorna `sim`
• Caso contrário, retorna `nao`
#### 🔍 Como funciona:
A sintaxe geral do operador ternário é:

[/CODE]
c++
(condição) ? valorseverdadeiro : valorsefalso;
[/CODE]


No caso do projeto:

[/CODE]
c++
Condição: imoveis[i].armariosembutidos
(campo booleano: true ou false)
[/CODE]

• Se verdadeiro: `sim`
• Se falso: `nao`

Portanto, essa linha está convertendo o valor booleano para uma representação textual compreensível, que será gravada no arquivo BDImoveis2.txt.

--------------------------

Considerações Finais
--------------------------
O código é modular e didático, facilitando futuras manutenções e adições de novas funcionalidades. A utilização de vetores, estruturas e arquivos proporciona uma base sólida para o aprendizado e prática de programação em C++ aplicada a sistemas reais.

--------------------------

Autor
--------------------------

• Joaquim Pedro do Nascimento Moreira de Jesus - Matrícula: 2025.1.08.014

--------------------------