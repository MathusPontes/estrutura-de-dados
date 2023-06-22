#include <iostream>
#include <string>

using namespace std;

struct Produto {
    int codigo;
    string descricao;
    double preco;
};

void selectionSort(Produto arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j].codigo < arr[minIndex].codigo) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int buscaSequencial(Produto arr[], int n, int codigoBusca, int& numComparacoes) {
    for (int i = 0; i < n; i++) {
        numComparacoes++;
        if (arr[i].codigo == codigoBusca) {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(Produto arr[], int n, int codigoBusca, int& numComparacoes) {
    int esquerda = 0, direita = n-1;
    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        numComparacoes++;
        if (arr[meio].codigo == codigoBusca) {
            return meio;
        } else if (arr[meio].codigo < codigoBusca) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}

int main() {
    const int n = 12;
    Produto produtos[n];

    // Preenchendo o vetor de produtos com informações inseridas pelo usuário
    for (int i = 0; i < n; i++) {
        cout << "Produto " << i+1 << ":" << endl;
        cout << "Código: ";
        cin >> produtos[i].codigo;
        cout << "Descrição: ";
        cin.ignore();
        getline(cin, produtos[i].descricao);
        cout << "Preço: ";
        cin >> produtos[i].preco;
        cout << endl;
    }

    // Ordenando o vetor de produtos pelo código usando Selection Sort
    selectionSort(produtos, n);

    // Buscando um produto com código 7 usando busca sequencial
    int codigoBusca = 7;
    int indiceSequencial;
    int numComparacoesSequencial = 0;
    indiceSequencial = buscaSequencial(produtos, n, codigoBusca, numComparacoesSequencial);
    if (indiceSequencial != -1) {
        cout << "Produto encontrado na posição " << indiceSequencial << " usando busca sequencial." << endl;
        cout << "Número de comparações: " << numComparacoesSequencial << endl;
    } else {
        cout << "Produto não encontrado usando busca sequencial." << endl;
    }

    // Buscando um produto com código 7 usando busca binária
    int indiceBinaria;
    int numComparacoesBinaria = 0;
    indiceBinaria = buscaBinaria(produtos, n, codigoBusca, numComparacoesBinaria);
    if (indiceBinaria != -1) {
        cout << "Produto encontrado na posição " << indiceBinaria << " usando busca binária." << endl;
        cout << "Número de comparações: " << numComparacoesBinaria << endl;
    }
    
    else {
        cout << "Produto não encontrado usando busca binária." << endl;
    }

    return 0;
}