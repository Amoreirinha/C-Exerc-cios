# Gerenciador de Imóveis C++

---

## Descrição do Projeto

Este é um **Aplicativo para Gestão de Imóveis** desenvolvido em C++. Ele foi criado com o objetivo de aprimorar habilidades na manipulação de registros armazenados em vetores e na utilização de estruturas de controle para gerar estatísticas. O programa permite gerenciar informações sobre imóveis disponíveis para venda, locação ou temporada, lendo e escrevendo dados de um arquivo texto.

---

## Funcionalidades Principais

O sistema oferece um menu interativo com as seguintes operações:

* **Inclusão de um Novo Imóvel**: Adiciona um novo registro de imóvel à base de dados.
* **Busca de Imóveis por Faixa de Valores**: Permite pesquisar imóveis com base em seus valores (para locação, venda ou temporada).
* **Busca de Imóveis por Características**: Filtra imóveis com base em características específicas, como:
    * Armários embutidos
    * Ar-condicionado
    * Aquecedor
    * Ventilador
* **Busca por Número de Quartos e Suítes**: Localiza imóveis que atendem a critérios de quantidade de quartos e suítes.
* **Relatório Estatístico**: Gera um relatório detalhado contendo:
    * Percentual de imóveis por finalidade (venda, locação, temporada).
    * Percentual de casas com suítes.
    * Percentual de salas comerciais com piso cerâmico.
    * Listagem completa de todos os imóveis disponíveis.
* **Visualizar Lista de Imóveis**: Exibe todos os imóveis carregados na base de dados.

---

## Estrutura do Aplicativo

O programa inicia lendo os dados do arquivo `BD_Imoveis2.txt` e os armazena em um vetor de registros, com capacidade máxima de 200 imóveis. Cada linha do arquivo corresponde a um imóvel e é carregada na ordem. Ao final da execução, os dados atualizados são gravados de volta no mesmo arquivo.

**Observação Importante**: O vetor de registros não permite "espaços vazios". Ao excluir um imóvel, os registros subsequentes são automaticamente deslocados para a esquerda para manter a sequência contínua dos dados.

---

## Formato do Arquivo de Imóveis (`BD_Imoveis2.txt`)

O arquivo de dados contém até 200 linhas, onde cada linha representa um imóvel e é composta por 22 campos, separados por espaços.

**Campos por Linha**:

1.  **Tipo**: Tipo do imóvel (ex: `casa`, `apartamento`, `sala_comercial`).
2.  **Finalidade**: `venda`, `locacao`, `temporada`.
3.  **Endereço**
4.  **Bairro**
5.  **Cidade**
6.  **Área**: Em metros quadrados.
7.  **Valor**: Preço ou valor de locação.
8.  **IPTU**
9.  **Quartos**
10. **Suítes**
11. **Banheiros**
12. **Vagas**: Número de vagas na garagem.
13. **Cozinha**: (ex: `sim`/`nao` ou `padrao`/`americana`).
14. **Sala**: (ex: `sim`/`nao`).
15. **Varanda**: (ex: `sim`/`nao`).
16. **Área de Serviço**: (ex: `sim`/`nao`).
17. **Piso**: Tipo de piso (ex: `ceramico`, `madeira`).
18. **Conservação**: Estado de conservação (ex: `bom`, `regular`, `ruim`).
19. **Armários**: (`sim`/`nao`).
20. **Ar-condicionado**: (`sim`/`nao`).
21. **Aquecedor**: (`sim`/`nao`).
22. **Ventilador**: (`sim`/`nao`).

**Regras Específicas do Arquivo**:

* A **primeira linha** do arquivo, que geralmente contém os cabeçalhos das colunas, é **ignorada** durante a leitura.
* A **última linha**, que contém a palavra "fim" no campo do tipo de imóvel, **não é considerada** nos cálculos ou na base de dados de imóveis.

---

## Como Compilar e Executar

### Requisitos

* Compilador C++ (recomendado: g++).

### Passos

1.  **Salve o código**: Certifique-se de que o arquivo `.cpp` (por exemplo, `main.cpp`) e o arquivo de dados `BD_Imoveis2.txt` estão no mesmo diretório.
2.  **Compile o código**: Abra um terminal ou prompt de comando e navegue até o diretório onde você salvou os arquivos. Em seguida, compile o programa usando um compilador C++:

    ```bash
    g++ main.cpp -o gerenciador_imoveis
    ```

    *Se o nome do seu arquivo `.cpp` for diferente, substitua `main.cpp` pelo nome correto.*

3.  **Execute o programa**: Após a compilação, você pode executar o programa:

    ```bash
    ./gerenciador_imoveis
    ```

O programa exibirá o menu de opções, e você poderá interagir com ele através do console.

---

## Tecnologias Utilizadas

* **C++**: Linguagem de programação principal.
* **fstream**: Para manipulação de arquivos (leitura/escrita).
* **iostream**: Para entrada e saída de dados no console.
* **string**: Para manipulação de cadeias de caracteres.

---

## Explicação do Código-Fonte (main.cpp)
O arquivo main.cpp contém toda a lógica do programa de gerenciamento de imóveis. A seguir, descrevemos os principais blocos do código para facilitar a compreensão de sua estrutura e funcionamento.

---

## Inclusão de Bibliotecas

```c++
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string.h>
```

Essas bibliotecas oferecem funcionalidades essenciais:

* **cstdlib:** Funções utilitárias (como system).
* **fstream:** Leitura e escrita em arquivos.
* **iostream:** Entrada e saída de dados pelo console.
* **string.h:** Manipulação de strings (poderia ser substituída por <string> para uso de std::string).

---

## Função limparTela

```c++
void limparTela() {
    cout << "\033[H\033[J";
}
```

Utiliza códigos de escape ANSI para limpar o terminal, proporcionando uma melhor experiência visual ao usuário.

---

## 🧾 Objetivo da Função
A função barradeporcentagem gera uma representação visual em texto de uma barra de progresso, com base em um valor percentual (entre 0 e 100). Ela retorna uma string com 100 caracteres, que mostra graficamente o quanto está "preenchido".

### 📌 Assinatura da Função

```c++
string barradeporcentagem(float valor)
```
* **Parâmetro:** valor → um número decimal representando a porcentagem (por exemplo, 45.7).

* **Retorno:** uma string com uma barra de progresso estilizada com blocos (cheios e vazios).

### 🧠 Funcionamento Passo a Passo
```c++
string barra = "█";
string vazio = "░";
```
Define dois caracteres para construir a barra:

* `█` representa a parte preenchida da barra.

* `░` representa a parte vazia da barra.

```c++
int tamanho = 100;
```
Define que a barra terá 100 "blocos" no total, representando 100%.

```c++
int preenchimento = static_cast<int>(valor);
```
Converte o valor de porcentagem em inteiro.

Por exemplo: se valor for 75.6, preenchimento será 75.

