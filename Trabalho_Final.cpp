#include <iostream>
#include <string>
#include <limits>
#include <locale>

using namespace std;

void pausar() {
    cout << "\n\tPressione ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int lerInteiro(string mensagem) {
    int valor;

    while (true) {
        cout << mensagem;

        if (cin >> valor) {
            return valor;
        }
        else {
            cout << "\n\t[ERRO]: Digite apenas numeros inteiros.";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

float lerFloat(string mensagem) {
    float valor;

    while (true) {
        cout << mensagem;

        if (cin >> valor) {
            return valor;
        }
        else {
            cout << "\n\t[ERRO]: Digite um valor numerico valido.";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int lerInteiroMaiorOuIgual(string mensagem, int minimo) {
    int valor = lerInteiro(mensagem);

    while (valor < minimo) {
        cout << "\n\tValor invalido. Informe um valor maior ou igual a " << minimo << ".";
        valor = lerInteiro(mensagem);
    }

    return valor;
}

int lerInteiroMaiorQueZero(string mensagem) {
    return lerInteiroMaiorOuIgual(mensagem, 1);
}

float lerFloatMaiorQueZero(string mensagem) {
    float valor = lerFloat(mensagem);

    while (valor <= 0) {
        cout << "\n\tValor invalido. Informe um valor maior que zero.";
        valor = lerFloat(mensagem);
    }

    return valor;
}

int lerOpcaoSimNao(string mensagem) {
    int opcao = 2;

    while (opcao != 1 && opcao != 0) {
        cout << mensagem;
        cout << "\n\t1 - Sim";
        cout << "\n\t0 - Nao";
        opcao = lerInteiro("\n\tOpcao: ");

        if (opcao != 1 && opcao != 0) {
            cout << "\n\tOpcao Invalida, Favor Inserir uma Correta.";
        }
    }

    return opcao;
}

struct Categoria {
    int codigo;
    string descricao;

    void imprimir() {
        cout << "\n\t\t--- CATEGORIA ---";
        cout << "\n\tCodigo: " << codigo;
        cout << "\n\tDescricao: " << descricao;
    }
};

struct Produto {
    int codigo;
    string descricao;
    int codCategoria;
    int quantEstoque;
    int estoqueMinimo;
    int estoqueMaximo;
    float valorUnitario;

    void imprimir() {
        cout << "\n\t\t--- PRODUTO ---";
        cout << "\n\tCodigo: " << codigo;
        cout << "\n\tDescricao: " << descricao;
        cout << "\n\tCodigo da Categoria: " << codCategoria;
        cout << "\n\tQuantidade em Estoque: " << quantEstoque;
        cout << "\n\tEstoque Minimo: " << estoqueMinimo;
        cout << "\n\tEstoque Maximo: " << estoqueMaximo;
        cout << "\n\tValor Unitario: " << valorUnitario;
    }

    void imprimirResumo() {
        cout << "\n\t\t--- PRODUTO ---";
        cout << "\n\tCodigo: " << codigo;
        cout << "\n\tDescricao: " << descricao;
        cout << "\n\tValor Unitario: " << valorUnitario;
        cout << "\n\tEstoque: " << quantEstoque;
    }

    void imprimirEstoqueMinimo() {
        cout << "\n\t\t--- PRODUTO ABAIXO DO ESTOQUE MINIMO ---";
        cout << "\n\tCodigo: " << codigo;
        cout << "\n\tDescricao: " << descricao;
        cout << "\n\tValor Unitario: " << valorUnitario;
        cout << "\n\tQuantidade em Estoque: " << quantEstoque;
        cout << "\n\tEstoque Minimo: " << estoqueMinimo;
        cout << "\n\tEstoque Maximo: " << estoqueMaximo;
        cout << "\n\tQuantidade a ser Comprada: " << estoqueMaximo - quantEstoque;
        cout << "\n\tValor da Compra: " << valorUnitario * (estoqueMaximo - quantEstoque);
    }
};

struct Cliente {
    int codigo;
    string nome;
    string endereco;
    string telefone;

    void imprimir() {
        cout << "\n\t\t--- CLIENTE ---";
        cout << "\n\tCodigo: " << codigo;
        cout << "\n\tNome: " << nome;
        cout << "\n\tEndereco: " << endereco;
        cout << "\n\tTelefone: " << telefone;
    }

    void imprimirResumo() {
        cout << "\n\t\t--- CLIENTE ---";
        cout << "\n\tCodigo: " << codigo;
        cout << "\n\tNome: " << nome;
    }
};

struct Vendedor {
    int codigo;
    string nome;
    string telefone;

    void imprimir() {
        cout << "\n\t\t--- VENDEDOR ---";
        cout << "\n\tCodigo: " << codigo;
        cout << "\n\tNome: " << nome;
        cout << "\n\tTelefone: " << telefone;
    }

    void imprimirResumo() {
        cout << "\n\t\t--- VENDEDOR ---";
        cout << "\n\tCodigo: " << codigo;
        cout << "\n\tNome: " << nome;
    }
};

struct Venda {
    int codigo;
    int codCliente;
    int codVendedor;
    string data;

    void imprimir() {
        cout << "\n\t\t--- VENDA ---";
        cout << "\n\tCodigo: " << codigo;
        cout << "\n\tCodigo Cliente: " << codCliente;
        cout << "\n\tCodigo Vendedor: " << codVendedor;
        cout << "\n\tData: " << data;
    }
};

struct ItensVenda {
    int codVenda;
    int codProduto;
    int quantidade;

    void imprimir() {
        cout << "\n\t\t--- ITEM DA VENDA ---";
        cout << "\n\tCodigo da Venda: " << codVenda;
        cout << "\n\tCodigo do Produto: " << codProduto;
        cout << "\n\tQuantidade: " << quantidade;
    }
};

int ProcuraCategoria(Categoria categoria[], int cod, int cont, int &indCategoria) {
    int inicio = 0;
    int fim = cont - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (categoria[meio].codigo == cod) {
            indCategoria = meio;
            return 0;
        }
        else if (cod < categoria[meio].codigo) {
            fim = meio - 1;
        }
        else {
            inicio = meio + 1;
        }
    }

    return 1;
}

int ProcuraProduto(Produto produto[], int cod, int cont, int &indProduto) {
    int inicio = 0;
    int fim = cont - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (produto[meio].codigo == cod) {
            indProduto = meio;
            return 0;
        }
        else if (cod < produto[meio].codigo) {
            fim = meio - 1;
        }
        else {
            inicio = meio + 1;
        }
    }

    return 1;
}

int ProcuraCliente(Cliente cliente[], int cod, int cont, int &indCliente) {
    int inicio = 0;
    int fim = cont - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (cliente[meio].codigo == cod) {
            indCliente = meio;
            return 0;
        }
        else if (cod < cliente[meio].codigo) {
            fim = meio - 1;
        }
        else {
            inicio = meio + 1;
        }
    }

    return 1;
}

int ProcuraVendedor(Vendedor vendedor[], int cod, int cont, int &indVendedor) {
    int inicio = 0;
    int fim = cont - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vendedor[meio].codigo == cod) {
            indVendedor = meio;
            return 0;
        }
        else if (cod < vendedor[meio].codigo) {
            fim = meio - 1;
        }
        else {
            inicio = meio + 1;
        }
    }

    return 1;
}

int ProcuraVenda(Venda venda[], int cod, int cont, int &indVenda) {
    int inicio = 0;
    int fim = cont - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (venda[meio].codigo == cod) {
            indVenda = meio;
            return 0;
        }
        else if (cod < venda[meio].codigo) {
            fim = meio - 1;
        }
        else {
            inicio = meio + 1;
        }
    }

    return 1;
}

