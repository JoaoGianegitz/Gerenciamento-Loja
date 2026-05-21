#include <iostream>
#include <string.h>

using namespace std;

struct Clientes{
    int cod;
    char nome[30];
    char endereco[30];
    char telefone[13];
};

void lerCliente(struct Clientes x[], int &cont){
    char conf;
    int cadastrar=0;
    Clientes aux[];
    cout << "Deseja cadastrar quantos clientes: " << endl;
    cin >> cadastrar;
    for(int i=0; i<cadastrar;i++){

        cout << "\tCADASTRO DE CLIENTES\t" << endl;
        cout << "Posicao: " << i+1 << endl;
        cout << "Digite codigo do cliente: " << endl;
        cin >> aux.cod;
        cin.ignore(); 
        cout << "Digite nome do cliente: " << endl;
        cin.getline(aux.nome, 30);
        cin.ignore();
        cout << "Digite endereco do cliente: " << endl;
        cin.getline(aux.endereco, 30);
        cin.ignore();
        cout << "Digite telefone do cliente: " << endl;
        cin.getline(aux.telefone, 15);

        cout << "Confirmacao: " << endl;
        cout << "Codigo: " << aux.cod;
        cout << "| Nome: " << aux.nome;
        cout << "| Endereco: " << aux.endereco;
        cout << "| Telefone: " << aux.telefone;

        cout << "Voce confirma as informacoes: (Y ou N)" << endl;
        cin >> conf; 

        if(conf=='y' || conf=='Y'){
            x[cont]=aux;
            cont++;
        } else cout << "Cadastro cancelado";
    }

}

int main(){
    Clientes cli[100];
    int cont;
    lerCliente(cli, cont)
}


struct Vendas{
    int cod;
    int codCliente;
    int codVendedor;
    char data[10];
};
