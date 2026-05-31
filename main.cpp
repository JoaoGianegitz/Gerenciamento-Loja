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
    char data[10];
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

bool verificar(){
    bool resposta;
    cout << "Deseja continuar cadastrando? " << endl;
    cout << "0 - Sim" << " | " << "1 - Nao" << endl;
    cin >> resposta;
}

bool confirmarInfo(){
    bool resposta;
    cout << "Voce Confirma as informacoes? " << endl;
    cout << "0 - Sim" << " | " << "1 - Nao" << endl;
    cin >> resposta;
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
        cout << "\n\t\t10 - Excluir Cliente ( tem que colocar no siwtch case ainda)" << endl;
        cout << "\n\t\t0 - Sair" << endl;
}

bool verificaCategoria(struct Categorias x[], int &contCategoria, int codPesquisa){
    for (int i=0; i<contCategoria; i++){
    if (codPesquisa == x[i].cod) {                  //(codPesquisa == cli[i].cod){
        cout << "\n\n CATEGORIA JA CADASTRADA!";
        x[i].imprimir();

        return true;
    } 
    }
    return false;
}
// função de leitura das Categorias
void lerCategoria(struct Categorias x[], int &contCategoria, int tamanhoMax){
    char conf;
    do{ 
        if(contCategoria>=tamanhoMax){
            cout << "Limite Atingido" << endl;
            break;
        }    
        cout << "\nCADASTRO DE CATEGORIAS\n" << endl;
        cout << "Digite codigo: " << contCategoria+1 << endl;
        cin >> x[contCategoria].cod;
        while(verificaCategoria(x, contCategoria, x[contCategoria].cod)){ // aqui entramos em um loop ate o usuario digitar um codigo valido
            cout << "Digite outro codigo: " << endl;
            cin >> x[contCategoria].cod;
        }
        cin.ignore();
        cout << "Digite descricao: " << contCategoria+1 << endl;
        cin.getline(x[contCategoria].desc, 60);
        x[contCategoria].imprimir(); 
        contCategoria++;
        cout << "Deseja cadastrar outro categoria: (Y ou N)" << endl;
        cin >> conf; 
        if (conf == 'N' || conf == 'n') {
            cout << "Operacao Finalizada" << endl;
            break;
        }
    }while (conf=='Y' || conf =='y');
    getch();
}

