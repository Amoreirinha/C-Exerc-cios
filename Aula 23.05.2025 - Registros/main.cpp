/* 

 Tema: Registros
 Variável composta Heterogênea

 typdef - define um novo tipo de dado

 Exemplo:

 typedef struct {
    char nome[50];
    int idade;
    float altura;
    char sexo;
} Pessoa; // Nome para o novo tipo de dado

Pessoa p1, p2, p3; // Definindo variáveis do tipo Pessoa

// Definindo os valores para as variáveis

p1.nome = "João";
p1.idade = 25;
p1.altura = 1.75;
p1.sexo = 'M';

p2.nome = "Maria";
p2.idade = 30;
p2.altura = 1.65;
p2.sexo = 'F';

p3.nome = "José";
p3.idade = 28;
p3.altura = 1.80;
p3.sexo = 'M';

 * ifstream arquivo ("entrada.txt");
 * i - input
 * f - file
 * stream - fluxo de caracteres
 * arquivo - vatiável
 * ("entrada.txt") - caminho
 * entrada.txt - nome do arquivo nos diretórios
 * 
 * ofstream arquivo1 ("saida.txt");
 * o - output
 * f - file
 * stream - fluxo de caracteres
 * ("saida.txt") - caminho
 * saida.txt - nome do arquivo nos diretórios
 * 
 * arquivo >> figura;
 * arquivo - de onde vem
 * >> - operador de fluxo de caracteres
 * figura - variável
 * 
 * arquivo1 << numero;
 * arquivo1 - para onde vai
 * << - operador de fluxo de caracteres
 * numero - variável

 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    typedef struct{
        string nome;
        string email;
        int idade;
        int ddd;
        int celular;
        string cidade;
        string estado;
        string pais;
        string endereco;
        string bairro;
        string cep;      
    } TypeAmigo; // Nome para o novo tipo de dado

    const int TAM = 100; // Definindo o tamanho do vetor
    TypeAmigo agenda[TAM]; // Definindo variáveis do tipo TypeAmigo

    bool loop = true, continuar = true;
    int i = 0, choice = 0;
    string nome;
    string email;
    int idade;
    int ddd;
    int celular;
    string cidade;
    string estado;
    string pais;
    string endereco;
    string bairro;
    string cep;  

    ifstream arquivo ("agenda.txt");
    
    if(!arquivo.is_open()){
        cout<<"\nErro: Arquivo não encontrado.\n";
        return 1;
    }

    while(continuar){
        if(arquivo.eof()){
            continuar = false;
        }else{
        for(i = 0; i < TAM; i++){           
               
            arquivo >> agenda[i].nome; 
                    arquivo >> agenda[i].email;
                    arquivo >> agenda[i].idade;
                    arquivo >> agenda[i].ddd;
                    arquivo >> agenda[i].celular;
                    arquivo >> agenda[i].cidade;
                    arquivo >> agenda[i].estado;
                    arquivo >> agenda[i].pais;
                    arquivo >> agenda[i].endereco;
                    arquivo >> agenda[i].bairro;
                    arquivo >> agenda[i].cep;                
            }
        }
    }
    

    arquivo.close();

    while(loop){       
        switch(choice){
            case 0:
                cout << "\n\nEscolha uma opção:";
                cout << "\n\t1 - Adicionar contato";
                cout << "\n\t2 - Visualizar todos os contatos";
                cout << "\n\t3 - Procurar contato por nome";
                cout << "\n\t4 - Procurar contato por email";
                cout << "\n\t5 - Procurar contato por celular";
                cout << "\n\t6 - Filtrar contatos por cidade";
                cout << "\n\t7 - Filtrar contatos por estado";
                cout << "\n\t8 - Filtrar contatos por pais";
                cout << "\n\t9 - Filtrar contatos por bairro";
                cout << "\n\t10 - Filtrar contatos por CEP";
                cout << "\n\t11 - Filtrar contatos por idade";
                cout << "\n\t12 - Editar contato";
                cout << "\n\t13 - Sair";
                cout << "\n\nOpção: ";
                cin >> choice;
                break;
            case 1:
                loop = false;
                break;
            case 2:
                for(i=0; i < TAM; i++){
                    cout << "\n\nContato " << i+1;
                    cout << "\n---------------------";
                    cout << "\nNome: " << agenda[i].nome;
                    cout << "\nEmail: " << agenda[i].email;
                    cout << "\nIdade: " << agenda[i].idade;
                    cout << "\nDDD: " << agenda[i].ddd;
                    cout << "\nCelular: " << agenda[i].celular;
                    cout << "\nCidade: " << agenda[i].cidade;
                    cout << "\nEstado: " << agenda[i].estado;
                    cout << "\nPais: " << agenda[i].pais;
                    cout << "\nEndereco: " << agenda[i].endereco;
                    cout << "\nBairro: " << agenda[i].bairro;
                    cout << "\nCEP: " << agenda[i].cep;
                    cout << "\n---------------------";
                    cout << "\n\n";
                }
                choice = 0; // Voltar para o menu
                break;

                case 3:
                cout << "\nDigite o nome do contato: ";
                cin >> nome;
                
                for(i=0; i < TAM; i++){
                    if(agenda[i].nome == nome){
                        cout << "\n\nContato " << i+1;
                        cout << "\n---------------------";
                        cout << "\nNome: " << agenda[i].nome;
                        cout << "\nEmail: " << agenda[i].email;
                        cout << "\nIdade: " << agenda[i].idade;
                        cout << "\nDDD: " << agenda[i].ddd;
                        cout << "\nCelular: " << agenda[i].celular;
                        cout << "\nCidade: " << agenda[i].cidade;
                        cout << "\nEstado: " << agenda[i].estado;
                        cout << "\nPais: " << agenda[i].pais;
                        cout << "\nEndereco: " << agenda[i].endereco;
                        cout << "\nBairro: " << agenda[i].bairro;
                        cout << "\nCEP: " << agenda[i].cep;
                        cout << "\n---------------------";
                    }
                }
                choice = 0; // Voltar para o menu
                break;

            case 4:
                cout << "\nDigite o email do contato: ";
                cin >> email;
                
                for(i=0; i < TAM; i++){
                    if(agenda[i].email == email){
                        cout << "\n\nContato " << i+1;
                        cout << "\n---------------------";
                        cout << "\nNome: " << agenda[i].nome;
                        cout << "\nEmail: " << agenda[i].email;
                        cout << "\nIdade: " << agenda[i].idade;
                        cout << "\nDDD: " << agenda[i].ddd;
                        cout << "\nCelular: " << agenda[i].celular;
                        cout << "\nCidade: " << agenda[i].cidade;
                        cout << "\nEstado: " << agenda[i].estado;
                        cout << "\nPais: " << agenda[i].pais;
                        cout << "\nEndereco: " << agenda[i].endereco;
                        cout << "\nBairro: " << agenda[i].bairro;
                        cout << "\nCEP: " << agenda[i].cep;
                        cout << "\n---------------------";
                    }
                }
                choice = 0; // Voltar para o menu
                break;

            case 5:
                cout << "\nDigite o celular do contato: ";
                cin >> celular;
                
                for(i=0; i < TAM; i++){
                    if(agenda[i].celular == celular){
                        cout << "\n\nContato " << i+1;
                        cout << "\n---------------------";
                        cout << "\nNome: " << agenda[i].nome;
                        cout << "\nEmail: " << agenda[i].email;
                        cout << "\nIdade: " << agenda[i].idade;
                        cout << "\nDDD: " << agenda[i].ddd;
                        cout << "\nCelular: " << agenda[i].celular;
                        cout << "\nCidade: " << agenda[i].cidade;
                        cout << "\nEstado: " << agenda[i].estado;
                        cout << "\nPais: " << agenda[i].pais;
                        cout << "\nEndereco: " << agenda[i].endereco;
                        cout << "\nBairro: " << agenda[i].bairro;
                        cout << "\nCEP: " << agenda[i].cep;
                        cout << "\n---------------------";
                    }
                }
                choice = 0; // Voltar para o menu
                break;

            case 6:
                cout << "\nDigite a cidade do contato: ";
                cin >> cidade;
                
                for(i=0; i < TAM; i++){
                    if(agenda[i].cidade == cidade){
                        cout << "\n\nContato " << i+1;
                        cout << "\n---------------------";
                        cout << "\nNome: " << agenda[i].nome;
                        cout << "\nEmail: " << agenda[i].email;
                        cout << "\nIdade: " << agenda[i].idade;
                        cout << "\nDDD: " << agenda[i].ddd;
                        cout << "\nCelular: " << agenda[i].celular;
                        cout << "\nCidade: " << agenda[i].cidade;
                        cout << "\nEstado: " << agenda[i].estado;
                        cout << "\nPais: " << agenda[i].pais;
                        cout << "\nEndereco: " << agenda[i].endereco;
                        cout << "\nBairro: " << agenda[i].bairro;
                        cout << "\nCEP: " << agenda[i].cep;
                        cout << "\n---------------------";
                    }
                }
                choice = 0; // Voltar para o menu
                break;

            case 7:
                cout << "\nDigite o estado do contato: ";
                cin >> estado;
                
                for(i=0; i < TAM; i++){
                    if(agenda[i].estado == estado){
                        cout << "\n\nContato " << i+1;
                        cout << "\n---------------------";
                        cout << "\nNome: " << agenda[i].nome;
                        cout << "\nEmail: " << agenda[i].email;
                        cout << "\nIdade: " << agenda[i].idade;
                        cout << "\nDDD: " << agenda[i].ddd;
                        cout << "\nCelular: " << agenda[i].celular;
                        cout << "\nCidade: " << agenda[i].cidade;
                        cout << "\nEstado: " << agenda[i].estado;
                        cout << "\nPais: " << agenda[i].pais;
                        cout << "\nEndereco: " << agenda[i].endereco;
                        cout << "\nBairro: " << agenda[i].bairro;
                        cout << "\nCEP: " << agenda[i].cep;
                        cout << "\n---------------------";
                    }
                }
                choice = 0; // Voltar para o menu
                break;

            case 8:
                cout << "\nDigite o pais do contato: ";
                cin >> pais;
                
                for(i=0; i < TAM; i++){
                    if(agenda[i].pais == pais){
                        cout << "\n\nContato " << i+1;
                        cout << "\n---------------------";
                        cout << "\nNome: " << agenda[i].nome;
                        cout << "\nEmail: " << agenda[i].email;
                        cout << "\nIdade: " << agenda[i].idade;
                        cout << "\nDDD: " << agenda[i].ddd;
                        cout << "\nCelular: " << agenda[i].celular;
                        cout << "\nCidade: " << agenda[i].cidade;
                        cout << "\nEstado: " << agenda[i].estado;
                        cout << "\nPais: " << agenda[i].pais;
                        cout << "\nEndereco: " << agenda[i].endereco;
                        cout << "\nBairro: " << agenda[i].bairro;
                        cout << "\nCEP: " << agenda[i].cep;
                        cout << "\n---------------------";
                    }
                }
                choice = 0; // Voltar para o menu
                break;

            case 9:
                cout << "\nDigite o bairro do contato: ";
                cin >> bairro;
                
                for(i=0; i < TAM; i++){
                    if(agenda[i].bairro == bairro){
                        cout << "\n\nContato " << i+1;
                        cout << "\n---------------------";
                        cout << "\nNome: " << agenda[i].nome;
                        cout << "\nEmail: " << agenda[i].email;
                        cout << "\nIdade: " << agenda[i].idade;
                        cout << "\nDDD: " << agenda[i].ddd;
                        cout << "\nCelular: " << agenda[i].celular;
                        cout << "\nCidade: " << agenda[i].cidade;
                        cout << "\nEstado: " << agenda[i].estado;
                        cout << "\nPais: " << agenda[i].pais;
                        cout << "\nEndereco: " << agenda[i].endereco;
                        cout << "\nBairro: " << agenda[i].bairro;
                        cout << "\nCEP: " << agenda[i].cep;
                        cout << "\n---------------------";
                    }
                }
                choice = 0; // Voltar para o menu
                break;

            case 10:
                cout << "\nDigite o CEP do contato: ";
                cin >> cep;
                
                for(i=0; i < TAM; i++){
                    if(agenda[i].cep == cep){
                        cout << "\n\nContato " << i+1;
                        cout << "\n---------------------";
                        cout << "\nNome: " << agenda[i].nome;
                        cout << "\nEmail: " << agenda[i].email;
                        cout << "\nIdade: " << agenda[i].idade;
                        cout << "\nDDD: " << agenda[i].ddd;
                        cout << "\nCelular: " << agenda[i].celular;
                        cout << "\nCidade: " << agenda[i].cidade;
                        cout << "\nEstado: " << agenda[i].estado;
                        cout << "\nPais: " << agenda[i].pais;
                        cout << "\nEndereco: " << agenda[i].endereco;
                        cout << "\nBairro: " << agenda[i].bairro;
                        cout << "\nCEP: " << agenda[i].cep;
                        cout << "\n---------------------";
                    }
                }
                choice = 0; // Voltar para o menu
                break;

            case 11:
                cout << "\nDigite a idade do contato: ";
                cin >> idade;
                
                for(i=0; i < TAM; i++){
                    if(agenda[i].idade == idade){
                        cout << "\n\nContato " << i+1;
                        cout << "\n---------------------";
                        cout << "\nNome: " << agenda[i].nome;
                        cout << "\nEmail: " << agenda[i].email;
                        cout << "\nIdade: " << agenda[i].idade;
                        cout << "\nDDD: " << agenda[i].ddd;
                        cout << "\nCelular: " << agenda[i].celular;
                        cout << "\nCidade: " << agenda[i].cidade;
                        cout << "\nEstado: " << agenda[i].estado;
                        cout << "\nPais: " << agenda[i].pais;
                        cout << "\nEndereco: " << agenda[i].endereco;
                        cout << "\nBairro: " << agenda[i].bairro;
                        cout << "\nCEP: " << agenda[i].cep;
                        cout << "\n---------------------";
                    }
                }
                choice = 0; // Voltar para o menu
                break;

            case 12:
            



            case 13:
                loop = false;
                break;

            default:
                cout << "\nOpção inválida!";
                choice = 0; // Voltar para o menu
                break;
        }
    }

    ofstream arquivo1 ("agenda.txt");

    if(!arquivo1.is_open()){
        cout<<"\nErro: Arquivo não encontrado.\n";
        return 1;
    }

    cout << "Gostaria de salvar as alterações? (S/N): ";
    string resposta;
    cin >> resposta;
    if(resposta == "S" || resposta == "s"){
        for(i = 0; i < TAM; i++){
            arquivo1 << agenda[i].nome << " ";
            arquivo1 << agenda[i].email << " ";
            arquivo1 << agenda[i].idade << " ";
            arquivo1 << agenda[i].ddd << " ";
            arquivo1 << agenda[i].celular << " ";
            arquivo1 << agenda[i].cidade << " ";
            arquivo1 << agenda[i].estado << " ";
            arquivo1 << agenda[i].pais << " ";
            arquivo1 << agenda[i].endereco << " ";
            arquivo1 << agenda[i].bairro << " ";
            arquivo1 << agenda[i].cep << endl; 
        }

        cout << "\n\nAlterações salvas com sucesso!\n";

    }else{
        cout << "\n\nAlterações não salvas!\n";
    }
    
    arquivo1.close();
    
    cout << "\n\nADEUS\n\n";

    return 0;
}