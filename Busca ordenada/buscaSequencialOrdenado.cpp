#include <iostream>
using namespace std;

int main(){
    int X[10], n, i, achou;
    
    for(i=0; i<=9; i++){
        cout << "Digite o " <<i+1<< "o numero: ";
        cin >> X[i];
    }

    cout << "Digite o numero a ser buscado no vetor: ";
    cin >> n;

    achou = 0;
    i = 0;
    while (i <= 9 && achou == 0 && n >= X[i]){
        if (X[i] == n){
            achou = 1;
        }
        else{
            i++;
        }
    }

    if (achou == 0){
        cout << "Numero não encontrado no vetor";
    }
    else{
        cout << "Numero ecnontrado na posicao " << i+1;
    }

    return 0;
}