void InclusaoCategoria(Categoria categoria[], Categoria inclusao, int t, int cont) {
    Categoria tab[t];
    int i = 0;
    int j = 0;

    while (i < cont && categoria[i].codigo < inclusao.codigo) {
        tab[j] = categoria[i];
        i++;
        j++;
    }

    tab[j] = inclusao;
    j++;

    while (i < cont) {
        tab[j] = categoria[i];
        i++;
        j++;
    }

    for (i = 0; i < cont + 1; i++) {
        categoria[i] = tab[i];
    }
}

void InclusaoProduto(Produto produto[], Produto inclusao, int t, int cont) {
    Produto tab[t];
    int i = 0;
    int j = 0;

    while (i < cont && produto[i].codigo < inclusao.codigo) {
        tab[j] = produto[i];
        i++;
        j++;
    }

    tab[j] = inclusao;
    j++;

    while (i < cont) {
        tab[j] = produto[i];
        i++;
        j++;
    }

    for (i = 0; i < cont + 1; i++) {
        produto[i] = tab[i];
    }
}

void InclusaoCliente(Cliente cliente[], Cliente inclusao, int t, int cont) {
    Cliente tab[t];
    int i = 0;
    int j = 0;

    while (i < cont && cliente[i].codigo < inclusao.codigo) {
        tab[j] = cliente[i];
        i++;
        j++;
    }

    tab[j] = inclusao;
    j++;

    while (i < cont) {
        tab[j] = cliente[i];
        i++;
        j++;
    }

    for (i = 0; i < cont + 1; i++) {
        cliente[i] = tab[i];
    }
}

