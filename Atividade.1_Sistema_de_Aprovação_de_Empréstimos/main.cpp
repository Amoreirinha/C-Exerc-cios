/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: joaquim-pedro
 *
 * Created on March 22, 2025, 12:11 PM
 */

/*
Joaquim Pedro do Nascimento Moreira de Jesus
RA: 2025.1.08.014
Data: 22/03/2025
Alfenas - MG
AED's Prática

Atividade 01 - Sistema de Aprovação de Empréstimo
Objetivo da atividade:
      - Criação de um programa para avaliação de Empréstimo tendo como variáveis de etrada a idade do solicitante, sua renda, se possuie ou não nome negativado e se tem atrasos em parcelas atualmente e nos últimos 2 anos.
      - O programa deve verificar, de acordo com os parâmetros estabelecidos no código, qual resultado o solicitante pode ter, sendo esses:
              1. Empréstimo Negado
              2. Empréstimo de Baixo Valor (até R$ 5.000,00)
              3. Empréstimo de Médio Valor (até R$ 20.000,00)
              4. Empréstimo de Alto Valor (acima de R$ 20.000,00)
      - O programa também deve avisar no caso de entradas inválidas, como idade ou renda negativas.

*/

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Variáveis / Dados
    int idade, nomenegativo, parcelasatraso, parcelasatraso2anos;
    float renda;
    
    //Entradas
    printf("\nBem-vindo ao Sistema de Aprovação de Empréstimo!\nPara a avaliação da solicitação de empréstimo será necessário a entrada de alguns dados.\nDigite a idade do solicitante:\n");
    scanf("%d",&idade);
    printf("\nDigite a renda mensal do solicitante:\nR$");
    scanf("%f",&renda);
    printf("\nHistórico de crédito do solicitante negativado?\nDigite 0 para 'Não' e 1 para 'Sim'\n");
    scanf("%d",&nomenegativo);
    printf("\nDigite o número atual de parcelas em atraso:\n");
    scanf("%d",&parcelasatraso);
    printf("\nDigite o número de parcelas em atraso nos últimos 2 anos:\n");
    scanf("%d",&parcelasatraso2anos);
    
    //Processamento e Saída
    //Validação de entradas
    if (idade <0 || nomenegativo != 0 && nomenegativo != 1 || parcelasatraso < 0 || parcelasatraso2anos < 0 || renda < 0){
        printf("\nValores inválidos inseridos!");
        //Código para informar qual entrada é inválido
        if(idade<0){
                               Exemplo:
                               Exemplo:
                               Exemplo:
                         Idade = 18
                         Renda = R$2500.00
                         Nome = 0 (Nome Limpo)
                         Parcelas em atraso atualmente= 3
                         Parcelas em atraso nos últimos 2 anos = 3
                         
                         Nesse caso ele passa pela verificação do Empréstimo Negado, mas n~o se qualifica para os outros tipos de Empréstimos.
                         */
                        printf("Empréstimo Negado");
                    }
                }
            }
        }
    }
    
    return 0;
}
                   Idade = 18
                         Renda = R$2500.00
                         Nome = 0 (Nome Limpo)
                         Parcelas em atraso atualmente= 3
                         Parcelas em atraso nos últimos 2 anos = 3
                         
                         Nesse caso ele passa pela verificação do Empréstimo Negado, mas n~o se qualifica para os outros tipos de Empréstimos.
                         */
                        printf("Empréstimo Negado");
                    }
                }
            }
        }
    }
    
    return 0;
}
                   Idade = 18
                         Renda = R$2500.00
                         Nome = 0 (Nome Limpo)
                         Parcelas em atraso atualmente= 3
                         Parcelas em atraso nos últimos 2 anos = 3
                         
                         Nesse caso ele passa pela verificação do Empréstimo Negado, mas n~o se qualifica para os outros tipos de Empréstimos.
                         */
                        printf("Empréstimo Negado");
                    }
                }
            }
        }
    }
    
    return 0;
}
      printf("\nO valor %d para idade do solicitante é inválido",idade);
        }
        if(renda<0){
            printf("\nO valor %.2f para renda do solicitante é inválido",renda);
        }
        if(nomenegativo !=0 && nomenegativo !=1){
            printf("\nO valor %d para a opção de histórico de crédito do solicitante é inválido.\nDigite 0 para 'Não' e 1 para 'Sim'",nomenegativo);
        }
        if(parcelasatraso < 0){
            printf("\nO valor %d para a quantidade de parcelas em atraso atualmente é inválido",parcelasatraso);
        }
        if(parcelasatraso2anos < 0){
            printf("\nO valor %d para a quantidade de parcelas em atraso nos últimos 2 anos é inválido",parcelasatraso2anos);
        }
    }else{
        //Empréstimo Negado
        if (renda < 2000 || nomenegativo == 1 || idade < 18 || idade > 70){
            printf("Empréstimo Negado");
        }else{
            //Empréstimo de Baixo Valor (até R$ 5.000,00)
            if (renda >= 2000 && renda < 5000 && parcelasatraso <= 2){
                printf("Empréstimo de Baixo Valor (até R$ 5.000,00)");                
            }else{
                //Empréstimo de Médio Valor (até R$ 20.000,00)
                if(renda >= 5000 && renda <=10000 && parcelasatraso2anos <=4){
                    printf("Empréstimo de Médio Valor (até R$ 20.000,00)");
                }else{
                    //Empréstimo de Alto Valor (acima de R$ 20.000,00)
                    if(renda > 10000 && parcelasatraso2anos == 0 && parcelasatraso == 0){
                        printf("Empréstimo de Alto Valor (acima de R$ 20.000,00)");
                    }else{
                        /*
                         Empréstimo negado para o caso dele ter valores que não desclassifiquem de imediato, mas não consiga os outros tipos de empréstimos
                         Exemplo:
                         Idade = 18
                         Renda = R$2500.00
                         Nome = 0 (Nome Limpo)
                         Parcelas em atraso atualmente= 3
                         Parcelas em atraso nos últimos 2 anos = 3
                         
                         Nesse caso ele passa pela verificação do Empréstimo Negado, mas n~o se qualifica para os outros tipos de Empréstimos.
                         */
                        printf("Empréstimo Negado");
                    }
                }
            }
        }
    }
    
    return 0;
}