bool verificaProduto(struct Produtos x[], int &contProdutos, int codPesquisa){
    for (int i=0; i<contProdutos; i++){
    if (codPesquisa == x[i].cod) {                  //(codPesquisa == cli[i].cod){
        cout << "\n PRODUTO JA CADASTRADO!";
        x[i].imprimir();
        return true;
    } 
    }
    return false;
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
void lerProduto(struct Produtos x[], int &contProdutos, int tamanhoMax){
    struct Produtos auxiliar;
    bool resposta;
    do{
        if(contProdutos>=tamanhoMax){
            cout << "Limite Atingido" << endl;
            break;
        }
        cout << "\nCADASTRO DE PRODUTOS\n" << endl;
        cout << "Digite codigo: " << contProdutos+1 << endl;
        cin >> auxiliar.cod;
        verificaProduto(x, contProdutos, x[contProdutos].cod);
        cout << "Digite codigo de categoria: " << contProdutos+1 << endl;
        cin >> auxiliar.codCategoria;
        cout << "Digite descricao: " << contProdutos+1 << endl;
        cin.ignore();
        cin.getline(auxiliar.desc, 60);
        cout << "Digite Estoque Maximo: " << contProdutos+1 << endl;
        cin >> auxiliar.estoqueMax;
        cout << "Digite Estoque Minimo: " << contProdutos+1 << endl;
        cin >> auxiliar.estoqueMin;
        cout << "Digite preco unitario: " << contProdutos+1 << endl;
        cin >> auxiliar.precoUnit;
        cout << "Digite quantidade de Estoque: " << contProdutos+1 << endl;
        cin >> auxiliar.quantEstoque;
        system("cls");
        auxiliar.imprimir();
        bool confirmacao=confirmarInfo();
        if(!confirmacao){
            incluirProduto(x, auxiliar, tamanhoMax, contProdutos);
            contProdutos++;
        }
        for(int i=0; i<contProdutos;i++){
        cout << "\n\t =====================================================" << endl;
            x[i].imprimir();
        }
        resposta=verificar();
    }while (!resposta);
    getch();
}


// função verifica cliente. Ultilizamos um contador de cliente e um codigo de pesquisa, onde temos um loop que percorre toda a lista para ver se existe um codigo igual, caso existir ele vai retornar um valor booleano, que vamos usar como parametro na hora de fazer a leitura dos registros, para saber se devemos continuar fazendo a leitura ou não
bool verificaCliente(struct Clientes x[], int contCliente, int codPesquisa){
    for (int i=0; i<contCliente; i++){
    if (codPesquisa == x[i].cod) {                  //(codPesquisa == cli[i].cod){
        cout << "\n\n CLIENTE JA CADASTRADO!";
        x[i].imprimir();
        return true;
    } 
    }
    return false;
}
/*
bool verifica_ordem_Cliente(struct Clientes x[], int contCliente, int i){
    for (i; i<contCliente; i++){
    if (x[i-1].cod <= x[i].cod) {                  //(codPesquisa == cli[i].cod){
        return true;
    } else {
        cout << "\n [SEQUENCIA QUEBRADA] DIGITE OUTRO NUMERO MAIOR QUE O ANTERIOR: " << endl;
        return false;
    }
    }
}*/
// copia os menores - insere novo - copia o restante - atualiza vetor original
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
    char conf;
    Clientes aux;
    bool resposta;
    do{
        if(contCliente >= tamanhoMax){
            cout << "\n[ERRO] Limite de cadastros digitados (" << tamanhoMax << ")!" << endl;
            break;
        }

        cout << "\tCADASTRO DE CLIENTES\t" << endl;
        //cout << "Posicao: " << contNovosClientes << endl;
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
        aux.imprimir();

        cout << "Voce confirma as informacoes: (Y ou N)" << endl;
        cin >> conf; 

        if(conf=='y' || conf=='Y'){
            incluirCliente(x, aux, tamanhoMax, contCliente);
            contCliente++;
            for(int i=0; i<contCliente;i++){
                x[i].imprimir();
                cout << endl;
            }
        } else cout << "Cadastro cancelado";
        resposta=verificar();
    }while(!resposta);
} //john of fishing


void imprimir_clientes(struct Clientes x[], int contClientes){
    for(int i=0;i<contClientes;i++){
        cout << endl;
        cout << "Codigo do Cliente: "<<  x[i].cod << endl;
        cout << "Codigo do Cliente: "<<  x[i].nome << endl;
        cout << "Codigo do Cliente: "<<  x[i].endereco << endl;
        cout << "Codigo do Cliente: "<<  x[i].telefone << endl;
        cout << endl;
    }


}
bool verificaVendedor(struct Vendedores x[], int contVendedor, int codPesquisa){
    for (int i=0; i<contVendedor; i++){
    if (codPesquisa == x[i].cod) {                  //(codPesquisa == cli[i].cod){
        cout << "\n\n VENDEDOR JA CADASTRADO!";
        x[i].imprimir();

        return true;
    } 
    }
    return false;
}


void ler_vendedor(struct Vendedores x[], int &contVendedor, int tamanhoMax){
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
        aux.imprimir();

        cout << "Voce confirma as informacoes: (Y ou N)" << endl;
        cin >> conf; 

        if(conf=='y' || conf=='Y'){
            x[contVendedor]=aux;
            contVendedor++;
        } else cout << "Cadastro cancelado";
    }
    getch();
}

bool imprimirCliente(struct Clientes x[], int contCliente, int codCliente){
    for(int i=0; i<contCliente; i++){
        if (codCliente == x[i].cod) {                
            cout << "\nCLIENTE!";
            x[i].imprimir();
            cout << endl;
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
            x[i].imprimir();
            cout << endl;

            return true;
        }
    }
    cout << "Vendedor nao cadastrado" << endl;
    return false; 
}