Ou seja, os primeiros 75 blocos serão "█", os restantes 25 serão "░".

```c++
string resultado = "[";
```
Inicia a construção da string com um colchete de abertura.

```c++
for (int i = 0; i < tamanho; i++)
{
    if (i < preenchimento)
        resultado += barra;
    else
        resultado += vazio;
}
```
Laço que constrói a barra caractere por caractere:

Se o índice for menor que preenchimento, adiciona `█`.

Caso contrário, adiciona `░`.

```c++
resultado += "]";
```
Fecha a barra com colchete final.

### ✅ Exemplo de Uso
```c++

cout << barradeporcentagem(42.3);
```
Saída esperada:

```css

[████████████████████████████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░]
```
(42 blocos preenchidos, 58 blocos vazios)

### 🎯 Resumo

| Elemento | Função |
|:--------:|:-------:|
|`█`|	Bloco que indica preenchimento|
|`░`|	Bloco que indica espaço vazio|
|`valor`|	Percentual a ser visualizado (0–100)|
|`static_cast<int>`|	Uma forma segura e explícita de converter tipos de dados em C++|
|`Resultado final`|	Barra como string entre colchetes

---

## Definição da Estrutura imovel

```c++
struct imovel {
    string tipo, finalidade, endereco, bairro, cidade;
    float area, valor, iptu;
    int quartos, suites, banheiros, vagas;
    string cozinha, sala, varanda, area_servico;
    string piso, conservacao;
    string armarios, ar_condicionado, aquecedor, ventilador;
};
```

Cada objeto da estrutura representa um imóvel, com todos os campos refletindo os dados de uma linha do arquivo BD_Imoveis2.txt.

---

## Função Principal ``` main ```
A função `main()` é responsável por:

* Declarar o vetor de imóveis (imovel imoveis[200]).
* Chamar funções auxiliares para:
* Ler dados do arquivo.
* Apresentar o menu interativo.
* Executar as opções conforme a escolha do usuário.
* Gravar os dados atualizados de volta no arquivo.

---

## Funções Auxiliares
O código está organizado em várias funções auxiliares que realizam tarefas específicas, como:

* **Leitura e escrita no arquivo:** Lê os imóveis do arquivo texto para o vetor e salva as alterações.
* **Inclusão de imóvel:** Adiciona um novo registro com entrada do usuário.
* **Filtros de busca:** Permite busca por valor, características, número de quartos, etc.
* **Relatório estatístico:** Gera estatísticas e percentuais com base nos imóveis cadastrados.
* **Remoção:** Exclui um imóvel e reorganiza o vetor para evitar espaços vazios.

---

## Manipulação do Arquivo
A leitura do arquivo ocorre ignorando a primeira linha (cabeçalho) e a última (linha com o campo tipo igual a "fim"). Durante a execução, o vetor é atualizado em tempo real, e os dados são sobrescritos no final da execução para garantir persistência.

---

## 📥 Leitura dos Dados do Arquivo BD_Imoveis2.txt
Antes de exibir ou manipular os dados, o programa realiza a leitura inicial do arquivo de imóveis (BD_Imoveis2.txt) para carregar as informações existentes na memória.

```c++
    ifstream arquivo("BD_Imoveis2.txt");
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo BD_Imoveis2.txt" << endl;
        return 1;
    }
    string linha;
    getline(arquivo, linha);
    for(i=0; i < MAX_IMOVEIS; i++) {
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
        arquivo >> imoveis[i].area_servico;
        arquivo >> imoveis[i].piso;
        arquivo >> imoveis[i].conservacao;
        string temp_armarios, temp_ar_condicionado, temp_aquecedor, temp_ventilador;
        arquivo >> temp_armarios;
        imoveis[i].armarios_embutidos = (temp_armarios == "sim");
        arquivo >> temp_ar_condicionado;
        imoveis[i].ar_condicionado = (temp_ar_condicionado == "sim");
        arquivo >> temp_aquecedor;
        imoveis[i].aquecedor = (temp_aquecedor == "sim");
        arquivo >> temp_ventilador;
        imoveis[i].ventilador = (temp_ventilador == "sim");
        num_imoveis++;
    }
    arquivo.close();
    cout << "Total de imóveis lidos: " << num_imoveis << endl;

    limparTela();
```
* **Observação**

    O trecho do código
    ```c++
    getline(arquivo, linha);
    ```
    lê uma linha inteira do arquivo BD_Imoveis2.txt e armazena o conteúdo na variável linha. No contexto desse código, ela serve para descartar a primeira linha do arquivo, que normalmente contém apenas o cabeçalho (nomes das colunas), evitando que seja processada como um imóvel válido.

    **Resumo:**
    `getline` lê uma linha completa do arquivo de texto, diferente do operador `>>`, que lê apenas até o próximo espaço.

### Funcionamento:
1. **Abertura do Arquivo:**
Utiliza a biblioteca fstream (ifstream) para abrir o arquivo em modo de leitura.
Se o arquivo não puder ser aberto, o programa exibe uma mensagem de erro e encerra.
2. **Cabeçalho Ignorado:**
A primeira linha do arquivo é lida e descartada por conter apenas os nomes das colunas. Isso evita que seja processada como um imóvel válido.
3. **Leitura das Linhas de Imóveis:**
Cada linha subsequente do arquivo representa um imóvel.
A leitura continua até encontrar a palavra-chave fim, que marca o fim dos registros válidos.
4. **Armazenamento no Vetor de Registros:**
Cada campo da linha é lido e armazenado na estrutura de dados imovel.
Os campos booleanos (armarios_embutidos, ar_condicionado, aquecedor, ventilador) são lidos como strings (`sim`/`nao`) e convertidos para valores **`true`** ou **`false`**.
5. **Controle de Quantidade:**
O vetor comporta no máximo 200 imóveis, e cada registro lido incrementa o contador num_imoveis.
6. **Encerramento da Leitura:**
Após o término da leitura, o arquivo é fechado com segurança.
O programa então exibe no console a quantidade total de imóveis carregados.

### Exemplo de Uso:
Se o arquivo contiver 50 imóveis e a linha final for "fim", o console exibirá:

```bash
Total de imóveis lidos: 50
```
### Observações Técnicas
Utiliza estrutura de repetição for e controle com break para parar na linha "fim".

A conversão de campos `sim` ou `nao` para booleanos é feita com a expressão:

```c++
imoveis[i].armarios_embutidos = (armarios == "sim");
```

