#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
/* Inclus�o de registros Arquivo Sequencial
*/

struct clientes {
       int codigo;
       char nome[30];
       char endereco[35];
       char cidade[25];
       char uf[2];
       };

void leitura (struct clientes cli[], int &contador){
    int i = 0;
    for (int saida = 1; i < 10 && saida != 0; i++){
        cout << "\n\nCodigo do Cliente " << (i+1) << ": ";
        cin >> cli[i].codigo;
        if (cli[i].codigo > 0){
            cout << "Nome: ";
            cin >> cli[i].nome;
            cout << "Endereco: ";
            cin >> cli[i].endereco;
            cout << "Cidade: ";
            cin >> cli[i].cidade;
            cout << "Estado: ";
            cin >> cli[i].uf;
        }
        else saida = 0;
    }
    contador = i-1;
}

void inclusao (struct clientes S[], int contS, struct clientes T[], int contT, struct clientes A[], int &contA){
    int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)
    for (;i < contS && j < contT;k++){
        if (S[i].codigo < T[j].codigo){
            A[k].codigo = S[i].codigo;
            strcpy (A[k].nome,S[i].nome);
            strcpy (A[k].endereco,S[i].endereco);
            strcpy (A[k].cidade,S[i].cidade);
            strcpy (A[k].uf,S[i].uf);
            i++;
            }
        else {
            A[k].codigo = T[j].codigo;
            strcpy (A[k].nome,T[j].nome);
            strcpy (A[k].endereco,T[j].endereco);
            strcpy (A[k].cidade,T[j].cidade);
            strcpy (A[k].uf,T[j].uf);
            j++;
        }
    }
    while (i < contS){
        A[k].codigo = S[i].codigo;
        strcpy (A[k].nome,S[i].nome);
        strcpy (A[k].endereco,S[i].endereco);
        strcpy (A[k].cidade,S[i].cidade);
        strcpy (A[k].uf,S[i].uf);
        i++;
        k++;
    }
    while (j < contT){
        A[k].codigo = T[j].codigo;
        strcpy (A[k].nome,T[j].nome);
        strcpy (A[k].endereco,T[j].endereco);
        strcpy (A[k].cidade,T[j].cidade);
        strcpy (A[k].uf,T[j].uf);
        j++;
        k++;
    }
    contA = k;
}
void mostrar (struct clientes A[], int contA){
    cout << "\n\nLista dos Registros no Arquivo Atualizado" << endl;
    for (int i = 0; i < contA; i++){
        cout << "\nCodigo: " << A[i].codigo;
        cout << "\tNome: " << A[i].nome;
        cout << "\tEndereco: " << A[i].endereco;
        cout << "\tCidade: " << A[i].cidade;
        cout << "\tUF: " << A[i].uf;
    }
}
int main(){
    struct clientes arqS[20], arqT[20], arqA[40];
    int contS, contT, contA;
    cout << "\n\nLeitura do Arquivo S";
    leitura (arqS,contS);
    cout << "\n\nLeitura do Arquivo T";
    leitura (arqT,contT);
    inclusao (arqS, contS, arqT, contT, arqA, contA);
    mostrar (arqA, contA);
    getch();
}