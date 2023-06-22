#include <iostream>

using namespace std;

const int TAM = 5;

int main (){
	int X[TAM];
	int i, j, eleito, menor, pos;
	
	for (i=0;i<=TAM-1;i++){
		cout << "Digite o "<<i+1<<"o numero: ";
		cin >> X[i];
	}
	
	for(i=0; i<=TAM-2; i++){
		eleito = X[i];
		menor = X[i+1];
		pos = i+1;
		
		for (j=i+1; j<=TAM-1; j++){
			if (X[j] < menor){
				menor = X[j];
				pos = j;
			}
		}
		if (menor < eleito){
			X[i] = X[pos];
			X[pos] = eleito;
		}
	}
	for (i=0; i<=TAM-1; i++){
		cout << "\n"<<i+1<<"o número: " << X[i];
	}
	return 0;
}