* **🧠 Como isso funciona, passo a passo:**
    1. **Leitura da string:**
        Antes dessa linha, o código já leu o valor do campo como string:
        ```c++
        string armarios;
        arquivo >> armarios;
        ```
        Agora, armarios pode conter "sim" ou "nao".
    2. **Comparação lógica:**
        ```c++
        (armarios == "sim")
        ```
        Essa expressão compara se o conteúdo da string é exatamente igual a `sim`.
        * Se for igual, o resultado da comparação é **`true`**.
        * Se for diferente, o resultado é **`false`**.
    3. **Atribuição do valor booleano:**
        O valor **`true`** ou **`false`** é atribuído ao campo:
        ```c++
        imoveis[i].armarios_embutidos = (temp_armarios == "sim");
        ```
        Assim:
        * Se o texto no arquivo era `sim`, o campo armarios_embutidos receberá **`true`**.
        * Se era `nao`, o campo receberá **`false`**.

Essa abordagem garante que todos os imóveis válidos sejam lidos corretamente e que o vetor esteja pronto para as demais operações do sistema.

---

## Estrutura do Menu
O menu principal é exibido no terminal, oferecendo ao usuário diversas opções numeradas para interação. Cada escolha leva a uma função correspondente, que realiza a ação desejada (inclusão, busca, estatísticas, listagem etc.).
```c++
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
            while (choice < 1 || choice > 8){ 
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
```
O código utiliza da função `limparTela()`; e cout's para mostrar um menu no terminal do usuário.

Há também uma validação de dados utilizando um loop `while` para que, caso seja selecionado um número inválido, ele não avance no código e continue pedindo uma opção válida de escolha.

Após isso, incrementa 1 a variável `choice` pois o case 1 é um caso aonde o usuário é perguntado se deseja voltar ao menu ou sair do programa.

---
## `Case 1` - Voltar ao menu ou sair do programa

### 🎯 Objetivo do Código
Este bloco pergunta ao usuário se ele deseja voltar ao menu principal ou sair do programa, e responde a isso de forma segura e interativa, com verificação de entrada.

```c++
case 1:
    cout << "\n\nDeseja voltar ao menu principal? Digite 's' para SIM ou 'n' para NÃO: ";
    resposta = "x";
    cin >> resposta;
    if (resposta == "s" || resposta == "S"){
        choice = 0;
        limparTela();
    }else if (resposta == "n" || resposta == "N"){
        continuar = false;
    }else{
        while (resposta != "s" && resposta != "S" && resposta != "n" && resposta != "N"){
            cout << "Opção inválida. Digite 's' para SIM ou 'n' para NÃO: ";
            cin >> resposta;
        }
        if (resposta == "s" || resposta == "S"){
            choice = 0;
            limparTela();
        }else if (resposta == "n" || resposta == "N"){
            continuar = false;
        }
    }
    break;
```

### 🔍 Explicação Linha a Linha
```c++
case 1:
```
Trata a opção 1 do menu (poderia ser, por exemplo, "Sair ou voltar").

```c++
cout << "\n\nDeseja voltar ao menu principal? Digite 's' para SIM ou 'n' para NÃO: ";
```
Pergunta ao usuário o que ele deseja fazer a seguir.

```c++
resposta = "x"; // Inicializa a resposta com um valor inválido
cin >> resposta;
```

Inicializa a variável resposta com algo que não é 's' nem 'n', para garantir que entre na verificação.

Em seguida, lê o que o usuário digitou.

```c++
if (resposta == "s" || resposta == "S")
```
Se a resposta for "s" ou "S", então...

```c++
choice = 0;
limparTela();
```
...volta ao menu principal (choice = 0) e limpa a tela com a função limparTela().

```c++
else if (resposta == "n" || resposta == "N"){
    continuar = false; // Encerra o loop e o programa
}
```
Se a resposta for "n" ou "N", define continuar = false, o que provavelmente encerra o programa (já que deve haver um while(continuar) em algum lugar).

```c++
else {
    while (resposta != "s" && resposta != "S" && resposta != "n" && resposta != "N"){
        cout << "Opção inválida. Digite 's' para SIM ou 'n' para NÃO: ";
        cin >> resposta;
    }
```

Se a resposta não for válida (qualquer outra coisa além de 's', 'S', 'n' ou 'N'), entra em um loop de repetição, pedindo para o usuário digitar novamente até ele acertar.

```cpp
    if (resposta == "s" || resposta == "S"){
        choice = 0;
        limparTela();
    }else if (resposta == "n" || resposta == "N"){
        continuar = false;
    }
```

Após o loop de validação, o código executa novamente a ação correta de acordo com a resposta final.

```c++
break;
```
Finaliza o case 1, voltando ao controle principal do switch.

---
## Exibir lista de imóveis
Este trecho de código faz parte de um menu de opções de um programa em C++ voltado para o gerenciamento de imóveis. A opção case 2 é responsável por listar os imóveis cadastrados no sistema, exibindo suas principais características.
```c++
case 2:
    cout << "Lista de Imóveis:\n";
    for (i = 0; i < num_imoveis; i++){
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
```

### 🧠 O que o Código Faz?
1. Mostra um cabeçalho na tela
    ```c++
    cout << "Lista de Imóveis:\n";
    ```
    Exibe o título da lista para o usuário.

2. Percorre todos os imóveis cadastrados
    ```c++
    for (i = 0; i < num_imoveis; i++)
    ```
    Usa um loop for para iterar de 0 até o número de imóveis `(num_imoveis)`.

    `i` é o índice usado para acessar cada imóvel individualmente.

3. Exibe as informações de cada imóvel
    ```c++
    cout << "Imóvel " << (i + 1) << ": " << imoveis[i].tipo << ", "
        << imoveis[i].finalidade << ", "
        << imoveis[i].endereco << ", "
        << imoveis[i].bairro << ", "
        << imoveis[i].cidade << ", "
        << imoveis[i].area << " m², ";
    ```
    Mostra:
    * Número do imóvel (começando em 1)
    * Tipo (ex: casa, apartamento)
    * Finalidade (ex: aluguel ou venda)
    * Endereço completo: endereço, bairro, cidade
    * Área em metros quadrados (m²)

4. Mostra o valor com base na finalidade
    ```c++
    if (imoveis[i].finalidade == "aluguel"){
        cout << "Aluguel(dia): R$" << imoveis[i].valor << endl;
    } else {
        cout << "Venda: R$" << imoveis[i].valor << endl;
    }
    ```
    Se a finalidade do imóvel for aluguel, mostra o valor por dia.

    Se for venda, mostra o valor total.

5. Define o próximo passo do menu
    ```c++
    choice = 1;
    ```
    Após mostrar todos os imóveis, o programa força a próxima opção como `choice = 1`, que  leva o usuário a decidir se deseja voltar ao menu principal ou sair do sistema.

---
## Inclusão de um Novo Imóvel
Este trecho de código refere-se ao caso 3 de um menu de sistema para inclusão de novos imóveis em um banco de dados, presumivelmente utilizando vetores e structs em C++.

### Objetivo
O objetivo principal é coletar do usuário todas as informações necessárias para cadastrar um novo imóvel, assegurando a validação de dados e o formato padronizado.

