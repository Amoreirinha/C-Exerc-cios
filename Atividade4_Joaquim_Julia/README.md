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

## Autores

* **Joaquim Pedro do Nascimento Moreira de Jesus** - Matrícula: 2025.1.08.014
* **Júlia Rocha** - Matrícula: 2025.1.08.015

---