void InclusaoVendedor(Vendedor vendedor[], Vendedor inclusao, int t, int cont) {
    Vendedor tab[t];
    int i = 0;
    int j = 0;

    while (i < cont && vendedor[i].codigo < inclusao.codigo) {
        tab[j] = vendedor[i];
        i++;
        j++;
    }

    tab[j] = inclusao;
    j++;

    while (i < cont) {
        tab[j] = vendedor[i];
        i++;
        j++;
    }

    for (i = 0; i < cont + 1; i++) {
        vendedor[i] = tab[i];
    }
}

void InclusaoVenda(Venda venda[], Venda inclusao, int t, int cont) {
    Venda tab[t];
    int i = 0;
    int j = 0;

    while (i < cont && venda[i].codigo < inclusao.codigo) {
        tab[j] = venda[i];
        i++;
        j++;
    }

    tab[j] = inclusao;
    j++;

    while (i < cont) {
        tab[j] = venda[i];
        i++;
        j++;
    }

    for (i = 0; i < cont + 1; i++) {
        venda[i] = tab[i];
    }
}

bool ProcuraItensEstoque(Produto produto[], int inicio, int fim) {
    if (inicio > fim) {
        return false;
    }

    int meio = (inicio + fim) / 2;

    if (produto[meio].quantEstoque > 0) {
        return true;
    }

    if (ProcuraItensEstoque(produto, inicio, meio - 1)) {
        return true;
    }

    return ProcuraItensEstoque(produto, meio + 1, fim);
}

bool TesteEstoque(Produto produto[], int contProduto) {
    return ProcuraItensEstoque(produto, 0, contProduto - 1);
}

bool ProcuraClienteVenda(Venda venda[], int inicio, int fim, int codCliente) {
    if (inicio > fim) {
        return false;
    }

    int meio = (inicio + fim) / 2;

    if (venda[meio].codCliente == codCliente) {
        return true;
    }

    if (ProcuraClienteVenda(venda, inicio, meio - 1, codCliente)) {
        return true;
    }

    return ProcuraClienteVenda(venda, meio + 1, fim, codCliente);
}

bool TesteClienteVenda(Venda venda[], int contVenda, int codCliente) {
    return ProcuraClienteVenda(venda, 0, contVenda - 1, codCliente);
}

void LerCategoria(Categoria categoria[], int &contCategoria, int t) {
    int saida = 1;

    while (saida == 1) {
        system("cls");

        if (contCategoria >= t) {
            cout << "\n\tINFELIZMENTE O SISTEMA JA ATINGIU A CAPACIDADE MAXIMA PARA INSERIR UMA NOVA CATEGORIA.";
            pausar();
            return;
        }

        int cod;
        int indCategoria;
        Categoria inclusao;

        cout << "\n\t\t--- LEITURA DE CATEGORIA ---";
        cod = lerInteiro("\n\tCodigo da Categoria " + to_string(contCategoria + 1) + ": ");

        if (ProcuraCategoria(categoria, cod, contCategoria, indCategoria) == 0) {
            cout << "\n\tCodigo ja Informado, Favor Inserir um Valido.";
            pausar();
            continue;
        }

        inclusao.codigo = cod;

        cout << "\n\tDescricao: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, inclusao.descricao);

        InclusaoCategoria(categoria, inclusao, t, contCategoria);
        contCategoria++;

        cout << "\n\tCategoria cadastrada com sucesso!";

        for (int i = 0; i < contCategoria; i++) {
            categoria[i].imprimir();
        }

        saida = lerOpcaoSimNao("\n\n\t\t--- DESEJA INSERIR MAIS ALGUMA CATEGORIA? ---");
    }
}