```c++
case 3:
    limparTela();
    cout << "Inclusão de um Novo Imóvel\n";
    if (num_imoveis >= MAX_IMOVEIS){
        cout << "ERROR - Banco de dados cheio. Não é possível incluir mais imóveis.\n";
        choice = 1;
        break;
    } else {
        (limparTela());
        cout << "Digite o tipo do imóvel (Casa, Apartamento, Sala, etc.): ";
        cin.ignore();
        getline(cin, tipo_temp);
        if (!tipo_temp.empty()){
            for (size_t j = 0; j < tipo_temp.length(); j++){
                tipo_temp[j] = tolower(tipo_temp[j]);
            }
        }
        for (size_t j = 0; j < tipo_temp.length(); j++){
            if (tipo_temp[j] == ' '){
                tipo_temp[j] = '_';
            }
        }
        imoveis[num_imoveis].tipo = tipo_temp;
        cout << "Digite a finalidade (venda, locação, temporada, aluguel): ";
        cin >> imoveis[num_imoveis].finalidade;
        while (imoveis[num_imoveis].finalidade != "venda" && imoveis[num_imoveis].finalidade != "locação" && imoveis[num_imoveis].finalidade != "temporada" && imoveis[num_imoveis].finalidade != "aluguel"{
            limparTela();
            cout << "ERROR - Finalidade inválida. Digite 'venda', 'locação' ou 'temporada'.\n";
            cout << "Digite a finalidade (venda, locação, temporada): ";
            cin >> imoveis[num_imoveis].finalidade;
        }
        cout << "Digite o endereço: ";
        getline(cin, endereco_temp);
        for (size_t j = 0; j < endereco_temp.length(); j++){
            if (endereco_temp[j] == ' '){
                endereco_temp[j] = '_';
            }
        }
        imoveis[num_imoveis].endereco = endereco_temp;
        string bairro_temp;
        cout << "Digite o bairro: ";
        getline(cin, bairro_temp);
        if (!bairro_temp.empty()){
            bairro_temp[0] = toupper(bairro_temp[0]);
            for (size_t j = 1; j < bairro_temp.length(); j++){
                bairro_temp[j] = tolower(bairro_temp[j]);
            }
        }
        for (size_t j = 0; j < bairro_temp.length(); j++){
            if (bairro_temp[j] == ' '){
                bairro_temp[j] = '_';
            }
        }
        imoveis[num_imoveis].bairro = bairro_temp;
        string cidade_temp;
        cout << "Digite a cidade: ";
        getline(cin, cidade_temp);
        if (!cidade_temp.empty()){
            cidade_temp[0] = toupper(cidade_temp[0]);
            for (size_t j = 1; j < cidade_temp.length(); j++){
                cidade_temp[j] = tolower(cidade_temp[j]);
            }
        }
        for (size_t j = 0; j < cidade_temp.length(); j++){
            if (cidade_temp[j] == ' '){
                cidade_temp[j] = '_';
            }
        }
        imoveis[num_imoveis].cidade = cidade_temp;
        cout << "Digite a área em m²: ";
        cin >> imoveis[num_imoveis].area;
        while (imoveis[num_imoveis].area <= 0){
            limparTela();
            cout << "ERROR - Área inválida. A área deve ser maior que zero.\n";
            cout << "Digite a área em m²: ";
            cin >> imoveis[num_imoveis].area;
        }
        cout << "Digite o valor: R$";
        cin >> imoveis[num_imoveis].valor;
        while (imoveis[num_imoveis].valor <= 0){
            limparTela();
            cout << "ERROR - Valor inválido. O valor deve ser maior que zero.\n";
            cout << "Digite o valor: R$";
            cin >> imoveis[num_imoveis].valor;
        }
        cout << "Digite o valor do IPTU: R$";
        cin >> imoveis[num_imoveis].iptu;
        while (imoveis[num_imoveis].iptu < 0){
            limparTela();
            cout << "ERROR - Valor do IPTU inválido. O valor deve ser maior ou igual a zero.\n";
            cout << "Digite o valor do IPTU: R$";
            cin >> imoveis[num_imoveis].iptu;
        }
        cout << "Digite o número de quartos: ";
        cin >> imoveis[num_imoveis].quartos;
        while (imoveis[num_imoveis].quartos < 0){
            limparTela();
            cout << "ERROR - Número de quartos inválido. O número deve ser maior ou igual a zero.\n";
            cout << "Digite o número de quartos: ";
            cin >> imoveis[num_imoveis].quartos;
        }
        cout << "Digite o número de suítes: ";
        cin >> imoveis[num_imoveis].suites;
        while (imoveis[num_imoveis].suites < 0){
            limparTela();
            cout << "ERROR - Número de suítes inválido. O número deve ser maior ou igual a zero.\n";
            cout << "Digite o número de suítes: ";
            cin >> imoveis[num_imoveis].suites;
        }
        cout << "Digite o número de banheiros: ";
        cin >> imoveis[num_imoveis].banheiros;
        while (imoveis[num_imoveis].banheiros < 0){
            limparTela();
            cout << "ERROR - Número de banheiros inválido. O número deve ser maior ou igual a zero.\n";
            cout << "Digite o número de banheiros: ";
            cin >> imoveis[num_imoveis].banheiros;
        }
        cout << "Digite o número de vagas de garagem: ";
        cin >> imoveis[num_imoveis].vagas;
        while (imoveis[num_imoveis].vagas < 0){
            limparTela();
            cout << "ERROR - Número de vagas inválido. O número deve ser maior ou igual a zero.\n";
            cout << "Digite o número de vagas de garagem: ";
            cin >> imoveis[num_imoveis].vagas;
        }
        cout << "Possui cozinha? (sim/não): ";
        cin >> imoveis[num_imoveis].cozinha;
        while (imoveis[num_imoveis].cozinha != "sim" && imoveis[num_imoveis].cozinha != "não"){
            limparTela();
            cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
            cout << "Possui cozinha? (sim/não): ";
            cin >> imoveis[num_imoveis].cozinha;
        }
        cout << "Possui sala? (sim/não): ";
        cin >> imoveis[num_imoveis].sala;
        while (imoveis[num_imoveis].sala != "sim" && imoveis[num_imoveis].sala != "não"){
            limparTela();
            cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
            cout << "Possui sala? (sim/não): ";
            cin >> imoveis[num_imoveis].sala;
        }
        cout << "Possui varanda? (sim/não): ";
        cin >> imoveis[num_imoveis].varanda;
        while (imoveis[num_imoveis].varanda != "sim" && imoveis[num_imoveis].varanda != "não"){
            limparTela();
            cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
            cout << "Possui varanda? (sim/não): ";
            cin >> imoveis[num_imoveis].varanda;
        }
        cout << "Possui área de serviço? (sim/não): ";
        cin >> imoveis[num_imoveis].area_servico;
        while (imoveis[num_imoveis].area_servico != "sim" && imoveis[num_imoveis].area_servico != "não"){
            limparTela();
            cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
            cout << "Possui área de serviço? (sim/não): ";
            cin >> imoveis[num_imoveis].area_servico; 
        }
        cout << "Tipo de piso: ";
        cin >> imoveis[num_imoveis].piso;
        for (size_t j = 0; j < imoveis[num_imoveis].piso.length(); j++){
            if (imoveis[num_imoveis].piso[j] == ' ')
            {
                imoveis[num_imoveis].piso[j] = '_';
            }
            else
            {
                imoveis[num_imoveis].piso[j] = tolower(imoveis[num_imoveis].piso[j]);
            }
        }
        cout << "Estado de conservação: (péssimo, ruim, regular, bom, ótimo, novo) ";
        cin >> imoveis[num_imoveis].conservacao;
        while (imoveis[num_imoveis].conservacao != "péssimo" && imoveis[num_imoveis].conservacao != "ruim" &&
                imoveis[num_imoveis].conservacao != "regular" && imoveis[num_imoveis].conservacao != "bom" &&
                imoveis[num_imoveis].conservacao != "ótimo" && imoveis[num_imoveis].conservacao != "novo"){
            limparTela();
            cout << "ERROR - Estado de conservação inválido. Digite 'péssimo', 'ruim', 'regular', 'bom', 'ótimo' ou 'novo'.\n";
            cout << "Estado de conservação: (péssimo, ruim, regular, bom, ótimo, novo) ";
            cin >> imoveis[num_imoveis].conservacao;
        }
        cout << "Possui armários embutidos? (sim/não): ";
        cin >> temp_bool;
        while (temp_bool != "sim" && temp_bool != "não"){
            limparTela();
            cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
            cout << "Possui armários embutidos? (sim/não): ";
            cin >> temp_bool;
        }
        imoveis[num_imoveis].armarios_embutidos = (temp_bool == "sim");
        cout << "Possui ar-condicionado? (sim/não): ";
        cin >> temp_bool;
        while (temp_bool != "sim" && temp_bool != "não"){
            limparTela();
            cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
            cout << "Possui ar-condicionado? (sim/não): ";
            cin >> temp_bool;
        }
        imoveis[num_imoveis].ar_condicionado = (temp_bool == "sim");
        cout << "Possui aquecedor? (sim/não): ";
        cin >> temp_bool;
        while (temp_bool != "sim" && temp_bool != "não"){
            limparTela();
            cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
            cout << "Possui aquecedor? (sim/não): ";
            cin >> temp_bool;
        }
        imoveis[num_imoveis].aquecedor = (temp_bool == "sim");
        cout << "Possui ventilador? (sim/não): ";
        cin >> temp_bool;
        while (temp_bool != "sim" && temp_bool != "não"){
            limparTela();
            cout << "ERROR - Resposta inválida. Digite 'sim' ou 'não'.\n";
            cout << "Possui ventilador? (sim/não): ";
            cin >> temp_bool;
        }
        imoveis[num_imoveis].ventilador = (temp_bool == "sim");
        num_imoveis++;
        cout << "Imóvel incluído com sucesso!\n";
    }
    choice = 1;
    break;
```
Funcionamento Passo a Passo
1. Verificação de Capacidade do Banco
    ```c++
    if (num_imoveis >= MAX_IMOVEIS)
    ```

    Verifica se o número atual de imóveis cadastrados já atingiu o limite (`MAX_IMOVEIS`).

    Se sim, exibe uma mensagem de erro e volta ao menu principal (`choice = 1`).

