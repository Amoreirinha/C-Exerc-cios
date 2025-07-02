EDITOR DE IMAGENS EM C++

DESCRIÇÃO DO PROJETO:

Este é um aplicativo de edição de imagens PGM desenvolvido em C++. Com o objetivo de aprender a manipular matrizes (imagens) usando ponteiros, implementando funções que processam dados de arquivos PGM (formato de imagem em texto) para gerar novas imagens modificadas. O programa permite a leitura da imagem, sua edição dependendo da escolha do usuário e a salvando na pasta determinada.

FUNCIONALIDADES PRINCIPAIS:

O sistema oferece um menu de opções interativo ao usuário, para que ele possa manipular a imagem, que contem as operações:

- Redefinir imagem PGM original: Carrega novamente a imagem inicial (original).
- Exibir valores dos pixels: Mostra os valores numéricos da matriz da imagem.
- Escurecer imagem: Reduz o brilho dos pixels conforme um valor definido pelo usuario.
- Clarear imagem: Aumenta o brilho dos pixels conforme um valor definido pelo usuário.
- Gerar negativo da imagem: Inverte as cores (tonalidades de cinza).
- Binarizar imagem: Converte para preto e branco usando um limiar ou a média dos pixels.
- Rotacionar imagem 90° para a esquerda: Gira a imagem no sentido anti-horário.
- Rotacionar imagem 90° para a direita: Gira a imagem no sentido horário.
- Rotação Vertical: Espelha a imagem no eixo vertical.
- Rotação Horizontal: Espelha a imagem no eixo horizontal.
- Iconizar imagem: Reduz a imagem para um ícone de 64×64 pixels.
- Sair: Encerra o programa.

ESTRUTURA DO APLICATIVO

O programa começa lendo os valores de cada pixel do arquivo cat.pgm e os armazena em uma matriz de 1024x1024 em ordem. Cada valor definido na matriz é um tom de cinza diferente que tem valor máximo de 255 (sendo 0 preto e 255 branco) e ao final da manipulação da matriz as diversas mudanças que o usuario fez serão salvas dentro da pasta ImagensDosProcessos, todos com nomes diferentes, sendo eles a data e hora de cada salvamento.

FORMATO DO ARQUIVO DE IMAGEM (cat.pgm)

O arquivo de imagem contem um cabeçalho que contém informações importantes sendo eles:
- O tipo do arquivo (P2 no arquivo usado nesse projeto)
- Largura e altura em pixels (1024x1024)
- Valor máximo de intensidade dos tons de cinza (255)
- Um comentário (opcional)
- Valores dos pixels (a partir daqui as informações serão salvas na matriz)

REGRA ESPECÍFICA DO ARQUÍVO:
- As primeiras 4 linhas do arquivo, incluindo o possível comentário, são apenas informações de formatação da imagem, que durante a leitura, são ignoradas.

INCLUSÃO DE BIBLIOTECAS:

main.cpp
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include "functions.h"

functions.h
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <time.h>

Essas bibliotecas tem importantes funções para o código:
- iostream: Entrada e saída de dados pelo console.
- string.h: Usada para operações com strings
- fstream: Leitura e escrita em arquivos.
- time.h: Obtem a data e a hora para o nome dos arquivos pgm.
- stdio.h: Entrada e saída de dados (apenas para as cores)
- functions.h: Declara as funções personalizadas usadas no programa.

FUNÇÕES

FUNÇÃO PRINCIPAL (main.cpp)
A função mainé responsável por:
- Declara os tipos das variaveis e seus valores, fixos ou apenas iniciais.
- Apresenta o menu interativo
- Chama as funções auxiliares do functions.h para:
- Gravar as alterações feitas, individualmente, na imagem
- Executar as operações, conforme o usuário escolhe

FUNÇÕES AUXILIARES
O código está separado em duas partes o main.cppe o functions.h, em que no functions.h, é armazenada as funções que serão chamadas no main.cpp, como:

- Leitura da imagem: Lê um arquivo PGM (formato P2) e carrega os pixels em uma matriz.
- Salvamento da imagem: Salva a matriz de pixels em um arquivo PGM com nome único (data/hora), incluindo um cabeçalho de "tipo" com histórico de alterações.
- Limpar a tela: Limpa o terminal.
- setColor/resetColor: respectivamente altera a cor do texto e do fundo (opcional) e reseta a cor do terminal para a padrão.
- Mostra valor do pixel: mostra valor de cada pixel que forma a imagem.
- Escurecer imagem: diminui a intensidade dos píxels (escurece a imagem).
- Clarear imagem: aumenta a intensidade dos píxels (clareia a imagem).
- Negativa a imagem: inverte os tons de cinza os tornando negativo
- Binariza a imagem: converte para preto ou branco com base ou na media ou em um limiar.
- Rotação para a esquerda: gira a imagem 90° para a esquerda (sentido anti-horário).
- Rotação para a direira: gira a imagem 90° para a direita (sentido horário).
- Rotação vertical: espelha a imagem verticalmente (inverte as colunas).
- Rotação horizontal: espelha a imagem horizontalmente (inverte as linhas).
- Iconizar a imagem: zria uma versão reduzida (ícone) da imagem original, fazendo média de blocos.

CONSIDERAÇÕES FINAIS
O projeto cumpre seu objetivo de oferecer um editor básico para imagens PGM em terminal. Ele permite ler, salvar e aplicar transformações como brilho, negativo, binarização, rotações e redução de tamanho. A divisão entre biblioteca de funções e programa principal facilita o uso e a manutenção.

AUTORES
- Joaquim Pedro do Nascimento Moreira de Jesus - Matrícula: 2025.1.08.014
- Victória de Almeida Tambasco - Matrícula: 2025.1.08.030