void imprimir_produto(struct Produtos x[], int codigoProduto){
    cout << "Descricao Produto: " << x[codigoProduto].desc;
    cout << "Preco unitario: " << x[codigoProduto].precoUnit;
    cout << "Quantidade em estoque: " << x[codigoProduto].quantEstoque << endl;
}
void lancar_produtos(struct ItensVenda itens[], int &contItens, int codVenda, struct Produtos produtos[], int contProdutos){
    ItensVenda aux_itens;
    char conf;
    char confirmacao;
    do {

    aux_itens.codVenda=codVenda;

    cout << "Digite Codigo do produto: " << endl; 
    cin >> aux_itens.codProd;
    if(aux_itens.codProd < 0 || aux_itens.codProd >= contProdutos){
        cout << "Produto nao existe" << endl;
        continue; // interromper a iteração atual de um loop, mas tambem utilizado especificamente para uma condicional
    }
    imprimir_produto(produtos, aux_itens.codProd);
    cout << "Digite quantidade: " << endl;
    cin >> aux_itens.quant;
    if(aux_itens.quant > produtos[aux_itens.codProd].quantEstoque){
        cout << "Estoque insuficiente" << endl;
        cout << "Disponivel no momento: " << produtos[aux_itens.codProd].quantEstoque << endl;
        continue;
    }
    cout << "\nCodigo do Produto: " << aux_itens.codProd;
    cout << "\nQuantidade de Produtos: " << aux_itens.quant;
    cout << "Voce confirma as informacoes: (Y ou N)" << endl;
    cin >> conf; 

    if (conf=='y' || conf=='Y'){
        produtos[aux_itens.codProd].quantEstoque=produtos[aux_itens.codProd].quantEstoque-aux_itens.quant;
        itens[contItens]=aux_itens;
        cout << "Informacoes Confirmadas" << endl;
        contItens++;
    } 
    else cout << "Lancamento nao confirmado" << endl;

    cout << "Deseja cadastrar mais algum item? (Y/N): ";
    cin >> confirmacao;

    } while(confirmacao == 'y' || confirmacao == 'Y');
    getch();
}

// função registrar venda, usamos como parametro as 3 structs junto a seus contadores, e chamamos outras 2 funções diferentes para imprimir cliente e vendedor com seus dados. 
// dentro da função registrar venda para poder fazer o lançamento das vendas, ou seja ele envvia como paramatro para função de lancar produtos o vetor de itens, contador de itens e o codigo da venda que é usado como parametro, e na função de lançar a venda ele vincula a chave primária a chave estrangeira, entrando assim em um loop para lançar quantos produtos desejar
void registrar_venda(struct Vendas x[], int &contVendas, int tamanhoMax, struct Clientes cliente[], int &contCliente, struct Vendedores vendedor[], int &contVendedores, struct ItensVenda itens[], int &contItens, struct Produtos produtos[], int &contProdutos){
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
    lancar_produtos(itens, contItens, aux.cod, produtos, contProdutos);
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
    aux.imprimir();

    cout << "Voce confirma as informacoes: (Y ou N)" << endl;
    cin >> conf; 

    if(conf=='y' || conf=='Y'){
        x[contVendas]=aux;
        contVendas++;
    } else cout << "Cadastro cancelado";
    getch();
}