2. Coleta de Dados do Imóvel

    **a. Tipo do Imóvel**
    ```c++
    getline(cin, tipo_temp);
    ```
    Lê uma linha de entrada para armazenar o tipo do imóvel (como "Casa", "Apartamento").

    ```c++
    if (!tipo_temp.empty())
    ```
    `.empty()` verifica se a string está vazia (sem caracteres).

    Se não estiver vazia, o tipo é convertido para minúsculas com `tolower()`:

    ```c++
    tipo_temp[j] = tolower(tipo_temp[j]);
    ```

    `tolower(char c)` transforma um caractere maiúsculo em minúsculo.

    Útil para padronizar o formato dos dados.

    ```c++
    if (tipo_temp[j] == ' '){
        tipo_temp[j] = '_';
    ```

    Substitui espaços por sublinhados `_` para facilitar armazenamento e comparação de dados.

    **b. Finalidade**

    ```c++
    cin >> imoveis[num_imoveis].finalidade;
    ```

    Pode ser: venda, locação, temporada, ou aluguel.

    Caso inválido, é solicitado novamente.

    **c. Endereço**

    ```c++
    getline(cin, endereco_temp);
    ```

    Lê e formata o endereço, substituindo espaços por sublinhados.

3. Formatação de Strings: Bairro e Cidade
    ```c++
    bairro_temp[0] = toupper(bairro_temp[0]);
    ```
    `toupper(char c)` converte o caractere para maiúsculo.

    Utilizado para capitalizar a primeira letra do bairro e cidade.

    ```c++
    for (size_t j = 1; j < bairro_temp.length(); j++){
        bairro_temp[j] = tolower(bairro_temp[j]);
    ```
    `.length()` retorna o número de caracteres da string.

    Utilizado para converter as demais letras em minúsculas.

4. Dados Numéricos
    Coletados com validações para:
    * Área (area)
    * Valor (valor)
    * IPTU (iptu)
    * Número de quartos, suítes, banheiros, vagas

    Cada valor é validado para garantir que seja não-negativo ou positivo, conforme o campo.

5. Características Adicionais
    Campos de sim/não:

    Cozinha, sala, varanda, área de serviço

    Armários embutidos, ar-condicionado, aquecedor, ventilador

    Exemplo:

    ```c++
    cin >> imoveis[num_imoveis].cozinha;
    while (cozinha != "sim" && cozinha != "não") { ... }
    ```
6. Tipo de Piso
    ```c++
    cin >> imoveis[num_imoveis].piso;
    ```
    Convertido todo para minúsculo e espaços substituídos por `_`.

7. Estado de Conservação
    Deve ser um valor válido entre: péssimo, ruim, regular, bom, ótimo, novo.

    Valida a entrada e repete em caso de erro.

8. Incremento e Confirmação
    Após todos os dados serem validados e inseridos:

    ```c++
    num_imoveis++;
    ```
    O imóvel é registrado e o contador é incrementado.

### Explicação dos Comandos

|Comando|	Descrição|
|:----:|:------:|
|`.empty()`|	Verifica se a string está vazia. Retorna true se não houver caracteres.|
|`.length()`|	Retorna o número de caracteres na string.|
|`tolower(char)`|	Converte um caractere para minúsculo, se for uma letra maiúscula.|
|`toupper(char)`|	Converte um caractere para maiúsculo, se for uma letra minúscula.|

---

## Busca de Imóveis por Faixa de Valores

