#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

// Inicio da definição da estrutura de dados
struct Categorias{
    int cod;
    char desc[60];

    void imprimir(){
        cout << "Codigo: " << cod << endl;
        cout << "Descricao: " << desc << endl;
    }
};

struct Produtos{
    int cod;
    char desc[60];
    int codCategoria;
    int quantEstoque;
    int estoqueMin;
    int estoqueMax;
    float precoUnit;
    
    void imprimir(){
        cout << "Codigo: " << cod << endl;
        cout << "Descricao: " << desc << endl;
        cout << "Codigo da Categoria: " << codCategoria << endl;
        cout << "Quantidade em Estoque: " << quantEstoque << endl;
        cout << "Estoque Minimo: " << estoqueMin << endl;
        cout << "Estoque Maximo: " << estoqueMax << endl;
        cout << "Preco Unitario: " << precoUnit << endl;
    }
};

struct Clientes{
    int cod;
    char nome[30];
    char endereco[30];
    char telefone[13];

    void imprimir(){
        cout << "Codigo: " << cod << endl;
        cout << "Nome: " << nome << endl;
        cout << "Endereco: " << endereco << endl;
        cout << "Telefone: " << telefone << endl;
    }
};

struct Vendedores{
    int cod;
    char nome[30];
    char telefone[13];

    void imprimir(){
        cout << "Codigo: " << cod << endl;
        cout << "Nome: " << nome << endl;
        cout << "Telefone: " << telefone << endl;
    }
};

struct Vendas{
    int cod;
    int codCliente;
    int codVendedor;
    char data[12];

    void imprimir(){
        cout << "Codigo da Venda: " << cod << endl;
        cout << "Codigo do Cliente: " << codCliente << endl;
        cout << "Codigo do Vendedor: " << codVendedor << endl;
        cout << "Data: " << data << endl;
    }
};

struct ItensVenda{
    int codVenda;
    int codProd;
    int quant;

    void imprimir(){
        cout << "Codigo da Venda: " << codVenda << endl;
        cout << "Codigo do Produto: " << codProd << endl;
        cout << "Quantidade: " << quant << endl;
    }
};  

char verificar(){
    char opcao;
    cout << "Deseja continuar cadastrando? S | N " << endl;
    cin >> opcao;
    return opcao;
}

char confirmarInfo(){
    char opcao;
    cout << "Voce Confirma as informacoes? S | N " << endl;
    cin >> opcao;
    return opcao;
}

void menu(){
        cout << "\n\t =====================================================";
        cout << "\n\t\t             ==== MENU ====";
        cout << "\n\t =====================================================";
        cout << "\n\t\t1- Leitura de Nova Categoria" << endl;
        cout << "\n\t\t2 - Leitura de Novo Produto" << endl;
        cout << "\n\t\t3 - Leitura de Novo Cliente" << endl;
        cout << "\n\t\t4 - Leitura de Novo Vendedor" << endl;
        cout << "\n\t\t5 - Nova Venda" << endl;
        cout << "\n\t\t6 - Inclusao de itens na venda" << endl;
        cout << "\n\t\t7 - Consulta de Produtos" << endl;
        cout << "\n\t\t8 - Consulta de Produtos com Estoque Baixo" << endl;
        cout << "\n\t\t9 - Consulta o Total Arrecadado com as Vendas" << endl;
        cout << "\n\t\t10 - Excluir Cliente" << endl;
        cout << "\n\t\t0 - Sair" << endl;
}

bool BuscarCategoria(struct Categorias x[], int codPesquisa, int contCategoria)
{
    int ini = 0;
    int fim = contCategoria - 1;
    int m;
    while(ini <= fim)
    {
        m = (ini + fim) / 2;
        if (codPesquisa == x[m].cod)
        {
            return true;
        }
        else if(codPesquisa < x[m].cod)
        {
            fim = m - 1;
        }
        else
        {
            ini = m + 1;
        }
    }
    return false;
}

bool BuscarProdutos(struct Produtos x[], int codPesquisa, int contProdutos)
{
    int ini = 0;
    int fim = contProdutos - 1;
    int m;
    while(ini <= fim)
    {
        m = (ini + fim) / 2;
        if (codPesquisa == x[m].cod)
        {
            return true;
        }
        else if(codPesquisa < x[m].cod)
        {
            fim = m - 1;
        }
        else
        {
            ini = m + 1;
        }
    }
    return false;
}