void LerProduto(Produto produto[], int &contProduto, int t, Categoria categoria[], int contCategoria) {
    if (contCategoria == 0) {
        cout << "\n\tInfelizmente Nao Existem Categorias Cadastradas Ainda, Favor Cadastrar Novas Categorias Antes de Tentar Novamente.";
        pausar();
        return;
    }

    int saida = 1;

    while (saida == 1) {
        system("cls");

        if (contProduto >= t) {
            cout << "\n\tINFELIZMENTE O SISTEMA JA ATINGIU A CAPACIDADE MAXIMA PARA INSERIR UM NOVO PRODUTO.";
            pausar();
            return;
        }

        int cod;
        int codCategoria;
        int indCategoria;
        int indProduto;
        Produto inclusao;

        cout << "\n\t\t--- LEITURA DE PRODUTO ---";
        cod = lerInteiro("\n\tCodigo do Produto " + to_string(contProduto + 1) + ": ");

        if (ProcuraProduto(produto, cod, contProduto, indProduto) == 0) {
            cout << "\n\tCodigo ja Informado, Favor Inserir um Valido.";
            pausar();
            continue;
        }

        inclusao.codigo = cod;

        cout << "\n\tDescricao: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, inclusao.descricao);

        codCategoria = lerInteiro("\n\n\tCodigo Categoria: ");

        while (ProcuraCategoria(categoria, codCategoria, contCategoria, indCategoria) == 1) {
            cout << "\n\tCodigo Informado Nao Existe, Favor Informar um Valido.";
            codCategoria = lerInteiro("\n\n\tCodigo Categoria: ");
        }

        categoria[indCategoria].imprimir();
        inclusao.codCategoria = codCategoria;

        inclusao.quantEstoque = lerInteiroMaiorOuIgual("\n\tQuantidade em Estoque: ", 0);
        inclusao.estoqueMinimo = lerInteiroMaiorOuIgual("\n\tEstoque Minimo: ", 0);
        inclusao.estoqueMaximo = lerInteiroMaiorOuIgual("\n\tEstoque Maximo: ", 0);

        while (inclusao.estoqueMinimo > inclusao.estoqueMaximo) {
            cout << "\n\tEstoque minimo nao pode ser maior que o estoque maximo.";
            inclusao.estoqueMinimo = lerInteiroMaiorOuIgual("\n\tEstoque Minimo: ", 0);
            inclusao.estoqueMaximo = lerInteiroMaiorOuIgual("\n\tEstoque Maximo: ", 0);
        }

        inclusao.valorUnitario = lerFloatMaiorQueZero("\n\tValor Unitario: ");

        InclusaoProduto(produto, inclusao, t, contProduto);
        contProduto++;

        cout << "\n\tProduto cadastrado com sucesso!";

        for (int i = 0; i < contProduto; i++) {
            produto[i].imprimir();
        }

        saida = lerOpcaoSimNao("\n\n\t\t--- DESEJA INSERIR MAIS ALGUM PRODUTO? ---");
    }
}

void LerCliente(Cliente cliente[], int &contCliente, int t) {
    int saida = 1;

    while (saida == 1) {
        system("cls");

        if (contCliente >= t) {
            cout << "\n\tINFELIZMENTE O SISTEMA JA ATINGIU A CAPACIDADE MAXIMA PARA INSERIR UM NOVO CLIENTE.";
            pausar();
            return;
        }

        int cod;
        int indCliente;
        Cliente inclusao;

        cout << "\n\t\t--- LEITURA DE CLIENTE ---";
        cod = lerInteiro("\n\tCodigo do Cliente " + to_string(contCliente + 1) + ": ");

        if (ProcuraCliente(cliente, cod, contCliente, indCliente) == 0) {
            cout << "\n\tCodigo ja Informado, Favor Inserir um Valido.";
            pausar();
            continue;
        }

        inclusao.codigo = cod;

        cout << "\n\tNome: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, inclusao.nome);

        cout << "\n\tEndereco: ";
        getline(cin, inclusao.endereco);

        cout << "\n\tTelefone: ";
        getline(cin, inclusao.telefone);

        InclusaoCliente(cliente, inclusao, t, contCliente);
        contCliente++;

        cout << "\n\tCliente cadastrado com sucesso!";

        for (int i = 0; i < contCliente; i++) {
            cliente[i].imprimir();
        }

        saida = lerOpcaoSimNao("\n\n\t\t--- DESEJA INSERIR MAIS ALGUM CLIENTE? ---");
    }
}