Este trecho de código faz parte de um menu de opções de um sistema de gerenciamento de imóveis. A `case 4` trata especificamente da **busca de imóveis com base em uma faixa de valores** definida pelo usuário.

### Etapas do Código

**a. Inicialização**

```c++
limparTela();
encontrou = false;
```

`limparTela()`: limpa a tela para melhorar a visualização do processo.

`encontrou = false`: inicializa a variável booleana que indica se algum imóvel foi encontrado.

**b. Entrada do Valor Mínimo**

```c++
cout << "Digite o valor mínimo: R$";
cin >> valor_minimo;
```

O usuário é solicitado a digitar o valor mínimo desejado.

**Validação**
```c++
while (valor_minimo < 0)
```

Garante que o valor mínimo não seja negativo.

Se for, a tela é limpa e o valor é solicitado novamente até que seja válido.

**c. Entrada do Valor Máximo**

```c++
cout << "Digite o valor máximo: R$";
cin >> valor_maximo;
```

O usuário informa o valor máximo da faixa de busca.

**Validação**
```c++
while (valor_maximo < valor_minimo)
```
Garante que o valor máximo seja maior ou igual ao valor mínimo.

Caso contrário, repete a solicitação até estar correto.

**d. Exibição dos Resultados**

```c++
limparTela();
cout << "\nImóveis encontrados na faixa de R$" << valor_minimo << " a R$" << valor_maximo << ":\n";
```

A tela é limpa novamente.

A faixa de valores é apresentada ao usuário.

Verificação de Existência de Imóveis
```c++
if (num_imoveis == 0){
    cout << "Não há imóveis no Banco de Dados.\n";
}
```

Caso não haja imóveis cadastrados, exibe uma mensagem apropriada.

**Loop de Busca**

```c++
for (i = 0; i < num_imoveis; i++)
```
Percorre todos os imóveis cadastrados.

Para cada imóvel, exibe os seguintes dados:
* Tipo
* Finalidade (preço ou aluguel)
* Endereço
* Bairro
* Cidade
* Área
* Valor

```c++
if (imoveis[i].finalidade == "aluguel"){
    cout << "Aluguel(dia): R$" << imoveis[i].valor << endl;
} else {
    cout << "Preço: R$" << imoveis[i].valor << endl;
}
encontrou = true;
```
Dependendo da finalidade do imóvel, exibe o valor corretamente.


**e. Verificação Final**

```c++
if (!encontrou)
{
    cout << "Nenhum imóvel encontrado na faixa de R$" << valor_minimo << " a R$" << valor_maximo << ".\n";
}
```
Caso encontrou continue false, exibe uma mensagem de que nenhum imóvel foi encontrado.

Como mencionado, isso pode ocorrer mesmo se imóveis forem exibidos, pois encontrou nunca é atualizado.

**f. Encaminhamento para o Menu**

```c++
choice = 1;
```
Retorna para a opção 1, provavelmente o menu principal.

---
## 📦 Busca de Imóveis por Características (case 5)
### 🧩 Visão Geral
Este trecho de código faz parte de um sistema de gerenciamento de imóveis. Especificamente, ele implementa o menu de busca de imóveis por características específicas. O usuário escolhe uma das 21 características disponíveis para filtrar os imóveis cadastrados, e o sistema exibe os que correspondem ao critério informado.

### 🏗️ Estrutura Principal
Início do case 5
```c++
Copy
Edit
case 5:
    limparTela();      
    encontrou = false;
```
* `limparTela()`: função que limpa a tela para melhor legibilidade.

* `encontrou`: flag para verificar se algum imóvel foi encontrado.

### 🧭 Menu de Características
O sistema apresenta ao usuário uma lista de 21 características possíveis para busca:

```c++
cout << "1. Tipo\n";
cout << "2. Finalidade\n";
...
cout << "21. Ventilador\n";
```

O número escolhido é armazenado em `caract`, e validado para garantir que esteja entre 1 e 21.

### 🔄 Estrutura de Busca: `switch(caract)`
A seguir, para cada valor de caract, é executado um bloco de código para:
* Ler o valor a ser buscado;
* Formatar esse valor, se necessário;
* Percorrer todos os imóveis cadastrados;
* Comparar a característica escolhida com a do imóvel;
* Exibir os imóveis compatíveis.

### 🔍 Explicações Detalhadas por Característica
1. **Tipo**

    ```c++
    getline(cin, busca_str);
    ```
    Substitui espaços por `_` e converte para minúsculas.

    Ex: "Apartamento Térreo" → apartamento_térreo.

2. **Finalidade**

    Valida se o valor é:

    "venda", "locação", "aluguel" ou "temporada".

3. **Endereço**

    Formata a string, substituindo espaços por `_`.

4. **Bairro e 5. Cidade**

    Formata:
    * Primeira letra em maiúscula;
    * Demais em minúscula;
    * Espaços viram `_`.

6. **Área (m²)**

    Busca por float > 0.

7. **IPTU**

    Busca por valor float >= 0.

8. **Quartos, 9. Suítes, 10. Banheiros, 11. Vagas**

    Busca por valores inteiros >= 0.

12. **Cozinha, 13. Sala, 14. Varanda, 15. Área de serviço**

    Busca por:

    "sim" ou "não" (strings).

    Validação textual.

16. **Piso**

    Formata a string como no caso de "tipo", convertendo para minúsculas e `_`.

17. **Conservação**

    Validação contra valores permitidos:

    "péssimo", "ruim", "regular", "bom", "ótimo", "novo".

18. **Armários embutidos, 19. Ar-condicionado, 20. Aquecedor, 21. Ventilador**

    Busca booleana:

        Entrada "sim" → true, "não" → false.

### 📤 Exibição dos Resultados

Para todos os casos, quando um imóvel atende ao critério, é exibido:

```c++
cout << "Imóvel " << (i + 1) << ": "
     << imoveis[i].tipo << ", "
     << imoveis[i].finalidade << ", "
     << imoveis[i].endereco << endl;
```

Se nenhum imóvel for encontrado, uma mensagem pode ser exibida (não presente no trecho, mas recomendada).

---

## 📊 Relatório Estatístico de Imóveis - Explicação do Código

##3 🧩 Contexto Geral

O trecho de código pertence ao `case 6` de um `switch`, que corresponde à opção de **gerar um relatório estatístico** sobre os imóveis armazenados no sistema. O relatório é exibido no console e, opcionalmente, salvo em um arquivo `.txt`.

### ✅ Estrutura do Código

#### 1. **Verificação Inicial**

```c++
if (num_imoveis == 0)
```
Verifica se há imóveis cadastrados.

Caso não haja, exibe uma mensagem e termina o processo.

#### 2. Inicialização de Variáveis Acumuladoras
São zeradas variáveis responsáveis por somar valores de características dos imóveis (como área, valor, IPTU, etc.), contar tipos de imóveis, finalidades, comodidades, estados de conservação e tipos de piso.

