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
#include <cmath>
```

Essas bibliotecas oferecem funcionalidades essenciais:

* **cstdlib:** Funções utilitárias (como system).
* **fstream:** Leitura e escrita em arquivos.
* **iostream:** Entrada e saída de dados pelo console.
* **string.h:** Manipulação de strings (poderia ser substituída por <string> para uso de std::string).
* **cmath:** Funções matemáticas, como pow, sqrt, etc.

---

## Função limparTela

```c++
void limparTela() {
    cout << "\033[H\033[J";
}
```

Utiliza códigos de escape ANSI para limpar o terminal, proporcionando uma melhor experiência visual ao usuário.

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
        string armarios, ar_condicionado, aquecedor, ventilador;
        arquivo >> armarios;
        imoveis[i].armarios_embutidos = (armarios == "sim");
        arquivo >> ar_condicionado;
        imoveis[i].ar_condicionado = (ar_condicionado == "sim");
        arquivo >> aquecedor;
        imoveis[i].aquecedor = (aquecedor == "sim");
        arquivo >> ventilador;
        imoveis[i].ventilador = (ventilador == "sim");
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
        imoveis[i].armarios_embutidos = (armarios == "sim");
        ```
        Assim:
        * Se o texto no arquivo era `sim`, o campo armarios_embutidos receberá **`true`**.
        * Se era `nao`, o campo receberá **`false`**.

Essa abordagem garante que todos os imóveis válidos sejam lidos corretamente e que o vetor esteja pronto para as demais operações do sistema.

---

## Estrutura do Menu
O menu principal é exibido no terminal, oferecendo ao usuário diversas opções numeradas para interação. Cada escolha leva a uma função correspondente, que realiza a ação desejada (inclusão, busca, estatísticas, listagem etc.).

---

## Salvamento Condicional dos Dados
Ao finalizar o programa, o sistema realiza um processo interativo para confirmar com o usuário se deseja ou não atualizar os dados no arquivo BD_Imoveis2.txt.

```c++
limparTela(); 
    cout << "\nDeseja atualizar os dados no arquivo BD_Imoveis2.txt? (s/n): ";
    cin >> resposta; 
    while (resposta != "s" && resposta != "S" && resposta != "n" && resposta != "N") {
        cout << "ERROR - Opção inválida.\n\n";
        cout << "\nDeseja atualizar os dados no arquivo BD_Imoveis2.txt? (s/n): ";
        cin >> resposta; 
    }
    if (resposta == "s" || resposta == "S") {
        ofstream arquivo_saida("BD_Imoveis2.txt"); 
        if (!arquivo_saida.is_open()) {
            cerr << "Erro ao abrir o arquivo BD_Imoveis2.txt para escrita." << endl;
            return 1; 
        }
        for (i = 0; i < num_imoveis; i++) {
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
                          << (imoveis[i].armarios_embutidos ? "sim" : "nao") << " "
                          << (imoveis[i].ar_condicionado ? "sim" : "nao") << " "
                          << (imoveis[i].aquecedor ? "sim" : "nao") << " "
                          << (imoveis[i].ventilador ? "sim" : "nao") 
                          << endl;
        }
        arquivo_saida << "fim"; /
        arquivo_saida.close(); 
        cout << "\nDados atualizados com sucesso no arquivo BD_Imoveis2.txt.\n";
    } else {
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