void LerVendedor(Vendedor vendedor[], int &contVendedor, int t) {
    int saida = 1;

    while (saida == 1) {
        system("cls");

        if (contVendedor >= t) {
            cout << "\n\tINFELIZMENTE O SISTEMA JA ATINGIU A CAPACIDADE MAXIMA PARA INSERIR UM NOVO VENDEDOR.";
            pausar();
            return;
        }

        int cod;
        int indVendedor;
        Vendedor inclusao;

        cout << "\n\t\t--- LEITURA DE VENDEDOR ---";
        cod = lerInteiro("\n\tCodigo do Vendedor " + to_string(contVendedor + 1) + ": ");

        if (ProcuraVendedor(vendedor, cod, contVendedor, indVendedor) == 0) {
            cout << "\n\tCodigo ja Informado, Favor Inserir um Valido.";
            pausar();
            continue;
        }

        inclusao.codigo = cod;

        cout << "\n\tNome: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, inclusao.nome);

        cout << "\n\tTelefone: ";
        getline(cin, inclusao.telefone);

        InclusaoVendedor(vendedor, inclusao, t, contVendedor);
        contVendedor++;

        cout << "\n\tVendedor cadastrado com sucesso!";

        for (int i = 0; i < contVendedor; i++) {
            vendedor[i].imprimir();
        }

        saida = lerOpcaoSimNao("\n\n\t\t--- DESEJA INSERIR MAIS ALGUM VENDEDOR? ---");
    }
}

void AdicionarItensPorCodigoVenda(ItensVenda itensVenda[], int &contItensVenda, int codVenda, Produto produto[], int contProduto, int y) {
    int saida = 1;

    while (saida == 1) {
        if (contItensVenda >= y) {
            cout << "\n\tINFELIZMENTE O SISTEMA JA ATINGIU A CAPACIDADE MAXIMA PARA INSERIR UM NOVO ITEM.";
            pausar();
            return;
        }

        if (contProduto == 0) {
            cout << "\n\tInfelizmente Nao Existem Produtos Cadastrados Ainda, Favor Cadastrar Novos Produtos Antes de Tentar Novamente.";
            pausar();
            return;
        }

        if (!TesteEstoque(produto, contProduto)) {
            cout << "\n\tInfelizmente Nenhum Produto Possui Estoque Disponivel Para Venda.";
            pausar();
            return;
        }

        int codProduto;
        int indProduto;
        int quantidade;
        ItensVenda inclusao;

        cout << "\n\t\t--- LEITURA DE ITENS ---";
        codProduto = lerInteiro("\n\n\tCodigo do Produto: ");

        while (ProcuraProduto(produto, codProduto, contProduto, indProduto) == 1 || produto[indProduto].quantEstoque <= 0) {
            if (ProcuraProduto(produto, codProduto, contProduto, indProduto) == 1) {
                cout << "\n\tCodigo Informado Nao Existe, Favor Informar um Valido.";
            }
            else {
                cout << "\n\tProduto Sem Estoque Disponivel, Favor Informar Outro Produto.";
            }

            codProduto = lerInteiro("\n\n\tCodigo do Produto: ");
        }

        produto[indProduto].imprimirResumo();

        quantidade = lerInteiroMaiorQueZero("\n\tQuantidade do Produto: ");

        while (quantidade > produto[indProduto].quantEstoque) {
            cout << "\n\tValor Informado e Superior a Quantidade que Temos Em Estoque.";
            cout << "\n\tQuantidade disponivel: " << produto[indProduto].quantEstoque;
            quantidade = lerInteiroMaiorQueZero("\n\tQuantidade do Produto: ");
        }

        produto[indProduto].quantEstoque = produto[indProduto].quantEstoque - quantidade;

        inclusao.codVenda = codVenda;
        inclusao.codProduto = codProduto;
        inclusao.quantidade = quantidade;

        itensVenda[contItensVenda] = inclusao;
        contItensVenda++;

        cout << "\n\tItem Adicionado com sucesso!";

        if (contItensVenda >= y) {
            cout << "\n\tCapacidade maxima de itens atingida.";
            pausar();
            return;
        }

        saida = lerOpcaoSimNao("\n\n\t\t--- DESEJA INSERIR MAIS ALGUM ITEM A ESSA VENDA? ---");
    }
}

