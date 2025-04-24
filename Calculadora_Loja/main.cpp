/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.014
 *
 * Created on 20 de março de 2025, 08:52
 */

#include <cstdlib>
#include <stdio.h>
#include <string.h>

/*
3. Uma loja dá 10% de desconto para compras acima de R$100,00,
   15% acima de R$500,00 e 20% acima de R$1.000,00.
   E ainda, no cartão de crédito, faz o valor da compra em 3 parcelas para compras até R$500,00,
   em 6 parcelas até R$1.000,00 e em 12 parcelas acima disso. Compras até R$100,00 não parcela no cartão de crédito.
   Peça o valor da compra ao usuário e informe o valor final a ser pago, aplicando o desconto se necessário,
   e o valor das parcelas para o cartão de crédito.

Joaquim Pedro do Nascimento Moreira de Jesus
20/03/2025
2025.1.08.014
 */
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Variável / Dados
    float valor,valor_desconto,valor_parcelas;
    int pagamento;
    
    //Entrada
    printf("\nCalculadora de descontos\n");
    printf("\nDigite o valor total da compra:\n");
    scanf("%f",&valor);
    printf("\nSelecione a forma de pagamento:\n\t1.Crédito\n\t2.Débito\n\t3.Pix\n");
    scanf("%d",&pagamento);
    
    //Processamento e Saída
    
    if (valor>100 and valor<=500){
        valor_desconto = valor*0.9;
    }else{
        if(valor>500 and valor<=1000){
            valor_desconto = valor*0.85;
        }else{
            if(valor>1000){
                valor_desconto = valor*0.8;
            }else{
                if (valor<0){
                    printf("Valor Inválido");
                    return 0;
                }else{
                    valor_desconto = valor;                    
                }
            }
        }
    }
    
    if (pagamento == 1){
        if (valor<=500 and valor>100){
            valor_parcelas=valor_desconto/3;
            printf("\n\n\t_____________________\n\n\tValor total: R$%.2f\n\tValor com total com desconto: R$%.2f\n\tMétodo de pagamento: Crédito\n\tQuantidade de Parcelas: 3 x R$%2.f",valor,valor_desconto,valor_parcelas);
        }else{
            if(valor>500 and valor<=1000){
                valor_parcelas=valor_desconto/6;
                printf("\n\n\t_____________________\n\n\tValor total: R$%.2f\n\tValor com total com desconto: R$%.2f\n\tMétodo de pagamento: Crédito\n\tQuantidade de Parcelas: 6 x R$%2.f",valor,valor_desconto,valor_parcelas);
            }else{
                if(valor<=100){
                    valor_parcelas=valor_desconto;
                    printf("\n\n\t_____________________\n\n\tValor total: R$%.2f\n\tValor com total com desconto: R$%.2f\n\tMétodo de pagamento: Crédito\n",valor,valor_desconto);
                }else{
                    valor_parcelas=valor_desconto/12;
                    printf("\n\n\t_____________________\n\n\tValor total: R$%.2f\n\tValor com total com desconto: R$%.2f\n\tMétodo de pagamento: Crédito\n\tQuantidade de Parcelas: 12 x R$%2.f",valor,valor_desconto,valor_parcelas);
                }
            }
        }
    }else{
        if (pagamento == 2){
            printf("\n\n\t_____________________\n\n\tValor total: R$%.2f\n\tValor com total com desconto: R$%.2f\n\tMétodo de pagamento: Débito\n",valor,valor_desconto);
        }else{
            if (pagamento == 3){
                printf("\n\n\t_____________________\n\n\tValor total: R$%.2f\n\tValor com total com desconto: R$%.2f\n\tMétodo de pagamento: Pix\n",valor,valor_desconto);
            }else{
                printf("\nForma de Pagamento Inválida");
                return 0;                      
            }
        }
    }
    
    
    
    
    return 0;
}

