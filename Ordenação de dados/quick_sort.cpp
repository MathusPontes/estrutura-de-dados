#include <iostream>

using namespace std;

const int TAM = 10;

void troca (int X[], int i, int j){
    int aux;
    aux = X[i];
    X[i] = X[j];
    X[j] = aux;
}

int particao (int X[], int p, int r){
    int pivo, i, j;
    pivo = X[(p+r)/2];
    i = p-1;
    j = r+1;
    while (i < j){
        do{
            j -= 1;
        } while (X[j] > pivo);

        do{
            i += 1;
        } while (X[i] < pivo);
    }
    if (i<j){
        troca(X, i, j);
    }
    return j;
}

void quicksort (int X[], int p, int r){
    int q;
    if (p < r){
        q = particao(X, p, r);
        quicksort(X, p, q);
        quicksort ( X, q+1, r);
    }
}

void main (){
    int X[TAM];
    int i;

    for (i=0; i<=TAM-1; i++){
        cout << "Digite o "<<i+1<<"o numero: ";
        cin >> X[i];
    }
    
    quicksort(X, 0, TAM-1);

    for (i=0; i<=TAM-1; i++){
        cout <<"\n"<<i+1<<"o numero: "<<X[i];
    }
}