int BuscarPosProdutos(struct Produtos x[], int codPesquisa, int contProdutos)
{
    int ini = 0;
    int fim = contProdutos - 1;
    int m;
    while(ini <= fim)
    {
        m = (ini + fim) / 2;
        if (codPesquisa == x[m].cod)
        {
            return m;
        }
        else if(codPesquisa < x[m].cod)
        {
            fim = m - 1;
        }
        else
        {
            ini = m + 1;
        }
    }
    return -1;
}

bool BuscarClientes(struct Clientes x[], int codPesquisa, int contClientes)
{
    int ini = 0;
    int fim = contClientes - 1;
    int m;
    while(ini <= fim)
    {
        m = (ini + fim) / 2;
        if (codPesquisa == x[m].cod)
        {
            return true;
        }
        else if(codPesquisa < x[m].cod)
        {
            fim = m - 1;
        }
        else
        {
            ini = m + 1;
        }
    }
    return false;
}

int BuscarPosCliente(struct Clientes x[], int codPesquisa, int contClientes)
{
    int ini = 0;
    int fim = contClientes - 1;
    int m;
    while(ini <= fim)
    {
        m = (ini + fim) / 2;
        if (codPesquisa == x[m].cod)
        {
            return m;
        }
        else if(codPesquisa < x[m].cod)
        {
            fim = m - 1;
        }
        else
        {
            ini = m + 1;
        }
    }
    return -1;
}

int BuscarPosVendedor(struct Vendedores x[], int codPesquisa, int contVendedor)
{
    int ini = 0;
    int fim = contVendedor - 1;
    int m;
    while(ini <= fim)
    {
        m = (ini + fim) / 2;
        if (codPesquisa == x[m].cod)
        {
            return m;
        }
        else if(codPesquisa < x[m].cod)
        {
            fim = m - 1;
        }
        else
        {
            ini = m + 1;
        }
    }
    return -1;
}

bool BuscarVendedor(struct Vendedores x[], int codPesquisa, int contVendedor)
{
    int ini = 0;
    int fim = contVendedor - 1;
    int m;
    while(ini <= fim)
    {
        m = (ini + fim) / 2;
        if (codPesquisa == x[m].cod)
        {
            return true;
        }
        else if(codPesquisa < x[m].cod)
        {
            fim = m - 1;
        }
        else
        {
            ini = m + 1;
        }
    }
    return false;
}

bool BuscarVendas(struct Vendas x[], int codPesquisa, int contVendas)
{
    int ini = 0;
    int fim = contVendas - 1;
    int m;
    while(ini <= fim)
    {
        m = (ini + fim) / 2;
        if (codPesquisa == x[m].cod)
        {
            return true;
        }
        else if(codPesquisa < x[m].cod)
        {
            fim = m - 1;
        }
        else
        {
            ini = m + 1;
        }
    }
    return false;
}

//busca simples

bool imprimirCategoria(struct Categorias y[],int codPesquisa, int contCategoria){
    for(int i=0; i<contCategoria; i++){
        if(y[i].cod == codPesquisa){
            y[i].imprimir();
            return true;
        } 
    }
    return false;
}

void incluirCategoria(struct Categorias x[], struct Categorias CategoriaIncluir, int tamanhoMax, int contCategoria){
    struct Categorias auxiliar[tamanhoMax];
    int i=0; // contador de Cliente
    int j=0; // contador de auxiliar

    // aqui estamos fazendo a comparação de uma lista com a outra. se o codigo da lista x na pos z for menor que o cod da lista novos clientes na pos j a lista atualizada recebe x[z], pois é sequencial, se não ele recebe novosclientes[j]
    while(i<contCategoria&& x[i].cod < CategoriaIncluir.cod) // enqt ainda tem clientes, e o codigo atual for menor que o ClienteIncluir.cod
    {
        auxiliar[j] = x[i];
        i++;
        j++;
    }
    auxiliar[j] = CategoriaIncluir;
    j++;
    while(i<contCategoria){
        auxiliar[j] = x[i];
        i++;
        j++;
    }
    for(i=0;i<contCategoria+1; i++){ // devolve ao vetor principal
        x[i]=auxiliar[i];
    }
}
// função de leitura das Categorias
void lerCategoria(struct Categorias x[], int &contCategoria, int tamanhoMax){
    Categorias aux;
    char op, op1;
    do{ 
        if(contCategoria>=tamanhoMax){
            cout << "Limite Atingido" << endl;
            break;
        }    
        cout << "\nCADASTRO DE CATEGORIAS\n" << endl;
        cout << "Digite codigo: " << endl;
        cin >> aux.cod;
        while(BuscarCategoria(x, aux.cod, contCategoria)==true){ // aqui entramos em um loop ate o usuario digitar um codigo valido
            cout << "\nCATEGORIA JA CADASTRADA !!!" << endl;
            cout << "Digite outro codigo: " << endl;
            cin >> aux.cod;
        }
        cin.ignore();
        cout << "Digite descricao: " << endl;
        cin.getline(aux.desc, 60);
        system ("cls");
        aux.imprimir(); 
        op=confirmarInfo();
        if (op == 'S' || op == 's') {
            incluirCategoria(x, aux, tamanhoMax, contCategoria);
            contCategoria++;
            cout << "LISTA ATUALIZADA: " << endl;
            for(int i=0;i<contCategoria;i++){
                cout << endl;
                x[i].imprimir();
                cout << endl;
            }
        }
        op1=verificar();
    }while (op1=='S' || op1 =='s');
    getch();
}


