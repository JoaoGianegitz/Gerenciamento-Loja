#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

#define TAM 10

// Iinicio da definição da estrutura de dados
struct Categorias{
    int cod;
    char desc[60];
};

struct Produtos{
    int cod;
    char desc[60];
    int codCategoria;
    int quantEstoque;
    int estoqueMin;
    int estoqueMax;
    float precoUnit;
};

struct Clientes{
    int cod;
    char nome[30];
    char endereco[30];
    int telefone;
};

struct Vendedores{
    int cod;
    char nome[30];
    int telefone;
};

struct Vendas{
    int cod;
    int codCliente;
    int codVendedor;
    char data[10];
};

struct ItensVenda{
    int codVenda;
    int codProd;
    int quant;
};  
// fim da estrutura de dados

// função menu
void menu(){
        cout << "\n====================Menu==================\n" << endl;
        cout << "1- Leitura de Categorias" << endl;
        cout << "2 - Leitura de Produtos" << endl;
        cout << "3- Buscar Cliente" << endl;
        cout << "4 - " << endl;
        cout << "5 - Sair" << endl;
}


// função de leitura das Categorias
void lerCategoria(struct Categorias x[], int &cont){
    char conf;
    do{
        if(cont>=TAM){
            cout << "Limite Atingido" << endl;
            break;
        }    
        cout << "\nCADASTRO DE CATEGORIAS\n" << endl;
        cout << "Digite codigo: " << cont+1 << endl;
        cin >> x[cont].cod;
        cin.ignore();
        cout << "Digite descricao: " << cont+1 << endl;
        cin.getline(x[cont].desc, 60);
        cont++;

        cout << "Deseja cadastrar outro categoria: (Y ou N)" << endl;
        cin >> conf; 
        if (conf == 'N' || conf == 'n') {
            cout << "Operacao Finalizada" << endl;
            break;
        }
    }while (conf=='Y' || conf =='y');
}

// função de leitura de produtos
void lerProduto(struct Produtos x[], int &cont){
    char conf;
    do{
        if(cont>=TAM){
            cout << "Limite Atingido" << endl;
            break;
        }
        cout << "\nCADASTRO DE PRODUTOS\n" << endl;
        cout << "Digite codigo: " << cont+1 << endl;
        cin >> x[cont].cod;
        cout << "Digite codigo de categoria: " << cont+1 << endl;
        cin >> x[cont].codCategoria;
        cout << "Digite descricao: " << cont+1 << endl;
        cin.ignore();
        cin.getline(x[cont].desc, 60);
        cout << "Digite Estoque Maximo: " << cont+1 << endl;
        cin >> x[cont].estoqueMax;
        cout << "Digite Estoque Minimo: " << cont+1 << endl;
        cin >> x[cont].estoqueMin;
        cout << "Digite preco unitario: " << cont+1 << endl;
        cin >> x[cont].precoUnit;
        cout << "Digite quantidade de Estoque: " << cont+1 << endl;
        cin >> x[cont].quantEstoque;
        cont++;

        cout << "Deseja cadastrar outro produto: (Y ou N)" << endl;
        cin >> conf; 
        if (conf == 'N' || conf == 'n') {
            cout << "Operacao Finalizada" << endl;
            break;
        }
    }while (conf=='Y' || conf =='y');
}

void buscaCliente(struct Clientes cli[], int cod){
    int i=0, f=TAM-1;
    int m=(i+f) / 2;
    for (;f>=i && cod != cli[m].cod; m=(i+f) / 2){
        if(cod>cli[m].cod){
            i=m+1; }
        else
            f=m-1;
        
    if (cod == cli[m].cod){
        cout << "\n\n Cliente Encontrado";
        cout << "\nCodigo do Cliente: " << cli[m].cod;
        cout << "\tNome: " << cli[m].nome;
        cout << "\tEndereco: " << cli[m].endereco;
        cout << "\tTelefone: " << cli[m].telefone;
    } else 
        cout << "\n\n Cliente nao encontrado";
    getch();
    }
}

int main(){

    Categorias cat[TAM];

    Produtos prod[TAM];

    Clientes cliente[TAM];

    int codPesquisa=0;
    int contCategorias=0;
    int contProdutos=0;
    int opcao;

    do {
        menu();
        cout << "Faca sua escolha" << endl;
        cin >> opcao;
        switch(opcao) {
            case 1:
                lerCategoria(cat, contCategorias);
                break;
            case 2:
                lerProduto(prod, contProdutos);
                break;
            case 3:
                for(codPesquisa=TAM-1; codPesquisa !=0;){
                    cout << "Informe codigo do cliente a ser buscado: ";
                    cin >> codPesquisa;
                    if(codPesquisa!=0)
                        buscaCliente(cliente, codPesquisa);
                }
            case 4:

            case 5:
                cout << "Encerrando operacao" << endl;
                break;
            default:
                cout << "Opcao invalida" << endl;
        }
    } while(opcao!=5);

}

/*fazer esquema dele nao deixar o usuario definir um estoque menor que o estoque minimo
*/