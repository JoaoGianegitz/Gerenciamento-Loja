#include <iostream>
#include <string.h>
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
    char telefone[13];
};

struct Vendedores{
    int cod;
    char nome[30];
    char telefone[13];
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
void menuPrincipal(){
    int opcao;
    do {
        cout << "\tMENU PRINCIPAL\t" << endl;
        cout << "\n1 - Categorias";
        cout << "\n2 - Produtos";
        cout << "\n3 - Clientes";
        cout << "\n4 - Vendedores";
        cout << "\n5 - Vendas";
        cout << "\n6 - Relatorios";
        cout << "\n0 - Sair";
        
        cin >> opcao;

        switch(opcao) {
            case 1:
                menuCategorias();
                break;

            case 2:
                menuProdutos();
                break;

            case 3:
                menuClientes();
                break;

            case 4:
                menuVendedores();
                break;

            case 5:
                menuVendas();
                break;
        }

    }while(op != 0);
}

void menuCategorias(){}

void menu(){
        cout << "\n====================Menu==================\n" << endl;
        cout << "1- Leitura de Categorias" << endl;
        cout << "2 - Leitura de Produtos" << endl;
        cout << "3- Inclusao de Cliente" << endl;
        cout << "4 - Inclusao de Vendedor" << endl;
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
/*    int cod;
    char nome[30];
    char endereco[30];
    int telefone;
void lerCliente(struct Cliente x[]){
    
}

void lerVendedor(struct Vendedor x[])
{

}
*/
void lerCliente(struct Clientes x[], int &cont){
    char conf;
    int cadastrar=0;
    Clientes aux[];
    cout << "Deseja cadastrar quantos clientes: " << endl;
    cin >> cadastrar;
    for(int i=0; i<cadastrar;i++){

        cout << "\tCADASTRO DE CLIENTES\t" << endl;
        cout << "Posicao: " << cont+1 << endl;
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
    /*
    do {
        if(cont>=TAM){
            cout << "Limite Atingido";
            break;
        }
        cout << "\tCADASTRO DE CLIENTES\t" << endl;
        cout << "Posicao: " << i+1 << endl;
        cout << "Digite codigo do cliente: " << endl;
        cin >> x[cont].cod;
        cout << "Digite nome do cliente: " << endl;
        cin.ignore();
        cin.getline(x[cont].nome, 30);
        cout << "Digite endereco do cliente: " << endl;
        cin.ignore();
        cin.getline(x[cont].endereco, 30);
        cout << "Digite telefone do cliente: " << endl;
        cin.ignore();
        cin.getline(x[cont].telefone, 15);
        cout << "Voce confirma as informacoes: (Y ou N)" << endl;
        cin >> conf; 
        if (conf == 'N' || conf == 'n') {
            cout << "Operacao Finalizada" << endl;
            break;
        cont++;

    } while (cadastrar!=0);
}*/
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

void inclusao_cliente(struct Clientes x[], int contX, struct Clientes s[], int contS, struct Clientes a[], int &contA){
    int i=0, j=0, k=0; // i (CONTADOR DE X) | j (CONTADOR DE S) | k (CONTADOR DE A)
    for(;i<contX && j< contS; k++){
        if(x[i].cod < s[j].cod){
            a[k].cod=x[i].cod;
            strcpy(a[k].nome, x[i].nome);
            strcpy(a[k].endereco, x[i].endereco);
            strcpy(a[k].telefone, x[i].telefone);
            i++;
        }
        else{
            a[k].cod=s[j].cod;
            strcpy(a[k].nome, s[j].nome);
            strcpy(a[k].endereco, s[j].endereco);
            strcpy(a[k].telefone, s[j].telefone);
            j++; 
        }
    }
    while(i<contX){
        a[k].cod=x[i].cod;
        strcpy(a[k].nome, x[i].nome);
        strcpy(a[k].endereco, x[i].endereco);
        strcpy(a[k].telefone, x[i].telefone);
        i++;
        k++;
    }
    while(j<contS){
        a[k].cod= s[j].cod;
        strcpy(a[k].nome, s[j].nome);
        strcpy(a[k].endereco, s[j].endereco);
        strcpy(a[k].telefone, s[j].telefone);
        k++;
        j++;
    }
    contA=k;
}

void inclusao_vendedor(struct Vendedores x[], int contX, struct Vendedores s[], int contS, struct Vendedores a[], int &contA)
{
    int i = 0, j = 0, k = 0; // i (CONTADOR DE X) | j (CONTADOR DE S) | k (CONTADOR DE A)
    for(; i < contX && j < contS; k++)
    {
        if(x[i].cod < s[j].cod)
        {
            a[k].cod = x[i].cod;
            strcpy(a[k].nome, x[i].nome);
            strcpy(a[k].telefone, x[i].telefone);
            i++;
        }
        else
        {
            a[k].cod = s[j].cod;
            strcpy(a[k].nome, s[j].nome);
            strcpy(a[k].telefone, s[j].telefone);
            j++; 
        }
        while(i < contX)
        {
            a[k].cod = x[i].cod;
            strcpy(a[k].nome, x[i].nome);
            strcpy(a[k].telefone, a[k].telefone);
            i++;
            k++;
        }
        while(j < contS)
        {
            a[k].cod = s[j].cod;
            strcpy(a[k].nome, s[j].nome);
            strcpy(a[k].telefone, s[j].telefone);
            k++;
            j++;
        }
        contA = k;
    }
}

int main(){

    Categorias cat[TAM];
    Produtos prod[TAM];
    Clientes cliente[TAM], clienteS[TAM], clienteA[TAM];
    Vendedores vendedor[TAM], vendedorS[TAM], vendedorA[TAM];


    int codPesquisa=0;
    int contCategorias=0;
    int contProdutos=0;
    int opcao;
    int contX, contS, contA;

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
                inclusao_cliente(cliente, contX, clienteS, contS, clienteA, contA);
                break;
            case 4:
                inclusao_vendedor(vendedor, contX, vendedorS, contS, vendedorA, contA);
                break;
            case 0:
                cout << "Encerrando operacao" << endl;
                break;
            default:
                cout << "Opcao invalida" << endl;
        }
    } while(opcao!=0);

}

/*fazer esquema dele nao deixar o usuario definir um estoque menor que o estoque minimo
busca client enao sei de onde tirei

            case 3:
                for(codPesquisa=TAM-1; codPesquisa !=0;){
                    cout << "Informe codigo do cliente a ser buscado: ";
                    cin >> codPesquisa;
                    if(codPesquisa!=0)
                        buscaCliente(cliente, codPesquisa);
                }
*/


/*
Fazer diferentes tipos de menu
com confirmação de leitura, possibilidade de modificação 
*/

// colocar para o usuario fazer a confirmação da inserção de dados
//leitura -> categoria -> confirmação -> modificação -> cod, nome, 