void incluirProduto(struct Produtos x[], struct Produtos ProdutosIncluir, int tamanhoMax, int contProdutos){
    struct Produtos auxiliar[tamanhoMax];
    int i=0; // contador de Cliente
    int j=0; // contador de auxiliar

    // aqui estamos fazendo a comparação de uma lista com a outra. se o codigo da lista x na pos z for menor que o cod da lista novos clientes na pos j a lista atualizada recebe x[z], pois é sequencial, se não ele recebe novosclientes[j]
    while(i<contProdutos && x[i].cod < ProdutosIncluir.cod) // enqt ainda tem clientes, e o codigo atual for menor que o ClienteIncluir.cod
    {
        auxiliar[j] = x[i];
        i++;
        j++;
    }
    auxiliar[j] = ProdutosIncluir;
    j++;
    while(i<contProdutos){
        auxiliar[j] = x[i];
        i++;
        j++;
    }
    for(i=0;i<contProdutos+1; i++){ // devolve ao vetor principal
        x[i]=auxiliar[i];
    }
}
// função de leitura de produtos
void lerProduto(struct Produtos x[], int &contProdutos, int tamanhoMax, struct Categorias y[], int contCategoria){
    struct Produtos auxiliar;
    char op;
    char op1;
    do{
        if(contProdutos>=tamanhoMax){
            cout << "Limite Atingido" << endl;
            break;
        }
        cout << "\nCADASTRO DE PRODUTOS\n" << endl;
        cout << "Digite codigo: " << endl;
        cin >> auxiliar.cod;

        while(BuscarProdutos(x, auxiliar.cod, contProdutos)==true){
            cout << "\n\tPRODUTO JA CADASTRADO !!!" << endl;
            cout << "Digite outro codigo: " << endl;
            cin >> auxiliar.cod;
        }

        cout << "Digite codigo de categoria: " << endl;
        cin >> auxiliar.codCategoria;

        while(BuscarCategoria(y, auxiliar.codCategoria, contCategoria)==false){
        cout << "[ERRO]: Categoria nao cadastrada!" << endl;
        cout << "Digite outro codigo de categoria: " << endl;
        cin >> auxiliar.codCategoria;
        }

        imprimirCategoria(y, auxiliar.codCategoria, contCategoria);

        cout << "Digite descricao: " << endl;
        cin.ignore();
        cin.getline(auxiliar.desc, 60);

        cout << "Digite Estoque Maximo: " << endl;
        cin >> auxiliar.estoqueMax;
        cout << "Digite Estoque Minimo: " << endl;
        cin >> auxiliar.estoqueMin;
        
        while(auxiliar.estoqueMin < 0 || auxiliar.estoqueMax < 0 || auxiliar.estoqueMax < auxiliar.estoqueMin){
        cout << "[ERRO]: Estoque maximo menor que o minimo!" << endl;
        cout << "Digite Estoque Maximo: " << endl;
        cin >> auxiliar.estoqueMax;
        cout << "Digite Estoque Minimo: " << endl;
        cin >> auxiliar.estoqueMin;
        }

        cout << "Digite preco unitario: " << endl;
        cin >> auxiliar.precoUnit;

        while(auxiliar.precoUnit <=0){
            cout << "[ERRO]: Preco invalido " << endl;
            cout << "Digite preco unitario: " << endl;
            cin >> auxiliar.precoUnit;
        }

        cout << "Digite quantidade de Estoque: " << endl;
        cin >> auxiliar.quantEstoque;

        while(auxiliar.quantEstoque < 0){
            cout << "[ERRO] : Estoque invalido" << endl;
            cout << "Digite quantidade de Estoque: " << endl;
            cin >> auxiliar.quantEstoque;   
        }

        system("cls");

        auxiliar.imprimir();

        op=confirmarInfo();

        if(op=='s' || op=='S'){
            incluirProduto(x, auxiliar, tamanhoMax, contProdutos);
            contProdutos++;
            for(int i=0; i<contProdutos;i++){
                cout << endl;
                x[i].imprimir();
                cout << endl;
            }
        } else cout << "[CADASTRO DE PRODUTO CANCELADO]" << endl;

        op1=verificar();
    }while (op1=='s' || op1=='S');
    getch();    
}

