#include <iostream>

using namespace std;

const int TAM = 10;

void bubblesort_v2_D (int *X){
	int i, n, troca;
	int aux;
    
	n = 1;
	troca = 1;
	
	while (n<=TAM && troca == 1){
		troca = 0;
		
		for (i = 0; i<=TAM-2; i++){
			if(X[i] > X[i+1]){
				
				troca = 1;
				aux = X[i];
				X[i] = X[i+1];
				X[i+1] = aux;
			}
		}
		n = n+1;
	}
}

void entrada_de_dados (int *X){
	int i;
	
	int *pAux = X;
	
	for (i=0; i<TAM; i++){
		cout << "\nDigite o " << i+1 << "o. numero: ";
		cin >> *pAux;
		pAux = pAux + 1;
	}
	
}

void imprime_vetor(int *X){
	int i;
	int *pAux = X;
	
	cout << "Sequencia dos numeros" << endl;
	
	for (i=0; i<TAM; i++){
		cout << *pAux << endl;
		pAux = pAux + 1;
	}
	cout << endl;
}

int encontra_numero_menor(int *X){
    int qnt = 0, acabou = 0;

    for (int i = 0; i < TAM-1 && acabou == 0; i++){
        if (X[0] == X[i]){
            qnt += 1;
        }

        else{
            acabou +=1;
        }
    }
    return qnt;
}

int encontra_numero_maior(int *X){
    int qnt = 0, acabou = 0;

    for (int i = TAM-1; i >= 0 && acabou == 0; i--){
        if (X[TAM-1] == X[i]){
            qnt += 1;
        }

        else{
            acabou +=1;
        }
    }
    return qnt;
}

int main (){
    int X[TAM], qnt;

    entrada_de_dados(X);
    cout << endl << "vetor original: " << endl;
	imprime_vetor(X);

    bubblesort_v2_D(X);

    cout << endl << "vetor ordenado de forma crescente: " << endl;
    imprime_vetor(X);

    qnt = encontra_numero_menor(X);
    cout << X[0] << " eh o menor numero e aparece "<< qnt << " vezes no vetor" << endl;

    qnt = encontra_numero_maior(X);
    cout << X[TAM-1] << " eh o maior numero e aparece "<< qnt << " vezes no vetor" << endl;

    return 0;
}