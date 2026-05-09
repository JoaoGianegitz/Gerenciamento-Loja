#include <iostream>
#include <string>

using namespace std;

#define TAM 10


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

int lerCategoria(struct Categorias x[]){
    int i=0;
    char conf;
    do{
        if(i>=TAM){
            cout << "Limite Atingido" << endl;
            break;
        }    
        cout << "\nCADASTRO DE CATEGORIAS\n" << endl;
        cout << "Digite codigo: " << endl;
        cin >> x[i].cod;
        cin.ignore();
        cout << "Digite descricao: " << endl;
        cin.getline(x[i].desc, 60);
        i++;

        cout << "Deseja cadastrar outra categoria: (s ou S)" << endl;
        cin >> conf; 
        } while (conf=='s' || conf =='S');
    return i;
}

int lerProduto(struct Produtos x[]){
    int i=0;
    char conf;
    do{
        if(i>=TAM){
            cout << "Limite Atingido" << endl;
            break;
        }
        cout << "\nCADASTRO DE PRODUTOS\n" << endl;
        cout << "Digite codigo: " << endl;
        cin >> x[i].cod;
        cout << "Digite codigo de categoria: " << endl;
        cin >> x[i].codCategoria;
        cout << "Digite descricao: " << endl;
        cin.ignore();
        cin.getline(x[i].desc, 60);
        cout << "Digite Estoque Maximo: " << endl;
        cin >> x[i].estoqueMax;
        cout << "Digite Estoque Minimo: " << endl;
        cin >> x[i].estoqueMin;
        cout << "Digite preco unitario: " << endl;
        cin >> x[i].precoUnit;
        cout << "Digite quantidade de Estoque: " << endl;
        cin >> x[i].quantEstoque;
        i++;

        cout << "Deseja cadastrar outro produto: (s ou S)" << endl;
        cin >> conf; 
    }while (conf=='s' || conf =='S');
    return i;   
}

void inserir_cliente(struct Clientes x[], int contX){
    int i=0;
    while(i<=)

}





int main(){

}