void NovaVenda(Venda venda[], int &contVenda, Cliente cliente[], int contCliente, Vendedor vendedor[], int contVendedor, int t, ItensVenda itensVenda[], int &contItensVenda, int y, Produto produto[], int contProduto) {
    if (contCliente == 0) {
        cout << "\n\tInfelizmente Nao Existem Clientes Cadastrados Ainda, Favor Cadastrar Novos Clientes Antes de Tentar Novamente.";
        pausar();
        return;
    }

    if (contVendedor == 0) {
        cout << "\n\tInfelizmente Nao Existem Vendedores Cadastrados Ainda, Favor Cadastrar Novos Vendedores Antes de Tentar Novamente.";
        pausar();
        return;
    }

    if (contProduto == 0) {
        cout << "\n\tInfelizmente Nao Existem Produtos Cadastrados Ainda, Favor Cadastrar Novos Produtos Antes de Tentar Novamente.";
        pausar();
        return;
    }

    if (!TesteEstoque(produto, contProduto)) {
        cout << "\n\tInfelizmente Nenhum Produto Possui Estoque Disponivel Para Venda.";
        pausar();
        return;
    }

    if (contItensVenda >= y) {
        cout << "\n\tInfelizmente O Sistema Ja Atingiu A Capacidade Maxima De Itens De Venda.";
        pausar();
        return;
    }

    int saida = 1;

    while (saida == 1) {
        system("cls");

        if (contVenda >= t) {
            cout << "\n\tINFELIZMENTE O SISTEMA JA ATINGIU A CAPACIDADE MAXIMA PARA INSERIR UMA NOVA VENDA.";
            pausar();
            return;
        }

        if (contItensVenda >= y) {
            cout << "\n\tInfelizmente O Sistema Ja Atingiu A Capacidade Maxima De Itens De Venda.";
            pausar();
            return;
        }

        int cod;
        int codCliente;
        int codVendedor;
        int indCliente;
        int indVendedor;
        int indVenda;
        Venda inclusao;

        cout << "\n\t\t--- LEITURA DE VENDA ---";
        cod = lerInteiro("\n\tCodigo da Venda " + to_string(contVenda + 1) + ": ");

        if (ProcuraVenda(venda, cod, contVenda, indVenda) == 0) {
            cout << "\n\tCodigo ja Informado, Favor Inserir um Valido.";
            pausar();
            continue;
        }

        inclusao.codigo = cod;

        codCliente = lerInteiro("\n\n\tCodigo Cliente: ");

        while (ProcuraCliente(cliente, codCliente, contCliente, indCliente) == 1) {
            cout << "\n\tCodigo Informado Nao Existe, Favor Informar um Valido.";
            codCliente = lerInteiro("\n\n\tCodigo Cliente: ");
        }

        cliente[indCliente].imprimirResumo();
        inclusao.codCliente = codCliente;

        codVendedor = lerInteiro("\n\n\tCodigo Vendedor: ");

        while (ProcuraVendedor(vendedor, codVendedor, contVendedor, indVendedor) == 1) {
            cout << "\n\tCodigo Informado Nao Existe, Favor Informar um Valido.";
            codVendedor = lerInteiro("\n\n\tCodigo Vendedor: ");
        }

        vendedor[indVendedor].imprimirResumo();
        inclusao.codVendedor = codVendedor;

        cout << "\n\n\tData: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, inclusao.data);

        InclusaoVenda(venda, inclusao, t, contVenda);
        contVenda++;

        cout << "\n\tVenda cadastrada com sucesso! Agora adicione os itens desta venda.";

        AdicionarItensPorCodigoVenda(itensVenda, contItensVenda, inclusao.codigo, produto, contProduto, y);

        for (int i = 0; i < contVenda; i++) {
            venda[i].imprimir();
        }

        if (contVenda >= t || contItensVenda >= y) {
            pausar();
            return;
        }

        saida = lerOpcaoSimNao("\n\n\t\t--- DESEJA INSERIR MAIS ALGUMA VENDA? ---");
    }
}