void incluirCliente(struct Clientes x[], struct Clientes ClienteIncluir, int tamanhoMax, int contCliente){
    Clientes auxiliar[tamanhoMax];
    int i=0; // contador de Cliente
    int j=0; // contador de auxiliar

    // aqui estamos fazendo a comparação de uma lista com a outra. se o codigo da lista x na pos z for menor que o cod da lista novos clientes na pos j a lista atualizada recebe x[z], pois é sequencial, se não ele recebe novosclientes[j]
    while(i<contCliente && x[i].cod < ClienteIncluir.cod) // enqt ainda tem clientes, e o codigo atual for menor que o ClienteIncluir.cod
    {
        auxiliar[j] = x[i];
        i++;
        j++;
    }
    auxiliar[j] = ClienteIncluir;
    j++;
    while(i<contCliente){
        auxiliar[j] = x[i];
        i++;
        j++;
    }
    for(i=0;i<contCliente+1; i++){ // devolve ao vetor principal
        x[i]=auxiliar[i];
    }
}

// aqui na leitura de clientes
void ler_cliente(struct Clientes x[], int &contCliente, int tamanhoMax){
    Clientes aux;
    char op;
    char op1;
    do{
        if(contCliente >= tamanhoMax){
            cout << "\n[ERRO] Limite de cadastros digitados (" << tamanhoMax << ")!" << endl;
            break;
        }

        cout << "\tCADASTRO DE CLIENTES\t" << endl;
        cout << "Digite codigo do cliente: " << endl;
        cin >> aux.cod;

        while(BuscarClientes(x, aux.cod, contCliente)==true){ // esse while aqui é para verificar se o codigo é igual a algum da lista, caso for ele pede ao usuario digitar novamente, outro codigo, repetindo ate que digite outro codigo
        cout << "\n\tCLIENTE JA CADASTRADO !!" << endl;
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

        aux.imprimir();

        op=confirmarInfo();
        system ("cls");
        if(op=='s' || op=='S'){
            cout << "LISTA ATUALIZADA!" << endl;
            incluirCliente(x, aux, tamanhoMax, contCliente);
            contCliente++;
            for(int i=0; i<contCliente;i++){
                cout << endl;
                x[i].imprimir();
                cout << endl;
            }
        } else cout << "Cadastro cancelado";
        op1=verificar();
    }while(op1=='S' || op1=='s');
    getch();

} 


void inclusaoVendedor(struct Vendedores x[], struct Vendedores VendedorIncluir, int tamanhoMax, int contVendedor){
    Vendedores auxiliar[tamanhoMax];
    int i=0; // contador de Cliente
    int j=0; // contador de auxiliar

    // aqui estamos fazendo a comparação de uma lista com a outra. se o codigo da lista x na pos z for menor que o cod da lista novos clientes na pos j a lista atualizada recebe x[z], pois é sequencial, se não ele recebe novosclientes[j]
    while(i<contVendedor && x[i].cod < VendedorIncluir.cod) // enqt ainda tem clientes, e o codigo atual for menor que o ClienteIncluir.cod
    {
        auxiliar[j] = x[i];
        i++;
        j++;
    }
    auxiliar[j] = VendedorIncluir;
    j++;
    while(i<contVendedor){
        auxiliar[j] = x[i];
        i++;
        j++;
    }
    for(i=0;i<contVendedor+1; i++){ // devolve ao vetor principal
        x[i]=auxiliar[i];
    }
}

void ler_vendedor(struct Vendedores x[], int &contVendedor, int tamanhoMax){
    char op, op1;
    Vendedores aux;
    do{
        if(contVendedor >= tamanhoMax){
            cout << "\n[ERRO] Limite de cadastros digitados (" << tamanhoMax << ")!" << endl;
            break;
        }

        cout << "\tCADASTRO DE VENDEDORES\t" << endl;
        cout << "Posicao: " << contVendedor+1 << endl;
        cout << "Digite codigo do vendedor: " << endl;
        cin >> aux.cod;
        while(BuscarVendedor(x, aux.cod, contVendedor)==true){ 
            cout << "\n\tVENDEDOR JA CADASTRADO!!!" << endl;
            cout << "Digite outro codigo: " << endl;
            cin >> aux.cod;
        }
        cin.ignore();
        cout << "Digite nome do Vendedor: " << endl;
        cin.getline(aux.nome, 30);
        cout << "Digite telefone do Vendedor: " << endl;
        cin.getline(aux.telefone, 13);

        aux.imprimir();

        op=confirmarInfo();
        if(op=='s' || op=='S'){
            inclusaoVendedor(x, aux, tamanhoMax, contVendedor);
            contVendedor++;
            cout << "LISTA DE VENDEDORES ATUALIZADA" << endl;
            for(int i=0;i<contVendedor;i++){
                cout << endl;
                x[i].imprimir();
                cout << endl;
            }
        } else cout << "Cadastro cancelado";
    op1=verificar();
    } while(op1 == 's' || op1 == 'S');
    getch();
}

void lancar_produtos(struct ItensVenda itens[], int &contItens, int codVenda, struct Produtos produtos[], int contProdutos, int tamanhoMax){
    ItensVenda aux_itens;
    char op, op1;
    int posProduto;
    do {

    aux_itens.codVenda=codVenda;

    if(contItens>= tamanhoMax){
        cout << "\n[ERRO] Limite de cadastros digitados (" << tamanhoMax << ")!" << endl;
        break;
    }
    cout << "Digite Codigo do produto: " << endl; 
    cin >> aux_itens.codProd;

    posProduto=BuscarPosProdutos(produtos, aux_itens.codProd, contProdutos);

    if(posProduto==-1){
        cout << "Produto nao existe" << endl;
        op1=verificar();
        continue; // interromper a iteração atual de um loop, mas tambem utilizado especificamente para uma condicional
    }

    produtos[posProduto].imprimir();
    
    cout << "Digite quantidade: " << endl;
    cin >> aux_itens.quant;
    
    while(aux_itens.quant <=0){
        cout << "Quantidade invalida" << endl;
        cout << "Digite outra quantidade" << endl;
        cin >> aux_itens.quant;
    }

    while(aux_itens.quant > produtos[posProduto].quantEstoque){
        cout << "Estoque insuficiente" << endl;
        cout << "Disponivel no momento: " << produtos[posProduto].quantEstoque << endl;
        cout << "Digite outra quantidade" << endl;
        cin >> aux_itens.quant;
    }
    
    cout << "\nCodigo do Produto: " << aux_itens.codProd;
    cout << "\nQuantidade de Produtos: " << aux_itens.quant << endl;
    
    op=confirmarInfo();

    if (op=='S' || op=='s'){
        produtos[posProduto].quantEstoque=produtos[posProduto].quantEstoque-aux_itens.quant;
        itens[contItens]=aux_itens;
        cout << "Informacoes Confirmadas" << endl;
        contItens++;
    } 
    else cout << "Lancamento nao confirmado" << endl;

    op1=verificar();

    } while(op1 == 'S' || op1 == 's');
    getch();
}
void inclusaoVenda(struct Vendas x[], struct Vendas VendasIncluir, int tamanhoMax, int contVendas){
    Vendas auxiliar[tamanhoMax];
    int i=0; // contador de Cliente
    int j=0; // contador de auxiliar

    // aqui estamos fazendo a comparação de uma lista com a outra. se o codigo da lista x na pos z for menor que o cod da lista novos clientes na pos j a lista atualizada recebe x[z], pois é sequencial, se não ele recebe novosclientes[j]
    while(i<contVendas && x[i].cod < VendasIncluir.cod) // enqt ainda tem clientes, e o codigo atual for menor que o ClienteIncluir.cod
    {
        auxiliar[j] = x[i];
        i++;
        j++;
    }
    auxiliar[j] = VendasIncluir;
    j++;
    while(i<contVendas){
        auxiliar[j] = x[i];
        i++;
        j++;
    }
    for(i=0;i<contVendas+1; i++){ // devolve ao vetor principal
        x[i]=auxiliar[i];
    }
}

void incluir_venda(struct ItensVenda itens[], int &contItens,struct Produtos x[], int contProdutos, struct Vendas vendas[], int contVendas, int tamanhoMax){
    char op, op1;
    int posProduto;
    ItensVenda aux;
    do{
        if(contItens >= tamanhoMax){
            cout << "\n[ERRO] Limite de cadastros digitados (" << tamanhoMax << ")!" << endl;
            break;
        }
        cout << "Digite codigo da venda" << endl;
        cin >> aux.codVenda;
        while(BuscarVendas(vendas, aux.codVenda, contVendas)==false){
            cout << "[ERRO] VENDA NAO CADASTRADA" << endl;
            cout << "Digite outro codigo de venda" << endl;
            cin >> aux.codVenda;
        }
        cout << "Digite codigo do produto" << endl;
        cin >> aux.codProd;
        posProduto=BuscarPosProdutos(x, aux.codProd, contProdutos);
        if (posProduto == -1){
            cout << "Produto nao encontrado" << endl;
            op1=verificar();
            continue;
        }
        x[posProduto].imprimir();

        cout << "Digite a quantidade do produto: " << endl;
        cin >>  aux.quant;

        while(aux.quant <= 0){
        cout << "[ERRO] Quantidade invalida!" << endl;
        cout << "Digite uma quantidade maior que zero: " << endl;
        cin >> aux.quant;
        }

        while(aux.quant > x[posProduto].quantEstoque){
            cout << "Estoque Insuficiente" << endl;
            cout << "Atualmente em estoque temos: " << x[posProduto].quantEstoque << endl;
            cout << endl;
            cout << "Digite a quantidade do produto: " << endl;
            cin >>  aux.quant; 
        }
        
        op=confirmarInfo();
            
        if (op == 'S' || op=='s'){
            x[posProduto].quantEstoque = x[posProduto].quantEstoque-aux.quant;
            itens[contItens]=aux;
            contItens++;
            cout << "Item incluido com sucesso" << endl;
            } else{
            cout << "Inclusao cancelada" << endl;
        }
        op1=verificar();
        } while(op1=='S' || op1=='s');
        
    getch();

}
// função registrar venda, usamos como parametro as 3 structs junto a seus contadores, e chamamos outras 2 funções diferentes para imprimir cliente e vendedor com seus dados. 
// dentro da função registrar venda para poder fazer o lançamento das vendas, ou seja ele envvia como paramatro para função de lancar produtos o vetor de itens, contador de itens e o codigo da venda que é usado como parametro, e na função de lançar a venda ele vincula a chave primária a chave estrangeira, entrando assim em um loop para lançar quantos produtos desejar
void registrar_venda(struct Vendas x[], int &contVendas, int tamanhoMax, struct Clientes cliente[], int &contCliente, struct Vendedores vendedor[], int &contVendedores, struct ItensVenda itens[], int &contItens, struct Produtos produtos[], int &contProdutos){
    Vendas aux;
    char op, op1;
    do{

        if(contVendas >= tamanhoMax){
            cout << "\n[ERRO] Limite de cadastros digitados (" << tamanhoMax << ")!" << endl;
            return;
        }

        cout << "\nLANCAMENTO DE VENDAS\t" << endl;
        cout << "Digite codigo da venda: " << endl;
        cin >> aux.cod;

        while(BuscarVendas(x, aux.cod, contVendas)==true){ // aqui entramos em um loop ate o usuario digitar um codigo valido
            cout << "\n\tVENDA DA CADASTRADA!!!" << endl;
            cout << "Digite outro codigo: " << endl;
            cin >> aux.cod;
        }
        
        cout << "Digite codigo do cliente: " << endl;
        cin >> aux.codCliente;

        while(BuscarClientes(cliente, aux.codCliente, contCliente)==false){
            cout << "\n\tCLIENTE NAO CADASTRADO!!!" << endl;
            cout << "Digite outro codigo; " << endl;
            cin >> aux.codCliente;
        }
        int posCliente=BuscarPosCliente(cliente, aux.codCliente, contCliente);
        cliente[posCliente].imprimir();

        cout << "Digite codigo do Vendedor: " << endl;
        cin >> aux.codVendedor;

        while(BuscarVendedor(vendedor, aux.codVendedor, contVendedores)==false){
            cout << "\n\tVENDEDOR NAO CADASTRADO!!!" << endl;
            cout << "Digite outro codigo: " << endl;
            cin >> aux.codVendedor;
        }
        int posVendedor=BuscarPosVendedor(vendedor, aux.codVendedor, contVendedores);
        vendedor[posVendedor].imprimir();

        cout << "Digite data da venda" << endl;
        cin.ignore();
        cin.getline(aux.data, 12);

        aux.imprimir();

        op=confirmarInfo();

        if(op=='S' || op=='s'){
            lancar_produtos(itens, contItens, aux.cod, produtos, contProdutos, tamanhoMax);
            inclusaoVenda(x, aux, tamanhoMax, contVendas);
            contVendas++;
            cout << "LISTA DE VENDAS ATUALIZADA" << endl;
        
            for(int i=0;i<contVendas; i++){
                cout << endl;
                x[i].imprimir();
                cout << endl;
        }

            }  else cout << "Cadastro cancelado" << endl;
        
            op1=verificar();

    } while(op1 == 's' || op1 =='S');
    getch();
}


void consultar_produtos(struct Produtos busc[], int contProdutos)
{
    int ini = 0;
    int fim = contProdutos - 1;
    int m;
    bool achou = false;
    int codPesquisa=0;
    cout << "Digite o codigo do produto: ";
    cin >> codPesquisa;
    while(ini <= fim)
    {
        m = (ini + fim) / 2;
        if (codPesquisa == busc[m].cod)
        {
            cout << "\n\nPRODUTO ENCONTRADO";
            cout << "\nCodigo do produto: " << busc[m].cod;
            cout << "\nDescricao do produto: " << busc[m].desc;
            cout << "\nCodigo da categoria: " << busc[m].codCategoria;
            cout << "\nQuantidade em estoque: " << busc[m].quantEstoque;
            cout << "\nEstoque minimo: " << busc[m].estoqueMin;
            cout << "\nEstoque maximo: " << busc[m].estoqueMax;
            cout << "\nPreco do produto: " << busc[m].precoUnit;

            float valorTotal = busc[m].quantEstoque * busc[m].precoUnit;

            cout << "\nValor total em estoque: " << valorTotal << endl;

            achou = true;
            break;
        }
        else if(codPesquisa < busc[m].cod)
        {
            fim = m - 1;
        }
        else
        {
            ini = m + 1;
        }
    }
    if (!achou)
    {
        cout << "\n\nProduto nao encontrado\n";
    }
    getch();
}


void estoque_baixo(struct Produtos prod[], int contProdutos)
{
    int i = 0;
    float totalReposicao = 0;

    for(;i < contProdutos; i++)
    {
        if(prod[i].quantEstoque <= prod[i].estoqueMin)
        {
            int qtdComprar = prod[i].estoqueMax - prod[i].quantEstoque;
            float valorCompra = qtdComprar * prod[i].precoUnit;
            totalReposicao += valorCompra;
            
            cout << "\n\nPRODUTO COM ESTOQUE ABAIXO DO MINIMO";
            cout << "\nCodigo do produto: " << prod[i].cod;
            cout << "\nDescricao do produto: " << prod[i].desc;
            cout << "\nQuantidade em estoque: " << prod[i].quantEstoque;
            cout << "\nEstoque maximo: " << prod[i].estoqueMax;
            cout << "\nQuantidade a comprar: " << qtdComprar;
            cout << "\nValor da compra: R$ " << valorCompra << endl;
        }
    }
    cout << "\nValor total da reposicao: R$ " << totalReposicao << endl;
    getch();
}

void total_arrecadado(struct Produtos prod[], int contProdutos, struct ItensVenda itens[], int contItens) {
    float total = 0;

    for(int i = 0; i < contItens; i++)
    {
        int posProduto =
            BuscarPosProdutos(prod, itens[i].codProd, contProdutos);

        if(posProduto != -1)
        {
            total += itens[i].quant * prod[posProduto].precoUnit;
        }
    }

    cout << "Valor total arrecadado: R$ " << total << endl;
    getch();
}

void exclusao_cliente(struct Clientes cli[], int &contClientes)
{
    int codPesquisa;
    bool achou = false;

    cout << "Digite o codigo do cliente a excluir: ";
    cin >> codPesquisa;

    int inicio = 0;
    int fim = contClientes - 1;
    int meio;

    while(inicio <= fim)
    {
        meio = (inicio + fim) / 2;

        if(cli[meio].cod == codPesquisa)
        {
            cout << "\nCliente encontrado:";
            cout << "\nCodigo: " << cli[meio].cod;
            cout << "\nNome: " << cli[meio].nome;
            cout << "\nEndereco: " << cli[meio].endereco;
            cout << "\nTelefone: " << cli[meio].telefone << endl;

            char op=confirmarInfo();

            if(op== 'S' || op == 's')
            {
                for(int j = meio; j < contClientes - 1; j++)
                {
                    cli[j] = cli[j + 1];
                }

                contClientes--;

                cout << "\nCliente excluido com sucesso!" << endl;
                cout << "Lista de Clientes Atualizada" << endl;
                for(int i=0; i<contClientes;i++){
                    cli[i].imprimir();
                }
            }

            achou = true;
            break;
        }
        else if(codPesquisa < cli[meio].cod)
        {
            fim = meio - 1;
        }
        else
        {
            inicio = meio + 1;
        }
    }

    if(!achou)
    {
        cout << "\nCliente nao encontrado!" << endl;
    }

    getch();
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
    int tamanhoMax=10;
    int opcao;
// 1. Carga de Categorias
    cat[0].cod = 1; strcpy(cat[0].desc, "Hortifruti");
    cat[1].cod = 2; strcpy(cat[1].desc, "Grafica e Papelaria");
    cat[2].cod = 3; strcpy(cat[2].desc, "Vestuario");
    contCategorias = 3;

    // 2. Carga de Produtos (cod, desc, codCategoria, quantEstoque, estoqueMin, estoqueMax, precoUnit)
    prod[0].cod=1; strcpy(prod[0].desc, "Banana");prod[0].codCategoria=1; prod[0].quantEstoque=50; prod[0].estoqueMax=100; prod[0].estoqueMin=10; prod[0].precoUnit=5;
    prod[1].cod = 102; strcpy(prod[1].desc, "Caderno Universitario"); prod[1].codCategoria = 2; prod[1].quantEstoque = 30; prod[1].estoqueMin = 5; prod[1].estoqueMax = 50; prod[1].precoUnit = 25.00;
    prod[2].cod = 103; strcpy(prod[2].desc, "Camiseta Dry Termica"); prod[2].codCategoria = 3; prod[2].quantEstoque = 20; prod[2].estoqueMin = 5; prod[2].estoqueMax = 40; prod[2].precoUnit = 45.90;
    prod[3].cod = 104; strcpy(prod[3].desc, "Impressao A4 Colorida"); prod[3].codCategoria = 2; prod[3].quantEstoque = 500; prod[3].estoqueMin = 100; prod[3].estoqueMax = 1000; prod[3].precoUnit = 2.00;
    contProdutos = 5;

    // 3. Carga de Clientes (cod, nome, endereco, telefone)
    cliente[0].cod = 1; strcpy(cliente[0].nome, "Valter Silva"); strcpy(cliente[0].endereco, "Rua Central, 123"); strcpy(cliente[0].telefone, "18999990000");
    cliente[1].cod = 2; strcpy(cliente[1].nome, "Cicero Siqueira"); strcpy(cliente[1].endereco, "Av. Brasil, 45"); strcpy(cliente[1].telefone, "18988881111");
    contClientes = 2;

    // 4. Carga de Vendedores (cod, nome, telefone)
    vendedor[0].cod = 1; strcpy(vendedor[0].nome, "Joao Paulo"); strcpy(vendedor[0].telefone, "18977772222");
    vendedor[1].cod = 2; strcpy(vendedor[1].nome, "Carlos Augusto"); strcpy(vendedor[1].telefone, "18966663333");
    contVendedores = 2;
    do {
        setlocale(LC_ALL, "");
        menu();
        cout << "Faca sua escolha: " << endl;
        cin >> opcao;
        switch(opcao) {
            case 1:
                lerCategoria(cat, contCategorias, tamanhoMax); // LEITURA DE CATEGORIA
                break;
            case 2:
                lerProduto(prod, contProdutos, tamanhoMax, cat, contCategorias); // LEITURA DE PRODUTOS
                break;
            case 3:
                ler_cliente(cliente, contClientes, tamanhoMax);
                break; 
            case 4:
                ler_vendedor(vendedor, contVendedores, tamanhoMax);
                break;
            case 5:
                registrar_venda(vendas, contVendas, tamanhoMax, cliente, contClientes, vendedor, contVendedores, itens_venda, contItens, prod, contProdutos);
                break;
            case 6:
                incluir_venda(itens_venda, contItens, prod, contProdutos, vendas, contVendas, tamanhoMax);
                break;
            case 7:
                consultar_produtos(prod, contProdutos);
                break;
            case 8:
                estoque_baixo(prod, contProdutos);
                break;
            case 9:
                total_arrecadado(prod, contProdutos, itens_venda, contItens);
                break;
            case 10:
                exclusao_cliente(cliente, contClientes);
                break;
            case 0:
                cout << "Encerrando operacao" << endl;
                break;
            default:    
                cout << "Opcao invalida" << endl;
        }
    } while(opcao!=0);

}