#### 3. Laço de Processamento
```c++
for (i = 0; i < num_imoveis; i++) { ... }
```
Percorre todos os imóveis cadastrados e:
* Soma valores como preço, área, IPTU, número de quartos, etc.
* Identifica o imóvel mais caro e mais barato.
* Conta ocorrências de:
* Tipos de imóvel (casa, apartamento, galpão, etc.).
* Finalidade (venda, locação, etc.).
* Comodidades (armário, ar-condicionado, etc.).
* Cômodos (cozinha, sala, etc.).
* Estado de conservação (novo, bom, ruim...).
* Tipo de piso (cerâmica, madeira, etc.).

#### 4. Exibição do Relatório no Console
Após o processamento:
* Calcula médias:
    * Valor médio.
    * Área média.
    * Média de IPTU, quartos, suítes, banheiros, vagas.
* Exibe os imóveis mais caro e mais barato.
* Mostra porcentagens e barras gráficas (geradas por barradeporcentagem()) para:
    * Tipos de imóveis.
    * Finalidades.
    * Comodidades.
    * Cômodos.
    * Conservação.
    * Pisos.

#### 5. Salvar em Arquivo?
```c++
cout << "Deseja salvar este relatório em um arquivo? (sim/não): ";
```
Usuário decide se deseja salvar o relatório.

Se sim:

Cria o arquivo relatorio.txt.

Escreve as mesmas informações do console no arquivo, inclusive com as barras gráficas.

### 🧠 Funções Utilizadas
`limparTela()` – Limpa o console para melhorar a visualização.

`barradeporcentagem(int porcentagem)` – Provavelmente retorna uma string com uma barra visual representando a porcentagem.

`ofstream` – Usado para gravar o relatório em um arquivo de texto.

---

## 📄 Explicação do Código: Visualização de um Único Imóvel

Este trecho de código faz parte de um sistema de gerenciamento de imóveis e corresponde à opção 7 de um menu switch-case, responsável por exibir os detalhes de um imóvel específico a partir da escolha do usuário.

### 🧩 Estrutura do Código

```c++
case 7:
    limparTela();
    cout << "Visualizar Imóvel\n";
    ...
    choice = 1;
    break;
```

Esse bloco é executado quando o usuário escolhe a opção 7 no menu principal. A seguir, detalhamos cada parte.

### 🔍 Etapas Detalhadas
#### 1. Limpeza da tela

```c++
limparTela();
```

Antes de qualquer ação, a tela é limpa para melhorar a apresentação das informações ao usuário.

#### 2. Solicitação do número do imóvel

```c++
cout << "Digite o número do imóvel (1 a " << num_imoveis << "): ";
cin >> i;
i--;
```

O programa solicita ao usuário o número do imóvel que deseja visualizar.

Como os índices em arrays começam do zero, o valor informado é decrementado em 1 (i--) para corresponder ao índice correto no vetor imoveis.

#### 3. Validação de entrada

```c++
while (i < 0 || i >= num_imoveis) {
    limparTela();
    cout << "ERROR - Número de imóvel inválido. Digite um número entre 1 e " << num_imoveis << ".\n";
    ...
    cin >> i;
    i--;
}
```

Garante que o usuário forneça um número de imóvel válido.

Repete a solicitação enquanto o número estiver fora do intervalo válido.

#### 4. Exibição dos dados do imóvel

```c++
cout << "\nDetalhes do Imóvel " << (i + 1) << ":\n";
cout << "Tipo: " << imoveis[i].tipo << endl;
...
```

Após validar o número, são exibidos todos os detalhes do imóvel correspondente, incluindo:

|Propriedade|	Exemplo de Conteúdo|
|:-:|:-:|
|Tipo|	"Apartamento", "Casa"|
|Finalidade|	"Venda", "Aluguel"|
|Endereço, Bairro, Cidade|	Localização completa|
|Área, Valor, IPTU|	Informações financeiras|
|Quartos, Suítes, etc.|	Características internas|
|Piso, Conservação|	Acabamento e estado geral|
|Itens opcionais|	Armários, ar-condicionado, etc.|

As variáveis booleanas são exibidas como "sim" ou "não" com uso do operador ternário:

```c++
cout << "Ar-condicionado: " << (imoveis[i].ar_condicionado ? "sim" : "não") << endl;
```

#### 5. Encaminhamento ao menu principal

```c++
choice = 1;
```

Após exibir as informações, a variável choice é setada para 1, indicando que o fluxo do programa deve retornar ao menu principal ou perguntar se o usuário deseja sair.

---

## 📘 Edição de Imóvel

Este trecho de código implementa a funcionalidade de edição de um imóvel cadastrado no sistema. Ele é executado quando o usuário escolhe a opção 8 no menu principal do programa.

### 🧩 Estrutura Geral
```c++
case 8:
    // Código de edição de imóvel
    break;
```
O case 8 está dentro de um switch, responsável por tratar a opção de menu escolhida pelo usuário. Quando essa opção é selecionada, o sistema permite modificar os dados de um imóvel previamente cadastrado.

### 🧼 Limpeza de Tela e Seleção de Imóvel
Antes de iniciar a edição, a tela é limpa e o usuário é solicitado a inserir o número do imóvel que deseja editar:

```c++
limparTela();
cout << "Editar Imóvel\n";
cout << "Digite o número do imóvel (1 a " << num_imoveis << "): ";
cin >> i;
i--; // Índice ajustado (vetores começam em 0)
```

Se o número for inválido, um laço while obriga o usuário a digitar novamente até que um número válido seja fornecido.

### 📋 Exibição dos Dados Atuais
Depois de selecionar um imóvel válido, o programa exibe todos os dados atuais do imóvel escolhido:

```c++
cout << "\nDetalhes do Imóvel " << (i + 1) << ":\n";
```

### 🛠️ Edição dos Dados
#### 🔤 Campos de Texto
* Tipo do imóvel: é convertido para minúsculas e espaços são trocados por `_`.

* Finalidade: o usuário precisa digitar um valor válido dentre as opções permitidas.

* Endereço, Bairro e Cidade: os espaços são convertidos para _ e a capitalização é ajustada.

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

Tem os espaços substituídos por _.

#### 🧱 Estado de Conservação
O estado de conservação deve ser uma das opções fixas:

```c++
péssimo, ruim, regular, bom, ótimo, novo
```

Se a entrada não for uma dessas, o programa exibe um erro e solicita novamente.

#### ✅ Confirmação Final
Ao final do processo, o sistema exibe uma mensagem de sucesso:

```c++
cout << "\nImóvel editado com sucesso!\n";
```
E altera a variável choice para 1, retornando ao menu principal.

---

## 📦  Remover Imóvel
Este trecho de código faz parte de um sistema de gerenciamento de imóveis em C++. O case 9 é responsável por remover um imóvel cadastrado com base em seu número.