void InclusaoItensVenda(ItensVenda itensVenda[], int &contItensVenda, Venda venda[], int contVenda, Produto produto[], int contProduto, int y) {
    system("cls");

    if (contVenda == 0) {
        cout << "\n\tInfelizmente Nao Existem Vendas Cadastradas Ainda, Favor Cadastrar Novas Vendas Antes de Tentar Novamente.";
        pausar();
        return;
    }

    if (contProduto == 0) {
        cout << "\n\tInfelizmente Nao Existem Produtos Cadastrados Ainda, Favor Cadastrar Novos Produtos Antes de Tentar Novamente.";
        pausar();
        return;
    }

    if (!TesteEstoque(produto, contProduto)) {
        cout << "\n\tInfelizmente Nenhum Produto Possui Estoque Disponivel Para Venda.";
        pausar();
        return;
    }

    if (contItensVenda >= y) {
        cout << "\n\tINFELIZMENTE O SISTEMA JA ATINGIU A CAPACIDADE MAXIMA PARA INSERIR UM NOVO ITEM.";
        pausar();
        return;
    }

    int codVenda;
    int indVenda;

    cout << "\n\t\t--- INCLUSAO DE ITENS EM VENDA ---";
    codVenda = lerInteiro("\n\tCodigo da Venda: ");

    while (ProcuraVenda(venda, codVenda, contVenda, indVenda) == 1) {
        cout << "\n\tCodigo Informado Nao Existe, Favor Informar um Valido.";
        codVenda = lerInteiro("\n\n\tCodigo da Venda: ");
    }

    venda[indVenda].imprimir();

    if (contItensVenda > 0) {
        cout << "\n\n\t\t--- ITENS JA CADASTRADOS NESSA VENDA ---";

        for (int i = 0; i < contItensVenda; i++) {
            if (itensVenda[i].codVenda == codVenda) {
                itensVenda[i].imprimir();
            }
        }
    }

    AdicionarItensPorCodigoVenda(itensVenda, contItensVenda, codVenda, produto, contProduto, y);
}

void ConsultaProduto(Produto produto[], int contProduto) {
    if (contProduto == 0) {
        cout << "\n\tInfelizmente Ainda Nao Temos Produtos Cadastrados.";
        pausar();
        return;
    }

    int saida = 1;

    while (saida == 1) {
        system("cls");

        int cod;
        int indProduto;
        float totalEstoque;

        cout << "\n\t\t--- CONSULTA DE PRODUTO ---";
        cod = lerInteiro("\n\tCodigo do Produto: ");

        if (ProcuraProduto(produto, cod, contProduto, indProduto) == 0) {
            totalEstoque = produto[indProduto].quantEstoque * produto[indProduto].valorUnitario;
            produto[indProduto].imprimir();
            cout << "\n\tTotal em Estoque: " << totalEstoque;
        }
        else {
            cout << "\n\tCodigo nao encontrado.";
        }

        saida = lerOpcaoSimNao("\n\n\tDeseja buscar dados de outro Produto?");
    }
}

void ExibirProdMin(Produto produto[], int contProduto) {
    float totalCustoCompra = 0;
    system("cls");

    if (contProduto == 0) {
        cout << "\n\tInfelizmente Ainda Nao Temos Produtos Declarados, Tente Novamente Apos Adicionar Algum Produto.";
        pausar();
        return;
    }

    bool encontrou = false;

    for (int i = 0; i < contProduto; i++) {
        if (produto[i].quantEstoque < produto[i].estoqueMinimo) {
            produto[i].imprimirEstoqueMinimo();
            encontrou = true;
            totalCustoCompra += produto[i].valorUnitario * (produto[i].estoqueMaximo - produto[i].quantEstoque);
            continue;
        }

    }
    if(totalCustoCompra>0){
    cout << "\n\t\t--- CUSTO TOTAL REPOSIÇÃO ---";
    cout << "\n\t\tTotal: " << totalCustoCompra;

    }
    if (!encontrou) {
        cout << "\n\tNenhum produto esta abaixo do estoque minimo.";
    }

    pausar();
}

void TotalVendas(Venda venda[], int contVenda, ItensVenda itensVenda[], int contItensVenda, Produto produto[], int contProduto) {
    system("cls");

    if (contVenda == 0) {
        cout << "\n\tInfelizmente Ainda Nao Temos Vendas Cadastradas.";
        pausar();
        return;
    }

    if (contItensVenda == 0) {
        cout << "\n\tInfelizmente Ainda Nao Temos Itens Cadastrados Para Vendas.";
        pausar();
        return;
    }

    float totalGeral = 0;

    for (int i = 0; i < contVenda; i++) {
        float totalVenda = 0;

        for (int j = 0; j < contItensVenda; j++) {
            if (itensVenda[j].codVenda == venda[i].codigo) {
                int indProduto;

                if (ProcuraProduto(produto, itensVenda[j].codProduto, contProduto, indProduto) == 0) {
                    totalVenda += itensVenda[j].quantidade * produto[indProduto].valorUnitario;
                }
            }
        }


        cout << "\n\t\t--- CÁLCULO TOTAL VENDA ---";
        cout << "\n\tCodigo da Venda: " << venda[i].codigo;
        cout << "\n\tValor da Venda: " << totalVenda;
        totalGeral += totalVenda;
    }

    cout << "\n\n\tVALOR TOTAL DAS VENDAS: " << totalGeral;
    pausar();
}