void incluir_venda(struct Produtos x[], int contProdutos){
    char conf;
    int qtdade;
    int cod;
    cout << "Digite codigo do produto" << endl;
    cin >> cod;
    if (cod < 0 || cod >= contProdutos){
        cout << "Produto nao encontrado" << endl;
    }
    imprimir_produto(x, cod); // chamando função de imprimir produto

    cout << "Digite a quantidade do produto: " << endl;
    cin >>  qtdade;

    if (qtdade > x[cod].quantEstoque){
        cout << "Estoque Insuficiente" << endl;
        cout << "Atualmente em estoque temos: " << x[cod].quantEstoque << endl;
    } else {
        cout << "Estoque Suficiente" << endl;
        cout << "Voce confirma a inclusao Y|N: " << endl;
        cin >> conf;
        if (conf == 'y' || conf=='Y'){
            x[cod].quantEstoque = x[cod].quantEstoque-qtdade;
            } else{
            cout << "Inclusao cancelada" << endl;
        }
        }
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

void total_arrecadado(struct Produtos prod[], int contProdutos, struct ItensVenda itens[], int contItens)
{
    int i = 0;
    int j = 0;
    float total = 0;
    float valorItem = 0;

    for(;i < contItens; i++)
    {
        int codigoProduto = itens[i].codProd;
        for(;j < contProdutos; j++)
        {
            if(codigoProduto == prod[j].cod)
            {
                valorItem = itens[i].quant * prod[j].precoUnit;
                total += valorItem;
            }
        }
    }

    cout << "Valor total arrecadado: R$ " << total << endl;
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
    int opcao;

// 1. Carga de Categorias
    cat[0].cod = 1; strcpy(cat[0].desc, "Hortifruti");
    cat[1].cod = 2; strcpy(cat[1].desc, "Grafica e Papelaria");
    cat[2].cod = 3; strcpy(cat[2].desc, "Vestuario");
    contCategorias = 3;

    // 2. Carga de Produtos (cod, desc, codCategoria, quantEstoque, estoqueMin, estoqueMax, precoUnit)
    prod[0].cod = 101; strcpy(prod[0].desc, "Pacote de Mandioca 1kg"); prod[0].codCategoria = 1; prod[0].quantEstoque = 50; prod[0].estoqueMin = 10; prod[0].estoqueMax = 100; prod[0].precoUnit = 15.50;
    prod[1].cod = 102; strcpy(prod[1].desc, "Caderno Universitario"); prod[1].codCategoria = 2; prod[1].quantEstoque = 30; prod[1].estoqueMin = 5; prod[1].estoqueMax = 50; prod[1].precoUnit = 25.00;
    prod[2].cod = 103; strcpy(prod[2].desc, "Camiseta Dry Termica"); prod[2].codCategoria = 3; prod[2].quantEstoque = 20; prod[2].estoqueMin = 5; prod[2].estoqueMax = 40; prod[2].precoUnit = 45.90;
    prod[3].cod = 104; strcpy(prod[3].desc, "Impressao A4 Colorida"); prod[3].codCategoria = 2; prod[3].quantEstoque = 500; prod[3].estoqueMin = 100; prod[3].estoqueMax = 1000; prod[3].precoUnit = 2.00;
    contProdutos = 4;

    // 3. Carga de Clientes (cod, nome, endereco, telefone)
    cliente[0].cod = 10; strcpy(cliente[0].nome, "Valter Silva"); strcpy(cliente[0].endereco, "Rua Central, 123"); strcpy(cliente[0].telefone, "18999990000");
    cliente[1].cod = 20; strcpy(cliente[1].nome, "Cicero Siqueira"); strcpy(cliente[1].endereco, "Av. Brasil, 45"); strcpy(cliente[1].telefone, "18988881111");
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
                lerCategoria(cat, contCategorias, 100); // LEITURA DE CATEGORIA
                break;
            case 2:
                lerProduto(prod, contProdutos, 100); // LEITURA DE PRODUTOS
                break;
            case 3:
                ler_cliente(cliente, contClientes, 100);
                break; 
            case 4:
                ler_vendedor(vendedor, contVendedores, 100);
                break;
            case 5:
                registrar_venda(vendas, contVendas, 100, cliente, contClientes, vendedor, contVendedores, itens_venda, contItens, prod, contProdutos);
                break;
            case 6:
                incluir_venda(prod, contProdutos);
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
                imprimir_clientes(cliente, contClientes);
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


Confirmar com begosso, sobre como devemos fazer a inclusão em umm arquivo sequencial, se temos que fazer uma confirmação para ver se realmente os numeros digitados estão em sequencia, ou algo do tipo.

fazer uma função para ler cliente e outra para incluir cliente


fazer uma confirmação se a digitação dos codigos está sendo em ordem crescente
*/


