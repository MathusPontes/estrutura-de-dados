/* Implemente um programa estruturado e recursivo para pesquisa binária. Faça uma
função de busca chamada pesquisaBR que receba como parâmetro o valor a ser
encontrado e a referência do vetor onde a busca será efetuada. A função retornará -1,
caso não encontre o item, ou retornará o índice, caso o encontre. */

#include <iostream>
using namespace std;

const int TAM = 10;

int pesquisaBR(int *X, int busca){
    int inicio = 0, fim = TAM-1, meio = (inicio+fim)/2, achou = 0;

    while (inicio <= fim && achou == 0){
        if (X[meio] == busca){
            return meio;
        }
        else{
            if (busca < X[meio]){
                fim = meio-1;
            }
            else{
                inicio = meio+1;
                meio = (inicio+fim)/2;
            }
        }
    }

    return -1;
}

void bubblesort_v2_C (int *X){
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

int main (){
    int X[TAM], indice, busca;

    entrada_de_dados(X);
    cout << endl << "vetor original: " << endl;
	imprime_vetor(X);

    bubblesort_v2_C(X);
    cout << endl << "vetor ordenado de forma crescente: " << endl;
    imprime_vetor(X);

    cout << "Informe o numero que busca no vetor: ";
    cin >> busca;

    indice = pesquisaBR(X, busca);

    if (indice == -1){
        cout << "Numero não encontrado no vetor";
    }
    else{
        cout << "Numero ecnontrado na posicao " << indice+1;
    }
    return 0;
}