void ExclusaoClientes(Cliente cliente[], int &contCliente, int t, Venda venda[], int contVenda) {
    system("cls");

    if (contCliente == 0) {
        cout << "\n\tInfelizmente Nao Existem Clientes Cadastrados Ainda, Favor Cadastrar Novos Clientes Antes de Tentar Novamente.";
        pausar();
        return;
    }

    int codCliente;
    int indCliente;

    cout << "\n\t\t--- EXCLUSAO DE CLIENTE ---";
    codCliente = lerInteiro("\n\tCodigo do Cliente: ");

    while (ProcuraCliente(cliente, codCliente, contCliente, indCliente) == 1) {
        cout << "\n\tCodigo Informado Nao Existe, Favor Informar um Valido.";
        codCliente = lerInteiro("\n\n\tCodigo do Cliente: ");
    }

    cliente[indCliente].imprimir();

    if (TesteClienteVenda(venda, contVenda, codCliente)) {
        cout << "\n\n\tNao E Possivel Excluir Este Cliente, Pois Ele Possui Venda Cadastrada.";
        pausar();
        return;
    }

    int saida = lerOpcaoSimNao("\n\n\t\t--- DESEJA REALMENTE EXCLUIR ESSE CLIENTE? ---");

    if (saida == 1) {
        Cliente tab[t];
        int j = 0;

        for (int i = 0; i < contCliente; i++) {
            if (i != indCliente) {
                tab[j] = cliente[i];
                j++;
            }
        }

        for (int i = 0; i < contCliente - 1; i++) {
            cliente[i] = tab[i];
        }

        contCliente--;

        cout << "\n\tCliente Excluido com Sucesso!";
    }
    else {
        cout << "\n\tExclusao Cancelada.";
    }

    pausar();
}

int main() {
    setlocale(LC_ALL, "");

    const int t = 2;
    const int y = 4;

    Categoria categoria[t];
    Produto produto[t];
    Cliente cliente[t];
    Vendedor vendedor[t];
    Venda venda[t];
    ItensVenda itensVenda[y];

    int contCategoria = 0;
    int contProduto = 0;
    int contCliente = 0;
    int contVendedor = 0;
    int contVenda = 0;
    int contItensVenda = 0;

    int op = 100;

    while (op != 0) {
        system("cls");
        cout << "\n\t =====================================================";
        cout << "\n\t\t             --- MENU ---";
        cout << "\n\t =====================================================";
        cout << "\n\t\t1 - Ler Nova Categoria";
        cout << "\n\t\t2 - Ler Novo Produto";
        cout << "\n\t\t3 - Ler Novo Cliente";
        cout << "\n\t\t4 - Ler Novo Vendedor";
        cout << "\n\t\t5 - Nova Venda";
        cout << "\n\t\t6 - Incluir Itens Em Uma Venda";
        cout << "\n\t\t7 - Consultar Produto";
        cout << "\n\t\t8 - Consultar Produtos Com Estoque Abaixo do Minimo";
        cout << "\n\t\t9 - Consultar o Valor Total Arrecadado com Vendas";
        cout << "\n\t\t10 - Excluir Cliente";
        cout << "\n\t\t0 - Sair";

        op = lerInteiro("\n\t\tOpcao: ");

        switch (op) {
            case 1:
                LerCategoria(categoria, contCategoria, t);
                break;

            case 2:
                LerProduto(produto, contProduto, t, categoria, contCategoria);
                break;

            case 3:
                LerCliente(cliente, contCliente, t);
                break;

            case 4:
                LerVendedor(vendedor, contVendedor, t);
                break;

            case 5:
                NovaVenda(venda, contVenda, cliente, contCliente, vendedor, contVendedor, t, itensVenda, contItensVenda, y, produto, contProduto);
                break;

            case 6:
                InclusaoItensVenda(itensVenda, contItensVenda, venda, contVenda, produto, contProduto, y);
                break;

            case 7:
                ConsultaProduto(produto, contProduto);
                break;

            case 8:
                ExibirProdMin(produto, contProduto);
                break;

            case 9:
                TotalVendas(venda, contVenda, itensVenda, contItensVenda, produto, contProduto);
                break;

            case 10:
                ExclusaoClientes(cliente, contCliente, t, venda, contVenda);
                break;

            case 0:
                cout << "\n\tPrograma encerrado.";
                break;

            default:
                cout << "\n\tInsira um Codigo Valido.";
                pausar();
                break;
        }
    }

    return 0;
}