### 🔁 Estrutura do Case
```c++
case 9:
```
Este case é uma opção de um switch-case, normalmente dentro de um menu principal. A opção 9 corresponde à remoção de um imóvel.

### 🧹 Limpeza da Tela
```c++
limparTela();
```
Função chamada para limpar a tela, geralmente para deixar a interface do usuário mais limpa antes de interagir com ele.

### 📥 Solicitação do Número do Imóvel
```c++
cout << "Digite o número do imóvel a ser removido (1 a " << num_imoveis << "): ";
cin >> i;
i--;
```
Solicita ao usuário o número do imóvel a ser removido.

Como os vetores começam no índice 0, é feito um ajuste (i--) para converter o número do usuário (1-based) para o índice interno (0-based).

### 🧾 Validação da Entrada
```c++
while (i < 0 || i >= num_imoveis)
```
Garante que o índice está dentro do intervalo válido.

Caso não esteja, o sistema:

* Limpa a tela;

* Exibe uma mensagem de erro;

* Solicita novamente a entrada.

### ❌ Remoção do Imóvel
```c++
for (int j = i; j < num_imoveis - 1; j++)
{
    imoveis[j] = imoveis[j + 1];
}
```
Esse for desloca todos os elementos do vetor uma posição para trás, sobrescrevendo o imóvel a ser removido.

Isso mantém a integridade da estrutura do vetor após a exclusão.

### 🔻 Decremento do Total de Imóveis
```c++
num_imoveis--;
```
Após remover o item e reorganizar o vetor, o total de imóveis cadastrados é atualizado.

### ✅ Mensagem de Sucesso
```c++
cout << "\nImóvel removido com sucesso!\n";
```
Confirma ao usuário que a operação foi realizada com êxito.

### 🔁 Retorno ao Menu
```c++
choice = 1;
```
Define a variável choice para 1, o que provavelmente faz o programa retornar ao menu principal ou perguntar ao usuário o que deseja fazer em seguida.

### 📝 Resumo
|Ação	|Propósito|
|:-:|:-:|
|limparTela()|	Melhorar visualização para o usuário|
|Solicitação do número	|Identificar o imóvel a ser removido|
|Validação	|Evitar índice inválido no vetor|
|Loop de remoção|	Sobrescreve o imóvel e reorganiza o vetor|
|num_imoveis--|	Atualiza o total de imóveis após a exclusão|
|Mensagem de sucesso	|Feedback para o usuário|
|choice = 1|	Controla o fluxo do programa para continuar a execução|

---

## Salvamento Condicional dos Dados
Ao finalizar o programa, o sistema realiza um processo interativo para confirmar com o usuário se deseja ou não atualizar os dados no arquivo BD_Imoveis2.txt.

```c++
    limparTela();
    cout << "\nDeseja atualizar os dados no arquivo BD_Imoveis2.txt? (s/n): ";
    cin >> resposta;
    while (resposta != "s" && resposta != "S" && resposta != "n" && resposta != "N"){
        cout << "ERROR - Opção inválida.\n\n";
        cout << "\nDeseja atualizar os dados no arquivo BD_Imoveis2.txt? (s/n): ";
        cin >> resposta;
    }
    if (resposta == "s" || resposta == "S"){
        ofstream arquivo_saida("BD_Imoveis2.txt");
        if (!arquivo_saida.is_open()){
            cerr << "Erro ao abrir o arquivo BD_Imoveis2.txt para escrita." << endl;
            return 1; 
        }
        arquivo_saida << "Tipo Finalidade Endereço Bairro Cidade Área Valor IPTU Quartos Suítes Banheiros Vagas Cozinha Sala Varanda Área_de_serviço Piso Conservação Armários Ar-condicionado Aquecedor Ventilador\n";
        for (i = 0; i < num_imoveis; i++){
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
        arquivo_saida << "fim";
        arquivo_saida.close();
        cout << "\nDados atualizados com sucesso no arquivo BD_Imoveis2.txt.\n";
    }else{
        cout << "\nOs dados não foram atualizados no arquivo BD_Imoveis2.txt.\n";
    }
    cout << "\n\nPrograma encerrado.\n\n";
    return 0;
```

### 🔄 Funcionamento
1. **Limpeza da tela:** Antes de exibir a pergunta final, a tela é limpa com a função limparTela(), proporcionando uma interface mais limpa para o encerramento.
2. **Pergunta ao usuário:** O programa exibe a seguinte mensagem no terminal:
```text
Deseja atualizar os dados no arquivo BD_Imoveis2.txt? (s/n):
```
3. **Validação de entrada:** Se o usuário digitar algo diferente de s, S, n ou N, será informado que a opção é inválida e será solicitado novamente até uma resposta válida ser fornecida.
4. **Atualização dos dados:**
* Se o usuário optar por "sim", o programa:
    * Abre o arquivo BD_Imoveis2.txt em modo de escrita.
    * Escreve o cabeçalho na primeira linha do arquivo (linha ignorada).
    * Sobrescreve o conteúdo com os dados atualizados dos imóveis.
    * Conclui o arquivo com a palavra fim, que sinaliza o fim da base de dados.
    * Informa que a atualização foi realizada com sucesso.
* Se o usuário escolher "não", o programa apenas exibe uma mensagem informando que os dados não foram alterados.

5. **Encerramento:** Após essa etapa, uma mensagem de encerramento é exibida e o programa termina sua execução.

### 💡 Importante
Esse mecanismo garante que o usuário tenha controle total sobre a persistência das alterações feitas durante a sessão, evitando alterações acidentais nos dados salvos.

### Utilização de Operador Ternário
O trecho:

```c++
(imoveis[i].armarios_embutidos ? "sim" : "nao")
```

é um operador ternário que serve para simplificar uma estrutura condicional if-else.

#### ✅ O que ele faz:
Esse código verifica se o campo armarios_embutidos do imóvel atual (imoveis[i]) é true (ou seja, possui armários embutidos). Se for:
* Retorna `sim`
* Caso contrário, retorna `nao`
#### 🔍 Como funciona:
A sintaxe geral do operador ternário é:

```c++
(condição) ? valor_se_verdadeiro : valor_se_falso;
```

No caso do projeto:

```c++
Condição: imoveis[i].armarios_embutidos
(campo booleano: true ou false)
```
* Se verdadeiro: `sim`
* Se falso: `nao`

Portanto, essa linha está convertendo o valor booleano para uma representação textual compreensível, que será gravada no arquivo **BD_Imoveis2.txt**.

---

## Considerações Finais
O código é modular e didático, facilitando futuras manutenções e adições de novas funcionalidades. A utilização de vetores, estruturas e arquivos proporciona uma base sólida para o aprendizado e prática de programação em C++ aplicada a sistemas reais.

---

## Autor

* **Joaquim Pedro do Nascimento Moreira de Jesus** - Matrícula: 2025.1.08.014

---