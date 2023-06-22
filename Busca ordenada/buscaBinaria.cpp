#include <iostream>
using namespace std;

int main (){
    int X[10], np, i, inicio, fim, meio, achou;

    for(i=0; i<=9; i++){
        cout << "Digite o "<< i+1 <<"o numero: ";
        cin>>X[i];
    }

    cout << "Digite o numero a ser buscado no vetor: ";
    cin >> np;

    achou = 0;
    inicio = 0;
    fim = 9;
    meio = (inicio+fim)/2;
    while (inicio <= fim && achou == 0){
        if (X[meio] == np){
            achou = 1;
        }
        else{
            if (np < X[meio]){
                fim = meio-1;
            }
            else{
                inicio = meio+1;
                meio = (inicio+fim)/2;
            }
        }
    }

    if (achou == 0){
        cout << "Numero não encontrado no vetor";
    }
    else{
        cout << "Numero encontrado na posicao "<<meio+1;
    }

    return 0;
}