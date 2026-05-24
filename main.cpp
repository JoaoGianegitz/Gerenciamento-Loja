#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

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

void menu(){
        cout << "\n====================Menu==================\n" << endl;
        cout << "1- Leitura de Categorias" << endl;
        cout << "2 - Leitura de Produtos" << endl;
        cout << "3- Inclusao de Cliente" << endl;
        cout << "4 - Inclusao de Vendedor" << endl;
        cout << "5 - Registrar nova venda" << endl;
        cout << "0 - Sair" << endl;
}


// função de leitura das Categorias
void lerCategoria(struct Categorias x[], int &cont, int tamanhoMax){
    char conf;
    do{ 
        if(cont>=tamanhoMax){
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
void lerProduto(struct Produtos x[], int &cont, int tamanhoMax){
    char conf;
    do{
        if(cont>=tamanhoMax){
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


// função verifica cliente. Ultilizamos um contador de cliente e um codigo de pesquisa, onde temos um loop que percorre toda a lista para ver se existe um codigo igual, caso existir ele vai retornar um valor booleano, que vamos usar como parametro na hora de fazer a leitura dos registros, para saber se devemos continuar fazendo a leitura ou não
bool verificaCliente(struct Clientes x[], int contCliente, int codPesquisa){
    for (int i=0; i<contCliente; i++){
    if (codPesquisa == x[i].cod) {                  //(codPesquisa == cli[i].cod){
        cout << "\n\n CLIENTE JA CADASTRADO!";
        cout << "\nCodigo do Cliente: " << x[i].cod;
        cout << "\tNome: " << x[i].nome;
        cout << "\tEndereco: " << x[i].endereco;
        cout << "\tTelefone: " << x[i].telefone << endl;

        return true;
    } 
    }
    return false;
}


// aqui na leitura de clientes
void inclusao_cliente(struct Clientes x[], int &contCliente, int tamanhoMax){
    char conf;
    int cadastrar=0;
    Clientes aux;
    cout << "Deseja cadastrar quantos clientes: " << endl;
    cin >> cadastrar;
    for(int i=0; i<cadastrar;i++){
        if(contCliente >= tamanhoMax){
            cout << "\n[ERRO] Limite de cadastros digitados (" << tamanhoMax << ")!" << endl;
            break;
        }

        cout << "\tCADASTRO DE CLIENTES\t" << endl;
        cout << "Posicao: " << contCliente+1 << endl;
        cout << "Digite codigo do cliente: " << endl;
        cin >> aux.cod;
        while(verificaCliente(x, contCliente, aux.cod)){ // esse while aqui é para verificar se o codigo é igual a algum da lista, caso for ele pede ao usuario digitar novamente, outro codigo, repetindo ate que digite outro codigo
            cout << "Digite outro codigo: " << endl;
            cin >> aux.cod;
        }
        cin.ignore();
        cout << "Digite nome do cliente: " << endl;
        cin.getline(aux.nome, 30);
        cout << "Digite endereco do cliente: " << endl;
        cin.getline(aux.endereco, 30);
        cout << "Digite telefone do cliente: " << endl;
        cin.getline(aux.telefone, 13);

        cout << "Confirmacao: " << endl;
        cout << "Codigo: " << aux.cod;
        cout << "| Nome: " << aux.nome;
        cout << "| Endereco: " << aux.endereco;
        cout << "| Telefone: " << aux.telefone;

        cout << "Voce confirma as informacoes: (Y ou N)" << endl;
        cin >> conf; 

        if(conf=='y' || conf=='Y'){
            x[contCliente]=aux;
            contCliente++;
        } else cout << "Cadastro cancelado";
    }
}

bool verificaVendedor(struct Vendedores x[], int contVendedor, int codPesquisa){
    for (int i=0; i<contVendedor; i++){
    if (codPesquisa == x[i].cod) {                  //(codPesquisa == cli[i].cod){
        cout << "\n\n VENDEDOR JA CADASTRADO!";
        cout << "\nCodigo do VENDEDOR: " << x[i].cod;
        cout << "\tNome: " << x[i].nome;
        cout << "\tTelefone: " << x[i].telefone << endl;

        return true;
    } 
    }
    return false;
}


void inclusao_vendedor(struct Vendedores x[], int &contVendedor, int tamanhoMax){
    char conf;
    int cadastrar=0;
    Vendedores aux;
    cout << "Deseja cadastrar quantos Vendedores: " << endl;
    cin >> cadastrar;
    for(int i=0; i<cadastrar;i++){
        if(contVendedor >= tamanhoMax){
            cout << "\n[ERRO] Limite de cadastros digitados (" << tamanhoMax << ")!" << endl;
            break;
        }

        cout << "\tCADASTRO DE VENDEDORES\t" << endl;
        cout << "Posicao: " << contVendedor+1 << endl;
        cout << "Digite codigo do vendedor: " << endl;
        cin >> aux.cod;
        while(verificaVendedor(x, contVendedor, aux.cod)){ 
            cout << "Digite outro codigo: " << endl;
            cin >> aux.cod;
        }
        cin.ignore();
        cout << "Digite nome do Vendedor: " << endl;
        cin.getline(aux.nome, 30);
        cout << "Digite telefone do Vendedor: " << endl;
        cin.getline(aux.telefone, 13);

        cout << "Confirmacao: " << endl;
        cout << "Codigo: " << aux.cod;
        cout << "| Nome: " << aux.nome;
        cout << "| Telefone: " << aux.telefone;

        cout << "Voce confirma as informacoes: (Y ou N)" << endl;
        cin >> conf; 

        if(conf=='y' || conf=='Y'){
            x[contVendedor]=aux;
            contVendedor++;
        } else cout << "Cadastro cancelado";
    }
}

void buscaCliente(struct Clientes cli[], int contCliente){
    int codPesquisa=0;
    cout << "Digite codigo do cliente que esta buscando: " << endl;
    cin >> codPesquisa;
    int i=0;
    for (; i<contCliente && cli[i].cod != codPesquisa; i++){
    }
    if (i < contCliente) {                  //(codPesquisa == cli[i].cod){
        cout << "\n\n Cliente Encontrado";
        cout << "\nCodigo do Cliente: " << cli[i].cod;
        cout << "\tNome: " << cli[i].nome;
        cout << "\tEndereco: " << cli[i].endereco;
        cout << "\tTelefone: " << cli[i].telefone;
    } else 
        cout << "\n\n Cliente nao encontrado";
    getch();

}


bool imprimirCliente(struct Clientes x[], int contCliente, int codCliente){
    for(int i=0; i<contCliente; i++){
        if (codCliente == x[i].cod) {                
            cout << "\nCLIENTE!";
            cout << "\nCodigo do Cliente: " << x[i].cod;
            cout << "\tNome: " << x[i].nome;
            cout << "\tEndereco: " << x[i].endereco;
            cout << "\tTelefone: " << x[i].telefone << endl;

            return true;
        }
    }
    cout << "Cliente nao cadastrado" << endl;
    return false; 
}

bool imprimirVendedor(struct Vendedores x[], int contVendedor, int codVendedor){
    for(int i=0; i<contVendedor; i++){
        if (codVendedor == x[i].cod) {                
            cout << "\nVENDEDOR!";
            cout << "\nCodigo do Vendedor: " << x[i].cod;
            cout << "\tNome: " << x[i].nome;
            cout << "\tTelefone: " << x[i].telefone << endl;

            return true;
        }
    }
    cout << "Vendedor nao cadastrado" << endl;
    return false; 
}

void lancar_produtos(struct ItensVenda itens[], int &contItens, int codVenda){
    ItensVenda aux_itens;
    char conf;
    char confirmacao;
    do {

    aux_itens.codVenda=codVenda;

    cout << "Digite Codigo do produto: " << endl; 
    cin >> aux_itens.codProd;
    cout << "Digite quantidade: " << endl;
    cin >> aux_itens.quant;
    cout << "\nCodigo do Produto: " << aux_itens.codProd;
    cout << "\nQuantidade de Produtos: " << aux_itens.quant;
    cout << "Voce confirma as informacoes: (Y ou N)" << endl;
    cin >> conf; 

    if (conf=='y' || conf=='Y'){
        itens[contItens]=aux_itens;
        cout << "Informacoes Confirmadas" << endl;
        contItens++;
    } 
    else cout << "Lancamento nao confirmado" << endl;

    cout << "Deseja cadastrar mais algum item? (Y/N): ";
    cin >> confirmacao;

    } while(confirmacao == 'y' || confirmacao == 'Y');
}

// função registrar venda, usamos como parametro as 3 structs junto a seus contadores, e chamamos outras 2 funções diferentes para imprimir cliente e vendedor com seus dados. 
// dentro da função registrar venda para poder fazer o lançamento das vendas, ou seja ele envvia como paramatro para função de lancar produtos o vetor de itens, contador de itens e o codigo da venda que é usado como parametro, e na função de lançar a venda ele vincula a chave primária a chave estrangeira, entrando assim em um loop para lançar quantos produtos desejar
void registrar_venda(struct Vendas x[], int &contVendas, int tamanhoMax, struct Clientes cliente[], int &contCliente, struct Vendedores vendedor[], int &contVendedores, struct ItensVenda itens[], int &contItens){
    char conf;
    Vendas aux;

    if(contVendas >= tamanhoMax){
        cout << "\n[ERRO] Limite de cadastros digitados (" << tamanhoMax << ")!" << endl;
        return;
    }
    cout << "\nLANCAMENTO DE VENDAS\t" << endl;
    cout << "Posicao: " << contVendas+1 << endl;
    cout << "Digite codigo da venda: " << endl;
    cin >> aux.cod;
    lancar_produtos(itens, contItens, aux.cod);
    cout << "Digite codigo do cliente: " << endl;
    cin >> aux.codCliente;
    imprimirCliente(cliente, contCliente, aux.codCliente);
    cout << "Digite codigo do Vendedor: " << endl;
     cin >> aux.codVendedor;
    imprimirVendedor(vendedor, contVendedores, aux.codVendedor);

    cout << "Digite data da venda" << endl;
    cin.ignore();
    cin.getline(aux.data, 10);

    cout << "Confirmacao: " << endl;
    cout << "\nCodigo da venda: " << aux.cod;
    cout << "\tCodigo do Cliente: " << aux.codCliente;
    cout << "\tCodigo do Vendedor: " << aux.codVendedor;
    cout << "\tData da venda: " << aux.data << endl;

    cout << "Voce confirma as informacoes: (Y ou N)" << endl;
    cin >> conf; 

    if(conf=='y' || conf=='Y'){
        x[contVendas]=aux;
        contVendas++;
    } else cout << "Cadastro cancelado";

}

int main(){

    Categorias cat[100];
    Produtos prod[100];
    Clientes cliente[100];
    Vendedores vendedor[100];
    Vendas vendas[100];
    ItensVenda itens_venda[100];

    int codPesquisa=0;
    int contCategorias=0;
    int contProdutos=0;
    int contClientes=0;
    int contVendedores=0;
    int contVendas=0;
    int contItens=0;
    int opcao;

    do {
        menu();
        cout << "Faca sua escolha: " << endl;
        cin >> opcao;
        switch(opcao) {
            case 1:
                lerCategoria(cat, contCategorias, 100); // LEITURA DE CATEGORIA
                break;
            case 2:
                lerProduto(prod, contProdutos, 100); // LEITURA DE PRODUTOS
                break;
            case 3:
                inclusao_cliente(cliente, contClientes, 100);
                break;
            case 4:
                inclusao_vendedor(vendedor, contVendedores, 100);
                break;
            case 5:
                registrar_venda(vendas, contVendas, 100, cliente, contClientes, vendedor, contVendedores, itens_venda, contItens);
                break;
            case 0:
                cout << "Encerrando operacao" << endl;
                break;
            default:
                cout << "Opcao invalida" << endl;
        }
    } while(opcao!=0);

}
/*
Vinicius eu implementei uma função para fazer a leitura dos clientes, e uma para verificar se existe o codigo que o usuario está digitnado na lista
replique isso para a função dos vendedores tbm, entenda o codigo!!!
*/