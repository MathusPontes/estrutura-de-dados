#include <iostream>

using namespace std;

const int TAM = 5;

void main(){
    int X[TAM];
    int i, j, eleito;

    for(i=0; i<=TAM-1; i++){
        cout << "Digite o "<< i+1 << "o numero: ";
        cin >> X[i]; 
    }

    for (i=1; i<=TAM-1; i++){
        eleito = X[i];
        j = i-1;

        while(j >= 0 && X[j] > eleito){
            X[j+1] = X[j];
            j -= 1;
        }
        X[j+1] = eleito;
    }

    for (i = 0; i <= TAM-1; i++){
        cout << "\n"<< i+1 << "o numero: " << X[i];
    }
}